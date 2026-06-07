/*********************************************************************************
Chips and Salsa  Write a program that lets a maker of chips and salsa keep 
track of sales for five different types of salsa: mild, medium, sweet, hot, 
and zesty. The program should use two parallel 5-element arrays: an array of 
strings that holds the five salsa names, and an array of integers that holds 
the number of jars sold during the past month for each salsa type. The salsa 
names should be stored using an initialization list at the time the name array 
is created. The program should prompt the user to enter the number of jars sold 
for each type. Once this sales data has been entered, the program should produce 
a report that displays sales for each salsa type, total sales, and the names of 
the highest selling and lowest selling products.

Input Validation: Do not accept negative values for number of jars sold.
************************************************************************************/
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int main()
{
    const int SIZE = 5;
    string salsaNames[SIZE] = 
    {"mild" , "medium", "sweet", "hot", "zesty"};
    int jarsSold[SIZE];

    int total = 0;
    int highest, lowest;
    int highIndex = 0;
    int lowIndex = 0;

    for (int i = 0; i < SIZE; i++)
    {
        cout << "Enter the jars sold for " << salsaNames[i] << ": ";
        cin >> jarsSold[i];

        while (jarsSold[i] < 0)
        {
            cout << "Error: number of jars cannont be negative. Enter again: ";
            cin >> jarsSold[i];
        }

         total += jarsSold[i];
    }

    highest = jarsSold[0];
    lowest = jarsSold[0];

    // Find highest ad lowest
    for (int i = 1; i < SIZE; i++)
    {
        if (jarsSold[i] > highest)
        {
            highest = jarsSold[i];
            highIndex = i;
        }

        if (jarsSold[i] < lowest)
        {
            lowest = jarsSold[i];
            lowIndex = i;
        }
    }

    // Build Report
    cout << "\nSales Report\n";
    cout << "________________\n";

    for (int i = 0; i < SIZE; i++)
    {
        cout << left << setw(8) << salsaNames[i]  // 8-character column
             << ": " << jarsSold[i] << " jars" << endl;
    }

    cout << "\nTotal jars sold: " << total << endl;
    cout << "\nHighest selling product: " << salsaNames[highIndex] 
         << " (" << highest << " jars)\n";
    cout << "Lowest selling product: " << salsaNames[lowIndex]
         << " (" << lowest << " jars)\n";

    return 0;
}