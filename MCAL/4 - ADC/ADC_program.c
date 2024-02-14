/********************************************************************************************************************/
/*****************     Author 		: Ahmed Abdelhady 	*************************************************************/
/*****************     File 		: Program Of ADC  	*************************************************************/
/*****************     Date 		: 1/1/2023  		*************************************************************/
/*****************     Version 		: 1.0  				*************************************************************/
/*****************     Description 	: Drive For ADC 	*************************************************************/
/********************************************************************************************************************/

/* LIB Layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU       8000000UL
#include "util/delay.h"

/* MCAL Layer */
#include "ADC_private.h"
#include "ADC_config.h"
#include "ADC_interface.h"


/* Global Variables */
static void (*ADC_pfNotifiFunc)(u16) = NULL ;

/*ADC busy flag */
static u8 ADC_u8BusyFlag = 0 ;

u8 ADC_u8Init (void)
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;

	/* Selection Vref   */
#if(ADC_u8_ADC_SELECT_VREF == ADC_u8_AREF)
	CLR_BIT (ADC_u8_ADMUX_REG , ADC_u8_REFS0_BIT)	;
	CLR_BIT (ADC_u8_ADMUX_REG , ADC_u8_REFS1_BIT) 	;

#elif(ADC_u8_ADC_SELECT_VREF == ADC_u8_AVCC)
	SET_BIT (ADC_u8_ADMUX_REG , ADC_u8_REFS0_BIT)	;
	CLR_BIT (ADC_u8_ADMUX_REG , ADC_u8_REFS1_BIT)	 ;

#elif(ADC_u8_ADC_SELECT_VREF == ADC_u8_INTERNAL_VREF)
	SET_BIT (ADC_u8_ADMUX_REG , ADC_u8_REFS0_BIT)	;
	SET_BIT (ADC_u8_ADMUX_REG , ADC_u8_REFS1_BIT) 	;
#else
	Local_u8ErrorState = STD_TYPES_NOK ;
#endif



	/* Selection Direction Adjust Result */
#if(ADC_u8_SELECT_DIERCTION_ADJUST_RESULT == ADC_u8_RIGHT_ADJUST)
	CLR_BIT (ADC_u8_ADMUX_REG , ADC_u8_ADLAR_BIT) ;
#elif(ADC_u8_SELECT_DIERCTION_ADJUST_RESULT == ADC_u8_LEFT_ADJUST)
	SET_BIT (ADC_u8_ADMUX_REG , ADC_u8_ADLAR_BIT) ;
#else
	Local_u8ErrorState = STD_TYPES_NOK ;
#endif


	/* Selection ADC Prescaler */
#if(ADC_u8_SELECT_PRESCALER == ADC_u8_PRESCALER_2)
	CLR_BIT (ADC_u8_ADCSRA_REG , ADC_u8_ADPS0_BIT) ;
	CLR_BIT (ADC_u8_ADCSRA_REG , ADC_u8_ADPS1_BIT);
	CLR_BIT (ADC_u8_ADCSRA_REG , ADC_u8_ADPS2_BIT);
#elif(ADC_u8_SELECT_PRESCALER == ADC_u8_PRESCALER_4)
	CLR_BIT (ADC_u8_ADCSRA_REG , ADC_u8_ADPS0_BIT) ;
	SET_BIT (ADC_u8_ADCSRA_REG , ADC_u8_ADPS1_BIT);
	CLR_BIT (ADC_u8_ADCSRA_REG , ADC_u8_ADPS2_BIT);
#elif(ADC_u8_SELECT_PRESCALER == ADC_u8_PRESCALER_8)
	SET_BIT (ADC_u8_ADCSRA_REG , ADC_u8_ADPS0_BIT) ;
	SET_BIT (ADC_u8_ADCSRA_REG , ADC_u8_ADPS1_BIT);
	CLR_BIT (ADC_u8_ADCSRA_REG , ADC_u8_ADPS2_BIT);
#elif(ADC_u8_SELECT_PRESCALER == ADC_u8_PRESCALER_16)
	CLR_BIT (ADC_u8_ADCSRA_REG , ADC_u8_ADPS0_BIT) ;
	CLR_BIT (ADC_u8_ADCSRA_REG , ADC_u8_ADPS1_BIT);
	SET_BIT (ADC_u8_ADCSRA_REG , ADC_u8_ADPS2_BIT);
