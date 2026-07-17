#include <stdio.h>
#include <string.h>

#define MAX 100

// Structure Definition
struct Employee
{
    int id;
    char name[50];
    float basicSalary;
    float hra;
    float da;
    float tax;
    float grossSalary;
    float netSalary;
};

// Calculate Salary Details
void calculateSalary(struct Employee *emp)
{
    emp->hra = emp->basicSalary * 0.20;
    emp->da = emp->basicSalary * 0.10;

    emp->grossSalary =
        emp->basicSalary + emp->hra + emp->da;

    emp->tax = emp->grossSalary * 0.05;

    emp->netSalary =
        emp->grossSalary - emp->tax;
}

// Add Employee
void addEmployee(struct Employee employees[],
                 int *count)
{
    if (*count >= MAX)
    {
        printf("\nEmployee Limit Reached.\n");
        return;
    }

    printf("\nEnter Employee ID : ");
    scanf("%d", &employees[*count].id);

    printf("Enter Employee Name : ");
    scanf(" %[^\n]", employees[*count].name);

    printf("Enter Basic Salary : ");
    scanf("%f", &employees[*count].basicSalary);

    calculateSalary(&employees[*count]);

    (*count)++;

    printf("\nEmployee Added Successfully.\n");
}

// Display Salary Report
void displayEmployees(struct Employee employees[],
                      int count)
{
    int i;

    if (count == 0)
    {
        printf("\nNo Employee Records Found.\n");
        return;
    }

    printf("\n-------- EMPLOYEE PAYROLL REPORT --------\n");

    for (i = 0; i < count; i++)
    {
        printf("\nEmployee %d\n", i + 1);
        printf("ID            : %d\n",
               employees[i].id);

        printf("Name          : %s\n",
               employees[i].name);

        printf("Basic Salary  : %.2f\n",
               employees[i].basicSalary);

        printf("HRA           : %.2f\n",
               employees[i].hra);

        printf("DA            : %.2f\n",
               employees[i].da);

        printf("Tax           : %.2f\n",
               employees[i].tax);

        printf("Gross Salary  : %.2f\n",
               employees[i].grossSalary);

        printf("Net Salary    : %.2f\n",
               employees[i].netSalary);
    }
}

// Search Employee
void searchEmployee(struct Employee employees[],
                    int count)
{
    int id;
    int i;

    printf("\nEnter Employee ID : ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (employees[i].id == id)
        {
            printf("\nEmployee Found\n");

            printf("Name         : %s\n",
                   employees[i].name);

            printf("Net Salary   : %.2f\n",
                   employees[i].netSalary);

            return;
        }
    }

    printf("\nEmployee Not Found.\n");
}

// Sort Employees by Net Salary
void sortEmployees(struct Employee employees[],
                   int count)
{
    int i, j;
    struct Employee temp;

    for (i = 0; i < count - 1; i++)
    {
        for (j = 0; j < count - i - 1; j++)
        {
            if (employees[j].netSalary >
                employees[j + 1].netSalary)
            {
                temp = employees[j];

                employees[j] =
                    employees[j + 1];

                employees[j + 1] = temp;
            }
        }
    }

    printf("\nEmployees Sorted Successfully.\n");
}

int main()
{
    struct Employee employees[MAX];

    int count = 0;
    int choice;

    do
    {
        printf("\n====== EMPLOYEE PAYROLL SYSTEM ======\n");

        printf("1. Add Employee\n");
        printf("2. Display Payroll Report\n");
        printf("3. Search Employee\n");
        printf("4. Sort by Salary\n");
        printf("5. Exit\n");

        printf("\nEnter Your Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addEmployee(employees, &count);
            break;

        case 2:
            displayEmployees(employees,
                             count);
            break;

        case 3:
            searchEmployee(employees,
                           count);
            break;

        case 4:
            sortEmployees(employees,
                          count);

            displayEmployees(employees,
                             count);
            break;

        case 5:
            printf("\nProgram Terminated Successfully.\n");
            break;

        default:
            printf("\nInvalid Choice.\n");
        }

    } while (choice != 5);

    return 0;
}