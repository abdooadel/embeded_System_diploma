/*
 ============================================================================
 Name        : lab6.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int var=10;
	for(int i=0;i<10;i++){
		int count=i;
		for(int a=0;a<var;a++)
		{
			printf("%d",count);
			count ++;

		}
		var--;
		printf("\n");
	}
	return EXIT_SUCCESS;
}
