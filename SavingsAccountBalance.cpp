/***************************************************************************
Savings Account 
Balance  Write a program that calculates the balance of a savings account 
at the end of a period of time. It should ask the user for the annual 
interest rate, the starting balance, and the number of months that have 
passed since the account was established. A loop should then iterate once 
for every month, performing the following:   Ask the user for the amount 
deposited into the account during the month. (Do not accept negative numbers.) 
This amount should be added to the balance.Ask the user for the amount withdrawn 
from the account during the month. (Do not accept negative numbers.) This amount 
should be subtracted from the balance.Calculate the monthly interest. The monthly 
interest rate is the annual interest rate divided by 12. Multiply the monthly 
interest rate by the balance, and add the result to the balance. 
NOTE: If a negative balance is calculated at any point, a message 
should be displayed indicating the account has been closed and the loop should 
terminate. 
*******************************************************************************/
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    char again;

    do
    {
        double annualRate;
        double balance;
        double monthlyRate;
        int months;

        // Get the annual interest rate
        cout << "Enter the annual interest rate as a percent: ";
        cin >> annualRate;

        while (cin.fail() || annualRate < 0)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: Interest rate cannot be negative. Try again: ";
            cin >> annualRate;
        }

        // Convert to deicimals montly rate
        monthlyRate = (annualRate / 100) / 12.0;

        // Get starting balance
        cout << "Enter the starting balance: ";
        cin >> balance;

        while (cin.fail() || balance < 0) 
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: Starting balance cannot be negative. Try again: ";
            cin >> balance;
        }

        // Get number of months
        cout << "Enter the number of months since the account was opened: ";
        cin >> months;
        while (cin.fail() || months < 1) 
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: Months must be at least 1. Try again: ";
            cin >> months;
        }

        // Monthly processing loop
        for (int m = 1; m <= months; m++) 
        {
            double deposit, withdrawal;

            cout << "\nMonth " << m << endl;

            // Deposit
            cout << "Amount deposited: ";
            cin >> deposit;
            while (cin.fail() || deposit < 0) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Error: Deposit cannot be negative. Try again: ";
                cin >> deposit;
            }
            balance += deposit;

            // Withdrawal
            cout << "Amount withdrawn: ";
            cin >> withdrawal;
            while (cin.fail() || withdrawal < 0) 
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Error: Withdrawal cannot be negative. Try again: ";
                cin >> withdrawal;
            }
            balance -= withdrawal;

            // Check for account closure
            if (balance < 0) {
                cout << "\nAccount has been closed due to negative balance." << endl;
                break;
            }

            // Monthly interest
            double interest = balance * monthlyRate;
            balance += interest;
        }

        cout << fixed << setprecision(2);
        cout << "\nFinal balance: $" << balance << endl;

        cout << "\nWould you like to run the program again (Y/N): ";
        cin >> again;

        
    } while (again == 'Y' || again == 'y');

    return 0;
}