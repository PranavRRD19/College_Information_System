#include<stdio.h>    
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>


void homepage();
void studentsection();
void adminsection();
void adminchoices();
void red();
void yellow();
void purple();
void reset();
void gotoxy(int a, int b);
void studentmenu();
void studentadd();
void studentview();
void studentsearch();
void studentmodify();
void studentdeleterec();
void studentsectionstudentview();
void teachermenu();
void teacheradd();
void teacherview();
void teachersearch();
void teachermodify();
void teacherdeleterec();
void teachersectionstudentview();
void studentsectionbusview();
void busmenu();
void busadd();
void busview();
void bussearch();
void busmodify();
void busdeleterec();
void classroutinemenu();
void displayroutine();
void addclassroutine();
void editclassroutine();
void deleteclassroutine();
void classroutinestudentview();

struct routine
{
char day[50];
char one[25];
char two[25];
char three[25];
char four[25];
char five[25];
char sic[25];
};
struct routine r;

struct bus
{
    char busid[10];
    char locations[40];   
    char pickup[30]; 
    char drop[20];
};

struct teacher
{
    char name[30];
    char mobile[20];   
    char email[30]; 
    char branch[20];
};

struct student
{
    char name[30];
    char mobile[20];
    char srn[20];   
    char email[30]; 
    char branch[20];
};

void classroutinestudentview()
{
FILE *fp;
    int i=1,j;
    system("cls");
    purple();
    printf("\n\n\t\t\t%c%c%c%c%c\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  VIEW CLASS ROUTINE  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t",' ',' ',' ',' ',' ');
    reset();
    printf("\n\n\n\t\t\t\t%c%cDAY\t\t%s9:45-10:30\t%s10:30-11:15\t%s11:15-12:00\t%s12:00-12:45\t%s12:45-1:30\t%s1:30-2:15\t%s2:15-3:00",' ',' ',"  ","    ","    ","    ","    ","    ","    ");
    printf("\n\t\t\t%s","    ");
    for(int i=0;i<140;i++)
    {
	printf("%c",'-');
    }
    printf("\n");
    fp = fopen("classroutine.txt","rb+");
    if(fp == NULL){
        gotoxy(10,8);
        printf("Error opening file.");
        exit(1);
    }
    j=8;
    while(fread(&r,sizeof(r),1,fp) == 1)
    {
        printf("\n\t\t\t\t%-18s%-18s%-17s%-17s%-16s%-15s%-15s%-15s\n",r.day,r.one,r.two,r.three,r.four,"BREAK",r.five,r.sic);
        i++;
    }
    fclose(fp);
    int studentdetailschoice;
    yellow();
    printf("\n\n\t\t\t\t*Enter 1 to go to the main menu");
    printf("\n\n\n\t\t\t\t*Enter 2 to go back");
    printf("\n\n\n\t\t\t\t*Enter 3 to Exit");
    reset();
    purple();
    printf("\n\n\n\t\t\t\t*Enter your choice : ");
    scanf("%d",&studentdetailschoice);
    reset();
    if(studentdetailschoice==1)
    {
	homepage();
    }
    else if(studentdetailschoice==2)
    {
	studentsection();
    }
    else
    {
	exit(0);
    }
}
void classroutinemenu()
{
    int choice;
    system("cls");
    purple();
    printf("\n\n\t\t\t%c%c%c%c%c\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  CLASS TIMETABLE  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t",' ',' ',' ',' ',' ');
    reset();
    printf("\n\n\n");
    red();
    printf("\t\t\t\t\t\t\t*Enter appropriate number to perform following task.");    
    reset();
    printf("\n\n\n\t\t\t\t\t\t\t1 : Add a day in the Class Timetable");    
    printf("\n\n\n\t\t\t\t\t\t\t2 : View the Class Timetable.");    
    printf("\n\n\n\t\t\t\t\t\t\t3 : Modify Class Routine.");
    printf("\n\n\n\t\t\t\t\t\t\t4 : Delete a day in the Class Routine");
    printf("\n\n\n\t\t\t\t\t\t\t5 : To go back");
    yellow();
    printf("\n\n\n\t\t\t\t\t\t\tEnter your choice : ");
    scanf("%d",&choice);
    reset();
    switch(choice)
    {
    case 1:
        addclassroutine();
        break;

    case 2:
        displayroutine();
        break;

    case 3:
        editclassroutine();
        break;

    case 4:
        deleteclassroutine();
        break;

    case 5:
        adminchoices();
        break;

    default:       
        printf("\n\n\n\t\t\t\t<-----Invalid Choice----->");
    }
}

