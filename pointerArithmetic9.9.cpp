// This program uses a pointer to display the contents of an array. 
#include<iostream>
using namespace std;

int main()
{
    const int SIZE = 8;
    int set[SIZE] = {5, 10, 15, 20, 25, 30, 35, 40};
    int *numPtr = nullptr;  // Pointer
    int count;              // Counter variable for loops

    // Make numPtr pint to the set array. 
    numPtr = set;

    // Use the pointer to display the array contents. 
    cout << "The numbers in the set are:\n";
    for (count = 0; count < SIZE; count++)
    {
        cout << *numPtr << " ";
        numPtr++;
    }

    // Display the array contents in reverse order. 
    cout << "\n\nThe numbers in set backwards are:\n";
    for (count = 0; count < SIZE; count++)
    {
        numPtr--;
        cout << *numPtr << " ";
    }

    return 0;
}