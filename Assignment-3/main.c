#include <stdio.h>

// Function Prototypes
void displayAddress();
void swapNumbers(int *a, int *b);
void traverseArray(int arr[], int n);
void pointerArithmetic(int arr[], int n);

// Display Memory Address and Dereferencing
void displayAddress()
{
    int number;

    printf("\nEnter a Number : ");
    scanf("%d", &number);

    int *ptr = &number;

    printf("\nValue of Number = %d\n", number);
    printf("Address of Number = %p\n", &number);
    printf("Value Stored in Pointer = %p\n", ptr);
    printf("Dereferenced Value = %d\n", *ptr);
}

// Swap Two Numbers Using Pointers
void swapNumbers(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

// Traverse Array Using Pointer
void traverseArray(int arr[], int n)
{
    int i;
    int *ptr = arr;

    printf("\nArray Elements:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", *(ptr + i));
    }

    printf("\n");
}

// Demonstrate Pointer Arithmetic
void pointerArithmetic(int arr[], int n)
{
    int i;
    int *ptr = arr;

    printf("\nPointer Arithmetic:\n");

    for (i = 0; i < n; i++)
    {
        printf("Address = %p   Value = %d\n",
               (ptr + i), *(ptr + i));
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n====== POINTER PLAYGROUND ======\n");
        printf("1. Display Address and Dereference Pointer\n");
        printf("2. Swap Two Numbers\n");
        printf("3. Traverse Array Using Pointer\n");
        printf("4. Pointer Arithmetic\n");
        printf("5. Exit\n");

        printf("\nEnter Your Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            displayAddress();
            break;
        }

        case 2:
        {
            int a, b;

            printf("\nEnter First Number : ");
            scanf("%d", &a);

            printf("Enter Second Number : ");
            scanf("%d", &b);

            printf("\nBefore Swapping:");
            printf("\na = %d", a);
            printf("\nb = %d\n", b);

            swapNumbers(&a, &b);

            printf("\nAfter Swapping:");
            printf("\na = %d", a);
            printf("\nb = %d\n", b);

            break;
        }

        case 3:
        {
            int n, i;

            printf("\nEnter Size of Array : ");
            scanf("%d", &n);

            int arr[n];

            for (i = 0; i < n; i++)
            {
                printf("Enter Element %d : ", i + 1);
                scanf("%d", &arr[i]);
            }

            traverseArray(arr, n);

            break;
        }

        case 4:
        {
            int n, i;

            printf("\nEnter Size of Array : ");
            scanf("%d", &n);

            int arr[n];

            for (i = 0; i < n; i++)
            {
                printf("Enter Element %d : ", i + 1);
                scanf("%d", &arr[i]);
            }

            pointerArithmetic(arr, n);

            break;
        }

        case 5:
        {
            printf("\nProgram Terminated Successfully.\n");
            break;
        }

        default:
            printf("\nInvalid Choice.\n");
        }

    } while (choice != 5);

    return 0;
}