/*
 ============================================================================
 Name        : 4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void rev (int );

int main(void) {

	int num;
	printf ("Enter the number  : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&num);
	rev(num);

	return EXIT_SUCCESS;
}

void rev (int num){
	int digit, i;
	digit= printf("%d \n",num);
	printf("The reversed number : ");
	for(i=0; i< (digit -2);i++){
		printf("%d",num%10);
		num /=10;
	}
	return ;
}
