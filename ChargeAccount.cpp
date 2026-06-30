/*****************************************************
Charge Account Validation:
Write a program that lets the user enter a charge account number. The program shoulddetermine if the number is valid by checking for it in the following list:
The list of numbers above should be initialized in a single-dimensional array. A simple linear search should be used to locate the number entered by the user. If the user enters a number that is in the array, the program should display a message saying the number is valid. If the user enters a number that is not in the array, the program should display a message indicating the number is invalid.
 *****************************************************/

 #include<iostream>
 using namespace std;

 int main()
 {
    const int NUM_ACCOUNTS = 18;

    int accounts[NUM_ACCOUNTS] = 
    {
        5658845, 4520125, 7895122, 8777541, 8451277, 1302850,8080152, 4562555, 5552012, 5050552, 7825877, 1250255,1005231, 6545231, 3852085, 7576651, 7881200, 4581002
    };

    int userAccount;
    char again;

    do
    {

        cout << "Enter a charge account number: ";
        cin >> userAccount;
        cout << endl;

        bool found = false; // assume not found yet

        for (int i = 0; i < NUM_ACCOUNTS; i++)
        {
            if (accounts[i] == userAccount)
            {
                found = true;
                break; // no need to keep searching.
            }
        }

        if (found)
        {
            cout << "The number is valid.\n";
        }
        else 
        {
            cout << "The number is INVALID. Please try again.\n";
        }

        cout << "\nWould you like to try again (Y/N): ";
        cin >> again;
    }while (again == 'Y' || again == 'y');

    return 0;
 }