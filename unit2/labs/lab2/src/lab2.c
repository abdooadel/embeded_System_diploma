/*
 ============================================================================
 Name        : lab2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int a,b,c;
	printf("enter three values : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&a);
	scanf("\n\r%d",&b);
	scanf("\n\r%d",&c);
	if( a>b && a>c)
		printf("The Largest value is : %d",a);
	if( b>a && b>c)
		printf("The Largest value is : %d",b);
	if( c>a && c>b)
		printf("The Largest value is : %d",c);



	return EXIT_SUCCESS;
}
