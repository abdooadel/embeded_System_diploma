/*
 * main.c
 *
 *  Created on: Oct 24, 2023
 *      Author: abdoo
 */

#include <stdio.h>
#include <stdlib.h>
#include "US.h"
#include "CA.h"
#include "DC.h"



void setup(){
	US_init();
	DC_init();

	CA_state=STATE (CA_waiting);
	US_state=STATE (US_busy);
	DC_state=STATE (DC_idle);

}

void main(){
	 volatile int d;
	setup();
	while(1){
		US_state();
		CA_state();
		DC_state();
		for(d=0; d<=2000; d++);
	}



}
