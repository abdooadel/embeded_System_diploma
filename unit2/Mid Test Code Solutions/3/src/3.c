/*
 ============================================================================
 Name        : 3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void findprim (int , int);
int main(void) {

	int num1, num2;
	printf("enter two numbers : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d %d",&num1, &num2);
	printf ("primary numbers between %d and %d are : ", num1,num2);
	findprim(num1,num2);

	return EXIT_SUCCESS;
}

void findprim (int num1 , int num2){

	int x,i;
	int count=0;

	for ( x=num1;x<=num2 ; x++)
	{
		if (x==1){
			printf("%d ",x);
			continue;
		}
		for(i=2; i<= num2;i++)
		{
			if (x %i == 0)
				count ++;
		}

		if (count ==1)
			printf("%d ",x);
		count=0;
	}
}
