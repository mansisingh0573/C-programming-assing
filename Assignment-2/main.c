#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Function Prototypes
void findLength(char str[]);
void reverseString(char str[]);
void checkPalindrome(char str[]);
void countCharacters(char str[]);
void characterFrequency(char str[]);

// Length of String
void findLength(char str[])
{
    printf("\nLength of String = %d\n", (int)strlen(str));
}

// Reverse String
void reverseString(char str[])
{
    int i;
    int length = strlen(str);

    printf("\nReversed String = ");

    for (i = length - 1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }

    printf("\n");
}

// Palindrome Check
void checkPalindrome(char str[])
{
    int start = 0;
    int end = strlen(str) - 1;
    int flag = 1;

    while (start < end)
    {
        if (str[start] != str[end])
        {
            flag = 0;
            break;
        }

        start++;
        end--;
    }

    if (flag)
        printf("\nString is Palindrome.\n");
    else
        printf("\nString is NOT Palindrome.\n");
}

// Count Vowels, Digits and Spaces
void countCharacters(char str[])
{
    int vowels = 0;
    int digits = 0;
    int spaces = 0;
    int i;

    for (i = 0; str[i] != '\0'; i++)
    {
        char ch = tolower(str[i]);

        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            vowels++;
        }

        else if (isdigit(str[i]))
        {
            digits++;
        }

        else if (str[i] == ' ')
        {
            spaces++;
        }
    }

    printf("\nTotal Vowels = %d", vowels);
    printf("\nTotal Digits = %d", digits);
    printf("\nTotal Spaces = %d\n", spaces);
}

// Character Frequency
void characterFrequency(char str[])
{
    int frequency[256] = {0};
    int i;

    for (i = 0; str[i] != '\0'; i++)
    {
        frequency[(unsigned char)str[i]]++;
    }

    printf("\nCharacter Frequency:\n");

    for (i = 0; i < 256; i++)
    {
        if (frequency[i] != 0)
        {
            printf("%c = %d\n", i, frequency[i]);
        }
    }
}

int main()
{
    char str[MAX];

    int choice;

    printf("Enter a String : ");
    fgets(str, sizeof(str), stdin);

    // remove newline character
    str[strcspn(str, "\n")] = '\0';

    do
    {
        printf("\n====== STRING UTILITY TOOLKIT ======\n");
        printf("1. Find Length\n");
        printf("2. Reverse String\n");
        printf("3. Check Palindrome\n");
        printf("4. Count Vowels, Digits and Spaces\n");
        printf("5. Character Frequency\n");
        printf("6. Exit\n");

        printf("\nEnter Your Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            findLength(str);
            break;

        case 2:
            reverseString(str);
            break;

        case 3:
            checkPalindrome(str);
            break;

        case 4:
            countCharacters(str);
            break;

        case 5:
            characterFrequency(str);
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