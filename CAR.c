#include<stdio.h>
#include"conio2.h"
#include"CAR.H"
#include<string.h>
void addAdmin()
{
    FILE * fp=fopen("admin.bin","rb");
    if(fp==NULL)
    {
        fp=fopen("admin.bin","wb");
        user u[2]={{"vinayak","avvhjpig","ramesh"},{"ram","abc","Md aftab ahmad"}};
        fwrite(u,sizeof(u),1,fp);
        printf("file saved");
        fclose(fp);
        _getch();
    }
    else
        fclose(fp);
}
        user * getInput()
        {
            int i;
            clrscr();
            textcolor(YELLOW);
            gotoxy(30,1);
            printf("CAR RENTAL SYSTEM");
            gotoxy(1,3);
            for(i=0;i<80;i++)
            {
                printf("%c",247);
            }
            textcolor(YELLOW);
            gotoxy(30,7);
            printf("*   LOGIN PANEL   *");
            textcolor(LIGHTCYAN);
            gotoxy(1,9);
            for(i=0;i<80;i++)
            {
                printf("%c",247);
            }
            gotoxy(1,20);
            for(i=0;i<80;i++)
            {
                printf("%c",247);
            }
            textcolor(WHITE);
            gotoxy(60,10);
            printf("press 0 to exit");
            textcolor(LIGHTCYAN);
            gotoxy(25,11);
            printf("Enter user id :");
            fflush(stdin);
            textcolor(WHITE);
            static user usr;
            fgets(usr.userid,20,stdin);
            char *pos=strchr(usr.userid,'\n');
            if(pos!=NULL)
            {
                *pos='\0';
            }
            if(strcmp(usr.userid,"0")==0)
            {
                textcolor(RED);
                gotoxy(30,21);
                printf("Login cancelled!!");
                getch();
                textcolor(YELLOW);
                return NULL;
            }
    textcolor(LIGHTCYAN);
    gotoxy(25,12);
    printf("Enter password:");
    fflush(stdin);
    i=0;
    textcolor(WHITE);
    for(;;)
    {
    usr.pwd[i]=getch();
    if(usr.pwd[i]==13)
    {
        break;
    }
    if(usr.pwd[i]=='\b')
    {
        printf("\b \b");
        i--;
        continue;
    }
    printf("*");
    i++;
    }
    usr.pwd[i]='\0';
 if(strcmp(usr.pwd,"0")==0)
 {
     textcolor(RED);
     gotoxy(30,21);
     printf("Login cancelled!!");
     getch();
     textcolor(YELLOW);
return NULL;
 }
 return &usr;
        }
        int checkUserExist(user u,char* usertype)
        {
            if(strlen(u.userid)==0||strlen(u.pwd)==0)
            {
                gotoxy(26,22);
                textcolor(RED);
                printf("BOTH FIELDS ARE MENDATORY TRY AGAIN!");
                getch();
                gotoxy(26,22);
                printf("\t\t\t\t");
                return 0;
            }
            FILE* fp;
            if(strcmp(usertype,"admin")==0)
            {
                fp=fopen("admin.bin","rb");
            }
            else
            {
                fp=fopen("emp.bin","rb");
            }
            if(fp==NULL)
            {
                gotoxy(26,22);
                textcolor(RED);
                printf("SORRY CANNOT OPEN THE FILE");
                getch();
                gotoxy(26,22);
                printf("\t\t\t\t\t");
                return -1;
            }
            int found=0;
            user user;
            while(fread(&user,sizeof(user),1,fp)==1)
                  {
                      if(strcmp(u.userid,user.userid)==0 && strcmp(u.pwd,user.pwd)==0)
                    {
                        found=1;
                        break;
                    }
                  }
                  if(found==0)
                  {
                      gotoxy(26,22);
                      textcolor(RED);
                      printf("INVALID USERID OR PASSWRORD,TRY AGAIN!");
                      getch();
                      gotoxy(26,22);
                      printf("\t\t\t\t\t");
                  }
            else
            {
                gotoxy(26,22);
                textcolor(GREEN);
                printf("LOGIN SUCCCESSFUL");
                getch();
                gotoxy(26,22);
                printf("\t\t\t\t\t\t");
            }
            fclose(fp);
            return found;
            }
