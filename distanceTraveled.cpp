/***************************************************************************************
Distance Traveled  The distance a vehicle travels can be calculated as follows:  For example, if a train travels 40 miles per hour for 3 hours, the distance traveled is 120 miles.Write a program that asks the user for the speed of a vehicle (in miles per hour) and how many hours it has traveled. The program should then use a loop to display the distance the vehicle has traveled for each hour of that time period. Here is an example of the output:  Input Validation: Do not accept a negative number for speed and do not accept any value less than 1 for time traveled.
***************************************************************************************/
#include<iostream>
using namespace std;

int main()
{
    double distance, speed, hours;
    char again;

    do
    {
    cout <<"What is the speed of your vehicle(in mile per hour): ";
    cin >> speed;

    while (speed < 0)
        {
        cout << "Speed cannot be negative. Enter a valid speed: ";
        cin >> speed;
        }

    cout << "How many hour did you travel:  ";
    cin >> hours;

     while (hours < 1)
        {
        cout << "Hours must be at least 1. Enter a valid number of hours: ";
        cin >> hours;
        }

        // Output table
        cout << "\nHours\tDistance Traveled\n";
        cout << "_____________________________\n";

        for (int hour = 1; hour <= hours; hour++)
        {
            distance = speed * hour;
            cout << hour << "\t" << distance << endl;
        }

        cout << "\nWould you like to try again: ";
        cin >> again;
        cout << endl;

    }while(again == 'Y' || again == 'y');

    return 0;
}