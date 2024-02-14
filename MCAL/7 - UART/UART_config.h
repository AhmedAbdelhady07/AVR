/********************************************************************************************************************/
/*****************     Author 		: Ahmed Abdelhady 	*************************************************************/
/*****************     File 		: Config Of UART  	*************************************************************/
/*****************     Date 		: 27/9/2023  		*************************************************************/
/*****************     Version 		: 1.0  				*************************************************************/
/*****************     Description 	: Drive For UART 	*************************************************************/
/********************************************************************************************************************/

#ifndef 	UART_CONFIG_H
#define 	UART_CONFIG_H

/* Options : UART_NORMAL_SPEED
 * 			 UART_DOUBLE_SPEED
 */
#define  UART_SPEED        UART_NORMAL_SPEED

/* Options : UART_ASYNCH_OPERATION
 * 			 UART_SYNCH_OPERATION
 */
#define  UART_MODE_SELECT                     UART_ASYNCH_OPERATION


/* Options : UART_SINGLE_CYCLE_PROCESSOR
 * 			 UART_MULTI_PROCESSOR
 */
#define  UART_PROCESSOR_COMMUNICATION         UART_SINGLE_CYCLE_PROCESSOR


/* Options : UART_DISABLE_PARITY
 * 			 UART_ENABLE_EVEN_PARITY
 * 			 UART_ENABLE_ODD_PARITY
 */
#define  UART_PARITY_MODE               		UART_DISABLE_PARITY


/* Options : UART_1_BIT_STOP_SELECT
 * 			 UART_2_BIT_STOP_SELECT
 */
#define  UART_STOP_BIT_SELECT                    UART_2_BIT_STOP_SELECT


/* Options : UART_5_BIT_CHARACTER_SIZE
 * 			 UART_6_BIT_CHARACTER_SIZE
 * 			 UART_7_BIT_CHARACTER_SIZE
 * 			 UART_8_BIT_CHARACTER_SIZE
 * 			 UART_9_BIT_CHARACTER_SIZE
 */
#define  UART_CHARACTER_SIZE                     UART_8_BIT_CHARACTER_SIZE

/* Options : UART_RIS_TX_FALL_RX
 * 			 UART_FALL_TX_RIS_RX
 */
#define UART_SYNCH_CLK_POLARITY		UART_RIS_TX_FALL_RX

/**********************************************************************************************/
/**********************************************************************************************
 *                                   ((F_CPU/(16*9600))-1)                                    *
 *********************************************************************************************/
#define      UART_BAUD_RATE_UBRR              51

#endif
