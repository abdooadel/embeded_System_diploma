/*
 ============================================================================
 Name        : 7.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int sum ( int );

int main(void) {

	printf("summing numbers from 1 to 100 is : %d" , sum(100));

	return EXIT_SUCCESS;
}

int sum (int count){

	static int result=0;

	if (count >0){
		result += count;
		count --;
		sum(count);
	}

	return result;
}
