/*
 ============================================================================
 Name        : Ex5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int element_num,search,arr[50],search_ind;
	printf("Enter no of elements : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&element_num);
	for(int i=0;i<element_num;i++)
	{
		arr[i]=(i+1)*11;
		printf("%d ", arr[i]);
	}
	printf("\nEnter the element to be searched : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&search);
	for(search_ind=0;search_ind<element_num;search_ind++)
	{
		if(search == arr[search_ind])
		{
			printf("Number found at the location = %d",search_ind+1);
			break;
		}
	}
	if (search_ind==element_num)
		printf("element not found");
	return EXIT_SUCCESS;
}
