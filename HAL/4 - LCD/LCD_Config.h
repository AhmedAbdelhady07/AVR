/*************************************************************************/
/***************      Name 		:  Ahmed Abdelhady  	******************/
/***************      Date 		:  20 / 12 / 2022  		******************/
/***************      SWC 		:  LCD          		******************/
/***************      Version 	:  1.0          		******************/
/*************************************************************************/

#ifndef 	LCD_CONFIG_H
#define 	LCD_CONFIG_H

/* Options :     1-DIO_u8_PORTA
                 2-DIO_u8_PORTB
				 3-DIO_u8_PORTC
				 4-DIO_u8_PORTD

				 DIO_u8_PIN 0----7 */

#define LCD_u8_RS_PORT        			DIO_u8_PORTD
#define LCD_u8_RS_PIN					DIO_u8_PIN0

#define LCD_u8_RW_PORT					DIO_u8_PORTD
#define LCD_u8_RW_PIN					DIO_u8_PIN1

#define LCD_u8_E_PORT					DIO_u8_PORTD
#define LCD_u8_E_PIN					DIO_u8_PIN2

/* Case all data pins on one port */
#define LCD_u8_DATA_PORT				DIO_u8_PORTA

/* Config Pins for 8bit Mode */
/************************************************************************************/
/**************************************************************************************/
/* Config Pins for 4bit Mode *//*****************************/                        /**/
#define LCD_u8_DATA_PORT_PIN7        	DIO_u8_PORTC       	/**/                      /**/
#define LCD_u8_DATA_PIN_PIN7        	DIO_u8_PIN7         /**/                      /**/
                                                            /**/                      /**/
#define LCD_u8_DATA_PORT_PIN6        	DIO_u8_PORTC        /**/                      /**/
#define LCD_u8_DATA_PIN_PIN6        	DIO_u8_PIN6         /**/                      /**/
                                                           	/**/                      /**/
#define LCD_u8_DATA_PORT_PIN5        	DIO_u8_PORTC       	/**/                      /**/
#define LCD_u8_DATA_PIN_PIN5        	DIO_u8_PIN5         /**/                      /**/
                                                            /**/                      /**/
#define LCD_u8_DATA_PORT_PIN4        	DIO_u8_PORTC        /**/                      /**/
#define LCD_u8_DATA_PIN_PIN4        	DIO_u8_PIN4        	/**/                      /**/
/**********************************************************//**/                      /**/
/**********************************************************/                          /**/
#define LCD_u8_DATA_PORT_PIN3        	DIO_u8_PORTC                                  /**/
#define LCD_u8_DATA_PIN_PIN3        	DIO_u8_PIN3                                   /**/
                                                                                      /**/
#define LCD_u8_DATA_PORT_PIN2        	DIO_u8_PORTC                                  /**/
#define LCD_u8_DATA_PIN_PIN2        	DIO_u8_PIN2                                   /**/
                                                                                      /**/
#define LCD_u8_DATA_PORT_PIN1        	DIO_u8_PORTC                                  /**/
#define LCD_u8_DATA_PIN_PIN1        	DIO_u8_PIN1                                   /**/
                                                                                      /**/
#define LCD_u8_DATA_PORT_PIN0        	DIO_u8_PORTC                                  /**/
#define LCD_u8_DATA_PIN_PIN0        	DIO_u8_PIN0                                   /**/
/************************************************************************************/
/************************************************************************************/

/* Options : 1-LCD_u8_8_BIT_MODE
 	 	 	 2-LCD_u8_4_BIT_MODE
 */


#define 	LCD_u8_MODE			LCD_u8_4_BIT_MODE


// 0 --> 1 Line
// 1 --> 2 Lines
#define LCD_u8_NO_OF_LINES		1

// 0 --> 5*7
// 1 --> 5*10
#define LCD_u8_CHARACTER_FONT 	0

// 0 --> Off
// 1 --> On
#define LCD_u8_DISPLAY_STATUS 	1

// 0 --> Hidden
// 1 --> Displayed
#define LCD_u8_CURSOR_DISPLAY  	0

// 0 --> Fixed
// 1 --> Blink
#define LCD_u8_CURSOR_BLINK		0

/* AC Shifting **/
// 0 --> Decrease
// 1 --> Increase
#define LCD_u8_I_D	1

/* While writing */
// 0 --> Shift is off
// 1 --> Shift is on
#define LCD_u8_SHIFT 0



#endif
