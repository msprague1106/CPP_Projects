// This program demonstrates a two-dimensinal array. 
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    char again;

    do
    {
        const int NUM_DIVS = 3;             // Number of divisions 
        const int NUM_QTRS = 4;             // Number of Quaters
        double sales[NUM_DIVS][NUM_QTRS];   // Array with 3 rows / 4 columns
        double totalSales = 0;              // To hold the total Sales
        int div, qtr;                       // Loop Counters

        cout << "This program will calculate the total sales of\n";
        cout << "all the company's divisions.\n";
        cout << "\nEnter the following slaes information:\n\n";

        // Nested loops to fill the array with quaterly 
        // sales figures for each division.
        for (div = 0; div < NUM_DIVS; div++)
        {
            for (qtr = 0; qtr < NUM_QTRS; qtr++)
            {
                cout << "Division " << (div + 1);
                cout << ", Quater " << (qtr + 1) << ": $";
                cin >> sales[div][qtr];
            }
            cout << endl; //Print blank line. 
        }

        // Nested loops used to add all the elements.
        for (div = 0; div < NUM_DIVS; div++)
        {
            for (qtr = 0; qtr < NUM_QTRS; qtr++)
                totalSales += sales[div][qtr];
        }

        cout << fixed << setprecision(2);
        cout << "The total sales for the company are: $";
        cout << totalSales << endl;

        cout << "\nWould you like to enter again(Y/N): ";
        cin >> again;

    } while (again == 'Y'|| again == 'y');
    
    return 0;
}