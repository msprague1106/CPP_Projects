/*****************************************************************************
Lottery Application:  
Write a program that simulates a lottery. The program should have an array of 
five integers named  and should generate a random number in the range of 0 
through 9 for each element in the array. The user should enter five digits, 
which should be stored in an integer array named . The program is to compare 
the corresponding elements in the two arrays and keep a count of the digits 
that match. 
For example, the following shows the  array and the  array with 
sample numbers stored in each. 
There are two matching digits (elements 2 and 4)  
Lottery array: 74913  User array: 42973  The program should display the random 
numbers stored in the  array and the number of matching digits. If all of the 
digits match, display a message proclaiming the user as a grand prize winner.
******************************************************************************/
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
    char again;
    do
    {
        
        const int SIZE = 5;
        int lottery[SIZE];
        int user[SIZE];
        int matches = 0;

        srand(time(0)); // Seed randomm number generator

        // Generat lottery numbers
        for (int i = 0; i < SIZE; i++)
            lottery[i] = rand() % 10; //0-9

        // get user numbers
        cout << "Enter 5 digits (0-9):\n";
        for (int i = 0; i < SIZE; i++)
        {
            cout << "Digit #" << (i +1) <<": ";
            cin >> user[i];

            while (user[i] < 0 || user[i] >9)
            {
                cout << "Error: Enter digit (0-9): ";
                cin >> user[i];
            }
        }

        // Compare arrays
        for (int i = 0; i < SIZE; i++)
        {
            if (user[i] == lottery[i])
                matches++;
        }

        // Display lottery numbers
        cout << "\nLottery Numbers: ";
        for (int i = 0; i < SIZE; i++)
            cout << lottery[i];

        cout << "\nYour Numbers: " << "   ";
        for (int i = 0; i < SIZE; i++)
            cout << user[i];

        // Display results
        cout << "\n\nMatching digits: " << matches << endl;

        if (matches == SIZE)
            cout << "🎉 GRAND PRIZE WINNER! 🎉\n";
        else
            cout << "Better luck next time.\n";

        cout << "\nWould you like to try again(Y/N): ";
        cin >> again;

    }while (again == 'Y' || again == 'y');    
        
    return 0;
}