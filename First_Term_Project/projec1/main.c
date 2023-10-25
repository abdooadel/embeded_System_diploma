#include <stdint.h>
#include <stdio.h>
#include "AA.h"
#include "AM.h"
#include "PS.h"
#include "MAL.h"

int global;
void setup(){
	PS_init();
	AA_init();
	MAL_state= state(high_pressure);
	AM_state=state(AM_OFF);

}


int main (){
	GPIO_INITIALIZATION();
	setup();

	while (1)
	{
		global=getPressureVal();
/*
		Set_Alarm_actuator(0);
		Delay(10000);
		Set_Alarm_actuator(1);
		Delay(10000);
*/

		PS_state();
		MAL_state();
		AM_state();
		AA_state();

	}

}
