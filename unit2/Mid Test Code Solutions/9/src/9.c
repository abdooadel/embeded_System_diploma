/*
 ============================================================================
 Name        : 9.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void revstr(char str[]);
int main(void) {
	char str[100];
	printf("Enter the name: ");
	fflush(stdin);
	fflush(stdout);
	gets(str);
	revstr(str);
	return EXIT_SUCCESS;
}

void revstr(char str[]){
	int i;
	for(i=0;i< strlen(str);i++){
		if (str[i]==' '){
			str[i]= '\0';
			break;
		}
	}
	for (i +=1 ;str[i];i++){
		printf("%c",str[i]);
	}
	printf(" %s",str);
}