#elif(ADC_u8_SELECT_PRESCALER == ADC_u8_PRESCALER_32)
	SET_BIT (ADC_u8_ADCSRA_REG , ADC_u8_ADPS0_BIT) ;
	CLR_BIT (ADC_u8_ADCSRA_REG , ADC_u8_ADPS1_BIT);
	SET_BIT (ADC_u8_ADCSRA_REG , ADC_u8_ADPS2_BIT);
#elif(ADC_u8_SELECT_PRESCALER == ADC_u8_PRESCALER_64)
	CLR_BIT (ADC_u8_ADCSRA_REG , ADC_u8_ADPS0_BIT) ;
	SET_BIT (ADC_u8_ADCSRA_REG , ADC_u8_ADPS1_BIT);
	SET_BIT (ADC_u8_ADCSRA_REG , ADC_u8_ADPS2_BIT);
#elif(ADC_u8_SELECT_PRESCALER == ADC_u8_PRESCALER_128)
	SET_BIT (ADC_u8_ADCSRA_REG , ADC_u8_ADPS0_BIT) ;
	SET_BIT (ADC_u8_ADCSRA_REG , ADC_u8_ADPS1_BIT);
	SET_BIT (ADC_u8_ADCSRA_REG , ADC_u8_ADPS2_BIT);
#else
	Local_u8ErrorState = STD_TYPES_NOK ;
#endif



	/* Enable ADC */
	SET_BIT (ADC_u8_ADCSRA_REG , ADC_u8_ADEN_BIT);

	return Local_u8ErrorState ;

}

u8 ADC_u8GetDigitalValueSynchNonBlocking (u8 Copy_u8ChannelNumber ,u8 Copy_u8ConvMode , u16 * Copy_Pu16DigitalValue)
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;

	u32 Local_u32TimeOutCounter = 0 ;

	if((Copy_u8ChannelNumber <32) && (Copy_Pu16DigitalValue !=NULL) && (ADC_u8BusyFlag == 0))
	{
		/* Set flag to make ADC is Busy */
		ADC_u8BusyFlag = 1 ;

		/* Select Channel */
		/* Clear  MUX4....0 */
		ADC_u8_ADMUX_REG &= ADC_u8_ADMUX_MASKING ;
		/* Selection Channel */
		ADC_u8_ADMUX_REG |= Copy_u8ChannelNumber ;


		/* Selection Conv Mode */
		if(Copy_u8ConvMode == ADC_u8_SINGLE_CONV_MODE)
		{
			/* Disable Auto Triggering */
			CLR_BIT (ADC_u8_ADCSRA_REG , ADC_u8_ADATE_BIT) ;

			/* Start Conversion */
			SET_BIT (ADC_u8_ADCSRA_REG , ADC_u8_ADSC_BIT) ;
		}
		else if (Copy_u8ConvMode == ADC_u8_AUTO_TRIGG_CONV_FREE_RUNNING_MODE)
		{
			/* Enable Auto Triggering */
			SET_BIT (ADC_u8_ADCSRA_REG , ADC_u8_ADATE_BIT) ;
			/* Clear ADT 2...0 */
			ADC_u8_SFIOR_REG &= ADC_u8_AUTO_TRIGGER_MASKING ;
			/* Selection Auto Trigger Conv Mode */
			ADC_u8_SFIOR_REG |= (Copy_u8ConvMode<<5) ;

			/* Start Conversion */
			SET_BIT (ADC_u8_ADCSRA_REG , ADC_u8_ADSC_BIT) ;
		}
		else
		{
			Local_u8ErrorState = STD_TYPES_NOK ;
		}

		/* Wait flag = 1 */
		while ( (GET_BIT( ADC_u8_ADCSRA_REG , ADC_u8_ADIF_BIT) == 0) && (Local_u32TimeOutCounter < ADC_u32_TIME_OUT_MAX_VALUE ))
		{
			Local_u32TimeOutCounter ++ ;
		}
		/* while (! GET_BIT( ADC_u8_ADCSRA_REG	 , ADC_u8_ADIF_BIT))	; */

		if(GET_BIT( ADC_u8_ADCSRA_REG , ADC_u8_ADIF_BIT) != 0)/* Can check that counter < ADC_u32_TIME_OUT_MAX_VALUE also */
		{
			/* Clear Flag ---Polling Needs Self Clear Flag*/
			SET_BIT( ADC_u8_ADCSRA_REG , ADC_u8_ADIF_BIT )	;

			/* Read The Digital Value */
#if( ADC_u8_SELECT_DIERCTION_ADJUST_RESULT == ADC_u8_RIGHT_ADJUST )
			* Copy_Pu16DigitalValue = ADC_u16_ADC_REG ;
#elif( ADC_u8_SELECT_DIERCTION_ADJUST_RESULT == ADC_u8_LEFT_ADJUST )
			* Copy_Pu16DigitalValue = ADC_u8_ADCH_REG ;
#else
			Local_u8ErrorState = STD_TYPES_NOK ;
#endif
			/* Clear ADC Busy Flag */
			ADC_u8BusyFlag = 0 ;

		}
		else
		{
			Local_u8ErrorState = STD_TYPES_NOK ;
		}

	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}

	return Local_u8ErrorState ;
}

