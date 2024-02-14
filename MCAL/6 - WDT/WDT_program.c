/****************************************************************************************************************************/
/***************** Author : Ahmed Abdelhady **********************************************************************************/
/***************** File : Program of WDT **********************************************************************************/
/***************** Date : 24/9/2023  ***************************************************************************************/
/***************** Version : 1.0  *******************************************************************************************/
/***************** Description : Drive For WDT ****************************************************************************/
/****************************************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "WDT_private.h"
#include "WDT_config.h"
#include "WDT_interface.h"

u8 WDT_u8Enable (u8 Copy_u8TimeValues)
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;

	if(Copy_u8TimeValues <= WDT_TIMEOUT_2_1_S)
	{
		/* Enable WDT */
		SET_BIT(WDT_u8_WDTCR_REG , WDT_u8_WDTCR_WDE_BIT) ;

		/* Choose TimeOut Value */
		WDT_u8_WDTCR_REG &= WDT_u8_WDTCR_PRE_MASK ;
		WDT_u8_WDTCR_REG |= Copy_u8TimeValues ;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}

	return Local_u8ErrorState ;

}

void WDT_voidDisable (void)
{
	WDT_u8_WDTCR_REG |= ((1 << WDT_u8_WDTCR_WDTOE_BIT) | (1 << WDT_u8_WDTCR_WDE_BIT)) ;

	WDT_u8_WDTCR_REG = 0x00 ;
}
