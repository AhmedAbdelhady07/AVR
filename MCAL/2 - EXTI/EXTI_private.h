/********************************************************************************************************************/
/*****************     Author 		: Ahmed Abdelhady 	*************************************************************/
/*****************     File 		: Private Of EXTI  	*************************************************************/
/*****************     Date 		: 1/1/2023  		*************************************************************/
/*****************     Version 		: 1.0  				*************************************************************/
/*****************     Description 	: Drive For EXTI 	*************************************************************/
/********************************************************************************************************************/

#ifndef 	EXTI_PRIVATE_H
#define 	EXTI_PRIVATE_H

/* EXTI Register */
/*************  MCUCR Register  *************/
#define EXTI_u8_MCUCR_REG			* ((volatile u8 *) 0x55)
/*************  MCUSCR Register  *************/
#define EXTI_u8_MCUCSR_REG		* ((volatile u8 *) 0x54)
/*************  GICR Register  *************/
#define EXTI_u8_GICR_REG			* ((volatile u8 *) 0x5B)
/*************  GIFR Register  *************/
#define EXTI_u8_GIFR_REG			* ((volatile u8 *) 0x5A)

/* EXTI BITS */

/*************  MCUCR Bits  *************/
#define EXTI_u8_ISC00_BIT			0
#define EXTI_u8_ISC01_BIT			1
#define EXTI_u8_ISC10_BIT			2
#define EXTI_u8_ISC11_BIT			3

/*************  MCUSCR Bits  *************/
#define	EXTI_u8_ISC2_BIT		6

/*************  GICR Bits  *************/
#define	EXTI_u8_INT2_BIT		5
#define	EXTI_u8_INT0_BIT		6
#define	EXTI_u8_INT1_BIT		7

/* Masking */
#define EXTI_u8_EXTI_0_TRIGG_MASKING		0b11111100 /* 0xFC */
#define EXTI_u8_EXTI_1_TRIGG_MASKING		0b11110011 /* 0xF3 */

/* Value Way Of Sense*/
#define EXTI_u8_NORMAL_WAY			0
#define EXTI_u8_MASK_WAY			1


#endif
