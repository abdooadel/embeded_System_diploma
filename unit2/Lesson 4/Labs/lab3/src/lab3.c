/*
 ============================================================================
 Name        : lab3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	float matrix[3][3];
	float matrix_trans[3][3];

	for(int i=0;i<3;i++)
	{
		for(int z=0; z<3; z++)
		{
			printf("\n\rEnter the item[%d][%d]  ",i,z);
			fflush(stdin); fflush(stdout);
			scanf("%f",&matrix[i][z]);
		}
	}

	printf("the matrix is \n\r");
	for(int i=0;i<3;i++)
	{
		for(int z=0; z<3; z++)
		{
			printf("[%f] : ",matrix[i][z]);

		}
		printf("\n\r");
	}

	for(int i=0;i<3;i++)
		{
			for(int z=0; z<3; z++)
			{
				matrix_trans[z][i]=	matrix[i][z];

			}
		}

	printf("the Transpose matrix is \n\r");
		for(int i=0;i<3;i++)
		{
			for(int z=0; z<3; z++)
			{
				printf("[%f] : ",matrix_trans[i][z]);

			}
			printf("\n\r");
		}
	return EXIT_SUCCESS;
}
