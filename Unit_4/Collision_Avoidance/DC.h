/*
 * DC.h
 *
 *  Created on: Oct 24, 2023
 *      Author: abdoo
 */

#ifndef DC_H_
#define DC_H_

#include "STATE.h"



STATE_define(DC_idle);
STATE_define(DC_busy);
void DC_init();

  extern void (*DC_state)();

#endif /* DC_H_ */
