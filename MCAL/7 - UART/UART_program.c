/********************************************************************************************************************/
/*****************     Author 		: Ahmed Abdelhady 	*************************************************************/
/*****************     File 		: Program Of UART  	*************************************************************/
/*****************     Date 		: 27/9/2023  		*************************************************************/
/*****************     Version 		: 1.0  				*************************************************************/
/*****************     Description 	: Drive For UART 	*************************************************************/
/********************************************************************************************************************/

/* LIB Layer */
#include "util/delay.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL Layer */
#include "UART_interface.h"
#include "UART_config.h"
#include "UART_private.h"


/******************  Global Variables ******************/
static void (* UART_APfCallBack[3])(void) = {NULL};

static u8 UART_u8BusyFlag = 0 ;

static u8 * UART_pu8String = NULL ;

static u8 UART_u8Conter = 0 ;

static u8 UART_u8MessageSize = 0 ;

void UART_voidInit (void)
{
	u8 Local_u8UCSRCValue = UART_SELECT_UCSRC_REG ;

	u16 Local_u16UBRRValue ;
	Local_u16UBRRValue = UART_BAUD_RATE_UBRR;
	UART_u8_UBRRL_REG=(u8)Local_u16UBRRValue;
	UART_u8_UBRRH_REG=(u8)(Local_u16UBRRValue>>8);

#if (UART_MODE_SELECT == UART_ASYNCH_OPERATION)

	CLR_BIT(Local_u8UCSRCValue , UART_u8_UCSRC_UMSEL_BIT) ;

#if (UART_SPEED == UART_NORMAL_SPEED)

	CLR_BIT(UART_u8_UCSRA_REG , UART_u8_UCSRA_U2X_BIT) ;

#elif (UART_SPEED == UART_DOUBLE_SPEED)

	SET_BIT(UART_u8_UCSRA_REG , UART_u8_UCSRA_U2X_BIT) ;

#endif

#elif (UART_MODE_SELECT == UART_SYNCH_OPERATION)

	SET_BIT(Local_u8UCSRCValue , UART_u8_UCSRC_UMSEL_BIT) ;

#if   (UART_SYNCH_CLK_POLARITY == UART_RIS_TX_FALL_RX)

	CLR_BIT(Local_u8UCSRCValue , UART_u8_UCSRC_UCPOL_BIT) ;

#elif (UART_SYNCH_CLK_POLARITY == UART_RIS_TX_FALL_RX)

	SET_BIT(Local_u8UCSRCValue , UART_u8_UCSRC_UCPOL_BIT) ;

#endif

#if (UART_PROCESSOR_COMMUNICATION == UART_SINGLE_CYCLE_PROCESSOR)

	CLR_BIT(UART_u8_UCSRA_REG , UART_u8_UCSRA_MPCM_BIT) ;

#elif (UART_SPEED == UART_DOUBLE_SPEED)

	SET_BIT(UART_u8_UCSRA_REG , UART_u8_UCSRA_MPCM_BIT) ;

#endif
#endif

#if (UART_PARITY_MODE == UART_DISABLE_PARITY)

	CLR_BIT(Local_u8UCSRCValue , UART_u8_UCSRC_UPM0_BIT) ;
	CLR_BIT(Local_u8UCSRCValue , UART_u8_UCSRC_UPM1_BIT) ;

#elif (UART_PARITY_MODE == UART_ENABLE_EVEN_PARITY)

	CLR_BIT(Local_u8UCSRCValue , UART_u8_UCSRC_UPM0_BIT) ;
	SET_BIT(Local_u8UCSRCValue , UART_u8_UCSRC_UPM1_BIT) ;

#elif (UART_PARITY_MODE == UART_ENABLE_ODD_PARITY)

	SET_BIT(Local_u8UCSRCValue , UART_u8_UCSRC_UPM0_BIT) ;
	SET_BIT(Local_u8UCSRCValue , UART_u8_UCSRC_UPM1_BIT) ;

#endif

#if(UART_STOP_BIT_SELECT   == UART_1_BIT_STOP_SELECT)
	CLR_BIT(Local_u8UCSRCValue , UART_u8_UCSRC_USBS_BIT) ;
#elif(UART_STOP_BIT_SELECT == UART_2_BIT_STOP_SELECT)
	SET_BIT(Local_u8UCSRCValue , UART_u8_UCSRC_USBS_BIT) ;
#endif

#if     UART_CHARACTER_SIZE == UART_5_BIT_CHARACTER_SIZE
	CLR_BIT(Local_u8UCSRCValue,UART_u8_UCSRC_UCSZ0_BIT);
	CLR_BIT(Local_u8UCSRCValue,UART_u8_UCSRC_UCSZ1_BIT);
	CLR_BIT(UART_u8_UCSRB_REG,UART_u8_UCSRB_UCSZ2_BIT);
#elif   UART_CHARACTER_SIZE == UART_6_BIT_CHARACTER_SIZE
	SET_BIT(Local_u8UCSRCValue,UART_u8_UCSRC_UCSZ0_BIT);
	CLR_BIT(Local_u8UCSRCValue,UART_u8_UCSRC_UCSZ1_BIT);
	CLR_BIT(UART_u8_UCSRB_REG,UART_u8_UCSRB_UCSZ2_BIT);
#elif   UART_CHARACTER_SIZE == UART_7_BIT_CHARACTER_SIZE
	CLR_BIT(Local_u8UCSRCValue,UART_u8_UCSRC_UCSZ0_BIT);
	SET_BIT(Local_u8UCSRCValue,UART_u8_UCSRC_UCSZ1_BIT);
	CLR_BIT(UART_u8_UCSRB_REG,UART_u8_UCSRB_UCSZ2_BIT);
#elif   UART_CHARACTER_SIZE == UART_8_BIT_CHARACTER_SIZE
	SET_BIT(Local_u8UCSRCValue,UART_u8_UCSRC_UCSZ0_BIT);
	SET_BIT(Local_u8UCSRCValue,UART_u8_UCSRC_UCSZ1_BIT);
	CLR_BIT(UART_u8_UCSRB_REG,UART_u8_UCSRB_UCSZ2_BIT);
#elif   UART_CHARACTER_SIZE == UART_9_BIT_CHARACTER_SIZE
	SET_BIT(Local_u8UCSRCValue,UART_u8_UCSRC_UCSZ0_BIT);
	SET_BIT(Local_u8UCSRCValue,UART_u8_UCSRC_UCSZ1_BIT);
	SET_BIT(UART_u8_UCSRB_REG,UART_u8_UCSRB_UCSZ2_BIT);
#endif

	/* Update UCSRC REG */
	UART_u8_UCSRC_REG = Local_u8UCSRCValue ;

	/* Rx Enable */
	SET_BIT(UART_u8_UCSRB_REG , UART_u8_UCSRB_RXEN_BIT) ;

	/* Tx Enable */
	SET_BIT(UART_u8_UCSRB_REG , UART_u8_UCSRB_TXEN_BIT) ;
}

