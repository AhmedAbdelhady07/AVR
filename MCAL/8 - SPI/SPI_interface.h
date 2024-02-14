/********************************************************************************************************************/
/*****************     Author 		: Ahmed Abdelhady 	*************************************************************/
/*****************     File 		: Interface Of SPI  *************************************************************/
/*****************     Date 		: 27/9/2023  		*************************************************************/
/*****************     Version 		: 1.0  				*************************************************************/
/*****************     Description 	: Drive For SPI 	*************************************************************/
/********************************************************************************************************************/

#ifndef 	SPI_INTERFACE_H
#define 	SPI_INTERFACE_H

void SPI_voidInit (void) ;

u8 SPI_u8TransmitReceiveByteSynchBlocking (u8 Copy_u8TransmittedByte , u8 * Copy_pu8ReceivedByte) ;

u8 SPI_u8TransmitReceiveByteSynchNonBlocking (u8 Copy_u8TransmittedByte , u8 * Copy_pu8ReceivedByte) ;

u8 SPI_u8TransmitReceiveStringSynchBlocking (u8 * Copy_pu8TransmittedString , u8 * Copy_pu8ReceivedString , u8 Copy_u8MessageSize) ;

u8 SPI_u8TransmitReceiveStringSynchNonBlocking (u8 * Copy_pu8TransmittedString , u8 * Copy_pu8ReceivedString , u8 Copy_u8MessageSize) ;

u8 SPI_u8TransmitReceiveStringAsynch (u8 * Copy_pu8TransmittedString , u8 * Copy_pu8ReceivedString , void (*Copy_pf)(void) , u8 Copy_u8MessageSize) ;

void SPI_voidSendByteSynchBlocking(u8 Copy_u8DataByte) ;

u8 SPI_u8SendByteSynchNonBlocking(u8 Copy_u8DataByte) ;

u8 SPI_u8SendStringSynchBlocking (u8 * Copy_pu8TransmittedString , u8 Copy_u8MessageSize) ;

u8 SPI_u8SendStringSynchNonBlocking (u8 * Copy_pu8TransmittedString , u8 Copy_u8MessageSize) ;

u8 SPI_u8ReceiveByte(void) ;

u8 SPI_u8ReceiveStringSynchBlocking (u8 * Copy_pu8ReceivedString) ;

u8 SPI_u8ReceiveStringSynchNonBlocking (u8 * Copy_pu8ReceivedString) ;

#endif
