/********************************************************************************************************************/
/*****************     Author 		: Ahmed Abdelhady 	*************************************************************/
/*****************     File 		: Program Of PB  	*************************************************************/
/*****************     Date 		: 1/1/2023  		*************************************************************/
/*****************     Version 		: 1.0  				*************************************************************/
/*****************     Description 	: Drive For PB 	*************************************************************/
/********************************************************************************************************************/

/* LIB Layer */
#include "util/delay.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL Layer */
#include "DIO_interface.h"

/* HAL Layer */
#include "PB_private.h"
#include "PB_config.h"
#include "PB_interface.h"

u8 PB_u8Init (u8 Copy_u8PB_ID)
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;

	switch(Copy_u8PB_ID)
	{
	case PB_u8_DIP1  	:

		DIO_u8SetPinDirection 			( PB_u8_DIP1_PORT , PB_u8_DIP1_PIN, DIO_u8_INPUT ) 	;
		DIO_u8SetPinValue				(PB_u8_DIP1_PORT , PB_u8_DIP1_PIN , DIO_u8_HIGH)	;

		break ;

	case PB_u8_DIP2  	:

		DIO_u8SetPinDirection 			( PB_u8_DIP2_PORT , PB_u8_DIP2_PIN, DIO_u8_INPUT ) 	;
		DIO_u8SetPinValue				(PB_u8_DIP2_PORT , PB_u8_DIP2_PIN , DIO_u8_HIGH)	;

		break ;

	case PB_u8_DIP3  	:

		DIO_u8SetPinDirection 			( PB_u8_DIP3_PORT , PB_u8_DIP3_PIN, DIO_u8_INPUT ) 	;
		DIO_u8SetPinValue				(PB_u8_DIP3_PORT , PB_u8_DIP3_PIN , DIO_u8_HIGH)	;

		break ;

	case PB_u8_DIP4  	:

		DIO_u8SetPinDirection 			( PB_u8_DIP4_PORT , PB_u8_DIP4_PIN, DIO_u8_INPUT ) ;
		DIO_u8SetPinValue				(PB_u8_DIP4_PORT , PB_u8_DIP4_PIN , DIO_u8_HIGH)   ;

		break ;

	case PB_u8_DIP5  	:

		DIO_u8SetPinDirection 			( PB_u8_DIP5_PORT , PB_u8_DIP5_PIN, DIO_u8_INPUT ) ;
		DIO_u8SetPinValue					(PB_u8_DIP5_PORT , PB_u8_DIP5_PIN , DIO_u8_HIGH)   ;

		break ;

	case PB_u8_DIP6  	:

		DIO_u8SetPinDirection 			( PB_u8_DIP6_PORT , PB_u8_DIP6_PIN, DIO_u8_INPUT ) ;
		DIO_u8SetPinValue					(PB_u8_DIP6_PORT , PB_u8_DIP6_PIN , DIO_u8_HIGH)   ;

		break ;

	case PB_u8_DIP7  	:

		DIO_u8SetPinDirection 			( PB_u8_DIP7_PORT , PB_u8_DIP7_PIN, DIO_u8_INPUT ) ;
		DIO_u8SetPinValue					(PB_u8_DIP7_PORT , PB_u8_DIP7_PIN , DIO_u8_HIGH)   ;
		break ;

	case PB_u8_DIP8  	:

		DIO_u8SetPinDirection 			( PB_u8_DIP8_PORT , PB_u8_DIP8_PIN, DIO_u8_INPUT ) ;
		DIO_u8SetPinValue					(PB_u8_DIP8_PORT , PB_u8_DIP8_PIN , DIO_u8_HIGH)   ;

		break ;

	case PB_u8_TAC1 	:

		DIO_u8SetPinDirection 			( PB_u8_TAC1_PORT , PB_u8_TAC1_PIN, DIO_u8_INPUT ) ;
		DIO_u8SetPinValue				(PB_u8_TAC1_PORT , PB_u8_TAC1_PIN , DIO_u8_HIGH)	;

		break ;
	case PB_u8_TAC2 	:

		DIO_u8SetPinDirection 			( PB_u8_TAC2_PORT , PB_u8_TAC2_PIN, DIO_u8_INPUT ) ;
		DIO_u8SetPinValue				(PB_u8_TAC2_PORT , PB_u8_TAC2_PIN , DIO_u8_HIGH)	;

		break ;

	case PB_u8_TAC3 	:

		DIO_u8SetPinDirection 			( PB_u8_TAC3_PORT , PB_u8_TAC3_PIN, DIO_u8_INPUT ) ;
		DIO_u8SetPinValue				(PB_u8_TAC3_PORT , PB_u8_TAC3_PIN , DIO_u8_HIGH)	;

		break ;

	default 				  	:	Local_u8ErrorState = STD_TYPES_NOK ;

	}
	return Local_u8ErrorState ;
}

