/******************************************************************************
Sales Prediction:  
The East Coast sales division of a company generates 58 percent of total sales.
 Based on that percentage, write a program that will predict how much the 
 East Coast division will generate if the company has $8.6 million in sales 
 this year.
******************************************************************************/
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    double totalSales = 8600000;
    double percentSales = 0.58;
    double salesGenerated;

    // Calutlate sales
    salesGenerated = totalSales * percentSales;

    // Display output
    cout << fixed << setprecision(2);
    cout << "The East Coast sales division will generate $" << salesGenerated 
         << " in sales." << endl;

    return 0;
}