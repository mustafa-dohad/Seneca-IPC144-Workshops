/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
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
#include <stdio.h>
int main() 
{
    char type1, type2, type3,cream1,cream2,cream3,user_s,usercream;
    int weight1, weight2, weight3,servings;
    const double GRAMS_IN_LBS = 453.5924;
    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n\n");
    printf("Enter the coffee product information being sold today...\n\n");
    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &type1);
    printf("Bag weight (g): ");
    scanf("%d", &weight1);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream1);
    printf("\nCOFFEE-2...");
    printf("\nType ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &type2);
    printf("Bag weight (g): ");
    scanf("%d", &weight2);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream2);
    printf("\nCOFFEE-3...");
    printf("\nType ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &type3);
    printf("Bag weight (g): ");
    scanf("%d", &weight3);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream3);
    printf("\n---+------------------------+---------------+-------+\n");
    printf("   |    Coffee              |   Packaged    | Best  |\n");
    printf("   |     Type               |  Bag Weight   | Served|\n");
    printf("   +------------------------+---------------+ With  |\n");
    printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
    printf("---+------------------------+---------------+-------|\n");
    printf(" 1 |   %d   |   %d    |   %d   |  %d |  %.3lf |   %d   |\n", ((type1=='l')||(type1=='L')),((type1=='m')||(type1=='M')), ((type1=='r')||(type1=='R')),weight1,(weight1/GRAMS_IN_LBS),((cream1=='y')||(cream1 == 'Y') ));
    printf(" 2 |   %d   |   %d    |   %d   |  %d |  %.3lf |   %d   |\n", ((type2=='l')||(type2=='L')),((type2=='m')||(type2=='M')), ((type2=='r')||(type2=='R')),weight2,(weight2/GRAMS_IN_LBS),((cream2=='y')||(cream2 == 'Y') ));
    printf(" 3 |   %d   |   %d    |   %d   | %d |  %.3lf |   %d   |\n\n", ((type3=='l')||(type3=='L')),((type3=='m')||(type3=='M')), ((type3=='r')||(type3=='R')),weight3,(weight3/GRAMS_IN_LBS),((cream3=='y')||(cream3 == 'Y') ));
    printf("Enter how you like your coffee...\n\n");
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf (" %c",&user_s );
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf( " %c" ,& usercream ) ;
    printf("Typical number of daily servings: ");
    scanf("%d", &servings);
    printf("\nThe below table shows how your preferences align to the available products:");
    printf("\n\n--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", (user_s == 'L' || user_s == 'l'), (1 <= servings && servings <= 4), ((user_s== 'l' || user_s=='L') && (usercream=='y' || usercream == 'Y')));
    printf(" 2|       %d         |      %d      |   %d   |\n",(user_s == 'M' || user_s == 'm'), (5 <= servings && servings <= 9), ((user_s== 'M' || user_s=='m') && (usercream=='y' || usercream == 'Y')));
    printf(" 3|       %d         |      %d      |   %d   |\n\n",(user_s == 'R' || user_s == 'r'), ( servings >= 10), ((user_s== 'r' || user_s=='R') && (usercream=='y' || usercream == 'Y')));
    printf("Enter how you like your coffee...\n\n");
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf (" %c",&user_s );
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf( " %c" ,& usercream ) ;
    printf("Typical number of daily servings: ");
    scanf("%d", &servings);
    printf("\nThe below table shows how your preferences align to the available products:\n\n");
    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       0         |      0      |   0   |\n" );
    printf(" 2|       0         |      0      |   1   |\n");
    printf(" 3|       1         |      1      |   1   |\n\n");
    printf("Hope you found a product that suits your likes!\n");

 
 
 
 
    return 0;
}