void addclassroutine()
{
    FILE *fp;
    char another ='y';
    system("cls");
    fp = fopen("classroutine.txt","ab+");
    if(fp == NULL)
    {
        gotoxy(10,5);
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
        gotoxy(10,3);
        purple();
        printf("\n\n\t\t\t%c%c%c%c%c\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  ADD DETAILS  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t",' ',' ',' ',' ',' ');
        reset();
        printf("\n\n\n\t\t\t\t*ENTER DETAILS OF A DAY");        
        printf("\n\n\n\t\t\t\tEnter Day name : ");
        gets(r.day);
	fflush(stdin);        
        printf("\n\n\t\t\t\tEnter the 1st period : ");
        gets(r.one);
        fflush(stdin);
        printf("\n\n\t\t\t\tEnter the 2nd period : ");
        gets(r.two);
	fflush(stdin);       
        printf("\n\n\t\t\t\tEnter the 3rd period : ");
        gets(r.three);
	fflush(stdin);  
        printf("\n\n\t\t\t\tEnter the 4th period : ");
        gets(r.four);
	fflush(stdin);  
	printf("\n\n\t\t\t\tEnter the 5th period : ");
        gets(r.five);
	fflush(stdin);  
	printf("\n\n\t\t\t\tEnter the 6th period : ");
        gets(r.sic);
        fwrite(&r,sizeof(r),1,fp);
	yellow();
        printf("\n\n\t\t\t\tWant to add of another record? Then press 'y' else 'n'.");
	reset();
        fflush(stdin);
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    yellow();
    printf("\n\n\n\t\t\t\tPress any key to continue.");
    reset();
    getch();
    classroutinemenu();
}

void deleteclassroutine()
{
    char stname[20];
    FILE *fp,*ft;
    system("cls");
    gotoxy(10,3);
    purple();
    printf("\n\n\n\n\t\t\t%c%c%c%c%c\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  DELETE A DAY'S RECORD  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t",' ',' ',' ',' ',' ');
    reset();
    printf("\n\n\n\t\t\t\tEnter the day  name to delete its record : ");
    fflush(stdin);
    gets(stname);
    fp = fopen("classroutine.txt","rb+");
    if(fp == NULL)
    {
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&r,sizeof(r),1,fp) == 1)
    {
        if(strcmp(stname,r.day)!=0)
            fwrite(&r,sizeof(r),1,ft);
    }
    fclose(fp);
    fclose(ft);
    remove("classroutine.txt");
    rename("temp.txt","classroutine.txt");
    yellow();
    printf("\n\n\n\t\t\t\tPress any key to continue.");
    reset();
    getch();
    classroutinemenu();
}

void editclassroutine()
{
    char stname[20];
    FILE *fp;
    system("cls");
    purple();
    printf("\n\n\n\n\t\t\t%c%c%c%c%c\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  MODIFY CLASS ROUTINE  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t",' ',' ',' ',' ',' ');
    reset();
    printf("\n\n\n\t\t\t\tEnter the name of the day to be modified : ");
    fflush(stdin);
    gets(stname);
    fp = fopen("classroutine.txt","rb+");
    if(fp == NULL)
    {
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    while(fread(&r,sizeof(r),1,fp) == 1)
    {
        if(strcmp(stname,r.day) == 0)
        {
        printf("\n\n\n\t\t\t\tEnter Day name : ");
        gets(r.day);
	fflush(stdin);        
        printf("\n\n\t\t\t\tEnter the 1st period : ");
        gets(r.one);
        fflush(stdin);
        printf("\n\n\t\t\t\tEnter the 2nd period : ");
        gets(r.two);
	fflush(stdin);       
        printf("\n\n\t\t\t\tEnter the 3rd period : ");
        gets(r.three);
	fflush(stdin);  
        printf("\n\n\t\t\t\tEnter the 4th period : ");
        gets(r.four);
	fflush(stdin);  
	printf("\n\n\t\t\t\tEnter the 5th period : ");
        gets(r.five);
	fflush(stdin);  
	printf("\n\n\t\t\t\tEnter the 6th period : ");
        gets(r.sic);
            fseek(fp ,-sizeof(r),SEEK_CUR);
            fwrite(&r,sizeof(r),1,fp);
            break;
        }
    }
    fclose(fp);
    yellow();
    printf("\n\n\n\t\t\t\tPress any key to continue.");
    reset();
    getch();
    classroutinemenu();
}

void displayroutine()
{
    FILE *fp;
    int i=1,j;
    system("cls");
    purple();
    printf("\n\n\t\t\t%c%c%c%c%c\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  VIEW CLASS ROUTINE  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t",' ',' ',' ',' ',' ');
    reset();
    printf("\n\n\n\t\t\t\t%c%cDAY\t\t%s9:45-10:30\t%s10:30-11:15\t%s11:15-12:00\t%s12:00-12:45\t%s12:45-1:30\t%s1:30-2:15\t%s2:15-3:00",' ',' ',"  ","    ","    ","    ","    ","    ","    ");
    printf("\n\t\t\t%s","    ");
    for(int i=0;i<140;i++)
    {
	printf("%c",'-');
    }
    printf("\n");
    fp = fopen("classroutine.txt","rb+");
    if(fp == NULL)
    {
        gotoxy(10,8);
        printf("Error opening file.");
        exit(1);
    }
    j=8;
    while(fread(&r,sizeof(r),1,fp) == 1)
    {
        printf("\n\t\t\t\t%-18s%-18s%-17s%-17s%-16s%-15s%-15s%-15s\n",r.day,r.one,r.two,r.three,r.four,"BREAK",r.five,r.sic);
    }
    fclose(fp);
    yellow();
    printf("\n\n\n\t\t\t\tPress any key to continue.");
    reset();
    getch();
    classroutinemenu();
}

void studentsectionbusview()
{
    FILE *fp;
    int i=1,j;
    struct bus std;
    system("cls");
    purple();
    printf("\n\n\t\t\t%c%c%c%c%c\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  VIEW RECORD  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t",' ',' ',' ',' ',' ');
    reset();
    printf("\n\n\n\t\t\t\t  S.No \t%s  BUS ID%s%sPICKUP / DROP LOCATION(S)  \t\t\t   PICKUP TIME\t\t%sDROP TIME","   ","      ","    ","       ","     ");
    printf("\n\t\t\t\t");
    for(int i=0;i<133;i++)
    {
	printf("%c",'-');
    }
    printf("\n");
    fp = fopen("businfo.txt","rb+");
    if(fp == NULL)
    {
        gotoxy(10,8);
        printf("Error opening file.");
        exit(1);
    }
    j=8;
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        printf("\n\t\t\t\t%c%c%c%-10d%-13s%-57s%-29s%-20s\n",' ',' ',' ',i,std.busid,std.locations,std.pickup,std.drop);
        i++;
    }
    fclose(fp);
    int studentdetailschoice;
    yellow();
    printf("\n\n\t\t\t\t*Enter 1 to go to the main menu");
    printf("\n\n\n\t\t\t\t*Enter 2 to go back");
    printf("\n\n\n\t\t\t\t*Enter 3 to Exit");
    reset();
    purple();
    printf("\n\n\n\t\t\t\t*Enter your choice : ");
    scanf("%d",&studentdetailschoice);
    reset();
    if(studentdetailschoice==1)
    {
	homepage();
    }
    else if(studentdetailschoice==2)
    {
	studentsection();
    }
    else
    {
	exit(0);
    }
}

