/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 1
Full Name  : Mustafa Dohad
Student ID#: 123090235
Email      : mna26@myseneca.ca
Section    : ZGG

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
// System Libraries
#include <stdio.h>
// User Libraries
#include "core.h"
// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}
// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

// to get the integer followed by newline char
int inputInt(void)
{
    int value;
    char newline;
    do
    {
        scanf("%d%c", &value, &newline);

        if (newline != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }

    } while (newline != '\n');

    return value;
}
// to get the positive integer as a value
int inputIntPositive(void)
{
    int value;
    char newline;
    do
    {
        scanf("%d%c", &value, &newline);
        if (value < 1 || newline != '\n')
        {
            if (newline != '\n')
            {
                clearInputBuffer();
                printf("Error! Input a whole number: ");
            }

            else
                printf("ERROR! Value must be > 0: ");
        }

    } while (value < 1 || newline != '\n');
    return value;
}
// to get the positive integer as a value
int inputIntRange(int lowerBound, int upperBound)
{
    int value;
    char newline;
    do
    {
        scanf("%d%c", &value, &newline);
        if ((value > upperBound || value < lowerBound) || newline != '\n')
        {
            if (newline != '\n')
            {
                clearInputBuffer();
                printf("Error! Input a whole number: ");
            }
            else
                printf("ERROR! Value must be between %d and %d inclusive: ", lowerBound, upperBound);
        }
    } while ((value > upperBound || value < lowerBound) || newline != '\n');
    return value;
}
// to get the input of a character out of a specific range
char inputCharOption(char *charList)
{
    char enter;
    int i, flag = 0;
    do
    {
        i = 0;
        enter = getchar();
        do
        {
            if (enter == *(charList + i))
                flag = 1;
            i++;
        } while (flag != 1 && *(charList + i) != '\0');

        if (flag == 0)
        {
            clearInputBuffer();
            printf("ERROR: Character must be one of [qwErty]: ");
        }

    } while (flag == 0);
    return enter;
}

void inputCString(char cstring_value[], int minLength, int maxLength)
{
    int no;
    char example[100] = {'\0'};
    do
    {
        clearInputBuffer();
        no = 0;
        scanf("%[^\n]s", example);

        while (example[no] != '\0')
        {
            no++;
        }

        if (no < minLength || no > maxLength)
        {
            if (minLength == maxLength)
            {
                printf("ERROR: String length must be exactly %d chars: ", minLength);
            }
            else
            {
                if (no > maxLength)
                {
                    printf("ERROR: String length must be no more than %d chars: ", maxLength);
                }
                else if (no < minLength)
                {
                    printf("ERROR: String length must be between %d and %d chars: ", minLength, maxLength);
                }
            }
        }

    } while (no < minLength || no > maxLength);
    for (no = no - 1; no > -1; no--)
    {
        cstring_value[no] = example[no];
    }
}
void displayFormattedPhone(char *phoneNumber)
{
    int i = 0, no;
    char start = '(', end = ')', inbetween = '-';
    no = 0;
    if (phoneNumber != NULL)
    {
        while (*(phoneNumber + no) != '\0')
        {
            if ((int)*(phoneNumber + no) > 47 && (int)*(phoneNumber + no) < 58)
                i++;
            no++;
        }

        if (i == 10)
        {
            i = 0;
            while (*(phoneNumber + i) != '\0')
            {
                if (i == 0)
                {
                    printf("%c", start);
                }
                else if (i == 3)
                {
                    printf("%c", end);
                }
                else if (i == 6)
                {
                    printf("%c", inbetween);
                }
                printf("%c", *(phoneNumber + i));
                i++;
            }
        }
    }
    if (i != 10)
        printf("(___)___-____");
}
