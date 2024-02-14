/********************************************************************************************************************/
/*****************     Author 		: Ahmed Abdelhady 	*************************************************************/
/*****************     File 		: Program Of EXTI  	*************************************************************/
/*****************     Date 		: 1/1/2023  		*************************************************************/
/*****************     Version 		: 1.0  				*************************************************************/
/*****************     Description 	: Drive For EXTI 	*************************************************************/
/********************************************************************************************************************/

/* LIB Layer */
#include "util/delay.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL Layer */
#include "EXTI_private.h"
#include "EXTI_config.h"
#include "EXTI_interface.h"


/******************  Global Variables ******************/
static void (* EXTI_APfCallBack[3])(void) = {NULL};


u8 EXTI_u8Enable ( u8 Copy_u8Exti_ID ,u8 Copy_u8Exti_Sense )
{

	u8 Local_u8ErrorState = STD_TYPES_OK ;

	switch (Copy_u8Exti_ID)
	{
	case EXTI_u8_EXTI_0 :
#if (EXTI_u8_VALUE_WAY ==	EXTI_u8_NORMAL_WAY	)
		/* Normal Way */
		switch(Copy_u8Exti_Sense)
		{
		case EXTI_u8_TRIGG_LOW_LEVEL :

			CLR_BIT (EXTI_u8_MCUCR_REG , EXTI_u8_ISC00_BIT)	;
			CLR_BIT (EXTI_u8_MCUCR_REG , EXTI_u8_ISC01_BIT)	;

			break ;

		case EXTI_u8_TRIGG_ANY_LOGICAL_CHANGE :

			SET_BIT (EXTI_u8_MCUCR_REG , EXTI_u8_ISC00_BIT)	;
			CLR_BIT (EXTI_u8_MCUCR_REG , EXTI_u8_ISC01_BIT)	;

			break ;

		case EXTI_u8_TRIGG_FALLING_EDGE :

			CLR_BIT (EXTI_u8_MCUCR_REG , EXTI_u8_ISC00_BIT)	;
			SET_BIT (EXTI_u8_MCUCR_REG , EXTI_u8_ISC01_BIT)	;

			break ;

		case EXTI_u8_TRIGG_RISING_EDGE :

			SET_BIT (EXTI_u8_MCUCR_REG , EXTI_u8_ISC00_BIT)	;
			SET_BIT (EXTI_u8_MCUCR_REG , EXTI_u8_ISC01_BIT)	;

			break ;

		default : Local_u8ErrorState = STD_TYPES_NOK ; break ;

		}

#elif(EXTI_u8_VALUE_WAY ==	EXTI_u8_MASK_WAY	)

		/* Masking ---Better Another Way*/
		EXTI_u8_MCUCR_REG & = EXTI_u8_EXTI_0_TRIGG_MASKING ;
		EXTI_u8_MCUCR_REG | =	Copy_u8Exti_Sense ;

#else
		Local_u8ErrorState = STD_TYPES_NOK ;
#endif

		break ;

		case EXTI_u8_EXTI_1 :
#if (EXTI_u8_VALUE_WAY ==	EXTI_u8_NORMAL_WAY	)
			/* Normal Way */
			switch(Copy_u8Exti_Sense)
			{

			case EXTI_u8_TRIGG_LOW_LEVEL :

				CLR_BIT (EXTI_u8_MCUCR_REG , EXTI_u8_ISC10_BIT)	;
				CLR_BIT (EXTI_u8_MCUCR_REG , EXTI_u8_ISC11_BIT)	;

				break ;

			case EXTI_u8_TRIGG_ANY_LOGICAL_CHANGE :

				SET_BIT (EXTI_u8_MCUCR_REG , EXTI_u8_ISC10_BIT)	;
				CLR_BIT (EXTI_u8_MCUCR_REG , EXTI_u8_ISC11_BIT)	;

				break ;

			case EXTI_u8_TRIGG_FALLING_EDGE :

				CLR_BIT (EXTI_u8_MCUCR_REG , EXTI_u8_ISC10_BIT)	;
				SET_BIT (EXTI_u8_MCUCR_REG , EXTI_u8_ISC11_BIT)	;

				break ;

			case EXTI_u8_TRIGG_RISING_EDGE :

				SET_BIT (EXTI_u8_MCUCR_REG , EXTI_u8_ISC10_BIT)	;
				SET_BIT (EXTI_u8_MCUCR_REG , EXTI_u8_ISC11_BIT)	;

				break ;

			default : Local_u8ErrorState = STD_TYPES_NOK ; break ;

			}

#elif(EXTI_u8_VALUE_WAY ==	EXTI_u8_MASK_WAY	)

			/* Masking ---Better Another Way*/
			EXTI_u8_MCUCR_REG & = EXTI_u8_EXTI_1_TRIGG_MASKING ;
			EXTI_u8_MCUCR_REG | =	( Copy_u8Exti_Sense<< EXTI_u8_ISC10_BIT );

#else
			Local_u8ErrorState = STD_TYPES_NOK ;
#endif

			break ;

			case EXTI_u8_EXTI_2 :
#if (EXTI_u8_VALUE_WAY ==	EXTI_u8_NORMAL_WAY	)
				/* Normal Way */
				switch(Copy_u8Exti_Sense)
				{

				case EXTI_u8_TRIGG_FALLING_EDGE :

					CLR_BIT (EXTI_u8_MCUCR_REG , EXTI_u8_ISC2_BIT)	;

					break ;

				case EXTI_u8_TRIGG_RISING_EDGE :

					SET_BIT (EXTI_u8_MCUCR_REG , EXTI_u8_ISC2_BIT)	;

					break ;

				default : Local_u8ErrorState = STD_TYPES_NOK ; break ;

				}

#elif(EXTI_u8_VALUE_WAY ==	EXTI_u8_MASK_WAY	)

				/* Masking ---Better Another Way*/
				CLR_BIT(EXTI_u8_MCUCSR_REG, EXTI_u8_ISC2_BIT);
				EXTI_u8_MCUCSR_REG | =	( ( GET_BIT(Copy_u8Exti_Sense , 0 ))<< EXTI_u8_ISC2_BIT );

#else
				Local_u8ErrorState = STD_TYPES_NOK ;
#endif

				break ;

				default : Local_u8ErrorState = STD_TYPES_NOK ; break ;
	}

	/* Enable Choosen EXTI (PIE) */
	if (( Copy_u8Exti_ID <= EXTI_u8_EXTI_1 ) && ( Copy_u8Exti_ID >= EXTI_u8_EXTI_2 ) && (Local_u8ErrorState = STD_TYPES_OK ))
	{
		SET_BIT (EXTI_u8_GICR_REG , Copy_u8Exti_ID ) ;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}

	return Local_u8ErrorState ;
}

