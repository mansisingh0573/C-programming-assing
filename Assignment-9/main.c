#include <stdio.h>
#include <stdlib.h>

// Function Prototypes
void displayArray(int *arr, int size);
void insertElement(int **arr, int *size);
void deleteElement(int *arr, int *size);
void updateElement(int *arr, int size);
void linearSearch(int *arr, int size);
void binarySearch(int *arr, int size);
void sortArray(int *arr, int size);

// Display Array
void displayArray(int *arr, int size)
{
    int i;

    if (size == 0)
    {
        printf("\nArray is Empty.\n");
        return;
    }

    printf("\nArray Elements:\n");

    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

// Insert Element
void insertElement(int **arr, int *size)
{
    int value;

    printf("\nEnter Element : ");
    scanf("%d", &value);

    *arr = realloc(*arr, (*size + 1) * sizeof(int));

    (*arr)[*size] = value;

    (*size)++;

    printf("\nElement Inserted Successfully.\n");
}

// Delete Element
void deleteElement(int *arr, int *size)
{
    int value;
    int i, j;

    if (*size == 0)
    {
        printf("\nArray is Empty.\n");
        return;
    }

    printf("\nEnter Element to Delete : ");
    scanf("%d", &value);

    for (i = 0; i < *size; i++)
    {
        if (arr[i] == value)
        {
            for (j = i; j < *size - 1; j++)
            {
                arr[j] = arr[j + 1];
            }

            (*size)--;

            printf("\nElement Deleted Successfully.\n");
            return;
        }
    }

    printf("\nElement Not Found.\n");
}

// Update Element
void updateElement(int *arr, int size)
{
    int oldValue, newValue;
    int i;

    if (size == 0)
    {
        printf("\nArray is Empty.\n");
        return;
    }

    printf("\nEnter Existing Element : ");
    scanf("%d", &oldValue);

    for (i = 0; i < size; i++)
    {
        if (arr[i] == oldValue)
        {
            printf("Enter New Element : ");
            scanf("%d", &newValue);

            arr[i] = newValue;

            printf("\nElement Updated Successfully.\n");
            return;
        }
    }

    printf("\nElement Not Found.\n");
}

// Linear Search
void linearSearch(int *arr, int size)
{
    int value;
    int i;

    printf("\nEnter Element to Search : ");
    scanf("%d", &value);

    for (i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            printf("\nElement Found at Index %d\n", i);
            return;
        }
    }

    printf("\nElement Not Found.\n");
}

// Sort Array (Bubble Sort)
void sortArray(int *arr, int size)
{
    int i, j, temp;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Binary Search
void binarySearch(int *arr, int size)
{
    int value;
    int low, high, mid;

    if (size == 0)
    {
        printf("\nArray is Empty.\n");
        return;
    }

    sortArray(arr, size);

    printf("\nEnter Element to Search : ");
    scanf("%d", &value);

    low = 0;
    high = size - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == value)
        {
            printf("\nElement Found at Index %d\n", mid);
            return;
        }

        else if (arr[mid] < value)
        {
            low = mid + 1;
        }

        else
        {
            high = mid - 1;
        }
    }

    printf("\nElement Not Found.\n");
}

int main()
{
    int *arr = NULL;
    int size = 0;
    int choice;

    do
    {
        printf("\n====== DYNAMIC ARRAY OPERATIONS ======\n");

        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Update Element\n");
        printf("4. Display Array\n");
        printf("5. Linear Search\n");
        printf("6. Binary Search\n");
        printf("7. Exit\n");

        printf("\nEnter Your Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertElement(&arr, &size);
            break;

        case 2:
            deleteElement(arr, &size);
            break;

        case 3:
            updateElement(arr, size);
            break;

        case 4:
            displayArray(arr, size);
            break;

        case 5:
            linearSearch(arr, size);
            break;

        case 6:
            binarySearch(arr, size);
            break;

        case 7:
            printf("\nProgram Terminated Successfully.\n");
            break;

        default:
            printf("\nInvalid Choice.\n");
        }

    } while (choice != 7);

    free(arr);

    return 0;
}