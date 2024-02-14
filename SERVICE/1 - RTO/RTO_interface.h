/********************************************************************************************************************/
/*****************     Author 		: Ahmed Abdelhady 	*************************************************************/
/*****************     File 		: Interface Of RTO  *************************************************************/
/*****************     Date 		: 8/10/2023  		*************************************************************/
/*****************     Version 		: 1.0  				*************************************************************/
/*****************     Description 	: Drive For RTO 	*************************************************************/
/********************************************************************************************************************/

#ifndef 	RTO_INTERFACE_H
#define 	RTO_INTERFACE_H

void RTO_voidInit	(void) ;

u8 RTO_u8CreateTask (u8 Copy_u8Priority , u16 Copy_u16Periodicty , u16 Copy_u16FirstDelay , void (* Copy_Pf)(void)) ;

void RTO_voidStartScheduler (u32 Copy_u32DTime) ;


#endif