void busmenu()
{
    int choice;
    system("cls");
    purple();
    printf("\n\n\t\t\t%c%c%c%c%c\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  BUS DETAILS  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t",' ',' ',' ',' ',' ');
    reset();
    printf("\n\n\n");
    red();
    printf("\t\t\t\t\t\t\t*Enter appropriate number to perform following task.");    
    reset();
    printf("\n\n\n\t\t\t\t\t\t\t1 : Add a bus Record");    
    printf("\n\n\n\t\t\t\t\t\t\t2 : View a bus Record.");    
    printf("\n\n\n\t\t\t\t\t\t\t3 : Search a bus Record.");
    printf("\n\n\n\t\t\t\t\t\t\t4 : Modify a bus Record.");
    printf("\n\n\n\t\t\t\t\t\t\t5 : Delete a bus record");
    printf("\n\n\n\t\t\t\t\t\t\t6 : To go back");
    yellow();
    printf("\n\n\n\t\t\t\t\t\t\tEnter your choice : ");
    reset();
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        busadd();
        break;

    case 2:
        busview();
        break;

    case 3:
        bussearch();
        break;

    case 4:
        busmodify();
        break;

    case 5:
        busdeleterec();
        break;

    case 6:
        adminchoices();
        break;

    default:       
        printf("\n\n\n\t\t\t\t<-----Invalid Choice----->");
    }
}
void busadd()
{
    FILE *fp;
    struct bus std;
    char another ='y';
    system("cls");
    fp = fopen("businfo.txt","ab+");
    if(fp == NULL)
    {
        gotoxy(10,5);
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
        gotoxy(10,3); 	
	purple();
        printf("\n\n\t\t\t%c%c%c%c%c\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  ADD DETAILS  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t",' ',' ',' ',' ',' ');
        reset();
	printf("\n\n\n\t\t\t\t*ENTER DETAILS OF THE BUS");        
        printf("\n\n\n\t\t\t\tEnter Bus ID : ");
        gets(std.busid);
	fflush(stdin);        
        printf("\n\n\t\t\t\tEnter the areas wherever the bus goes : ");
        gets(std.locations);
        fflush(stdin);
        printf("\n\n\t\t\t\tEnter Pickup time : ");
        gets(std.pickup);
	fflush(stdin);       
        printf("\n\n\t\t\t\tEnter Drop time : ");
        gets(std.drop);
        fwrite(&std,sizeof(std),1,fp);
	yellow();
        printf("\n\n\t\t\t\tWant to add of another record? Then press 'y' else 'n'.");
	reset();
        fflush(stdin);
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    yellow();
    printf("\n\n\n\t\t\t\tPress any key to continue.");
    reset();
    getch();
    busmenu();
}
void busview()
{
    FILE *fp;
    int i=1,j;
    struct bus std;
    system("cls");
    purple();
    printf("\n\n\t\t\t%c%c%c%c%c\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  VIEW RECORD  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t",' ',' ',' ',' ',' ');
    reset();
    printf("\n\n\n\t\t\t\t  S.No \t%s  BUS ID%s%sPICKUP / DROP LOCATION(S)  \t\t\t   PICKUP TIME\t\t%sDROP TIME","   ","      ","    ","       ","     ");
    printf("\n\t\t\t\t");
    for(int i=0;i<133;i++)
    {
	printf("%c",'-');
    }
    printf("\n");
    fp = fopen("businfo.txt","rb+");
    if(fp == NULL){
        gotoxy(10,8);
        printf("Error opening file.");
        exit(1);
    }
    j=8;
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        printf("\n\t\t\t\t%c%c%c%-10d%-13s%-57s%-29s%-20s\n",' ',' ',' ',i,std.busid,std.locations,std.pickup,std.drop);
        i++;
    }
    fclose(fp);
    yellow();
    printf("\n\n\n\t\t\t\tPress any key to continue.");
    reset();
    getch();
    busmenu();
}
void bussearch()
{
    FILE *fp;
    struct bus std;
    char stname[20];
    system("cls");
    red();
    printf("\n\n\n\n\t\t\t%c%c%c%c%c\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  SEARCH BUS DETAILS  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t",' ',' ',' ',' ',' ');
    reset();
    printf("\n\n\n\t\t\t\tEnter Bus ID : ");
    fflush(stdin);
    gets(stname);
    fp = fopen("businfo.txt","rb+");
    if(fp == NULL)
    {
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp ) == 1)
    {
        if(strcmp(stname,std.busid) == 0)
	{
	    purple();
            printf("\n\n\t\t\t\tBus ID : %s",std.busid);
            printf("\n\n\t\t\t\tA : %s",std.locations);
            printf("\n\n\t\t\t\tPickup Time : %s",std.pickup);
            printf("\n\n\t\t\t\tDrop Time : %s\n\n",std.drop);
	    reset();
        }
    }
    fclose(fp);
    yellow();
    printf("\n\n\n\t\t\t\tPress any key to continue.");
    reset();
    getch();
    busmenu();
}
void busmodify()
{
    char stname[20];
    FILE *fp;
    struct bus std;
    system("cls");
    purple();
    printf("\n\n\n\n\t\t\t%c%c%c%c%c\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  MODIFY DETAILS  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t",' ',' ',' ',' ',' ');
    reset();
    printf("\n\n\n\t\t\t\tEnter the ID of the bus to be modified : ");
    fflush(stdin);
    gets(stname);
    fp = fopen("businfo.txt","rb+");
    if(fp == NULL)
    {
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(strcmp(stname,std.busid) == 0)
	{
            printf("\n\n\n\t\t\t\tEnter Bus ID : ");
            gets(std.busid);
            printf("\n\n\t\t\t\tEnter the areas wherever the bus goes : ");
            gets(std.locations);
            printf("\n\n\t\t\t\tEnter Pickup time : ");
            fflush(stdin);
            gets(std.pickup);
            printf("\n\n\t\t\t\tEnter Drop time : ");
            fflush(stdin);
            gets(std.drop);
            fseek(fp ,-sizeof(std),SEEK_CUR);
            fwrite(&std,sizeof(std),1,fp);
            break;
        }
    }
    fclose(fp);
    yellow();
    printf("\n\n\n\t\t\t\tPress any key to continue.");
    reset();
    getch();
    busmenu();
}
void busdeleterec()
{
    char stname[20];
    FILE *fp,*ft;
    struct bus std;
    system("cls");
    gotoxy(10,3);
    purple();
    printf("\n\n\n\n\t\t\t%c%c%c%c%c\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  DELETE RECORD  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t",' ',' ',' ',' ',' ');
    reset();
    printf("\n\n\n\t\t\t\tEnter the ID of bus to delete its record : ");
    fflush(stdin);
    gets(stname);
    fp = fopen("businfo.txt","rb+");
    if(fp == NULL)
    {
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL)
    {
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(strcmp(stname,std.busid)!=0)
            fwrite(&std,sizeof(std),1,ft);
    }
    fclose(fp);
    fclose(ft);
    remove("businfo.txt");
    rename("temp.txt","businfo.txt");
    yellow();
    printf("\n\n\n\t\t\t\tPress any key to continue.");
    reset();
    getch();
    busmenu();
}



