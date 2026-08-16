/***************************************************************************
Mass and Weight:  
Scientists measure an object’s mass in kilograms and its weight in newtons. 
If you know the amount of mass that an object has, you can calculate its 
weight, in newtons, with the 

following formula: Weight = mass * 9.8

Write a program that asks the user to enter an object’s mass, then calculates 
and displays its weight. If the object weighs more than 1,000 newtons, 
display a message indicating that it is too heavy. If the object weighs less 
than 10 newtons, display a message indicating that the object is too light.
*****************************************************************************/

#include<iostream>
#include<iomanip>
using namespace std;

main()
{
    char again;

    do
    {
            
        double mass, weight;

        cout << "Please enter an object's mass in kilograms: ";
        cin >> mass;

        weight = mass * 9.8;

        cout << fixed << setprecision(2);
        cout << "\nWeight in newtons is: " << weight << endl;

        if (weight > 1000)
            cout << "\nThe objects weight is too heavy!" << endl;
        else if (weight < 10)
            cout << "\nThe objects weight is too light!" << endl;

        cout << "\nWould you like to try again (Y/N)? ";
        cin >> again;

        cout << endl;

    } while (again == 'Y' || again == 'y');

    return 0;
}