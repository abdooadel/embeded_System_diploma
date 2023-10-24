/*
 * US.h
 *
 *  Created on: Oct 24, 2023
 *      Author: abdoo
 */

#ifndef US_H_
#define US_H_
#include "STATE.h"


STATE_define(US_busy);

extern void (*US_state)();
void US_init();


#endif /* US_H_ */
