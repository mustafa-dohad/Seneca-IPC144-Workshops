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

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    int i=0, app_n,or_n,pears_n,tom_n, cab_n,app_p,or_p,pears_p,tom_p,cab_p,appcount=0,orcount=0,pearscount=0,tomcount=0,cabcount=0,remaining;
 do{
        printf("Grocery Shopping\n");
        printf("================");
        do{ printf("\nHow many APPLES do you need? : ");
        scanf("%d", &app_n);
        if (app_n < 0) // checks if the value is zero or more
        {
            printf("ERROR: Value must be 0 or more.");
        }
        } while ((app_n<0)); // this loops until the value is negative
        do{ printf("\nHow many ORANGES do you need? : "); 
        scanf("%d", &or_n);
        if (or_n < 0)
        {
            printf("ERROR: Value must be 0 or more.");
        }
        } while ((or_n<0));
        do{ printf("\nHow many PEARS do you need? : ");
        scanf("%d", &pears_n);
        if (pears_n < 0)
        {
            printf("ERROR: Value must be 0 or more.");
        }
        } while ((pears_n<0));
        do{ printf("\nHow many TOMATOES do you need? : ");
        scanf("%d", &tom_n);
        if (tom_n < 0)
        {
            printf("ERROR: Value must be 0 or more.");
        }
        } while ((tom_n<0));
        do{ printf("\nHow many CABBAGES do you need? : ");
        scanf("%d", &cab_n);
        if (cab_n < 0)
        {
            printf("ERROR: Value must be 0 or more.");
        }
        } while ((cab_n<0));
        printf("\n--------------------------\n");
        printf("Time to pick the products!");
        printf("\n--------------------------\n");
        if (app_n > 0) // this will check if there are apples to be picked
        {
            remaining = app_n;//saving the apples needed value in another variable so that we could get how mane remaining fruits left to pe picked
            printf("\n");
            while (app_p != app_n) //loops until the apple picked is not equal to apple needed
            {
            printf("Pick some APPLES... how many did you pick? : ");
            scanf ("%d",&app_p);
            
            if (app_p > app_n)
            {
                printf("You picked too many... only %d more APPLE(S) are needed.\n", remaining);//this shows how much more fruits are left to be picked
            }
            else if (app_p <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if (app_p < app_n) //if the apples picked are less than apples needed
            {
                remaining -= app_p; //overwriting remaining value as soon as some apples are picked so in the next error output it shows how much more fruit is needed
                appcount += app_p; //we'll just insert the ones picked into another variable which sums up the total until the apples picked are equal to apples needed
                if (appcount == app_n) // if both are equal then the loop ends and the user is done with the apple picking
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
        if (or_n > 0)
        {
            remaining = or_n;
            printf("\n");
            while (or_p != or_n)
            {
            printf("Pick some ORANGES... how many did you pick? : ");
            scanf ("%d",&or_p);
            if (or_p > or_n)
            {
                printf("You picked too many... only %d more ORANGE(S) are needed.\n", remaining);
            }
            else if (or_p <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if (or_p < or_n)
            {
                remaining -= or_p;
                orcount += or_p;
                if (orcount == or_n)
                {
                    printf("Great, that's the oranges done!\n");
                    or_p = or_n;
                }
                else
                printf("Looks like we still need some ORANGES...\n");
                
            }
            else if (or_p == or_n)
            {
                printf("Great, that's the oranges done!\n");
            }
            
            }
        }
        if (pears_n > 0)
        {
            remaining = pears_n;
            printf("\n");
            while (pears_p != pears_n)
            {
            printf("Pick some PEARS... how many did you pick? : ");
            scanf ("%d",&pears_p);
            
            if (pears_p > pears_n)
            {
                 printf("You picked too many... only %d more PEAR(S) are needed.\n", remaining);
            }
            else if (pears_p <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
                
            }
            else if (pears_p < pears_n)
            {
                remaining -= pears_p;
                pearscount += pears_p;
                if (pearscount == pears_n)
                {
                    printf("Great, that's the pears done!\n");
                    pears_p = pears_n;
                }
                else
                printf("Looks like we still need some PEARS...\n");

            }
            else if (pears_p == pears_n)
            {
                printf("Great, that's the pears done!\n");
               
            }
            
            }
        }
        if (tom_n > 0)
        {
            remaining = tom_n;
            printf("\n");
            while (tom_p != tom_n)
            {
            printf("Pick some TOMATOES... how many did you pick? : ");
            scanf ("%d",&tom_p);
            
            if (tom_p > tom_n)
            {
                printf("You picked too many... only %d more TOMATO(ES) are needed.\n", remaining);
            }
             else if (tom_p <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if (tom_p < tom_n)
            {
                remaining -= tom_p;
                tomcount += tom_p;
                if (tomcount == tom_n)
                {
                    printf("Great, that's the tomatoes done!\n");
                    tom_p = tom_n;
                }
                else
                printf("Looks like we still need some TOMATOES...\n");

            }
            else if (tom_p == tom_n)
            {
                printf("Great, that's the tomatoes done!\n");
                
            }
           
            } 
        }
        if (cab_n > 0)
        {
            remaining = cab_n;
            printf("\n");
            while (cab_p != cab_n)
            {
            printf("Pick some CABBAGES... how many did you pick? : ");
            scanf ("%d",&cab_p);
            
            if (cab_p > cab_n)
            {
                printf("You picked too many... only %d more CABBAGE(S) are needed.\n", remaining);
            }
            else if (cab_p <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if (cab_p < cab_n)
            {
                remaining-=cab_p;
                 cabcount += cab_p;
                if (cabcount == cab_n)
                {
                    printf("Great, that's the cabbages done!\n");
                    cab_p = cab_n;
                }
                else
                printf("Looks like we still need some CABBAGES...\n");

                
            }
            else if (cab_p == cab_n)
            {
                printf("Great, that's the cabbages done!\n");
            }
               
            } 
        }
        printf("\nAll the items are picked!");
        printf("\n\nDo another shopping? (0=NO): ");
        scanf("%d", &i); 
        appcount =0; /* resetting all the sums so that if user needs to pick fruits again so all the values are reset and the new values would be initiated*/
        orcount = 0; 
        pearscount = 0;
        tomcount = 0;
        cabcount = 0;
        printf("\n");
    } while (i == 1);
    printf("Your tasks are done for today - enjoy your free time!\n");
     
    //did'nt comment out everything because its just the same process for every fruit 
    
    
    return 0;
}