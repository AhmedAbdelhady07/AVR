/********************************************************************************************************************/
/*****************     Author 		: Ahmed Abdelhady 	*************************************************************/
/*****************     File 		: Interface Of LM35  *************************************************************/
/*****************     Date 		: 1/1/2023  		*************************************************************/
/*****************     Version 		: 1.0  				*************************************************************/
/*****************     Description 	: Drive For LM35 	*************************************************************/
/********************************************************************************************************************/

#ifndef 	LM35_INTERFACE_H
#define 	LM35_INTERFACE_H

void LM35_voidInit (u8 Copy_u8ChannelNumber) ;

u16	LM35_u16ReadTempDegree (u16 Copy_u16AnalogValue)	;

#endif