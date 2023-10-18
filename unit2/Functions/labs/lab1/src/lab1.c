/*
 ============================================================================
 Name        : lab1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

unsigned long factorial (int num);
int main(void) {
	int num;
	printf("Enter the number you want to find factorial to :");
	fflush(stdin); fflush(stdout);
	scanf("\n\f %u",&num);
	printf("Factorial(%d) = %lu",num,factorial(num));
	return EXIT_SUCCESS;
}

unsigned long factorial (int num){
	int result=1;
	if (num==0){
		return 1;
	}
	else if (num>0)
	{
		for(;num > 0;num--)
		{
			result *=num;
		}
		return result;
	}
	else
		return 0;

}
