/**************************************************************************
The Greatest and Least of These  Write a program with a loop that lets the 
user enter a series of integers. The user should enter −99 to signal the 
end of the series. After all the numbers have been entered, the program 
should display the largest and smallest numbers entered.
**************************************************************************/
#include<iostream>
using namespace std;

int main()
{
    char again;

    do
    {
        int num;
        int largest;
        int smallest;

        cout << "Enter a series of number, when you want to stop enter -99: ";
        cin >> num;
        cout << endl;

        // Initalize largest and smallest with first valid number
        largest = num;
        smallest = num;

        while (num != -99)
        {
            if (num > largest)
            largest = num;

            if (num < smallest)
            smallest = num;

            cin >> num;
        }

        cout << "\nThe largest number is " << largest << endl;
        cout << "The smallest number is " << smallest << endl;
        
        cout << "\nWould you like to try again(Y/N): ";
        cin >> again;
        cout << endl;
        
    } while (again == 'Y' || again == 'y');

    return 0;
    
}
