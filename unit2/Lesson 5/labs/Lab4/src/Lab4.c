/*
 ============================================================================
 Name        : Lab4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void print(int arr[], int x);
int main(void) {
	int z=10;
	int arr[]={0,1,2,3,4,5,6,7,8,9};
	for(int i=0;i< 10;i++)
	{
		print(arr+i,z);
		z--;

	}
	return EXIT_SUCCESS;
}

void print(int arr[],int x){

	for(int i=0;i<x;i++)
	{
		printf("%d",arr[i]);
	}
	printf("\n");

}
