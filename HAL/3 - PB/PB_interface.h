/********************************************************************************************************************/
/*****************     Author 		: Ahmed Abdelhady 	*************************************************************/
/*****************     File 		: Interface Of PB  *************************************************************/
/*****************     Date 		: 1/1/2023  		*************************************************************/
/*****************     Version 		: 1.0  				*************************************************************/
/*****************     Description 	: Drive For PB 	*************************************************************/
/********************************************************************************************************************/

#ifndef 	PB_INTERFACE_H
#define 	PB_INTERFACE_H

/* DIP Switches */
#define PB_u8_DIP1			1
#define PB_u8_DIP2	    	2
#define PB_u8_DIP3       	3 
#define PB_u8_DIP4        	4 
#define PB_u8_DIP5        	5 
#define PB_u8_DIP6        	6 
#define PB_u8_DIP7        	7 
#define PB_u8_DIP8        	8

/* Tac Switches */
#define PB_u8_TAC1		9
#define PB_u8_TAC2		10	
#define PB_u8_TAC3		11

/* Switch Status */

#define PB_u8_SWITCH_PRESSED_L			0
#define PB_u8_SWITCH_NOT_PRESSED_L		1

#define PB_u8_SWITCH_PRESSED_H			1
#define PB_u8_SWITCH_NOT_PRESSED_H		0
	

u8 PB_u8Init (u8 Copy_u8PB_ID) ;

u8 PB_u8SwitchStatus (u8 Copy_u8PB_ID , u8 * Copy_Pu8ReturnedPBValue) ;

#endif
