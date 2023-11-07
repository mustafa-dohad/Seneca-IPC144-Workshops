/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P1)
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
#include "w8p1.h"

int getIntPositive(int* value) {
    int input;
    while (1) {
        scanf("%d", &input);
        if (input > 0) {
            if (value != NULL) {
                *value = input;
            }
            return input;
        } else {
            printf("ERROR: Enter a positive value: ");
        }
    }
}

double getDoublePositive(double* value) {
    double input;
    while (1) {
        scanf("%lf", &input);
        if (input > 0) {
            if (value != NULL) {
                *value = input;
            }
            return input;
        } else {
            printf("ERROR: Enter a positive value: ");
        }
    }
}

void openingMessage(int numProducts) {
    printf("Cat Food Cost Analysis\n");
    printf("======================\n\n");
    printf("Enter the details for %d dry food bags of product data for analysis.\n", numProducts);
    printf("NOTE: A 'serving' is %dg\n", SERVING_GRAMS);
}

CatFoodInfo getCatFoodInfo(int productNumber) {
    CatFoodInfo info;
    printf("\nCat Food Product #%d\n", productNumber);
    printf("--------------------\n");
    printf("SKU           : ");
    getIntPositive(&info.sku);
    printf("PRICE         : $");
    getDoublePositive(&info.price);
    printf("WEIGHT (LBS)  : ");
    getDoublePositive(&info.weight);
    printf("CALORIES/SERV.: ");
    getIntPositive(&info.calories);
    return info;
}

void displayCatFoodHeader() {
    printf("\nSKU         $Price    Bag-lbs Cal/Serv\n");
    printf("------- ---------- ---------- --------\n");
}

void displayCatFoodData(int sku, double price, double weight, int calories) {
    printf("%07d %10.2lf %10.1lf %8d\n", sku, price, weight, calories);
}

void start() {
    int i;
    CatFoodInfo products[MAX_PRODUCTS];
    openingMessage(MAX_PRODUCTS);

    for (i = 0; i < MAX_PRODUCTS; i++) {
        products[i] = getCatFoodInfo(i + 1);
    }

    displayCatFoodHeader();

    for ( i = 0; i < MAX_PRODUCTS; i++) {
        displayCatFoodData(products[i].sku, products[i].price, products[i].weight, products[i].calories);
    }
}