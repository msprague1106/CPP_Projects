/**********************
 * Program:  Calories
 * Author:   Matthew Sprague
 * Assignment: Chapter 5 - Calories
 * Date: 3/13/2026
 * Purpose: This program calculates the total calories consumed based on user input.
 **********************/

#include<iostream>
using namespace std;

int main()
{
    //Constants for caleries per minute. 
    const double CALORIES_PER_MINUTE= 3.9;

    int minutes; //To store the number of minutes exercised.
    double calories; //To store the total calories consumed.

    for(minutes=10; minutes<=30; minutes+=5)
    {
        calories= CALORIES_PER_MINUTE*minutes;
        cout<<"After "<<minutes<<" minutes you burned " <<calories<<" calories.\n";
    }

    return 0;
}