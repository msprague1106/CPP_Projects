// Percent value
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

// Function prototype
double presentValue(double futureValue, double annualRate, int years);

int main()
{
    char again;

    do
    {
        double futureValue;
        double deposit; 
        double annualRate;
        int years;

        //Get furture value
        cout << "Enter the furture value you want in your account: ";
        cin >> futureValue;

        while (cin.fail() || futureValue < 0)
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Error: Furture value cannot be negative. Try again: ";
            cin >> futureValue;
        }

        //Get annual interest rate
        cout << "Enter your annual interest rate (as percent): ";
        cin >> annualRate;

        while (cin.fail() || annualRate < 0)
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Error: annual rate cannont be negative. Try again: ";
            cin >> annualRate;
        }
        // Get number of years
        cout << "Enter the number of years the money will sit in the account: ";
        cin >> years;
        while (cin.fail() || years < 1) 
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: Years must be at least 1. Try again: ";
            cin >> years;
        }

        // Calculate the present value
        deposit = presentValue(futureValue, annualRate, years);

        cout << fixed << setprecision(2);
        cout << "\nYou need to deposit $" << deposit << endl;

        cout << "\nWould you like to enter again(Y/N): ";
        cin >> again;
        
    } while (again == 'Y' || again == 'y');

    return 0;
}

// Functin definition
double presentValue(double furtureValue, double annualRate, int years)
{
    double r = annualRate / 100.00; // convert percent to decimal
    return furtureValue / pow(1 + r, years);

}
