/********************************************************************************************************************/
/*****************     Author 		: Ahmed Abdelhady 	*************************************************************/
/*****************     File 		: Program Of LM35  	*************************************************************/
/*****************     Date 		: 1/1/2023  		*************************************************************/
/*****************     Version 		: 1.0  				*************************************************************/
/*****************     Description 	: Drive For LM35 	*************************************************************/
/********************************************************************************************************************/

/* LIB Layer */
#include <util/delay.h>
#include <math.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL Layer */
#include "DIO_interface.h"
#include "ADC_interface.h"

/* HAL Layer */
#include "LM35_private.h"
#include "LM35_config.h"
#include "LM35_interface.h"

void LM35_voidInit (u8 Copy_u8ChannelNumber)
{
	DIO_u8SetPinDirection (DIO_u8_PORTA , Copy_u8ChannelNumber , DIO_u8_INPUT ) ;
	ADC_u8Init ()	;
}

u16	LM35_u16ReadTempDegree (u16 Copy_u16DigitalValue)
{
	u16 Local_u16TempDegree ;
	
	Local_u16TempDegree = (u16)(((Copy_u16DigitalValue * LM35_u16_VREF ) / LM35_u16_RESOULTION_MODE) / 10.0) ;
	
	return Local_u16TempDegree ;
}
