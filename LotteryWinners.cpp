/******************************************************************************
 A lottery ticket buyer purchases ten tickets a week, always playing the same 
 ten 5-digit “lucky” combinations. Write a program that initializes an array 
 or a  with these numbers, then lets the player enter this week’s winning 
 5-digit number. The program should perform a linear search through the list 
 of the player’s numbers and report whether or not one of the tickets is a 
 winner this week. Here are the numbers:
 *****************************************************************************/
#include<iostream>
using namespace std;

int main()
{
    const int NUM_TICKETS = 10;

     int tickets[NUM_TICKETS] = {13579, 26791, 26792, 
                                 33445, 55555, 62483, 
                                 77777, 79422, 85647, 
                                 93121};

    int winningNumbers;
    char again;

    do
    {
        cout << "Enter this week's winning 5-digit number: ";
        cin >> winningNumbers;
        cout << endl;

        bool found = false;

        for (int i = 0; i < NUM_TICKETS; i++)
        {
            if (tickets[i] == winningNumbers)
            {
                found = true;
                break;
            }
        }

        if (found)
        {
            cout << "You have a winning ticket!\n";
        }
        else
        {
            cout << "Sorry, no winnng tickets this week.\n";
        }

        cout << "\nYou you like to try again (Y/N): ";
        cin >> again;
        cout << endl;
        
    } while (again == 'Y' || again == 'y');
    
    return 0;
}