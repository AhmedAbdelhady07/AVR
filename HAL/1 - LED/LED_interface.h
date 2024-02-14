/********************************************************************************************************************/
/*****************     Author 		: Ahmed Abdelhady 	*************************************************************/
/*****************     File 		: Interface Of LED  *************************************************************/
/*****************     Date 		: 1/1/2023  		*************************************************************/
/*****************     Version 		: 1.0  				*************************************************************/
/*****************     Description 	: Drive For LED 	*************************************************************/
/********************************************************************************************************************/

#ifndef 	LED_INTERFACE_H
#define 	LED_INTERFACE_H

/* Macros For Leds */
#define LED_u8_LED1			1
#define LED_u8_LED2			2
#define LED_u8_LED3			3
#define LED_u8_LED4			4
#define LED_u8_LED5			5
#define LED_u8_LED6			6
#define LED_u8_LED7			7
#define LED_u8_LED8			8

u8 LED_voidInit			(u8 Copy_u8LedNumber) ;
u8 LED_u8TurnLed_ON 		(u8 Copy_u8LedNumber) ;
u8 LED_u8TurnLed_OFF 	(u8 Copy_u8LedNumber) ;
u8 LED_u8GetLedStatus	(u8 Copy_u8LedNumber , u8 * Copy_Pu8ReturnedLedStatus)  ;
u8 LED_u8ToggleLed			(u8 Copy_u8LedNumber) ;

#endif
