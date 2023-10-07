/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P2)
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
#define LOG_DAYS 3

int main(void)
{
    const int JAN = 1, DEC = 12;
    int year, month;
    char *monthName;
    float m_rating, e_rating, total_m_rating = 0, total_e_rating = 0, overall_rating, avg_m_rating, avg_e_rating, total_avg_rating;
    
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
            if (month == 1)
            {
                monthName = "JAN";
            }
            else if (month == 2)
            {
                monthName = "FEB";
            }
            // ... (Repeat for the remaining months)
            else if (month == 12)
            {
                monthName = "DEC";
            }

            printf("\n");

            int i;
            for (i = 1; i <= LOG_DAYS; i++)
            {
                printf("\n%d-%s-0%d", year, monthName, i);

                // Input and validate morning rating.
                do
                {
                    printf("\n   Morning rating (0.0-5.0): ");
                    scanf("%f", &m_rating);

                    if (m_rating < 0.0 || m_rating > 5.0)
                    {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!");
                    }
                    else
                    {
                        break;
                    }
                } while (1);

                total_m_rating += m_rating;

                // Input and validate evening rating.
                do
                {
                    printf("   Evening rating (0.0-5.0): ");
                    scanf("%f", &e_rating);

                    if (e_rating < 0.0 || e_rating > 5.0)
                    {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                    }
                    else
                    {
                        break;
                    }
                } while (1);

                total_e_rating += e_rating;
            }

            // Calculate overall and average ratings.
            overall_rating = total_e_rating + total_m_rating;
            avg_m_rating = total_m_rating / LOG_DAYS;
            avg_e_rating = total_e_rating / LOG_DAYS;
            total_avg_rating = (avg_e_rating + avg_m_rating) / 2.0;

            // Display summary.
            printf("\nSummary");
            printf("\n=======");
            printf("\nMorning total rating: %.3f", total_m_rating);
            printf("\nEvening total rating:  %.3f", total_e_rating);
            printf("\n----------------------------");
            printf("\nOverall total rating: %.3f", overall_rating);
            printf("\n\nAverage morning rating:  %.1f", avg_m_rating);
            printf("\nAverage evening rating:  %.1f", avg_e_rating);
            printf("\n----------------------------");
            printf("\nAverage overall rating:  %.1f\n", total_avg_rating);

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
