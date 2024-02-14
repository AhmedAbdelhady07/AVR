/********************************************************************************************************************/
/*****************     Author 		: Ahmed Abdelhady 	*************************************************************/
/*****************     File 		: Private Of ADC  	*************************************************************/
/*****************     Date 		: 1/1/2023  		*************************************************************/
/*****************     Version 		: 1.0  				*************************************************************/
/*****************     Description 	: Drive For ADC 	*************************************************************/
/********************************************************************************************************************/

#ifndef 	ADC_PRIVATE_H
#define 	ADC_PRIVATE_H

/* ADC Registers */

/* Special FunctionIO Register */
#define ADC_u8_SFIOR_REG					* (( volatile u8 * )0x50)

/* ADC Multiplexer Selection Register */
#define 	ADC_u8_ADMUX_REG				* (( volatile u8 * )0x27)

/* ADC Control and Status Register A – */
#define 	ADC_u8_ADCSRA_REG				* (( volatile u8 * )0x26)

/* Data Register H */
#define 	ADC_u8_ADCH_REG					* (( volatile u8 * )0x25)

/* Data Register L */
#define 	ADC_u8_ADCL_REG					* (( volatile u8 * )0x24)

/* ADC Data Register */
#define 	ADC_u16_ADC_REG					* (( volatile u16 * )0x24)

/* ADC Bits */

/* ADMUX - Bits*/
#define 	ADC_u8_REFS1_BIT				7
#define 	ADC_u8_REFS0_BIT				6
#define 	ADC_u8_ADLAR_BIT				5
#define 	ADC_u8_ MUX4_BIT				4
#define 	ADC_u8_MUX3_BIT					3
#define 	ADC_u8_MUX2_BIT					2
#define 	ADC_u8_MUX1_BIT					1
#define 	ADC_u8_MUX0_BIT					0

/* ADCSRA - Bits */
#define 	ADC_u8_ADEN_BIT					7
#define 	ADC_u8_ADSC_BIT					6
#define 	ADC_u8_ADATE_BIT					5
#define 	ADC_u8_ADIF_BIT					4
#define 	ADC_u8_ADIE_BIT					3
#define 	ADC_u8_ADPS2_BIT					2
#define 	ADC_u8_ADPS1_BIT					1
#define 	ADC_u8_ADPS0_BIT					0

/* ADMUX Masking */

#define ADC_u8_ADMUX_MASKING	0b11100000

/* VREF Chooses */
#define ADC_u8_AREF							0
#define ADC_u8_AVCC							1
#define ADC_u8_INTERNAL_VREF			2

/*Direction Adjust Result */
#define ADC_u8_RIGHT_ADJUST							0
#define ADC_u8_LEFT_ADJUST								1

/* Conv Mode :Auto Triggering Masking */
#define ADC_u8_AUTO_TRIGGER_MASKING		0b00011111

/* ADC Prescaler Chooses */
#define 	ADC_u8_PRESCALER_2					0
#define     ADC_u8_PRESCALER_4 				1
#define     ADC_u8_PRESCALER_8 				2
#define	    ADC_u8_PRESCALER_16				3
#define     ADC_u8_PRESCALER_32 				4
#define     ADC_u8_PRESCALER_64 				5
#define     ADC_u8_PRESCALER_128 			6

#endif
