/*
 ============================================================================
 Name        : Ex8.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char text[50];
	printf("Enter a string");
	fflush(stdin); fflush(stdout);
	gets(text);
	printf("Reverse string is : ");
	for(int i=strlen(text);i !=0;i--)
	{
		printf("%c",text[i-1]);
	}
	return EXIT_SUCCESS;
}