void UART_voidSendByteSynchBlocking (u8 Copy_u8DataByte)
{

	/* Wait until the TX Register is empty */
	while((GET_BIT(UART_u8_UCSRA_REG , UART_u8_UCSRA_UDRE_BIT) == 0)) ;

	/* Send Data Byte */
	UART_u8_UDR_REG = Copy_u8DataByte ;
}

u8 UART_u8SendByteSynchNonBlocking (u8 Copy_u8DataByte)
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;
	u16 Local_u16Counter = 0 ;
	/* Wait until the TX Register is empty */
	while((Local_u16Counter < 1500) && ((GET_BIT(UART_u8_UCSRA_REG , UART_u8_UCSRA_UDRE_BIT)) == 0))
	{
		Local_u16Counter ++ ;
	}

	if((GET_BIT(UART_u8_UCSRA_REG , UART_u8_UCSRA_UDRE_BIT)) == 1)
	{
		/* Send Data Byte */
		UART_u8_UDR_REG = Copy_u8DataByte ;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}

	return Local_u8ErrorState ;
}

u8 UART_u8SendByteAsynch (void (* Copy_pf) (void))
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;

	if((Copy_pf != NULL) && (UART_u8BusyFlag == 0))
	{
		UART_u8BusyFlag = 1 ;
		UART_APfCallBack[UART_DATA_REG_EMPTY_INTER] = Copy_pf ;
		SET_BIT(UART_u8_UCSRB_REG , UART_u8_UCSRB_UDRIE_BIT) ;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}
	return Local_u8ErrorState ;
}

u8 UART_u8SendStringSynchBlocking(u8 * Copy_pu8String)

