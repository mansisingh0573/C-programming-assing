#include <stdio.h>
#include <string.h>

#define MAX 100

// Structure Definition
struct Patient
{
    int id;
    char name[50];
    int age;
    char disease[50];
};

// Add Patient
void addPatient(struct Patient patients[], int *count)
{
    if (*count >= MAX)
    {
        printf("\nHospital Records are Full.\n");
        return;
    }

    printf("\nEnter Patient ID : ");
    scanf("%d", &patients[*count].id);

    printf("Enter Patient Name : ");
    scanf(" %[^\n]", patients[*count].name);

    printf("Enter Patient Age : ");
    scanf("%d", &patients[*count].age);

    printf("Enter Disease Name : ");
    scanf(" %[^\n]", patients[*count].disease);

    (*count)++;

    printf("\nPatient Registered Successfully.\n");
}

// Display Patients
void displayPatients(struct Patient patients[], int count)
{
    int i;

    if (count == 0)
    {
        printf("\nNo Patient Records Found.\n");
        return;
    }

    printf("\n------ PATIENT RECORDS ------\n");

    for (i = 0; i < count; i++)
    {
        printf("\nPatient %d\n", i + 1);
        printf("ID      : %d\n", patients[i].id);
        printf("Name    : %s\n", patients[i].name);
        printf("Age     : %d\n", patients[i].age);
        printf("Disease : %s\n", patients[i].disease);
    }
}

// Search Patient
void searchPatient(struct Patient patients[], int count)
{
    int id;
    int i;

    printf("\nEnter Patient ID : ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (patients[i].id == id)
        {
            printf("\nPatient Found\n");
            printf("ID      : %d\n", patients[i].id);
            printf("Name    : %s\n", patients[i].name);
            printf("Age     : %d\n", patients[i].age);
            printf("Disease : %s\n", patients[i].disease);

            return;
        }
    }

    printf("\nPatient Not Found.\n");
}

// Update Patient Details
void updatePatient(struct Patient patients[], int count)
{
    int id;
    int i;

    printf("\nEnter Patient ID : ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (patients[i].id == id)
        {
            printf("\nEnter New Patient Name : ");
            scanf(" %[^\n]", patients[i].name);

            printf("Enter New Age : ");
            scanf("%d", &patients[i].age);

            printf("Enter New Disease : ");
            scanf(" %[^\n]", patients[i].disease);

            printf("\nPatient Record Updated Successfully.\n");
            return;
        }
    }

    printf("\nPatient Not Found.\n");
}

// Delete Patient Record
void deletePatient(struct Patient patients[], int *count)
{
    int id;
    int i, j;

    printf("\nEnter Patient ID : ");
    scanf("%d", &id);

    for (i = 0; i < *count; i++)
    {
        if (patients[i].id == id)
        {
            for (j = i; j < *count - 1; j++)
            {
                patients[j] = patients[j + 1];
            }

            (*count)--;

            printf("\nPatient Record Deleted Successfully.\n");
            return;
        }
    }

    printf("\nPatient Not Found.\n");
}

int main()
{
    struct Patient patients[MAX];

    int count = 0;
    int choice;

    do
    {
        printf("\n====== HOSPITAL PATIENT MANAGEMENT ======\n");
        printf("1. Register Patient\n");
        printf("2. Display Patients\n");
        printf("3. Search Patient\n");
        printf("4. Update Patient\n");
        printf("5. Delete Patient\n");
        printf("6. Exit\n");

        printf("\nEnter Your Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addPatient(patients, &count);
            break;

        case 2:
            displayPatients(patients, count);
            break;

        case 3:
            searchPatient(patients, count);
            break;

        case 4:
            updatePatient(patients, count);
            break;

        case 5:
            deletePatient(patients, &count);
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