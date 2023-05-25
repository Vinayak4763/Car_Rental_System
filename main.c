#include <stdio.h>
#include <stdlib.h>
#include"conio2.h"
#include"CAR.H"

int main()
{
    int i,type,result,choice;
   user *usr;
gotoxy(25,10);
textcolor(YELLOW);
printf("WELCOME TO THE CAR RENTAL SYSTEM");
gotoxy(24,13);
textcolor(LIGHTGREEN);
printf("RENT A CAR AND GO WHEREVER YOU NEED");
_getch();
textcolor(YELLOW);
addAdmin();
clrscr();
gotoxy(30,2);
textcolor(RED);
printf("CAR RENTAL SYSTEM");
gotoxy(1,6);
textcolor(YELLOW);
for(i=0;i<80;i++)
{
    printf("*");
}
gotoxy(1,17);
for(i=0;i<80;i++)
{
    printf("*");
}
gotoxy(30,9);
printf("1: ADMIN");
gotoxy(30,10);
printf("2: EMPLOYEE");
gotoxy(30,11);
printf("3: QUIT");
textcolor(WHITE);
gotoxy(30,13);
int k;
printf("SELECT YOUR ROLE  :");
do
{
    scanf("%d",&type);
    k=0;
    if(type==1)
    {
        do
        {
         usr= getInput();
          if(usr!=NULL)
        {
            k= checkUserExist(*usr,"admin");
        }
        else
        {
            break;
        }
        }while(k==0);
        if(k==-1)
        {
            break;
        }
        if(k==1)
        {
            gotoxy(1,22);
            textcolor(WHITE);
            printf("Press Any Key To Continue");
            _getch();
            while(1)
            {
                clrscr();
choice=adminMenu();
if(choice==7)
{
    clrscr();
    break;
    break;
}
switch(choice)
{
case 1:
    clrscr();
addEmployee();
    break;
case 2:
    clrscr();
addCarDetails();
    break;
case 3:
    clrscr();
    viewEmployee();
    break;
case 4:
    clrscr();
    showCarDetails();
    break;
case 5:
    clrscr();
                           result=deleteEmp();
                                 gotoxy(15,14);
                                 if(result==0)
                                  {
                                     textcolor(LIGHTRED);
                                     printf("Sorry! No emp found for given emp id");

                                   }
                                 else if(result==1)
                                  {
                                     textcolor(LIGHTGREEN);
                                      printf("Record deleted successfully!");
                                  }
                                  else if(result==2)
                                   {
                                      textcolor(LIGHTRED);
                                       printf("Sorry! Error in deletion. Try again!");
                                   }
                                   textcolor(WHITE);
                                   printf("\n\nPress any key to go back to the main screen!");
                                   getch();
                                   break;
case 6:
    clrscr();
result=deleteCarModel();
                                 gotoxy(15,14);
                                 if(result==0)
                                  {
                                     textcolor(LIGHTRED);
                                     printf("Sorry! No car found for given car id");

                                   }
                                 else if(result==1)
                                  {
                                     textcolor(LIGHTGREEN);
                                      printf("Record deleted successfully!");
                                  }
                                  else if(result==2)
                                   {
                                      textcolor(LIGHTRED);
                                       printf("Sorry! Error in deletion. Try again!");
                                   }
                                   textcolor(WHITE);
                                   printf("\n\nPress any key to go back to the main screen!");
                                   getch();
                                   break;
default:
    printf("incorrect choice");
}
            }
        }
    }
    else if(type==2)
    {
        clrscr();
        do
        {
         usr= getInput();
          if(usr!=NULL)
        {
            k= checkUserExist(*usr,"emp");
        }
        else
            break;
        }while(k==0);
        if(k==-1)
        {
            break;
        }
        if(k==1)
        {
            gotoxy(1,22);
            textcolor(WHITE);
            printf("Press Any Key To Continue");
            _getch();
            while(1)
            {
                clrscr();
choice=empMenu();
if(choice==5)
{
    clrscr();
    break;
}
switch(choice)
{
case 1:
    clrscr();

    break;
case 2:
    clrscr();

    break;
case 3:
    clrscr();

    break;
case 4:
    clrscr();

    break;
default:
    printf("INCORRECT CHOICE");
}
            }
    }
    }
    else if(type==3)
    {
        clrscr();
        gotoxy(27,12);
        textcolor(BLUE);
        printf("THANK YOU FOR USING THE APP!");
    }
    else
    {
         textcolor(RED);
        gotoxy(30,19);
    printf("INVALID CHOICE!");
    getch();
    gotoxy(30,19);
    printf("\t\t\t");
    gotoxy(49,13);
    printf("\t\t\t");
    textcolor(WHITE);
    gotoxy(49,13);
    }
}while(1);
return 0;
}
