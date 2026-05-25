/************************************************************************
Population:
Write a program that will predict the size of a population of organisms. 
The program should ask the user for the starting number of organisms, 
their average daily population increase (as a percentage), and the 
number of days they will multiply. A loop should display the size 
of the population for each day.Input Validation: Do not accept a 
number less than 2 for the starting size of the population. 
Do not accept a negative number for average daily population 
increase. Do not accept a number less than 1 for the number 
of days they will multiply.
*************************************************************************/

#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    char again;

    do
    {
        int startPop;
        int days;
        double dailyIncrease;
        double rate;
        double population;

        // Getting starting population
        cout << "Enter the starting number of organisms: ";
        cin >> startPop;

        while (cin.fail() ||startPop < 2) 
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Error: Starting population must be at least 2. Try again: ";
            cin >> startPop;
        }

        // Get daily increase percentage
        cout << "Enter the average daily population increase (in %): ";
        cin >> dailyIncrease;

        while (cin.fail() || dailyIncrease < 0)
         {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Error: Increase cannot be negative. Try again: ";
            cin >> dailyIncrease;
        }

         // Convert percentage to decimal
        rate = dailyIncrease / 100.0;

        // Get number of days
        cout << "Enter the number of days they will multiply: ";
        cin >> days;

        while (cin.fail() || days < 1)
         {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Error: Days must be at least 1. Try again: ";
            cin >> days;
        }

         // Display results
        cout << "\nDay\tPopulation\n";
        cout << "-------------------\n";

        population = startPop;

        for (int day = 1; day <= days; day++)
        {
           
            cout << day << "\t" << fixed << setprecision(2)
                 << population <<endl;
            
            population = population + (population * rate);

        }

        cout << "\nWould you like to try again(Y/N): ";
        cin >> again;
        cout << endl;
     
    } while (again == 'Y' || again == 'y');
    
    return 0;
}