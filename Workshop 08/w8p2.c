/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #8 (P2)
Full Name  : Mustafa Dohad
Student ID#: 123090235
Email      : mna26@myseneca.ca
Section    : ZGG

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3report party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p2.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *value)
{
	int input;
	while (1)
	{
		scanf("%d", &input);
		if (input > 0)
		{
			if (value != NULL)
			{
				*value = input;
			}
			return input;
		}
		else
		{
			printf("ERROR: Enter a positive value: ");
		}
	}
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *value)
{
	double input;
	while (1)
	{
		scanf("%lf", &input);
		if (input > 0)
		{
			if (value != NULL)
			{
				*value = input;
			}
			return input;
		}
		else
		{
			printf("ERROR: Enter a positive value: ");
		}
	}
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(int numProducts)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", numProducts);
	printf("NOTE: A 'serving' is %dg\n\n", SERVING_GRAMS);
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int seq_number)
{
	struct CatFoodInfo catFood;
	int flag;
	printf("Cat Food Product #%d\n", seq_number + 1);
	printf("--------------------\n");
	flag = 1;

	// SKU
	printf("SKU           : ");
	flag = 1;
	do
	{
		scanf("%d", &catFood.skuNumber);
		if (catFood.skuNumber <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			flag = 0;
		}
	} while (flag);

	// Price
	printf("PRICE         : $");
	flag = 1;
	do
	{
		scanf("%lf", &catFood.productPrice);
		if (catFood.productPrice <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			flag = 0;
		}
	} while (flag);

	// Weight
	printf("WEIGHT (LBS)  : ");
	flag = 1;
	do
	{
		scanf("%lf", &catFood.productWeight);
		if (catFood.productWeight <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			flag = 0;
		}
	} while (flag);

	// Calories
	printf("CALORIES/SERV.: ");
	flag = 1;
	do
	{
		scanf("%d", &catFood.calories);
		if (catFood.calories <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			flag = 0;
		}
	} while (flag);

	printf("\n");

	// Returning the struct
	return catFood;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted report of cat food data
void displayCatFoodData(int sku_number, double *product_price, int calorie_per_serving, double *product_weight_lbs)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku_number, *product_price, *product_weight_lbs, calorie_per_serving);
}

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double *lbs, double *kgResult)
{

	double poundsToKg = (*lbs) / LBS_TO_KG;

	if (kgResult != NULL)
	{
		*kgResult = poundsToKg;
	}

	return poundsToKg;
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double *lbs, int *gramsResult)
{

	int poundsToG = ((*lbs) / LBS_TO_KG) * 1000;

	if (gramsResult != NULL)
	{
		*gramsResult = poundsToG;
	}

	return poundsToG;
}

// 10. convert lbs: kg and g
void convertLbs(const double *lbs, double *kgResult, int *gramsResult)
{

	double poundsToKg = (*lbs) / LBS_TO_KG;
	int poundsToG = ((*lbs) / LBS_TO_KG) * 1000;

	if (gramsResult != NULL && kgResult != NULL)
	{
		*gramsResult = poundsToG;
		*kgResult = poundsToKg;
	}
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int servingSizeGrams, const int totalGrams, double *numberOfServings)
{

	double servings = ((double)totalGrams) / servingSizeGrams;

	if (numberOfServings != NULL)
	{
		*numberOfServings = servings;
	}

	return servings;
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double *price, const double *numberOfServings, double *result)
{

	double costPerServing = (*price) / (*numberOfServings);

	if (result != NULL)
	{
		*result = costPerServing;
	}

	return costPerServing;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double *price, const double *totalCalories, double *result)
{

	double costPerCal = (*price) / (*totalCalories);

	if (result != NULL)
	{
		*result = costPerCal;
	}

	return costPerCal;
}

// 14. Derive a reporting detail report based on the cat food product data
struct ReportData calculateReportData(struct CatFoodInfo catFood)
{

	struct ReportData report;

	// Assigning Values
	report.skuNumber = catFood.skuNumber;
	report.productPrice = catFood.productPrice;
	report.productWeightPounds = catFood.productWeight;
	report.calories = catFood.calories;

	// Assigning calculated values
	report.productWeightKilos = convertLbsKg(&report.productWeightPounds, &report.productWeightKilos);
	report.productWeightGrams = convertLbsG(&report.productWeightPounds, &report.productWeightGrams);
	report.servings = calculateServings(SERVING_GRAMS, report.productWeightGrams, &report.servings);

	// Total calories
	double totalCalories = report.calories * report.servings;

	report.costPerServing = calculateCostPerServing(&report.productPrice, &report.servings, &report.costPerServing);
	report.costCaloriesPerServing = calculateCostPerCal(&report.productPrice, &totalCalories, &report.costCaloriesPerServing);

	// Returning the struct
	return report;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg)\n", SERVING_GRAMS);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData report, const int cheapestProduct)
{

	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", report.skuNumber, report.productPrice, report.productWeightPounds, report.productWeightKilos, report.productWeightGrams, report.calories, report.servings, report.costPerServing, report.costCaloriesPerServing);
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo catFood)
{
	printf("Final Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%5.2lf\n", catFood.skuNumber, catFood.productPrice);
	printf("\n");

	// Ending line
	printf("Happy shopping!\n");
	printf("\n");
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
	// Struct Arrays
	struct ReportData report[MAX_PRODUCTS] = {{0}};
	struct CatFoodInfo catFood[MAX_PRODUCTS] = {{0}};

	// Declaring variables
	int i, cheapestIndex = 0;

	// Printing the opening message
	openingMessage(MAX_PRODUCTS);

	// Filling the catFood array
	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		catFood[i] = getCatFoodInfo(i);
		report[i] = calculateReportData(catFood[i]);
	}

	// Displaying cat food header
	displayCatFoodHeader();

	// Displaying cat food data
	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		displayCatFoodData(catFood[i].skuNumber, &catFood[i].productPrice, catFood[i].calories, &catFood[i].productWeight);
	}

	// Determining the cheapest product's sku and price
	double cheapestProductPrice = report[0].costPerServing;
	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		if (report[i].costPerServing <= cheapestProductPrice)
		{
			cheapestProductPrice = report[i].costPerServing;
			cheapestIndex = i;
		}
	}
	printf("\n");

	// Displaying the report header
	displayReportHeader();

	// Displaying the report data
	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		displayReportData(report[i], cheapestIndex);

		if (cheapestIndex == i)
		{
			printf(" ***\n");
		}
		else
		{
			printf("\n");
		}
	}
	printf("\n");

	// Displaying final analysis
	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		if (i == cheapestIndex)
		{
			displayFinalAnalysis(catFood[i]);
		}
	}
}
