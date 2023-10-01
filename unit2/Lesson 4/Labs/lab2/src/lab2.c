/*
 ============================================================================
 Name        : lab2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float x[]={5,16,22,3.5,15};
	float y;
	for(int i=0;i<5;i++){
		y=5*x[i]*x[i]+3*x[i]+2;
		printf("y(%f)=%f\r\n",x[i],y);
	}
	return EXIT_SUCCESS;
}
