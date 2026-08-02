/******************************************************************************
Ocean Levels:  
Assuming the ocean’s level is currently rising at about 1.5 millimeters per 
year, write a program that displays:  • The number of millimeters higher than 
the current level that the ocean’s level will be in 5 years.• The number of 
millimeters higher than the current level that the ocean’s level will be in 
7 years.• The number of millimeters higher than the current level that the 
ocean’s level will be in 10 years.
********************************************************************************/
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    double risePerYear = 1.5;

    double risePerYear5 = risePerYear * 5;
    double risePerYear7 = risePerYear * 7;
    double risePerYear10 = risePerYear * 10;

    cout << fixed << setprecision(1);

   cout << left  << setw(20) << "Rise in 5 years:"
         << right << setw(1) << risePerYear5 << " mm" << endl;

    cout << left  << setw(20) << "Rise in 7 years:"
         << right << setw(1) << risePerYear7 << " mm" << endl;

    cout << left  << setw(20) << "Rise in 10 years:"
         << right << setw(1) << risePerYear10 << " mm" << endl;

         return 0;

}