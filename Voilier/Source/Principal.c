#include "stm32f10x.h"
#include "TIMER.h"
#include "GPIO.h"
#include "math.h"
#include "SERVOMTR.h"
#include "GIROUETTE.h"

int angle;


void Initialisation(void){
		Init_SERVOMTR();
		Conf_Girouette();
}

int main (void)
{
			Initialisation();

	while(1){
		angle = Get_Angle_Girouette();
		Commande_SERVOMTR(angle);
	}
}