{
	u8 Local_u8ErrorState = STD_TYPES_OK ;
	u8 Local_u8Conter  = 0 ;

	if(Copy_pu8String != NULL)
	{

		while (Copy_pu8String[Local_u8Conter] != '\0')
		{
			UART_voidSendByteSynchBlocking (Copy_pu8String[Local_u8Conter]) ;
			_delay_ms(2) ;

			Local_u8Conter ++ ;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}

	return Local_u8ErrorState ;
}

u8 UART_u8SendStringSynchNonBlocking(u8 * Copy_pu8String)

{
	u8 Local_u8ErrorState = STD_TYPES_OK ;
	u8 Local_u8Conter  = 0 ;

	if(Copy_pu8String != NULL)
	{

		while (Copy_pu8String[Local_u8Conter] != '\0')
		{
			UART_u8SendByteSynchNonBlocking(Copy_pu8String[Local_u8Conter]) ;
			_delay_ms(2) ;

			Local_u8Conter ++ ;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}

	return Local_u8ErrorState ;
}

u8 UART_u8SendStringAsynch(u8 * Copy_pu8String , void (* Copy_pf) (void))
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;


	if((Copy_pu8String != NULL) && (Copy_pf != NULL) && (UART_u8BusyFlag == 0))
	{
		UART_u8Conter = 0 ;

		UART_u8BusyFlag = 1 ;

		UART_APfCallBack[UART_TX_COM_INTER] = Copy_pf ;

		UART_pu8String = Copy_pu8String ;

		UART_u8_UDR_REG = Copy_pu8String[0] ;

		SET_BIT(UART_u8_UCSRB_REG , UART_u8_UCSRB_TXCIE_BIT) ;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}

	return Local_u8ErrorState ;
}

u8 UART_u8ReceiveByteSynchBlocking (u8 * Copy_pu8ReceivedByte)
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;

	if(Copy_pu8ReceivedByte != NULL)
	{
		/* Wait until the data is received */
		while((GET_BIT(UART_u8_UCSRA_REG , UART_u8_UCSRA_RXC_BIT) == 0)) ;

		/* Read Data */
		*Copy_pu8ReceivedByte = UART_u8_UDR_REG ;

	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}

	return Local_u8ErrorState ;
}

