/*
 * Alarm Monitor.h
 *
 *  Created on: Oct 24, 2023
 *      Author: abdoo
 */

#ifndef AM_H_
#define AM_H_

#include "STATE.h"
extern void (*AM_state)();

enum {

	AM_ON,
	AM_OFF,
	AM_wait

}AM_state_ID;


define_state(AM_ON);
define_state(AM_OFF);
define_state(AM_wait);
void high_pressure_detected();


#endif /* AA_H_ */
