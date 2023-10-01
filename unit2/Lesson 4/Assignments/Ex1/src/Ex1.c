/*
 ============================================================================
 Name        : Ex1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : sum of two arrays
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	float arr1[2][2], arr2[2][2] ,sum[2][2];
	printf("Enter the element of 1st matrix");
	for(int i=0;i<2;i++)
	{
		for(int z=0;z<2;z++)
		{
			printf("\n\rEnter a%d%d :",i+1,z+1);
			fflush(stdin); fflush(stdout);
			scanf("%f",&arr1[i][z]);
		}
	}
	printf("Enter the element of 2st matrix");
	for(int i=0;i<2;i++)
	{
		for(int z=0;z<2;z++)
		{
			printf("\n\rEnter a%d%d :",i+1,z+1);
			fflush(stdin); fflush(stdout);
			scanf("%f",&arr2[i][z]);
		}
	}

	for(int i=0;i<2;i++)
	{
		for(int z=0;z<2;z++)
		{
			sum[i][z]=arr1[i][z]+arr2[i][z];
		}
	}
	printf("Sum of Matrix : \n\r");
	for(int i=0;i<2;i++)
	{
		for(int z=0;z<2;z++)
		{
			printf("%2.1f  ",sum[i][z]);
		}
		printf("\n");
	}
	return EXIT_SUCCESS;
}
