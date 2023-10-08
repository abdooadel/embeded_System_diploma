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
#include <string.h>

void print_backword(char string[],int len);

int main(void) {
	char string[100];
	printf("Enter a sentence: ");
	fflush(stdin); fflush(stdout);
	gets(string);
	print_backword(string, strlen(string)-1);
	return EXIT_SUCCESS;
}

void print_backword(char string[],int len){
	printf("%c" , string[len]);
	len--;
	if(len >=0)
		print_backword(string,len);
}
