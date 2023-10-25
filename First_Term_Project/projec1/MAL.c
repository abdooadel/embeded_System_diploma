/*
 * PS.c
 *
 *  Created on: Oct 24, 2023
 *      Author: abdoo
 */

#include "MAL.h"
extern  int pressure_val;
int threshold=20;
void (*MAL_state)();

void set_pressure_val(){
	pressure_val= (int)getPressureVal();
	MAL_state=state(high_pressure);
}


define_state(high_pressure){
	MAL_state_ID=high_pressure;
	MAL_state= state(high_pressure);
	(pressure_val > threshold) ? (MAL_state=high_pressure_detected):(MAL_state=set_pressure_val);

}

