/*
 ============================================================================
 Name        : assignment2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Assignment 2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	// Ex1 check even or odd

		int x;
		printf("Enter an integer you want to check: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%d",&x);
		if(x%2==0)
			printf("%d is even",x);
		else
			printf("%d is odd",x);

	//Ex2 check vower or consonant

		char try;
		printf("\nEnter an alphabet: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%c",&try);
		if(try=='i' || try=='a' || try=='e' || try=='o' ||
			try=='I' || try=='A' || try=='E' || try=='O')
			printf("\n%c is a vowel",try);
		else
			printf("\n%c is a consonant",try);

	// Ex3  find biggest of three numbers
		float num1,num2,num3,big_num;
		printf("Enter three numbers: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%f %f %f",&num1,&num2,&num3);
		if(num1>num2 && num1>num3)
			big_num=num1;
		else if (num2>num1 &&num2>num3)
			big_num=num2;
		else
			big_num=num3;
		printf("Largest number = %f",big_num);


	//Ex5 check alphabet

		char alpha;
		printf("Enter a character: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%c",&alpha);
		if ((alpha >= 65 && alpha<91) || (alpha >= 97 && alpha< 122) )
			printf("%c is an alphabet",alpha);
		else
			printf("%c is not an alphabet",alpha);


	//
	//	//Ex6 sum of numbers
	//
		int n,summ;
		printf("Enter an integer: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%d",&n);
		for(int i=0;i<=n;i++)
		{
			summ+=i;
		}
		printf("Sum = %d",summ);



	//Ex8 Calculator

	char op;
	float n1,n2,num10=0;
	printf("Enter operator either + or - or * or divide : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%c",&op);
	printf("Enter two operands : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f %f",&n1,&n2);
	switch(op){
	case '+':
	{
		num10=n1+n2;
	}
	break;
	case '-':
	{
		num10=n1-n2;
	}
	break;
	case '*':
	{
		num10=n1*n2;
	}
	break;
	case '/':
	{
		num10=n1/n2;
	}
	break;
	default:
		printf("wrong input");
		break;

	}



	printf("%f %c %f = %f",n1,op,n2,num10);




	return 0;
}
