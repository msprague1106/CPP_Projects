/******************************************************************************************************
Days in a Month  Write a program that asks the user to enter the month (letting the user enter an integer in the range of 1 through 12) and the year. The program should then display the number of days in that month. Use the following criteria to identify leap years:  1. Determine whether the year is divisible by 100. If it is, then it is a leap year if and only if it is divisible by 400. For example, 2000 is a leap year but 2100 is not.2. If the year is not divisible by 100, then it is a leap year if and only if it is divisible by 4. For example, 2008 is a leap year but 2009 is not.  H
******************************************************************************************************/
#include<iostream>
using namespace std;

int main()
{
    int month, year, days;
    bool leap;
    char again;
    string monthName;

    do
    {
    
        cout << "Enter a month (1-12): ";
        cin >> month; 
        
        while (!cin || month < 1 || month > 12)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid month. Enter a number from 1-12: ";
            cin >> month;
        }

        cout << "Enter a year: ";
        cin >> year;

         while (!cin || year < 1)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid year. Enter a postive number: ";
            cin >> year;

        }

        //Determine if it is a leap year
        if (year % 100 == 0)
        {
            // Century year leap only if divisible by 100
            leap = (year % 400 == 0);
        }
        else
        {
            // Non-Century year = leap if divisible by 4
            leap = (year % 4 == 0);
        }
        switch (month)
        {
            case 1:  monthName = "January";   days = 31; break;
            case 2:  monthName = "February";  days = (leap ? 29 : 28); break;
            case 3:  monthName = "March";     days = 31; break;
            case 4:  monthName = "April";     days = 30; break;
            case 5:  monthName = "May";       days = 31; break;
            case 6:  monthName = "June";      days = 30; break;
            case 7:  monthName = "July";      days = 31; break;
            case 8:  monthName = "August";    days = 31; break;
            case 9:  monthName = "September"; days = 30; break;
            case 10: monthName = "October";   days = 31; break;
            case 11: monthName = "November";  days = 30; break;
            case 12: monthName = "December";  days = 31; break;
        }

        cout << "\n" << monthName << " " << year << " has " << days << endl;

        cout << "\nWould you like to try again? (Y/N): ";
        cin >> again;

    }while (again == 'Y' || again == 'y');

    return 0;
}