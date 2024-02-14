/****************************************************************************************************************************/
/***************** Author : Ahmed Abdelhady **********************************************************************************/
/***************** File : Interface of TIMERS ********************************************************************************/
/***************** Date : 24/9/2023  ***************************************************************************************/
/***************** Version : 1.0  *******************************************************************************************/
/***************** Description : Drive For TIMERS ****************************************************************************/
/****************************************************************************************************************************/
#ifndef TIMERS_INTERFACE_H
#define TIMERS_INTERFACE_H
/********************************************************************************** Timer 0 ***************************************/
void TIMERS_voidTimer0Init(void);
u8 TIMERS_u8Timer0Delay(u32 Copy_u32DTime,void(*Copy_pFun)(void)) ;
void TIMERS_voidTimer0Start (void) ;
void TIMERS_voidTimer0Stop (void) ;
void TIMERS_voidTimer0GeneratePWM(u8 Copy_u8Intensity);
/********************************************************************************** Timer 2 ***************************************/
void TIMERS_voidTimer2Init(void);
u8 TIMERS_u8Timer2Delay(u32 Copy_u32DTime,void(*Copy_pFun)(void)) ;
void TIMERS_voidTimer2Start (void) ;
void TIMERS_voidTimer2Stop (void)  ;
void TIMERS_voidTimer2GeneratePWM(u8 Copy_u8Intensity);
/*********************************************************************************************/
/********************************************************************************** Timer 1 ***************************************/
void TIMERS_voidTimer1Enable(u8 Copy_u8Timer1Mode,u8 Copy_u8Timer1ModeChannelA,u8 Copy_u8Timer1ModeChannelB);
void TIMERS_voidTimer1GeneratePWMOCR1A(u8 Copy_u8Intensity) ;
void TIMERS_voidTimer1GeneratePWMOCR1B(u8 Copy_u8Intensity) ;
void TIMERS_voidTimer1SetOCR1A(u16 Copy_u16OCRA);
void TIMERS_voidTimer1SetOCR1B(u16 Copy_u16OCRB);
void TIMERS_voidTimer1SetICR1(u16 Copy_u16ICR1);
void TIMERS_voidTimer1SetTCNT1(u16 Copy_u16TCNT1);
u16  TIMERS_u16Timer1ReadTimerValue (void) ;
/***************************************************************************/
#define  TIMER1_MODE_NORMAL                                          0
#define  TIMER1_MODE_PWM_PHASE_CORRECT_8_BIT                         1
#define  TIMER1_MODE_PWM_PHASE_CORRECT_9_BIT                         2
#define  TIMER1_MODE_PWM_PHASE_CORRECT_10_BIT                        3
#define  TIMER1_MODE_CTC_OCR1A                                       4
#define  TIMER1_MODE_FAST_PWM_8_BIT                                  5
#define  TIMER1_MODE_FAST_PWM_9_BIT                                  6
#define  TIMER1_MODE_FAST_PWM_10_BIT                                 7
#define  TIMER1_MODE_PWM_PHASE_AND_FRQUENCY_CORRECT_ICR1             8
#define  TIMER1_MODE_PWM_PHASE_AND_FRQUENCY_CORRECT_OCR1A            9
#define  TIMER1_PWM_PHASE_CORRECT_ICR1                               10
#define  TIMER1_PWM_PHASE_CORRECT_OCR1A                              11
#define  TIMER1_MODE_CTC_ICR1                                        12
#define  TIMER1_MODE_FAST_PWM_ICR1                                   14
#define  TIMER1_MODE_FAST_PWM_OCR1A                                  15
/***************************************************************************/
#define  TIMER1_MODE_CHANNEL_A_NORMAL                                0
#define  TIMER1_MODE_CHANNEL_A_TOGGLE                                1
#define  TIMER1_MODE_CHANNEL_A_CLEAR_OC1A                            2
#define  TIMER1_MODE_CHANNEL_A_SET_OC1A                              3
/***************************************************************************/
#define  TIMER1_MODE_CHANNEL_B_NORMAL                                0
#define  TIMER1_MODE_CHANNEL_B_TOGGLE                                1
#define  TIMER1_MODE_CHANNEL_B_CLEAR_OC1B                            2
#define  TIMER1_MODE_CHANNEL_B_SET_OC1B                              3
/***************************************************************************/
/********************************************************************************** ICU Timer 1 ***************************************/
void TIMERS_voidTimer1ICUInit(void);
void TIMERS_voidTimer1ICU_Disable_Int (void) ;
void TIMERS_voidTimer1ICUSetTriggerEdge(u8 Copy_u8ICUEdgeType);
u16  TIMERS_u16Timer1ICUGetInputCaptureValue(void);
void TIMERS_voidTimer1ICUSetCallBack(void (*Copy_pFun) (void));
void TIMERS_voidClearTimer1Value(void);
/***************************************************************************/
#define  TIMER1_ICU_RISING_EDGY_TYPE_MODE                           1
#define  TIMER1_ICU_FALLING_EDGY_TYPE_MODE                          0
/***************************************************************************/




#endif
