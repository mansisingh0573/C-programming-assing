#include <stdio.h>

#define MAX 100

// Function Prototypes
void displayMarks(int marks[], int n);
void highestMarks(int marks[], int n);
void lowestMarks(int marks[], int n);
void totalMarks(int marks[], int n);
void averageMarks(int marks[], int n);
void searchMarks(int marks[], int n, int key);
void sortMarks(int marks[], int n);

// Display Marks
void displayMarks(int marks[], int n)
{
    int i;

    printf("\nStudent Marks:\n");

    for (i = 0; i < n; i++)
    {
        printf("Student %d = %d\n", i + 1, marks[i]);
    }
}

// Highest Marks
void highestMarks(int marks[], int n)
{
    int i, max = marks[0];

    for (i = 1; i < n; i++)
    {
        if (marks[i] > max)
        {
            max = marks[i];
        }
    }

    printf("\nHighest Marks = %d\n", max);
}

// Lowest Marks
void lowestMarks(int marks[], int n)
{
    int i, min = marks[0];

    for (i = 1; i < n; i++)
    {
        if (marks[i] < min)
        {
            min = marks[i];
        }
    }

    printf("\nLowest Marks = %d\n", min);
}

// Total Marks
void totalMarks(int marks[], int n)
{
    int i, total = 0;

    for (i = 0; i < n; i++)
    {
        total += marks[i];
    }

    printf("\nTotal Marks = %d\n", total);
}

// Average Marks
void averageMarks(int marks[], int n)
{
    int i, total = 0;
    float average;

    for (i = 0; i < n; i++)
    {
        total += marks[i];
    }

    average = (float)total / n;

    printf("\nAverage Marks = %.2f\n", average);
}

// Search Marks
void searchMarks(int marks[], int n, int key)
{
    int i, found = 0;

    for (i = 0; i < n; i++)
    {
        if (marks[i] == key)
        {
            printf("\nMarks Found at Student %d\n", i + 1);
            found = 1;
        }
    }

    if (!found)
    {
        printf("\nMarks Not Found.\n");
    }
}

// Sort Marks (Ascending Order)
void sortMarks(int marks[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (marks[j] > marks[j + 1])
            {
                temp = marks[j];
                marks[j] = marks[j + 1];
                marks[j + 1] = temp;
            }
        }
    }

    printf("\nMarks Sorted Successfully.\n");
}

// Main Function
int main()
{
    int marks[MAX];
    int n;
    int choice;
    int key;
    int i;

    printf("Enter Number of Students : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter Marks of Student %d : ", i + 1);
        scanf("%d", &marks[i]);
    }

    do
    {
        printf("\n====== STUDENT MARKS ANALYZER ======\n");
        printf("1. Display Marks\n");
        printf("2. Highest Marks\n");
        printf("3. Lowest Marks\n");
        printf("4. Total Marks\n");
        printf("5. Average Marks\n");
        printf("6. Search Marks\n");
        printf("7. Sort Marks\n");
        printf("8. Exit\n");

        printf("\nEnter Your Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            displayMarks(marks, n);
            break;

        case 2:
            highestMarks(marks, n);
            break;

        case 3:
            lowestMarks(marks, n);
            break;

        case 4:
            totalMarks(marks, n);
            break;

        case 5:
            averageMarks(marks, n);
            break;

        case 6:
            printf("Enter Marks to Search : ");
            scanf("%d", &key);
            searchMarks(marks, n, key);
            break;

        case 7:
            sortMarks(marks, n);
            displayMarks(marks, n);
            break;

        case 8:
            printf("\nProgram Terminated Successfully.\n");
            break;

        default:
            printf("\nInvalid Choice.\n");
        }

    } while (choice != 8);

    return 0;
}