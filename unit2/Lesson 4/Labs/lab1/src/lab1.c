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

int main(void) {
	float stud_deg[10];
	for(int i=0;i<10;i++)
	{
		printf("\n Enter %d degree : ",i+1);
		fflush(stdout);
		fflush(stdin);
		scanf("%f",&stud_deg[i]);

	}

	for(int i=0;i<10;i++)
	{
		printf("\nstudent %d degree is %f",i+1,stud_deg[i]);
	}

	return EXIT_SUCCESS;
}
