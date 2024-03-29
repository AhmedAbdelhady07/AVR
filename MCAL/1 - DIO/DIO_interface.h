/********************************************************************************************************************/
/*****************     Author 		: Ahmed Abdelhady 	*************************************************************/
/*****************     File 		: Interface Of DIO  *************************************************************/
/*****************     Date 		: 1/1/2023  		*************************************************************/
/*****************     Version 		: 1.0  				*************************************************************/
/*****************     Description 	: Drive For DIO 	*************************************************************/
/********************************************************************************************************************/

#ifndef  	DIO_INTERFACE_H
#define 	DIO_INTERFACE_H


/* Macros For PORTS */
#define DIO_u8_PORTA 	0
#define DIO_u8_PORTB 	1
#define DIO_u8_PORTC 	2
#define DIO_u8_PORTD 	3

/* Macros For Pins */
#define DIO_u8_PIN0 		0
#define DIO_u8_PIN1 		1
#define DIO_u8_PIN2 		2
#define DIO_u8_PIN3 		3
#define DIO_u8_PIN4 		4
#define DIO_u8_PIN5 		5
#define DIO_u8_PIN6 		6
#define DIO_u8_PIN7 		7

/* Macros For Pin Direction */
#define DIO_u8_OUTPUT   	1
#define DIO_u8_INPUT   		0

/* Macros For pin Value */
#define DIO_u8_HIGH   	1
#define DIO_u8_LOW   	0

void DIO_voidInit						(void) ;

u8 DIO_u8SetPinDirection 			( u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8PinDirection ) ;

u8 DIO_u8SetPinValue 				( u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8PinValue ) ;

u8 DIO_u8GetPinValue 				( u8 Copy_u8PortID , u8 Copy_u8PinID , u8 * Copy_Pu8ReturnedPinValue ) ;

u8 DIO_u8SetAllPortDirection 		( u8 Copy_u8PortID , u8 Copy_u8PortDirection ) ;

u8  DIO_u8SetPortDirection			(u8 Copy_u8PortID , u8 Copy_u8PortDirection) ;

u8 DIO_u8SetAllPortValue 			( u8 Copy_u8PortID , u8 Copy_u8PinValue ) ;

u8 DIO_u8SetPortValue 				( u8 Copy_u8PortID , u8 Copy_u8PinValue ) ;

u8 DIO_u8GetPortValue 				( u8 Copy_u8PortID , u8 * Copy_Pu8ReturnedPortValue ) ;

u8  DIO_u8TogglePinValue			(u8 Copy_u8PortID , u8 Copy_u8PinID ) ;

#endif
