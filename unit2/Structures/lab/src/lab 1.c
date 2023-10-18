/*
 ============================================================================
 Name        : lab.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct SComplex
{
	double m_R;
	double m_I;
};
struct SComplex ReadComp(char name[]);
struct SComplex AddComp(struct SComplex, struct SComplex);
void PrintComp(char name[] ,struct SComplex);
int main(void) {
	struct SComplex num1,num2,result;
	num1=ReadComp("first number ");
	num2=ReadComp("second number ");
	
	result=AddComp(num1,num2);
	PrintComp("The result number is : ",result);


	return EXIT_SUCCESS;
}

struct SComplex ReadComp(char name[]){
	struct SComplex num1;
	printf("\nEnter %s real number ",name);
	fflush(stdin); fflush(stdout);
	scanf("%lf",&num1.m_R);
	printf("\nEnter %s imaginary number", name);
	fflush(stdin); fflush(stdout);
	scanf("%lf",&num1.m_I);
	return num1;
}

struct SComplex AddComp(struct SComplex num1, struct SComplex num2){
	struct SComplex result;
	result.m_I=num1.m_I+num2.m_I;
	result.m_R=num1.m_R+num2.m_R;
	return result;
}


void PrintComp(char name[] ,struct SComplex result){
	printf("%s  %.3lfi %.3lfj", name,result.m_R, result.m_R);
}









