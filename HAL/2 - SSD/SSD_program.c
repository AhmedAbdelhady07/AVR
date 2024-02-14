/********************************************************************************************************************/
/*****************     Author 		: Ahmed Abdelhady 	*************************************************************/
/*****************     File 		: Program Of SSD  	*************************************************************/
/*****************     Date 		: 1/1/2023  		*************************************************************/
/*****************     Version 		: 1.0  				*************************************************************/
/*****************     Description 	: Drive For SSD 	*************************************************************/
/********************************************************************************************************************/

/* LIB Layer */
#include "util/delay.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL Layer */
#include "DIO_interface.h"

/* HAL Layer */
#include "SSD_private.h"
#include "SSD_config.h"
#include "SSD_interface.h"

/* SSD1 On Left ... SSD2 On Right*/

u8 SSD_u8Init	(u8 Copy_u8SSDNumberOfDevices)
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;

	switch(Copy_u8SSDNumberOfDevices)
	{
	case SSD_u8_ONE_DEVICE :
		DIO_u8SetPinDirection 			( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_OUTPUT) ;
		DIO_u8SetPinDirection 			( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN , DIO_u8_OUTPUT) ;
		DIO_u8SetPinDirection 			( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_OUTPUT) ;
		DIO_u8SetPinDirection 			( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_OUTPUT) ;
		DIO_u8SetPinDirection 			( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN , DIO_u8_OUTPUT) ;
		DIO_u8SetPinDirection 			( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN , DIO_u8_OUTPUT) ;
		DIO_u8SetPinDirection 			( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_OUTPUT) ;
		DIO_u8SetPinDirection 			( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_OUTPUT) ;

		DIO_u8SetPinDirection 			( SSD_u8_SSD1_ENABLE_PORT , SSD_u8_SSD1_ENABLE_PIN , DIO_u8_OUTPUT) ;

		break ;

	case SSD_u8_TWO_DEVICES :

#if (SSD_u8_SSD_MODE_VISION == SSD_u8_SSD_NORMAL_MODE)
		DIO_u8SetPinDirection 			( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_OUTPUT) ;
		DIO_u8SetPinDirection 			( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN , DIO_u8_OUTPUT) ;
		DIO_u8SetPinDirection 			( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_OUTPUT) ;
		DIO_u8SetPinDirection 			( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_OUTPUT) ;
		DIO_u8SetPinDirection 			( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN , DIO_u8_OUTPUT) ;
		DIO_u8SetPinDirection 			( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN , DIO_u8_OUTPUT) ;
		DIO_u8SetPinDirection 			( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_OUTPUT) ;
		DIO_u8SetPinDirection 			( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_OUTPUT) ;

		DIO_u8SetPinDirection 			( SSD_u8_SSD1_ENABLE_PORT , SSD_u8_SSD1_ENABLE_PIN , DIO_u8_OUTPUT) ;

		DIO_u8SetPinDirection 			( SSD_u8_SSD2_LED_A_PORT , SSD_u8_SSD2_LED_A_PIN , DIO_u8_OUTPUT) ;
		DIO_u8SetPinDirection 			( SSD_u8_SSD2_LED_B_PORT , SSD_u8_SSD2_LED_B_PIN , DIO_u8_OUTPUT) ;
		DIO_u8SetPinDirection 			( SSD_u8_SSD2_LED_C_PORT , SSD_u8_SSD2_LED_C_PIN , DIO_u8_OUTPUT) ;
		DIO_u8SetPinDirection 			( SSD_u8_SSD2_LED_D_PORT , SSD_u8_SSD2_LED_D_PIN , DIO_u8_OUTPUT) ;
		DIO_u8SetPinDirection 			( SSD_u8_SSD2_LED_E_PORT , SSD_u8_SSD2_LED_E_PIN , DIO_u8_OUTPUT) ;
		DIO_u8SetPinDirection 			( SSD_u8_SSD2_LED_F_PORT , SSD_u8_SSD2_LED_F_PIN , DIO_u8_OUTPUT) ;
		DIO_u8SetPinDirection 			( SSD_u8_SSD2_LED_G_PORT , SSD_u8_SSD2_LED_G_PIN , DIO_u8_OUTPUT) ;
		DIO_u8SetPinDirection 			( SSD_u8_SSD2_LED_DOT_PORT , SSD_u8_SSD2_LED_DOT_PIN , DIO_u8_OUTPUT) ;

		DIO_u8SetPinDirection 			( SSD_u8_SSD2_ENABLE_PORT , SSD_u8_SSD2_ENABLE_PIN , DIO_u8_OUTPUT) ;

#elif(SSD_u8_SSD_MODE_VISION == SSD_u8_SSD_POV_MODE)
		DIO_u8SetPinDirection 			( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_OUTPUT) ;
		DIO_u8SetPinDirection 			( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN , DIO_u8_OUTPUT) ;
		DIO_u8SetPinDirection 			( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_OUTPUT) ;
		DIO_u8SetPinDirection 			( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_OUTPUT) ;
		DIO_u8SetPinDirection 			( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN , DIO_u8_OUTPUT) ;
		DIO_u8SetPinDirection 			( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN , DIO_u8_OUTPUT) ;
		DIO_u8SetPinDirection 			( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_OUTPUT) ;
		DIO_u8SetPinDirection 			( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_OUTPUT) ;

		DIO_u8SetPinDirection 			( SSD_u8_SSD1_ENABLE_PORT , SSD_u8_SSD1_ENABLE_PIN , DIO_u8_OUTPUT) ;
		DIO_u8SetPinDirection 			( SSD_u8_SSD2_ENABLE_PORT , SSD_u8_SSD2_ENABLE_PIN , DIO_u8_OUTPUT) ;

#else
		Local_u8ErrorState = STD_TYPES_NOK ;
#endif

		break ;

	default 		: Local_u8ErrorState = STD_TYPES_NOK ; break ;

	}

	/* Disable Two SSD */
	#if(SSD_u8_SSD_MODE == SSD_u8_SSD_COMMON_CATHODE)
	DIO_u8SetPinValue 				( SSD_u8_SSD1_ENABLE_PORT , SSD_u8_SSD1_ENABLE_PIN , DIO_u8_HIGH ) ;
	DIO_u8SetPinValue 				( SSD_u8_SSD2_ENABLE_PORT , SSD_u8_SSD2_ENABLE_PIN , DIO_u8_HIGH ) ;
	#elif(SSD_u8_SSD_MODE == SSD_u8_SSD_COMMON_ANODE)
	DIO_u8SetPinValue 				( SSD_u8_SSD1_ENABLE_PORT , SSD_u8_SSD1_ENABLE_PIN , DIO_u8_LOW ) ;
	DIO_u8SetPinValue 				( SSD_u8_SSD2_ENABLE_PORT , SSD_u8_SSD2_ENABLE_PIN , DIO_u8_LOW ) ;
	#elif
	Local_u8ErrorState = STD_TYPES_NOK ;
	#endif

	return 	Local_u8ErrorState ;
}


