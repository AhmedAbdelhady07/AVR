/*************************************************************************/
/***************      Name 		:  Ahmed Abdelhady  	******************/
/***************      Date 		:  25 / 12 / 2022  		******************/
/***************      SWC 		:  KPD          		******************/
/***************      Version 	:  1.0          		******************/
/*************************************************************************/

#ifndef KPD_INTERFACE_H
#define KPD_INTERFACE_H

#define KPD_u8_OK             	1
#define KPD_u8_NOK				0

#define KPD_u8_KEY_NOT_PRESSED  0xff

void KPD_voidInit (void) ;
u8 KPD_u8GetKeyState (u8 * Copy_Pu8ReturnedKey);

#endif


