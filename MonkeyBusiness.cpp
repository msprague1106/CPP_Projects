/*****************************************************************************
Monkey Business  
A local zoo wants to keep track of how many pounds of food each of its three 
monkeys eats each day during a typical week. Write a program that stores 
this information in a two-dimensional 3 × 5 array, where each row represents 
a different monkey, and each column represents a different day of the week. 
The program should first have the user input the data for each monkey. 
Then, it should create a report that includes the following information:  
• Average amount of food eaten per day by the whole family of monkeys.
• The least amount of food eaten during the week by any one monkey.
• The greatest amount of food eaten during the week by any one monkey.  
Input Validation: Do not accept negative numbers for pounds of food eaten.
***************************************************************************/
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    const int MONKEY = 3;
    const int DAYS = 5;
    const int LABEL_WIDTH = 66;
    const int VALUE_WIDTH = 8;

    double food[MONKEY][DAYS];
    double total = 0;
    double highest, lowest;

    // Input food data with validation
    for (int m = 0; m < MONKEY; m++)
    {
        cout << "Enter pounds of food eaten by a Monkey " << (m + 1)
            << " for 5 days:\n";

        for (int d = 0; d < DAYS; d++)
        {
            cout << " Day " << (d + 1) << ": ";
            cin >> food[m][d];
        
            while (food[m][d] < 0)
            {
                cout << "Error: food cannot be negative. Enter again: ";
                cin >> food[m][d];
            }
        }
    }

    // Initialize highest and lowest to first element
    highest = food[0][0];
    lowest = food[0][0];

    // Process total, highest and lowest.
    for (int m = 0; m < MONKEY; m++)
    {
        for (int d = 0; d < DAYS; d++)
        {
            double amount = food[m][d];
            total += amount;

            if (amount > highest)
                highest = amount;

            if (amount < lowest)
                lowest = amount;
        }
    }

    // Results
    cout << "\n------------------------------------ Monkey Food Report ------------------------------\n\n";

    cout << fixed << setprecision(2);

        cout << left << setw(LABEL_WIDTH)
            << "1. Average food eaten per day by (all Monkeys):"
            << right << setw(VALUE_WIDTH) << total / (MONKEY * DAYS) << " pounds\n";

        cout << left << setw(LABEL_WIDTH)
            << "2. The lowest amount of food eaten during the week by any monkey:"
            << right << setw(VALUE_WIDTH) << lowest << " pounds\n";

        cout << left << setw(LABEL_WIDTH)
            << "3. Greatest amount of food eaten during the week by any monkey:"
            << right << setw(VALUE_WIDTH) << highest << " pounds" << endl;

    return 0;
}