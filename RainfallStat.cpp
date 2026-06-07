/******************************************************************************
Rainfall Statistics  Write a program that lets the user enter the total 
rainfall for each of 12 months into an array  of  .  The  program  should  
calculate  and  display  the  total  rainfall  for  the  year, the average 
monthly rainfall, and the months with the highest and lowest amounts.
Input Validation: Do not accept negative numbers for monthly rainfall figures.
******************************************************************************/
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int main()
{
    const int MONTHS = 12;
    double rain[MONTHS];
    string monthNames[MONTHS] = 
    {
        "January", "February", "March" , "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    double total = 0;
    double highest, lowest;
    int highMonth = 0, lowMonth = 0;

    // Input rainfall with validation
    for (int i = 0; i < MONTHS; i++)
    {
        cout << "Enter rainfall for " << monthNames[i] << ": ";
        cin >> rain[i];

        while (rain[i] < 0)
        {
            cout << "Error: rainfall cannot be negative. Enter again: ";
            cin >> rain[i];
        }
        total += rain[i];
    }

    // Initialize highest and lowest
    highest = rain[0];
    lowest = rain[0];

    // Find highest and lowest
    for (int i = 1; i < MONTHS; i++)
    {
        if (rain[i] > highest)
        {
            highest = rain[i];
            highMonth = i;
        }

        if (rain[i] < lowest)
        {
            lowest = rain[i];
            lowMonth =i;
        }
    }

     // Output results
    cout << fixed << setprecision(2);
    cout << "\nTotal rainfall for the year: " << total << " inches\n";
    cout << "\nAverage monthly rainfall: " << total / MONTHS << " inches\n";
    cout << "\nHighest rainfall: " << highest << " inches in " << monthNames[highMonth] << endl;
    cout << "\nLowest rainfall: " << lowest << " inches in " << monthNames[lowMonth] << endl;

    return 0;
}