void teachersectionstudentview()
{
    FILE *fp;
    int i=1,j;
    struct teacher std;
    system("cls");
    purple();
    printf("\n\n\t\t\t%c%c%c%c%c\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  VIEW RECORD  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t",' ',' ',' ',' ',' ');
    reset();
    printf("\n\n\n\t\t\t\t  S.No \t%s  NAME OF TEACHER   \t%s\t%s    MOBILE No  \t\t   EMAIL\t\t%sSUBJECT TAUGHT","   ","      ","    ","       ","     ");
    printf("\n\t\t\t\t");
    for(int i=0;i<133;i++)
    {
	printf("%c",'-');
    }
    printf("\n");
    fp = fopen("teacherinfo.txt","rb+");
    if(fp == NULL)
    {
        gotoxy(10,8);
        printf("Error opening file.");
        exit(1);
    }
    j=8;
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        printf("\n\t\t\t\t%c%c%c%-10d%-35s%-20s%-40s%-10s\n",' ',' ',' ',i,std.name,std.mobile,std.email,std.branch);
        i++;
    }
    fclose(fp);
    int studentdetailschoice;
    yellow();
    printf("\n\n\t\t\t\t*Enter 1 to go to the main menu");
    printf("\n\n\n\t\t\t\t*Enter 2 to go back");
    printf("\n\n\n\t\t\t\t*Enter 3 to Exit");
    reset();
    purple();
    printf("\n\n\n\t\t\t\t*Enter your choice : ");
    scanf("%d",&studentdetailschoice);
    reset();
    if(studentdetailschoice==1)
    {
	homepage();
    }
    else if(studentdetailschoice==2)
    {
	studentsection();
    }
    else
    {
	exit(0);
    }
}


