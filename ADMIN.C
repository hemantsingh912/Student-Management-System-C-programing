#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include"password.c"
#include"custmor.c"

struct student
{
	int sr_no;
	char name[100];
	char father_name[100];
	float paid_fees;
	float due_fees;
};
struct Marksheet
 {
int sr_no;
float marks[5];
};

void student_details();
void show_marksheet();
void addStudent(int class_no);
void showStudents(int class_no);
void searchStudent(int class_no);
void deleteStudent(int class_no);
void updateStudent(int class_no);

void addMarksheet(int class_no);
void showMarksheet(int class_no);
void deleteMarksheet(int class_no);
void updateMarksheet(int class_no);
void admin();
int get_net_sr_no();


void mai()
{
      int i;
      while(1){
	clrscr();
	printf("                ***********************************************\n");
	printf("               (<---------------------WELCOME----------------->)\n");
	printf("                ***********************************************\n");
	printf("\n\n\n\n\n\n\n\n");

printf("\n[1]  Admin\n");
printf("[2]  Custmor\n");
printf("[3]  Exit\n");

printf("Enter a choice:- ");
scanf("%d",&i);

switch(i)
{
	case 1:
	pass();
	 admin();
	break;
	case 2:
	  custmors();
	break;
	case 3:
	exit(0);
	break;

}






getch();
}
}


void admin()
{
	int i;
	while(1)
	{

	clrscr();
	printf("                ***********************************************\n");
	printf("               (<---------------------WELCOME----------------->)\n");
	printf("                ***********************************************\n");
	printf("\n\n\n\n\n\n\n\n");
	printf("                [1]. Student Details\n");
	printf("                [2]. Show Marksheet\n");
	printf("                [3]. Exit\n\n");
	printf("                Enter your choice:- ");
	scanf("%d",&i);
	switch(i)
	{
		case 1:
		 student_details();
		break;
		case 2:
		 show_marksheet();
		break;
		case 3:
		mai();
		break;
		default:

		printf("INVALID VALUE TRY AGAIN ");
		  delay(3000);
		  break;

	}


getch();
}
}


void student_details()
{
	int i,class_no;
	while(1)
	{
	   clrscr();
	       printf("                ******************************************************\n");
	       printf("               (<-----------------Student Management Menu------------>)\n");
	       printf("                *****************************************************\n");
	       printf("\n\n\n\n\n\n\n\n");
	       printf("                  [1]. Add Student Data\n");
	       printf("                  [2]. Show All Students Data\n");
	       printf("                  [3]. searchStudent data\n");
	       printf("                  [4]. Delete Student Data\n");
	       printf("                  [5]. Update Student Data\n");
	       printf("                  [6]. Back to Main Menu\n\n");
	       printf("                  Enter your choice: ");
	       scanf("%d", &i);
	       if(i==6)
	       break;
	       printf("Enter a class (1-5):- ");
	       scanf("%d",&class_no);

	       switch(i)
	       {
		case 1:
		addStudent( class_no);
		break;
		case 2:
		showStudents( class_no);
		break;
		case 3:
		searchStudent( class_no);
		break;
		case 4:
		deleteStudent( class_no);
		break;
		case 5:
		updateStudent( class_no);
		break;
		case 6:
		exit(0);
		break;
	       default:
	       printf("INVALID VALUE TRY AGAIN ");
		  delay(3000);
	       break;
	       }

getch();
}
}

void show_marksheet()
{
	int i,class_no;
	while(1)
	{
		clrscr();
	       printf("                ***********************************************\n");
	       printf("               (<-----------------Marksheet Menu-------------->)\n");
	       printf("                ***********************************************\n");
	       printf("\n\n\n\n\n\n\n\n");
	       printf("                [1]. Add Marksheet\n");
	       printf("                [2]. Show Marksheet\n");
	       printf("                [3]  Updata marksheet\n");
	       printf("                [4]  Delete marksheet\n");
	       printf("                [5]. Back to Main Menu\n\n");
	       printf("Enter your choise ");
		scanf("%d",&i);

		if(i==5)
		break;
		printf("Enter a class (1-5):- ");
	       scanf("%d",&class_no);

		switch(i)
		{
			case 1:
			 addMarksheet( class_no);

			break;
			case 2:
			 showMarksheet( class_no);
			break;
			case 3:

			 updateMarksheet(class_no);
			break;
			case 4:
			 deleteMarksheet( class_no);
			break;

			default:
			printf("INVALID VALUE TRY AGAIN ");
			delay(3000);
			break;
		}


getch();
}

}
void get_filename(char filename[], int class_no)
{
	sprintf(filename, "b%d.txt", class_no);
}


 int get_next_sr_no()
  {
 FILE *fp = fopen("global_srno.txt", "r+");
 int sr_no = 100;

 if (fp == NULL)
  {
     fp = fopen("global_srno.txt", "w");
     fprintf(fp, "%d", sr_no);
     fclose(fp);
    return sr_no;
 } else
  {
	       fscanf(fp, "%d", &sr_no);
	       sr_no++;
	       rewind(fp);
	       fprintf(fp, "%d", sr_no);
	       fclose(fp);
	       return sr_no;
   }
}


