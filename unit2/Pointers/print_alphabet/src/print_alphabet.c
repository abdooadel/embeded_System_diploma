/*
 ============================================================================
 Name        : print_alphabet.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	char alpha='A';
	char *Palpha=&alpha;
	int i=0;
	for(i='A';i<'Z';i++){
		printf("%c  ",*Palpha);
		(*Palpha)++;
	}
	return EXIT_SUCCESS;
}
