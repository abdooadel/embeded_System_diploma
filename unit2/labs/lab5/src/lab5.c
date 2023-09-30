/*
 ============================================================================
 Name        : lab5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int student_number,student_degree;
	float sum=0.0;
	printf("Enter the number of students: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&student_number);
	for(int i=1;i<=student_number;i++){
		printf("Enter student (%d) degree: ",i);
		fflush(stdin); fflush(stdout);
		scanf("%d",&student_degree);
		sum += student_degree;
	}
	printf("Average students degree is : %f", sum/student_number);
	return EXIT_SUCCESS;
}
