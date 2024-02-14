/********************************************************************************************************************/
/*****************     Author 		: Ahmed Abdelhady 	*************************************************************/
/*****************     File 		: Program Of TWI  	*************************************************************/
/*****************     Date 		: 1/1/2023  		*************************************************************/
/*****************     Version 		: 1.0  				*************************************************************/
/*****************     Description 	: Drive For TWI 	*************************************************************/
/********************************************************************************************************************/

/* LIB Layer */
#include "util/delay.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL Layer */
#include "TWI_private.h"
#include "TWI_config.h"
#include "TWI_interface.h"


TWI_ErrorState TWI_enuMasterInit (u8 Copy_u8SlaveAdress)
{
	TWI_ErrorState Local_enuErrorState = TWI_OK ;

	if (Copy_u8SlaveAdress != NO_ADDRESS)
	{
		TWI_u8_TWAR_REG = (Copy_u8SlaveAdress << 1);
	}

	/* Set Prescaler Value */
#if (TWI_u8_PRESCALER_VALUE == 1)
	CLR_BIT(TWI_u8_TWSR_REG , TWI_u8_TWPS0_BIT) ;
	CLR_BIT(TWI_u8_TWSR_REG , TWI_u8_TWPS1_BIT) ;
#elif (TWI_u8_PRESCALER_VALUE == 4)
	SET_BIT(TWI_u8_TWSR_REG , TWI_u8_TWPS0_BIT) ;
	CLR_BIT(TWI_u8_TWSR_REG , TWI_u8_TWPS1_BIT) ;
#elif (TWI_u8_PRESCALER_VALUE == 16)
	CLR_BIT(TWI_u8_TWSR_REG , TWI_u8_TWPS0_BIT) ;
	SET_BIT(TWI_u8_TWSR_REG , TWI_u8_TWPS1_BIT) ;
#elif (TWI_u8_PRESCALER_VALUE == 64)
	SET_BIT(TWI_u8_TWSR_REG , TWI_u8_TWPS0_BIT) ;
	SET_BIT(TWI_u8_TWSR_REG , TWI_u8_TWPS1_BIT) ;
#else
	Local_enuErrorState = TWI_Prescaler_Error ;
#endif	

	/* Set TWBR Value  */
	TWI_u8_TWBR_REG = (((( TWI_u32_F_CPU_FREQ / TWI_u8_Frequency ) - 16 ) / TWI_u8_PRESCALER_VALUE ) / 2 )  ;

	return Local_enuErrorState ;
}

TWI_ErrorState TWI_enuSlaveInit (u8 Copy_u8SlaveAdress)
{
	TWI_ErrorState  Local_enuErrorState = TWI_OK ;

	if(( Copy_u8SlaveAdress >= 1 ) && ( Copy_u8SlaveAdress < 120 ))
	{

		/* Set Slave Address in TWAR */
		TWI_u8_TWAR_REG &= TWI_u8_SLAVE_ADRESS_MASKING ;

		TWI_u8_TWAR_REG |= (Copy_u8SlaveAdress << 1)	;

#if(TWI_u8_GENERAL_CALL == TWI_ENABLE_GC)
		SET_BIT(TWI_u8_TWAR_REG , TWI_u8_TWGCE_BIT) ;
#else
		CLR_BIT(TWI_u8_TWAR_REG , TWI_u8_TWGCE_BIT) ;
#endif

	}
	else
	{
		Local_enuErrorState = TWI_SLA_Error ;
	}

	return Local_enuErrorState ;
}