u8 UART_u8ReceiveByteSynchNonBlocking (u8 * Copy_pu8ReceivedByte)
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;

	u16 Local_u16Counter = 0 ;

	if(Copy_pu8ReceivedByte != NULL)
	{
		/* Wait until the data is received */
		while((Local_u16Counter < 2000) && ((GET_BIT(UART_u8_UCSRA_REG , UART_u8_UCSRA_RXC_BIT)) == 0))
		{
			Local_u16Counter ++ ;
		}

		if((GET_BIT(UART_u8_UCSRA_REG , UART_u8_UCSRA_RXC_BIT)) == 1)
		{
			/* Read Data */
			*Copy_pu8ReceivedByte = UART_u8_UDR_REG ;
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

u8 UART_u8ReceiveByteAsynch (void (* Copy_pf) (void))

{
	u8 Local_u8ErrorState = STD_TYPES_OK ;

	if((Copy_pf != NULL) && (UART_u8BusyFlag == 0))
	{
		UART_u8BusyFlag = 1 ;
		UART_APfCallBack[UART_RX_COM_INTER] = Copy_pf ;
		SET_BIT(UART_u8_UCSRB_REG , UART_u8_UCSRB_RXCIE_BIT) ;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}

	return Local_u8ErrorState ;
}

u8 UART_u8ReceiveStringSynchNonBlocking(u8 * Copy_pu8RecString , u8 Copy_u8MessageSize)

{
	u8 Local_u8ErrorState = STD_TYPES_OK ;

	u8 Local_u8Conter = 0 ;

   u16 Local_u16Counter = 0 ;

	if(Copy_pu8RecString != NULL)
	{
		while(Local_u8Conter < Copy_u8MessageSize)
		{
			/* Wait until the data is received */
			while((Local_u16Counter < 2000) && ((GET_BIT(UART_u8_UCSRA_REG , UART_u8_UCSRA_RXC_BIT)) == 0))
			{
				Local_u16Counter ++ ;
			}
			_delay_ms(2) ;
			Copy_pu8RecString[Local_u8Conter] = UART_u8_UDR_REG ;
			Local_u8Conter ++ ;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}

	return Local_u8ErrorState ;
}

u8 UART_u8ReceiveStringAsynch(u8 * Copy_pu8RecString , void (* Copy_pf) (void) , u8 Copy_u8MessageSize)
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;

	if((Copy_pu8RecString != NULL) && (Copy_pf != NULL) && (UART_u8BusyFlag == 0))
	{
		UART_u8BusyFlag = 1 ;

		UART_APfCallBack[UART_RX_COM_INTER] = Copy_pf ;

		UART_pu8String = Copy_pu8RecString ;

		UART_u8MessageSize = Copy_u8MessageSize-1 ;

		if((GET_BIT(UART_u8_UCSRA_REG , UART_u8_UCSRA_RXC_BIT) == 1))
		{
			UART_pu8String[0] = UART_u8_UDR_REG ;

			UART_u8Conter ++ ;
		}

		SET_BIT(UART_u8_UCSRB_REG , UART_u8_UCSRB_RXCIE_BIT) ;

	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}

	return Local_u8ErrorState ;
}

void UART_voidDisable (void)
{
	/* Rx Disable */
	CLR_BIT(UART_u8_UCSRB_REG , UART_u8_UCSRB_RXEN_BIT) ;

	/* Tx Disable */
	CLR_BIT(UART_u8_UCSRB_REG , UART_u8_UCSRB_TXEN_BIT) ;
}

u8 UART_u8SetCallBack (u8 Copy_u8InterType , void (* Copy_pf) (void))
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;

	if(Copy_pf != NULL)
	{
		UART_APfCallBack[Copy_u8InterType] = Copy_pf ;
		switch(Copy_u8InterType)
		{
		case UART_RX_COM_INTER :

			SET_BIT(UART_u8_UCSRB_REG , UART_u8_UCSRB_RXCIE_BIT) ;

			break ;

		case UART_DATA_REG_EMPTY_INTER :

			SET_BIT(UART_u8_UCSRB_REG , UART_u8_UCSRB_UDRIE_BIT) ;

			break ;

		case UART_TX_COM_INTER :

			SET_BIT(UART_u8_UCSRB_REG , UART_u8_UCSRB_TXCIE_BIT) ;

			break ;

		default :
			Local_u8ErrorState = STD_TYPES_NOK ;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}


	return Local_u8ErrorState ;
}


void UART_voidDisableInter(u8 Copy_u8InterType)
{
	switch(Copy_u8InterType)
	{
	case UART_RX_COM_INTER :

		CLR_BIT(UART_u8_UCSRB_REG , UART_u8_UCSRB_RXCIE_BIT) ;

		break ;

	case UART_DATA_REG_EMPTY_INTER :

		CLR_BIT(UART_u8_UCSRB_REG , UART_u8_UCSRB_UDRIE_BIT) ;

		break ;

	case UART_TX_COM_INTER :

		CLR_BIT(UART_u8_UCSRB_REG , UART_u8_UCSRB_TXCIE_BIT) ;

		break ;
	}
}

u8 UART_u8GetUDR_Reg (void)
{
	return UART_u8_UDR_REG ;
}

void UART_voidWriteOnUDR_Reg (u8 Copy_u8Data)
{
	UART_u8_UDR_REG = Copy_u8Data ;
}


/* Proto Type Of ISR For Rx Complete */
void __vector_13 (void)  __attribute__((signal)) ;
void __vector_13 (void)
{
	if(UART_APfCallBack[UART_RX_COM_INTER] != NULL)
	{
		if(UART_u8Conter < UART_u8MessageSize)
		{
			UART_pu8String[UART_u8Conter] = UART_u8_UDR_REG ;
			UART_u8Conter ++ ;
		}
		else
		{
			if(UART_pu8String != NULL)
			{
				UART_pu8String[UART_u8Conter] = UART_u8_UDR_REG ;
			}

			UART_u8Conter = 0 ;
			UART_u8BusyFlag = 0  ;
			UART_APfCallBack[UART_RX_COM_INTER]() ;
			CLR_BIT(UART_u8_UCSRB_REG , UART_u8_UCSRB_RXCIE_BIT) ;
			UART_pu8String = NULL ;
		}
	}
}

/* Proto Type Of ISR For Data TX Register Empty */
void __vector_14 (void)  __attribute__((signal)) ;
void __vector_14 (void)
{
	if(UART_APfCallBack[UART_DATA_REG_EMPTY_INTER] != NULL)
	{
		UART_APfCallBack[UART_DATA_REG_EMPTY_INTER]() ;
		UART_voidDisableInter(UART_DATA_REG_EMPTY_INTER) ;
		UART_u8BusyFlag = 0 ;
	}
}

/* Proto Type Of ISR For Tx Complete */
void __vector_15 (void)  __attribute__((signal)) ;
void __vector_15 (void)
{
	static u8 Local_u8Counter = 1 ;

	if(UART_APfCallBack[UART_TX_COM_INTER] != NULL)
	{
		if(UART_pu8String[Local_u8Counter] != '\0')
		{
			UART_u8_UDR_REG = UART_pu8String[Local_u8Counter] ;
			Local_u8Counter ++ ;
		}
		else
		{
			UART_u8BusyFlag = 0 ;

			Local_u8Counter = 1 ;

			UART_pu8String = NULL ;

			UART_APfCallBack[UART_TX_COM_INTER]() ;

			CLR_BIT(UART_u8_UCSRB_REG , UART_u8_UCSRB_TXCIE_BIT) ;
		}
	}
}

