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

#ifndef W8P1_H
#define W8P1_H

#define MAX_PRODUCTS 3
#define SERVING_GRAMS 64

// ----------------------------------------------------------------------------
// structures
typedef struct
{
    int sku;
    double price;
    int calories;
    double weight;
} CatFoodInfo;

// ----------------------------------------------------------------------------
// function prototypes
// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *value);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *value);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(int numProducts);

// 4. Get user input for the details of cat food product
CatFoodInfo getCatFoodInfo(int productNumber);

// 5. Display the formatted table header
void displayCatFoodHeader();

// 6. Display a formatted record of cat food data
void displayCatFoodData(int sku, double price, double weight, int calories);

// 7. Logic entry point
void start();

#endif