void addStudent(int class_no)
{
	       struct student s;
	       FILE *fp;
	       char filename[20];
		   int h;
	       clrscr();
	       printf("                ******************************************************\n");
	       printf("               (<-------------------Add Student Data----------------->)\n");
	       printf("                *****************************************************\n");
	       printf("\n\n\n\n\n\n\n\n");

	       get_filename(filename, class_no);
	       fp = fopen(filename, "a");

	       s.sr_no = get_next_sr_no();
	       printf("Generated SR No: %d\n", s.sr_no);
	       printf("Enter Name: ");
	       fflush(stdin); gets(s.name);
	       printf("Enter Father's Name: ");
	       gets(s.father_name);
		   h:
	       printf("Enter Paid Fees: ");
	       scanf("%f", &s.paid_fees);
		  if (s.paid_fees > 100000)
		   {
		     printf("Invalid fees amount!");

		     goto h;

		   }
	       s.due_fees = 100000 - s.paid_fees;

	       fprintf(fp, "%d|%s|%s|%.2f|%.2f\n", s.sr_no, s.name, s.father_name, s.due_fees, s.paid_fees);
	       fclose(fp);
	       printf("Student added successfully!\n");
}

void showStudents(int class_no)
{

	       FILE *fp;
	       char filename[20], line[200];

	       clrscr();
	       printf("                ******************************************************\n");
	       printf("               (<----------------Show-All Student Data--------------->)\n");
	       printf("                *****************************************************\n");
	       printf("\n\n\n\n\n\n");

	       get_filename(filename, class_no);
	       fp = fopen(filename, "r");

	       if (fp == NULL) {
	       printf("No data found for class %d.\n", class_no);
	       return;
	       }

	       printf("--------------------------------------------------------------------------------\n");
	       printf("| %-5s | %-20s | %-20s | %-9s | %-9s |\n","SR_NO","NAME","father_name","due_fees","Paid_fees");
	       printf("--------------------------------------------------------------------------------\n");

	       while (fgets(line, sizeof(line), fp)) {
	       sscanf(line, "%d|%[^|]|%[^|]|%f|%f", &s.sr_no, s.name, s.father_name, &s.due_fees, &s.paid_fees);
	       printf("| %-5d | %-20s | %-20s | %-9.2f | %-9.2f |\n", s.sr_no, s.name, s.father_name, s.due_fees,s.paid_fees);
	       }
	       fclose(fp);
	       printf("--------------------------------------------------------------------------------\n");
}



void searchStudent(int class_no)
{

	       FILE *fp;
	       char filename[20], line[200];
	       int target_sr, found = 0;

	      clrscr();

	       printf("                ******************************************************\n");
	       printf("               (<---------------Searching Student Data--------------->)\n");
	       printf("                *****************************************************\n");
	       printf("\n\n\n\n\n\n");
	       printf("Enter SR No to search: ");
	       scanf("%d", &target_sr);

	       get_filename(filename, class_no);
	       fp = fopen(filename, "r");

	       if (fp == NULL)
		{
		 printf("No data found for class %d.\n", class_no);
		 return;
	       }

	       printf("--------------------------------------------------------------------------------\n");
	       printf("| %-5s | %-20s | %-20s | %-9s | %-9s |\n","SR_NO","NAME","father_name","due_fees","Paid_fees");
	       printf("--------------------------------------------------------------------------------\n");


	       while (fgets(line, sizeof(line), fp)) {
	       sscanf(line, "%d|%[^|]|%[^|]|%f|%f", &s.sr_no, s.name, s.father_name, &s.due_fees, &s.paid_fees);
	       if (s.sr_no == target_sr) {
		printf("| %-5d | %-20s | %-20s | %-9.2f | %-9.2f |\n", s.sr_no, s.name, s.father_name, s.due_fees,s.paid_fees);

		 //  printf("\nStudent Found:\n");
		//   printf("SR No: %d\n", s.sr_no);
		 //  printf("Name: %s\n", s.name);
		 //  printf("Father's Name: %s\n", s.father_name);
	       //	   printf("Due Fees: %.2f\n", s.due_fees);
		//   printf("Paid Fees: %.2f\n", s.paid_fees);
		   found = 1;
		   break;
	       }
	       }
	       fclose(fp);
	       if (!found)
	       printf("Student not found!\n");
		printf("--------------------------------------------------------------------------------\n");

}

