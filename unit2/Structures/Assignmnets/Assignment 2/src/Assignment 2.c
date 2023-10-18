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
struct SDistance_info{
	int feet;
	float inch;
}D1,D2,sum;
int main(void) {

	printf("Enter information for 1st distance");
	printf("\nEnter feet: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&D1.feet);
	printf("\nEnter inch: ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&D1.inch);
	printf("\nEnter information for 2nd distance");
	printf("\nEnter feet: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&D2.feet);
	printf("\nEnter inch: ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&D2.inch);
	sum.feet= D1.feet+D2.feet;
	sum.inch= D1.inch+D2.inch;
	if(sum.inch>12){
		sum.inch -=12;
		sum.feet++;
	}
	printf("Sum of distances= %d'-%.2f",sum.feet,sum.inch);
}