void teachermenu()
{
    int choice;
    system("cls");
    purple();
    printf("\n\n\t\t\t%c%c%c%c%c\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  TEACHER DETAILS  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t",' ',' ',' ',' ',' ');
    reset();
    printf("\n\n\n");
    red();
    printf("\t\t\t\t\t\t\t*Enter appropriate number to perform following task.");    
    reset();
    printf("\n\n\n\t\t\t\t\t\t\t1 : Add a teacher Record");    
    printf("\n\n\n\t\t\t\t\t\t\t2 : View a teacher Record.");    
    printf("\n\n\n\t\t\t\t\t\t\t3 : Search a teacher Record.");
    printf("\n\n\n\t\t\t\t\t\t\t4 : Modify a teacher Record.");
    printf("\n\n\n\t\t\t\t\t\t\t5 : Delete a teacher record");
    printf("\n\n\n\t\t\t\t\t\t\t6 : To go back");
    yellow();
    printf("\n\n\n\t\t\t\t\t\t\tEnter your choice : ");
    scanf("%d",&choice);
    reset();
    switch(choice)
    {
    case 1:
        teacheradd();
        break;

    case 2:
        teacherview();
        break;

    case 3:
        teachersearch();
        break;

    case 4:
        teachermodify();
        break;

    case 5:
        teacherdeleterec();
        break;

    case 6:
        adminchoices();
        break;

    default:       
        printf("\n\n\n\t\t\t\t<-----Invalid Choice----->");
    }
}
void teacheradd()
{
    FILE *fp;
    struct teacher std;
    char another ='y';
    system("cls");
    fp = fopen("teacherinfo.txt","ab+");
    if(fp == NULL)
    {
        gotoxy(10,5);
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
        gotoxy(10,3);
	purple();
        printf("\n\n\t\t\t%c%c%c%c%c\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  ADD RECORD  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t",' ',' ',' ',' ',' ');
        reset();
	printf("\n\n\n\t\t\t\t*ENTER DETAILS OF THE TEACHER");        
        printf("\n\n\n\t\t\t\tEnter Name : ");
        gets(std.name);
	fflush(stdin);        
        printf("\n\n\t\t\t\tEnter Mobile Number : ");
        gets(std.mobile);
        fflush(stdin);
        printf("\n\n\t\t\t\tEnter email: ");
        gets(std.email);
	fflush(stdin);       
        printf("\n\n\t\t\t\tEnter Subject taught : ");
        gets(std.branch);
        fwrite(&std,sizeof(std),1,fp);
	yellow();
        printf("\n\n\t\t\t\tWant to add of another record? Then press 'y' else 'n'.");
	reset();
        fflush(stdin);
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    yellow();
    printf("\n\n\n\t\t\t\tPress any key to continue.");
    reset();
    getch();
    teachermenu();
}
void teacherview()
{
    FILE *fp;
    int i=1,j;
    struct teacher std;
    system("cls");
    purple();
    printf("\n\n\t\t\t%c%c%c%c%c\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  VIEW RECORD  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t",' ',' ',' ',' ',' ');
    reset();
    printf("\n\n\n\t\t\t\t  S.No \t%s  NAME OF TEACHER   \t%s\t%s    MOBILE No  \t\t   EMAIL\t\t%sSUBJECT TAUGHT","   ","      ","    ","       ","     ");
    printf("\n\t\t\t\t");
    for(int i=0;i<133;i++)
    {
	printf("%c",'-');
    }
    printf("\n");
    fp = fopen("teacherinfo.txt","rb+");
    if(fp == NULL)
    {
        gotoxy(10,8);
        printf("Error opening file.");
        exit(1);
    }
    j=8;
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        printf("\n\t\t\t\t%c%c%c%-10d%-35s%-20s%-40s%-10s\n",' ',' ',' ',i,std.name,std.mobile,std.email,std.branch);
        i++;
    }
    fclose(fp);
    yellow();
    printf("\n\n\n\t\t\t\tPress any key to continue.");
    reset();
    getch();
    teachermenu();
}
void teachersearch()
{
    FILE *fp;
    struct teacher std;
    char stname[20];
    system("cls");
    red();
    printf("\n\n\n\n\t\t\t%c%c%c%c%c\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  SEARCH RECORD  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t",' ',' ',' ',' ',' ');
    reset();
    printf("\n\n\n\t\t\t\tEnter name of teacher : ");
    fflush(stdin);
    gets(stname);
    fp = fopen("teacherinfo.txt","rb+");
    if(fp == NULL)
    {
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp ) == 1)
    {
        if(strcmp(stname,std.name) == 0)
	{
	    purple();
            printf("\n\n\t\t\t\tName : %s",std.name);
            printf("\n\n\t\t\t\tMobile Number : %s",std.mobile);
            printf("\n\n\t\t\t\tEmail : %s",std.email);
            printf("\n\n\t\t\t\tSubject Taught : %s\n\n",std.branch);
	    reset();
        }
    }
    fclose(fp);
    yellow();
    printf("\n\n\n\t\t\t\tPress any key to continue.");
    reset();
    getch();
    teachermenu();
}
void teachermodify()
{
    char stname[20];
    FILE *fp;
    struct teacher std;
    system("cls");
    purple();
    printf("\n\n\n\n\t\t\t%c%c%c%c%c\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  MODIFY RECORD  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t",' ',' ',' ',' ',' ');
    reset();
    printf("\n\n\n\t\t\t\tEnter name of teacher to modify: ");
    fflush(stdin);
    gets(stname);
    fp = fopen("teacherinfo.txt","rb+");
    if(fp == NULL)
    {
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(strcmp(stname,std.name) == 0)
	{
            printf("\n\n\n\t\t\t\tEnter name: ");
            gets(std.name);
            printf("\n\n\t\t\t\tEnter mobile number : ");
            gets(std.mobile);
            printf("\n\n\t\t\t\tEnter email : ");
            fflush(stdin);
            gets(std.email);
            printf("\n\n\t\t\t\tEnter Subject Taught : ");
            fflush(stdin);
            gets(std.branch);
            fseek(fp ,-sizeof(std),SEEK_CUR);
            fwrite(&std,sizeof(std),1,fp);
            break;
        }
    }
    fclose(fp);
    yellow();
    printf("\n\n\n\t\t\t\tPress any key to continue.");
    reset();
    getch();
    teachermenu();
}
void teacherdeleterec()
{
    char stname[20];
    FILE *fp,*ft;
    struct teacher std;
    system("cls");
    gotoxy(10,3);
    purple();
    printf("\n\n\n\n\t\t\t%c%c%c%c%c\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  DELETE RECORD  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t",' ',' ',' ',' ',' ');
    reset();
    printf("\n\n\n\t\t\t\tEnter name of teacher to delete record : ");
    fflush(stdin);
    gets(stname);
    fp = fopen("teacherinfo.txt","rb+");
    if(fp == NULL)
    {
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL)
    {
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(strcmp(stname,std.name)!=0)
            fwrite(&std,sizeof(std),1,ft);
    }
    fclose(fp);
    fclose(ft);
    remove("teacherinfo.txt");
    rename("temp.txt","teacherinfo.txt");
    yellow();
    printf("\n\n\n\t\t\t\tPress any key to continue.");
    reset();
    getch();
    teachermenu();
}

