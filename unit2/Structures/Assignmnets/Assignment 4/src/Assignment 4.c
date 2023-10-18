/*
 ============================================================================
 Name        : Assignment 4.c
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
	struct Sstudent_info students[10];
	printf("Enter information about the students: \n\n");
	for(int i=0;i<10;i++){
		students[i].roll=i+1;
		printf("For roll number %d",students[i].roll);
		printf("\nEnter name: ");
		fflush(stdin); 	fflush(stdout);
		gets(students[i].name);
		printf("\nEnter marks: ");
		fflush(stdin); 	fflush(stdout);
		scanf("%f",&students[i].mark);
	}
	printf("\n\nDisplaying Information of students: \n");

	for(int i=0;i<10;i++){
		printf("\nInformation for roll number %d:",students[i].roll);
		printf("\nname: %s",students[i].name);
		printf("\nMarks: %.0f",students[i].mark);
	}




	return EXIT_SUCCESS;
}
