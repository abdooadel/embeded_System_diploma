/*
 * main.c
 *
 *  Created on: Oct 23, 2023
 *      Author: abdoo
 */

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define printD(...)  	{fflush(stdin);\
		fflush(stdout);\
		printf(__VA_ARGS__);\
		fflush(stdin);\
		fflush(stdout);}

struct SData{
	unsigned int ID;
	char name[40];
	float height;
};

struct SStudent{
	struct SData data;
	struct SStudent *PNextStudent;
};

struct SStudent *gpFirstStudent=NULL;

void add_student(void){
	char temp[40];
	struct SStudent *SNewStudent= NULL;
	struct SStudent *pCurrStudent= NULL;
	if (gpFirstStudent==NULL){
		SNewStudent= (struct SStudent*)malloc(sizeof(struct SStudent));

		gpFirstStudent=SNewStudent;

	}
	else
	{
		pCurrStudent=gpFirstStudent;
		while(pCurrStudent->PNextStudent)
			pCurrStudent=pCurrStudent->PNextStudent;
		SNewStudent= (struct SStudent*)malloc(sizeof(struct SStudent));
		pCurrStudent->PNextStudent=SNewStudent;
	}

	SNewStudent->PNextStudent=NULL;
	printD("\n  Enter student ID : ");
	gets(temp);
	SNewStudent->data.ID = atoi(temp);
	printD("\n  Enter student name : ");
	gets(SNewStudent->data.name);
	printD("\n  Enter student height : ");
	gets(temp);
	SNewStudent->data.height = atof(temp);


}

int delete_student(void){
	unsigned int ID;
	char temp[10];
	printD("\n Enter student ID to be deleted:");
	gets(temp);
	ID = atoi(temp);
	struct SStudent *PcurrStudent= NULL;
	struct SStudent *PPrevStudent= NULL;
	PcurrStudent= gpFirstStudent;
	while(PcurrStudent)
	{
		if(PcurrStudent->data.ID == ID){
			if (PcurrStudent->PNextStudent==NULL)
			{
				gpFirstStudent=NULL;
				free(PcurrStudent);
				return 1;
			}
			else
			{
				PPrevStudent->PNextStudent=PcurrStudent->PNextStudent;
				free(PcurrStudent);
				return 1;
			}

		}

		PPrevStudent=PcurrStudent;
		PcurrStudent=PcurrStudent->PNextStudent;

	}

	printD("\n Wrong ID number");
	return 0;

}

void view_students(void){
	unsigned int count=1;
	struct SStudent *PCurrentStudent= NULL;
	if(gpFirstStudent == NULL)
	{printD("\nList is empty");}

	else{
		PCurrentStudent=gpFirstStudent;
		while(PCurrentStudent){
			printD("\nPrinting Student number : %d",count);
			printD("\n\t student ID : %d",PCurrentStudent->data.ID);
			printD("\n\t student name : %s",PCurrentStudent->data.name);
			printD("\n\t student ID : %f",PCurrentStudent->data.height);
			PCurrentStudent=PCurrentStudent->PNextStudent;
			count++;
			printD("\n===================")
		}

	}
}

void delete_all(void){
	struct SStudent *PCurrentStudent= NULL;
	struct SStudent *temp= NULL;

	PCurrentStudent=gpFirstStudent;
	while(PCurrentStudent){
		temp=PCurrentStudent;
		PCurrentStudent=PCurrentStudent->PNextStudent;
		free(temp);
		gpFirstStudent = NULL;
	}

}


void print_back(){
	struct SStudent *Pfirst;
	struct SStudent *Psec;
	int index,i;
	printD("Enter the index");
	scanf("%d",&index);
	Pfirst= gpFirstStudent;
	Psec=gpFirstStudent;
	for(i=0;i<index;i++){
		Psec=Psec->PNextStudent;
	}
	while(Psec->PNextStudent)
	{
		Pfirst=Pfirst->PNextStudent;
		Psec=Psec->PNextStudent;
	}
	printD("\n\t student ID : %d",Pfirst->data.ID);
	printD("\n\t student name : %s",Pfirst->data.name);
	printD("\n\t student ID : %f",Pfirst->data.height);
	printD("\n===================")

}

void reverse(){
	struct SStudent *PcurrStudent=NULL;
	struct SStudent *pNextStudent=NULL;
	struct SStudent *PPrev=NULL;

	PcurrStudent=gpFirstStudent;

	while(PcurrStudent != NULL)

	{
		pNextStudent=PcurrStudent->PNextStudent;
		PcurrStudent->PNextStudent=PPrev;
		PPrev=PcurrStudent;
		PcurrStudent=pNextStudent;



	}
	gpFirstStudent=PPrev;
	view_students();


}

void print_mid(void){
	struct SStudent *Pspeed;
	struct SStudent *Pslow;
	Pslow= gpFirstStudent;
	Pspeed=gpFirstStudent;
	while (Pspeed->PNextStudent)
	{
		Pslow=Pslow->PNextStudent;
		Pspeed=Pspeed->PNextStudent;
		if(Pspeed->PNextStudent != NULL)
			Pspeed=Pspeed->PNextStudent;
		else
			break;

	}
	printD("\n\t student ID : %d",Pslow->data.ID);
	printD("\n\t student name : %s",Pslow->data.name);
	printD("\n\t student ID : %f",Pslow->data.height);
	printD("\n===================");
}


void main(){
	int choice;

	while(1){
		printD("\n\t\t Choose on of the following options  \n\n 1: Add student \n 2: Delete student \n 3: View students \n 4: Delete all \n 5: Print student index from list end  \n 6: reverse list alignment \n 7: print the middle who is in the middle of the list ");
		printD("\n===================")
		printD("\n\n Enter Option Number : ");
		scanf("%d",&choice);
		switch(choice){
		case 1:
			add_student();
			break;
		case 2:
			delete_student();
			break;
		case 3:
			view_students();
			break;
		case 4:
			delete_all();
			break;
		case 5:
			print_back();
			break;
		case 6:
			reverse();
			break;
		case 7:
			print_mid();
			break;
		default:
			printD("Wrong Choice");
			break;
		}


	}

}


