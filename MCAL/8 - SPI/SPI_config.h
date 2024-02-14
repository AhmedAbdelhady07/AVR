/********************************************************************************************************************/
/*****************     Author 		: Ahmed Abdelhady 	*************************************************************/
/*****************     File 		: Config Of SPI  	*************************************************************/
/*****************     Date 		: 27/9/2023  		*************************************************************/
/*****************     Version 		: 1.0  				*************************************************************/
/*****************     Description 	: Drive For SPI 	*************************************************************/
/********************************************************************************************************************/

#ifndef 	SPI_CONFIG_H
#define 	SPI_CONFIG_H

/* Options : SPI_MASTER
 * 			 SPI_SLAVE
 */
#define SPI_MASTER_SLAVE_SELECT      SPI_MASTER

/* Options : SPI_LSB
 * 			 SPI_MSB
 */
#define SPI_DATA_ORDER_SELECT		SPI_MSB

/* Options : SPI_RISING_FALLING
 * 			 SPI_FALLING_RISING
 */
#define SPI_CLK_POLARITY_SELECT		SPI_RISING_FALLING

/* Options : SPI_SAMPLE_SETUP
 * 			 SPI_SETUP_SAMPLE
 */
#define SPI_CLK_PHASE_SELECT		SPI_SETUP_SAMPLE

/* Only For Master */
/* Options : SPI_FOSC_4
 * 			 SPI_FOSC_16
 * 			 SPI_FOSC_64
 * 			 SPI_FOSC_128
 */
#define SPI_CLK_RATE_SELECT			SPI_FOSC_64

/* Options : SPI_NORMAL_SPEED
 * 			 SPI_DOUBLE_SPEED
 */
#define SPI_CLK_SPEED_SELECT		SPI_NORMAL_SPEED

#endif
