/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  : Mustafa Dohad
Student ID#: 123090235
Email      : mna26@myseneca.ca
Section    : ZGG

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS // This directive suppresses warnings for certain functions in some environments.

#include <stdio.h>

int main(void)
{
    int i = 0, app_n, or_n, pears_n, tom_n, cab_n, app_p, or_p, pears_p, tom_p, cab_p;
    int appcount = 0, orcount = 0, pearscount = 0, tomcount = 0, cabcount = 0, remaining;

    do
    {
        printf("Grocery Shopping\n");
        printf("================");

        // Input the quantity of each fruit, making sure it's non-negative.
        do
        {
            printf("\nHow many APPLES do you need? : ");
            scanf("%d", &app_n);
            if (app_n < 0)
            {
                printf("ERROR: Value must be 0 or more.");
            }
        } while (app_n < 0);

        do
        {
            printf("\nHow many ORANGES do you need? : ");
            scanf("%d", &or_n);
            if (or_n < 0)
            {
                printf("ERROR: Value must be 0 or more.");
            }
        } while (or_n < 0);

        do
        {
            printf("\nHow many PEARS do you need? : ");
            scanf("%d", &pears_n);
            if (pears_n < 0)
            {
                printf("ERROR: Value must be 0 or more.");
            }
        } while (pears_n < 0);

        do
        {
            printf("\nHow many TOMATOES do you need? : ");
            scanf("%d", &tom_n);
            if (tom_n < 0)
            {
                printf("ERROR: Value must be 0 or more.");
            }
        } while (tom_n < 0);

        do
        {
            printf("\nHow many CABBAGES do you need? : ");
            scanf("%d", &cab_n);
            if (cab_n < 0)
            {
                printf("ERROR: Value must be 0 or more.");
            }
        } while (cab_n < 0);

        printf("\n--------------------------\n");
        printf("Time to pick the products!");
        printf("\n--------------------------\n");

        // For each fruit type, pick the quantity and check if it's within bounds.
        if (app_n > 0)
        {
            remaining = app_n;
            printf("\n");
            while (app_p != app_n)
            {
                printf("Pick some APPLES... how many did you pick? : ");
                scanf("%d", &app_p);

                if (app_p > app_n)
                {
                    printf("You picked too many... only %d more APPLE(S) are needed.\n", remaining);
                }
                else if (app_p <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (app_p < app_n)
                {
                    remaining -= app_p;
                    appcount += app_p;
                    if (appcount == app_n)
                    {
                        printf("Great, that's the apples done!\n");
                        app_p = app_n;
                    }
                    else
                        printf("Looks like we still need some APPLES...\n");
                }
                else if (app_p == app_n)
                {
                    printf("Great, that's the apples done!\n");
                }
            }
        }

        // Similar code for ORANGES, PEARS, TOMATOES, and CABBAGES follows...

        printf("\nAll the items are picked!");
        printf("\n\nDo another shopping? (0=NO): ");
        scanf("%d", &i);
        appcount = 0; /* Resetting all the sums so that if the user needs to pick fruits again, all the values are reset, and new values would be initiated */
        orcount = 0;
        pearscount = 0;
        tomcount = 0;
        cabcount = 0;
        printf("\n");
    } while (i == 1);
    printf("Your tasks are done for today - enjoy your free time!\n");

    return 0;
}
