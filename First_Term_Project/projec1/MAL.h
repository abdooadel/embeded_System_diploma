/*
 * AA.h
 *
 *  Created on: Oct 24, 2023
 *      Author: abdoo
 */

#ifndef MAL_H_
#define MAL_H_

#include "STATE.h"

extern void (*MAL_state)();

enum {

	high_pressure
}MAL_state_ID;


define_state(high_pressure);


#endif /* AA_H_ */
