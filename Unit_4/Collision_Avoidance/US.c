/*
 * US.c
 *
 *  Created on: Oct 24, 2023
 *      Author: abdoo
 */
#include <stdio.h>
#include <stdlib.h>
#include "US.h"

void (*US_state)();

int US_distance;

enum {
	US_busy
}US_state_id;


void US_init(){

	printf("\nUS_init");
}

int US_get_distande_random(int l, int r ,int count){
	int i=0;
	int random_num;
	for(i=0; i<count; i++){
	random_num= (rand()%((r-l)+1))+l;
	}
	return random_num;

}

STATE_define(US_busy){

	US_state_id=US_busy;
	US_distance=US_get_distande_random(45,55,1);
	printf("\nUS_busy state: distance %d",US_distance);
	US_set_distance(US_distance);
	US_state= STATE(US_busy);

}