u8 SSD_u8DisplayNumber (u8 Copy_u8Number)
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;
	u8 Local_u8Numer1 , Local_u8Numer2   ;
	u16 Local_u8CounterDelay = 0  ;

	if(Copy_u8Number <= 99)
	{

		Local_u8Numer1 = Copy_u8Number / 10 ;
		Local_u8Numer2 = Copy_u8Number % 10 ;

		for (Local_u8CounterDelay = 0 ;  Local_u8CounterDelay <= SSD_u8_DELAY_TIME  ; Local_u8CounterDelay++ )
		{
#if(SSD_u8_SSD_MODE == SSD_u8_SSD_COMMON_CATHODE)		
#if (SSD_u8_SSD_MODE_VISION == SSD_u8_SSD_NORMAL_MODE)
			/* Write Number 1 on SSD1 */
			switch (Local_u8Numer1)
			{
			case NUMBER_ZERO :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_LOW ) ;

				break ;

			case NUMBER_ONE :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_LOW ) ;

				break ;

			case NUMBER_TWO :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_LOW) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_LOW ) ;

				break ;

			case NUMBER_THREE :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_LOW ) ;

				break ;

			case NUMBER_FOUR :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN ,  DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_HIGH  ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN ,  DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN ,  DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_LOW   ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_HIGH   ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN ,  DIO_u8_HIGH) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_LOW ) ;

				break ;

			case NUMBER_FIVE :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_LOW ) ;

				break ;

			case NUMBER_SIX :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_LOW ) ;

				break ;

			case NUMBER_SEVEN :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_LOW ) ;

				break ;

			case NUMBER_EIGHT :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_LOW ) ;

				break ;

			case NUMBER_NINE :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_LOW ) ;

				break ;

			default : Local_u8ErrorState = STD_TYPES_NOK ; break ;

			}

			/* Write Number 2 on SSD2 */
			switch (Local_u8Numer2)
			{
			case NUMBER_ZERO :
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_A_PORT , SSD_u8_SSD2_LED_A_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_B_PORT , SSD_u8_SSD2_LED_B_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_C_PORT , SSD_u8_SSD2_LED_C_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_D_PORT , SSD_u8_SSD2_LED_D_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_E_PORT , SSD_u8_SSD2_LED_E_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_F_PORT , SSD_u8_SSD2_LED_F_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_G_PORT , SSD_u8_SSD2_LED_G_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_DOT_PORT , SSD_u8_SSD2_LED_DOT_PIN , DIO_u8_LOW ) ;

				break ;

			case NUMBER_ONE :
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_A_PORT , SSD_u8_SSD2_LED_A_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_B_PORT , SSD_u8_SSD2_LED_B_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_C_PORT , SSD_u8_SSD2_LED_C_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_D_PORT , SSD_u8_SSD2_LED_D_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_E_PORT , SSD_u8_SSD2_LED_E_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_F_PORT , SSD_u8_SSD2_LED_F_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_G_PORT , SSD_u8_SSD2_LED_G_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_DOT_PORT , SSD_u8_SSD2_LED_DOT_PIN , DIO_u8_LOW ) ;

				break ;

			case NUMBER_TWO :
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_A_PORT , SSD_u8_SSD2_LED_A_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_B_PORT , SSD_u8_SSD2_LED_B_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_C_PORT , SSD_u8_SSD2_LED_C_PIN , DIO_u8_LOW) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_D_PORT , SSD_u8_SSD2_LED_D_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_E_PORT , SSD_u8_SSD2_LED_E_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_F_PORT , SSD_u8_SSD2_LED_F_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_G_PORT , SSD_u8_SSD2_LED_G_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_DOT_PORT , SSD_u8_SSD2_LED_DOT_PIN , DIO_u8_LOW ) ;

				break ;

			case NUMBER_THREE :
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_LOW ) ;

				break ;

			case NUMBER_FOUR :
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_A_PORT , SSD_u8_SSD2_LED_A_PIN ,  DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_B_PORT , SSD_u8_SSD2_LED_B_PIN  , DIO_u8_HIGH  ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_C_PORT , SSD_u8_SSD2_LED_C_PIN ,  DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_D_PORT , SSD_u8_SSD2_LED_D_PIN ,  DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_E_PORT , SSD_u8_SSD2_LED_E_PIN  , DIO_u8_LOW   ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_F_PORT , SSD_u8_SSD2_LED_F_PIN  , DIO_u8_HIGH   ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_G_PORT , SSD_u8_SSD2_LED_G_PIN ,  DIO_u8_HIGH) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_DOT_PORT , SSD_u8_SSD2_LED_DOT_PIN , DIO_u8_LOW ) ;

				break ;

			case NUMBER_FIVE :
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_A_PORT , SSD_u8_SSD2_LED_A_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_B_PORT , SSD_u8_SSD2_LED_B_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_C_PORT , SSD_u8_SSD2_LED_C_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_D_PORT , SSD_u8_SSD2_LED_D_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_E_PORT , SSD_u8_SSD2_LED_E_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_F_PORT , SSD_u8_SSD2_LED_F_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_G_PORT , SSD_u8_SSD2_LED_G_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_DOT_PORT , SSD_u8_SSD2_LED_DOT_PIN , DIO_u8_LOW ) ;

				break ;

			case NUMBER_SIX :
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_A_PORT , SSD_u8_SSD2_LED_A_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_B_PORT , SSD_u8_SSD2_LED_B_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_C_PORT , SSD_u8_SSD2_LED_C_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_D_PORT , SSD_u8_SSD2_LED_D_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_E_PORT , SSD_u8_SSD2_LED_E_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_F_PORT , SSD_u8_SSD2_LED_F_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_G_PORT , SSD_u8_SSD2_LED_G_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_DOT_PORT , SSD_u8_SSD2_LED_DOT_PIN , DIO_u8_LOW ) ;

				break ;

			case NUMBER_SEVEN :
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_A_PORT , SSD_u8_SSD2_LED_A_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_B_PORT , SSD_u8_SSD2_LED_B_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_C_PORT , SSD_u8_SSD2_LED_C_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_D_PORT , SSD_u8_SSD2_LED_D_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_E_PORT , SSD_u8_SSD2_LED_E_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_F_PORT , SSD_u8_SSD2_LED_F_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_G_PORT , SSD_u8_SSD2_LED_G_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_DOT_PORT , SSD_u8_SSD2_LED_DOT_PIN , DIO_u8_LOW ) ;

				break ;

			case NUMBER_EIGHT :
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_A_PORT , SSD_u8_SSD2_LED_A_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_B_PORT , SSD_u8_SSD2_LED_B_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_C_PORT , SSD_u8_SSD2_LED_C_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_D_PORT , SSD_u8_SSD2_LED_D_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_E_PORT , SSD_u8_SSD2_LED_E_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_F_PORT , SSD_u8_SSD2_LED_F_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_G_PORT , SSD_u8_SSD2_LED_G_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_DOT_PORT , SSD_u8_SSD2_LED_DOT_PIN , DIO_u8_LOW ) ;

				break ;

			case NUMBER_NINE :
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_A_PORT , SSD_u8_SSD2_LED_A_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_B_PORT , SSD_u8_SSD2_LED_B_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_C_PORT , SSD_u8_SSD2_LED_C_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_D_PORT , SSD_u8_SSD2_LED_D_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_E_PORT , SSD_u8_SSD2_LED_E_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_F_PORT , SSD_u8_SSD2_LED_F_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_G_PORT , SSD_u8_SSD2_LED_G_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD2_LED_DOT_PORT , SSD_u8_SSD2_LED_DOT_PIN , DIO_u8_LOW ) ;

				break ;

			default : Local_u8ErrorState = STD_TYPES_NOK ; break ;

			}

			/* Enabled Two SSD */
			DIO_u8SetPinValue 				( SSD_u8_SSD1_ENABLE_PORT , SSD_u8_SSD1_ENABLE_PIN , DIO_u8_LOW ) ;
			DIO_u8SetPinValue 				( SSD_u8_SSD2_ENABLE_PORT , SSD_u8_SSD2_ENABLE_PIN , DIO_u8_LOW ) ;

