/******************************************************************************
Write a program that calculates how much a person would earn over a period of 
time if his or her salary is one penny the first day and two pennies the second 
day, and continues to double each day. The program should ask the user for the 
number of days. Display a table showing how much the salary was for each day,
and then show the total pay at the end of the period. The output should be 
displayed in a dollar amount, not the number of pennies.
Input Validation: Do not accept a number less than 1 for the number of days
 worked.
******************************************************************************/
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    char again;
    int days;
    double totalDollars;

    do
    {
        long long dailyPay = 1;  // reset each run
        long long totalPay = 0;  // reset each run

        cout << "Enter the number of days worked: ";
        cin >> days;

        while (days < 1)
        {
            cout << "\nError: You must enter 1 or more days: ";
            cin >> days;
            cout << endl;
        }

        cout << "\nDay\tDaily Pay (pennies)\n";
        cout << "_____________________________\n";

        for (int day = 1; day <= days; day++)
        {
            cout << day << "\t" << dailyPay << endl;
            totalPay += dailyPay;
            dailyPay *= 2;  //doubles for next day
        }

        //Convert pennies to dollars
        totalDollars = totalPay / 100.0;

        cout << fixed << setprecision(2);
        cout << "\nTotal pay in dollars: $" << totalDollars << endl;


        cout << "\nWould you like to try again: ";
        cin >> again;
        cout << endl;

    } while (again == 'Y' || again == 'y');
    
    return 0;
}