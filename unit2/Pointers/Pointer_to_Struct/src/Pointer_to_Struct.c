/*
 ============================================================================
 Name        : Pointer_to_Struct.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct Semployee_info{
	char name[20];
	int ID;
};
int main(void) {

	struct Semployee_info arr[10]={{"Alex",1002},{"Mohamed",1500}};
	struct Semployee_info *Parr=arr;
	printf("Exmployee Name : %s \nEmployee ID :%d",Parr->name,Parr->ID);
	Parr++;
	printf("\nExmployee Name : %s \nEmployee ID :%d",Parr->name,Parr->ID);
	return EXIT_SUCCESS;
}
