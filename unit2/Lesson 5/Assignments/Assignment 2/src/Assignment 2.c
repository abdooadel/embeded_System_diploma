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
		printf("Factorial of %d = %d", num,factoria(num));

	return EXIT_SUCCESS;
}
 int factoria(int num)

{
	 int result=1;
	if (num>0)
	{
		for(int i=1; i<= num;i++)
			result *= i;

	return result;
	}
else
	return 0;
}





