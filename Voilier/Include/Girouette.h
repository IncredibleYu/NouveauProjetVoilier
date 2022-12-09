#ifndef GIROUETTE_H
#define GIROUETTE_H

#include "stm32f10x.h"
#include "TIMER.h"
#include "GPIO.h"

// Configuration broches GPIOA, INDEX->PA5 et CHA->PA6 et CHB->PA7 en INPUT FLOATING
void GPIO_Config(void); 


// Configuration TIMER Codeur
void TIMER_Config(void);



// Configuration Girouette 
void Conf_Girouette(void);


// 	Retourner l'angle de la Girouette
int Get_Angle_Girouette(void);


#endif
