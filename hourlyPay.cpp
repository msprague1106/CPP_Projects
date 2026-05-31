//Hourly Pay chaptet 7 Arrays
#include<iostream>
#include<iomanip>
using namespace std; 

int main()
{
    char again;

    do
    {
        const int NUM_EMPLOYEES = 5;  // Number of employees
        int hours[NUM_EMPLOYEES];     // Array to hold hours
        double payrate;              // Hourly Pay Rate
        double grossPay;             // To hold gross pay

        // Input hours worked
        cout << "Enter the hours worked by ";
        cout << NUM_EMPLOYEES << " employee who all\n";
        cout << "earn the same hourly rate.\n" << endl;

        for (int index = 0; index < NUM_EMPLOYEES; index++)
        {
            cout << "Employee #" << (index + 1) << ": ";
            cin >> hours[index];
        }

        //Input the hoursly ratefor all employees.
        cout << "\nEnter the hourly rate for all the employees: ";
        cin >> payrate;

        // Display each employee's gross pay. 
        cout << "\nHere is the gross pay for each employee:\n" << endl;
        cout << fixed << setprecision(2);

        for (int index = 0; index < NUM_EMPLOYEES; index++)
        {
            grossPay = hours[index] * payrate;
            cout << "Employee #" << (index + 1);
            cout << ": $" << grossPay << endl;
        }

        cout << "\nWould you like to try again(Y/N): ";
        cin >> again;
        
    } while (again == 'Y' || again == 'y');

    return 0;
    
}