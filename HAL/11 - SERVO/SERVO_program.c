/****************************************************************************************************************************/
/***************** Author : Ahmed Abdelhady **********************************************************************************/
/***************** File : Program of SERVO **********************************************************************************/
/***************** Date : 25/9/2023  ***************************************************************************************/
/***************** Version : 1.0  *******************************************************************************************/
/***************** Description : Drive For SERVO ****************************************************************************/
/****************************************************************************************************************************/
/* LIB Layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/* HAL Layer */
#include "DIO_interface.h"
#include "TIMERS_interface.h"
/* MCAL Layer */
#include "SERVO_interface.h"
#include "SERVO_private.h"
#include "SERVO_config.h"
void SERVO_voidTimer1InitOCR1A(void)
{
	DIO_u8SetPinDirection(DIO_u8_PORTD,DIO_u8_PIN5,DIO_u8_OUTPUT);
	TIMERS_voidTimer1SetICR1 (19999);
	TIMERS_voidTimer1Enable(TIMER1_MODE_FAST_PWM_ICR1,TIMER1_MODE_CHANNEL_A_CLEAR_OC1A,TIMER1_MODE_CHANNEL_B_NORMAL);
}
void SERVO_voidTimer1InitOCR1B(void)
{
	DIO_u8SetPinDirection(DIO_u8_PORTD,DIO_u8_PIN4,DIO_u8_OUTPUT);
	TIMERS_voidTimer1SetICR1 (19999);
	TIMERS_voidTimer1Enable(TIMER1_MODE_FAST_PWM_ICR1,TIMER1_MODE_CHANNEL_A_NORMAL,TIMER1_MODE_CHANNEL_B_CLEAR_OC1B);
}
void SERVO_voidTimer1ServoSetAngleOCR1A(u8 Copy_u8Angle)
{
	u16 Local_u32AnglePulse = (((Copy_u8Angle * 2015UL )/180)+670);
	TIMERS_voidTimer1SetOCR1A(Local_u32AnglePulse);
}
void SERVO_voidTimer1ServoSetAngleOCR1B(u8 Copy_u8Angle)
{
	u16 Local_u32AnglePulse = (((Copy_u8Angle * 2015UL )/180)+670);
	TIMERS_voidTimer1SetOCR1B(Local_u32AnglePulse);
}
