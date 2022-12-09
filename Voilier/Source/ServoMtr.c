#include "SERVOMTR.h"
#define ARR1 99 
#define PSC1 14544 //EVENT_FREQUENCY =1440000 = ITRx_CLK / ( (PSC+1) * (ARR+1) * (RCR + 1))
MyTimer_Struct_TypeDef TI = {TIM3,ARR1,PSC1};
MyGPIO_Struct_TypeDef GPA6 = {GPIOA,6,AltOut_Ppull};
//Initialisation du Servomoteur
// Sortie PWN -> PA6
//PA8 -> Output Alternate function push-pull
void Init_SERVOMTR(void){
		
    MyGPIO_Init(&GPA6);
		MyTimer_Base_Init(&TI);
    Timer_PWM_Init(TIM3,1);
			
	   
}




//Calcul du rapport cyclique pour varier l'angle de rotation du Servomoteur
int Calcul_DutyCycle_SERVOMTR(int Angle_Vent) {

	int Duty_Cycle;
	

	if (Angle_Vent <= 45)  {
        Duty_Cycle = 5;
   }
   if (Angle_Vent > 45 && Angle_Vent < 68) {
		Duty_Cycle = 6; 
	}
	if (Angle_Vent >= 68 && Angle_Vent < 90) {
		Duty_Cycle = 7; 
	}
	if (Angle_Vent >= 90 && Angle_Vent < 113) {
		Duty_Cycle = 8; 
	}
   if (Angle_Vent >= 113 && Angle_Vent < 135) {
		Duty_Cycle = 9; 
	}
	if (Angle_Vent >= 135 && Angle_Vent < 225) {
		Duty_Cycle = 10; 
	}
	if (Angle_Vent >= 225 && Angle_Vent < 248) {
		Duty_Cycle = 9; 
	}
	if (Angle_Vent >= 248 && Angle_Vent < 270) {
		Duty_Cycle = 8; 
	}
   if (Angle_Vent >= 270 && Angle_Vent < 293) {
		Duty_Cycle = 7; 
	}
	if (Angle_Vent >= 293 && Angle_Vent < 315) {
		Duty_Cycle = 6; 
	}
	if (Angle_Vent >= 315)  {
        Duty_Cycle = 5;
   }
	
	
	return Duty_Cycle;
}

void Commande_SERVOMTR(int Angle_girouette) {
	
	 Timer_PWM_DutyCycle_Fix(TIM3, Calcul_DutyCycle_SERVOMTR(Angle_girouette), 1);
	
}
	