#elif(SSD_u8_SSD_MODE_VISION == SSD_u8_SSD_POV_MODE)

			/* Write Number 1 on SSD1 */
			switch (Local_u8Numer1)
			{
			case NUMBER_ZERO :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_LOW ) ;

				break ;

			case NUMBER_ONE :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_LOW ) ;

				break ;

			case NUMBER_TWO :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_LOW) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_LOW ) ;

				break ;

			case NUMBER_THREE :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_LOW ) ;

				break ;

			case NUMBER_FOUR :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN ,  DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_HIGH  ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN ,  DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN ,  DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_LOW   ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_HIGH   ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN ,  DIO_u8_HIGH) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_LOW ) ;

				break ;

			case NUMBER_FIVE :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_LOW ) ;

				break ;

			case NUMBER_SIX :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_LOW ) ;

				break ;

			case NUMBER_SEVEN :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_LOW ) ;

				break ;

			case NUMBER_EIGHT :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_LOW ) ;

				break ;

			case NUMBER_NINE :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_LOW ) ;

				break ;

			default : Local_u8ErrorState = STD_TYPES_NOK ; break ;

			}

			/* Enable SSD1 */
			DIO_u8SetPinValue 				( SSD_u8_SSD1_ENABLE_PORT , SSD_u8_SSD1_ENABLE_PIN , DIO_u8_LOW ) ;
			/* Disable SSD2 */
			DIO_u8SetPinValue 				( SSD_u8_SSD2_ENABLE_PORT , SSD_u8_SSD2_ENABLE_PIN , DIO_u8_HIGH ) ;

			/* Delay For 10 ms For POV */
			_delay_ms(10) ;



			/* Disable SSD1 */
			DIO_u8SetPinValue 				( SSD_u8_SSD1_ENABLE_PORT , SSD_u8_SSD1_ENABLE_PIN , DIO_u8_HIGH) ;

			/* Write Number 2 on SSD2 */
			switch (Local_u8Numer2)
			{
			case NUMBER_ZERO :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_LOW ) ;

				break ;

			case NUMBER_ONE :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_LOW ) ;

				break ;

			case NUMBER_TWO :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_LOW) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_LOW ) ;

				break ;

			case NUMBER_THREE :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_LOW ) ;

				break ;

			case NUMBER_FOUR :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN ,  DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_HIGH  ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN ,  DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN ,  DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_LOW   ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_HIGH   ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN ,  DIO_u8_HIGH) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_LOW ) ;

				break ;

			case NUMBER_FIVE :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_LOW ) ;

				break ;

			case NUMBER_SIX :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_LOW ) ;

				break ;

			case NUMBER_SEVEN :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_LOW ) ;

				break ;

			case NUMBER_EIGHT :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_LOW ) ;

				break ;

			case NUMBER_NINE :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_LOW ) ;

				break ;

			default : Local_u8ErrorState = STD_TYPES_NOK ; break ;

			}

			/* Disable SSD1 */
			DIO_u8SetPinValue 				( SSD_u8_SSD1_ENABLE_PORT , SSD_u8_SSD1_ENABLE_PIN , DIO_u8_HIGH) ;
			/* Enable SSD2 */
			DIO_u8SetPinValue 				( SSD_u8_SSD2_ENABLE_PORT , SSD_u8_SSD2_ENABLE_PIN , DIO_u8_LOW ) ;

			/* Delay For 10 ms For POV */
			_delay_ms(10) ;

			/* Disable SSD2 and SSD1 */
			DIO_u8SetPinValue 				( SSD_u8_SSD2_ENABLE_PORT , SSD_u8_SSD2_ENABLE_PIN , DIO_u8_HIGH ) ;
			DIO_u8SetPinValue 				( SSD_u8_SSD1_ENABLE_PORT , SSD_u8_SSD1_ENABLE_PIN , DIO_u8_HIGH ) ;

