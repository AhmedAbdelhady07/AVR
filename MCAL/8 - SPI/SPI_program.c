/********************************************************************************************************************/
/*****************     Author 		: Ahmed Abdelhady 	*************************************************************/
/*****************     File 		: Program Of SPI  	*************************************************************/
/*****************     Date 		: 27/9/2023  		*************************************************************/
/*****************     Version 		: 1.0  				*************************************************************/
/*****************     Description 	: Drive For SPI 	*************************************************************/
/********************************************************************************************************************/

/* LIB Layer */
#include "util/delay.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL Layer */
#include "SPI_private.h"
#include "SPI_config.h"
#include "SPI_interface.h"

/******************  Global Variables ******************/
static void (* SPI_APfCallBack)(void) = NULL;

static u8 SPI_u8BusyFlag = 0 ;

static u8 * SPI_pu8ReceivedString = NULL ;

static u8 * SPI_pu8TransmittedString = NULL ;

static u8 SPI_u8MessageSize = 0 ;
static u8 SPI_u8MessageSize2 = 0 ;

void SPI_voidInit (void)
{
	/* Master Slave Select */
#if (SPI_MASTER_SLAVE_SELECT == SPI_MASTER)
	SET_BIT(SPI_u8_SPCR_REG , SPI_u8_SPCR_MSTR_BIT) ;

	/* FOSC Select */
#if (SPI_CLK_RATE_SELECT == SPI_FOSC_4)
	CLR_BIT(SPI_u8_SPCR_REG , SPI_u8_SPCR_SPR0_BIT) ;
	CLR_BIT(SPI_u8_SPCR_REG , SPI_u8_SPCR_SPR1_BIT) ;
#elif(SPI_CLK_RATE_SELECT == SPI_FOSC_16)
	SET_BIT(SPI_u8_SPCR_REG , SPI_u8_SPCR_SPR0_BIT) ;
	CLR_BIT(SPI_u8_SPCR_REG , SPI_u8_SPCR_SPR1_BIT) ;
#elif(SPI_CLK_RATE_SELECT == SPI_FOSC_64)
	CLR_BIT(SPI_u8_SPCR_REG , SPI_u8_SPCR_SPR0_BIT) ;
	SET_BIT(SPI_u8_SPCR_REG , SPI_u8_SPCR_SPR1_BIT) ;
#elif(SPI_CLK_RATE_SELECT == SPI_FOSC_128)
	SET_BIT(SPI_u8_SPCR_REG , SPI_u8_SPCR_SPR0_BIT) ;
	SET_BIT(SPI_u8_SPCR_REG , SPI_u8_SPCR_SPR1_BIT) ;
#endif

#elif(SPI_MASTER_SLAVE_SELECT == SPI_SLAVE)
	CLR_BIT(SPI_u8_SPCR_REG , SPI_u8_SPCR_MSTR_BIT) ;
#endif

	/* Data Order */
#if (SPI_DATA_ORDER_SELECT == SPI_LSB)
	SET_BIT(SPI_u8_SPCR_REG , SPI_u8_SPCR_DORD_BIT) ;
#elif(SPI_DATA_ORDER_SELECT == SPI_MSB)
	CLR_BIT(SPI_u8_SPCR_REG , SPI_u8_SPCR_DORD_BIT) ;
#endif

	/* Clk Polarity select */
#if (SPI_CLK_POLARITY_SELECT == SPI_RISING_FALLING)
	CLR_BIT(SPI_u8_SPCR_REG , SPI_u8_SPCR_CPOL_BIT) ;
#elif(SPI_CLK_POLARITY_SELECT == SPI_FALLING_RISING)
	SET_BIT(SPI_u8_SPCR_REG , SPI_u8_SPCR_CPOL_BIT) ;
#endif

	/* Clk Phase select */
#if (SPI_CLK_PHASE_SELECT == SPI_SAMPLE_SETUP)
	CLR_BIT(SPI_u8_SPCR_REG , SPI_u8_SPCR_CPHA_BIT) ;
#elif(SPI_CLK_PHASE_SELECT == SPI_SETUP_SAMPLE)
	SET_BIT(SPI_u8_SPCR_REG , SPI_u8_SPCR_CPHA_BIT) ;
#endif

#if (SPI_CLK_SPEED_SELECT == SPI_NORMAL_SPEED)
	CLR_BIT(SPI_u8_SPSR_REG , SPI_u8_SPSR_SPI2X_BIT) ;
#elif(SPI_CLK_SPEED_SELECT == SPI_DOUBLE_SPEED)
	SET_BIT(SPI_u8_SPSR_REG , SPI_u8_SPSR_SPI2X_BIT) ;
#endif

	/* Enable SPI */
	SET_BIT(SPI_u8_SPCR_REG , SPI_u8_SPCR_SPE_BIT) ;
}