void studentsectionstudentview()
{
  FILE *fp;
  int i=1,j;
  struct student std;
  system("cls");
  red();
  printf("\n\n\n\t\t\t\t*THIS SECTION CONTAINS STUDENT DETAILS LIKE NAME , MOBILE NUMBER , SRN , SECTION AND EMAIL ID");
  reset();
  purple();
  printf("\n\n\t\t\t%c%c%c%c%c\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  VIEW RECORD  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t",' ',' ',' ',' ',' ');
  reset();
  printf("\n\n\n\t\t\t\t  S.No \t%s  NAME OF STUDENT   \t%s    MOBILE No  \t      SRN          \t     EMAIL\t\t\t%sBRANCH","    ","   ","    ");
  printf("\n\t\t\t\t");
  for(int i=0;i<133;i++)
  {
    printf("%c",'-');
  }
  printf("\n");
  fp = fopen("record.txt","rb+");
  if(fp == NULL)
  {
  gotoxy(10,8);
  printf("Error opening file.");
  exit(1);
  }
  while(fread(&std,sizeof(std),1,fp) == 1)
  {
  printf("\n\t\t\t\t%c%c%c%-8d%-35s%-20s%-20s%-38s%-10s\n",' ',' ',' ',i,std.name,std.mobile,std.srn,std.email,std.branch);
  i++;
  }
  fclose(fp);
  int studentdetailschoice;
  yellow();
  printf("\n\n\t\t\t\t*Enter 1 to go to the main menu");
  printf("\n\n\n\t\t\t\t*Enter 2 to go back");
  printf("\n\n\n\t\t\t\t*Enter 3 to Exit");
  reset();
  purple();
  printf("\n\n\n\t\t\t\t*Enter your choice : ");
  scanf("%d",&studentdetailschoice);
  reset();
  if(studentdetailschoice==1)
  {
    homepage();
  }
  else if(studentdetailschoice==2)
  {
    studentsection();
  }
  else
  {
    exit(0);
  }
}


void studentmenu()
{
    int choice;
    system("cls");
    purple();    
    printf("\n\n\t\t\t%c%c%c%c%c\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  STUDENT DETAILS  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t",' ',' ',' ',' ',' ');
    printf("\n\n\n");
    reset();    
    red();
    printf("\t\t\t\t\t\t\t*Enter appropriate number to perform following task.");        
    reset();
    printf("\n\n\n\t\t\t\t\t\t\t1 : Add a Student Record");    
    printf("\n\n\n\t\t\t\t\t\t\t2 : View a Student Record.");    
    printf("\n\n\n\t\t\t\t\t\t\t3 : Search a Student Record.");
    printf("\n\n\n\t\t\t\t\t\t\t4 : Modify a Student Record.");
    printf("\n\n\n\t\t\t\t\t\t\t5 : Delete a Student record");
    printf("\n\n\n\t\t\t\t\t\t\t6 : To go back");
    yellow();    
    printf("\n\n\n\t\t\t\t\t\t\tEnter your choice : ");
    scanf("%d",&choice);
    reset();    
    switch(choice)
    {
    case 1:
        studentadd();
        break;

    case 2:
        studentview();
        break;

    case 3:
        studentsearch();
        break;

    case 4:
        studentmodify();
        break;

    case 5:
        studentdeleterec();
        break;

    case 6:
        adminchoices();
        break;

    default:       
        printf("\n\n\n\t\t\t\t<-----Invalid Choice----->");
    }
}

