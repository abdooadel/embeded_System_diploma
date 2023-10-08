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

int factoria(int num);

int main(void) {

	int num;
	printf("Enter a positive integer: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num);
	int result= factoria(num);
	if (!result)
		printf("Wrong input");
	else
		printf("Factorial of %d = %d", num,result);

	return EXIT_SUCCESS;
}
int result=1;
int factoria(int num)

{



		result *= num;
		num--;
		if (num >0)
			factoria(num);
		return result;
	}







