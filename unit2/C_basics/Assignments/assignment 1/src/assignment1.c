/*
 ============================================================================
 Name        : assignment.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	//Ex1   Write C Program to Print a Sentence

	printf("C Programming");

	//Ex2  Write C Program to Print a Integer Entered by a User
	int num;
	printf("\nEnter a integer: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&num);
	printf("\nYou entered: %d",num);

	//Ex3  Write C Program to Add Two Integers
	int num1,num2;
	printf("\nEnter two integer: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d %d",&num1,&num2);
	printf("\nSum:  %d",num1+num2);

	//Ex4  Write C Program to Multiply two Floating Point Numbers
	float num11,num22;
	printf("\nEnter two Floating Point Numbers: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f %f",&num11,&num22);
	printf("\nSum:  %f",num11*num22);

	//Ex5  Write C Program to Find ASCII Value of a Character
	char input;
	printf("\nEnter a character: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%c",&input);
	printf("\nASCII value of %c = %d",input,input);

	//Ex6  Write Source Code to Swap Two Numbers
	float a,b,c;
	printf("\nEnter value of a: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f",&a);
	printf("\nEnter value of b: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f",&b);
	c=b;
	b=a;
	printf("After swapping, value of a = %f",c);
	printf("After swapping, value of b = %f",b);

	//Ex7  Write Source Code to Swap Two Numbers without temp variable.
	float x,y;
	printf("\nEnter value of a: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f",&x);
	printf("\nEnter value of b: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f",&y);
	x=x+y;
	y=x-y;
	x=x-y;
	printf("After swapping, value of a = %f",x);
	printf("After swapping, value of b = %f",y);






	return EXIT_SUCCESS;
}
