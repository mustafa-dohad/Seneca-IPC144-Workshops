/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P1)
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

#define MAX_ITEMS 10

int main(void)
{
    const double min_income = 500.00, max_income = 400000.00, min_cost = 100.00;
    double cost[MAX_ITEMS] = {0}, income, total_cost = 0;
    int priority[MAX_ITEMS] = {0}, num_items;
    char finance_op[MAX_ITEMS];

    // Display program header.
    printf("+--------------------------+\n");
    printf("|   Wish List Forecaster   |\n");
    printf("+--------------------------+\n");

    int valid_income = 0, valid_wishlist = 0;

    // Validate and input monthly NET income.
    while (!valid_income)
    {
        printf("\nEnter your monthly NET income: $");
        scanf("%lf", &income);

        if (income >= min_income && income <= max_income)
        {
            valid_income = 1; // Income is valid, exit the loop.
        }
        else if (income < min_income)
        {
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
        }
        else if (income > max_income)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400,000.00\n");
        }
    }

    // Validate and input the number of wish list items.
    while (!valid_wishlist)
    {
        printf("\nHow many wish list items do you want to forecast?: ");
        scanf("%d", &num_items);

        if (num_items >= 1 && num_items <= MAX_ITEMS)
        {
            valid_wishlist = 1; // Number of items is valid, exit the loop.
        }
        else
        {
            printf("ERROR: List is restricted to between 1 and %d items\n", MAX_ITEMS);
        }
    }

    // Input details for each wish list item.
    for (int i = 0; i < num_items; i++)
    {
        int valid_cost = 0, valid_priority = 0, valid_finance = 0;
        printf("\nItem-%d Details:\n", i + 1);

        // Validate and input item cost.
        while (!valid_cost)
        {
            printf("   Item cost: $");
            scanf("%lf", &cost[i]);

            if (cost[i] >= min_cost)
            {
                total_cost += cost[i]; // Update the total cost.
                valid_cost = 1; // Cost is valid, exit the loop.
            }
            else
            {
                printf("      ERROR: Cost must be at least $100.00\n");
            }
        }

        // Validate and input item priority.
        while (!valid_priority)
        {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &priority[i]);

            if (priority[i] >= 1 && priority[i] <= 3)
            {
                valid_priority = 1; // Priority is valid, exit the loop.
            }
            else
            {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
        }

        // Validate and input financing options.
        while (!valid_finance)
        {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &finance_op[i]);

            if (finance_op[i] == 'y' || finance_op[i] == 'n')
            {
                valid_finance = 1; // Financing option is valid, exit the loop.
            }
            else
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }
        }
    }

    // Display a table of wish list items with priority, financing option, and cost.
    printf("\nItem Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");

    for (int i = 0; i < num_items; i++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", i + 1, priority[i], finance_op[i], cost[i]);
    }

    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", total_cost);
    printf("Best of luck in all your future endeavors!\n");

    return 0;
}
