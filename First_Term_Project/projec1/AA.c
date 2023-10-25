/*
 * alarm actuator.c
 *
 *  Created on: Oct 24, 2023
 *      Author: abdoo
 */

#include  "AA.h"

void (*AA_state)();




void AA_init(){
	AA_state= state(AA_wait);
}

define_state(AA_ON){
	AA_state_ID=AA_ON;
	AA_state=state(AA_wait);

}

define_state(AA_OFF){
	AA_state_ID=AA_OFF;
	AA_state=state(AA_wait);
}

define_state(AA_wait){
	AA_state_ID=AA_wait;
}
void start_alarm(){
	Set_Alarm_actuator(alarm_ON);
	AA_state=state(AA_ON);

}
void stop_alarm(){
	Set_Alarm_actuator(alarm_OFF);
	AA_state=state(AA_OFF);

}
