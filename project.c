#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#define ANSI_COLOR_BLUE     "\x1b[34m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_BOLD    "\x1b[1m"
#define ANSI_COLOR_RESET   "\x1b[0m"
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
    typedef struct
     {
        int empID;
        char notification[100];  // Assuming a maximum of 100 characters for notifications
    } Employee;
int getche(void);
int welcome_screen(void);
int password_screen(void);
int notification(void);
void salary_calculator(void);
void about(void);
void attendance(FILE *fp);
void add_record(FILE *fp);
void view_record(FILE *fp);
void menu_screen(FILE *fp);
void search_record(FILE *fp);
void delete_record(FILE *fp);
void edit_record(FILE *fp);
void gotoxy(int x,int y);
int openFileWithOptions(void);
int main() 
{
    int login,password;
    login=welcome_screen();
    password=password_screen();

	FILE *fp,*ft;
	char another,choice;

	struct emp e;
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
        printf("\033[32m");
        system("cls\n");
        gotoxy(80,15);
        printf(" MAIN MENU");
        printf("\033[0m");
        gotoxy(80,20);
        printf("1-VIEW RECORD\n");
        gotoxy(80,22);
        printf("2-ADD RECORD\n");
        gotoxy(80,24);
        printf("3-EDIT RECORD\n");
        gotoxy(80,26);
        printf("4-DELETE RECORD\n");
        gotoxy(80,28);
        printf("5-SEARCH RECORD\n");
        gotoxy(80,30);
        printf("6-ATTENDANCE\n");
        gotoxy(80,32);
        printf("7-SALARY CALCULATOR\n");
        gotoxy(80,34);
        printf("8-NOTIFICATIONS\n");
        gotoxy(80,36);
        printf("9-ABOUT\n");
        gotoxy(80,38);
        printf("0-EXIT");
        fflush(stdin);
        gotoxy(80,40);
        printf("\n\t\t\t \t\t\t\t\t\t\tEnter your choice: ");
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
        	attendance(fp);
        	break;	
        case '7' :
        	salary_calculator();	        	
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
	printf("____________________________________");
	gotoxy(86,20);
	printf("%s%sEMPLOYEE MANAGEMENT SYSTEM%s",ANSI_COLOR_BLUE,ANSI_COLOR_BOLD,ANSI_COLOR_RESET);
	gotoxy(80,22);
	printf("____________________________________");	
    printf("\n\n\t\t\t\t\t\t\t\t\t\tEnter L/l to login and any key to exit:");
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
		printf("\n \t\t\t \t\t\t\t\t\t\t%s Wrong password%s",ANSI_COLOR_RED,ANSI_COLOR_RESET);
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
                        printf("\n \t\t\t \t\t\t\t\t\t\t%s Wrong password%s",ANSI_COLOR_RED,ANSI_COLOR_RESET);
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
void salary_calculator(void)
{
    system("cls");
	char ch;
    float basic_salary;
    float total_salary;
    float allowances;
    int hours_worked;
    printf("\n\n \t\t\t \t\t\t\t\t\t\t SALARY CALCULATOR");
    printf("\nAccording to the companies policy following things are calculated.");
    printf("\nOn each salary there is a 10\% tax deduction.");
    printf("\nAccording to overtime rules employee will get 50\% extra on each hour worked.");
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
	salary_calculator();
}
void edit_record(FILE *fp) {
    system("cls");
    struct emp e;
    char another = 'y';
    int emp_id, op;

    while (another == 'y') {
        printf("\nEnter employee id to modify:\n");
        scanf("%d", &emp_id);
        rewind(fp);

        while (fread(&e, sizeof(struct emp), 1, fp) == 1) {
            if (emp_id == e.ID) {
                printf("\nWhat do you want to edit:\n");
                printf("1.ID\n2.Name\n3.Gender\n4.Age\n5.Salary\n6.Designation\n7.Address\n8.Marital Status\n9.Date of Birth\n10.CNIC\n11.Attendance\n");
                scanf("%d", &op);

                switch (op) {
                    case 1:
                        printf("Enter new ID: ");
                        scanf("%d", &e.ID);
                        break;
                    case 2:
                        printf("Enter new name: ");
                        fflush(stdin);
                        // Clear input buffer 
                        scanf("%s",&e.name);
                        break;
                    case 3:
                        printf("Enter new gender: ");
                        fflush(stdin);
                        scanf("%c",&e.gender);
                        break;
                        case 4:
                        printf("Enter new age: ");
                        fflush(stdin);
                        scanf("%d",&e.age);
                        break;
                        case 5:
                        printf("Enter new salary: ");
                        fflush(stdin);
                        scanf("%f",&e.salary);
                        break;
                        case 6:
                        printf("Enter new designation: ");
                        fflush(stdin);
                        scanf("%s",&e.designation);
                        break;
                        case 7:
                        printf("Enter new address: ");
                        fflush(stdin);
                        scanf("%s",&e.address);
                        break;
                        case 8:
                        printf("Enter new martial status: ");
                        fflush(stdin);
                        scanf("%c",&e.martial_status);
                        break;
                        case 9:
                        printf("Enter new Date of birth: ");
                        fflush(stdin);
                        scanf("%s",&e.d_o_b);
                        break;
                        case 10:
                        printf("Enter new CNIC No: ");
                        fflush(stdin);
                        scanf("%s",&e.CNIC_NO);
                        break;
                        case 11:
                        printf("Enter new attendance: ");
                        fflush(stdin);
						scanf("%d", &e.attendance);
                        break;
                }

                fseek(fp, -sizeof(struct emp), SEEK_CUR);
                fwrite(&e, sizeof(struct emp), 1, fp);
                break;  // Exit the loop after modifying the record
            }
        }

        printf("\nDo you want to edit another record(y/n):\n");
        fflush(stdin);
        // Clear input buffer before getche
        another = getche();
    }
}
void delete_record(FILE *fp) {
    struct emp e;
    FILE *ft;
    system("cls");
    char another = 'y';
    int emp_id;

    while (another == 'y') {
        printf("\nEnter employee id to delete record:\n");
        scanf("%d", &emp_id);
        fflush(stdin);
        ft = fopen("temp.DAT", "wb");
        rewind(fp);

        while (fread(&e, sizeof(struct emp), 1, fp) == 1) {
            if (emp_id != e.ID) {
                fwrite(&e, sizeof(struct emp), 1, ft);
            }
        }

        fclose(fp);
        fclose(ft);

        remove("EMPLOYEE.DAT");
        rename("temp.DAT", "EMPLOYEE.DAT");
        fp = fopen("EMPLOYEE.DAT", "rb+");  // Reopen the file here

        printf("\nDelete another record(y/n): ");
        fflush(stdin);
        another = getche();
    }
}
void search_record(FILE *fp)
{
    struct emp e;
    int n;
    system("cls");
    rewind(fp);
    char another = 'y';

    while (another == 'y')
    {
        printf("\nSEARCH RECORD\n");
        printf("\nEnter ID_NO of the employee you want to search: ");
        fflush(stdin);
        scanf("%d", &n);

        fp = fopen("EMPLOYEE.DAT", "rb");  // Corrected file opening mode

        if (fp == NULL)
        {
            printf("\nUnable to open the file.\n");
            exit(1);
        }

        int found = 0;

        while (fread(&e, sizeof(struct emp), 1, fp) == 1)
        {
            if (n == e.ID)
            {
                printf("ID: %d\n", e.ID);
                printf("Name: %s\n", e.name);
                printf("Gender: %c\n", e.gender);
                printf("Age: %d\n", e.age);
                printf("Salary: %f\n", e.salary);  // Corrected format specifier
                printf("Designation: %s\n", e.designation);
                printf("Address: %s\n", e.address);
                printf("Marital Status: %c\n", e.martial_status);
                printf("Date of Birth: %s\n", e.d_o_b);
                printf("CNIC No.: %s\n", e.CNIC_NO);
                printf("Attendance: %d\n", e.attendance);
                printf("------------------------\n");
                found = 1;
                break;
            }
        }
          if (!found)
            {
                printf("%sRecord not found.%s\n",ANSI_COLOR_RED,ANSI_COLOR_RESET);
            }
        fclose(fp);
       
        printf("Do you want to search another record? (y/n): ");
        fflush(stdin);
        another = getchar();
    }
}
void about (void){
    system("cls");
   FILE* ptr;
char text;
ptr=fopen("about.txt","r");
if (ptr == NULL){
    printf("file is empty");
}
printf("\t\t\t\t\t\t\033[35m ***ITS ALL ABOUT US OUR COMPANY***\t\t\t\n \033[0m");
    while ((text = fgetc(ptr)) != EOF) {
        printf("%c", text);
    }
fclose(ptr);
getche();
}
int openFileWithOptions(void) {
    int option;
    FILE *filePointer;
    char options = 'y';

    while (options == 'y') {
        printf("\nChoose an option:");
        printf("\n1. Open in read mode");
        printf("\n2. Open in write mode (append)");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                filePointer = fopen("Notification.txt", "r");
                if (filePointer == NULL) {
                    printf("\nFile not found or unable to open in read mode.\n");
                    exit(1);
                }
                printf("\nFile opened in read mode.\n");
                char ch;
                printf("\nFile Contents:\n");
                while ((ch = fgetc(filePointer)) != EOF) {
                    putchar(ch);
                }
                printf("\n");
                fclose(filePointer);
                break;
            case 2:
                filePointer = fopen("Notification.txt", "a");
                if (filePointer == NULL) {
                    printf("\nUnable to open in write mode.\n");
                    exit(1);
                }
                printf("\nFile opened in write mode (append).\n");

                // Allow the user to input text to be appended
                char buffer[100];
                printf("\nEnter text to append: ");
                scanf(" %[^\n]s", buffer);

                Employee employee;
                printf("\nEnter employee ID to associate with the notification: ");
                scanf("%d", &employee.empID);

                // Save the notification along with the employee ID
                fprintf(filePointer, "Employee ID: %d, Notification: %s\n", employee.empID, buffer);

                fclose(filePointer);
                break;
            case 3:
            return 0;
                break;
            default:
                printf("\n%sInvalid option. Please choose 1, 2, or 3.%s\n",ANSI_COLOR_RED,ANSI_COLOR_RESET);
                break;
        }

        printf("\nPress 'y' to continue: ");
        scanf(" %c", &options);
    }
}
int notification(void) {
    system("cls");
    char options = 'y';

    while (options == 'y') {
        int numEmployees;

    printf("\nEnter the number of employees of employees you want to send a notification seperately: ");
    scanf("%d", &numEmployees);

    Employee *employees = (Employee *)malloc(numEmployees * sizeof(Employee));

    printf("\nEnter employee details:\n");
    for (int i = 0; i < numEmployees; ++i) {
        printf("\nEmployee %d ID: ", i + 1);
        scanf("%d", &employees[i].empID);
    }
       // Simulating receiving notifications for all employees
    for (int i = 0; i < numEmployees; ++i) {
        printf("\nHR sending notification to Employee ID %d: ", employees[i].empID);
        scanf(" %[^\n]s", employees[i].notification);
    }
    openFileWithOptions();
    // Free allocated memory
    free(employees);
        printf("\nDo you want to continue (y/n): ");
        scanf(" %c", &options);
    }
    return 0;
}