u8 ADC_u8GetDigitalValueAsynch (u8 Copy_u8ChannelNumber ,u8 Copy_u8ConvMode , void (*Copy_pfNotifiFunc)(u16))
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;


	if((Copy_u8ChannelNumber < 32) && (Copy_pfNotifiFunc !=NULL) && (ADC_u8BusyFlag == 0))
	{
		/* Set flag to make ADC is Busy */
		ADC_u8BusyFlag = 1 ;

		/* Update Global pf */
		ADC_pfNotifiFunc = Copy_pfNotifiFunc ;

		/* Enable ADC Interrupt */
		SET_BIT(ADC_u8_ADCSRA_REG , ADC_u8_ADIE_BIT) ;

		/* Select Channel */
		/* Clear  MUX4....0 */
		ADC_u8_ADMUX_REG &= ADC_u8_ADMUX_MASKING ;
		/* Selection Channel */
		ADC_u8_ADMUX_REG |= Copy_u8ChannelNumber ;

		/* Selection Conv Mode */
		if(Copy_u8ConvMode == ADC_u8_SINGLE_CONV_MODE)
		{
			/* Disable Auto Triggering */
			CLR_BIT (ADC_u8_ADCSRA_REG , ADC_u8_ADATE_BIT) ;
		}
		else
		{
			/* Enable Auto Triggering */
			SET_BIT (ADC_u8_ADCSRA_REG , ADC_u8_ADATE_BIT) ;
			/* Clear ADT 2...0 */
			ADC_u8_SFIOR_REG &= ADC_u8_AUTO_TRIGGER_MASKING ;
			/* Selection Auto Trigger Conv Mode */
			ADC_u8_SFIOR_REG |= (Copy_u8ConvMode<<5) ;
		}

		/* Start Conversion */
		if((Copy_u8ConvMode == ADC_u8_SINGLE_CONV_MODE) || (Copy_u8ConvMode == ADC_u8_AUTO_TRIGG_CONV_FREE_RUNNING_MODE) )
			SET_BIT (ADC_u8_ADCSRA_REG , ADC_u8_ADSC_BIT) ;

	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}

	return Local_u8ErrorState ;
}

u8 ADC_u8GetADCRegValue (u16 * Copy_Pu16ADCDigValue)
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;

	if(Copy_Pu16ADCDigValue != NULL)
	{
		/* Read The Digital Value */
#if( ADC_u8_SELECT_DIERCTION_ADJUST_RESULT == ADC_u8_RIGHT_ADJUST )
		* Copy_Pu16ADCDigValue = ADC_u16_ADC_REG ;
#elif( ADC_u8_SELECT_DIERCTION_ADJUST_RESULT == ADC_u8_LEFT_ADJUST )
		* Copy_Pu16ADCDigValue = ADC_u8_ADCH_REG ;
#else
		Local_u8ErrorState = STD_TYPES_NOK ;
#endif
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}

	return Local_u8ErrorState ;
}

void ADC_voidDisableADC (void)
{
	CLR_BIT (ADC_u8_ADCSRA_REG , ADC_u8_ADEN_BIT);
}

/* Prototype for ADC ISR Func */
void __vector_16 (void)   __attribute__((signal)) ;
void __vector_16 (void) 
{
	if(ADC_pfNotifiFunc != NULL)
	{
		/* Clear ADC Busy Flag */
		ADC_u8BusyFlag = 0 ;

		/*Call APP Func */
		/* Read The Digital Value */
#if( ADC_u8_SELECT_DIERCTION_ADJUST_RESULT == ADC_u8_RIGHT_ADJUST )
		ADC_pfNotifiFunc (ADC_u16_ADC_REG);
#elif( ADC_u8_SELECT_DIERCTION_ADJUST_RESULT == ADC_u8_LEFT_ADJUST )
		ADC_pfNotifiFunc ((u16)ADC_u8_ADCH_REG);
#else
		/* Do nothing */
#endif
	}
}

