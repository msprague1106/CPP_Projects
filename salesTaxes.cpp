/******************************************************************************
Sales Tax : 
Write a program that will compute the total sales tax on a $95 purchase. 
Assume the state sales tax is 4 percent, and the county sales tax is 2 percent.
******************************************************************************/
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    double sales = 95;
    double stateSalesTax = 0.04;
    double countySalesTax = 0.02;

    double stateTax = sales * stateSalesTax;
    double countyTax = sales * countySalesTax;
    double totalTax = stateTax + countyTax;
    double totalCost = sales + totalTax;
    
    cout << fixed << setprecision(2);

    cout << left << setw(18)<< "State Tax: " << right << setw(3) 
         <<"$" << stateTax << endl;
    cout << left << setw(18)<< "County Tax: " << right << setw(3) 
         << "$" << countySalesTax << endl;
    cout << left << setw(18) << "Total Sales Tax: " << right << setw(3)
         << "$" << totalTax << endl;
    cout << left << setw(18) << "Total Cost: " << right <<setw(1)
         << "$" << totalCost << endl;

    return 0;
}
