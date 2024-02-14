/********************************************************************************************************************/
/*****************     Author 		: Ahmed Abdelhady 	*************************************************************/
/*****************     File 		: Interface Of EXTI  *************************************************************/
/*****************     Date 		: 1/1/2023  		*************************************************************/
/*****************     Version 		: 1.0  				*************************************************************/
/*****************     Description 	: Drive For EXTI 	*************************************************************/
/********************************************************************************************************************/

#ifndef 	EXTI_INTERFACE_H
#define 	EXTI_INTERFACE_H

/* Macros For EXTI ID */
#define EXTI_u8_EXTI_0		6
#define EXTI_u8_EXTI_1		7	
#define EXTI_u8_EXTI_2		5

/* Macros For EXTI Sense */
#define EXTI_u8_TRIGG_LOW_LEVEL						0
#define EXTI_u8_TRIGG_ANY_LOGICAL_CHANGE			1
#define EXTI_u8_TRIGG_FALLING_EDGE					2
#define EXTI_u8_TRIGG_RISING_EDGE					3


u8 EXTI_u8Enable ( u8 Copy_u8Exti_ID ,u8 Copy_u8Exti_Sense )	;

u8 EXTI_u8Disable ( u8 Copy_u8Exti_ID )	;

u8 EXTI_u8SetCallBack (u8 Copy_u8Exti_ID , void (* Copy_Pf)(void) ) ;

#endif
