/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
Full Name  : Mustafa Dohad
Student ID#: 123090235
Email      : mna26@myseneca.ca
Section    : ZGG

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>

int main(void)
{
    char ch;
    int num;
    
    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n\n");
    
    do
    {
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &ch, &num);
        
        if (ch == 'Q' && num == 0)
        {
            break; // Exit the loop and quit the program if Q0 is entered.
        }
        else if (ch != 'D' && ch != 'W' && ch != 'F' && ch != 'Q')
        {
            printf("ERROR: Invalid entered value(s)!"); // Handle invalid characters.
        }
        else if (ch == 'Q' && !(num == 0))
        {
            printf("ERROR: To quit, the number of iterations should be 0!"); // Handle incorrect Q usage.
        }
        else if (num <= 0)
        {
            printf("ERROR: Invalid entered value(s)!"); // Handle non-positive numbers.
        }
        else if (num < 3 || num > 20)
        {
            printf("ERROR: The number of iterations must be between 3-20 inclusive!"); // Handle out-of-range numbers.
        }
        else if (ch == 'D' && num >= 3)
        {
            printf("DO-WHILE: ");
            int i;
            for (i = 0; i < num; i++)
            {
                printf("%c", ch); // Print characters for do-while loop.
            }
        }
        else if (ch == 'W' && num >= 3)
        {
            printf("WHILE   : ");
            int i;
            for (i = 0; i < num; i++)
            {
                printf("%c", ch); // Print characters for while loop.
            }
        }
        else if (ch == 'F' && num >= 3)
        {
            printf("FOR     : ");
            int i;
            for (i = 0; i < num; i++)
            {
                printf("%c", ch); // Print characters for for loop.
            }
        }

        printf("\n\n");
    } while (1); // Infinite loop until explicitly quit.

    printf("\n+--------------------+\n");
    printf("Loop application ENDED\n");
    printf("+--------------------+\n");
    
    return 0;
}