void studentadd()
{
    FILE *fp;
    struct student std;
    char another ='y';
    system("cls");
    fp = fopen("record.txt","ab+");
    if(fp == NULL)
    {
        gotoxy(10,5);
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
    gotoxy(10,3);
    red();       
    printf("\n\n\t\t\t%c%c%c%c%c\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  ADD RECORD  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t",' ',' ',' ',' ',' ');
    reset();
    purple();      
    printf("\n\n\n\t\t\t\t*ENTER DETAILS OF THE STUDENT");        
    reset();        
    printf("\n\n\n\t\t\t\tEnter Name : ");
    gets(std.name);
    fflush(stdin);        
    printf("\n\n\t\t\t\tEnter Mobile Number : ");
    gets(std.mobile);
    fflush(stdin);       
    printf("\n\n\t\t\t\tEnter the SRN : ");
    gets(std.srn);
    fflush(stdin);
    printf("\n\n\t\t\t\tEnter email: ");
    gets(std.email);
    fflush(stdin);       
    printf("\n\n\t\t\t\tEnter Branch : ");
    gets(std.branch);
    fwrite(&std,sizeof(std),1,fp);
    purple();        
    printf("\n\n\t\t\t\tWant to add of another record? Then press 'y' else 'n'.");
    reset();        
    fflush(stdin);
    another = getch();
    system("cls");
    fflush(stdin);
    }
    fclose(fp);
    printf("\n\n\n\t\t\t\tPress any key to continue.");
    getch();
    studentmenu();
}
void studentview()
{
    FILE *fp;
    int i=1,j;
    struct student std;
    system("cls");
    purple();    
    printf("\n\n\t\t\t%c%c%c%c%c\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  VIEW RECORD  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t",' ',' ',' ',' ',' ');
    reset();    
    red();
    printf("\n\n\n\t\t\t\t  S.No \t%s  NAME OF STUDENT   \t%s    MOBILE No  \t      SRN          \t     EMAIL\t\t\t%sBRANCH","    ","   ","    ");
    reset();    
    printf("\n\t\t\t\t");
    for(int i=0;i<133;i++)
    {
	printf("%c",'-');
    }
    printf("\n");
    fp = fopen("record.txt","rb+");
    if(fp == NULL)
    {
        gotoxy(10,8);
        printf("Error opening file.");
        exit(1);
    }
    j=8;
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        printf("\n\t\t\t\t%c%c%c%-8d%-35s%-20s%-20s%-38s%-10s\n",' ',' ',' ',i,std.name,std.mobile,std.srn,std.email,std.branch);
        i++;
    }
    fclose(fp);
    printf("\n\n\n\t\t\t\tPress any key to continue.");
    getch();
    studentmenu();
}
void studentsearch()
{
    FILE *fp;
    struct student std;
    char stname[20];
    system("cls");
    red();    
    printf("\n\n\n\t\t\t%c%c%c%c%c\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  SEARCH RECORD  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t",' ',' ',' ',' ',' ');
    reset();    
    yellow();
    printf("\n\n\n\t\t\t\tEnter name of student : ");    
    reset();
    fflush(stdin);
    gets(stname);
    fp = fopen("record.txt","rb+");
    if(fp == NULL)
    {
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp ) == 1)
     {
        if(strcmp(stname,std.name) == 0)
	{
	    purple();
            printf("\n\n\t\t\t\tName : %s",std.name);
            printf("\n\n\t\t\t\tMobile Number : %s",std.mobile);
            printf("\n\n\t\t\t\tSRN : %s",std.srn);
            printf("\n\n\t\t\t\tEmail : %s",std.email);
            printf("\n\n\t\t\t\tBranch : %s\n\n",std.branch);
	    reset();        
	}
    }
    fclose(fp);
    printf("\n\n\n\t\t\t\tPress any key to continue.");
    getch();
    studentmenu();
}
void studentmodify()
{
    char stname[20];
    FILE *fp;
    struct student std;
    system("cls");
    red();    
    printf("\n\n\n\t\t\t%c%c%c%c%c\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  MODIFY RECORD  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t",' ',' ',' ',' ',' ');
    reset();
    purple();    
    printf("\n\n\n\t\t\t\tEnter name of student to modify: ");
    fflush(stdin);
    gets(stname);
    reset();
    fp = fopen("record.txt","rb+");
    if(fp == NULL)
    {
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(strcmp(stname,std.name) == 0)
	{
            printf("\n\n\n\t\t\t\tEnter name: ");
            gets(std.name);
            printf("\n\n\t\t\t\tEnter mobile number : ");
            gets(std.mobile);
            printf("\n\n\t\t\t\tEnter SRN : ");
            gets(std.srn);
            printf("\n\n\t\t\t\tEnter email : ");
            fflush(stdin);
            gets(std.email);
            printf("\n\n\t\t\t\tEnter Branch : ");
            fflush(stdin);
            gets(std.branch);
            fseek(fp ,-sizeof(std),SEEK_CUR);
            fwrite(&std,sizeof(std),1,fp);
            break;
        }
    }
    fclose(fp);
    printf("\n\n\n\t\t\t\tPress any key to continue.");
    getch();
    studentmenu();
}
void studentdeleterec()
{
    char stname[20];
    FILE *fp,*ft;
    struct student std;
    system("cls");
    purple();     
    printf("\n\n\n\t\t\t%c%c%c%c%c\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  DELETE RECORD  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t",' ',' ',' ',' ',' ');
    reset();    
    yellow();
    printf("\n\n\n\t\t\t\tEnter name of student to delete record : ");
    reset();
    fflush(stdin);
    gets(stname);
    fp = fopen("record.txt","rb+");
    if(fp == NULL)
    {
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL)
    {
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(strcmp(stname,std.name)!=0)
        {
            fwrite(&std,sizeof(std),1,ft);
        }
    }
    fclose(fp);
    fclose(ft);
    remove("record.txt");
    rename("temp.txt","record.txt");
    printf("\n\n\n\t\t\t\tPress any key to continue.");
    getch();
    studentmenu();
}


void gotoxy(int a, int b)    
{
  COORD c;
  c.X=a;        
  c.Y=b;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);    
}



void purple()
{
  printf("\033[1;34m");
}


void red()
{
  printf("\033[1;31m");
}


void yellow() 
{  
  printf("\033[1;33m");
}


void reset() 
{
  printf("\033[0m");
}



void homepage()
{
  system("cls");
  int homepagechoice;
  yellow();
  printf("\n\n\n\n\t\t%c%c%c%c%c%c%c\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  COLLEGE INFORMATION SYSTEM  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t",' ',' ',' ',' ',' ',' ',' ');
  reset();
  printf("\n\n\n\n\t\t\t%c%c%c%c%c\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  COLLEGE DATABASE  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t",' ',' ',' ',' ',' ');
  red();
  printf("\n\n\n\n\t\t\t\t\t\tPlease don't enter any invalid character");
  reset();
  printf("\n\n\n\n\t\t\t\t\t\t* Enter 1 for Student Section");
  printf("\n\n\n\t\t\t\t\t\t* Enter 2 for Admin Section");
  printf("\n\n\n\t\t\t\t\t\t* Enter 3 to Exit ");
  purple();
  printf("\n\n\n\t\t\t\t\t\tEnter your choice : ");
  scanf("%d",&homepagechoice);
  reset();
  if(homepagechoice==1)
  {
    studentsection();
  }
  else if(homepagechoice==2)
  {
    adminsection();
  }
  else if(homepagechoice==3)
  {
    exit(1);
  }
}



