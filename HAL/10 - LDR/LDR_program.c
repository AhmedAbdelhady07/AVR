/********************************************************************************************************************/
/*****************     Author 		: Ahmed Abdelhady 	*************************************************************/
/*****************     File 		: Program Of LDR  	*************************************************************/
/*****************     Date 		: 1/1/2023  		*************************************************************/
/*****************     Version 		: 1.0  				*************************************************************/
/*****************     Description 	: Drive For LDR 	*************************************************************/
/********************************************************************************************************************/

/* LIB Layer */
#include "util/delay.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL Layer */
#include "DIO_interface.h"
#include "ADC_interface.h"

/* HAL Layer */
#include "LDR_private.h"
#include "LDR_config.h"
#include "LDR_interface.h"

void LDR_voidInit (u8 Copy_u8ChannelNumber)
{
	DIO_u8SetPinDirection (DIO_u8_PORTA , Copy_u8ChannelNumber , DIO_u8_INPUT ) ;
	ADC_u8Init ()	;
}

u16	LDR_u8ReadLightIntensity (u16 Copy_u8DigitalValue)
{
	u16 Local_u8LightIntensity ;
	
	Local_u8LightIntensity = (u16)((Copy_u8DigitalValue *  LDR_u16_VREF ) / LDR_u16_RESOULTION_MODE)  ;
	
	return Local_u8LightIntensity ;
}
