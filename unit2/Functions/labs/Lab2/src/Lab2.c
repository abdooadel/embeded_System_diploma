/*
 ============================================================================
 Name        : Lab2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int calcMin(int values[],int n);

int main(void) {

	int values[]={15,12,31,48,6,-4,47,5,-8,0,6,4,-5};
	printf("Minimum value = %d",calcMin(values,13));
	return EXIT_SUCCESS;
}

int calcMin(int values[],int n){
	int storage=values[0];
	for(int i=0;i<= n-1;i++)
	{
		if(storage > values[i+1])
			storage=values[i+1];
	}
	return storage;
}
