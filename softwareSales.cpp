//Software Sales
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int units;
    const double PRICE = 99.0;
    double discount = 0;
    double discountedPrice, total;
    char again;

    do
    {
        cout << "Enter the number of units sold: ";
        cin >> units;
    
        while (units <= 0)
        {
            cout << "\nError: Units must be more than 0. \n";
            cin >> units;
        }
        if (units < 10)
            discount = 0.0;
        else if (units < 20)
            discount = .20;
        else if (units < 50)
            discount = .30;
        else if (units < 100)
            discount = .40;
        else 
            discount = .50;
        
        discountedPrice = PRICE * (1 - discount);
        total = units * discountedPrice;

        cout << fixed << showpoint << setprecision(2);

        cout << "\nThe total cost is: $" << total << endl;

        cout << "\nWould you like to enter units again (Y/N): ";
        cin >> again;
        cout << endl;

    } while (again == 'Y' || again == 'y');
    
    return 0;
}
