/*
 ============================================================================
 Name        : reverse_string.c
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

	char str[50];
	char *Pstr=str;
	printf("Input a string: ");
	fflush(stdin); fflush(stdout);
	gets(str);
	printf("\nReverse of the string is :");
	int i;
	for(i=strlen(str)-1;i>=0;i--){
		Pstr=str+i;
		printf("%c",*Pstr);
		Pstr--;
	}

	return EXIT_SUCCESS;
}
