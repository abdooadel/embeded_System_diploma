/*
 ============================================================================
 Name        : try.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	unsigned short myfunc(unsigned short num)
	{
		static unsigned short new=0;
		int rem;
		if(num != 0){
			rem =num %10;
			new +=rem;
			myfunc (num/10);
		}
		else
			return 0;
		return new;
	}

int main(void) {

	unsigned short num=12345;
	printf("%hu ", myfunc(num));
	return 0 ;



	return EXIT_SUCCESS;
}
