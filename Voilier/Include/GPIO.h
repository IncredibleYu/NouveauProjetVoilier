#ifndef GPIO_H
#define GPIO_H

#include "stm32f10x.h"

typedef struct
{
	GPIO_TypeDef * GPIO ;
	char GPIO_Pin ; //numero de 0 a 15
	char GPIO_Conf; // voir ci dessous
} MyGPIO_Struct_TypeDef ;


#define In_Analog 0x00
#define In_Floating 0x04
#define In_PullDown 0x08
#define In_PullUp 0x08
#define Out_Ppull 0x01
#define Out_OD 0x05
#define AltOut_Ppull 0x09
#define AltOut_OD 0x0D


// GPIO Initialisation et choix de la Config et Mode
void MyGPIO_Init (MyGPIO_Struct_TypeDef * JP ) ;


// Lire la broche : renvoie 0 ou autre chose different de 0
int MyGPIO_Read ( GPIO_TypeDef * GPIO , char GPIO_Pin ) ; 


// Mettre la broche à 1
void MyGPIO_Set ( GPIO_TypeDef * GPIO , char GPIO_Pin ) ; 


// Mettre la broche à 0
void MyGPIO_Reset ( GPIO_TypeDef * GPIO , char GPIO_Pin ) ;


// Faire clignotter la borche 
void MyGPIO_Toggle ( GPIO_TypeDef * GPIO , char GPIO_Pin ) ; 


#endif


