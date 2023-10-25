/*
 * Pressure sensor.c
 *
 *  Created on: Oct 24, 2023
 *      Author: abdoo
 */


#include "PS.h"

 void (*PS_state)();
  int pressure_val=0;
 int timer_val=100000;

void PS_init(){

	PS_state= state(PS_reading);

}

define_state(PS_reading){

	PS_state_ID=PS_reading;
	set_pressure_val();
	Delay(timer_val);
	PS_state= state(PS_waiting);



}
define_state(PS_waiting){

	PS_state_ID=PS_waiting;
	PS_state= state(PS_reading);

}
