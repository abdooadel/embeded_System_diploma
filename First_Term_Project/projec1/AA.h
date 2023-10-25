/*
 * alarm actuator.h
 *
 *  Created on: Oct 24, 2023
 *      Author: abdoo
 */

#ifndef AA_H_
#define AA_H_

#include "STATE.h"
extern void (*AA_state)();

enum {

	AA_ON,
	AA_OFF,
	AA_wait

}AA_state_ID;

enum {

	alarm_ON =0,
	alarm_OFF=1

}alarm_state_ID;

define_state(AA_ON);
define_state(AA_OFF);
define_state(AA_wait);
void start_alarm();
void stop_alarm();
void AA_init();

#endif /* AA_H_ */
