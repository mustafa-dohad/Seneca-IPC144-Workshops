/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P2)
Full Name  :
Student ID#:
Email      :
Section    :

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MAX_ITEMS 10
int main(void)
{
    const double min_income = 500.00, max_income = 400000.00, min_cost = 100.00;
    double cost[MAX_ITEMS] = {0}, income, total_cost = 0;
    int priority[MAX_ITEMS] = {0}, num_items, i, note = 0;
    char finance_op[MAX_ITEMS];

    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n");
    int valid_income = 0, valid_wishlist = 0;

    while (!valid_income)
    {
        printf("\nEnter your monthly NET income: $");
        scanf("%lf", &income);

        if (income >= min_income && income <= max_income)
        {
            valid_income = 1;
        }
        else if (income < min_income)
        {
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
        }
        else if (income > max_income)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
        }
    }

    while (!valid_wishlist)
    {
        printf("\nHow many wish list items do you want to forecast?: ");
        scanf("%d", &num_items);

        if (num_items >= 1 && num_items <= MAX_ITEMS)
        {
            valid_wishlist = 1;
        }
        else
        {
            printf("ERROR: List is restricted to between 1 and %d items.\n", MAX_ITEMS);
        }
    }

    for (i = 0; i < num_items; i++)
    {
        int valid_cost = 0, valid_priority = 0, valid_finance = 0;
        printf("\nItem-%d Details:\n", i + 1);

        while (!valid_cost)
        {
            printf("   Item cost: $");
            scanf("%lf", &cost[i]);

            if (cost[i] >= min_cost)
            {
                total_cost += cost[i];
                valid_cost = 1;
            }
            else
            {
                printf("      ERROR: Cost must be at least $100.00\n");
            }
        }

        while (!valid_priority)
        {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &priority[i]);

            if (priority[i] >= 1 && priority[i] <= 3)
            {
                valid_priority = 1;
            }
            else
            {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
        }

        while (!valid_finance)
        {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &finance_op[i]);

            if (finance_op[i] == 'y' || finance_op[i] == 'n')
            {
                valid_finance = 1;
            }
            else
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }
        }
    }

    printf("\nItem Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");

    for (i = 0; i < num_items; i++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", i + 1, priority[i], finance_op[i], cost[i]);
    }

    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n", total_cost);
    int valid_forecast = 0, fore_wish, years, months;
    double totalmonths;

    while (!valid_forecast)
    {
        printf("\nHow do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n");
        printf(" 2. By priority\n");
        printf(" 0. Quit/Exit\n");
        printf("Selection: ");
        scanf("%d", &fore_wish);

        if (fore_wish == 0)
        {
            valid_forecast = 1;
        }
        else if (fore_wish == 1)
        {
            totalmonths = total_cost / income;
            years = (int)(totalmonths / 12);
            months = (int)(totalmonths - (years * 12) + 1);

            printf("\n====================================================\n");
            printf("Filter:   All items\n");
            printf("Amount:   $%.2lf\n", total_cost);
            printf("Forecast: %d years, %d months\n", years, months);

            for (i = 0; i < num_items; i++)
            {
                if (finance_op[i] == 'y')
                {
                    note = 1;
                }
            }
            if (note)
            {
                printf("NOTE: Financing options are available on some items.\n");
                printf("      You can likely reduce the estimated months.\n");
            }

            printf("====================================================\n");
        }
        else if (fore_wish == 2)
        {
            int filter, i;
            double totalcost_priority = 0.0;
            totalmonths = 0; // Reset totalmonths

            printf("\nWhat priority do you want to filter by? [1-3]: ");
            scanf("%d", &filter);
            
            if (filter >= 1 && filter <= 3)
            {
                for (i = 0; i < num_items; i++)
                {
                    if (priority[i] == filter)
                    {
                        totalcost_priority += cost[i];
                    }
                }

                totalmonths = totalcost_priority / income;
                years = (int)(totalmonths / 12);
                months = (int)(totalmonths - (years * 12));
                printf("\n====================================================\n");
                printf("Filter:   by priority (%d)\n", filter);
                printf("Amount:   $%.2lf\n", totalcost_priority);
                printf("Forecast: %d years, %d months\n", years, (months + 1));
                if (filter == 2)
                {
                   printf("====================================================\n");
                }
                else
                {
                for (i = 0; i < num_items; i++)
                {
                    if (finance_op[i] == 'y')
                    {
                        note = 1;
                    }
                }
                if (note)
                {
                    printf("NOTE: Financing options are available on some items.\n");
                    printf("      You can likely reduce the estimated months.\n");
                }
                printf("====================================================\n");}
            }
            else
            {
                printf("\nERROR: Invalid priority selection.\n");
            }
        }
        else
        {
            printf("\nERROR: Invalid menu selection.\n");
        }
    }
    printf("\nBest of luck in all your future endeavours!\n\n");
    return 0;
}
