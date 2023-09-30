/*
 ============================================================================
 Name        : lab1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char choice;
	float radius;
	printf("Enter circle radius : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f",&radius);
	printf("\r\n Enter your choice (a to print the area, c to print the circumference) : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%c",&choice);
	if(choice=='a')
		printf("\n\r area is : %f", 3.14*radius*radius);
	else if (choice == 'c')
		printf("\n\r circumference is %f",2*3.14*radius);
	else
		printf("WRONG CHOICE");


	return EXIT_SUCCESS;
}
