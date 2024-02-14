/********************************************************************************************************************/
/*****************     Author 		: Ahmed Abdelhady 	*************************************************************/
/*****************     File 		: Interface Of EEPROM  *************************************************************/
/*****************     Date 		: 1/1/2023  		*************************************************************/
/*****************     Version 		: 1.0  				*************************************************************/
/*****************     Description 	: Drive For EEPROM 	*************************************************************/
/********************************************************************************************************************/

#ifndef 	EEPROM_INTERFACE_H
#define 	EEPROM_INTERFACE_H

u8 EEPROM_u8Init (void) ;

u8 EEPROM_u8WriteDataByte (u16 Copy_u16ByteAdress , u8 Copy_u8Data) ;

u8 EEPROM_u8ReadDataByte (u16 Copy_u16ByteAdress , u8 *  Copy_Pu8ReturnedData)	;

u8 EEPROM_u8WriteString (u16 Copy_u16ByteAdress , u8 *  Copy_Pu8Data) ;

u8 EEPROM_u8ReadString (u16 Copy_u16ByteAdress , u8 *  Copy_Pu8ReturnedData , u8 Copy_u8Size) ;

void EEPROM_voidEraseEEPROM (void)	;

#endif
