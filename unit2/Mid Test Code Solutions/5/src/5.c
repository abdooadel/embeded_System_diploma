/*
 ============================================================================
 Name        : 5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int find (int );

int main(void) {

	int num;
	printf ("Enter the number  : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&num);
	printf("Number of ones = %d",find(num));

	return EXIT_SUCCESS;
}

int find (int  num){
	int count=0;
	for( ;num !=0;num/= 2)
{
		if (num%2 == 1)
			count++;
	}
	return count;
}
