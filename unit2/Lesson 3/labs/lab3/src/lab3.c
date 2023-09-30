/*
 ============================================================================
 Name        : lab3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int a,b,min;
	printf("Enter two numbers : ");
	fflush(stdin); fflush(stdout);
	scanf("%d %d",&a , &b);
	min= (a>b)? b:a ;
	printf("The minimum Number is : %d",min);
	return 0;
}