#else
			Local_u8ErrorState = STD_TYPES_NOK ;

#endif
		}
	}

	else
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}
#elif(SSD_u8_SSD_MODE == SSD_u8_SSD_COMMON_ANODE)
	#if (SSD_u8_SSD_MODE_VISION == SSD_u8_SSD_NORMAL_MODE)
			/* Write Number 1 on SSD1 */
			switch (Local_u8Numer1)
			{
			case NUMBER_ZERO :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_HIGH) ;

				break ;

			case NUMBER_ONE :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_HIGH) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_ HIGH) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_HIGH ) ;

				break ;

			case NUMBER_TWO :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_LOW) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_HIGH) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_LOW) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_HIGH) ;

				break ;

			case NUMBER_THREE :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_HIGH ) ;

				break ;

			case NUMBER_FOUR :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN ,  DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_LOW  ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN ,  DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN ,  DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_HIGH  ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_LOW   ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN ,  DIO_u8_LOW) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_HIGH ) ;

				break ;

			case NUMBER_FIVE :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_HIGH) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_LOW) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_HIGH ) ;

				break ;

			case NUMBER_SIX :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_HIGH ) ;

				break ;

			case NUMBER_SEVEN :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_HGHI ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_HGHI ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_HIGH ) ;

				break ;

			case NUMBER_EIGHT :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_HIGH ) ;

				break ;

			case NUMBER_NINE :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_HIGH ) ;

				break ;

			default : Local_u8ErrorState = STD_TYPES_NOK ; break ;

			}

			/* Write Number 2 on SSD2 */
			switch (Local_u8Numer2)
			{
			case NUMBER_ZERO :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_HIGH) ;

				break ;

			case NUMBER_ONE :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_HIGH) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_ HIGH) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_HIGH ) ;

				break ;

			case NUMBER_TWO :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_LOW) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_HIGH) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_LOW) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_HIGH) ;

				break ;

			case NUMBER_THREE :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_HIGH ) ;

				break ;

			case NUMBER_FOUR :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN ,  DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_LOW  ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN ,  DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN ,  DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_HIGH  ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_LOW   ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN ,  DIO_u8_LOW) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_HIGH ) ;

				break ;

			case NUMBER_FIVE :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_HIGH) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_LOW) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_HIGH ) ;

				break ;

			case NUMBER_SIX :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_HIGH ) ;

				break ;

			case NUMBER_SEVEN :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_HGHI ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_HGHI ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_HIGH ) ;

				break ;

			case NUMBER_EIGHT :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_HIGH ) ;

				break ;

			case NUMBER_NINE :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_HIGH ) ;

				break ;

			default : Local_u8ErrorState = STD_TYPES_NOK ; break ;

			}

			/* Enabled Two SSD */
			DIO_u8SetPinValue 				( SSD_u8_SSD1_ENABLE_PORT , SSD_u8_SSD1_ENABLE_PIN , DIO_u8_LOW ) ;
			DIO_u8SetPinValue 				( SSD_u8_SSD2_ENABLE_PORT , SSD_u8_SSD2_ENABLE_PIN , DIO_u8_LOW ) ;

