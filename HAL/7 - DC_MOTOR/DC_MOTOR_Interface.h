/*************************************************************************/
/***************      Name 		:  Ahmed Abdelhady  	******************/
/***************      Date 		:  25 / 12 / 2022  		******************/
/***************      SWC 		:  DC_MOTOR          		******************/
/***************      Version 	:  1.0          		******************/
/*************************************************************************/

#ifndef DC_MOTOR_INTERFACE_H
#define DC_MOTOR_INTERFACE_H

#define DC_MOTOR_u8_ONE_WAY			0
#define DC_MOTOR_u8_WITHCLKWISE		1
#define DC_MOTOR_u8_COUNTERCLKWISE	2


void DC_MOTOR_voidInit 	(void);
u8 DC_MOTOR_voidTurnOn 	(u8 Copy_u8direction) ;
void DC_MOTOR_voidTurnOff 	(void) ;



#endif


