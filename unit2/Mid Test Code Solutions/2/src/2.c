/*
 ============================================================================
 Name        : 2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calc(float);
int main(void) {

	float num;
	printf("enter the number : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f",&num);
	printf("The result= %.3lf",calc(num));

	return EXIT_SUCCESS;
}

double calc(float num){

	return sqrt(num);
}
