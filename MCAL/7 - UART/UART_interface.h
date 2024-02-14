/********************************************************************************************************************/
/*****************     Author 		: Ahmed Abdelhady 	*************************************************************/
/*****************     File 		: Interface Of UART  *************************************************************/
/*****************     Date 		: 27/9/2023  		*************************************************************/
/*****************     Version 		: 1.0  				*************************************************************/
/*****************     Description 	: Drive For UART 	*************************************************************/
/********************************************************************************************************************/

#ifndef 	UART_INTERFACE_H
#define 	UART_INTERFACE_H

#define UART_RX_COM_INTER			0
#define UART_DATA_REG_EMPTY_INTER	1
#define UART_TX_COM_INTER			2

void UART_voidInit (void) ;

void UART_voidSendByteSynchBlocking (u8 Copy_u8DataByte) ;

u8 UART_u8SendByteSynchNonBlocking (u8 Copy_u8DataByte) ;

u8 UART_u8SendByteAsynch (void (* Copy_pf) (void)) ;

u8 UART_u8SendStringSynchBlocking(u8 * Copy_pu8String) ;

u8 UART_u8SendStringSynchNonBlocking(u8 * Copy_pu8String) ;

u8 UART_u8SendStringAsynch(u8 * Copy_pu8String , void (* Copy_pf) (void)) ;

u8 UART_u8ReceiveByteSynchBlocking (u8 * Copy_pu8ReceivedByte) ;

u8 UART_u8ReceiveByteSynchNonBlocking (u8 * Copy_pu8ReceivedByte) ;

u8 UART_u8ReceiveByteAsynch (void (* Copy_pf) (void)) ;

u8 UART_u8ReceiveStringSynchNonBlocking(u8 * Copy_pu8RecString , u8 Copy_u8MessageSize) ;

u8 UART_u8ReceiveStringAsynch(u8 * Copy_pu8RecString , void (* Copy_pf) (void) , u8 Copy_u8MessageSize) ;

void UART_voidDisable (void) ;

u8 UART_u8SetCallBack (u8 Copy_u8InterType , void (* Copy_pf) (void)) ;

void UART_voidDisableInter(u8 Copy_u8InterType) ;

u8 UART_u8GetUDR_Reg (void) ;

void UART_voidWriteOnUDR_Reg (u8 Copy_u8Data) ;

#endif
