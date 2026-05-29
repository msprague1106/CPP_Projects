/*************************************************************
Budget Analysis  
---------------
Write a program that asks the user to enter the amount that he 
or she has budgeted for a month. A loop should then prompt the 
user to enter each of his or her expenses for the month and keep 
a running total. When the loop finishes, the program should 
display the amount that the user is over or under budget.
****************************************************************/

#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    char again;

    do
    {
        double budget;
        double expense;
        double totalExpenses = 0;

        // Get monthly budget
        cout << "Enter your budget for the month: ";
        cin >> budget;

        while (cin.fail() ||budget < 0)
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Error: Your budget cannot be negative. Please try again: ";
            cin >>  budget;
        }

        //Expense loop 
        cout << "Enter your expense for the month." << endl;
        cout << "Enter (-1) when you are finished.\n" << endl;

        cout << "Enter your expenses: ";
        cin >> expense;

        while (expense != -1)
        {
            while (cin.fail() || expense < 0)
            {
                if (expense == -1)
                break; // allow -1 to exit
                cin.clear();
                cin.ignore(1000, '\n');

                cout << "Error: Expenses cannot be negative. Try again: ";
                cin >> expense;
            }

            if (expense == -1)
            break;

            totalExpenses += expense;

            cout << "Enter an expense: ";
            cin >> expense;

        }

        // Display results
        cout << fixed << setprecision(2);
        cout << "\nTotal expenses are: $" << totalExpenses << endl;

        if (totalExpenses > budget)
        {
            cout << "You are over budget by: $"
                 << (totalExpenses - budget) << endl;
        }
        else if (totalExpenses < budget)
        {
            cout << "You are under budget by: $" 
                 << (budget - totalExpenses) << endl;
        }
        else 
        {
            cout << "You are EXACTLY on budget!" << endl;
        }

        cout << "\nWould you like to try again(Y/N): ";
        cin >> again;

    } while (again == 'Y' || again == 'y');
    
    return 0;
}