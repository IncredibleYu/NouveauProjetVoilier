#include "GIROUETTE.h"
#include "stm32f10x.h"
#define Arr 1439
#define Psc 0
MyTimer_Struct_TypeDef MTIM2={TIM2,Arr,Psc}; 
// Configuration broches Codeur sur GPIOA: INDEX->PC6 et CHA->PA0 et CHB->PA1 en INPUT FLOATING
// PA6= TIM2_CH1 et PA7=TIM2_CH2
void GPIO_Config(void){
	MyGPIO_Struct_TypeDef MGPIOA0={GPIOA,0,In_Floating};
	MyGPIO_Struct_TypeDef MGPIOA1={GPIOA,1,In_Floating};
	MyGPIO_Struct_TypeDef MGPIOC6={GPIOC,6,In_Floating};
	MyGPIO_Init (&MGPIOA0) ;
	MyGPIO_Init (&MGPIOA1) ;
	MyGPIO_Init (&MGPIOC6) ;
}




// Initialisation et Configuration TIMER
void TIMER_Config(void){

	GPIO_Config();  
	MyTimer_Base_Init(&MTIM2);
	//On met TIM2_SMCR à 011 pour compter dans Tl1 ainsi que dans Tl2
	TIM2->SMCR &= ~(0x07);
	TIM2->SMCR |=(0x03);
	//Configuration Interruption EXTI PC6
	/*(EXTI->IMR) = 0x01<<6 ;
	// Activation Interruption EXTI sur front montant PC6
	(EXTI->RTSR)|=(0x01<<6); 
	// Désactivation Interruption EXTI sur front descendant PC6  
	(EXTI->FTSR) &= ~(0x01 <<6);

	// Activation Interruption EXTI au niveau du coeur
	// L’interruption EXTI au niveau du coeur est identifiée par le numéro 23
	NVIC->ISER[0] = NVIC->ISER[0] | (1 << 23);
	
	// Priorité Interruption EXTI
	NVIC->IP[23]=4;*/

}



// Configuration Girouette 
void Conf_Girouette(void){
	
	int test = 0;
	// Configuration TIMER Codeur
	TIMER_Config();
	
	while(test == 0){
				test = (GPIOC->IDR	& (0x01<<6)); // IDX=6
			}
	TIM2->CNT=0;

}

// 	Retourner l'angle de la Girouette
int Get_Angle_Girouette(void){
	int Angle_girouette;
	Angle_girouette = (TIM2->CNT)/4;
	return Angle_girouette;
}

