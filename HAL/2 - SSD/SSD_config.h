/********************************************************************************************************************/
/*****************     Author 		: Ahmed Abdelhady 	*************************************************************/
/*****************     File 		: Config Of SSD  	*************************************************************/
/*****************     Date 		: 1/1/2023  		*************************************************************/
/*****************     Version 		: 1.0  				*************************************************************/
/*****************     Description 	: Drive For SSD 	*************************************************************/
/********************************************************************************************************************/

#ifndef 	SSD_CONFIG_H
#define 	SSD_CONFIG_H

/* SSD1 On Left ... SSD2 On Right*/

/* SSD Mode */
/* Options : 	 SSD_u8_SSD_NORMAL_MODE
				 SSD_u8_SSD_POV_MODE 	*/

/* POV When Two Devices Only		   */
#define SSD_u8_SSD_MODE_VISION	SSD_u8_SSD_POV_MODE


/* SSD1---(POV_MODE) */
#define SSD_u8_SSD1_LED_A_PORT 		DIO_u8_PORTC
#define SSD_u8_SSD1_LED_A_PIN		DIO_u8_PIN0
#define SSD_u8_SSD1_LED_B_PORT		DIO_u8_PORTC
#define SSD_u8_SSD1_LED_B_PIN		DIO_u8_PIN1
#define SSD_u8_SSD1_LED_C_PORT		DIO_u8_PORTC
#define SSD_u8_SSD1_LED_C_PIN		DIO_u8_PIN2
#define SSD_u8_SSD1_LED_D_PORT		DIO_u8_PORTC
#define SSD_u8_SSD1_LED_D_PIN		DIO_u8_PIN3
#define SSD_u8_SSD1_LED_E_PORT		DIO_u8_PORTC
#define SSD_u8_SSD1_LED_E_PIN		DIO_u8_PIN4
#define SSD_u8_SSD1_LED_F_PORT		DIO_u8_PORTC
#define SSD_u8_SSD1_LED_F_PIN		DIO_u8_PIN5
#define SSD_u8_SSD1_LED_G_PORT		DIO_u8_PORTC
#define SSD_u8_SSD1_LED_G_PIN		DIO_u8_PIN6
#define SSD_u8_SSD1_LED_DOT_PORT	DIO_u8_PORTC
#define SSD_u8_SSD1_LED_DOT_PIN		DIO_u8_PIN7

/* SSD2  */
#define SSD_u8_SSD2_LED_A_PORT		DIO_u8_PORTB
#define SSD_u8_SSD2_LED_A_PIN		DIO_u8_PIN0
#define SSD_u8_SSD2_LED_B_PORT		DIO_u8_PORTB
#define SSD_u8_SSD2_LED_B_PIN		DIO_u8_PIN1
#define SSD_u8_SSD2_LED_C_PORT		DIO_u8_PORTB
#define SSD_u8_SSD2_LED_C_PIN		DIO_u8_PIN2
#define SSD_u8_SSD2_LED_D_PORT		DIO_u8_PORTB
#define SSD_u8_SSD2_LED_D_PIN		DIO_u8_PIN3
#define SSD_u8_SSD2_LED_E_PORT		DIO_u8_PORTB
#define SSD_u8_SSD2_LED_E_PIN		DIO_u8_PIN4
#define SSD_u8_SSD2_LED_F_PORT		DIO_u8_PORTB
#define SSD_u8_SSD2_LED_F_PIN		DIO_u8_PIN5
#define SSD_u8_SSD2_LED_G_PORT		DIO_u8_PORTB
#define SSD_u8_SSD2_LED_G_PIN		DIO_u8_PIN6
#define SSD_u8_SSD2_LED_DOT_PORT	DIO_u8_PORTB
#define SSD_u8_SSD2_LED_DOT_PIN		DIO_u8_PIN7



/* SSD1 Enable */
#define SSD_u8_SSD1_ENABLE_PORT		DIO_u8_PORTD
#define SSD_u8_SSD1_ENABLE_PIN		DIO_u8_PIN0

/* SSD2 Enable */
#define SSD_u8_SSD2_ENABLE_PORT		DIO_u8_PORTD
#define SSD_u8_SSD2_ENABLE_PIN		DIO_u8_PIN1

/* SSD Select Mode */
/* Opions : SSD_u8_SSD_COMMON_CATHODE
				SSD_u8_SSD_COMMON_ANODE		*/
#define SSD_u8_SSD_MODE	SSD_u8_SSD_COMMON_CATHODE


#endif
