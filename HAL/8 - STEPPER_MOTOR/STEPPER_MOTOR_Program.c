/*************************************************************************/
/***************      Name 		:  Ahmed Abdelhady  	******************/
/***************      Date 		:  25 / 12 / 2022  		******************/
/***************      SWC 		: STEPPER_MOTOR          		******************/
/***************      Version 	:  1.0          		******************/
/*************************************************************************/

/* LIB Layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 8000000UL
#include "util/delay.h"

/* MCAL Layer */
#include "DIO_Interface.h"

/* HAL Layer */
#include "STEPPER_MOTOR_Interface.h"
#include "STEPPER_MOTOR_Private.h"
#include "STEPPER_MOTOR_Config.h"

void STEPPER_MOTOR_voidInit (void)
{
	DIO_u8SetPinDirection(STEPPER_MOTOR_u8_PORT_PIN1 , STEPPER_MOTOR_u8_PIN1 , DIO_u8_OUTPUT) ;
	DIO_u8SetPinDirection(STEPPER_MOTOR_u8_PORT_PIN2 , STEPPER_MOTOR_u8_PIN2 , DIO_u8_OUTPUT) ;
	DIO_u8SetPinDirection(STEPPER_MOTOR_u8_PORT_PIN3 , STEPPER_MOTOR_u8_PIN3 , DIO_u8_OUTPUT) ;
	DIO_u8SetPinDirection(STEPPER_MOTOR_u8_PORT_PIN4 , STEPPER_MOTOR_u8_PIN4 , DIO_u8_OUTPUT) ;
}

u8 STEPPER_MOTOR_voidTurnOn 	(u8 Copy_u8Direction , u16 Copy_u16Angle)
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;

	/* Every iteration have a 4 step and STEPPER_MOTOR needs a 2048 step for 360 deg
	 * so 2048 / 4 = 512 case full step
	 * in case half speed 2048 / 8 = 256
	 */
	u16 Local_u16Ierations =	(Copy_u16Angle * 512UL)/360 ;
	u16 Local_u16Counter = 0 ;

	if(Copy_u16Angle <= 360)
	{
		switch (Copy_u8Direction)
		{
		case STEPPER_MOTOR_u8_COUNTER_CLK_WISE :

			for(Local_u16Counter = 0 ; Local_u16Counter < Local_u16Ierations ; Local_u16Counter ++ )
			{

				/* Step 1 */
				DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT_PIN1 , STEPPER_MOTOR_u8_PIN1 , DIO_u8_LOW)  ;
				DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT_PIN2 , STEPPER_MOTOR_u8_PIN2 , DIO_u8_HIGH) ;
				DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT_PIN3 , STEPPER_MOTOR_u8_PIN3 , DIO_u8_HIGH) ;
				DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT_PIN4 , STEPPER_MOTOR_u8_PIN4 , DIO_u8_HIGH) ;

				_delay_ms(10) ;

				/* Step 2 */
				DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT_PIN1 , STEPPER_MOTOR_u8_PIN1 , DIO_u8_HIGH)  ;
				DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT_PIN2 , STEPPER_MOTOR_u8_PIN2 , DIO_u8_LOW)   ;
				DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT_PIN3 , STEPPER_MOTOR_u8_PIN3 , DIO_u8_HIGH)  ;
				DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT_PIN4 , STEPPER_MOTOR_u8_PIN4 , DIO_u8_HIGH)  ;

				_delay_ms(10) ;

				/* Step 3 */
				DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT_PIN1 , STEPPER_MOTOR_u8_PIN1 , DIO_u8_HIGH)  ;
				DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT_PIN2 , STEPPER_MOTOR_u8_PIN2 , DIO_u8_HIGH)  ;
				DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT_PIN3 , STEPPER_MOTOR_u8_PIN3 , DIO_u8_LOW)   ;
				DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT_PIN4 , STEPPER_MOTOR_u8_PIN4 , DIO_u8_HIGH)  ;

				_delay_ms(10) ;

				/* Step 4 */
				DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT_PIN1 , STEPPER_MOTOR_u8_PIN1 , DIO_u8_HIGH)  ;
				DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT_PIN2 , STEPPER_MOTOR_u8_PIN2 , DIO_u8_HIGH)  ;
				DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT_PIN3 , STEPPER_MOTOR_u8_PIN3 , DIO_u8_HIGH)  ;
				DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT_PIN4 , STEPPER_MOTOR_u8_PIN4 , DIO_u8_LOW)   ;

				_delay_ms(10) ;

			}

			break ;

		case STEPPER_MOTOR_u8_CLK_WISE :

			for(Local_u16Counter = 0 ; Local_u16Counter < Local_u16Ierations ; Local_u16Counter ++ )
			{

				/* Step 1 */
				DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT_PIN1 , STEPPER_MOTOR_u8_PIN1 , DIO_u8_HIGH)  ;
				DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT_PIN2 , STEPPER_MOTOR_u8_PIN2 , DIO_u8_HIGH) ;
				DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT_PIN3 , STEPPER_MOTOR_u8_PIN3 , DIO_u8_HIGH) ;
				DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT_PIN4 , STEPPER_MOTOR_u8_PIN4 , DIO_u8_LOW) ;

				_delay_ms(10) ;

				/* Step 2 */
				DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT_PIN1 , STEPPER_MOTOR_u8_PIN1 , DIO_u8_HIGH)  ;
				DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT_PIN2 , STEPPER_MOTOR_u8_PIN2 , DIO_u8_HIGH)   ;
				DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT_PIN3 , STEPPER_MOTOR_u8_PIN3 , DIO_u8_LOW)  ;
				DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT_PIN4 , STEPPER_MOTOR_u8_PIN4 , DIO_u8_HIGH)  ;

				_delay_ms(10) ;

				/* Step 3 */
				DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT_PIN1 , STEPPER_MOTOR_u8_PIN1 , DIO_u8_HIGH)  ;
				DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT_PIN2 , STEPPER_MOTOR_u8_PIN2 , DIO_u8_LOW)  ;
				DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT_PIN3 , STEPPER_MOTOR_u8_PIN3 , DIO_u8_HIGH)   ;
				DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT_PIN4 , STEPPER_MOTOR_u8_PIN4 , DIO_u8_HIGH)  ;

				_delay_ms(10) ;

				/* Step 4 */
				DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT_PIN1 , STEPPER_MOTOR_u8_PIN1 , DIO_u8_LOW)  ;
				DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT_PIN2 , STEPPER_MOTOR_u8_PIN2 , DIO_u8_HIGH)  ;
				DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT_PIN3 , STEPPER_MOTOR_u8_PIN3 , DIO_u8_HIGH)  ;
				DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT_PIN4 , STEPPER_MOTOR_u8_PIN4 , DIO_u8_HIGH)   ;

				_delay_ms(10) ;
			}

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

void STEPPER_MOTOR_voidTurnOff 	(void)
{
	DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT_PIN1 , STEPPER_MOTOR_u8_PIN1 , DIO_u8_HIGH)  ;
	DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT_PIN2 , STEPPER_MOTOR_u8_PIN2 , DIO_u8_HIGH)  ;
	DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT_PIN3 , STEPPER_MOTOR_u8_PIN3 , DIO_u8_HIGH)  ;
	DIO_u8SetPinValue(STEPPER_MOTOR_u8_PORT_PIN4 , STEPPER_MOTOR_u8_PIN4 , DIO_u8_HIGH)   ;
}









