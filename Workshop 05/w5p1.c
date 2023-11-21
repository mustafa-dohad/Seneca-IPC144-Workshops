/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P1)
Full Name  : Mustafa Dohad
Student ID#: 123090235
Email      : mna26@myseneca.ca
Section    : ZGG

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS // This directive suppresses warnings for certain functions in some environments.

#include <stdio.h>

#define MIN_YEAR 2012
#define MAX_YEAR 2022

int main(void)
{
    const int JAN = 1, DEC = 12;
    int year, month;

    // Display program header.
    printf("General Well-being Log\n");
    printf("======================\n");

    do
    {
        // Input year and month for the well-being log.
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &year, &month);

        if ((year >= MIN_YEAR && year <= MAX_YEAR) && (month >= JAN && month <= DEC))
        {
            printf("\n*** Log date set! ***");

            // Convert numeric month to its corresponding three-letter abbreviation.
            switch (month)
            {
            case 1:
                printf("\n\nLog starting date: %d-JAN-01\n", year);
                break;
            case 2:
                printf("\n\nLog starting date: %d-FEB-01\n", year);
                break;
            case 3:
                printf("\n\nLog starting date: %d-MAR-01\n", year);
                break;
            case 4:
                printf("\n\nLog starting date: %d-APR-01\n", year);
                break;
            case 5:
                printf("\n\nLog starting date: %d-MAY-01\n", year);
                break;
            case 6:
                printf("\n\nLog starting date: %d-JUN-01\n", year);
                break;
            case 7:
                printf("\n\nLog starting date: %d-JUL-01\n", year);
                break;
            case 8:
                printf("\n\nLog starting date: %d-AUG-01\n", year);
                break;
            case 9:
                printf("\n\nLog starting date: %d-SEP-01\n", year);
                break;
            case 10:
                printf("\n\nLog starting date: %d-OCT-01\n", year);
                break;
            case 11:
                printf("\n\nLog starting date: %d-NOV-01\n", year);
                break;
            case 12:
                printf("\n\nLog starting date: %d-DEC-01\n", year);
                break;
            default:
                break;
            }
            break;
        }
        else if ((year < MIN_YEAR || year > MAX_YEAR) && (month < JAN || month > DEC))
        {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }
        else if (year < MIN_YEAR || year > MAX_YEAR)
        {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
        }
        else if (month < JAN || month > DEC)
        {
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }
    } while (1);

    return 0;
}
