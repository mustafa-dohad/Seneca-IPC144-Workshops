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
        if (ch == 'Q' && num == 0) //if the user enter Q0 then the loop breaks and enter the main function
        {
            break; // therefore the break syntax
        }
        else if (ch != 'D' && ch != 'W' && ch != 'F' && ch != 'Q') //if any other character except the one mentioned is entered
        {
            printf("ERROR: Invalid entered value(s)!");
        }
        
        else if (ch == 'Q' && !(num == 0)) //if the char is correct that is : Q but the num is incorrect 
        {
            printf("ERROR: To quit, the number of iterations should be 0!");
        }
        else if (num <= 0) // if the value of num is less than zero
        {
            printf("ERROR: Invalid entered value(s)!");
        }
        else if (num < 3 || num > 20) // if the num is not in the range of 3 or 20 
        {
            printf("ERROR: The number of iterations must be between 3-20 inclusive!");
        } //putting all the necessary if conditions before so that i receive the desired output and theres no room for error
        else if (ch == 'D' && num >= 3)
        {
            printf("DO-WHILE: ");
            int i;
            for ( i=0 ; i < num; i++) //this will print the character on the same line as DO-WHILE
            {
                printf("%c", ch); //where the character is looping and iterating according to the num value 
            }
        }
        else if (ch == 'W' && num >= 3)
        {
            printf("WHILE   : ");
            int i;
            for ( i=0 ; i < num; i++)
            {
                printf("%c", ch);
            }
        }
        else if (ch == 'F' && num >= 3)
        {
            printf("FOR     : ");
            int i;
            for ( i=0 ; i < num; i++)
            {
                printf("%c", ch);
            }
        }


        printf("\n\n");
    } while (1);
    printf("\n+--------------------+\n");
    printf("Loop application ENDED\n");
    printf("+--------------------+\n");
    return 0;
}
