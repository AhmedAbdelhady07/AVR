/*************************************************************************/
/***************      Name 		:  Ahmed Abdelhady  	******************/
/***************      Date 		:  20 / 12 / 2022  		******************/
/***************      SWC 		:  LCD          		******************/
/***************      Version 	:  1.0          		******************/
/*************************************************************************/
#ifndef 	LCD_INTERFACE_H
#define 	LCD_INTERFACE_H

/***************************************************************/
/***************************************************************/

#define LCD_u8_LINE1    1
#define LCD_u8_LINE2    2

#define LCD_u8_SHIFT_RIGHT      0
#define LCD_u8_SHIFT_LEFT      	1


#define LCD_u8_SPECIAL_CHAR_NUM_0       0
#define LCD_u8_SPECIAL_CHAR_NUM_1       1
#define LCD_u8_SPECIAL_CHAR_NUM_2       2
#define LCD_u8_SPECIAL_CHAR_NUM_3       3
#define LCD_u8_SPECIAL_CHAR_NUM_4       4
#define LCD_u8_SPECIAL_CHAR_NUM_5       5
#define LCD_u8_SPECIAL_CHAR_NUM_6       6
#define LCD_u8_SPECIAL_CHAR_NUM_7       7

void LCD_voidInit 				(void);

void LCD_voidSendCmnd 			(u8 Copy_u8Cmnd);

void LCD_voidSendChar			(u8 Copy_u8Char);

void LCD_voidWriteStr			(u8 *Copy_Pu8Str);

void LCD_voidWriteNum			(s32  Copy_s32Num);

u8 LCD_voidGoToXY 				(u8 Copy_u8LineNum , u8 Copy_u8Location);

void LCD_voidClearDisplay 		(void);

void LCD_voidWriteSpecialChar 	(u8 Copy_u8CharNum , u8 * Copy_u8Pattern , u8 Copy_u8LineNum , u8 Copy_u8Location);

void LCD_voidSetCGRAM_Addr  	(u8 Copy_u8Adrr);

u8 LCD_voidShiftDisplay       (u8 Copy_u8Side , u16 Copy_u16Delay) ;

u8 LCD_voidShiftCursor       (u8 Copy_u8Side , u8 Copy_u8Times) ;





#endif
