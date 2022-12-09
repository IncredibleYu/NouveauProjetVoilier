#ifndef TIMER_H
#define TIMER_H
#include "stm32f10x.h"

typedef struct
{
TIM_TypeDef * Timer ; // TIM1 à TIM4
unsigned short ARR ;
unsigned short PSC ;
} MyTimer_Struct_TypeDef ;
/*
*****************************************************************************************
* @brief
* @param -> Paramètre sous forme d’une structure (son addresse) contenant les
informations de base
* @Note -> Fonction à lancer systématiquement avant d’aller plus en détail dans les
conf plus fines 
*************************************************************************************************
*/
void MyTimer_Base_Init( MyTimer_Struct_TypeDef * Timer ) ;
void MyTimer_Active_IT ( TIM_TypeDef * Timer , char Prio,void (*IT_function)(void )) ;
//#define MyTimer_Base_Start ( Timer ) (Timer->CR1 |= ( 1 << 0))
//#define MyTimer_Base_Stop ( Timer ) (Timer->CR1 &= ~( 1 << 0))
void Timer_PWM_Init(TIM_TypeDef *Timer, int Channel);

//	 Fixer la le rapport cyclique de la PWM 
void Timer_PWM_DutyCycle_Fix(TIM_TypeDef *Timer, int Duty_Cycle, int Channel);
#endif
