/********************************************************************************
Restaurant Bill:  
Write a program that computes the tax and tip on a restaurant bill for a patron 
with a $88.67 meal charge. The tax should be 6.75 percent of the meal cost. 
The tip should be 20 percent of the total after adding the tax. Display the meal 
cost, tax amount, tip amount, and total bill on the screen.
*********************************************************************************/
#include<iostream>
#include<iomanip>
using namespace std; 

int main()
{
    double mealCharge = 88.67;
    double taxRate = 0.0675;
    double tipRate = .20;

    double tax = mealCharge * taxRate;
    double totalAfterTax = mealCharge + tax;
    double tip = totalAfterTax * tipRate;
    double totalBill = mealCharge + tip + tax;

    cout << fixed << setprecision(2);


    cout << left << setw(13)<< "Meal Cost:" 
         << right << right << setw(9) << "$ "<< mealCharge << endl;

    cout << left << setw(13)  << "Tax Amount:" << right
         << setw(9) << "$ " << tax << endl;

    cout << left << setw(13) << "Tip Amount:" << right
         << setw(9) << "$ " << tip << endl;

    cout << left << setw(13) << "Total Amount:" << right
         << setw(9) << "$ " << totalBill << endl;

    return 0;

}