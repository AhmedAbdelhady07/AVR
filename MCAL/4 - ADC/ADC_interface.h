/********************************************************************************************************************/
/*****************     Author 		: Ahmed Abdelhady 	*************************************************************/
/*****************     File 		: Interface Of ADC  *************************************************************/
/*****************     Date 		: 1/1/2023  		*************************************************************/
/*****************     Version 		: 1.0  				*************************************************************/
/*****************     Description 	: Drive For ADC 	*************************************************************/
/********************************************************************************************************************/

#ifndef 	ADC_INTERFACE_H
#define 	ADC_INTERFACE_H

/* Channels Of ADC */
#define ADC_u8_CHANNEL_0		0
#define ADC_u8_CHANNEL_1		1
#define ADC_u8_CHANNEL_2		2
#define ADC_u8_CHANNEL_3		3
#define ADC_u8_CHANNEL_4		4
#define ADC_u8_CHANNEL_5		5
#define ADC_u8_CHANNEL_6		6
#define ADC_u8_CHANNEL_7		7

/* ADC Conversion Modes */
#define ADC_u8_SINGLE_CONV_MODE								10
#define ADC_u8_AUTO_TRIGG_CONV_FREE_RUNNING_MODE			0
#define ADC_u8_AUTO_TRIGG_CONV_ANALOG_COMPARATOR			1
#define ADC_u8_AUTO_TRIGG_CONV_EXTI0						2
#define ADC_u8_AUTO_TRIGG_CONV_TIMER_0_CM					3
#define ADC_u8_AUTO_TRIGG_CONV_TIMER_0_OVF					4
#define ADC_u8_AUTO_TRIGG_CONV_TIMER_1_CM_B					5
#define ADC_u8_AUTO_TRIGG_CONV_TIMER_1_OVF					6
#define ADC_u8_AUTO_TRIGG_CONV_TIMER_1_CE					7




u8 ADC_u8Init (void)	;

u8 ADC_u8GetDigitalValueSynchNonBlocking (u8 Copy_u8ChannelNumber ,u8 Copy_u8ConvMode , u16 * Copy_Pu16DigitalValue)	;

u8 ADC_u8GetDigitalValueAsynch (u8 Copy_u8ChannelNumber ,u8 Copy_u8ConvMode , void (*Copy_pfNotifiFunc)(u16)) ;

u8 ADC_u8GetADCRegValue (u16 * Copy_Pu16ADCDigValue);

void ADC_voidDisableADC (void)	;

#endif
