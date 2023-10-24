/*
 * CA.c
 *
 *  Created on: Oct 24, 2023
 *      Author: abdoo
 */
#include <stdio.h>
#include <stdlib.h>
#include "CA.h"
int CA_distance=0;
int CA_threshold=50;
int CA_speed=0;
 void (*CA_state)();

 enum {
 	CA_waiting,
 	CA_driving
 }CA_state_id;


void US_set_distance(int d){

	CA_distance=d;
	(CA_distance > CA_threshold)? (CA_state=STATE(CA_driving)) : (CA_state=STATE(CA_waiting));
	printf("\nUS----distance=%d---->CA",CA_speed);
}

STATE_define(CA_waiting){

	CA_state_id= CA_waiting;
	printf("\nCA_WAITING state: distance=%d  speed=%d",CA_distance,CA_speed);
	CA_speed=0;
	DC_motor(CA_speed);
}

STATE_define(CA_driving){

	CA_state_id= CA_driving;
	printf("\nCA_driving state: distance=%d  speed=%d",CA_distance,CA_speed);
	CA_speed=30;
	DC_motor(CA_speed);
}
