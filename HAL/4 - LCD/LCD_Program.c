/*************************************************************************/
/***************      Name 		:  Ahmed Abdelhady  	******************/
/***************      Date 		:  20 / 12 / 2022  		******************/
/***************      SWC 		:  LCD          		******************/
/***************      Version 	:  1.0          		******************/
/*************************************************************************/

/* LIB Layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 8000000UL
#include <util/delay.h>

/* MCAL Layer */
#include "DIO_Interface.h"

/* HAL Layer (LCD) */
#include "LCD_Interface.h"
#include "LCD_Config.h"
#include "LCD_Private.h"

void LCD_voidInit (void)
{
	/* Set direction for control pins */
	DIO_u8SetPinDirection(LCD_u8_RS_PORT ,LCD_u8_RS_PIN,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(LCD_u8_RW_PORT ,LCD_u8_RW_PIN,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(LCD_u8_E_PORT  ,LCD_u8_E_PIN,DIO_u8_OUTPUT);
	
/* Set direction for data pins */
	DIO_u8SetPinDirection(LCD_u8_DATA_PORT_PIN7 ,LCD_u8_DATA_PIN_PIN7,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(LCD_u8_DATA_PORT_PIN6 ,LCD_u8_DATA_PIN_PIN6,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(LCD_u8_DATA_PORT_PIN5 ,LCD_u8_DATA_PIN_PIN5,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(LCD_u8_DATA_PORT_PIN4 ,LCD_u8_DATA_PIN_PIN4,DIO_u8_OUTPUT);
	
#if (LCD_u8_MODE == LCD_u8_8_BIT_MODE)

/* continue Set direction for data pins */
	DIO_u8SetPinDirection(LCD_u8_DATA_PORT_PIN3 ,LCD_u8_DATA_PIN_PIN3,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(LCD_u8_DATA_PORT_PIN2 ,LCD_u8_DATA_PIN_PIN2,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(LCD_u8_DATA_PORT_PIN1 ,LCD_u8_DATA_PIN_PIN1,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(LCD_u8_DATA_PORT_PIN0 ,LCD_u8_DATA_PIN_PIN0,DIO_u8_OUTPUT);
	
	_delay_ms(LCD_u8_VDD_DELAY);

	/* Function Set CMND */
	LCD_voidSendCmnd (LCD_FUNCTION_SET);

	_delay_us(LCD_u8_DELAY_AFTER_FUNC_SET);

	/* Display ON/OFF Control */
	LCD_voidSendCmnd (LCD_DISPLAY_ON_OFF_CONTROL);

	_delay_us(LCD_u8_DELAY_AFTER_DIS_CONTROL);

	/* Display Clear */
	LCD_voidSendCmnd (LCD_DISPLAY_CLEAR);

	_delay_ms(LCD_u8_DELAY_AFTER_DIS_CLEAR);

	/* Entry Mode Set */
	LCD_voidSendCmnd (LCD_ENTRY_MODE_SET);

#elif 	(LCD_u8_MODE == LCD_u8_4_BIT_MODE)

	_delay_ms(LCD_u8_VDD_DELAY);

	/* Function Set CMND */
	LCD_voidSendCmnd 	(LCD_ENTRY_MOSE_SET_1);
	LCD_voidSendCmnd 	(LCD_ENTRY_MOSE_SET_2);
	LCD_voidSendCmnd 	(LCD_ENTRY_MOSE_SET_3);

	_delay_us(LCD_u8_DELAY_AFTER_FUNC_SET);

	/* Display ON/OFF Control */
	LCD_voidSendCmnd (LCD_DISPLAY_ON_OFF_CONTROL);

	_delay_us(LCD_u8_DELAY_AFTER_DIS_CONTROL);

	/* Display Clear */
	LCD_voidSendCmnd (LCD_DISPLAY_CLEAR);

	_delay_ms(LCD_u8_DELAY_AFTER_DIS_CLEAR);

	/* Entry Mode Set */
	LCD_voidSendCmnd (LCD_ENTRY_MODE_SET);



#endif

}

/***************************************************************/
/***************************************************************/

void LCD_voidSendCmnd (u8 Copy_u8Cmnd)
{
#if (LCD_u8_MODE == LCD_u8_8_BIT_MODE)

	/* Step 1 : Rs = 0 */
	DIO_u8SetPinValue ( LCD_u8_RS_PORT , LCD_u8_RS_PIN , DIO_u8_LOW ) ;
	
	/* Step 2 : Rw = 0 */
	DIO_u8SetPinValue ( LCD_u8_RW_PORT , LCD_u8_RW_PIN , DIO_u8_LOW ) ;
	
	/* Write Command */
	/* Case All data pins on one port */
	/* DIO_voidSetPortValue ( LCD_u8_DATA_PORT ,  Copy_u8Cmnd) ; */
	DIO_u8SetPinValue(LCD_u8_DATA_PORT_PIN7 , LCD_u8_DATA_PIN_PIN7 , GET_BIT(Copy_u8Cmnd , DIO_u8_PIN7)) ;
	DIO_u8SetPinValue(LCD_u8_DATA_PORT_PIN6 , LCD_u8_DATA_PIN_PIN6 , GET_BIT(Copy_u8Cmnd , DIO_u8_PIN6)) ;
	DIO_u8SetPinValue(LCD_u8_DATA_PORT_PIN5 , LCD_u8_DATA_PIN_PIN5 , GET_BIT(Copy_u8Cmnd , DIO_u8_PIN5)) ;
	DIO_u8SetPinValue(LCD_u8_DATA_PORT_PIN4 , LCD_u8_DATA_PIN_PIN4 , GET_BIT(Copy_u8Cmnd , DIO_u8_PIN4)) ;
	DIO_u8SetPinValue(LCD_u8_DATA_PORT_PIN3 , LCD_u8_DATA_PIN_PIN3 , GET_BIT(Copy_u8Cmnd , DIO_u8_PIN3)) ;
	DIO_u8SetPinValue(LCD_u8_DATA_PORT_PIN2 , LCD_u8_DATA_PIN_PIN2 , GET_BIT(Copy_u8Cmnd , DIO_u8_PIN2)) ;
	DIO_u8SetPinValue(LCD_u8_DATA_PORT_PIN1 , LCD_u8_DATA_PIN_PIN1 , GET_BIT(Copy_u8Cmnd , DIO_u8_PIN1)) ;
	DIO_u8SetPinValue(LCD_u8_DATA_PORT_PIN0 , LCD_u8_DATA_PIN_PIN0 , GET_BIT(Copy_u8Cmnd , DIO_u8_PIN0)) ;

	/* E = 1 */
	DIO_u8SetPinValue ( LCD_u8_E_PORT , LCD_u8_E_PIN , DIO_u8_HIGH ) ;
	_delay_us(LCD_u8_ENABLE_DELAY);
	/* E = 0 */
	DIO_u8SetPinValue ( LCD_u8_E_PORT , LCD_u8_E_PIN , DIO_u8_LOW ) ;

#elif 	(LCD_u8_MODE == LCD_u8_4_BIT_MODE)
	/*code to send cmnd at 4 bit mode */

	/* Step 1 : Rs = 0 */
	DIO_u8SetPinValue ( LCD_u8_RS_PORT , LCD_u8_RS_PIN , DIO_u8_LOW ) ;
	/* Step 2 : Rw = 0 */
	DIO_u8SetPinValue ( LCD_u8_RW_PORT , LCD_u8_RW_PIN , DIO_u8_LOW ) ;
	/* Write Command */
	DIO_u8SetPinValue(LCD_u8_DATA_PORT_PIN7 , LCD_u8_DATA_PIN_PIN7 , GET_BIT(Copy_u8Cmnd , DIO_u8_PIN7)) ;
	DIO_u8SetPinValue(LCD_u8_DATA_PORT_PIN6 , LCD_u8_DATA_PIN_PIN6 , GET_BIT(Copy_u8Cmnd , DIO_u8_PIN6)) ;
	DIO_u8SetPinValue(LCD_u8_DATA_PORT_PIN5 , LCD_u8_DATA_PIN_PIN5 , GET_BIT(Copy_u8Cmnd , DIO_u8_PIN5)) ;
	DIO_u8SetPinValue(LCD_u8_DATA_PORT_PIN4 , LCD_u8_DATA_PIN_PIN4 , GET_BIT(Copy_u8Cmnd , DIO_u8_PIN4)) ;

	/* E = 1 */
	DIO_u8SetPinValue ( LCD_u8_E_PORT , LCD_u8_E_PIN , DIO_u8_HIGH ) ;
	_delay_us(LCD_u8_ENABLE_DELAY);
	/* E = 0 */
	DIO_u8SetPinValue ( LCD_u8_E_PORT , LCD_u8_E_PIN , DIO_u8_LOW ) ;

	/*Write the rest of the cmnd */
	DIO_u8SetPinValue(LCD_u8_DATA_PORT_PIN7 , LCD_u8_DATA_PIN_PIN7 , GET_BIT(Copy_u8Cmnd , DIO_u8_PIN3)) ;
	DIO_u8SetPinValue(LCD_u8_DATA_PORT_PIN6 , LCD_u8_DATA_PIN_PIN6 , GET_BIT(Copy_u8Cmnd , DIO_u8_PIN2)) ;
	DIO_u8SetPinValue(LCD_u8_DATA_PORT_PIN5 , LCD_u8_DATA_PIN_PIN5 , GET_BIT(Copy_u8Cmnd , DIO_u8_PIN1)) ;
	DIO_u8SetPinValue(LCD_u8_DATA_PORT_PIN4 , LCD_u8_DATA_PIN_PIN4 , GET_BIT(Copy_u8Cmnd , DIO_u8_PIN0)) ;

	/* E = 1 */
	DIO_u8SetPinValue ( LCD_u8_E_PORT , LCD_u8_E_PIN , DIO_u8_HIGH ) ;
	_delay_us(LCD_u8_ENABLE_DELAY);
	/* E = 0 */
	DIO_u8SetPinValue ( LCD_u8_E_PORT , LCD_u8_E_PIN , DIO_u8_LOW ) ;
/****************************************************************************************/
	/* another sloution ## : Shifting */

	/*
	  (Step 1 : Rs = 1)
		DIO_u8SetPinValue ( LCD_u8_RS_PORT , LCD_u8_RS_PIN , DIO_u8_HIGH ) ;
		 (Step 2 : Rw = 0)
		DIO_u8SetPinValue ( LCD_u8_RW_PORT , LCD_u8_RW_PIN , DIO_u8_LOW ) ;

				( Write Char first high 4 bit )
	DIO_voidSetPortValue ( LCD_u8_DATA_PORT ,  Copy_u8Cmnd) ;

			( E = 1 )
	DIO_u8SetPinValue ( LCD_u8_E_PORT , LCD_u8_E_PIN , DIO_u8_HIGH ) ;
	_delay_us(1);
	( E = 0 )
	DIO_u8SetPinValue ( LCD_u8_E_PORT , LCD_u8_E_PIN , DIO_u8_LOW ) ;

	 ( Write Char second high 4 bit )
	   DIO_voidSetPortValue ( LCD_u8_DATA_PORT ,  Copy_u8Cmnd<<4) ;

	   				( E = 1 )
	DIO_u8SetPinValue ( LCD_u8_E_PORT , LCD_u8_E_PIN , DIO_u8_HIGH ) ;
	_delay_us(1);
	( E = 0 )
	DIO_u8SetPinValue ( LCD_u8_E_PORT , LCD_u8_E_PIN , DIO_u8_LOW ) ;



		*/

#endif
}

/***************************************************************/
/***************************************************************/

void LCD_voidSendChar (u8 Copy_u8Char)
{
#if (LCD_u8_MODE == LCD_u8_8_BIT_MODE)

	/* Step 1 : Rs = 1 */
	DIO_u8SetPinValue ( LCD_u8_RS_PORT , LCD_u8_RS_PIN , DIO_u8_HIGH ) ;
	
	/* Step 2 : Rw = 0 */
	DIO_u8SetPinValue ( LCD_u8_RW_PORT , LCD_u8_RW_PIN , DIO_u8_LOW ) ;
	
	/* Write Char */
	//DIO_voidSetPortValue ( LCD_u8_DATA_PORT ,  Copy_u8Char) ;
	DIO_u8SetPinValue(LCD_u8_DATA_PORT_PIN7 , LCD_u8_DATA_PIN_PIN7 , GET_BIT(Copy_u8Char, DIO_u8_PIN7)) ;
	DIO_u8SetPinValue(LCD_u8_DATA_PORT_PIN6 , LCD_u8_DATA_PIN_PIN6 , GET_BIT(Copy_u8Char, DIO_u8_PIN6)) ;
	DIO_u8SetPinValue(LCD_u8_DATA_PORT_PIN5 , LCD_u8_DATA_PIN_PIN5 , GET_BIT(Copy_u8Char, DIO_u8_PIN5)) ;
	DIO_u8SetPinValue(LCD_u8_DATA_PORT_PIN4 , LCD_u8_DATA_PIN_PIN4 , GET_BIT(Copy_u8Char, DIO_u8_PIN4)) ;
	DIO_u8SetPinValue(LCD_u8_DATA_PORT_PIN3 , LCD_u8_DATA_PIN_PIN3 , GET_BIT(Copy_u8Char, DIO_u8_PIN3)) ;
	DIO_u8SetPinValue(LCD_u8_DATA_PORT_PIN2 , LCD_u8_DATA_PIN_PIN2 , GET_BIT(Copy_u8Char, DIO_u8_PIN2)) ;
	DIO_u8SetPinValue(LCD_u8_DATA_PORT_PIN1 , LCD_u8_DATA_PIN_PIN1 , GET_BIT(Copy_u8Char, DIO_u8_PIN1)) ;
	DIO_u8SetPinValue(LCD_u8_DATA_PORT_PIN0 , LCD_u8_DATA_PIN_PIN0 , GET_BIT(Copy_u8Char, DIO_u8_PIN0)) ;

	/* E = 1 */
	DIO_u8SetPinValue ( LCD_u8_E_PORT , LCD_u8_E_PIN , DIO_u8_HIGH ) ;
	
	_delay_us(LCD_u8_ENABLE_DELAY);
	
	/* E = 0 */
	DIO_u8SetPinValue ( LCD_u8_E_PORT , LCD_u8_E_PIN , DIO_u8_LOW ) ;

#elif 	(LCD_u8_MODE == LCD_u8_4_BIT_MODE)
	/*code to send cmnd at 4 bit mode */

	/* Step 1 : Rs = 1 */
		DIO_u8SetPinValue ( LCD_u8_RS_PORT , LCD_u8_RS_PIN , DIO_u8_HIGH ) ;
		/* Step 2 : Rw = 0 */
		DIO_u8SetPinValue ( LCD_u8_RW_PORT , LCD_u8_RW_PIN , DIO_u8_LOW ) ;

		/* Write Data */
		DIO_u8SetPinValue(LCD_u8_DATA_PORT_PIN7 , LCD_u8_DATA_PIN_PIN7 , GET_BIT(Copy_u8Char , DIO_u8_PIN7)) ;
		DIO_u8SetPinValue(LCD_u8_DATA_PORT_PIN6 , LCD_u8_DATA_PIN_PIN6 , GET_BIT(Copy_u8Char , DIO_u8_PIN6)) ;
		DIO_u8SetPinValue(LCD_u8_DATA_PORT_PIN5 , LCD_u8_DATA_PIN_PIN5 , GET_BIT(Copy_u8Char , DIO_u8_PIN5)) ;
		DIO_u8SetPinValue(LCD_u8_DATA_PORT_PIN4 , LCD_u8_DATA_PIN_PIN4 , GET_BIT(Copy_u8Char , DIO_u8_PIN4)) ;

		/* E = 1 */
		DIO_u8SetPinValue ( LCD_u8_E_PORT , LCD_u8_E_PIN , DIO_u8_HIGH ) ;
		_delay_us(LCD_u8_ENABLE_DELAY);
		/* E = 0 */
		DIO_u8SetPinValue ( LCD_u8_E_PORT , LCD_u8_E_PIN , DIO_u8_LOW ) ;

		/*Write the rest of the Data */
		DIO_u8SetPinValue(LCD_u8_DATA_PORT_PIN7 , LCD_u8_DATA_PIN_PIN7 , GET_BIT(Copy_u8Char , DIO_u8_PIN3)) ;
		DIO_u8SetPinValue(LCD_u8_DATA_PORT_PIN6 , LCD_u8_DATA_PIN_PIN6 , GET_BIT(Copy_u8Char , DIO_u8_PIN2)) ;
		DIO_u8SetPinValue(LCD_u8_DATA_PORT_PIN5 , LCD_u8_DATA_PIN_PIN5 , GET_BIT(Copy_u8Char , DIO_u8_PIN1)) ;
		DIO_u8SetPinValue(LCD_u8_DATA_PORT_PIN4 , LCD_u8_DATA_PIN_PIN4 , GET_BIT(Copy_u8Char , DIO_u8_PIN0)) ;

		/* E = 1 */
		DIO_u8SetPinValue ( LCD_u8_E_PORT , LCD_u8_E_PIN , DIO_u8_HIGH ) ;

		_delay_us(LCD_u8_ENABLE_DELAY);

		/* E = 0 */
		DIO_u8SetPinValue ( LCD_u8_E_PORT , LCD_u8_E_PIN , DIO_u8_LOW ) ;
/****************************************************************************************/

		/* another sloution ## : Shifting */

		/*
		  (Step 1 : Rs = 1)
			DIO_u8SetPinValue ( LCD_u8_RS_PORT , LCD_u8_RS_PIN , DIO_u8_HIGH ) ;
			 (Step 2 : Rw = 0)
			DIO_u8SetPinValue ( LCD_u8_RW_PORT , LCD_u8_RW_PIN , DIO_u8_LOW ) ;

					( Write Char first high 4 bit )
		DIO_voidSetPortValue ( LCD_u8_DATA_PORT ,  Copy_u8Char) ;

				( E = 1 )
		DIO_u8SetPinValue ( LCD_u8_E_PORT , LCD_u8_E_PIN , DIO_u8_HIGH ) ;
		_delay_us(1);
		( E = 0 )
		DIO_u8SetPinValue ( LCD_u8_E_PORT , LCD_u8_E_PIN , DIO_u8_LOW ) ;

		 ( Write Char second high 4 bit )
		   DIO_voidSetPortValue ( LCD_u8_DATA_PORT ,  Copy_u8Char<<4) ;

		   				( E = 1 )
		DIO_u8SetPinValue ( LCD_u8_E_PORT , LCD_u8_E_PIN , DIO_u8_HIGH ) ;
		_delay_us(1);
		( E = 0 )
		DIO_u8SetPinValue ( LCD_u8_E_PORT , LCD_u8_E_PIN , DIO_u8_LOW ) ;



			*/

#endif
}

/***************************************************************/
/***************************************************************/

void LCD_voidWriteStr(u8 * Copy_Pu8Str)
{
	u8 Local_u8Counter = 0;

	while(Copy_Pu8Str[Local_u8Counter]!='\0')
	{
		LCD_voidSendChar (Copy_Pu8Str[Local_u8Counter]);
		Local_u8Counter++;
	}
}

/***************************************************************/
/***************************************************************/


void LCD_voidWriteNum(s32  Copy_s32Num)
{
	    s32 Local_s32Num 	= Copy_s32Num;
	    s8 Local_s8len 		= 0;
	    u8 Local_u8Negflag  = 0;
	    u8 Local_pStr[10] 	= {0};
	    if(Copy_s32Num == 0)
	    {
	    	LCD_voidSendChar('0');
	    }
	    else
	    {
	        if(Copy_s32Num < 0)
	        {
	        	Copy_s32Num  = Copy_s32Num * (-1);
	        	Local_u8Negflag = 1;
	        }

			while(Local_s32Num != 0)
			{
				Local_s32Num /= 10;
				Local_s8len++;
			}
			for(int i = (Local_s8len-1) + Local_u8Negflag ; i >= 0 + Local_u8Negflag ; i--)
			{
				Local_pStr[i] = (Copy_s32Num % 10) + 48;
				Copy_s32Num /= 10;
			}
			Local_pStr[Local_s8len + Local_u8Negflag] = 0;
			if(Local_u8Negflag == 1)
			{
				Local_pStr[0] = '-';
			}
			LCD_voidWriteStr(Local_pStr);

	    }

}


/***************************************************************/
/***************************************************************/

u8 LCD_voidGoToXY (u8 Copy_u8LineNum , u8 Copy_u8Location)
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;

	if(Copy_u8Location <= 39)
	{
		switch(Copy_u8LineNum)
		{
		case LCD_u8_LINE1 :	LCD_voidSendCmnd (LCD_u8_LINE_1_FIRST_ADDRESS + Copy_u8Location); 	break;
		case LCD_u8_LINE2 :	LCD_voidSendCmnd (LCD_u8_LINE_2_FIRST_ADDRESS + Copy_u8Location); 	break;
		default 		  : Local_u8ErrorState = STD_TYPES_NOK ;		break;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}
	return Local_u8ErrorState ;
}

/***************************************************************/
/***************************************************************/

void LCD_voidClearDisplay (void)
{
	LCD_voidSendCmnd(0b00000001);
	_delay_ms(LCD_u8_DELAY_AFTER_DIS_CLEAR);
}

/***************************************************************/
/***************************************************************/

void LCD_voidWriteSpecialChar 	(u8 Copy_u8CharNum , u8 * Copy_u8Pattern , u8 Copy_u8LineNum , u8 Copy_u8Location)
{

	/* CGGRAM Address 0 ----> 63 */
	u8 Local_u8CGRAMAddress = Copy_u8CharNum * 8 ;

	u8 Local_u8counter = 0 ;

	SET_BIT(Local_u8CGRAMAddress , 6);

	LCD_voidSetCGRAM_Addr(Local_u8CGRAMAddress);

	for (Local_u8counter = 0 ; Local_u8counter <8 ; Local_u8counter ++)
	{
		LCD_voidSendChar(Copy_u8Pattern[Local_u8counter]);
	}

	LCD_voidGoToXY(Copy_u8LineNum , Copy_u8Location);

	LCD_voidSendChar(Copy_u8CharNum);

}

/***************************************************************/
/***************************************************************/

void LCD_voidSetCGRAM_Addr  	(u8 Copy_u8Adrr)
{
	LCD_voidSendCmnd(Copy_u8Adrr);
}

/***************************************************************/
/***************************************************************/

u8 LCD_voidShiftDisplay       (u8 Copy_u8Side , u16 Copy_u16Delay)
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;

		switch(Copy_u8Side)
		{
		case LCD_u8_SHIFT_LEFT 	: LCD_voidSendCmnd(LCD_u8_DISPLAY_LEFT); _delay_ms(Copy_u16Delay); break;
		case LCD_u8_SHIFT_RIGHT : LCD_voidSendCmnd(LCD_u8_DISPLAY_RIGHT); _delay_ms(Copy_u16Delay); break;
		default 				: Local_u8ErrorState = STD_TYPES_NOK ;
		}

	return Local_u8ErrorState ;
}

u8 LCD_voidShiftCursor       (u8 Copy_u8Side , u8 Copy_u8Times)
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;
	u8 Local_u8Counter = 0 ;

	for(Local_u8Counter = 0 ; Local_u8Counter < Copy_u8Times ; Local_u8Counter ++)
	{
		switch(Copy_u8Side)
		{
		case LCD_u8_SHIFT_LEFT 	: LCD_voidSendCmnd(LCD_u8_CURSOR_LEFT);  break;
		case LCD_u8_SHIFT_RIGHT : LCD_voidSendCmnd(LCD_u8_CURSOR_RIGHT);  break;
		default 				: Local_u8ErrorState = STD_TYPES_NOK ;
		}
	}
	return Local_u8ErrorState ;
}