u8 PB_u8SwitchStatus (u8 Copy_u8PB_ID , u8 * Copy_Pu8ReturnedPBValue)
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;

#if(PB_u8_PB_MODE == PB_u8_ACTIVE_LOW)

	u8 Local_u8ReturnedPinValue = PB_u8_SWITCH_NOT_PRESSED_L ;

	if(Copy_Pu8ReturnedPBValue != NULL)
	{
		* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_NOT_PRESSED_L ;


		switch(Copy_u8PB_ID)
		{
		case PB_u8_DIP1  	:

			DIO_u8GetPinValue 			( PB_u8_DIP1_PORT , PB_u8_DIP1_PIN,  &Local_u8ReturnedPinValue ) 	;

			if(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_L)
			{

				DIO_u8GetPinValue 			( PB_u8_DIP1_PORT , PB_u8_DIP1_PIN,  &Local_u8ReturnedPinValue ) 	;

				if(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_L)
				{
					* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_PRESSED_L ;
				}
				else
				{
					* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_NOT_PRESSED_L ;
				}
			}
			else
			{
				* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_NOT_PRESSED_L ;
			}

			break ;

		case PB_u8_DIP2  	:

			DIO_u8GetPinValue 			( PB_u8_DIP2_PORT , PB_u8_DIP2_PIN,  &Local_u8ReturnedPinValue ) 	;

			if(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_L)
			{

				DIO_u8GetPinValue 			( PB_u8_DIP2_PORT , PB_u8_DIP2_PIN,  &Local_u8ReturnedPinValue ) 	;

				if(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_L)
				{

					* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_PRESSED_L ;
				}
				else
				{
					* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_NOT_PRESSED_L ;
				}
			}
			else
			{
				* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_NOT_PRESSED_L ;
			}

			break ;


		case PB_u8_DIP3  	:

			DIO_u8GetPinValue 			( PB_u8_DIP3_PORT , PB_u8_DIP3_PIN,  &Local_u8ReturnedPinValue ) 	;

			if(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_L)
			{

				DIO_u8GetPinValue 			( PB_u8_DIP3_PORT , PB_u8_DIP3_PIN,  &Local_u8ReturnedPinValue ) 	;

				if(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_L)
				{

					* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_PRESSED_L ;
				}
				else
				{
					* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_NOT_PRESSED_L ;
				}
			}
			else
			{
				* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_NOT_PRESSED_L ;
			}

			break ;


		case PB_u8_DIP4  	:

			DIO_u8GetPinValue 			( PB_u8_DIP4_PORT , PB_u8_DIP4_PIN,  &Local_u8ReturnedPinValue ) 	;

			if(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_L)
			{

				DIO_u8GetPinValue 			( PB_u8_DIP4_PORT , PB_u8_DIP4_PIN,  &Local_u8ReturnedPinValue ) 	;

				if(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_L)
				{

					* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_PRESSED_L ;
				}
				else
				{
					* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_NOT_PRESSED_L ;
				}
			}
			else
			{
				* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_NOT_PRESSED_L ;
			}

			break ;


		case PB_u8_DIP5  	:

			DIO_u8GetPinValue 			( PB_u8_DIP5_PORT , PB_u8_DIP5_PIN,  &Local_u8ReturnedPinValue ) 	;

			if(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_L)
			{

				DIO_u8GetPinValue 			( PB_u8_DIP5_PORT , PB_u8_DIP5_PIN,  &Local_u8ReturnedPinValue ) 	;

				if(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_L)
				{

					* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_PRESSED_L ;
				}
				else
				{
					* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_NOT_PRESSED_L ;
				}
			}
			else
			{
				* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_NOT_PRESSED_L ;
			}

			break ;

		case PB_u8_DIP6  	:

			DIO_u8GetPinValue 			( PB_u8_DIP6_PORT , PB_u8_DIP6_PIN,  &Local_u8ReturnedPinValue ) 	;

			if(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_L)
			{

				DIO_u8GetPinValue 			( PB_u8_DIP6_PORT , PB_u8_DIP6_PIN,  &Local_u8ReturnedPinValue ) 	;

				if(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_L)
				{

					* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_PRESSED_L ;
				}
				else
				{
					* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_NOT_PRESSED_L ;
				}
			}
			else
			{
				* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_NOT_PRESSED_L ;
			}

			break ;

		case PB_u8_DIP7  	:

			DIO_u8GetPinValue 			( PB_u8_DIP7_PORT , PB_u8_DIP7_PIN,  &Local_u8ReturnedPinValue ) 	;

			if(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_L)
			{

				DIO_u8GetPinValue 			( PB_u8_DIP7_PORT , PB_u8_DIP7_PIN,  &Local_u8ReturnedPinValue ) 	;

				if(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_L)
				{

					* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_PRESSED_L ;
				}
				else
				{
					* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_NOT_PRESSED_L ;
				}
			}
			else
			{
				* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_NOT_PRESSED_L ;
			}

			break ;

		case PB_u8_DIP8  	:

			DIO_u8GetPinValue 			( PB_u8_DIP8_PORT , PB_u8_DIP8_PIN,  &Local_u8ReturnedPinValue ) 	;

			if(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_L)
			{

				DIO_u8GetPinValue 			( PB_u8_DIP8_PORT , PB_u8_DIP8_PIN,  &Local_u8ReturnedPinValue ) 	;

				if(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_L)
				{

					* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_PRESSED_L ;
				}
				else
				{
					* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_NOT_PRESSED_L ;
				}
			}
			else
			{
				* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_NOT_PRESSED_L ;
			}

			break ;

		case PB_u8_TAC1 	:

			DIO_u8GetPinValue 			( PB_u8_TAC1_PORT , PB_u8_TAC1_PIN, &Local_u8ReturnedPinValue)  	;

			if(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_L)
			{
				_delay_ms(PB_u8_DELAY_TIME) ;

				DIO_u8GetPinValue 			( PB_u8_TAC1_PORT , PB_u8_TAC1_PIN,  &Local_u8ReturnedPinValue ) 	;

				if(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_L)
				{
					while(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_L)
						DIO_u8GetPinValue 			( PB_u8_TAC1_PORT , PB_u8_TAC1_PIN,  &Local_u8ReturnedPinValue ) 	;

					* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_PRESSED_L ;
				}
				else
				{
					* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_NOT_PRESSED_L ;
				}
			}
			else
			{
				* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_NOT_PRESSED_L ;
			}


			break ;

		case PB_u8_TAC2 	:

			DIO_u8GetPinValue 			( PB_u8_TAC2_PORT , PB_u8_TAC2_PIN,&Local_u8ReturnedPinValue)  	;

			if(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_L)
			{
				_delay_ms(PB_u8_DELAY_TIME) ;

				DIO_u8GetPinValue 			( PB_u8_TAC2_PORT , PB_u8_TAC2_PIN,  &Local_u8ReturnedPinValue ) 	;

				if(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_L)
				{
					while(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_L)
						DIO_u8GetPinValue 			( PB_u8_TAC2_PORT , PB_u8_TAC2_PIN,  &Local_u8ReturnedPinValue ) 	;

					* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_PRESSED_L ;
				}
				else
				{
					* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_NOT_PRESSED_L ;
				}
			}
			else
			{
				* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_NOT_PRESSED_L ;
			}


			break ;

		case PB_u8_TAC3 	:

			DIO_u8GetPinValue 			( PB_u8_TAC3_PORT , PB_u8_TAC3_PIN,&Local_u8ReturnedPinValue)  	;

			if(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_L)
			{
				_delay_ms(PB_u8_DELAY_TIME) ;

				DIO_u8GetPinValue 			( PB_u8_TAC3_PORT , PB_u8_TAC3_PIN,  &Local_u8ReturnedPinValue ) 	;

				if(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_L)
				{
					while(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_L)
						DIO_u8GetPinValue 			( PB_u8_TAC3_PORT , PB_u8_TAC3_PIN,  &Local_u8ReturnedPinValue ) 	;

					* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_PRESSED_L ;
				}
				else
				{
					* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_NOT_PRESSED_L ;
				}
			}
			else
			{
				* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_NOT_PRESSED_L ;
			}


			break ;

		default 				  	:	Local_u8ErrorState = STD_TYPES_NOK ;	break ;
		}

	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}
