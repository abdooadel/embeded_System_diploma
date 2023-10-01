/*
 ============================================================================
 Name        : Ex4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int element_num,location,new_ele, arr[50], new[50];
	printf("Enter no of elements : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&element_num);
	for(int i=0;i<element_num;i++)
	{
		arr[i]=i+1;
		printf("%d ",arr[i]);
	}
	printf("\nEnter the element to be inserted : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&new_ele);
	printf("\nEnter the location : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&location);
	for(int i=0,z=0;i<element_num+1;i++,z++)
	{
		if(location==i+1)
		{
			new[i]=new_ele;
			z--;
			continue;
		}

		new[i]=arr[z];
	}

	for(int i=0;i<element_num+1;i++)
		{

			printf("%d ",new[i]);
		}

	return EXIT_SUCCESS;
}
