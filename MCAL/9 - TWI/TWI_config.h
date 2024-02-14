/********************************************************************************************************************/
/*****************     Author 		: Ahmed Abdelhady 	*************************************************************/
/*****************     File 		: Config Of TWI  	*************************************************************/
/*****************     Date 		: 1/1/2023  		*************************************************************/
/*****************     Version 		: 1.0  				*************************************************************/
/*****************     Description 	: Drive For TWI 	*************************************************************/
/********************************************************************************************************************/

#ifndef 		TWI_CONFIG_H
#define 	TWI_CONFIG_H

/* Select CPU Frequency */
#define TWI_u32_F_CPU_FREQ		8000000

/* Select Prescaler Value */
/* Options :		1
					4
					16
					64
*/
#define TWI_u8_PRESCALER_VALUE		1

/* Enable/Disable ACK */
/* Options :		TWI_ENABLE_ACK
					TWI_DISABLE_ACK
*/

/* Enable/Disable General Call */
/* Options :		TWI_ENABLE_GC
					TWI_DISABLE_GC
*/
#define TWI_u8_GENERAL_CALL		TWI_DISABLE_GC

/* Select TWI Frequency in Hz */
#define TWI_u8_Frequency						200000

#define 	TWI_u32_TIME_OUT_MAX_VALUE			50000

#endif
