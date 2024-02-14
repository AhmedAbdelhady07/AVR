/********************************************************************************************************************/
/*****************     Author 		: Ahmed Abdelhady 	*************************************************************/
/*****************     File 		: Config Of LED  	*************************************************************/
/*****************     Date 		: 1/1/2023  		*************************************************************/
/*****************     Version 		: 1.0  				*************************************************************/
/*****************     Description 	: Drive For LED 	*************************************************************/
/********************************************************************************************************************/

#ifndef 	LED_CONFIG_H
#define 	LED_CONFIG_H

/*
 * Please choose:
 * 		LED_PORT		: DIO_u8_PORTA 		......	 DIO_u8_PORTD
 * 		LED_PIN 		: PIN0			......	 PIN7
 * 		LED_DIRECTION 	: LED_u8_LED_FORWARD	......	 LED_u8_LED_REVERSE
 */

/* Led Mode */
#define LED_u8_LED_MODE	LED_u8_LED_FORWARD

/* Led 1--RED */
#define LED_u8_LED1_PORT				DIO_u8_PORTB
#define LED_u8_LED1_PIN					DIO_u8_PIN0

/* Led 2--YELLOW */
#define LED_u8_LED2_PORT				DIO_u8_PORTB
#define LED_u8_LED2_PIN         		DIO_u8_PIN1 

/* Led 3--GREEN */
#define LED_u8_LED3_PORT				DIO_u8_PORTB
#define LED_u8_LED3_PIN              	DIO_u8_PIN2 

/* Led 4--YELLOW */
#define LED_u8_LED4_PORT				DIO_u8_PORTA
#define LED_u8_LED4_PIN              	DIO_u8_PIN3 

/* Led 5--RED */
#define LED_u8_LED5_PORT				DIO_u8_PORTA
#define LED_u8_LED5_PIN              	DIO_u8_PIN4 

/* Led 6--GREEN */
#define LED_u8_LED6_PORT				DIO_u8_PORTA
#define LED_u8_LED6_PIN              	DIO_u8_PIN5 

/* Led 7--YELLOW */
#define LED_u8_LED7_PORT				DIO_u8_PORTA
#define LED_u8_LED7_PIN             	DIO_u8_PIN6 

/* Led 8--RED */
#define LED_u8_LED8_PORT				DIO_u8_PORTA
#define LED_u8_LED8_PIN             	DIO_u8_PIN7 


#endif
