/********************************************************************************************************************/
/*****************     Author 		: Ahmed Abdelhady 	*************************************************************/
/*****************     File 		: Private Of SPI  	*************************************************************/
/*****************     Date 		: 27/9/2023  		*************************************************************/
/*****************     Version 		: 1.0  				*************************************************************/
/*****************     Description 	: Drive For SPI 	*************************************************************/
/********************************************************************************************************************/

#ifndef 	SPI_PRIVATE_H
#define 	SPI_PRIVATE_H

/**********************************************************************/
#define  SPI_u8_SPDR_REG    *((volatile u8*)0x2F)
/**********************************************************************/
#define  SPI_u8_SPCR_REG               	 *((volatile u8*)0x2D)
#define  SPI_u8_SPCR_SPR0_BIT               0
#define  SPI_u8_SPCR_SPR1_BIT 			 	1
#define  SPI_u8_SPCR_CPHA_BIT 				2
#define  SPI_u8_SPCR_CPOL_BIT 				3
#define  SPI_u8_SPCR_MSTR_BIT               4
#define  SPI_u8_SPCR_DORD_BIT               5
#define  SPI_u8_SPCR_SPE_BIT                6
#define  SPI_u8_SPCR_SPIE_BIT               7
/**********************************************************************/
#define  SPI_u8_SPSR_REG                  *((volatile u8*)0x2E)
#define  SPI_u8_SPSR_SPI2X_BIT            0
#define  SPI_u8_SPSR_WCOL_BIT             6
#define  SPI_u8_SPSR_SPIF_BIT             7
/**********************************************************************/

#define SPI_MASTER		1
#define SPI_SLAVE		0

#define SPI_LSB			1
#define SPI_MSB			0

#define SPI_RISING_FALLING		0
#define SPI_FALLING_RISING		1

#define SPI_SAMPLE_SETUP		0
#define SPI_SETUP_SAMPLE		1

#define SPI_FOSC_4			0
#define SPI_FOSC_16			1
#define SPI_FOSC_64			2
#define SPI_FOSC_128		3

#define SPI_NORMAL_SPEED		0
#define SPI_DOUBLE_SPEED		1

#define SPI_DUMMY_DATA			'\0'


#endif
