/*
 * STATE.h
 *
 *  Created on: Oct 24, 2023
 *      Author: abdoo
 */

#ifndef STATE_H_
#define STATE_H_
#include "driver.h"
#include <stdio.h>
#define define_state(_func_) void _##_func_()
#define state(_func_)  _##_func_

void set_pressure_val();
void high_pressure_detected();
void start_alarm();
void stop_alarm();


#endif /* STATE_H_ */
