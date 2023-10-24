/*
 * DC.c
 *
 *  Created on: Oct 24, 2023
 *      Author: abdoo
 */
#include <stdio.h>
#include <stdlib.h>
#include "DC.h"

enum {
	DC_idle,
	DC_busy
}DC_state_id;

void (*DC_state)();

int DC_speed=0;
void DC_init(){
	printf("\n DC_init");
}

STATE_define(DC_idle){

	DC_state_id= DC_idle;
	printf("\n idle state: speed=%d",DC_speed);

}

STATE_define(DC_busy){

	DC_state_id= DC_busy;
	printf("\n busy state: speed=%d",DC_speed);
	DC_state=STATE(DC_idle);



}

void DC_motor(int speed){

	DC_speed=speed;
	DC_state=STATE(DC_busy);
	printf("\nUS----speed=%d---->CA",DC_speed);





}