#elif(PB_u8_PB_MODE == PB_u8_ACTIVE_HIGH)
	u8 Local_u8ReturnedPinValue = PB_u8_SWITCH_NOT_PRESSED_H ;

	if(Copy_Pu8ReturnedPBValue != NULL)
	{
		switch(Copy_u8PB_ID)
		{
		case PB_u8_DIP1  	:

			DIO_u8GetPinValue 			( PB_u8_DIP1_PORT , PB_u8_DIP1_PIN,  &Local_u8ReturnedPinValue ) 	;

			if(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_H)
			{
				_delay_ms(PB_u8_DELAY_TIME) ;

				DIO_u8GetPinValue 			( PB_u8_DIP1_PORT , PB_u8_DIP1_PIN,  &Local_u8ReturnedPinValue ) 	;

				if(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_H)
				{

					* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_PRESSED_H ;
				}
				else
				{
					* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_NOT_PRESSED_H ;
				}
			}
			else
			{
				* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_NOT_PRESSED_H ;
			}

			break ;

		case PB_u8_DIP2  	:

			DIO_u8GetPinValue 			( PB_u8_DIP2_PORT , PB_u8_DIP2_PIN,  &Local_u8ReturnedPinValue ) 	;

			if(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_H)
			{
				_delay_ms(PB_u8_DELAY_TIME) ;

				DIO_u8GetPinValue 			( PB_u8_DIP2_PORT , PB_u8_DIP2_PIN,  &Local_u8ReturnedPinValue ) 	;

				if(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_H)
				{

					* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_PRESSED_H ;
				}
				else
				{
					* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_NOT_PRESSED_H ;
				}
			}
			else
			{
				* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_NOT_PRESSED_H ;
			}

			break ;


		case PB_u8_DIP3  	:

			DIO_u8GetPinValue 			( PB_u8_DIP3_PORT , PB_u8_DIP3_PIN,  &Local_u8ReturnedPinValue ) 	;

			if(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_H)
			{
				_delay_ms(PB_u8_DELAY_TIME) ;

				DIO_u8GetPinValue 			( PB_u8_DIP3_PORT , PB_u8_DIP3_PIN,  &Local_u8ReturnedPinValue ) 	;

				if(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_H)
				{

					* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_PRESSED_H ;
				}
				else
				{
					* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_NOT_PRESSED_H ;
				}
			}
			else
			{
				* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_NOT_PRESSED_H ;
			}

			break ;


		case PB_u8_DIP4  	:

			DIO_u8GetPinValue 			( PB_u8_DIP4_PORT , PB_u8_DIP4_PIN,  &Local_u8ReturnedPinValue ) 	;

			if(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_H)
			{
				_delay_ms(PB_u8_DELAY_TIME) ;

				DIO_u8GetPinValue 			( PB_u8_DIP4_PORT , PB_u8_DIP4_PIN,  &Local_u8ReturnedPinValue ) 	;

				if(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_H)
				{

					* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_PRESSED_H ;
				}
				else
				{
					* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_NOT_PRESSED_H ;
				}
			}
			else
			{
				* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_NOT_PRESSED_H ;
			}

			break ;


		case PB_u8_DIP5  	:

			DIO_u8GetPinValue 			( PB_u8_DIP5_PORT , PB_u8_DIP5_PIN,  &Local_u8ReturnedPinValue ) 	;

			if(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_H)
			{
				_delay_ms(PB_u8_DELAY_TIME) ;

				DIO_u8GetPinValue 			( PB_u8_DIP5_PORT , PB_u8_DIP5_PIN,  &Local_u8ReturnedPinValue ) 	;

				if(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_H)
				{

					* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_PRESSED_H ;
				}
				else
				{
					* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_NOT_PRESSED_H ;
				}
			}
			else
			{
				* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_NOT_PRESSED_H ;
			}

			break ;

		case PB_u8_DIP6  	:

			DIO_u8GetPinValue 			( PB_u8_DIP6_PORT , PB_u8_DIP6_PIN,  &Local_u8ReturnedPinValue ) 	;

			if(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_H)
			{
				_delay_ms(PB_u8_DELAY_TIME) ;

				DIO_u8GetPinValue 			( PB_u8_DIP6_PORT , PB_u8_DIP6_PIN,  &Local_u8ReturnedPinValue ) 	;

				if(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_H)
				{

					* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_PRESSED_H ;
				}
				else
				{
					* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_NOT_PRESSED_H ;
				}
			}
			else
			{
				* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_NOT_PRESSED_H ;
			}

			break ;

		case PB_u8_DIP7  	:

			DIO_u8GetPinValue 			( PB_u8_DIP7_PORT , PB_u8_DIP7_PIN,  &Local_u8ReturnedPinValue ) 	;

			if(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_H)
			{
				_delay_ms(PB_u8_DELAY_TIME) ;

				DIO_u8GetPinValue 			( PB_u8_DIP7_PORT , PB_u8_DIP7_PIN,  &Local_u8ReturnedPinValue ) 	;

				if(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_H)
				{

					* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_PRESSED_H ;
				}
				else
				{
					* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_NOT_PRESSED_H ;
				}
			}
			else
			{
				* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_NOT_PRESSED_H ;
			}

			break ;

		case PB_u8_DIP8  	:

			DIO_u8GetPinValue 			( PB_u8_DIP8_PORT , PB_u8_DIP8_PIN,  &Local_u8ReturnedPinValue ) 	;

			if(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_H)
			{
				_delay_ms(PB_u8_DELAY_TIME) ;

				DIO_u8GetPinValue 			( PB_u8_DIP8_PORT , PB_u8_DIP8_PIN,  &Local_u8ReturnedPinValue ) 	;

				if(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_H)
				{

					* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_PRESSED_H ;
				}
				else
				{
					* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_NOT_PRESSED_H ;
				}
			}
			else
			{
				* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_NOT_PRESSED_H ;
			}

			break ;

		case PB_u8_TAC1 	:

			DIO_u8GetPinValue 			( PB_u8_TAC1_PORT , PB_u8_TAC1_PIN,&Local_u8ReturnedPinValue)  	;

			if(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_H)
			{
				_delay_ms(PB_u8_DELAY_TIME) ;

				DIO_u8GetPinValue 			( PB_u8_TAC1_PORT , PB_u8_TAC1_PIN,  &Local_u8ReturnedPinValue ) 	;

				if(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_H)
				{
					while(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_H)
						DIO_u8GetPinValue 			( PB_u8_TAC1_PORT , PB_u8_TAC1_PIN,  &Local_u8ReturnedPinValue ) 	;

					* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_PRESSED_H ;
				}
				else
				{
					* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_NOT_PRESSED_H ;
				}
			}
			else
			{
				* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_NOT_PRESSED_H ;
			}


			break ;

		case PB_u8_TAC2 	:

			DIO_u8GetPinValue 			( PB_u8_TAC2_PORT , PB_u8_TAC2_PIN,&Local_u8ReturnedPinValue)  	;

			if(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_H)
			{
				_delay_ms(PB_u8_DELAY_TIME) ;

				DIO_u8GetPinValue 			( PB_u8_TAC2_PORT , PB_u8_TAC2_PIN,  &Local_u8ReturnedPinValue ) 	;

				if(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_H)
				{
					while(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_H)
						DIO_u8GetPinValue 			( PB_u8_TAC2_PORT , PB_u8_TAC2_PIN,  &Local_u8ReturnedPinValue ) 	;

					* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_PRESSED_H ;
				}
				else
				{
					* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_NOT_PRESSED_H ;
				}
			}
			else
			{
				* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_NOT_PRESSED_H ;
			}


			break ;

		case PB_u8_TAC3 	:

			DIO_u8GetPinValue 			( PB_u8_TAC3_PORT , PB_u8_TAC3_PIN,&Local_u8ReturnedPinValue)  	;

			if(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_H)
			{
				_delay_ms(PB_u8_DELAY_TIME) ;

				DIO_u8GetPinValue 			( PB_u8_TAC3_PORT , PB_u8_TAC3_PIN,  &Local_u8ReturnedPinValue ) 	;

				if(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_H)
				{
					while(Local_u8ReturnedPinValue == PB_u8_SWITCH_PRESSED_H)
						DIO_u8GetPinValue 			( PB_u8_TAC3_PORT , PB_u8_TAC3_PIN,  &Local_u8ReturnedPinValue ) 	;

					* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_PRESSED_H ;
				}
				else
				{
					* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_NOT_PRESSED_H ;
				}
			}
			else
			{
				* Copy_Pu8ReturnedPBValue = PB_u8_SWITCH_NOT_PRESSED_H ;
			}


			break ;

		default 				  	:	Local_u8ErrorState = STD_TYPES_NOK ;	break ;
		}

	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}
#else
	Local_u8ErrorState = STD_TYPES_NOK ;
#endif

	return Local_u8ErrorState ;
}
