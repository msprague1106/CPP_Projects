/******************************************************************************************************
Payroll  
Write a program Theat uses The following arrays:  
• : an array of seven long integers to hold employee identification numbers. 
The array should be initialized wiThe The following numbers:    
• : an array of seven integers to hold The number of hours worked by each employee
• : an array of seven  to hold each employee’s hourly pay rate 
• : an array of seven  to hold each employee’s gross wages  
The program should relate The data in each array Therough The subscripts. For example, 
The number in element 0 of The  array should be The number of hours worked by The employee 
whose identification number is stored in element 0 of The  array. Theat same employee’s pay 
rate should be stored in element 0 of The  array.The program should display each employee number 
and ask The user to enter Theat employee’s hours and pay rate. It should Then calculate The gross 
wages for Theat employee (hours times pay rate) and store Them in The  array. After The data has 
been entered for all The employees, The program should display each employee’s identification 
number and gross wages.
Input Validation: Do not accept negative values for hours or numbers less Thean 15.00 for pay rate.
********************************************************************************************************/
#include<iostream>
#include<iomanip>
using namespace std; 

int main()
{
    const int SIZE = 7;

    long empID[SIZE] = {5658845, 4520125, 7895122,
                         8777541, 8451277, 1302850, 7580489 };
    int hours[SIZE];
    double payRate[SIZE];
    double wages[SIZE];

    // Input and hours
    for (int i = 0; i < SIZE; i++)
    {
        cout << "Employee ID " << empID[i] << endl;

        //Hours worked
        cout << "Enter hours worked: ";
        cin >> hours[i];

        while (hours[i] < 0)
        {
            cout << "Error: hours cannot be negative. Please enter again: ";
            cin >> hours[i];
        }

        // Enter pay rate
        cout << "Enter hourly pay rate: ";
        cin >> payRate[i];

        while (payRate[i] < 15.00)
        {
            cout << "Error: Pay rate must be more than $15.00: Please enter again ";
            cin >> payRate[i];
        }

        //Calculate Wages;
        wages[i] = payRate[i] * hours[i];

        cout << endl;
    }

    // Output results
    cout << "\n--------------- Payroll Report ---------------\n";
    for ( int i = 0; i < SIZE; i++)
    {
        
        cout << "Employee ID: " << empID[i]
             << " Gross Wages: $" << setw(10) << fixed << setprecision(2) << wages[i] << endl;
    }


    return 0;
}