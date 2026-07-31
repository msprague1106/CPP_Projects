/*****************************************************************************************************
Array Allocator  Write a function that dynamically allocates an array of integers. The function should accept an integer argument indicating the number of elements to allocate. The function should return a pointer to the array.
*****************************************************************************************************/
#include<iostream>
#include<limits>
using namespace std;

// Function that dynamically allocates an array
int* allocatedArray(int size)
{
    int* arr = new int[size];
    return arr;
}

main()
{
    int size;
    char again;

    do
    {
        cout << "Enter the number of elements to allocate: ";
        cin >> size;

        // If user enters something invalid (like a letter)
        while (cin.fail() || size <= 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Clear leftover input
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Allcoate the array
        int* myArray = allocatedArray(size);

        // Fill the array
        cout << "Enter " << size << " integers:\n\n";
        for (int i = 0; i < size; i++)
        {
            cout << "Element " << i << ": ";
            cin >> myArray[i];

            // Validate each array
            while (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>:: max(), '\n');

                cout << "Invalid input. Enter an integer for Element " << i << ": ";
                cin >> myArray[i];
            }
        }

        // Display the aray
        cout << "\nYou Entered: ";
        for (int i = 0; i <size; i++)
        {
            cout << myArray[i] << " ";
        }

        cout << endl;

        // Free the memeory
        delete[] myArray;

        // Ask user if they want to repeat
        cout << "\nAllocate another array (Y/N): ";
        cin >> again;

        // Clear buffer 
        cin.clear();
        cin.ignore(numeric_limits<streamsize>:: max(), '\n');

    } while (again == 'Y' || again == 'y');
    
    return 0;
}