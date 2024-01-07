#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
COORD coord={0,0};
struct emp
	{
		int ID;
		char name[30];
		char gender;
		int age;
		int salary;
		char designation[20];
		char address[100];
		char martial_status;
		char d_o_b[15];
		char CNIC_NO[15];
		int attendance;
	};
int getche(void);
int welcome_screen(void);
int password_screen(void);
int notification(void);
void salary(void);
void about(void);
void add_record(FILE *fp);
void view_record(FILE *fp);
void menu_screen(FILE *fp);
void salary(void);
void gotoxy(int x,int y);
void salary(void);

int main() 
{
    int login,password;
    login=welcome_screen();
    password=password_screen();

	FILE *fp,*ft;
	char another,choice;

	struct emp e;
	char id;
	fp = fopen("EMPLOYEE.DAT", "rb+");
	if (fp == NULL)
	{
		fp = fopen("EMPLOYEE1.DAT", "wb+");
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
void gotoxy(int x,int y)
{
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void menu_screen(FILE *fp)
{
    char another, choice;
    while (1)
    {
        system("cls\n");
        gotoxy(90,15);
        printf(" MAIN MENU");
        gotoxy(90,20);
        printf("1-VIEW RECORD\n");
        gotoxy(90,22);
        printf("2-ADD RECORD\n");
        gotoxy(90,24);
        printf("3-EDIT RECORD\n");
        gotoxy(90,26);
        printf("4-DELETE RECORD\n");
        gotoxy(90,28);
        printf("5-SEARCH RECORD\n");
        gotoxy(90,30);
        printf("6-ATTENDANCE\n");
        gotoxy(90,32);
        printf("7-SALARY\n");
        gotoxy(90,34);
        printf("8-NOTIFICATIONS\n");
        gotoxy(90,36);
        printf("9-ABOUT\n");
        gotoxy(90,38);
        printf("0-EXIT");
        fflush(stdin);
        gotoxy(90,40);
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
        	edit_record(fp);
        	break;
        case '4' :
        	delete_record(fp);
        	break;
        case '5' :
        	search_record(fp);
        	break;	
        case '6' :
        	//edit_record();
        	break;	
        case '7' :
        	salary();	        	
        	break;
        case '8' :
        	notification();
        	break;
        case '9' :
        	about();
        	break;
        case '0':
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
        printf("Salary: %d\n", e.salary);
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
		scanf("%d",&e.salary);
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
int welcome_screen(void)
{
    char login;
	system("cls");
	gotoxy(80,18);
	printf("______________");
	gotoxy(88,20);
	printf("EMPLOYEE MANAGEMENT SYSTEM");
	gotoxy(80,22);
	printf("______________");	
    printf("\n\n \t\t\t \t\t\t\t\t\t\t Enter L/l to login and any key to exit:");
    login=getche();
    if(login=='L'||login=='l')
    {
        return 1;
    }
    else
    exit(0);
}
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
int password_screen(void)
{
	system("cls");
	gotoxy(80,15);
	char password[10]="employee";
	char password1[10];
	char key[15]="thisisakey??";
	char key1[15];
	char new;
	printf("\n \t\t\t \t\t\t\t\t\t\t Enter the 8 digit password to enter:");
	scanf("%s",password1);
	if(strcmp(password,password1)==0)
	{
		return 1;
	}
	else
	{
		while (strcmp(password,password1)!=0)
		{
		printf("\n \t\t\t \t\t\t\t\t\t\t Wrong password");
		printf("\n \t\t\t \t\t\t\t\t\t\t Forgot your password? Enter F/f to enter the key:");
		printf("\n \t\t\t \t\t\t\t\t\t\t To re-enter the password press r/R:");
		new=getche();
		switch(new)
		{
			case 'r':
			case 'R':
					printf("\n \t\t\t \t\t\t\t\t\t\t Enter the 8 digit password to enter:");
					scanf("%s",password1);
                    if(strcmp(password,password1)!=0)
                    {
                        printf("\n \t\t\t \t\t\t\t\t\t\t Wrong password");
                        password_screen();
                    }
					break;
			case 'f':
			case 'F':
					printf("\n \t\t\t \t\t\t\t\t\t\t Enter the 12 digit key to change the password:");
					scanf("%s",key1);
					if(strcmp(key,key1)==0)
					{
						return 1;
					}	
					else
					{
						printf("\n \t\t\t \t\t\t\t\t\t\t Ask your administrator for the valid key");
						exit(0);
					}
		}
		return 1;	
		}
	}

}
void salary(void)
{
    system("cls");
	char ch;
    float basic_salary;
    float total_salary;
    float allowances;
    int hours_worked;

    printf("\nEnter employee basic salary: ");
    scanf("%f", &basic_salary);

    printf("\nEnter employee allowances: ");
    scanf("%f", &allowances);

    printf("\nEnter hours worked by the employee: ");
    scanf("%d", &hours_worked);

    const float TAX_RATE = 0.1;
    const float OVERTIME_PAY_RATE = 1.5;
    float hourlyRate = basic_salary / 160; // Assuming 160 hours in a month (40 hours per week for 4 weeks)
    float regularPay = hours_worked <= 160 ? hours_worked * hourlyRate : 160 * hourlyRate;
    float overtimePay = hours_worked > 160 ? (hours_worked - 160) * OVERTIME_PAY_RATE * hourlyRate : 0;

    float totalSalary = regularPay + overtimePay + allowances;
    float taxAmount = totalSalary * TAX_RATE;

    total_salary=totalSalary - taxAmount;
    printf("\nTotal Salary (after tax): %.2f\n", total_salary);
    printf("\nDo you want to calculate the salary of another employee: ");
    ch=getche();
    if(ch=='y'||ch=='Y')
	salary();
	else
    return 0;
}