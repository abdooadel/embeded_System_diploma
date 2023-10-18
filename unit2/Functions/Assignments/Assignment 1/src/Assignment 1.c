/*
 ============================================================================
 Name        : Assignment.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void printPrime(int num1 , int num2){
	int counter=0;
	int x;
	printf("Prime numbers between %d and %d are: ", num1 ,num2);
	for(int i=num1 ; i >= num1 && i <= num2; i++){
		if (i==1){
			printf(" %d", i);
			continue;
		}

		for(x=2; x <= i ;x++){
			if (i%x==0 )
			{
				counter ++;
			}

		}
		if(counter == 1)
			printf(" %d", i);
		counter=0;
	}
}


int main(void) {
	int num1,num2;
	printf("Enter two numbers(intervals): ");
	fflush(stdin); fflush(stdout);
	scanf("%d %d",&num1 ,&num2);
	printPrime(num1,num2);
	return EXIT_SUCCESS;
}
