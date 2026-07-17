#include <stdio.h>
#include <string.h>

#define MAX 100

// Structure Definition
struct Student
{
    int id;
    char name[50];
    float marks;
};

// Add Student Records
void addStudent(struct Student students[], int *count)
{
    if (*count >= MAX)
    {
        printf("\nRecord Limit Reached.\n");
        return;
    }

    printf("\nEnter Student ID : ");
    scanf("%d", &students[*count].id);

    printf("Enter Student Name : ");
    scanf(" %[^\n]", students[*count].name);

    printf("Enter Student Marks : ");
    scanf("%f", &students[*count].marks);

    (*count)++;

    printf("\nStudent Added Successfully.\n");
}

// Display Records
void displayStudents(struct Student students[], int count)
{
    int i;

    if (count == 0)
    {
        printf("\nNo Records Found.\n");
        return;
    }

    printf("\n----- STUDENT RECORDS -----\n");

    for (i = 0; i < count; i++)
    {
        printf("\nStudent %d\n", i + 1);
        printf("ID    : %d\n", students[i].id);
        printf("Name  : %s\n", students[i].name);
        printf("Marks : %.2f\n", students[i].marks);
    }
}

// Search Student
void searchStudent(struct Student students[], int count)
{
    int id;
    int i;
    int found = 0;

    printf("\nEnter Student ID : ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (students[i].id == id)
        {
            printf("\nRecord Found\n");
            printf("ID    : %d\n", students[i].id);
            printf("Name  : %s\n", students[i].name);
            printf("Marks : %.2f\n", students[i].marks);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nStudent Not Found.\n");
    }
}

// Update Record
void updateStudent(struct Student students[], int count)
{
    int id;
    int i;

    printf("\nEnter Student ID : ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (students[i].id == id)
        {
            printf("\nEnter New Name : ");
            scanf(" %[^\n]", students[i].name);

            printf("Enter New Marks : ");
            scanf("%f", &students[i].marks);

            printf("\nRecord Updated Successfully.\n");
            return;
        }
    }

    printf("\nStudent Not Found.\n");
}

// Delete Record
void deleteStudent(struct Student students[], int *count)
{
    int id;
    int i, j;

    printf("\nEnter Student ID : ");
    scanf("%d", &id);

    for (i = 0; i < *count; i++)
    {
        if (students[i].id == id)
        {
            for (j = i; j < *count - 1; j++)
            {
                students[j] = students[j + 1];
            }

            (*count)--;

            printf("\nRecord Deleted Successfully.\n");
            return;
        }
    }

    printf("\nStudent Not Found.\n");
}

int main()
{
    struct Student students[MAX];

    int count = 0;
    int choice;

    do
    {
        printf("\n====== STUDENT MANAGEMENT SYSTEM ======\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");

        printf("\nEnter Your Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addStudent(students, &count);
            break;

        case 2:
            displayStudents(students, count);
            break;

        case 3:
            searchStudent(students, count);
            break;

        case 4:
            updateStudent(students, count);
            break;

        case 5:
            deleteStudent(students, &count);
            break;

        case 6:
            printf("\nProgram Terminated Successfully.\n");
            break;

        default:
            printf("\nInvalid Choice.\n");
        }

    } while (choice != 6);

    return 0;
}