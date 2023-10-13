/*
 ============================================================================
 Name        : 1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int summ(unsigned int);
int main(void) {

	unsigned int num;
	printf("enter the number : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%u",&num);
	printf("The sum= %u",summ(num));
	return EXIT_SUCCESS;
}

int summ(unsigned int num){
	unsigned int  new;
	int store=0;
	while(num != 0)
	{
		new = num%10;
		store += new;
		num /= 10;
	}
	return store ;
}
