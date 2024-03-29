/****************************************************************************************************************************/
/***************** Author : Ahmed Abdelhady **********************************************************************************/
/***************** File : Private of WDT **********************************************************************************/
/***************** Date : 24/9/2023  ***************************************************************************************/
/***************** Version : 1.0  *******************************************************************************************/
/***************** Description : Drive For WDT ****************************************************************************/
/****************************************************************************************************************************/
#ifndef   WDT_PRIVATE_H
#define   WDT_PRIVATE_H

#define WDT_u8_WDTCR_REG	*((volatile u8 *)0x41)

#define WDT_u8_WDTCR_WDTOE_BIT	4
#define WDT_u8_WDTCR_WDE_BIT	3
#define WDT_u8_WDTCR_WDP2_BIT	2
#define WDT_u8_WDTCR_WDP1_BIT	1
#define WDT_u8_WDTCR_WDP0_BIT	0

#define WDT_u8_WDTCR_PRE_MASK	0b00011000 ;

#endif
