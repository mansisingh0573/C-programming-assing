#include <stdio.h>
#include <string.h>

#define MAX 100

// Structure Definition
struct Product
{
    int id;
    char name[50];
    float price;
    int quantity;
};

// Add Product
void addProduct(struct Product products[], int *count)
{
    if (*count >= MAX)
    {
        printf("\nInventory is Full.\n");
        return;
    }

    printf("\nEnter Product ID : ");
    scanf("%d", &products[*count].id);

    printf("Enter Product Name : ");
    scanf(" %[^\n]", products[*count].name);

    printf("Enter Product Price : ");
    scanf("%f", &products[*count].price);

    printf("Enter Quantity : ");
    scanf("%d", &products[*count].quantity);

    (*count)++;

    printf("\nProduct Added Successfully.\n");
}

// Display Products
void displayProducts(struct Product products[], int count)
{
    int i;

    if (count == 0)
    {
        printf("\nNo Products Available.\n");
        return;
    }

    printf("\n------ PRODUCT DETAILS ------\n");

    for (i = 0; i < count; i++)
    {
        printf("\nProduct %d\n", i + 1);
        printf("ID       : %d\n", products[i].id);
        printf("Name     : %s\n", products[i].name);
        printf("Price    : %.2f\n", products[i].price);
        printf("Quantity : %d\n", products[i].quantity);
    }
}

// Search Product
void searchProduct(struct Product products[], int count)
{
    int id;
    int i;

    printf("\nEnter Product ID : ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (products[i].id == id)
        {
            printf("\nProduct Found\n");
            printf("ID       : %d\n", products[i].id);
            printf("Name     : %s\n", products[i].name);
            printf("Price    : %.2f\n", products[i].price);
            printf("Quantity : %d\n", products[i].quantity);
            return;
        }
    }

    printf("\nProduct Not Found.\n");
}

// Update Product
void updateProduct(struct Product products[], int count)
{
    int id;
    int i;

    printf("\nEnter Product ID : ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (products[i].id == id)
        {
            printf("\nEnter New Product Name : ");
            scanf(" %[^\n]", products[i].name);

            printf("Enter New Price : ");
            scanf("%f", &products[i].price);

            printf("Enter New Quantity : ");
            scanf("%d", &products[i].quantity);

            printf("\nProduct Updated Successfully.\n");
            return;
        }
    }

    printf("\nProduct Not Found.\n");
}

// Sort Products by Price
void sortByPrice(struct Product products[], int count)
{
    int i, j;
    struct Product temp;

    for (i = 0; i < count - 1; i++)
    {
        for (j = 0; j < count - i - 1; j++)
        {
            if (products[j].price > products[j + 1].price)
            {
                temp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = temp;
            }
        }
    }

    printf("\nProducts Sorted Successfully.\n");
}

// Calculate Total Inventory Value
void totalInventoryValue(struct Product products[], int count)
{
    int i;
    float total = 0;

    for (i = 0; i < count; i++)
    {
        total += (products[i].price * products[i].quantity);
    }

    printf("\nTotal Inventory Value = %.2f\n", total);
}

int main()
{
    struct Product products[MAX];

    int count = 0;
    int choice;

    do
    {
        printf("\n====== INVENTORY MANAGEMENT SYSTEM ======\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Search Product\n");
        printf("4. Update Product\n");
        printf("5. Sort Products by Price\n");
        printf("6. Total Inventory Value\n");
        printf("7. Exit\n");

        printf("\nEnter Your Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addProduct(products, &count);
            break;

        case 2:
            displayProducts(products, count);
            break;

        case 3:
            searchProduct(products, count);
            break;

        case 4:
            updateProduct(products, count);
            break;

        case 5:
            sortByPrice(products, count);
            displayProducts(products, count);
            break;

        case 6:
            totalInventoryValue(products, count);
            break;

        case 7:
            printf("\nProgram Terminated Successfully.\n");
            break;

        default:
            printf("\nInvalid Choice.\n");
        }

    } while (choice != 7);

    return 0;
}