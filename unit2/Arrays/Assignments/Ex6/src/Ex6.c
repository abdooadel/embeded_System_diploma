/*
 ============================================================================
 Name        : Ex6.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char text[100],x,counter=0;
	printf("Enter a string : ");
	fflush(stdin); fflush(stdout);
	gets(text);
	printf("Enter a character to find frequency: ");
	fflush(stdin); fflush(stdout);
	scanf("%c",&x);
	for(int i=0;i<100;i++)
	{
		if(text[i]==0)
			break;
		if(text[i]==x)
			counter++;
	}
	printf("Frequency of %c = %d",x,counter);
	return EXIT_SUCCESS;
}
