/*
 ============================================================================
 Name        : Lab3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int findName(char names[][14],int n, char name[] );
int main(void) {

	char name[14];
	char names[5][14] = {"Alaa", "Osama", "Mamdouh","Samy", "Hossain"};
	puts("Enter your first name:");
	fflush(stdout);
	gets(name);
	if(findName(names, 5, name)==1)
	puts("Welcome");
	else
	puts("Goodby");

}

int findName(char names[][14],int n,char name[] )
{
	for(int x=0; x<= n;x++){
		if( !strcmp(name,names[x]))
			return 1;
	}
		return 0;
}
