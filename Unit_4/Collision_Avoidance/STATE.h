/*
 * STATE.h
 *
 *  Created on: Oct 24, 2023
 *      Author: abdoo
 */

#ifndef STATE_H_
#define STATE_H_


#define STATE_define(_state_)	void  ST_##_state_()
#define STATE(_state_)	ST_##_state_


void US_set_distance(int d);
void DC_motor(int speed);


#endif /* STATE_H_ */
