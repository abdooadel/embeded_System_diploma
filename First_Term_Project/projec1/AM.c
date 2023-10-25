/*
 * Alarm Monitor.h
 *
 *  Created on: Oct 24, 2023
 *      Author: abdoo
 */
#include "AM.h"

int alarm_time=600000;
void (*AM_state)();

define_state(AM_ON){
	AM_state_ID= AM_ON;
	start_alarm();
	Delay(alarm_time);
	AM_state= state(AM_wait);

}

define_state(AM_OFF){

	AM_state_ID= AM_OFF;
	stop_alarm();

}

define_state(AM_wait){
	AM_state_ID= AM_wait;
	stop_alarm();
	AM_state= state(AM_OFF);


}
void high_pressure_detected(){
	AM_state= state(AM_ON);
}
