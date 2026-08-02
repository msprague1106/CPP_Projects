/*****************************************************************************
Stadium Seating:  
There are three seating categories at a stadium. For a softball game, Class A 
seats cost $15, Class B seats cost $12, and Class C seats cost $9. Write a 
program that asks how many tickets for each class of seats were sold, then 
displays the amount of income generated from ticket sales. Format your dollar 
amount in fixed-point notation, with two decimal places of precision, and be 
sure the decimal point is always displayed.
******************************************************************************/
#include<iostream>
#include<iomanip>
using namespace std;

main()
{
    const double classA = 15.0;
    const double classB = 12.0;
    const double classC = 9.0;

    int ticketsA, ticketsB, ticketsC;
    double totalSales;

    cout << "Enter the amount of tickets sold for classA seats: ";
    cin >> ticketsA;

    cout << "Enter the amount of tickets sold for classB seats: ";
    cin >> ticketsB;

    cout << "Enter the amount of tickets sold for classC seats: ";
    cin >> ticketsC;

    totalSales = (ticketsA * classA) + (ticketsB * classB) + (ticketsC * classC);

    cout << fixed << showpoint << setprecision(2);

    cout << "\nThe total amount of sales generated from ticket sales is: $" << totalSales << endl;

    return 0;

}