/********************************************************************************************************************/
/*****************     Author 		: Ahmed Abdelhady 	*************************************************************/
/*****************     File 		: Program Of RTO  	*************************************************************/
/*****************     Date 		: 8/10/2023  		*************************************************************/
/*****************     Version 		: 1.0  				*************************************************************/
/*****************     Description 	: Drive For RTO 	*************************************************************/
/********************************************************************************************************************/

/* LIB Layer */
#include "util/delay.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "TIMERS_interface.h"

/* SERVICE Layer */
#include "RTO_private.h"
#include "RTO_config.h"
#include "RTO_interface.h"

/* Array of TCBs */
RTO_TCB RTO_AstrTasks[RTO_u8_MAX_NUM_TASKS]	;

void RTO_voidInit	(void)
{
	/* Init Timer0 */
	TIMERS_voidTimer0Init() ;
}

u8 RTO_u8CreateTask (u8 Copy_u8Priority , u16 Copy_u16Periodicty , u16 Copy_u16FirstDelay , void (* Copy_Pf)(void))
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;

	if((Copy_u8Priority < RTO_u8_MAX_NUM_TASKS) && (Copy_Pf != NULL))
	{

		RTO_AstrTasks[Copy_u8Priority].FirstDelay 	= Copy_u16FirstDelay ;
		RTO_AstrTasks[Copy_u8Priority].Periodicity 	= Copy_u16Periodicty ;
		RTO_AstrTasks[Copy_u8Priority].Pf 			= Copy_Pf ;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}

	return Local_u8ErrorState ;

}

static void Private_voidScheduler	(void)
{
	u8 Local_u8Counter = 0 ;

	/* For Loop To Loop On The Ready Tasks */
	for(Local_u8Counter = 0 ; Local_u8Counter < RTO_u8_MAX_NUM_TASKS ; Local_u8Counter ++)
	{
		if(RTO_AstrTasks [ Local_u8Counter ].FirstDelay == 0)
		{
			/* Call Task */
			RTO_AstrTasks [ Local_u8Counter ].Pf() ;

			/* Update The FirstDilay Value By The Periodicity */
			RTO_AstrTasks [ Local_u8Counter ].FirstDelay = RTO_AstrTasks [ Local_u8Counter ].Periodicity - 1 ;
		}
		else
		{
			RTO_AstrTasks [ Local_u8Counter ].FirstDelay -- ;
		}
	}
}

void RTO_voidStartScheduler (u32 Copy_u32DTime)
{
	TIMERS_voidTimer0Delay_ms(Copy_u32DTime , &Private_voidScheduler) ;
}
