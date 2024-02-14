/*************************************************************************/
/***************      Name 		:  Ahmed Abdelhady  	******************/
/***************      Date 		:  25 / 12 / 2022  		******************/
/***************      SWC 		:  DC_MOTOR          		******************/
/***************      Version 	:  1.0          		******************/
/*************************************************************************/

/* LIB Layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL Layer */
#include "DIO_Interface.h"

/* HAL Layer */
#include "DC_MOTOR_Interface.h"
#include "DC_MOTOR_Private.h"
#include "DC_MOTOR_Config.h"

void DC_MOTOR_voidInit (void) 
{
#if (DC_MOTOR_u8_MODE == DC_MOTOR_u8_ONE_WAY)
	DIO_u8SetPinDirection(DC_MOTOR_u8_PORT , DC_MOTOR_u8_PIN , DIO_u8_OUTPUT) ;
#elif (DC_MOTOR_u8_MODE == DC_MOTOR_u8_TWO_WAYS_HBRIDGE)
	DIO_u8SetPinDirection(DC_MOTOR_u8_PORT_PIN1 , DC_MOTOR_u8_PIN1 , DIO_u8_OUTPUT) ;
	DIO_u8SetPinDirection(DC_MOTOR_u8_PORT_PIN2 , DC_MOTOR_u8_PIN2 , DIO_u8_OUTPUT) ;
#endif
}

u8 DC_MOTOR_voidTurnOn 	(u8 Copy_u8direction)
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;

#if (DC_MOTOR_u8_MODE == DC_MOTOR_u8_ONE_WAY)
	DIO_u8SetPinValue(DC_MOTOR_u8_PORT ,DC_MOTOR_u8_PIN , DIO_u8_HIGH ) ;
#elif (DC_MOTOR_u8_MODE == DC_MOTOR_u8_TWO_WAYS_HBRIDGE)
	switch(Copy_u8direction)
	{
	case DC_MOTOR_u8_WITHCLKWISE :

		DIO_u8SetPinValue(DC_MOTOR_u8_PORT_PIN2 ,DC_MOTOR_u8_PIN2 , DIO_u8_LOW ) ;
		DIO_u8SetPinValue(DC_MOTOR_u8_PORT_PIN1 ,DC_MOTOR_u8_PIN1 , DIO_u8_HIGH ) ;

		break ;

	case DC_MOTOR_u8_COUNTERCLKWISE :

		DIO_u8SetPinValue(DC_MOTOR_u8_PORT_PIN1 ,DC_MOTOR_u8_PIN1 , DIO_u8_LOW ) ;
		DIO_u8SetPinValue(DC_MOTOR_u8_PORT_PIN2 ,DC_MOTOR_u8_PIN2 , DIO_u8_HIGH ) ;

		break ;

	default : Local_u8ErrorState = STD_TYPES_NOK ; break ;

	}

#else
	Local_u8ErrorState = STD_TYPES_NOK ;

#endif

	return Local_u8ErrorState ;
}

void DC_MOTOR_voidTurnOff 	(void)
{

#if (DC_MOTOR_u8_MODE == DC_MOTOR_u8_ONE_WAY)
	DIO_u8SetPinValue(DC_MOTOR_u8_PORT ,DC_MOTOR_u8_PIN , DIO_u8_LOW ) ;
#elif (DC_MOTOR_u8_MODE == DC_MOTOR_u8_TWO_WAYS_HBRIDGE)

		DIO_u8SetPinValue(DC_MOTOR_u8_PORT_PIN2 ,DC_MOTOR_u8_PIN1 , DIO_u8_LOW ) ;
		DIO_u8SetPinValue(DC_MOTOR_u8_PORT_PIN1 ,DC_MOTOR_u8_PIN2 , DIO_u8_LOW ) ;
#endif
}









