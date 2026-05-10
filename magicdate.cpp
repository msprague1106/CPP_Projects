/*********************************************************************************************** 
Magic Dates  The date June 10, 1960 is special because when we write it in the following format, the month times the day equals the year.6/10/60  Write a program that asks the user to enter a month (in numeric form), a day, and a two-digit year. The program should then determine whether the month times the day is equal to the year. If so, it should display a message saying the date is magic. Otherwise, it should display a message saying the date is not magic.
***********************************************************************************************/

#include<iostream>
using namespace std;

int main()
{
    int mon, day, year;
    char again;

    do
    {
        do
        {
             cout << "Enter the month (1-12) ";
             cin >> mon;

             if (mon < 1 || mon > 12)
                cout << "Invalid: Number must be between 1-12 \n";
                
        
        } while (mon < 1 || mon > 12);
            
        cout << "Enter the day: ";
        cin >> day;

        cout << "Enter the two digit year: ";
         cin >> year;

        if (mon * day == year)
        {
            cout <<"\nThat date is magic!\n";
        } 
        else
        {
            cout <<"\nNo magic happened. :(\n";
        }
        cout << endl;
        
        cout << "Would you like to try again? ";
        cin >> again;

         cout << "________________________________\n";   

    }while (again == 'Y' || again == 'y');

    return 0;
}