/****************************************************************************************************************************/
/***************** Author : Ahmed Abdelhady **********************************************************************************/
/***************** File : Program of ULTRASONIC *****************************************************************************/
/***************** Date : 1/5/2023  ***************************************************************************************/
/***************** Version : 1.0  *******************************************************************************************/
/***************** Description : Drive For ULTRASONIC ***********************************************************************/
/****************************************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "math.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include "DIO_interface.h"
#include "TIMERS_interface.h"
#include "GI_interface.h"

#include "ULTRASONIC_interface.h"
#include "ULTRASONIC_config.h"
#include "ULTRASONIC_private.h"

u8 ULTRASONIC_u8EdgeCounter = 0;
u16 ULTRASONIC_u16TimeON = 0;

void ULTRASONIC_voidInit(void)
{
	GI_voidEnable();
	TIMERS_voidTimer1ICUInit();
	TIMERS_voidTimer1ICUSetCallBack(&ULTRASONIC_voidEdgeProcessing);
	DIO_u8SetPinDirection(DIO_u8_PORTD,DIO_u8_PIN6,DIO_u8_INPUT);
	DIO_u8SetPinDirection(ULTRASONIC_TRIGGER_PORT,ULTRASONIC_TRIGGER_PIN,DIO_u8_OUTPUT);
	DIO_u8SetPinValue(ULTRASONIC_TRIGGER_PORT,ULTRASONIC_TRIGGER_PIN,DIO_u8_LOW);
}
void ULTRASONIC_voidTrigger(void)
{
	DIO_u8SetPinValue(ULTRASONIC_TRIGGER_PORT,ULTRASONIC_TRIGGER_PIN,DIO_u8_HIGH);
	_delay_us(10);
	DIO_u8SetPinValue(ULTRASONIC_TRIGGER_PORT,ULTRASONIC_TRIGGER_PIN,DIO_u8_LOW);
}
u16 ULTRASONIC_u16GetDistance(void)
{
	u16 Local_u16Distance;
	for (u8 Local_u8Couter=0;Local_u8Couter<16;Local_u8Couter++)
	{
		ULTRASONIC_voidTrigger();
		/* HC-SR-04 */
		/* Sound velocity = 340.00 m/s = 34000 cm/s
		 * The distance of Object (in cm) = (340000∗Time)/2 = 17000 * Time
		 * Prescaler F_CPU/8 for timer frequency.
		 * The timer gets incremented after 1 us time elapse.
		 * Distance (cm)= 17000 x (TIMER value) x 1 x 10^-6 cm
		 * Distance (cm)= (TIMER value) / 58 cm
		 * Local_u16Distance=(u16)(ULTRASONIC_u16TimeON/(57.828125));  Calculating Distance In cm
		 * */
		Local_u16Distance = (u16)ceil(((ULTRASONIC_u16TimeON / 2)/1000000.0) * 34300) ;
	}
	return Local_u16Distance;
}
void ULTRASONIC_voidEdgeProcessing(void)
{
	ULTRASONIC_u8EdgeCounter++;
	if(ULTRASONIC_u8EdgeCounter == 1)
	{
		TIMERS_voidClearTimer1Value();
		TIMERS_voidTimer1ICUSetTriggerEdge(TIMER1_ICU_FALLING_EDGY_TYPE_MODE);
	}
	else if(ULTRASONIC_u8EdgeCounter == 2)
	{
		ULTRASONIC_u16TimeON = TIMERS_u16Timer1ICUGetInputCaptureValue();
		TIMERS_voidClearTimer1Value();
		ULTRASONIC_u8EdgeCounter=0;
		TIMERS_voidTimer1ICUSetTriggerEdge(TIMER1_ICU_RISING_EDGY_TYPE_MODE);
	}
}
