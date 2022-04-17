#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct employee
{
    char name[30];
	char family_name[30];
    int year_of_birth;                   //Data of the node
    struct employee *nextper;       //Address of the node
}*stemployee;

void create_employee_list(int n); // function to create the list
void display_list();         // function to display the list

int main()
{
    int n;
    printf("\n\n Employees List : To create and display List Of Employees :\n");
    printf("-------------------------------------------------------------\n");
    printf(" Input the number of employees : ");
    scanf("%d", &n);
    create_employee_list(n);
    printf("\n Data entered in the list : \n");
    displayList();
    return 0;
}
void create_employee_list(int n)
{
    struct employee *fnemployee, *tmp;
    int num, i;
	char name[30];
	char family_name[30];
    stemployee = (struct employee *)malloc(sizeof(struct employee));

    if(stemployee == NULL) //check whether the fnemployee is NULL and if so no memory allocation
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
// reads data for the employee through keyboard

        printf(" Input first name,last name,year of birth for employee 1 : ");
        scanf("%s", name);
        scanf("%s",family_name);
        scanf("%d", &num);
        strcpy(stemployee->name,name);
        strcpy(stemployee->family_name,family_name);
        stemployee->year_of_birth = num;

        stemployee->nextper = NULL; // links the address field to NULL
        tmp = stemployee;
// Creating n employees and adding to linked list
        for(i=2; i<=n; i++)
        {
            fnemployee = (struct employee *)malloc(sizeof(struct employee));
            if(fnemployee == NULL)
            {
                printf(" Memory can not be allocated.");
                break;
            }
            else
            {
                printf(" Input first name,last name,year of birth for employee %d : ", i);
                scanf("%s", name);
			    scanf("%s",family_name);
                scanf("%d", &num);
                strcpy(fnemployee->name,name);
			    strcpy(fnemployee->family_name,family_name);
                fnemployee->year_of_birth = num;     // links the num field of fnemployee with num
                fnemployee->nextper = NULL; // links the address field of fnemployee with NULL
                tmp->nextper = fnemployee; // links previous employee i.e. tmp to the fnemployee
                tmp = tmp->nextper;
            }
        }
    }
}
void displayList()
{
    struct employee *tmp;
    if(stemployee == NULL)
    {
        printf(" List is empty.");
    }
    else
    {
        tmp = stemployee;
        while(tmp != NULL)
        {
            printf("Name: %s ,Family Name: %s,Year Of Birth: %d\n",tmp->name,tmp->family_name,tmp->year_of_birth);      // prints the data of current employee
            tmp = tmp->nextper;                     // advances the position of current employee
        }
    }
}
