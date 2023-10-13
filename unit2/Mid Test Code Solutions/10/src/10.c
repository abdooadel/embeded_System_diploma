/*
 ============================================================================
 Name        : 10.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int count (int);
int main(void) {
	int num;
		printf("Enter the number : ");
		fflush(stdout);
		scanf("%d",&num);
		printf("max number of ones is : %d", count(num));
	return EXIT_SUCCESS;
}

int count (int num){
	int arr[16];
	int count1=0,count2=0,i,x;
	for(i=0;num;num /=2,i++)
	{
		if (num%2 ==0)
			arr[i]=0;
		else
			arr[i]=1;
	}
	arr[i]=0;
	for(x=i;x>0;x--){
		if(arr[x]==0 && arr[x-1]==1)
		{
			count1=1;
			x--;
		}
		while(arr[x]==1 && arr[x-1]==1){
			count1++;
			x--;
		}
		if (count1>count2)
			count2=count1;
	}




	return count2;
}
