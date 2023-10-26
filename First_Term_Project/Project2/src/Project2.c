/*
 ============================================================================
 Name        : Project2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define printD(...)  	{fflush(stdin);\
		fflush(stdout);\
		printf(__VA_ARGS__);\
		fflush(stdin);\
		fflush(stdout);}


struct Sinfo{
	char fname[40];
	char lname[40];
	int roll;
	float GPA;
	int cid[10];
}st[55];

struct SStudent{
	struct Sinfo data;
	struct SStudent *PNextStudent;
};

struct SStudent *gpFirstStudent=NULL;
int Gcount=0;


void add_student_manualy(void){
	char temp[40];
	int check, flag=0;
	struct SStudent *SNewStudent= NULL;
	struct SStudent *pCurrStudent= NULL;
	struct SStudent *pCheck= NULL;

	if (gpFirstStudent==NULL){
		SNewStudent= (struct SStudent*)malloc(sizeof(struct SStudent));

		gpFirstStudent=SNewStudent;
		flag=2;
		Gcount++;
	}
	else
	{
		pCurrStudent=gpFirstStudent;
		while(pCurrStudent->PNextStudent)
			pCurrStudent=pCurrStudent->PNextStudent;
		SNewStudent= (struct SStudent*)malloc(sizeof(struct SStudent));
		pCurrStudent->PNextStudent=SNewStudent;
		Gcount++;
	}

	printD("\n-------------------------- ");
	printD("\nAdd the Student Details ");
	printD("\n-------------------------- ");
	printD("\nEnter the Roll Number : ");
	gets(temp);
	check= atoi(temp);
	pCheck=gpFirstStudent;
	if (flag !=2)
	{
		while(pCheck->PNextStudent)
		{
			if(check==pCheck->data.roll)
			{
				flag=1;
				break;
			}
			pCheck=pCheck->PNextStudent;

		}
	}
	if (flag==1)
	{
		printD("\n[ERROR] Roll Number %d is already taken.",check);
		printD("\n-------------------------------------------");
		free(SNewStudent);
		pCurrStudent->PNextStudent=NULL;
	}
	else
	{


		SNewStudent->data.roll = atoi(temp);
		printD("\nEnter the first name of the student: ");
		gets(SNewStudent->data.fname);
		printD("\nEnter the last name of the student: ");
		gets(SNewStudent->data.lname);
		printD("\nEnter the GPA you obtained: ");
		gets(temp);
		SNewStudent->data.GPA= atof(temp);
		printD("\nEnter the Course ID of each course");
		for(int i=0;i<5;i++){
			printD("\nCourse %d id: ",i+1);
			gets(temp);
			SNewStudent->data.cid[i]= atof(temp);



		}


		SNewStudent->PNextStudent=NULL;
		printD("\n[INFO] Student Details is Added Successfully");
		printD("\n-------------------------------------------\n");
	}

}

void deleteStr(char str[]){
	for(int i=0; i<40;i++){
		str[i]='\0';
	}
}

void add_student_file(){

	int check, flag=0, flagOut=0;
	struct SStudent *SNewStudent= NULL;
	struct SStudent *pCurrStudent= NULL;
	struct SStudent *pCheck= NULL;

	if (gpFirstStudent==NULL){
		SNewStudent= (struct SStudent*)malloc(sizeof(struct SStudent));
		gpFirstStudent=SNewStudent;
		flag=2;
	}
	else
	{
		pCurrStudent=gpFirstStudent;
		while(pCurrStudent->PNextStudent)
			pCurrStudent=pCurrStudent->PNextStudent;
		SNewStudent= (struct SStudent*)malloc(sizeof(struct SStudent));
		pCurrStudent->PNextStudent=SNewStudent;
	}





	char *filename = "readme.txt";
	FILE *fp = fopen(filename, "r");
	char ch;
	int count=0,count_subj=0;
	char str[40]={'\0'};
	int i=0;
	int arr_count=0;
	while ((ch = fgetc(fp)) != EOF)
	{
		if(ch=='\n'){
			arr_count++;
			i=0;
			count=0;
			deleteStr(str);
			count_subj=0;
			if (flag==1)
			{
				printD("\n[ERROR] Roll Number %d is already taken.",check);
				printD("\n-------------------------------------------");
				pCurrStudent->PNextStudent=NULL;
				free(SNewStudent);
				flag=0;
				flagOut=0;
			}
			else{
				SNewStudent->PNextStudent=NULL;
				flag=0;
				printD("\n[INFO] Roll Number %d saved Successfully",check);
				printD("\n-------------------------------------------\n");
				Gcount++;
			}

			SNewStudent= (struct SStudent*)malloc(sizeof(struct SStudent));
			pCurrStudent=gpFirstStudent;
			while(pCurrStudent->PNextStudent)
				pCurrStudent=pCurrStudent->PNextStudent;
			pCurrStudent->PNextStudent=SNewStudent;
		}
		if(ch==' '){
			switch (count){

			case 0:
				check= atoi(str);
				pCheck=gpFirstStudent;
				if (flag !=2)
				{
					while(pCheck)
					{
						if(check==pCheck->data.roll)
						{
							flag=1;
							flagOut=1;
							break;
						}
						pCheck=pCheck->PNextStudent;
					}
				}
				SNewStudent->data.roll=check;
				break;
			case 1:
				SNewStudent->data.GPA=atof(str);
				break;
			case 2:
				strcpy(SNewStudent->data.fname,str);
				break;
			case 3:
				strcpy(SNewStudent->data.lname,str);
				break;

			}
			if(count>3){
				switch (count_subj){

				case 0:
					SNewStudent->data.cid[0]=atoi(str);
					count_subj++;
					break;
				case 1:
					SNewStudent->data.cid[1]=atoi(str);
					count_subj++;
					break;

				case 2:
					SNewStudent->data.cid[2]=atoi(str);
					count_subj++;
					break;
				case 3:
					SNewStudent->data.cid[3]=atoi(str);
					count_subj++;
					break;
				case 4:
					SNewStudent->data.cid[4]=atoi(str);
					count_subj++;
					break;

				}
			}
			i=0;
			count++;
			deleteStr(str);
			continue;
		}
		str[i]=ch;
		i++;


	}
	if (flagOut==1)
	{
		printD("\n[ERROR] Roll Number %d is already taken.",check);
		printD("\n-------------------------------------------");
		pCurrStudent->PNextStudent=NULL;
		free(SNewStudent);
		flag=0;
	}
	else{
		SNewStudent->PNextStudent=NULL;
		printD("\n[INFO] Roll Number %d saved Successfully",check);
		printD("\n-------------------------------------------\n");
		Gcount++;
	}



}

int del_s(void){
	unsigned int ID;
	char temp[10];
	printD("\n Enter the Roll Number you want to delete:");
	gets(temp);
	ID = atoi(temp);
	struct SStudent *PcurrStudent= NULL;
	struct SStudent *PPrevStudent= NULL;
	PcurrStudent= gpFirstStudent;
	PPrevStudent=gpFirstStudent;

	if (PcurrStudent->PNextStudent==NULL && PcurrStudent->data.roll == ID)
	{
		gpFirstStudent=NULL;
		free(PcurrStudent);
		printD("\n[ERROR] Roll Number is removed Successfully");
		printD("\n-------------------------------------------");
		Gcount--;
		return 1;
	}

	while(PcurrStudent)
	{
		if(PcurrStudent->data.roll == ID){

			PPrevStudent->PNextStudent=PcurrStudent->PNextStudent;
			free(PcurrStudent);
			printD("\n[INFO] Roll Number is removed Successfully");
			printD("\n-------------------------------------------");
			Gcount--;
			return 1;


		}

		PPrevStudent=PcurrStudent;
		PcurrStudent=PcurrStudent->PNextStudent;

	}

	printD("\n[ERROR] Roll Number %d not found",ID);
	printD("\n-------------------------------------------");
	return 0;

}

void show_all(void){
	struct SStudent *PcurrStudent= NULL;
	if(gpFirstStudent == NULL)
	{printD("\n[INFO] List is empty");
	printD("\n-------------------------------------------");

	}

	else{
		PcurrStudent=gpFirstStudent;
		while(PcurrStudent){
			printD("\nThe Student Details are:");
			printD("\nThe Student Roll Number is %d",PcurrStudent->data.roll);
			printD("\nThe First Name is %s",PcurrStudent->data.fname);
			printD("\nThe Last Name is %s",PcurrStudent->data.lname);
			printD("\nThe GPA is %.3f",PcurrStudent->data.GPA);
			printD("\nThe Registered Courses are:");
			for(int i=0;i<5;i++){
				printD("\nThe course ID is %d ",PcurrStudent->data.cid[i]);
			}
			printD("\n-----------------------------------------------");
			PcurrStudent=PcurrStudent->PNextStudent;
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
	printD("\n[INFO] All Data Deleted");
	printD("\n-------------------------------------------");


}



void find_rl(){

	unsigned int roll_num;
	char temp[10];
	printD("\n Enter the Roll Number of the Student: ");
	gets(temp);
	roll_num = atoi(temp);
	struct SStudent *PcurrStudent= NULL;
	PcurrStudent= gpFirstStudent;
	if (gpFirstStudent==NULL)
	{
		printD("\n[ERROR] The Students List is EMPTY.");
		printD("\n-------------------------------------------");
		return;
	}
	else if (gpFirstStudent->PNextStudent==NULL)
	{
		if(PcurrStudent->data.roll == roll_num){
			printD("\nThe Student Details are:");
			printD("\nThe First Name is %s",PcurrStudent->data.fname);
			printD("\nThe Last Name is %s",PcurrStudent->data.lname);
			printD("\nThe GPA is %.3f",PcurrStudent->data.GPA);
			printD("\nThe Registered Courses are:");
			for(int i=0;i<5;i++){
				printD("\nThe course ID is %d ",PcurrStudent->data.cid[i]);
			}
			printD("\n-----------------------------------------------");
			return;
		}
	}
	else

	{

		while(PcurrStudent)
		{
			if(PcurrStudent->data.roll == roll_num){
				printD("\nThe Student Details are:");
				printD("\nThe First Name is %s",PcurrStudent->data.fname);
				printD("\nThe Last Name is %s",PcurrStudent->data.lname);
				printD("\nThe GPA is %.3f",PcurrStudent->data.GPA);
				printD("\nThe Registered Courses are:");
				for(int i=0;i<5;i++){
					printD("\nThe course ID is %d ",PcurrStudent->data.cid[i]);
				}
				printD("\n-----------------------------------------------");
				return;
			}
			PcurrStudent=PcurrStudent->PNextStudent;
		}


	}

	printD("\n[ERROR] Roll Number %d not found",roll_num);
	printD("\n-------------------------------------------");

	return ;

}


void find_fn(){
	int flag=0;
	char name[40];

	printD("\n Enter First Name of the Student: ");
	gets(name);
	struct SStudent *PcurrStudent= NULL;
	PcurrStudent= gpFirstStudent;
	if (gpFirstStudent==NULL)
	{
		printD("\n[ERROR] The Students List is EMPTY.");
		printD("\n-------------------------------------------");
		return;
	}
	else if (gpFirstStudent->PNextStudent==NULL)
	{
		if(!strcmp(PcurrStudent->data.fname,name )){
			printD("\nThe Student Details are:");
			printD("\nThe First Name is %s",PcurrStudent->data.fname);
			printD("\nThe Last Name is %s",PcurrStudent->data.lname);
			printD("\nThe GPA is %.3f",PcurrStudent->data.GPA);
			printD("\nThe Registered Courses are:");
			for(int i=0;i<5;i++){
				printD("\nThe course ID is %d ",PcurrStudent->data.cid[i]);
			}
			printD("\n-----------------------------------------------");
			return;
		}
	}
	else

	{

		while(PcurrStudent)
		{
			if(!strcmp(PcurrStudent->data.fname,name )){
				printD("\nThe Student Details are:");
				printD("\nThe First Name is %s",PcurrStudent->data.fname);
				printD("\nThe Last Name is %s",PcurrStudent->data.lname);
				printD("\nThe GPA is %.3f",PcurrStudent->data.GPA);
				printD("\nThe Registered Courses are:");
				for(int i=0;i<5;i++){
					printD("\nThe course ID is %d ",PcurrStudent->data.cid[i]);
				}
				printD("\n-----------------------------------------------");
				flag=1;
			}
			PcurrStudent=PcurrStudent->PNextStudent;
		}


	}
	if(!flag){


		printD("\n[ERROR] First Name %s not found",name);
		printD("\n-------------------------------------------");
		return ;
	}

}
void find_c(){
	int cID,count=0;
	char temp[10];


	printD("\n Enter the course ID: ");
	gets(temp);
	cID= atoi(temp);
	struct SStudent *PcurrStudent= NULL;
	PcurrStudent= gpFirstStudent;
	if (gpFirstStudent==NULL)
	{
		printD("\n[ERROR] The Students List is EMPTY.");
		printD("\n-------------------------------------------");
		return;
	}
	else if (gpFirstStudent->PNextStudent==NULL)
	{
		for(int i=0;i<5;i++)
		{
			if(PcurrStudent->data.cid[i]==cID)
			{
				printD("\nThe Student Details are:");
				printD("\nThe First Name is %s",PcurrStudent->data.fname);
				printD("\nThe Last Name is %s",PcurrStudent->data.lname);
				printD("\nThe GPA is %.3f",PcurrStudent->data.GPA);
				printD("\n-----------------------------------------------");
				return;
			}
		}

	}
	else

	{

		while(PcurrStudent)
		{
			for(int i=0;i<5;i++)
			{
				if(PcurrStudent->data.cid[i]==cID)
				{
					printD("\nThe Student Details are:");
					printD("\nThe First Name is %s",PcurrStudent->data.fname);
					printD("\nThe Last Name is %s",PcurrStudent->data.lname);
					printD("\nThe GPA is %.3f",PcurrStudent->data.GPA);
					printD("\n-----------------------------------------------");
					count++;
					break;
				}
			}
			PcurrStudent=PcurrStudent->PNextStudent;
		}


	}
	if(count ==0)
	{


		printD("\n[ERROR] Course ID %d not found",cID);
		printD("\n-------------------------------------------");
		return ;
	}
	else{
		printD("\n[INFO] Total Number of Students Enrolled: %d",count);
		printD("\n-----------------------------------------------");

	}
}

void tot_s(){
	printD("\n[INFO] The total Number of Students is %d",Gcount);
	printD("\n[INFO] You can add up to 50 Students");
	printD("\n[INFO] You can add %d more Students",(50-Gcount));
	printD("\n-----------------------------------------------");




}

void update_s(){
	char temp[40];
	int check,choice;
	struct SStudent *pCurrStudent= NULL;
	struct SStudent *pCheck= gpFirstStudent;
	pCurrStudent=gpFirstStudent;
	printD("\n-------------------------- ");
	printD("\nEnter the Roll Number to update the entry ");
	gets(temp);
	check= atoi(temp);
	while(pCurrStudent){
		if(check==pCurrStudent->data.roll)
		{
			printD("\nEnter which info you want to update: ");
			printD("\n1. first name ");
			printD("\n2. last name ");
			printD("\n3. Roll Number ");
			printD("\n4. GPA ");
			printD("\n5. Courses ");
			gets(temp);
			choice= atoi(temp);
			switch(choice){
			case 1:
				printD("Enter the New First Name ");
				gets(pCurrStudent->data.fname);
				break;
			case 2:
				printD("Enter the New Last Name ");
				gets(pCurrStudent->data.lname);
				break;
			case 3:
				printD("Enter the New Roll Number ");
				gets(temp);
				check=atoi(temp);
				while(pCheck->PNextStudent)
				{
					if(check==pCheck->data.roll)
					{
						printD("\n[ERROR] Roll Number %d is already taken.",check);
						printD("\n-------------------------------------------");
						return;
					}
					pCheck=pCheck->PNextStudent;

				}
				pCurrStudent->data.roll = atoi(temp);
				break;
			case 4:
				printD("Enter the New GPA ");
				gets(temp);
				pCurrStudent->data.GPA = atof(temp);
				break;
			case 5:
				printD("Enter the New courses ");
				for(int i=0;i<5;i++){
					printD("\nCourse %d id: ",i+1);
					gets(temp);
					pCurrStudent->data.cid[i]= atof(temp);
				}
				break;
			}

			printD("\n[INFO] UPDATED SUCCESSFULLY");
			printD("\n-------------------------------------------");
			return;
		}
		pCurrStudent=pCurrStudent->PNextStudent;
	}


	printD("\n[ERROR] Roll Number %d not found",check);
	printD("\n-------------------------------------------");









}



void main(){
	int choice;
	printD("\nWelcome to the Student Management System");
	while(1){
		printD("\nChoose The Task that you want to perform\n");
		printD("1.  Add the Student Details Manually\n");
		printD("2.  Add the Student Details From Text File\n");
		printD("3.  Find the Student Details by Roll Number\n");
		printD("4.  Find the Student Details by Course ID\n");
		printD("5.  Find the Student Details by First Name\n");
		printD("6.  Find the Total Number of Students\n");
		printD("7.  Delete the Student Details by Roll Number\n");
		printD("8.  Update the Student Details by Roll Number\n");
		printD("9.  Show all information\n");
		printD("10. Delete all information\n");
		printD("11. To Exit");
		printD("\n====================================================")
		printD("\n\n Enter your Choice to perform the task : ");

		scanf("%d",&choice);
		switch(choice){
		case 1:
			add_student_manualy();
			break;
		case 2:
			add_student_file();
			break;
		case 3:
			find_rl();
			break;
		case 4:
			find_c();
			break;
		case 5:
			find_fn();
			break;
		case 6:
			tot_s();
			break;
		case 7:
			del_s();
			break;
		case 8:
			update_s();
			break;
		case 9:
			show_all();
			break;
		case 10:
			delete_all();
			break;
		case 11:
			exit(1);
			break;
		default:
			printD("Wrong Choice\n");
			break;
		}


	}

}