u8 SPI_u8TransmitReceiveByteSynchBlocking (u8 Copy_u8TransmittedByte , u8 * Copy_pu8ReceivedByte)
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;

	if(Copy_pu8ReceivedByte != NULL)
	{
		/* Send Byte */
		SPI_u8_SPDR_REG = Copy_u8TransmittedByte ;

		/* Check if the transmission is completed */
		while ((GET_BIT(SPI_u8_SPSR_REG , SPI_u8_SPSR_SPIF_BIT)) == 0) ;

		/* Read Data */
		*Copy_pu8ReceivedByte = SPI_u8_SPDR_REG ;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}

	return Local_u8ErrorState ;
}

u8 SPI_u8TransmitReceiveByteSynchNonBlocking (u8 Copy_u8TransmittedByte , u8 * Copy_pu8ReceivedByte)
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;

	u16 Local_u16Counter = 0 ;

	if(Copy_pu8ReceivedByte != NULL)
	{
		/* Send Byte */
		SPI_u8_SPDR_REG = Copy_u8TransmittedByte ;

		/* Check if the transmission is completed */
		while ((Local_u16Counter < 2000) && ((GET_BIT(SPI_u8_SPSR_REG , SPI_u8_SPSR_SPIF_BIT)) == 0))
		{
			Local_u16Counter ++ ;
		}

		if((GET_BIT(SPI_u8_SPSR_REG , SPI_u8_SPSR_SPIF_BIT)) == 1)
		{
			/* Read Data */
			* Copy_pu8ReceivedByte = SPI_u8_SPDR_REG ;
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

u8 SPI_u8TransmitReceiveStringSynchBlocking (u8 * Copy_pu8TransmittedString , u8 * Copy_pu8ReceivedString , u8 Copy_u8MessageSize)
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;

	u8 Local_u8MessageSize2 = 0 ;

	u8 Local_u8Counter = 0 ;

	if((Copy_pu8TransmittedString != NULL) && (Copy_pu8ReceivedString != NULL))
	{
#if(SPI_MASTER_SLAVE_SELECT == SPI_MASTER)
		_delay_ms(2) ;
#endif
		SPI_u8_SPDR_REG = Copy_u8MessageSize ;

		while ((GET_BIT(SPI_u8_SPSR_REG , SPI_u8_SPSR_SPIF_BIT)) == 0) ;

		Local_u8MessageSize2 = SPI_u8_SPDR_REG ;

		if(Local_u8MessageSize2 > Copy_u8MessageSize)
		{
			Copy_u8MessageSize = Local_u8MessageSize2 ;
		}

		while(Local_u8Counter < Copy_u8MessageSize)
		{
#if(SPI_MASTER_SLAVE_SELECT == SPI_MASTER)
			_delay_ms(2) ;
#endif
			if(Copy_pu8TransmittedString[Local_u8Counter] != '\0')
			{
				SPI_u8_SPDR_REG = Copy_pu8TransmittedString[Local_u8Counter] ;
			}
			else
			{
				SPI_u8_SPDR_REG = SPI_DUMMY_DATA ;
			}
			/* Check if the transmission is completed */
			while ((GET_BIT(SPI_u8_SPSR_REG , SPI_u8_SPSR_SPIF_BIT)) == 0) ;

			Copy_pu8ReceivedString[Local_u8Counter] = SPI_u8_SPDR_REG ;

			Local_u8Counter ++ ;
		}

		Copy_pu8ReceivedString[Local_u8Counter] = '\0' ;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}

	return Local_u8ErrorState ;
}

u8 SPI_u8TransmitReceiveStringSynchNonBlocking (u8 * Copy_pu8TransmittedString , u8 * Copy_pu8ReceivedString , u8 Copy_u8MessageSize)
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;

	u8 Local_u8MessageSize2 = 0 ;

	u8 Local_u8Counter = 0 ;

	u16 Local_u16Counter = 0 ;

	if((Copy_pu8TransmittedString != NULL) && (Copy_pu8ReceivedString != NULL))
	{
#if(SPI_MASTER_SLAVE_SELECT == SPI_MASTER)
		_delay_ms(2) ;
#endif
		SPI_u8_SPDR_REG = Copy_u8MessageSize ;

		while ((Local_u16Counter < 2000) && ((GET_BIT(SPI_u8_SPSR_REG , SPI_u8_SPSR_SPIF_BIT)) == 0))
		{
			Local_u16Counter ++ ;
		}

		if((GET_BIT(SPI_u8_SPSR_REG , SPI_u8_SPSR_SPIF_BIT)) == 1)
		{

			Local_u8MessageSize2 = SPI_u8_SPDR_REG ;

			if(Local_u8MessageSize2 > Copy_u8MessageSize)
			{
				Copy_u8MessageSize = Local_u8MessageSize2 ;
			}

			while(Local_u8Counter < Copy_u8MessageSize)
			{
#if(SPI_MASTER_SLAVE_SELECT == SPI_MASTER)
				_delay_ms(2) ;
#endif
				if(Copy_pu8TransmittedString[Local_u8Counter] != '\0')
				{
					SPI_u8_SPDR_REG = Copy_pu8TransmittedString[Local_u8Counter] ;
				}
				else
				{
					SPI_u8_SPDR_REG = SPI_DUMMY_DATA ;
				}
				/* Check if the transmission is completed */
				while ((GET_BIT(SPI_u8_SPSR_REG , SPI_u8_SPSR_SPIF_BIT)) == 0) ;

				Copy_pu8ReceivedString[Local_u8Counter] = SPI_u8_SPDR_REG ;

				Local_u8Counter ++ ;
			}

			Copy_pu8ReceivedString[Local_u8Counter] = '\0' ;
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

u8 SPI_u8TransmitReceiveStringAsynch (u8 * Copy_pu8TransmittedString , u8 * Copy_pu8ReceivedString , void (*Copy_pf)(void) , u8 Copy_u8MessageSize)
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;

	if((SPI_u8BusyFlag == 0) && (Copy_pu8TransmittedString != NULL) && (Copy_pu8ReceivedString != NULL) && (Copy_pf != NULL))
	{
		SPI_u8BusyFlag = 1 ;

		SPI_APfCallBack = Copy_pf ;

		SPI_pu8ReceivedString = Copy_pu8ReceivedString ;

		SPI_u8MessageSize2 = Copy_u8MessageSize ;

		SPI_pu8TransmittedString = Copy_pu8TransmittedString ;
		/* Send Message Size */
		SPI_u8_SPDR_REG = Copy_u8MessageSize ;

		/* Enable Interrupt */
		SET_BIT(SPI_u8_SPCR_REG , SPI_u8_SPCR_SPIE_BIT) ;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}

	return Local_u8ErrorState ;
}

void SPI_voidSendByteSynchBlocking(u8 Copy_u8DataByte)
{
#if (SPI_MASTER_SLAVE_SELECT == SPI_MASTER)
	_delay_ms(1) ;
#endif
	/* Send Byte */
	SPI_u8_SPDR_REG = Copy_u8DataByte ;
	while ((GET_BIT(SPI_u8_SPSR_REG , SPI_u8_SPSR_SPIF_BIT)) == 0) ;
	Copy_u8DataByte = SPI_u8_SPDR_REG ;
}

u8 SPI_u8SendByteSynchNonBlocking(u8 Copy_u8DataByte)
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;
	u16 Local_u16Counter = 0 ;
#if (SPI_MASTER_SLAVE_SELECT == SPI_MASTER)
	_delay_ms(1) ;
#endif
	/* Send Byte */
	SPI_u8_SPDR_REG = Copy_u8DataByte ;
	while ((Local_u16Counter < 2000) && (GET_BIT(SPI_u8_SPSR_REG , SPI_u8_SPSR_SPIF_BIT)) == 0)
	{
		Local_u16Counter ++ ;
	}

	if((GET_BIT(SPI_u8_SPSR_REG , SPI_u8_SPSR_SPIF_BIT)) == 1)
	{
		Copy_u8DataByte = SPI_u8_SPDR_REG ;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}

	return Local_u8ErrorState ;
}

u8 SPI_u8SendStringSynchBlocking (u8 * Copy_pu8TransmittedString , u8 Copy_u8MessageSize)
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;

	u8 Local_u8Counter = 0 ;

	if(Copy_pu8TransmittedString != NULL)
	{
#if (SPI_MASTER_SLAVE_SELECT == SPI_MASTER)
		_delay_ms(1) ;
#endif
		SPI_u8_SPDR_REG	= Copy_u8MessageSize ;

		while ((GET_BIT(SPI_u8_SPSR_REG , SPI_u8_SPSR_SPIF_BIT)) == 0) ;

		while(Copy_pu8TransmittedString[Local_u8Counter] != '\0')
		{
#if (SPI_MASTER_SLAVE_SELECT == SPI_MASTER)
			_delay_ms(1) ;
#endif
			SPI_u8_SPDR_REG = Copy_pu8TransmittedString[Local_u8Counter] ;
			while ((GET_BIT(SPI_u8_SPSR_REG , SPI_u8_SPSR_SPIF_BIT)) == 0) ;
			Local_u8Counter ++ ;

		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}
	return Local_u8ErrorState ;
}

u8 SPI_u8SendStringSynchNonBlocking (u8 * Copy_pu8TransmittedString , u8 Copy_u8MessageSize)
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;

	u8 Local_u8Counter = 0 ;

	u16 Local_u16Counter = 0 ;

	if(Copy_pu8TransmittedString != NULL)
	{
#if (SPI_MASTER_SLAVE_SELECT == SPI_MASTER)
		_delay_ms(1) ;
#endif
		SPI_u8_SPDR_REG	= Copy_u8MessageSize ;
		while ((Local_u16Counter < 2000 )&& ((GET_BIT(SPI_u8_SPSR_REG , SPI_u8_SPSR_SPIF_BIT)) == 0))
		{
			Local_u16Counter ++ ;
		}

		if((GET_BIT(SPI_u8_SPSR_REG , SPI_u8_SPSR_SPIF_BIT)) == 1)
		{

			while(Copy_pu8TransmittedString[Local_u8Counter] != '\0')
			{
#if (SPI_MASTER_SLAVE_SELECT == SPI_MASTER)
				_delay_ms(1) ;
#endif
				SPI_u8_SPDR_REG = Copy_pu8TransmittedString[Local_u8Counter] ;
				while ((GET_BIT(SPI_u8_SPSR_REG , SPI_u8_SPSR_SPIF_BIT)) == 0) ;
				Local_u8Counter ++ ;

			}
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

u8 SPI_u8ReceiveByte(void)
{
#if (SPI_MASTER_SLAVE_SELECT == SPI_MASTER)
	_delay_ms(1) ;
#endif
	SPI_u8_SPDR_REG = SPI_DUMMY_DATA ;
	/* Check if the transmission is completed */
	while ((GET_BIT(SPI_u8_SPSR_REG , SPI_u8_SPSR_SPIF_BIT)) == 0) ;
	/* Read Data */
	return SPI_u8_SPDR_REG ;

}

u8 SPI_u8ReceiveStringSynchBlocking (u8 * Copy_pu8ReceivedString)
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;

	u8 Local_u8MessageSize = 0 ;

	u8 Local_u8Counter = 0 ;

	if(Copy_pu8ReceivedString != NULL)
	{
#if (SPI_MASTER_SLAVE_SELECT == SPI_MASTER)
		_delay_ms(1) ;
#endif
		SPI_u8_SPDR_REG = SPI_DUMMY_DATA ;

		while ((GET_BIT(SPI_u8_SPSR_REG , SPI_u8_SPSR_SPIF_BIT)) == 0) ;

		Local_u8MessageSize = SPI_u8_SPDR_REG ;

		while(Local_u8Counter < Local_u8MessageSize )
		{
#if (SPI_MASTER_SLAVE_SELECT == SPI_MASTER)
			_delay_ms(1) ;
#endif
			SPI_u8_SPDR_REG = SPI_DUMMY_DATA ;
			while ((GET_BIT(SPI_u8_SPSR_REG , SPI_u8_SPSR_SPIF_BIT)) == 0) ;
			Copy_pu8ReceivedString[Local_u8Counter] = SPI_u8_SPDR_REG ;
			Local_u8Counter ++ ;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}
	return Local_u8ErrorState ;
}

u8 SPI_u8ReceiveStringSynchNonBlocking (u8 * Copy_pu8ReceivedString)
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;

	u8 Local_u8MessageSize = 0 ;

	u8 Local_u8Counter = 0 ;

	u16 Local_u16Counter = 0 ;

	if(Copy_pu8ReceivedString != NULL)
	{
#if (SPI_MASTER_SLAVE_SELECT == SPI_MASTER)
		_delay_ms(1) ;
#else
		_delay_ms(2) ;
#endif
		SPI_u8_SPDR_REG = SPI_DUMMY_DATA ;

		while ((Local_u16Counter < 2000) && ((GET_BIT(SPI_u8_SPSR_REG , SPI_u8_SPSR_SPIF_BIT)) == 0))
		{
			Local_u16Counter ++ ;
		}

		if((GET_BIT(SPI_u8_SPSR_REG , SPI_u8_SPSR_SPIF_BIT)) == 1)
		{
			Local_u8MessageSize = SPI_u8_SPDR_REG ;

			while(Local_u8Counter < Local_u8MessageSize )
			{
				_delay_ms(1) ;
				SPI_u8_SPDR_REG = SPI_DUMMY_DATA ;
				while ((Local_u16Counter < 2000) && ((GET_BIT(SPI_u8_SPSR_REG , SPI_u8_SPSR_SPIF_BIT)) == 0))
				{
					Local_u16Counter ++ ;
				}
				if((GET_BIT(SPI_u8_SPSR_REG , SPI_u8_SPSR_SPIF_BIT)) == 1)
				{
					Copy_pu8ReceivedString[Local_u8Counter] = SPI_u8_SPDR_REG ;
					Local_u8Counter ++ ;
				}
				else
				{
					Local_u8ErrorState = STD_TYPES_NOK ;
					break;
				}
			}
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


/* Proto Type Of ISR For Transmission Completed */
void __vector_12 (void)  __attribute__((signal)) ;

void __vector_12 (void)
{
	static u8 Local_u8Counter = 0 ;
	if(SPI_APfCallBack != NULL)
	{
		if(Local_u8Counter == 0)
		{
			/* Read MessageSize */
			SPI_u8MessageSize = SPI_u8_SPDR_REG ;

			if(SPI_u8MessageSize2 > SPI_u8MessageSize)
			{
				SPI_u8MessageSize = SPI_u8MessageSize2 ;
			}

		}
		else
		{
			SPI_pu8ReceivedString[Local_u8Counter-1] = SPI_u8_SPDR_REG ;
#if (SPI_MASTER_SLAVE_SELECT == SPI_MASTER)
		_delay_ms(1) ;
#endif
		}

		if(Local_u8Counter < SPI_u8MessageSize)
		{
			if(SPI_pu8TransmittedString[Local_u8Counter]!='\0')
			{
				SPI_u8_SPDR_REG = SPI_pu8TransmittedString[Local_u8Counter] ;
			}
			else
			{
				SPI_u8_SPDR_REG = SPI_DUMMY_DATA ;
			}

			Local_u8Counter ++ ;
		}
		else
		{
			/* Disable Interrupt */
			CLR_BIT(SPI_u8_SPCR_REG , SPI_u8_SPCR_SPIE_BIT) ;
			Local_u8Counter = 0 ;
			SPI_u8BusyFlag = 0 ;
			SPI_APfCallBack() ;
		}

	}
}
