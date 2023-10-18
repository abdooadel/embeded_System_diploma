/*
 ============================================================================
 Name        : Print_array_rev.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int arr[15];
	int *Parr=arr;
	int size;
	printf("Input the number of elements to store in the array (max 15) : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&size);
	printf("\nInput %d number of elements in the array :",size);
	int i;
	for(i=1;i<=size;i++){
		printf("\nelement - %d :",i);
		fflush(stdin); fflush(stdout);
		scanf("%d",Parr);
		Parr++;
	}
	Parr--;
	printf("The elements of array in reverse order are :");
	for(i=size;i>0;i--){
		printf("\nelement - %d : %d",i,*Parr);
		Parr--;
	}

	return EXIT_SUCCESS;
}
