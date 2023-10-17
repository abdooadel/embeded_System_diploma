/*
 ============================================================================
 Name        : Assignment.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct Sstudent_info{
	char name[20];
	int roll;
	float mark;
};
int main(void) {
	struct Sstudent_info std1;
	printf("Enter information about the students: \n\n");
	printf("Enter name: ");
	fflush(stdin); 	fflush(stdout);
	gets(std1.name);
	printf("Enter roll number: ");
	fflush(stdin); 	fflush(stdout);
	scanf("%d",&std1.roll);
	printf("Enter marks: ");
	fflush(stdin); 	fflush(stdout);
	scanf("%f",&std1.mark);
	printf("\n\n	Displaying Information");
	printf("\nname: %s",std1.name);
	printf("\nRoll: %d",std1.roll);
	printf("\nMarks: %.2f",std1.mark);





	return EXIT_SUCCESS;
}