TWI_ErrorState TWI_enuSendStartCondition (void)
{
	TWI_ErrorState  Local_enuErrorState = TWI_OK ;

	u32 Local_u32TimeOutCounter = 0 ;

	/* Start Conation then Clear Flag by set then Enable TWI */
	TWI_u8_TWCR_REG = (1<<TWI_u8_TWINT_BIT)|(1<<TWI_u8_TWSTA_BIT)|(1<<TWI_u8_TWEN_BIT);

	/* Wati Till Flag = 1 */
	while ((! GET_BIT(TWI_u8_TWCR_REG , TWI_u8_TWINT_BIT) ) && Local_u32TimeOutCounter < TWI_u32_TIME_OUT_MAX_VALUE)
	{
		Local_u32TimeOutCounter ++ ;
	}

	/* Check Flag Set*/
	if(GET_BIT(TWI_u8_TWCR_REG , TWI_u8_TWINT_BIT))
	{
		/* Check The Status Code For Start Condation*/
		if(( TWI_u8_TWSR_REG & TWI_u8_STATUS_CODE_CHECK ) != TWI_u8_START_ACK)
		{
			Local_enuErrorState = TWI_SC_Error ;
		}
	}
	else
	{
		Local_enuErrorState = TWI_SC_Error ;
	}

	return Local_enuErrorState ;
}

TWI_ErrorState TWI_enuSendRepeatedCondition (void)
{
	TWI_ErrorState  Local_enuErrorState = TWI_OK ;

	u32 Local_u32TimeOutCounter = 0 ;

	/* Start Conation then Clear Flag by set then Enable TWI */
	TWI_u8_TWCR_REG = (1<<TWI_u8_TWINT_BIT)|(1<<TWI_u8_TWSTA_BIT)|(1<<TWI_u8_TWEN_BIT);

	/* Wati Till Flag = 1 */
	while ((! GET_BIT(TWI_u8_TWCR_REG , TWI_u8_TWINT_BIT) ) &&  Local_u32TimeOutCounter < TWI_u32_TIME_OUT_MAX_VALUE)
	{
		Local_u32TimeOutCounter ++ ;
	}

	/* Check Flag Set*/
	if(GET_BIT(TWI_u8_TWCR_REG , TWI_u8_TWINT_BIT))
	{
		/* Check The Status Code For Repeated Start Condation*/
		if(( TWI_u8_TWSR_REG & TWI_u8_STATUS_CODE_CHECK ) != TWI_u8_RESTART_ACK)
		{
			Local_enuErrorState = TWI_RSC_Error ;
		}

	}
	else
	{
		Local_enuErrorState = TWI_RSC_Error ;
	}

	return Local_enuErrorState ;		 
}

void TWI_voidSendStopCondition (void)
{
	/* Clear Flag by set then Enable TWI then stop condation */
	TWI_u8_TWCR_REG = (1<<TWI_u8_TWINT_BIT)|(1<<TWI_u8_TWEN_BIT)|(1<<TWI_u8_TWSTO_BIT);
}

TWI_ErrorState TWI_enuSendSlaveAddWithWrite (u8 Copy_u8SlaveAdress )
{
	TWI_ErrorState  Local_enuErrorState = TWI_OK ;

	u32 Local_u32TimeOutCounter = 0 ;

	/* Write Slave Adress + 0 in R/W Bit in TWDR */
	u8 Local_u8Address = (Copy_u8SlaveAdress << 1) ;
	CLR_BIT(Local_u8Address , 0) ;

	TWI_u8_TWDR_REG = Local_u8Address ;

	/* Clear Flag and enable TWI and ACK*/
	TWI_u8_TWCR_REG = (1<<TWI_u8_TWINT_BIT) | (1<<TWI_u8_TWEN_BIT) | (1<<TWI_u8_TWEA_BIT);

	/* Wati Till Flag = 1 */
	while ((! GET_BIT(TWI_u8_TWCR_REG , TWI_u8_TWINT_BIT) ) && Local_u32TimeOutCounter < TWI_u32_TIME_OUT_MAX_VALUE)
	{
		Local_u32TimeOutCounter ++ ;
	}

	/* Check Flag Set*/
	if(GET_BIT(TWI_u8_TWCR_REG , TWI_u8_TWINT_BIT))
	{
		/* Check The Status Code (ACK) For Slave And Write*/
		if(( TWI_u8_TWSR_REG & TWI_u8_STATUS_CODE_CHECK ) != TWI_u8_SLA_W_ACK)
		{
			Local_enuErrorState = TWI_SLA_W_Error ;
		}

	}
	else
	{
		Local_enuErrorState = TWI_SLA_W_Error ;
	}

	return Local_enuErrorState ;				 
}

