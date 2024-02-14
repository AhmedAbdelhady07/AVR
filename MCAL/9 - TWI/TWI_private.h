/********************************************************************************************************************/
/*****************     Author 		: Ahmed Abdelhady 	*************************************************************/
/*****************     File 		: Private Of TWI  	*************************************************************/
/*****************     Date 		: 1/1/2023  		*************************************************************/
/*****************     Version 		: 1.0  				*************************************************************/
/*****************     Description 	: Drive For TWI 	*************************************************************/
/********************************************************************************************************************/

#ifndef 	TWI_PRIVATE_H
#define 	TWI_PRIVATE_H


#define TWI_u8_SLAVE_ADRESS_MASKING	0b00000001

/* ACK macros for Master */
#define TWI_u8_START_ACK					0x08
#define TWI_u8_RESTART_ACK					0x10
#define TWI_u8_SLA_W_ACK					0x18
#define TWI_u8_SLA_R_ACK					0x40
#define TWI_u8_DATA_W_ACK					0x28
#define TWI_u8_DATA_R_ACK					0x50

/* NACK macros for Master */
#define TWI_u8_DATA_W_NACK					0x30
#define TWI_u8_DATA_R_NACK					0x58

#define TWI_u8_STATUS_CODE_CHECK			0xF8

/* Enable/Disable ACK */
#define TWI_ENABLE_ACK		1
#define TWI_DISABLE_ACK		0


/* Enable/Disable ACK */
#define TWI_ENABLE_GC		1
#define TWI_DISABLE_GC		0

/*  Data Register */
#define TWI_u8_TWDR_REG				*((volatile u8 *)0x23)
/* Data Register Bits */
#define  TWI_u8_TWD0_BIT					0

/* Bit Rate Register */
#define TWI_u8_TWBR_REG				*((volatile u8 *)0x20)


/* Control Register  */
#define TWI_u8_TWCR_REG				*((volatile u8 *)0x56)
/*  Control Register Bits */
#define  TWI_u8_TWIE_BIT					0
#define  TWI_u8_TWEN_BIT					2
#define  TWI_u8_TWWC_BIT					3
#define  TWI_u8_TWSTO_BIT					4
#define  TWI_u8_TWSTA_BIT					5
#define  TWI_u8_TWEA_BIT					6
#define  TWI_u8_TWINT_BIT					7

/*  (Slave) Address Register */
#define TWI_u8_TWAR_REG				*((volatile u8 *)0x22)
/* (Slave) Address Register Bits */
#define  TWI_u8_TWGCE_BIT						0
#define  TWI_u8_TWA0_BIT						1
#define  TWI_u8_TWA1_BIT						3
#define  TWI_u8_TWA3_BIT						4
#define  TWI_u8_TWA4_BIT						5
#define  TWI_u8_TWA5_BIT						6
#define  TWI_u8_TWA6_BIT						7

/* Status Register */
#define TWI_u8_TWSR_REG				*((volatile u8 *)0x21)
/* Status Register Bits */
#define  TWI_u8_TWPS0_BIT						0
#define  TWI_u8_TWPS1_BIT						1
#define  TWI_u8_TWS3_BIT						3
#define  TWI_u8_TWS4_BIT						4
#define  TWI_u8_TWS5_BIT						5
#define  TWI_u8_TWS6_BIT						6
#define  TWI_u8_TWS7_BIT						7

#endif