void deleteStudent(int class_no)
{

	       FILE *fp, *temp;
	       char filename[20], line[200];
	       int target_sr;

	       clrscr();
	       printf("Enter SR No to delete: ");
	       scanf("%d", &target_sr);

	       get_filename(filename, class_no);
	       fp = fopen(filename, "r");
	       temp = fopen("temp.txt", "w");

	       while (fgets(line, sizeof(line), fp))
		{
		   sscanf(line, "%d|%[^|]|%[^|]|%f|%f", &s.sr_no, s.name, s.father_name, &s.due_fees, &s.paid_fees);
		   if (s.sr_no != target_sr)
		   {
		       fprintf(temp, "%d|%s|%s|%.2f|%.2f\n", s.sr_no, s.name, s.father_name, s.due_fees, s.paid_fees);
		   }
	       }

	       fclose(fp);
	       fclose(temp);
	       remove(filename);
	       rename("temp.txt", filename);
	       printf("Student deleted successfully!\n");
	   }





void updateStudent(int class_no)
 {

	       FILE *fp, *temp;
	       char filename[20], line[200];
	       int target_sr,j;
	       long int fees;

	       clrscr();
	       printf("Enter SR No to update: ");
	       scanf("%d", &target_sr);

	       get_filename(filename, class_no);
	       fp = fopen(filename, "r");
	       temp = fopen("temp.txt", "w");

	       while (fgets(line, sizeof(line), fp))
		{
		   sscanf(line, "%d|%[^|]|%[^|]|%f|%f", &s.sr_no, s.name, s.father_name, &s.due_fees, &s.paid_fees);
		   if (s.sr_no == target_sr) {
		       printf("Enter New Name: ");
		       fflush(stdin); gets(s.name);
		       printf("Enter New Father's Name: ");
		       gets(s.father_name);
		       fees=s.paid_fees;
		       printf("fees=%ld",fees);
		       j:
		       printf("Enter New Paid Fees: ");
		       scanf("%f", &s.paid_fees);
		       if( s.paid_fees > fees )
		       {
		       printf("Invalid fees\n");
		       goto j;
		       }
		       s.due_fees = 100000 - s.paid_fees;
		   }
		   fprintf(temp, "%d|%s|%s|%.2f|%.2f\n", s.sr_no, s.name, s.father_name, s.due_fees, s.paid_fees);
	       }

	       fclose(fp);
	       fclose(temp);
	       remove(filename);
	       rename("temp.txt", filename);
	       printf("Student updated successfully!\n");
 }

void get_marksheet_filename(char filename[], int class_no)
 {
     sprintf(filename, "m%d.txt", class_no);
 }

 void addMarksheet(int class_no)
 {

 struct Marksheet m;
	       FILE *fp;
	       char filename[20];
	       int i;

	       clrscr();
	       printf("                ******************************************************\n");
	       printf("               (<--------------Add Marksheet Student Data------------>)\n");
	       printf("                *****************************************************\n");
	       printf("\n\n\n\n\n\n");
	       printf("Enter SR No: ");
	       scanf("%d", &m.sr_no);
	       for (i = 0; i < 5; i++)
	       {
		   printf("Enter marks for subject %d: ", i + 1);
		   scanf("%f", &m.marks[i]);
	       }

	       get_marksheet_filename(filename, class_no);
	       fp = fopen(filename, "a");
	       fprintf(fp, "%d|%.2f|%.2f|%.2f|%.2f|%.2f\n", m.sr_no, m.marks[0], m.marks[1], m.marks[2], m.marks[3], m.marks[4]);
	       fclose(fp);
	       printf("Marksheet added successfully!\n");
	   }

