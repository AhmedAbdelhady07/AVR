/*************************************************************************/
/***************      Name 		:  Ahmed Abdelhady  	******************/
/***************      Date 		:  20 / 12 / 2022  		******************/
/***************      SWC 		:  LCD          		******************/
/***************      Version 	:  1.0          		******************/
/*************************************************************************/
#ifndef 	LCD_Private_H
#define 	LCD_Private_H

#define     LCD_u8_8_BIT_MODE     1
#define     LCD_u8_4_BIT_MODE     0

#define LCD_u8_DONT_CARE_BIT	0

#define LCD_FUNCTION_SET  CONC(0 , 0 , 1 , LCD_u8_MODE , LCD_u8_NO_OF_LINES , LCD_u8_CHARACTER_FONT , LCD_u8_DONT_CARE_BIT , LCD_u8_DONT_CARE_BIT)

#define LCD_DISPLAY_ON_OFF_CONTROL CONC(0 , 0 , 0 , 0 , 1 , LCD_u8_DISPLAY_STATUS , LCD_u8_CURSOR_DISPLAY , LCD_u8_CURSOR_BLINK )

#define LCD_DISPLAY_CLEAR 0x01

/* 8 bit mode*/
#define LCD_ENTRY_MODE_SET CONC(0,0,0,0,0,1,LCD_u8_I_D,LCD_u8_SHIFT)

/* 4 bit mode */
#define LCD_ENTRY_MOSE_SET_1	0b00110011
#define LCD_ENTRY_MOSE_SET_2	0b00110010
#define LCD_ENTRY_MOSE_SET_3	CONC(0 , 0 , 1 , 0 , LCD_u8_NO_OF_LINES , LCD_u8_CHARACTER_FONT , 0 , 0)

/* Delays */
#define LCD_u8_ENABLE_DELAY				1
#define LCD_u8_VDD_DELAY				35
#define LCD_u8_DELAY_AFTER_FUNC_SET		40
#define LCD_u8_DELAY_AFTER_DIS_CONTROL	40
#define LCD_u8_DELAY_AFTER_DIS_CLEAR	2

/* DDRAM Adresses */
#define LCD_u8_LINE_1_FIRST_ADDRESS		0x80
#define LCD_u8_LINE_2_FIRST_ADDRESS		0xC0

/* Shifting */
#define LCD_u8_CURSOR_LEFT	0b00010000
#define LCD_u8_CURSOR_RIGHT	0b00010100

#define LCD_u8_DISPLAY_LEFT		0b00011000
#define LCD_u8_DISPLAY_RIGHT	0b00011100


#endif

/***************************************************************/
/***************************************************************/
