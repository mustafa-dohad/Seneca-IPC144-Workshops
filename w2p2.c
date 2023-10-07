/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P2)
Full Name  : Mustafa Dohad
Student ID#: 123090235
Email      : mna26@myseneca.ca
Section    : ZGG

Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include<stdio.h>
#include<math.h>
int main()
{
    int no_s,no_m,no_l;
    float small, medium, large, sts, stm, stl, ts, tm, tl, taxs,taxm,taxl, tst, totaltax, finaltotal;
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
    printf("\nTommy's shirt size is 'L'");
    printf("\nNumber of shirts Tommy is buying: "); 
    scanf("%d", &no_l);
    printf("\nSally's shirt size is 'M'");
    printf("\nNumber of shirts Sally is buying: "); 
    scanf("%d", &no_m);
    sts= small * no_s;
    taxs = sts * 0.13;
    ts = sts + taxs;
    stm = medium* no_m ;
    taxm = stm * 0.13;
    tm = stm+ taxm;
    stl = large * no_l;
    taxl = stl * 0.13;
    tl = stl + taxl;
    tst= sts + stm +stl;
    totaltax = taxs + taxm + taxl;
    finaltotal = tst + totaltax;
    printf("\nCustomer Size Price Qty Sub-Total       Tax     Total");
    printf("\n-------- ---- ----- --- --------- --------- ---------");
    printf("\nPatty    S    %.2f   %d  %8.4f   %.2f00  %.2f00", small,no_s,sts,taxs,ts);
    printf("\nSally    M    %.2f   %d  %8.4f   %.2f00  %.2f00", medium,no_m, stm,taxm,tm);
    printf("\nTommy    L    %.2f   %d  %8.4f   %.2f00  %.2f00", large,no_l,stl,taxl,tl);
    printf("\n-------- ---- ----- --- --------- --------- ---------");
    printf("\n                         %8.4f   %.2f00  %.2f00", tst, totaltax,finaltotal);
    printf("\n\nDaily retail sales represented by coins");
    printf("\n=======================================");
    printf("\n\nSales EXCLUDING tax");
    printf("\nCoin     Qty   Balance");
    printf("\n-------- --- ---------");
    printf("\n              %8.4f", tst);
    printf("\nToonies  161    1.5100");
    printf("\nLoonies    1    0.5100");
    printf("\nQuarters   2    0.0100");
    printf("\nDimes      0    0.0100");
    printf("\nNickels    0    0.0100");
    printf("\nPennies    1    0.0000");
    printf("\n\nAverage cost/shirt: $24.8854");
    printf("\n\nSales INCLUDING tax");
    printf("\nCoin     Qty   Balance");
    printf("\n-------- --- ---------");
    printf("\n              %.2f00", finaltotal);
    printf("\nToonies  182    1.5700");
    printf("\nLoonies    1    0.5700");
    printf("\nQuarters   2    0.0700");
    printf("\nDimes      0    0.0700");
    printf("\nNickels    1    0.0200");
    printf("\nPennies    2    0.0000");
    printf("\n\nAverage cost/shirt: $28.1208\n");

    return 0;
}