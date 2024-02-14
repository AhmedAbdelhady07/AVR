/********************************************************************************************************************/
/*****************     Author 		: Ahmed Abdelhady 	*************************************************************/
/*****************     File 		: Program Of LED  	*************************************************************/
/*****************     Date 		: 1/1/2023  		*************************************************************/
/*****************     Version 		: 1.0  				*************************************************************/
/*****************     Description 	: Drive For LED 	*************************************************************/
/********************************************************************************************************************/

/* LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "LED_private.h"
#include "LED_config.h"
#include "LED_interface.h"

u8 LED_voidInit			(u8 Copy_u8LedNumber)
{

	u8 Local_u8ErrorState = STD_TYPES_OK ;

#if(LED_u8_LED_MODE == LED_u8_LED_FORWARD)

	switch (Copy_u8LedNumber)
	{
	case LED_u8_LED1 	:		DIO_u8SetPinDirection 			( LED_u8_LED1_PORT , LED_u8_LED1_PIN , DIO_u8_OUTPUT ) 	; break ;
	case LED_u8_LED2 	:		DIO_u8SetPinDirection 			( LED_u8_LED2_PORT , LED_u8_LED2_PIN , DIO_u8_OUTPUT ) 	; break ;
	case LED_u8_LED3 	:		DIO_u8SetPinDirection 			( LED_u8_LED3_PORT , LED_u8_LED3_PIN , DIO_u8_OUTPUT ) 	; break ;
	case LED_u8_LED4 	:		DIO_u8SetPinDirection 			( LED_u8_LED4_PORT , LED_u8_LED4_PIN , DIO_u8_OUTPUT ) 	; break ;
	case LED_u8_LED5 	:		DIO_u8SetPinDirection 			( LED_u8_LED5_PORT , LED_u8_LED5_PIN , DIO_u8_OUTPUT ) 	; break ;
	case LED_u8_LED6 	:		DIO_u8SetPinDirection 			( LED_u8_LED6_PORT , LED_u8_LED6_PIN , DIO_u8_OUTPUT ) 	; break ;
	case LED_u8_LED7 	:		DIO_u8SetPinDirection 			( LED_u8_LED7_PORT , LED_u8_LED7_PIN , DIO_u8_OUTPUT ) 	; break ;
	case LED_u8_LED8 	:		DIO_u8SetPinDirection 			( LED_u8_LED8_PORT , LED_u8_LED8_PIN , DIO_u8_OUTPUT ) 	; break ;
	default 			:		Local_u8ErrorState = STD_TYPES_NOK 													    ; break ;
	}

#elif(LED_u8_LED_MODE == LED_u8_LED_REVERSE)
	switch (Copy_u8LedNumber)
	{
	case LED_u8_LED1 	:		DIO_u8SetPinDirection 			( LED_u8_LED1_PORT , LED_u8_LED1_PIN , DIO_u8_INPUT ) 	; break ;
	case LED_u8_LED2 	:		DIO_u8SetPinDirection 			( LED_u8_LED2_PORT , LED_u8_LED2_PIN , DIO_u8_INPUT ) 	; break ;
	case LED_u8_LED3 	:		DIO_u8SetPinDirection 			( LED_u8_LED3_PORT , LED_u8_LED3_PIN , DIO_u8_INPUT ) 	; break ;
	case LED_u8_LED4 	:		DIO_u8SetPinDirection 			( LED_u8_LED4_PORT , LED_u8_LED4_PIN , DIO_u8_INPUT ) 	; break ;
	case LED_u8_LED5 	:		DIO_u8SetPinDirection 			( LED_u8_LED5_PORT , LED_u8_LED5_PIN , DIO_u8_INPUT ) 	; break ;
	case LED_u8_LED6 	:		DIO_u8SetPinDirection 			( LED_u8_LED6_PORT , LED_u8_LED6_PIN , DIO_u8_INPUT ) 	; break ;
	case LED_u8_LED7 	:		DIO_u8SetPinDirection 			( LED_u8_LED7_PORT , LED_u8_LED7_PIN , DIO_u8_INPUT ) 	; break ;
	case LED_u8_LED8 	:		DIO_u8SetPinDirection 			( LED_u8_LED8_PORT , LED_u8_LED8_PIN , DIO_u8_INPUT ) 	; break ;
	default 			:		Local_u8ErrorState = STD_TYPES_NOK 														; break ;
	}

#else
	Local_u8ErrorState = STD_TYPES_NOK ;

#endif

	return Local_u8ErrorState ;

}

u8 LED_u8TurnLed_ON 		(u8 Copy_u8LedNumber)
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;

#if(LED_u8_LED_MODE == LED_u8_LED_FORWARD)

	switch (Copy_u8LedNumber)
	{
	case LED_u8_LED1 	:		DIO_u8SetPinValue 			( LED_u8_LED1_PORT , LED_u8_LED1_PIN , DIO_u8_HIGH ) 	; break ;
	case LED_u8_LED2 	:		DIO_u8SetPinValue 			( LED_u8_LED2_PORT , LED_u8_LED2_PIN , DIO_u8_HIGH ) 	; break ;
	case LED_u8_LED3 	:		DIO_u8SetPinValue 			( LED_u8_LED3_PORT , LED_u8_LED3_PIN , DIO_u8_HIGH ) 	; break ;
	case LED_u8_LED4 	:		DIO_u8SetPinValue 			( LED_u8_LED4_PORT , LED_u8_LED4_PIN , DIO_u8_HIGH ) 	; break ;
	case LED_u8_LED5 	:		DIO_u8SetPinValue 			( LED_u8_LED5_PORT , LED_u8_LED5_PIN , DIO_u8_HIGH ) 	; break ;
	case LED_u8_LED6 	:		DIO_u8SetPinValue 			( LED_u8_LED6_PORT , LED_u8_LED6_PIN , DIO_u8_HIGH ) 	; break ;
	case LED_u8_LED7 	:		DIO_u8SetPinValue 			( LED_u8_LED7_PORT , LED_u8_LED7_PIN , DIO_u8_HIGH ) 	; break ;
	case LED_u8_LED8 	:		DIO_u8SetPinValue 			( LED_u8_LED8_PORT , LED_u8_LED8_PIN , DIO_u8_HIGH ) 	; break ;
	default 			:		Local_u8ErrorState = STD_TYPES_NOK 													; break ;
	}

#elif(LED_u8_LED_MODE == LED_u8_LED_REVERSE)
	switch (Copy_u8LedNumber)
	{
	case LED_u8_LED1 	:		DIO_u8SetPinValue 			( LED_u8_LED1_PORT , LED_u8_LED1_PIN , DIO_u8_LOW ) 	; break ;
	case LED_u8_LED2 	:		DIO_u8SetPinValue 			( LED_u8_LED2_PORT , LED_u8_LED2_PIN , DIO_u8_LOW ) 	; break ;
	case LED_u8_LED3 	:		DIO_u8SetPinValue 			( LED_u8_LED3_PORT , LED_u8_LED3_PIN , DIO_u8_LOW ) 	; break ;
	case LED_u8_LED4 	:		DIO_u8SetPinValue 			( LED_u8_LED4_PORT , LED_u8_LED4_PIN , DIO_u8_LOW ) 	; break ;
	case LED_u8_LED5 	:		DIO_u8SetPinValue 			( LED_u8_LED5_PORT , LED_u8_LED5_PIN , DIO_u8_LOW ) 	; break ;
	case LED_u8_LED6 	:		DIO_u8SetPinValue 			( LED_u8_LED6_PORT , LED_u8_LED6_PIN , DIO_u8_LOW ) 	; break ;
	case LED_u8_LED7 	:		DIO_u8SetPinValue 			( LED_u8_LED7_PORT , LED_u8_LED7_PIN , DIO_u8_LOW ) 	; break ;
	case LED_u8_LED8 	:		DIO_u8SetPinValue 			( LED_u8_LED8_PORT , LED_u8_LED8_PIN , DIO_u8_LOW ) 	; break ;
	default 			:		Local_u8ErrorState = STD_TYPES_NOK 	 												; break ;
	}

#else
	Local_u8ErrorState = STD_TYPES_NOK ;

#endif

	return Local_u8ErrorState ;
}

u8 LED_u8TurnLed_OFF 	(u8 Copy_u8LedNumber)
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;

#if(LED_u8_LED_MODE == LED_u8_LED_FORWARD)

	switch (Copy_u8LedNumber)
	{
	case LED_u8_LED1 	:		DIO_u8SetPinValue 			( LED_u8_LED1_PORT , LED_u8_LED1_PIN , DIO_u8_LOW ) 	; break ;
	case LED_u8_LED2 	:		DIO_u8SetPinValue 			( LED_u8_LED2_PORT , LED_u8_LED2_PIN , DIO_u8_LOW ) 	; break ;
	case LED_u8_LED3 	:		DIO_u8SetPinValue 			( LED_u8_LED3_PORT , LED_u8_LED3_PIN , DIO_u8_LOW ) 	; break ;
	case LED_u8_LED4 	:		DIO_u8SetPinValue 			( LED_u8_LED4_PORT , LED_u8_LED4_PIN , DIO_u8_LOW ) 	; break ;
	case LED_u8_LED5 	:		DIO_u8SetPinValue 			( LED_u8_LED5_PORT , LED_u8_LED5_PIN , DIO_u8_LOW ) 	; break ;
	case LED_u8_LED6 	:		DIO_u8SetPinValue 			( LED_u8_LED6_PORT , LED_u8_LED6_PIN , DIO_u8_LOW ) 	; break ;
	case LED_u8_LED7 	:		DIO_u8SetPinValue 			( LED_u8_LED7_PORT , LED_u8_LED7_PIN , DIO_u8_LOW ) 	; break ;
	case LED_u8_LED8 	:		DIO_u8SetPinValue 			( LED_u8_LED8_PORT , LED_u8_LED8_PIN , DIO_u8_LOW ) 	; break ;
	default 			:		Local_u8ErrorState = STD_TYPES_NOK  												; break ;
	}

#elif(LED_u8_LED_MODE == LED_u8_LED_REVERSE)
	switch (Copy_u8LedNumber)
	{
	case LED_u8_LED1 	:		DIO_u8SetPinValue 			( LED_u8_LED1_PORT , LED_u8_LED1_PIN , DIO_u8_HIGH ) 	; break ;
	case LED_u8_LED2 	:		DIO_u8SetPinValue 			( LED_u8_LED2_PORT , LED_u8_LED2_PIN , DIO_u8_HIGH ) 	; break ;
	case LED_u8_LED3 	:		DIO_u8SetPinValue 			( LED_u8_LED3_PORT , LED_u8_LED3_PIN , DIO_u8_HIGH ) 	; break ;
	case LED_u8_LED4 	:		DIO_u8SetPinValue 			( LED_u8_LED4_PORT , LED_u8_LED4_PIN , DIO_u8_HIGH ) 	; break ;
	case LED_u8_LED5 	:		DIO_u8SetPinValue 			( LED_u8_LED5_PORT , LED_u8_LED5_PIN , DIO_u8_HIGH ) 	; break ;
	case LED_u8_LED6 	:		DIO_u8SetPinValue 			( LED_u8_LED6_PORT , LED_u8_LED6_PIN , DIO_u8_HIGH ) 	; break ;
	case LED_u8_LED7 	:		DIO_u8SetPinValue 			( LED_u8_LED7_PORT , LED_u8_LED7_PIN , DIO_u8_HIGH ) 	; break ;
	case LED_u8_LED8 	:		DIO_u8SetPinValue 			( LED_u8_LED8_PORT , LED_u8_LED8_PIN , DIO_u8_HIGH ) 	; break ;
	default 			:		Local_u8ErrorState = STD_TYPES_NOK  												; break ;
	}

#else
	Local_u8ErrorState = STD_TYPES_NOK ;

#endif

	return Local_u8ErrorState ;
}

u8 LED_u8GetLedStatus	(u8 Copy_u8LedNumber , u8 * Copy_Pu8ReturnedLedStatus) 
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;

	u8 Local_u8ReturnedPinValue  ;
	
	if(Copy_Pu8ReturnedLedStatus != NULL)
	{

	switch (Copy_u8LedNumber)
	{
	case LED_u8_LED1 	:{	* Copy_Pu8ReturnedLedStatus = 	DIO_u8GetPinValue 				( LED_u8_LED1_PORT , LED_u8_LED1_PIN , &Local_u8ReturnedPinValue )     ; break ;		}
	case LED_u8_LED2 	:{	* Copy_Pu8ReturnedLedStatus =	DIO_u8GetPinValue 				( LED_u8_LED2_PORT , LED_u8_LED2_PIN , &Local_u8ReturnedPinValue ) 	   ; break ;		}
	case LED_u8_LED3 	:{	* Copy_Pu8ReturnedLedStatus =	DIO_u8GetPinValue 				( LED_u8_LED3_PORT , LED_u8_LED3_PIN , &Local_u8ReturnedPinValue ) 	   ; break ;		}
	case LED_u8_LED4 	:{	* Copy_Pu8ReturnedLedStatus =	DIO_u8GetPinValue 				( LED_u8_LED4_PORT , LED_u8_LED4_PIN , &Local_u8ReturnedPinValue ) 	   ; break ;		}
	case LED_u8_LED5 	:{	* Copy_Pu8ReturnedLedStatus =	DIO_u8GetPinValue 				( LED_u8_LED5_PORT , LED_u8_LED5_PIN , &Local_u8ReturnedPinValue ) 	   ; break ;		}
	case LED_u8_LED6 	:{	* Copy_Pu8ReturnedLedStatus =	DIO_u8GetPinValue 				( LED_u8_LED6_PORT , LED_u8_LED6_PIN , &Local_u8ReturnedPinValue ) 	   ; break ;		}
	case LED_u8_LED7 	:{	* Copy_Pu8ReturnedLedStatus =	DIO_u8GetPinValue 				( LED_u8_LED7_PORT , LED_u8_LED7_PIN , &Local_u8ReturnedPinValue ) 	   ; break ;		}
	case LED_u8_LED8 	:{	* Copy_Pu8ReturnedLedStatus =	DIO_u8GetPinValue 				( LED_u8_LED8_PORT , LED_u8_LED8_PIN , &Local_u8ReturnedPinValue ) 	   ; break ;		}
	default 			:{		Local_u8ErrorState 			  = STD_TYPES_NOK 																					   ; break ;		}
	}

	* Copy_Pu8ReturnedLedStatus = Local_u8ReturnedPinValue ;
	}
	else
	{
		Local_u8ErrorState 			  = STD_TYPES_NOK ;
	}

	return Local_u8ErrorState ;

}

u8 LED_u8ToggleLed			(u8 Copy_u8LedNumber)
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;

	switch (Copy_u8LedNumber)
	{
	case LED_u8_LED1 	:		DIO_u8TogglePinValue 			( LED_u8_LED1_PORT , LED_u8_LED1_PIN ) 	; break ;
	case LED_u8_LED2 	:		DIO_u8TogglePinValue 			( LED_u8_LED2_PORT , LED_u8_LED2_PIN ) 	; break ;
	case LED_u8_LED3 	:		DIO_u8TogglePinValue 			( LED_u8_LED3_PORT , LED_u8_LED3_PIN ) 	; break ;
	case LED_u8_LED4 	:		DIO_u8TogglePinValue 			( LED_u8_LED4_PORT , LED_u8_LED4_PIN ) 	; break ;
	case LED_u8_LED5 	:		DIO_u8TogglePinValue 			( LED_u8_LED5_PORT , LED_u8_LED5_PIN ) 	; break ;
	case LED_u8_LED6 	:		DIO_u8TogglePinValue 			( LED_u8_LED6_PORT , LED_u8_LED6_PIN ) 	; break ;
	case LED_u8_LED7 	:		DIO_u8TogglePinValue 			( LED_u8_LED7_PORT , LED_u8_LED7_PIN ) 	; break ;
	case LED_u8_LED8 	:		DIO_u8TogglePinValue 			( LED_u8_LED8_PORT , LED_u8_LED8_PIN ) 	; break ;
	default 			:		Local_u8ErrorState = STD_TYPES_NOK 										; break ;
	}

	return Local_u8ErrorState ;
}
