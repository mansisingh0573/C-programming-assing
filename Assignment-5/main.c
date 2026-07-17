#include <stdio.h>
#include <stdlib.h>

// Function Prototypes
void displayMarks(int *marks, int n);
void calculateStatistics(int *marks, int n);

// Display Marks
void displayMarks(int *marks, int n)
{
    int i;

    printf("\nStudent Marks:\n");

    for (i = 0; i < n; i++)
    {
        printf("Student %d = %d\n", i + 1, marks[i]);
    }
}

// Calculate Statistics
void calculateStatistics(int *marks, int n)
{
    int i;
    int total = 0;
    int highest = marks[0];
    int lowest = marks[0];
    float average;

    for (i = 0; i < n; i++)
    {
        total += marks[i];

        if (marks[i] > highest)
        {
            highest = marks[i];
        }

        if (marks[i] < lowest)
        {
            lowest = marks[i];
        }
    }

    average = (float)total / n;

    printf("\n------ STATISTICS ------\n");
    printf("Highest Marks : %d\n", highest);
    printf("Lowest Marks  : %d\n", lowest);
    printf("Total Marks   : %d\n", total);
    printf("Average Marks : %.2f\n", average);
}

int main()
{
    int *marks;
    int n;
    int i;
    int choice;

    printf("Enter Number of Students : ");
    scanf("%d", &n);

    // Dynamic Memory Allocation
    marks = (int *)malloc(n * sizeof(int));

    if (marks == NULL)
    {
        printf("\nMemory Allocation Failed.\n");
        return 1;
    }

    // Input Marks
    for (i = 0; i < n; i++)
    {
        printf("Enter Marks of Student %d : ", i + 1);
        scanf("%d", &marks[i]);
    }

    do
    {
        printf("\n====== DYNAMIC ARRAY MANAGEMENT ======\n");
        printf("1. Display Marks\n");
        printf("2. Calculate Statistics\n");
        printf("3. Exit\n");

        printf("\nEnter Your Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            displayMarks(marks, n);
            break;

        case 2:
            calculateStatistics(marks, n);
            break;

        case 3:
            printf("\nMemory Released Successfully.\n");
            break;

        default:
            printf("\nInvalid Choice.\n");
        }

    } while (choice != 3);

    // Free Allocated Memory
    free(marks);

    return 0;
}