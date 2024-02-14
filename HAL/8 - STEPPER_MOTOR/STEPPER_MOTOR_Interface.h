/*************************************************************************/
/***************      Name 		:  Ahmed Abdelhady  	******************/
/***************      Date 		:  25 / 12 / 2022  		******************/
/***************      SWC 		: STEPPER_MOTOR          		******************/
/***************      Version 	:  1.0          		******************/
/*************************************************************************/

#ifndef STEPPER_MOTOR_INTERFACE_H
#define STEPPER_MOTOR_INTERFACE_H


#define STEPPER_MOTOR_u8_CLK_WISE				0
#define	STEPPER_MOTOR_u8_COUNTER_CLK_WISE		1

void STEPPER_MOTOR_voidInit 	(void);
u8 STEPPER_MOTOR_voidTurnOn 	(u8 Copy_u8Direction , u16 Copy_u16Angle) ;
void STEPPER_MOTOR_voidTurnOff 	(void) ;



#endif


