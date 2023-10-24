/*
 * CA.h
 *
 *  Created on: Oct 24, 2023
 *      Author: abdoo
 */

#ifndef CA_H_
#define CA_H_

#include "STATE.h"


STATE_define(CA_waiting);
STATE_define(CA_driving);

extern void (*CA_state)();





#endif /* CA_H_ */