TWI_ErrorState TWI_enuSendSlaveAddWithRead (u8 Copy_u8SlaveAdress )
{
	TWI_ErrorState  Local_enuErrorState = TWI_OK ;

	u32 Local_u32TimeOutCounter = 0 ;

	/* Write Slave Adress and Set R/W Bit in TWDR*/
	u8 Local_u8Address = (Copy_u8SlaveAdress << 1) ;
	SET_BIT(Local_u8Address , 0) ;

	TWI_u8_TWDR_REG = Local_u8Address ;


	/* Clear Flag and enable TWI and ACK*/
	TWI_u8_TWCR_REG = (1<<TWI_u8_TWINT_BIT) | (1<<TWI_u8_TWEN_BIT) | (1<<TWI_u8_TWEA_BIT);

	/* Wati Till Flag = 1 */
	while ((! GET_BIT(TWI_u8_TWCR_REG , TWI_u8_TWINT_BIT) ) && Local_u32TimeOutCounter < TWI_u32_TIME_OUT_MAX_VALUE)
	{
		Local_u32TimeOutCounter ++ ;
	}

	/* Check Flag Set*/
	if(GET_BIT(TWI_u8_TWCR_REG , TWI_u8_TWINT_BIT))
	{
		/* Check The Status Code (ACK) For Slave And Read*/
		if(( TWI_u8_TWSR_REG & TWI_u8_STATUS_CODE_CHECK ) != TWI_u8_SLA_R_ACK)
		{
			Local_enuErrorState = TWI_SLA_R_Error ;
		}

	}
	else
	{
		Local_enuErrorState = TWI_SLA_R_Error ;
	}

	return Local_enuErrorState ;
}

TWI_ErrorState TWI_MasterSendDataWithACK (u8 Copy_u8DataByte )
{
	TWI_ErrorState  Local_enuErrorState = TWI_OK ;

	u32 Local_u32TimeOutCounter = 0 ;

	/* Write Data in TWDR */
	TWI_u8_TWDR_REG = Copy_u8DataByte ;

	/* Clear Flag and enable TWI and ACK*/
	TWI_u8_TWCR_REG = (1<<TWI_u8_TWINT_BIT) | (1<<TWI_u8_TWEN_BIT) | (1<<TWI_u8_TWEA_BIT);

	/* Wati Till Flag = 1 */
	while ((! GET_BIT(TWI_u8_TWCR_REG , TWI_u8_TWINT_BIT) ) && Local_u32TimeOutCounter < TWI_u32_TIME_OUT_MAX_VALUE)
	{
		Local_u32TimeOutCounter ++ ;
	}

	/* Check Flag Set*/
	if(GET_BIT(TWI_u8_TWCR_REG , TWI_u8_TWINT_BIT))
	{
		/* Check The Status Code (ACK) For Data Transmit */
		if(( TWI_u8_TWSR_REG & TWI_u8_STATUS_CODE_CHECK ) != TWI_u8_DATA_W_ACK)
		{
			Local_enuErrorState = TWI_MT_ACK_Data_Error  ;
		}

	}
	else
	{
		Local_enuErrorState = TWI_MT_ACK_Data_Error ;
	}

	return Local_enuErrorState ;
}

TWI_ErrorState TWI_MasterSendDataWithNACK (u8 Copy_u8DataByte )
{
	TWI_ErrorState  Local_enuErrorState = TWI_OK ;

	u32 Local_u32TimeOutCounter = 0 ;

	/* Write Data in TWDR */
	TWI_u8_TWDR_REG = Copy_u8DataByte ;

	/* Clear Flag and enable TWI*/
	TWI_u8_TWCR_REG = (1<<TWI_u8_TWINT_BIT) | (1<<TWI_u8_TWEN_BIT);

	/* Wati Till Flag = 1 */
	while ((! GET_BIT(TWI_u8_TWCR_REG , TWI_u8_TWINT_BIT) ) && Local_u32TimeOutCounter < TWI_u32_TIME_OUT_MAX_VALUE)
	{
		Local_u32TimeOutCounter ++ ;
	}

	/* Check Flag Set*/
	if(GET_BIT(TWI_u8_TWCR_REG , TWI_u8_TWINT_BIT))
	{
		/* Check The Status Code (NACK) For Data Transmit */
		if(( TWI_u8_TWSR_REG & TWI_u8_STATUS_CODE_CHECK ) != TWI_u8_DATA_W_NACK)
		{
			Local_enuErrorState = TWI_MT_NACK_Data_Error  ;
		}

	}
	else
	{
		Local_enuErrorState = TWI_MT_NACK_Data_Error ;
	}

	return Local_enuErrorState ;
}

