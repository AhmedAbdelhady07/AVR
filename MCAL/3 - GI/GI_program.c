/********************************************************************************************************************/
/*****************     Author 		: Ahmed Abdelhady 	*************************************************************/
/*****************     File 		: Program Of GI  	*************************************************************/
/*****************     Date 		: 1/1/2023  		*************************************************************/
/*****************     Version 		: 1.0  				*************************************************************/
/*****************     Description 	: Drive For GI 	*************************************************************/
/********************************************************************************************************************/

/* LIB Layer */
#include "util/delay.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL Layer */
#include "GI_private.h"
#include "GI_config.h"
#include "GI_interface.h"


void GI_voidEnable ( void )
{
	SET_BIT(GI_u8_SREG_REG , GI_u8_I_BIT)	;
}

void GI_voidDisable ( void )
{
	CLR_BIT(GI_u8_SREG_REG , GI_u8_I_BIT)	;
}