#elif(SSD_u8_SSD_MODE_VISION == SSD_u8_SSD_POV_MODE)

			/* Write Number 1 on SSD1 */
			switch (Local_u8Numer1)
			{
			case NUMBER_ZERO :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_HIGH) ;

				break ;

			case NUMBER_ONE :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_HIGH) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_ HIGH) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_HIGH ) ;

				break ;

			case NUMBER_TWO :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_LOW) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_HIGH) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_LOW) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_HIGH) ;

				break ;

			case NUMBER_THREE :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_HIGH ) ;

				break ;

			case NUMBER_FOUR :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN ,  DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_LOW  ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN ,  DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN ,  DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_HIGH  ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_LOW   ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN ,  DIO_u8_LOW) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_HIGH ) ;

				break ;

			case NUMBER_FIVE :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_HIGH) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_LOW) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_HIGH ) ;

				break ;

			case NUMBER_SIX :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_HIGH ) ;

				break ;

			case NUMBER_SEVEN :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_HGHI ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_HGHI ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_HIGH ) ;

				break ;

			case NUMBER_EIGHT :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_HIGH ) ;

				break ;

			case NUMBER_NINE :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_HIGH ) ;

				break ;

			default : Local_u8ErrorState = STD_TYPES_NOK ; break ;

			}

			/* Enable SSD1 */
			DIO_u8SetPinValue 				( SSD_u8_SSD1_ENABLE_PORT , SSD_u8_SSD1_ENABLE_PIN , DIO_u8_LOW ) ;
			/* Disable SSD2 */
			DIO_u8SetPinValue 				( SSD_u8_SSD2_ENABLE_PORT , SSD_u8_SSD2_ENABLE_PIN , DIO_u8_HIGH ) ;

			/* Delay For 10 ms For POV */
			_delay_ms(10) ;



			/* Disable SSD1 */
			DIO_u8SetPinValue 				( SSD_u8_SSD1_ENABLE_PORT , SSD_u8_SSD1_ENABLE_PIN , DIO_u8_HIGH) ;

			/* Write Number 2 on SSD2 */
			switch (Local_u8Numer2)
			{
			case NUMBER_ZERO :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_HIGH) ;

				break ;

			case NUMBER_ONE :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_HIGH) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_ HIGH) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_HIGH ) ;

				break ;

			case NUMBER_TWO :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_LOW) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_HIGH) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_LOW) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_HIGH) ;

				break ;

			case NUMBER_THREE :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_HIGH ) ;

				break ;

			case NUMBER_FOUR :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN ,  DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_LOW  ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN ,  DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN ,  DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_HIGH  ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_LOW   ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN ,  DIO_u8_LOW) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_HIGH ) ;

				break ;

			case NUMBER_FIVE :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_HIGH) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_LOW) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_HIGH ) ;

				break ;

			case NUMBER_SIX :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_HIGH ) ;

				break ;

			case NUMBER_SEVEN :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_HGHI ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_HGHI ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_HIGH ) ;

				break ;

			case NUMBER_EIGHT :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_HIGH ) ;

				break ;

			case NUMBER_NINE :
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_A_PORT , SSD_u8_SSD1_LED_A_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_B_PORT , SSD_u8_SSD1_LED_B_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_C_PORT , SSD_u8_SSD1_LED_C_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_D_PORT , SSD_u8_SSD1_LED_D_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_E_PORT , SSD_u8_SSD1_LED_E_PIN  , DIO_u8_HIGH ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_F_PORT , SSD_u8_SSD1_LED_F_PIN  , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_G_PORT , SSD_u8_SSD1_LED_G_PIN , DIO_u8_LOW ) ;
				DIO_u8SetPinValue 				( SSD_u8_SSD1_LED_DOT_PORT , SSD_u8_SSD1_LED_DOT_PIN , DIO_u8_HIGH ) ;

				break ;

			default : Local_u8ErrorState = STD_TYPES_NOK ; break ;

			}

			/* Disable SSD1 */
			DIO_u8SetPinValue 				( SSD_u8_SSD1_ENABLE_PORT , SSD_u8_SSD1_ENABLE_PIN , DIO_u8_HIGH) ;
			/* Enable SSD2 */
			DIO_u8SetPinValue 				( SSD_u8_SSD2_ENABLE_PORT , SSD_u8_SSD2_ENABLE_PIN , DIO_u8_LOW ) ;

			/* Delay For 10 ms For POV */
			_delay_ms(10) ;

			/* Disable SSD2 and SSD1 */
			DIO_u8SetPinValue 				( SSD_u8_SSD2_ENABLE_PORT , SSD_u8_SSD2_ENABLE_PIN , DIO_u8_HIGH ) ;
			DIO_u8SetPinValue 				( SSD_u8_SSD1_ENABLE_PORT , SSD_u8_SSD1_ENABLE_PIN , DIO_u8_HIGH ) ;

#else
			Local_u8ErrorState = STD_TYPES_NOK ;

#endif
		}
	}

	else
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}
#else
	Local_u8ErrorState = STD_TYPES_NOK ;
#endif
	

	return 	Local_u8ErrorState ;

}