TWI_ErrorState TWI_enuMasterReceiveDataWithACK (u8 * Copy_Pu8ReturnedDataByte )
{
	TWI_ErrorState  Local_enuErrorState = TWI_OK ;

	u32 Local_u32TimeOutCounter = 0 ;


	if(Copy_Pu8ReturnedDataByte != NULL)
	{

		/* Clear Flag and enable TWI*/
		TWI_u8_TWCR_REG = (1<<TWI_u8_TWINT_BIT) | (1<<TWI_u8_TWEN_BIT) | (1<<TWI_u8_TWEA_BIT);

		/* Wati Till Flag = 1 */
		while ((! GET_BIT(TWI_u8_TWCR_REG , TWI_u8_TWINT_BIT) ) && Local_u32TimeOutCounter < TWI_u32_TIME_OUT_MAX_VALUE)
		{
			Local_u32TimeOutCounter ++ ;
		}

		/* Check Flag Set*/
		if(GET_BIT(TWI_u8_TWCR_REG , TWI_u8_TWINT_BIT))
		{
			/* Check The Status Code (NACK) For Master Recieve Data */
			if(( TWI_u8_TWSR_REG & TWI_u8_STATUS_CODE_CHECK ) != TWI_u8_DATA_R_ACK)
			{
				Local_enuErrorState = TWI_MR_ACK_Data_Error   ;
			}
			else
			{
				* Copy_Pu8ReturnedDataByte = TWI_u8_TWDR_REG ;
			}

		}
		else
		{
			Local_enuErrorState = TWI_MR_ACK_Data_Error  ;
		}
	}
	else
	{
		Local_enuErrorState = TWI_NULL_Pointer_Error  ;
	}

	return Local_enuErrorState ;
}


TWI_ErrorState TWI_enuMasterReceiveDataWithNACK (u8 * Copy_Pu8ReturnedDataByte )
{
	TWI_ErrorState  Local_enuErrorState = TWI_OK ;

	u32 Local_u32TimeOutCounter = 0 ;


	if(Copy_Pu8ReturnedDataByte != NULL)
	{

		/* Clear Flag and enable TWI*/
		TWI_u8_TWCR_REG = (1<<TWI_u8_TWINT_BIT) | (1<<TWI_u8_TWEN_BIT);

		/* Wati Till Flag = 1 */
		while ((! GET_BIT(TWI_u8_TWCR_REG , TWI_u8_TWINT_BIT) ) && Local_u32TimeOutCounter < TWI_u32_TIME_OUT_MAX_VALUE)
		{
			Local_u32TimeOutCounter ++ ;
		}

		/* Check Flag Set*/
		if(GET_BIT(TWI_u8_TWCR_REG , TWI_u8_TWINT_BIT))
		{
			/* Check The Status Code (NACK) For Master Recieve Data */
			if(( TWI_u8_TWSR_REG & TWI_u8_STATUS_CODE_CHECK ) != TWI_u8_DATA_R_NACK)
			{
				Local_enuErrorState = TWI_MR_NACK_Data_Error   ;
			}
			else
			{
				* Copy_Pu8ReturnedDataByte = TWI_u8_TWDR_REG ;
			}

		}
		else
		{
			Local_enuErrorState = TWI_MR_NACK_Data_Error  ;
		}
	}
	else
	{
		Local_enuErrorState = TWI_NULL_Pointer_Error  ;
	}

	return Local_enuErrorState ;
}

void TWI_voidStop (void)
{
	TWI_u8_TWCR_REG = (0 << TWI_u8_TWEN_BIT) ;
}