void showMarksheet(int class_no)
{
	       struct Marksheet m;

	       FILE *fp1, *fp2;
	       char filename1[20], filename2[20], line1[200], line2[200];
	       int sr, found = 0, i;
	       float total = 0, percentage;

	       printf("Enter SR No: ");
	       scanf("%d", &sr);

	       get_filename(filename1, class_no);
	       get_marksheet_filename(filename2, class_no);

	       fp1 = fopen(filename1, "r");
	       fp2 = fopen(filename2, "r");

	       if (!fp1 || !fp2)
	       {
		   printf("Data not found.\n");
		   return;
	       }

	       while (fgets(line1, sizeof(line1), fp1))
	       {
		   sscanf(line1, "%d|%[^|]|%[^|]|%f|%f", &s.sr_no, s.name, s.father_name, &s.due_fees, &s.paid_fees);
		   if (s.sr_no == sr)
		   {
		       found = 1;
		       break;
		   }
	       }

	       if (!found)
	       {
		   printf("Student not found!\n");
		   fclose(fp1); fclose(fp2);
		   return;
	       }

	       found = 0;
	       while (fgets(line2, sizeof(line2), fp2))
	       {
		   sscanf(line2, "%d|%f|%f|%f|%f|%f", &m.sr_no, &m.marks[0], &m.marks[1], &m.marks[2], &m.marks[3], &m.marks[4]);
		   if (m.sr_no == sr)
		   {
		       found = 1;
		       break;
		   }
	       }

	       fclose(fp1); fclose(fp2);

	       if (!found) {
	       printf("Marksheet not found!\n");
	       return;
	       }

	       clrscr();
	       printf("\n\n\n\n\n\n\n");
	       printf("                *************************************************\n");
	       printf("               (<-------------STAR INFOTECH COLLEGE------------->)\n");
	       printf("                *************************************************\n");
	       printf("                |       Name    : %-20s          |\n", s.name);
	       printf("                |       Father  : %-20s          |\n", s.father_name);
	       printf("                |       SR No   : %-10d                    |\n", s.sr_no);
	       printf("               (<---------------Subjects Marks------------------>)\n");

	       for (i = 0; i < 5; i++) {
	       printf("                |        Subject %d: %.2f                       |\n", i + 1, m.marks[i]);
	       total += m.marks[i];
	       }

	       percentage = total / 5;
	       printf("                |          TOTAL  : %.2f                      |\n", total);
	       printf("                -------------------------------------------------\n");
	       printf("                |        Percentage: %.2f%%                     |\n", percentage);
	       if (percentage >= 33)
	       printf("                |        RESULT :PASS                           |\n");
	       else
	       printf("                |        RESULT :FAIL                           |\n");
	       printf("                -------------------------------------------------\n");
	   }
void deleteMarksheet(int class_no)
{
struct Marksheet m;
    FILE *fp, *temp;
    char filename[20];
    int target_sr;
    int found = 0;

    get_marksheet_filename(filename, class_no);
    fp = fopen(filename, "r");
    temp = fopen("temp.txt", "w");

    if (!fp || !temp)
    {
	printf("Error opening file.\n");
	return;
    }

    printf("Enter SR No to delete marksheet: ");
    scanf("%d", &target_sr);

    while (fscanf(fp, "%d|%f|%f|%f|%f|%f", &m.sr_no, &m.marks[0], &m.marks[1], &m.marks[2], &m.marks[3], &m.marks[4]) == 6)
    {
	if (m.sr_no != target_sr)
	{
	    fprintf(temp, "%d|%.2f|%.2f|%.2f|%.2f|%.2f\n", m.sr_no, m.marks[0], m.marks[1], m.marks[2], m.marks[3], m.marks[4]);
	}
	else
	{
	    found = 1;
	}
    }

    fclose(fp);
    fclose(temp);

    remove(filename);
    rename("temp.txt", filename);

    if (found)
	printf("Marksheet deleted successfully.\n");
    else
	printf("Marksheet with SR No %d not found.\n", target_sr);

    getch();
}
void updateMarksheet(int class_no)
{
struct Marksheet m;
    FILE *fp, *temp;
    char filename[20];
    int target_sr, i;
    int found = 0;

    get_marksheet_filename(filename, class_no);
    fp = fopen(filename, "r");
    temp = fopen("temp.txt", "w");

    if (!fp || !temp)
    {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter SR No to update marksheet: ");
    scanf("%d", &target_sr);

    while (fscanf(fp, "%d|%f|%f|%f|%f|%f", &m.sr_no, &m.marks[0], &m.marks[1], &m.marks[2], &m.marks[3], &m.marks[4]) == 6)
    {
        if (m.sr_no == target_sr)
        {
            found = 1;
            printf("Enter new marks:\n");
            for (i = 0; i < 5; i++)
            {
                printf("Subject %d: ", i + 1);
                scanf("%f", &m.marks[i]);
            }
        }

        fprintf(temp, "%d|%.2f|%.2f|%.2f|%.2f|%.2f\n", m.sr_no, m.marks[0], m.marks[1], m.marks[2], m.marks[3], m.marks[4]);
    }

    fclose(fp);
    fclose(temp);

    remove(filename);
    rename("temp.txt", filename);

    if (found)
        printf("Marksheet updated successfully.\n");
    else
        printf("Marksheet with SR No %d not found.\n", target_sr);

    getch();
}   