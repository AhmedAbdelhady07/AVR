/*************************************************************************/
/***************      Name 		:  Ahmed Abdelhady  	******************/
/***************      Date 		:  25 / 12 / 2022  		******************/
/***************      SWC 		:  BUZZER          		******************/
/***************      Version 	:  1.0          		******************/
/*************************************************************************/

/* LIB Layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL Layer */
#include "DIO_Interface.h"

/* HAL Layer */
#include "BUZZER_Interface.h"
#include "BUZZER_Private.h"
#include "BUZZER_Config.h"
										 
void BUZZER_voidInit (void) 
{
	DIO_u8SetPinDirection(BUZZER_u8_PORT , BUZZER_u8_PIN , DIO_u8_OUTPUT) ;
}

void BUZZER_voidTurnOn 	(void)
{
	DIO_u8SetPinValue(BUZZER_u8_PORT , BUZZER_u8_PIN , DIO_u8_HIGH) ;
}
void BUZZER_voidTurnOff 	(void)
{
	DIO_u8SetPinValue(BUZZER_u8_PORT , BUZZER_u8_PIN , DIO_u8_LOW) ;
}

	
	
	
	
	
	
	
	
