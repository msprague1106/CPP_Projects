/******************************************************************************
Minimum/Maximum:  
Write a program that asks the user to enter two numbers. 
The program should use the conditional operator to determine 
which number is the smaller and which is the larger.
******************************************************************************/
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    char again;

    do
    {
        double smaller, larger; // to hold the larger and smaller numbers
        double num1, num2;      // to enter 1st and 2nd numbers

        cout << "Enter any number: ";
        cin >> num1;

        cout << "Enter a second number: ";
        cin >> num2;

        smaller = (num1 < num2) ? num1 : num2;
        larger = (num1 > num2) ? num1 : num2;

        cout << "\nThe smaller number is: " << smaller << endl;
        cout << "The larger number is: " << larger << endl;

        cout << "\nWould you like to try again (Y/N): ";
        cin >> again;

        cout << endl;

    } while (again == 'Y' || again == 'y');

    return 0;
    
}