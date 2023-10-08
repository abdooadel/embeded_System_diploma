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

int get_power(int num, int power);

int main(void) {
	int num,power;
	printf("Enter base number :");
	fflush(stdin); fflush(stdout);
	scanf("%d", &num);
	printf("Enter power number(positive integer) :");
	fflush(stdin); fflush(stdout);
	scanf("%d", &power);

	printf("%d^%d = %d",num,power,get_power(num,power));
	return EXIT_SUCCESS;
}

int get_power(int num, int power){
	power--;
	if(power>0){
		return num*get_power(num,power);
	}

}
