/*
 ============================================================================
 Name        : 8.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void rev(int arr[],int size);
int main(void) {

	int arr[100],size;
	printf("enter size of the array: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&size);
	rev(arr,size);
	return EXIT_SUCCESS;
}

void rev(int arr[],int size){
	int i;
	for(i=0;i<size;i++){
		printf("enter number %d:  ",i+1);
		fflush(stdin); fflush(stdout);
		scanf("%d",&arr[i]);
	}
	printf("\n reversed array: ");
	for(i=size-1;i>=0;i--){
		printf(" %d",arr[i]);
	}

}
