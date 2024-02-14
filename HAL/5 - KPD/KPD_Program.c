/*************************************************************************/
/***************      Name 		:  Ahmed Abdelhady  	******************/
/***************      Date 		:  25 / 12 / 2022  		******************/
/***************      SWC 		:  KPD          		******************/
/***************      Version 	:  1.0          		******************/
/*************************************************************************/

/* LIB Layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 8000000UL
#include <util/delay.h>

/* MCAL Layer */
#include "DIO_Interface.h"

/* HAL Layer */
#include "KPD_Interface.h"
#include "KPD_Private.h"
#include "KPD_Config.h"

static const  u8 KPD_Au8Keys[4][4] = KPD_KEYS ;
    										 
static const  u8 KPD_Au8RowsPins[4] = {KPD_u8_R1_PIN , KPD_u8_R2_PIN , KPD_u8_R3_PIN , KPD_u8_R4_PIN} ;
static const  u8 KPD_Au8ColsPins[4] = {KPD_u8_C1_PIN , KPD_u8_C2_PIN , KPD_u8_C3_PIN , KPD_u8_C4_PIN} ;
										 
void KPD_voidInit (void) 
{
	DIO_u8SetPinDirection(KPD_u8_PORT , KPD_u8_R1_PIN , DIO_u8_OUTPUT) ;
	DIO_u8SetPinDirection(KPD_u8_PORT , KPD_u8_R2_PIN , DIO_u8_OUTPUT) ;
	DIO_u8SetPinDirection(KPD_u8_PORT , KPD_u8_R3_PIN , DIO_u8_OUTPUT) ;
	DIO_u8SetPinDirection(KPD_u8_PORT , KPD_u8_R4_PIN , DIO_u8_OUTPUT) ;

	DIO_u8SetPinValue(KPD_u8_PORT , KPD_u8_R1_PIN , DIO_u8_HIGH) ;
	DIO_u8SetPinValue(KPD_u8_PORT , KPD_u8_R2_PIN , DIO_u8_HIGH) ;
	DIO_u8SetPinValue(KPD_u8_PORT , KPD_u8_R3_PIN , DIO_u8_HIGH) ;
	DIO_u8SetPinValue(KPD_u8_PORT , KPD_u8_R4_PIN , DIO_u8_HIGH) ;

	DIO_u8SetPinDirection(KPD_u8_PORT , KPD_u8_C1_PIN , DIO_u8_INPUT) ;
	DIO_u8SetPinDirection(KPD_u8_PORT , KPD_u8_C2_PIN , DIO_u8_INPUT) ;
	DIO_u8SetPinDirection(KPD_u8_PORT , KPD_u8_C3_PIN , DIO_u8_INPUT) ;
	DIO_u8SetPinDirection(KPD_u8_PORT , KPD_u8_C4_PIN , DIO_u8_INPUT) ;

	DIO_u8SetPinValue(KPD_u8_PORT , KPD_u8_C1_PIN , DIO_u8_HIGH) ;
	DIO_u8SetPinValue(KPD_u8_PORT , KPD_u8_C2_PIN , DIO_u8_HIGH) ;
	DIO_u8SetPinValue(KPD_u8_PORT , KPD_u8_C3_PIN , DIO_u8_HIGH) ;
	DIO_u8SetPinValue(KPD_u8_PORT , KPD_u8_C4_PIN , DIO_u8_HIGH) ;
}

u8 KPD_u8GetKeyState (u8 * Copy_Pu8ReturnedKey)
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;
	u8 Local_u8RowsCounter = 0 , Local_u8ColsCounter = 0 , Local_u8PinValue = 0 , Local_u8Flag = KPD_u8_NOK;
	
	if(Copy_Pu8ReturnedKey != NULL)
	{
		* Copy_Pu8ReturnedKey = KPD_u8_KEY_NOT_PRESSED;
	for(Local_u8RowsCounter = 0 ; Local_u8RowsCounter  <= 3 ; Local_u8RowsCounter ++)
	{
		
		/* Activat Each Row -->For Loop on the pins of the rows */
		DIO_u8SetPinValue (KPD_u8_PORT , KPD_Au8RowsPins[Local_u8RowsCounter] , DIO_u8_LOW) ;
		
		for(Local_u8ColsCounter = 0 ; Local_u8ColsCounter <= 3 ; Local_u8ColsCounter ++)
		{
			DIO_u8GetPinValue (KPD_u8_PORT , KPD_Au8ColsPins[Local_u8ColsCounter ] , &Local_u8PinValue) ;
			//Local_u8PinValue = GET_BIT (DIO_u8_PORTA , KPD_Au8ColsPins[Local_u8ColsCounter ]) ;
			
			if(Local_u8PinValue == DIO_u8_LOW )/* Switch is pressed */
			{
				/* De bouncing */
				_delay_ms(KPD_u8_DELAY_TIME);
				
				DIO_u8GetPinValue (KPD_u8_PORT , KPD_Au8ColsPins[Local_u8ColsCounter ] , &Local_u8PinValue) ;
				
				if(Local_u8PinValue == DIO_u8_LOW)
				{
				
					/* Check if the pin still equal LOW */
					while(Local_u8PinValue == DIO_u8_LOW)
					{
						DIO_u8GetPinValue (KPD_u8_PORT , KPD_Au8ColsPins[Local_u8ColsCounter ] , &Local_u8PinValue) ;
					}
					
					* Copy_Pu8ReturnedKey = KPD_Au8Keys[Local_u8RowsCounter][Local_u8ColsCounter];
					
						Local_u8Flag = KPD_u8_OK ;
						
						break;
				}
			}
		}
		
		/* De Active each Row */
		DIO_u8SetPinValue (KPD_u8_PORT , KPD_Au8RowsPins[Local_u8RowsCounter] , DIO_u8_HIGH) ;
		
		if(Local_u8Flag == KPD_u8_OK)/* found the key so break the all loop */
		{
			break;
		}
		
	}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}
	
	return Local_u8ErrorState ;
}
	
	
	
	
	
	
	
	
	
