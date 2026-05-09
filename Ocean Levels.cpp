/******************************************************************************
 Program Name: Ocean Levels.cpp
 Author: Matthew Sprague
 Assignment: Chapter 5 - Ocean Levels
 Date: 3/13/2026
 Purpose: The ocean is rising at an average rate of 1.5 millimeters per year. 
 Write a program that displays a table showing the number of millimeters 
 that the ocean will have risen each year for the next 25 years.
 ******************************************************************************/

 #include<iostream>
    #include<iomanip>
    using namespace std;

    int main()
    {
        const double RISE_PER_YEAR = 1.5;
        const int YEARS = 25;

        cout << "Year\tRise (mm)" << endl;
        for (int year = 1; year <= YEARS; year++)
        {
            cout << year << "\t" << year * RISE_PER_YEAR << endl;
        }

        return 0;
    }