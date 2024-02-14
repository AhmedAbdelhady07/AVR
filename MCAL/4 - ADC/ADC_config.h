/********************************************************************************************************************/
/*****************     Author 		: Ahmed Abdelhady 	*************************************************************/
/*****************     File 		: Config Of ADC  	*************************************************************/
/*****************     Date 		: 1/1/2023  		*************************************************************/
/*****************     Version 		: 1.0  				*************************************************************/
/*****************     Description 	: Drive For ADC 	*************************************************************/
/********************************************************************************************************************/

#ifndef 	ADC_CONFIG_H
#define 	ADC_CONFIG_H

/* Choose ADC Vref */
/* Options : 	   ADC_u8_AREF
				   ADC_u8_AVCC
				   ADC_u8_INTERNAL_VREF
 */
#define 	ADC_u8_ADC_SELECT_VREF			ADC_u8_AVCC

/* Choose ADC Direction Adjust Result */
/* Options : 	ADC_u8_RIGHT_ADJUST when 10bits Resoultion
				ADC_u8_LEFT_ADJUST	when 8bits Resoultion
 */
#define 	ADC_u8_SELECT_DIERCTION_ADJUST_RESULT		ADC_u8_RIGHT_ADJUST


/* Choose ADC Prescaler */
/* Options : 	   ADC_u8_PRESCALER_2
				   ADC_u8_PRESCALER_4
				   ADC_u8_PRESCALER_8
				   ADC_u8_PRESCALER_16
				   ADC_u8_PRESCALER_32
				   ADC_u8_PRESCALER_64
				   ADC_u8_PRESCALER_128
 */

#define 	ADC_u8_SELECT_PRESCALER	ADC_u8_PRESCALER_64

#define 	ADC_u32_TIME_OUT_MAX_VALUE			50000



#endif
