/*
 ============================================================================
 Name        : 6.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int find(int arr[],int size);
int main(void) {
	int arr[3]={4,2,4};

	printf("The unique number is : %d", find(arr,3));

	return EXIT_SUCCESS;
}

int find(int arr[],int size){
	int i,x;
	int flag=0;

	for(i=0; i<=size-1;i++){
		for (x=0;x<=size-1;x++)
		{
			if(i==x)
				continue;

			if (arr[i]== arr[x])
			{
				flag=1;
				break;
			}
			else
				flag=0;
		}
		if (flag ==0)
			return arr[i];
	}
	return 0;
}
