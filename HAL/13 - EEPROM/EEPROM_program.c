/********************************************************************************************************************/
/*****************     Author 		: Ahmed Abdelhady 	*************************************************************/
/*****************     File 		: Program Of EEPROM  	*************************************************************/
/*****************     Date 		: 1/1/2023  		*************************************************************/
/*****************     Version 		: 1.0  				*************************************************************/
/*****************     Description 	: Drive For EEPROM 	*************************************************************/
/********************************************************************************************************************/

/* LIB Layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 8000000UL
#include "util/delay.h"

/* MCAL Layer */
#include "DIO_interface.h"
#include "TWI_interface.h"


/* HAL Layer */
#include "EEPROM_private.h"
#include "EEPROM_config.h"
#include "EEPROM_interface.h"

#include "LCD_Interface.h"


u8 EEPROM_u8Init (void)
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;
	TWI_ErrorState Local_enuTWIErrorState = TWI_OK ;

	DIO_u8SetPinDirection(DIO_u8_PORTC , DIO_u8_PIN0 , DIO_u8_OUTPUT) ;
	DIO_u8SetPinDirection(DIO_u8_PORTC , DIO_u8_PIN1 , DIO_u8_OUTPUT) ;

	Local_enuTWIErrorState = TWI_enuMasterInit(NO_ADDRESS) ;
	Local_u8ErrorState = private_u8CheckErrorState (Local_enuTWIErrorState) ;
	return Local_u8ErrorState ;
}

u8 EEPROM_u8WriteDataByte (u16 Copy_u16ByteAdress , u8 Copy_u8Data)
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;
	TWI_ErrorState Local_enuTWIErrorState = TWI_OK ;

	/* Send Start Condation */
	Local_enuTWIErrorState = TWI_enuSendStartCondition();
	Local_u8ErrorState = private_u8CheckErrorState (Local_enuTWIErrorState) ;

	/* Send SLA + W */
	Local_enuTWIErrorState = TWI_enuSendSlaveAddWithWrite(EEPROM_u8_FIXED_ADDRESS | (EEPROM_u8_A2_ADRESS << 2) | Copy_u16ByteAdress >> 8);
	Local_u8ErrorState = private_u8CheckErrorState (Local_enuTWIErrorState) ;

	/* Send Byte Adress */
	Local_enuTWIErrorState = TWI_MasterSendDataWithACK((u8)Copy_u16ByteAdress) ;
	Local_u8ErrorState = private_u8CheckErrorState (Local_enuTWIErrorState) ;

	/* Send Data */
	Local_enuTWIErrorState = TWI_MasterSendDataWithACK(Copy_u8Data) ;
	Local_u8ErrorState = private_u8CheckErrorState (Local_enuTWIErrorState) ;

	/* Stop Condation */
	TWI_voidSendStopCondition() ;

	/* Delay */
	_delay_ms(5) ;

	return Local_u8ErrorState ;

}

u8 EEPROM_u8ReadDataByte (u16 Copy_u16ByteAdress , u8 * Copy_Pu8ReturnedData)
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;
	TWI_ErrorState Local_enuTWIErrorState = TWI_OK ;

	/* Check The Pointer */
	if((Copy_Pu8ReturnedData != NULL) && (Copy_u16ByteAdress < 1024))
	{
		/* Send Start Condation */
		Local_enuTWIErrorState = TWI_enuSendStartCondition();
		Local_u8ErrorState = private_u8CheckErrorState (Local_enuTWIErrorState) ;

		/* Send SLA + W */
		Local_enuTWIErrorState = TWI_enuSendSlaveAddWithWrite((EEPROM_u8_FIXED_ADDRESS) | (EEPROM_u8_A2_ADRESS << 2) | (Copy_u16ByteAdress >> 8));
		Local_u8ErrorState = private_u8CheckErrorState (Local_enuTWIErrorState) ;

		/* Send Byte Adress */
		Local_enuTWIErrorState = TWI_MasterSendDataWithACK((u8)Copy_u16ByteAdress) ;
		Local_u8ErrorState = private_u8CheckErrorState (Local_enuTWIErrorState) ;

		/* Send Repeated Start Condation */
		Local_enuTWIErrorState = TWI_enuSendRepeatedCondition();
		Local_u8ErrorState = private_u8CheckErrorState (Local_enuTWIErrorState) ;

		/* Send SLA + R */
		Local_enuTWIErrorState = TWI_enuSendSlaveAddWithRead((EEPROM_u8_FIXED_ADDRESS) | (EEPROM_u8_A2_ADRESS << 2) | (Copy_u16ByteAdress >> 8));
		Local_u8ErrorState = private_u8CheckErrorState (Local_enuTWIErrorState) ;

		/* Read Data */
		Local_enuTWIErrorState = TWI_enuMasterReceiveDataWithNACK(Copy_Pu8ReturnedData) ;
		Local_u8ErrorState = private_u8CheckErrorState (Local_enuTWIErrorState) ;

		/* Stop Condation */
		TWI_voidSendStopCondition() ;

		/* Delay */
		_delay_ms(5) ;

	}
	else
	{
		Local_u8ErrorState = TWI_NULL_Pointer_Error ;
	}

	return Local_u8ErrorState ;
}

u8 EEPROM_u8WriteString (u16 Copy_u16ByteAdress , u8 *  Copy_Pu8Data)
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;

	u8 Local_u8Counter = 0 ;

	while (Copy_Pu8Data[Local_u8Counter] != '\0')
	{
		EEPROM_u8WriteDataByte(Copy_u16ByteAdress , Copy_Pu8Data[Local_u8Counter]) ;

		Copy_u16ByteAdress ++ ;
		Local_u8Counter ++ ;
	}

	return Local_u8ErrorState ;
}

u8 EEPROM_u8ReadString (u16 Copy_u16ByteAdress , u8 *  Copy_Pu8ReturnedData , u8 Copy_u8Size)
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;

	u8 Local_u8Counter = 0 ;

	while (Local_u8Counter < Copy_u8Size)
	{
		EEPROM_u8ReadDataByte (Copy_u16ByteAdress , &Copy_Pu8ReturnedData[Local_u8Counter]) ;

		Copy_u16ByteAdress ++ ;
		Local_u8Counter ++ ;
	}

	Copy_Pu8ReturnedData[Local_u8Counter] = '\0' ;

	return Local_u8ErrorState ;
}

static u8 private_u8CheckErrorState (TWI_ErrorState Copy_enuErrorState)
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;

	if (Copy_enuErrorState != TWI_OK)
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}

	return Local_u8ErrorState ;
}

void EEPROM_voidEraseEEPROM (void)
{
	u16 Local_u16PosNumber = 0 ;

	for(Local_u16PosNumber = 0 ; Local_u16PosNumber < 1024 ; Local_u16PosNumber ++)
	{
		EEPROM_u8WriteDataByte (Local_u16PosNumber , 0xFF)	;
	}
}