int adminMenu()
{
    int choice,i;
    textcolor(RED);
    gotoxy(32,2);
    printf("CAR RENTAL SYSTEM");
    textcolor(LIGHTGREEN);
    gotoxy(35,6);
    printf("ADMIN MENU\n");
    for(i=0;i<80;i++)
    {
        printf("*");
    }
    textcolor(YELLOW);
    gotoxy(32,8);
    printf("1. Add Employee\n");
    gotoxy(32,9);
    printf("2. Add Car Details\n");
    gotoxy(32,10);
    printf("3. Show Employee\n");
    gotoxy(32,11);
    printf("4. Show Car Details\n");
    gotoxy(32,12);
    printf("5. Delete Employee\n");
    gotoxy(32,13);
    printf("6. Delete Car Details\n");
    gotoxy(32,14);
    printf("7. Exit\n\n");
    gotoxy(32,16);
    textcolor(WHITE);
    printf("Enter Choice :");
    scanf("%d",&choice);
return choice;
}
void addEmployee()
{
    char empid[10]="EMP-";
    char temp[10];
    char uchoice;
    FILE* fp=fopen("emp.bin","ab+");
    fseek(fp,0,SEEK_END);
    int  totalrec=ftell(fp)/sizeof(user);
    totalrec++;
    sprintf(temp,"%d",totalrec);
    strcat(empid,temp);
    user u;
    strcpy(u.userid,empid);
    do
    {
        clrscr();
        gotoxy(32,2);
        textcolor(RED);
        printf("CAR RENTAL APP");
        textcolor(LIGHTGREEN);
        int i;
        gotoxy(1,3);
        for(i=0;i<80;i++)
        {
        printf("~");
    }
       textcolor(WHITE);
       gotoxy(25,5);
       printf("****ADD EMPLOYEE DETAILS****");
       gotoxy(1,8);
       textcolor(YELLOW);
       printf("Enter Employee Name:");
       fflush(stdin);
       textcolor(WHITE);
       fgets(u.name,20,stdin);
       char*pos;
       pos=strchr(u.name,'\n');
       *pos='\0';
       textcolor(YELLOW);
       printf("Enter Employee password:");
       fflush(stdin);
       textcolor(WHITE);
       fgets(u.pwd,20,stdin);
       pos=strchr(u.pwd,'\n');
       *pos='\0';
       textcolor(YELLOW);
       fseek(fp,0,SEEK_END);
       fwrite(&u,sizeof(user),1,fp);
       gotoxy(30,15);
       textcolor(LIGHTGREEN);
       printf("Employee Added Successfully!\n");
       printf("EMPLOYEE ID IS :%s",u.userid);
       _getch();
       gotoxy(1,20);
       textcolor(RED);
       printf("DO YOU WANT TO ADD MORE EMPLOYEES(Y/N)?");
       textcolor(WHITE);
       fflush(stdin);
       scanf("%c",&uchoice);
       totalrec++;
       strcpy(empid,"EMP-");
       sprintf(temp,"%d",totalrec);
       strcat(empid,temp);
       strcpy(u.userid,empid);
    }
    while(uchoice=='Y'||uchoice=='y');
       fclose(fp);
}
void addCarDetails()
{
    char cchoice;
    FILE*fp=fopen("car.bin","ab+");
    fseek(fp, 0, SEEK_END);
    int totalcar=ftell(fp)/sizeof(car);
    totalcar++;
    car c;
    c.car_id=totalcar;
do
{
    clrscr();
    textcolor(RED);
    gotoxy(32,1);
    printf("CAR RENTAL APP\n");
    int i;
    textcolor(BLUE);
    for(i=0;i<80;i++)
    {
        printf("~");
    }
    textcolor(LIGHTCYAN);
    gotoxy(25,6);
    printf("**** ADD CAR DETAILS ****");
    textcolor(YELLOW);
    gotoxy(1,10);
    printf("Enter Car Model :");
    fflush(stdin);
    textcolor(WHITE);
    fgets(c.car_name,50,stdin);
    char*pos;
       pos=strchr(c.car_name,'\n');
       if(pos!=NULL)
       *pos='\0';
       textcolor(YELLOW);
       printf("Enter Car Capacity :");
       fflush(stdin);
       textcolor(WHITE);
       scanf("%d",&c.capacity);
       textcolor(YELLOW);
       printf("Enter Car Count :");
       textcolor(WHITE);
       scanf("%d",&c.car_count);
       textcolor(YELLOW);
       printf("Enter Car Price For Per Day :");
       textcolor(WHITE);
       scanf("%d",&c.price);
 fseek(fp,0,SEEK_END);
       fwrite(&c,sizeof(car),1,fp);
       gotoxy(30,15);
       textcolor(LIGHTGREEN);
       printf("Car Added Successfully!\n");
       printf("CAR ID IS :%d",c.car_id);
       _getch();
       gotoxy(1,20);
       textcolor(RED);
       printf("DO YOU WANT TO ADD MORE CARS(Y/N)?");
       textcolor(WHITE);
       fflush(stdin);
       scanf("%c",&cchoice);
       totalcar++;
       c.car_id=totalcar;
}while(cchoice=='Y'||cchoice=='y');
fclose(fp);
}
void viewEmployee()
{
    FILE *fp=fopen("emp.bin","rb");
    user ur;
    int i;
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\n");
    for(i=1;i<=80;i++)
        printf("%c",247);
    gotoxy(31,5);
    printf("* EMPLOYEE DETAILS *");
    gotoxy(1,7);
    textcolor(LIGHTGREEN);
    for(i=1;i<=80;i++)
        printf("%c",247);
    if(fp==NULL)
    {
        gotoxy(31,9);
        textcolor(LIGHTRED);
        printf("Sorry! No employees added yet!");
        getch();
        return;
    }
    gotoxy(1,8);
    printf("Employee ID\t\t\tName\t\t\tPassword");
    gotoxy(1,9);
    for(i=1;i<=80;i++)
        printf("%c",247);
    int row=10;
    textcolor(YELLOW);
    while(fread(&ur,sizeof(ur),1,fp)==1)
    {
        gotoxy(2,row);
        printf("%s",ur.userid);
        gotoxy(33,row);
        printf("%s",ur.name);
        gotoxy(57,row);
        printf("%s",ur.pwd);
        row++;
    }
    fclose(fp);
    getch();
}
void showCarDetails()
{
    FILE *fp=fopen("car.bin","rb");
    car c;
    int i;
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\n");
    for(i=0;i<80;i++)
    {
        printf("%c",247);
    }
    gotoxy(31,5);
    textcolor(YELLOW);
    printf("ALL CAR DETAILS");
    gotoxy(1,7);
    textcolor(LIGHTGREEN);
    for(i=0;i<80;i++)
    {
        printf("%c",247);
    }
    if(fp==NULL)
    {
        gotoxy(31,9);
        textcolor(LIGHTRED);
        printf("sorry! no cars present");
        getch();
        return;
    }
    gotoxy(1,8);
    printf("Car ID\t\tModel\t\t\tCapacity\tAvailable\tPrice/Day");
    gotoxy(1,9);
    textcolor(LIGHTGREEN);
    for(i=1;i<80;i++)
    {
        printf("%c",247);
    }
    int x=10;
    textcolor(YELLOW);
    while(fread(&c,sizeof(c),1,fp)==1)
    {
        gotoxy(2,x);
        printf("%d",c.car_id);
        gotoxy(18,x);
        printf("%s",c.car_name);
        gotoxy(44,x);
        printf("%d",c.capacity);
        gotoxy(60,x);
        printf("%d",c.car_count);
        gotoxy(72,x);
        printf("%d",c.price);
        x++;
    }
    fclose(fp);
    _getch();
}
int deleteEmp()
{
     FILE *fp1=fopen("emp.bin","rb");
     char empid[10];
     int i,result;
     textcolor(YELLOW);
     gotoxy(32,1);
     printf("CAR RENTAL SYSTEM\n");
     for(i=1; i<=80; i++)
        printf("%c",247);
     gotoxy(29,5);
     textcolor(YELLOW);
     printf("* DELETE EMPLOYEE RECORD *");
     gotoxy(1,7);
     textcolor(LIGHTGREEN);
     for(i=1; i<=80; i++)
        printf("%c",247);
     gotoxy(1,12);
     for(i=1; i<80; i++)
        printf("%c",247);
     if(fp1==NULL)
     {
        textcolor(LIGHTRED);
        printf("\nNo Employee Added Yet!");
        return -1;
     }
    FILE *fp2=fopen("temp.bin","wb+");
    gotoxy(10,9);
    textcolor(YELLOW);
    printf("Enter Employee Id to delete the record:");
    textcolor(WHITE);
    scanf("%s",empid);
    user u;
    int found=0;
    while(fread(&u,sizeof(u),1,fp1)==1)
    {
        if(strcmp(u.userid,empid)!=0)
        {
            fwrite(&u,sizeof(u),1,fp2);
        }
        else
        {
            found=1;
        }
     }
    fclose(fp1);
    fclose(fp2);
     if(found==0)
    {
        remove("temp.bin");
    }
    else
    {
        result=remove("emp.bin");
        if(result!=0)
            return 2;
    result=rename("temp.bin","emp.bin");
        if(result!=0)
            return 2;
    }
    return found;
}
int deleteCarModel()
{
    FILE* fp1=fopen("car.bin","rb");
    int carid;
     int i,result;
     if(fp1==NULL)
     {
        textcolor(LIGHTRED);
        printf("\nNo Car Added Yet!");
        return -1;
     }
     textcolor(YELLOW);
     gotoxy(32,1);
     printf("CAR RENTAL SYSTEM\n");
     for(i=1; i<=80; i++)
        printf("%c",247);
     gotoxy(29,5);
     textcolor(YELLOW);
     printf("* DELETE CAR RECORD *");
     gotoxy(1,7);
     textcolor(LIGHTGREEN);
     for(i=1; i<=80; i++)
        printf("%c",247);
     gotoxy(1,12);
     for(i=1; i<80; i++)
        printf("%c",247);
    FILE *fp2=fopen("temp.bin","wb+");
    gotoxy(10,9);
    textcolor(YELLOW);
    printf("Enter Car Id to delete the record:");
    textcolor(WHITE);
    scanf("%d",&carid);
    car c;
    int found=0;
    while(fread(&c,sizeof(c),1,fp1)==1)
    {
        if(c.car_id!=carid)
        {
            fwrite(&c,sizeof(c),1,fp2);
        }
        else
        {
            found=1;
        }
     }
    fclose(fp1);
    fclose(fp2);
     if(found==0)
    {
        remove("temp.bin");
        return 0;
    }
    else
    {
        result=remove("car.bin");
        if(result!=0)
            return 2;
        result=rename("temp.bin","car.bin");
        if(result!=0)
            return 2;
    }
    return found;
}
int empMenu()
{
int choice,i;
textcolor(LIGHTRED);
 gotoxy(32,2);
  printf("CAR RENTAL SYSTEM");
  textcolor(LIGHTGREEN);
gotoxy(35,6);
printf("EMPLOYEE MENU\n");
for(i=0; i<80; i++)
{
printf("*");
}
textcolor(YELLOW);
gotoxy(32,8);
printf("1. Rent A Car");
gotoxy(32,9);
printf("2. Booking Details");
gotoxy(32,10);
printf("3. Available Car Details");
 gotoxy(32,11);
 printf("4. Show All Car Details");
  gotoxy(32,12); printf("5. Exit");
   gotoxy(32,15);
    printf("Enter choice:");
    textcolor(WHITE);
     scanf("%d",&choice);
      return choice;
}
int selectCarModel()
{
    int flag;
FILE *fp=fopen("car.bin","rb");
car c;
int choice,x=9;
gotoxy(34,x);
while(fread(&c,sizeof(c),1,fp)==1)
{
if(c.car_count>0)
{
printf("%d .%s",c.car_id,c.car_name);
gotoxy(34,++x);
}}
gotoxy(34,x+2);
printf("Enter your choice:");
while(1)
{
flag=0;
scanf("%d",&choice);
rewind(fp);
while(fread(&c,sizeof(c),1,fp)==1)
{
if(c.car_id==choice)
{
flag=1;
break;}
}
if(flag==1)
{
fclose(fp);
return choice;
}
else
{
gotoxy(37,x+4);
textcolor(LIGHTRED);
printf("Wrong Input");
_getch();
gotoxy(35,x+4);
 printf("\t\t");
  gotoxy(52,x+2);
   printf("\t");
    gotoxy(52,x+2);
     textcolor(WHITE);
} } }
