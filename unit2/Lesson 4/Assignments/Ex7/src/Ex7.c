/*
 ============================================================================
 Name        : Ex7.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char text[50];
	int i=0;
	printf("Enter a string");
	fflush(stdin); fflush(stdout);
	gets(text);
	for(i=0;i<100 && text[i] !=0;i++);
	printf("Length of string: %d",i);
	return EXIT_SUCCESS;
}
