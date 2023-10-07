//Full Name: Mustafa Dohad
//Student ID#: 123090235
//Email: mna26@myseneca.ca
//Section: ZGG

//Authenticity Declaration:
//I declare this submission is the result of my own work and has not been
//shared with any other student or 3rd party content provider. This submitted
//piece of work is entirely of my own creation

#include<stdio.h>
#include<math.h>
int main()
{
    int no_s;
    float small, medium, large, st, t, tax;
    printf("Set Shirt Prices");
    printf("\n================");
    printf("\nEnter the price for a SMALL shirt: $"); 
    scanf("%f", &small);
    printf("Enter the price for a MEDIUM shirt: $"); 
    scanf("%f", &medium);
    printf("Enter the price for a LARGE shirt: $"); 
    scanf("%f", &large);
    printf("\nShirt Store Price List");
    printf("\n======================");
    printf("\nSMALL  : $%.2f", small);
    printf("\nMEDIUM : $%.2f", medium);
    printf("\nLARGE  : $%.2f" , large);
    printf("\n\nPatty's shirt size is 'S'");
    printf("\nNumber of shirts Patty is buying: "); 
    scanf("%d", &no_s);
    printf("\nPatty's shopping cart...");
    printf("\nContains : %d shirts", no_s);
    st = small * no_s;
    tax = st * 0.13;
    t = st + tax;
    printf("\nSub-total: $%8.4f", st);
    printf("\nTaxes    : $ %.2f00", tax);
    printf("\nTotal    : $%.2f00\n", t);

    return 0;
}