/***************************************************************************************************
Sum of Numbers   Write a program that asks the user for a positive integer value. 
The program should use a loop to get the sum of all the integers from 1 up to the number entered. 
For example, if the user enters 50, the loop will find the sum of 1, 2, 3, 4, . . ., 50.
Input Validation: Do not accept a negative starting number..
*******************************************************************************************************/

#include<iostream>
using namespace std;

int main()
{
    char again;
    int number;
    int sum;

    do
    {
        cout << "Enter a postive number: ";
        cin >> number;

        while (cin.fail() || number < 1)
        {
            cin.clear();             // clear error flag
            cin.ignore(1000, '\n');  // discard invalid input 

            cout << "Error: You must enter a postive number. ";
            cin >> number;
        }

        // Loop to compute the sum from 1 to number
        sum = 0; // reset sum each loop

        for (int i = 1; i <= number; i++)
        {
            sum += i;
        }

        cout << "\nThe sum of numbers from 1 to " << number << " is "
             << sum << endl;

        cout << "\nWould you like to try again(Y/N): ";
        cin >> again; 

    } while (again == 'Y' || again == 'y');
    
    return 0;

}