/*************************************************************************/
/***************      Name 		:  Ahmed Abdelhady  	******************/
/***************      Date 		:  25 / 12 / 2022  		******************/
/***************      SWC 		:  DC_MOTOR          		******************/
/***************      Version 	:  1.0          		******************/
/*************************************************************************/

#ifndef DC_MOTOR_CONFIG_H
#define DC_MOTOR_CONFIG_H

/* Config pins of DC_MOTOR --> One Way */
#define DC_MOTOR_u8_PORT      		DIO_u8_PORTA
#define DC_MOTOR_u8_PIN    			DIO_u8_PIN0

/* Config pins of DC_MOTOR --> Two Ways */
#define DC_MOTOR_u8_PORT_PIN1     	DIO_u8_PORTA
#define DC_MOTOR_u8_PIN1    			DIO_u8_PIN0

#define DC_MOTOR_u8_PORT_PIN2     	DIO_u8_PORTA
#define DC_MOTOR_u8_PIN2   			DIO_u8_PIN1

/* Options : 		DC_MOTOR_u8_ONE_WAY
					DC_MOTOR_u8_TWO_WAYS_HBRIDGE
											*/
#define DC_MOTOR_u8_MODE	DC_MOTOR_u8_ONE_WAY


#endif
