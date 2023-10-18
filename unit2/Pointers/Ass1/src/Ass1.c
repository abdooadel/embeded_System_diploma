/*
 ============================================================================
 Name        : Ass1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int m;
	int *Pm=&m;
	*Pm=29;
	printf("Address of m : %x \nValue of m : %d",Pm,*Pm);
	*Pm=34;
	printf("\nAddress of m : %x \nValue of m : %d",Pm,*Pm);
	*Pm=7;
	printf("\nAddress of m : %x \nValue of m : %d",Pm,*Pm);
	return EXIT_SUCCESS;

}