void attendance(FILE *fp) {
    system("cls");
    char ch;
    int empID;
    int total_days;
    printf("Enter employee ID to calculate attendance percentage and salary using attendance: ");
    scanf("%d", &empID);
    printf("Enter the total no. of days the employee had to come this year:");
    scanf("%d",&total_days);
    struct emp e;
    rewind(fp);

    while (fread(&e, sizeof(struct emp), 1, fp) == 1)
     {
        if (empID == e.ID)
         {
            // Display attendance details and calculate salary adjustments
            float salary = e.salary;
             int attendance = e.attendance;
             printf("\nEmployee ID: %d\n", e.ID);
             printf("Attendance: %d days\n", attendance);

            float attendance_percentage = (float)attendance / total_days * 100;
            printf("Attendance Percentage: %.2f%%\n", attendance_percentage);

            if (attendance_percentage < 75) 
            {
                // Deduct 10% from salary
                salary -= 0.10 * salary;
                printf("Deducted 10%% from salary due to low attendance.\n");
            } 
            else if (attendance_percentage > 95) 
            {
                // Give 5% bonus to salary
                salary += 0.05 * salary;
                printf("Added 5%% bonus to salary due to high attendance.\n");
            }
    // Display the adjusted salary
    printf("Adjusted Salary: %.2f\n", salary);
            break;
        }
    }
    printf("\nDo you want to calculate the salary of another employee: ");
    fflush(stdin);
    scanf(" %c", &ch);
    if (ch == 'y' || ch == 'Y') {
        attendance(fp);
    }
}
