#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
struct emp
	{
		int ID;
		char name[30];
		char gender;
		int age;
		float salary;
		char designation[20];
		char address[100];
		char martial_status;
		char d_o_b[15];
		char CNIC_NO[15];
		int attendance;
	};
void add_record(FILE *fp);
void view_record(FILE *fp);
void menu_screen(FILE *fp);
int main() 
{
	FILE *fp,*ft;
	char another,choice;
	
	struct emp e;
	char id;
	fp = fopen("EMPLOYEE.DAT", "rb+");
	if (fp == NULL)
	{
		fp = fopen("EMPLOYEE.DAT", "wb+");
		if (fp == NULL)
		{
    	printf("can not open file");
    	exit (1);
    	}
	}
	menu_screen(fp);
	fclose(fp);
	return 0;
}

void menu_screen(FILE *fp)
{
    char another, choice;
    while (1)
    {
        system("cls\n");
        printf("1-VIEW RECORD\n");
        printf("2-ADD RECORD\n");
        printf("3-EDIT RECORD\n");
        printf("4-DELETE RECORD\n");
        printf("5-ATTENDANCE\n");
        printf("6-SALARY\n");
        printf("7-NOTIFICATIONS\n");
        printf("8-ABOUT\n");
        printf("9-EXIT");
        fflush(stdin);
        printf("\nEnter your choice: ");
        choice = getche();
        switch (choice)
        {
        case '1':
            view_record(fp);
            break;
        case '2':
            add_record(fp);
            break;
        case '3' :
        	//edit_record();
        	break;
        case '4' :
        	//delete_record();
        	break;
        case '5' :
        	//edit_record();
        	break;	
        case '6' :
        	//edit_record();
        	break;	
        case '7' :
        	//edit_record();	        	
        	break;
        case '8' :
        	//edit_record();
        	break;
        case '9':
            exit(0);
            break;
        }
    }
}
void view_record(FILE *fp)
{
    system("cls");
    struct emp e;
    rewind(fp);
    while (fread(&e, sizeof(struct emp), 1, fp) == 1)
    {
        printf("ID: %d\n", e.ID);
        printf("Name: %s\n", e.name);
        printf("Gender: %c\n", e.gender);
        printf("Age: %d\n", e.age);
        printf("Salary: %f\n", e.salary);
        printf("Designation: %s\n", e.designation);
        printf("Address: %s\n", e.address);
        printf("Marital Status: %c\n", e.martial_status);
        printf("Date of Birth: %s\n", e.d_o_b);
        printf("CNIC No.: %s\n", e.CNIC_NO);
        printf("Attendance: %d\n", e.attendance);

        printf("\n------------------------\n");
    }
    getch();
}
void add_record(FILE *fp)
{
	system("cls");
	struct emp e;
	fseek(fp,0,SEEK_END);
	char another='y';
	while(another=='y')
	{
		printf("\nEnter the ID: ");
		scanf("%d",&e.ID);
		printf("\nEnter the name: ");
		scanf("%s",&e.name);
		printf("\nEnter the gender: ");
		scanf(" %c",&e.gender);
		printf("\nEnter the age: ");
		scanf("%d",&e.age);	
		printf("\nEnter the salary: ");
		scanf("%f",&e.salary);
		printf("\nEnter the designation: ");
		scanf("%s",&e.designation);
		printf("\nEnter the address: ");
		scanf("%s",&e.address);
		printf("\nEnter the martial status: ");
		scanf(" %c",&e.martial_status);
		printf("\nEnter the date of birth: ");
		scanf("%s",&e.d_o_b);
		printf("\nEnter the CNIC No.: ");
		scanf("%s",&e.CNIC_NO);
		printf("\nEnter the attendance: ");
		scanf("%d",&e.attendance);	
		fwrite(&e,sizeof(struct emp),1,fp);
		printf("\nDo you want to add another record? (y/n): ");
		fflush(stdin);
		another=getchar();	
	}
		
}



