/********************************************************************************************************************/
/*****************     Author 		: Ahmed Abdelhady 	*************************************************************/
/*****************     File 		: Interface Of TWI  *************************************************************/
/*****************     Date 		: 1/1/2023  		*************************************************************/
/*****************     Version 		: 1.0  				*************************************************************/
/*****************     Description 	: Drive For TWI 	*************************************************************/
/********************************************************************************************************************/

#ifndef 	TWI_INTERFACE_H
#define 	TWI_INTERFACE_H

#define NO_ADDRESS  0

typedef enum 
{
	TWI_OK = 1 ,
	TWI_Prescaler_Error ,
	TWI_SLA_Error ,
	TWI_SC_Error ,
	TWI_RSC_Error ,
	TWI_SLA_W_Error ,
	TWI_SLA_R_Error ,
	TWI_MT_ACK_Data_Error ,
	TWI_MT_NACK_Data_Error ,
	TWI_MR_ACK_Data_Error ,
	TWI_MR_NACK_Data_Error ,
	TWI_NULL_Pointer_Error ,
	
}TWI_ErrorState ;

TWI_ErrorState TWI_enuMasterInit (u8 Copy_u8SlaveAdress) ;

TWI_ErrorState TWI_enuSlaveInit (u8 Copy_u8SlaveAdress)	;

TWI_ErrorState TWI_enuSendStartCondition (void)	;

TWI_ErrorState TWI_enuSendRepeatedCondition (void)	;

void TWI_voidSendStopCondition (void) ;

TWI_ErrorState TWI_enuSendSlaveAddWithWrite (u8 Copy_u8SlaveAdress )	;

TWI_ErrorState TWI_enuSendSlaveAddWithRead (u8 Copy_u8SlaveAdress )	;

TWI_ErrorState TWI_MasterSendDataWithACK (u8 Copy_u8DataByte )	;

TWI_ErrorState TWI_MasterSendDataWithNACK (u8 Copy_u8DataByte )	;

TWI_ErrorState TWI_enuMasterReceiveDataWithACK (u8 * Copy_Pu8ReturnedDataByte )	;

TWI_ErrorState TWI_enuMasterReceiveDataWithNACK(u8 * Copy_Pu8ReturnedDataByte);

void TWI_voidStop (void) ;

#endif