u8 EXTI_u8Disable ( u8 Copy_u8Exti_ID )
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;

	/* Disable Choosen EXTI (PIE) */
	if (( Copy_u8Exti_ID <= EXTI_u8_EXTI_1 ) && ( Copy_u8Exti_ID >= EXTI_u8_EXTI_2 ))
	{
		CLR_BIT (EXTI_u8_GICR_REG , Copy_u8Exti_ID ) ;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}

	return Local_u8ErrorState ;
}

u8 EXTI_u8SetCallBack (u8 Copy_u8Exti_ID  , void (* Copy_Pf)(void) )
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;

	if(Copy_Pf != NULL)
	{
		switch (Copy_u8Exti_ID)
		{
		case EXTI_u8_EXTI_0 :

			EXTI_APfCallBack[0] = Copy_Pf ;

			break ;

		case EXTI_u8_EXTI_1 :

			EXTI_APfCallBack[1] = Copy_Pf ;

			break ;

		case EXTI_u8_EXTI_2 :

			EXTI_APfCallBack[2] = Copy_Pf ;

			break ;

		default : Local_u8ErrorState = STD_TYPES_NOK ; break ;

		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}
	return Local_u8ErrorState ;
}

/* Proto Type Of ISR For EXTI 0 */
void __vector_1(void) 		__attribute__((signal))	;
void __vector_1(void) 
{
	if(EXTI_APfCallBack[0] != NULL)
	{
		EXTI_APfCallBack[0] ()	;
	}
}

/* Proto Type Of ISR For EXTI 1 */
void __vector_2(void) 		__attribute__((signal))	;
void __vector_2(void) 
{
	if(EXTI_APfCallBack[1] != NULL)
	{
		EXTI_APfCallBack[1] ()	;
	}
}

/* Proto Type Of ISR For EXTI 2 */
void __vector_3(void)  	 	__attribute__((signal))	;
void __vector_3(void) 
{
	if(EXTI_APfCallBack[2] != NULL)
	{
		EXTI_APfCallBack[2] ()	;
	}
}

