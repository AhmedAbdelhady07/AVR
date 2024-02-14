/********************************************************************************************************************/
/*****************     Author 		: Ahmed Abdelhady 	*************************************************************/
/*****************     File 		: Config Of PB  	*************************************************************/
/*****************     Date 		: 1/1/2023  		*************************************************************/
/*****************     Version 		: 1.0  				*************************************************************/
/*****************     Description 	: Drive For PB 	*************************************************************/
/********************************************************************************************************************/

#ifndef 	PB_CONFIG_H
#define 	PB_CONFIG_H

/* DIP Switches */
#define PB_u8_DIP1_PORT 	DIO_u8_PORTD
#define PB_u8_DIP1_PIN		DIO_u8_PIN0

#define PB_u8_DIP2_PORT		DIO_u8_PORTD
#define PB_u8_DIP2_PIN		DIO_u8_PIN1

#define PB_u8_DIP3_PORT		DIO_u8_PORTD
#define PB_u8_DIP3_PIN		DIO_u8_PIN2

#define PB_u8_DIP4_PORT		DIO_u8_PORTD
#define PB_u8_DIP4_PIN		DIO_u8_PIN3

#define PB_u8_DIP5_PORT		DIO_u8_PORTD
#define PB_u8_DIP5_PIN		DIO_u8_PIN4

#define PB_u8_DIP6_PORT		DIO_u8_PORTD
#define PB_u8_DIP6_PIN		DIO_u8_PIN5

#define PB_u8_DIP7_PORT		DIO_u8_PORTD
#define PB_u8_DIP7_PIN		DIO_u8_PIN6

#define PB_u8_DIP8_PORT		DIO_u8_PORTD
#define PB_u8_DIP8_PIN		DIO_u8_PIN7

/* Tactile Switches */
#define PB_u8_TAC1_PORT		DIO_u8_PORTC
#define PB_u8_TAC1_PIN		DIO_u8_PIN0

#define PB_u8_TAC2_PORT		DIO_u8_PORTC
#define PB_u8_TAC2_PIN		DIO_u8_PIN1

#define PB_u8_TAC3_PORT		DIO_u8_PORTC
#define PB_u8_TAC3_PIN		DIO_u8_PIN2

/* PB Select Mode */
/* Options :PB_u8_ACTIVE_LOW
 * 			PB_u8_ACTIVE_HIGH */
#define PB_u8_PB_MODE		PB_u8_ACTIVE_LOW


#endif
