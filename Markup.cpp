/***************************************************************************
Markup  Write a program that asks the user to enter an item’s wholesale cost 
and its markup percentage. It should then display the item’s retail price. 
For example:  • If an item’s wholesale cost is 5.00 and its markup percentage 
is 100 percent, then the item’s retail price is 10.00.• IIf an item’s wholesale 
cost is 5.00 and its markup percentage is 50 percent, then the item’s retail 
price is 7.50.  The program should have a function named  that receives the 
wholesale cost and the markup percentage as arguments and returns the retail 
price of the item.  Input Validation: Do not accept negative values for 
either the wholesale cost of the item or the markup percentage.
*****************************************************************************/
#include<iostream>
#include<iomanip>
using namespace std;

double calculateRetail(double wholeSale, double markupPercent);

int main()
{
    char again;

    do
    {
        double wholeSale, markup, retail;

        //Get the wholesale cost.
        cout << "Enter the item's wholesale cost: ";
        cin >> wholeSale;

        while (cin.fail() || wholeSale < 0)
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Error:Wholesale cost cannot be negative. Try again: ";
            cin >> wholeSale;
        }

        //Get markup Percentage
        cout << "Enter the markup percentage: ";
        cin >> markup;

        while (cin.fail() || markup < 0)
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Error: Markup Percentage cannot be negative. Try again ";
            cin >> markup;
        }

        // Calculate retail Price. 
        retail = calculateRetail(wholeSale, markup);

        // Display output
        cout << fixed << setprecision(2);

        cout << "\nThe retail price is $" << retail << endl;

        cout << "\nWould you like to enter again(Y/N): ";
        cin >> again;

    } while (again == 'Y' || again == 'y');

    return 0;
}

// Fuction Definition
double calculateRetail(double wholeSale, double markupPercent)
{
    double markupDecimal = markupPercent / 100.0;
    return wholeSale * (1 + markupDecimal);

}