void studentsection()
{
  int studentsectionchoice;
  system("cls");
  printf("\n\n");
  purple();
  printf("\n\n\t\t\t%c%c%c%c%c\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  STUDENT SECTION  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t",' ',' ',' ',' ',' ');
  reset();
  printf("\n\n\n");
  red();
  printf("\t\t\t\t%c%cNOTE : STUDENTS SECTION CONTAINS STUDENT INFORMATION , TEACHERS' CONTACT DETAILS AND BUS TIMINGS",' ',' ');
  printf("\n\n\n\t\t\t\t\t STUDENTS CANNOT ADD , DELETE OR MODIFY THE DATA");
  reset();
  printf("\n\n\n\n\t\t\t\t\t\t* Enter 1 for Student Details");
  printf("\n\n\n\t\t\t\t\t\t* Enter 2 for Teacher Contact Details");
  printf("\n\n\n\t\t\t\t\t\t* Enter 3 for Bus Timings");
  printf("\n\n\n\t\t\t\t\t\t* Enter 4 for Class Timetable");
  printf("\n\n\n\t\t\t\t\t\t* Enter 5 to go back to the main page");
  printf("\n\n\n\t\t\t\t\t\t* Enter 6 to Exit");
  yellow();
  printf("\n\n\n\t\t\t\t\t\t* Enter your choice : ");
  scanf("%d",&studentsectionchoice);
  reset();
  if(studentsectionchoice==1)
  {
    studentsectionstudentview();
  }
  else if(studentsectionchoice==2)
  {
    teachersectionstudentview();
  }
  else if(studentsectionchoice==3)
  {
    studentsectionbusview();
  }
  else if(studentsectionchoice==4)
  {
    classroutinestudentview();
  }
  else if(studentsectionchoice==5)
  {
    homepage();
  }
  else if(studentsectionchoice==6)
  {
    exit(0);
  }
}

void adminsection()
{
  system("cls");
  int tryagain;
  char user[]="1";
  char pass[]="1";
  char username[30],password[30];
  int v=1,i=0;
  for(v=1;v<=5;v++)
  {
    printf("\n\n\n\t\t");
    char ch=0,passw[10];
    purple();
    printf("\n\t\t\t%c%c%c%c%c\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  PASSWORD PROTECTED  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t",' ',' ',' ',' ',' ');
    reset();
    yellow();
    printf("\n\n\n\t\t\t\t*ENTER THE CORRECT CREDENTIALS TO GET ACCESS TO THE ADMIN SECTION (YOU HAVE A MAXIMUM OF 5 ATTEMPTS)");
    reset();
    printf("\n\n\n\n\t\t\t\t\t\tEnter your Admin Username (No Spaces) : ");
    scanf("%s",username);
    printf("\n\n\n\t\t\t\t\t\tEnter the Admin Password (No Spaces) : ");
    while(ch!=13)
    {
	ch=getch();
	if(ch!=13)
        {
        putch('*');
        passw[i] = ch;
        i++;
        }
    }
    passw[i] = '\0';
    if(strcmp(pass,passw)==0 && strcmp(user,username)==0)
    {
        adminchoices();
	break;
    }
    else
    {
	i=0;
	red();
	printf("\a\n\n\n\n\t\t\t\t\t\tWRONG CREDENTIALS !!!!!");
	reset();
	Sleep(1000);
	system("cls");
	yellow();
	printf("\n\n\tYOUR ATTEMPT NUMBER : %d",v+1);
	reset();
	if(v==4)
	{
	    system("cls");
	    printf("\n\n\t\t\t\tTHIS IS YOUR LAST CHANCE\n\n\t\t\t\tU WILL HAVE TO WAIT FOR 20s IF YOU DON'T GET IT RIGHT !!");
	}
	else if(v==5)
	{
	    system("cls");
	    int count=21;
	    do
	    {
	      Sleep(1000);
	      system("cls");
	      count--;
	      red();
	      printf("\n\n\n\t\t\t%c%c%c%c%c\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  HAVE PATIENCE :)  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t",' ',' ',' ',' ',' ');
	      reset();
	      printf("\n\n\n\n\n\t\t\t\t\t\tTRY AGAIN AFTER %ds ..... ",count);
	    }while(count!=0);
	system("cls");
	purple();
        printf("\n\n\t\t\t%c%c%c%c%c\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  WANNA TRY AGAIN ?  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t",' ',' ',' ',' ',' ');
	reset();
	printf("\n\n\n\n\t\t\t\t\t\t*Enter 1 to try to login to admin section again  ");
	printf("\n\n\n\t\t\t\t\t\t*Enter 2 to go back to the main page  ");
	yellow();
	printf("\n\n\n\t\t\t\t\t\t*Enter your choice : ");
	scanf("%d",&tryagain);
	reset();
	if(tryagain==1)
	{
	    adminsection();
	}
	else
	{
	    homepage();
	}
        }
    }
  }
}

void adminchoices()
{
  int adminchoice;
  system("cls");
  printf("\n\n\n");
  purple();
  printf("\n\n\t\t\t%c%c%c%c%c\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  ADMIN  CHOICES  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t",' ',' ',' ',' ',' ');
  reset();
  printf("\n\n\n\n\t\t\t\t\t\t* Enter 1 for Student Details");
  printf("\n\n\n\t\t\t\t\t\t* Enter 2 for Teacher Details");
  printf("\n\n\n\t\t\t\t\t\t* Enter 3 for Bus Timings");
  printf("\n\n\n\t\t\t\t\t\t* Enter 4 for Class Timetable");
  printf("\n\n\n\t\t\t\t\t\t* Enter 5 to go log out and go back to the main page");
  printf("\n\n\n\t\t\t\t\t\t* Enter 6 to Exit");
  yellow();
  printf("\n\n\n\t\t\t\t\t\t*Enter your choice : ");
  scanf("%d",&adminchoice);
  reset();
  if(adminchoice==1)
  {
    studentmenu();
  }
  else if(adminchoice==2)
  {
    teachermenu();
  }
  else if(adminchoice==3)
  {
    busmenu();
  }
  else if(adminchoice==4)
  {
    classroutinemenu();
  }
  else if(adminchoice==5)
  {
    homepage();
  }
  else
  {
    exit(0);
  }
}

int main()
{
    system("cls");
    homepage();
    return 0;
}




    

    


