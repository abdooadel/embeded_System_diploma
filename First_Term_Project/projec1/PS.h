/*
 * Pressure sensor.c
 *
 *  Created on: Oct 24, 2023
 *      Author: abdoo
 */

#ifndef PS_H_
#define PS_H_

#include "STATE.h"

extern void (*PS_state)();

enum {

	PS_reading,
	PS_waiting
}PS_state_ID;

void PS_init();

define_state(PS_reading);
define_state(PS_waiting);



#endif /* AA_H_ */
