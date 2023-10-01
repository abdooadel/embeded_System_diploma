/*
 ============================================================================
 Name        : Ex2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int data_num;
	float arr[100],sum=0;
	printf("Enter the numbers of data: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&data_num);
	for(int i=0; i<data_num;i++)
	{
		printf("Enter number%d: ",i+1);
		fflush(stdin);
		fflush(stdout);
		scanf("%f",&arr[i]);
		sum += arr[i];
	}
	printf("Average = %2.2f",sum/data_num);
	return EXIT_SUCCESS;
}
