//stadium seating There are three seating categories at a stadium. For a softball game, Class A seats ///cost $15, Class B seats cost $12, and Class C seats cost $9. Write a program that asks how many tickets for each class of seats were sold, then displays the amount of income generated from ticket sales. Format your dollar amount in fixed-point notation, with two decimal places of precision, and be sure the decimal point is always displayed.

#include<iostream>
#include<iomanip>  // For fixes and setprecision
using namespace std; // cout and cin

int main()
{
    const double SEAT_A_PRICE = 15.00;
    const double SEAT_B_PRICE = 12.00;
    const double SEAT_C_PRICE = 9.00;

    int classA_tickets, classB_tickets, classC_tickets;
    double totalSales;
    char again;

    do
    {
        cout << "Enter the number of Class A tickets sold: ";
        cin >> classA_tickets;

        cout << "Enter the number of Class B tickets sold: ";
        cin >> classB_tickets;

        cout << "Enter the number of Class C tickets sold: ";
        cin >> classC_tickets;

        // Calculation
        totalSales = (classA_tickets * SEAT_A_PRICE) +
                     (classB_tickets * SEAT_B_PRICE) +
                     (classC_tickets * SEAT_C_PRICE);

        // Output formatting
        cout << fixed << showpoint << setprecision(2);
        cout << "\nTotal amount of tickets solds is: $" << totalSales << endl;

        cout << "\nWould you like to enter again (Y/N): ";
        cin >> again;

        cout << "_______________________________________\n\n";
    
    }while (again == 'Y' || again == 'y');  

    return 0;
}