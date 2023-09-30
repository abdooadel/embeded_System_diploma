/*
 ============================================================================
 Name        : assignment.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	//Ex1

	printf("C Programming");

	//Ex2
	int num;
	printf("\nEnter a integer: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&num);
	printf("\nYou entered: %d",num);

	//Ex3
	int num1,num2;
	printf("\nEnter two integer: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d %d",&num1,&1um2);
	printf("\nSum:  %d",num1+num2);


	return EXIT_SUCCESS;
}
