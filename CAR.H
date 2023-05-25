#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED
#include<time.h>
struct user
{
    char userid[20];
    char pwd[20];
    char name[20];
};
struct car
{
    int car_id;
    char car_name[50];
    int capacity;
    int car_count;
    int price;
};
 struct customer_car_details
{
    char cust_name[30];
    char pick[30];
    struct tm sd;
    struct tm ed;
};
typedef struct user user;
typedef struct car car;
typedef struct customer_car_details customer_car_details;
void addAdmin();
user* getInput();
int checkUserExist(user,char*);
int adminMenu();
int empMenu();
void addEmployee();
void addCarDetails();
void viewEmployee();
void showCarDetails();
int deleteEmp();
int deleteCarModel();
int selectCarModel();
#endif // CAR_H_INCLUDED
