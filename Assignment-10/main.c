#include <stdio.h>

#define MAX 100

// Function Prototypes
void displayArray(int arr[], int n);
void largestElement(int arr[], int n);
void secondLargest(int arr[], int n);
void smallestElement(int arr[], int n);
void secondSmallest(int arr[], int n);
void reverseArray(int arr[], int n);
void removeDuplicates(int arr[], int *n);
void frequencyCount(int arr[], int n);
void linearSearch(int arr[], int n);
void sortArray(int arr[], int n);

// Display Array
void displayArray(int arr[], int n)
{
    int i;

    printf("\nArray Elements : ");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

// Largest Element
void largestElement(int arr[], int n)
{
    int i;
    int max = arr[0];

    for (i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    printf("\nLargest Element = %d\n", max);
}

// Second Largest Element
void secondLargest(int arr[], int n)
{
    int i;
    int largest = arr[0];
    int second = -1;

    for (i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            second = largest;
            largest = arr[i];
        }

        else if (arr[i] > second &&
                 arr[i] != largest)
        {
            second = arr[i];
        }
    }

    printf("\nSecond Largest = %d\n", second);
}

// Smallest Element
void smallestElement(int arr[], int n)
{
    int i;
    int min = arr[0];

    for (i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    printf("\nSmallest Element = %d\n", min);
}

// Second Smallest Element
void secondSmallest(int arr[], int n)
{
    int i;
    int smallest = arr[0];
    int second = 999999;

    for (i = 1; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            second = smallest;
            smallest = arr[i];
        }

        else if (arr[i] < second &&
                 arr[i] != smallest)
        {
            second = arr[i];
        }
    }

    printf("\nSecond Smallest = %d\n", second);
}

// Reverse Array
void reverseArray(int arr[], int n)
{
    int start = 0;
    int end = n - 1;
    int temp;

    while (start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }

    printf("\nArray Reversed Successfully.\n");
}

// Remove Duplicate Elements
void removeDuplicates(int arr[], int *n)
{
    int i, j, k;

    for (i = 0; i < *n; i++)
    {
        for (j = i + 1; j < *n; j++)
        {
            if (arr[i] == arr[j])
            {
                for (k = j; k < *n - 1; k++)
                {
                    arr[k] = arr[k + 1];
                }

                (*n)--;
                j--;
            }
        }
    }

    printf("\nDuplicates Removed Successfully.\n");
}

// Frequency Count
void frequencyCount(int arr[], int n)
{
    int visited[MAX] = {0};
    int i, j, count;

    printf("\nElement Frequencies\n");

    for (i = 0; i < n; i++)
    {
        if (visited[i] == 1)
        {
            continue;
        }

        count = 1;

        for (j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
                visited[j] = 1;
            }
        }

        printf("%d -> %d times\n",
               arr[i], count);
    }
}

// Linear Search
void linearSearch(int arr[], int n)
{
    int key;
    int i;

    printf("\nEnter Element : ");
    scanf("%d", &key);

    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            printf("\nElement Found at Index %d\n", i);
            return;
        }
    }

    printf("\nElement Not Found.\n");
}

// Bubble Sort
void sortArray(int arr[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("\nArray Sorted Successfully.\n");
}

int main()
{
    int arr[MAX];
    int n;
    int choice;
    int i;

    printf("Enter Size of Array : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter Element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    do
    {
        printf("\n====== LEETCODE ARRAY CHALLENGE ======\n");

        printf("1. Largest Element\n");
        printf("2. Second Largest\n");
        printf("3. Smallest Element\n");
        printf("4. Second Smallest\n");
        printf("5. Reverse Array\n");
        printf("6. Remove Duplicates\n");
        printf("7. Frequency Count\n");
        printf("8. Search Element\n");
        printf("9. Sort Array\n");
        printf("10. Display Array\n");
        printf("11. Exit\n");

        printf("\nEnter Your Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            largestElement(arr, n);
            break;

        case 2:
            secondLargest(arr, n);
            break;

        case 3:
            smallestElement(arr, n);
            break;

        case 4:
            secondSmallest(arr, n);
            break;

        case 5:
            reverseArray(arr, n);
            break;

        case 6:
            removeDuplicates(arr, &n);
            break;

        case 7:
            frequencyCount(arr, n);
            break;

        case 8:
            linearSearch(arr, n);
            break;

        case 9:
            sortArray(arr, n);
            break;

        case 10:
            displayArray(arr, n);
            break;

        case 11:
            printf("\nProgram Terminated Successfully.\n");
            break;

        default:
            printf("\nInvalid Choice.\n");
        }

    } while (choice != 11);

    return 0;
}