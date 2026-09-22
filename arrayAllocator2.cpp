/****************************************************************************************************
*Array Allocator  Write a function that dynamically allocates an array of integers. The function * *  should accept an integer argument indicating the number of elements to allocate. The function * *       should return a pointer to the array.
****************************************************************************************************/

#include<iostream>

using namespace std;

//==========================================================================
// Function prototype
//==========================================================================

// Dynamicall allocates an array of the given size and returns a pointer
// to it
int *allocateArray(int size);

//==========================================================================

int main()
{
    const int SIZE = 7;
    int *numbers = allocateArray(SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        *(numbers + i) = i * 10;
    }

    cout << "The array contains:\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << *(numbers + i) << " ";
    }

    cout << endl;

    delete [] numbers;
    numbers = nullptr;

    return 0;
}

//============================================================================
// allocateArray: Dynamically allocates an array of integers large enough
//                to hold "size" elements
//Parameters: size - the number of integers to allcoate space for (read-only)
// Returns:  a pointer to the first element of the newly alloacted array
//============================================================================

int *allocateArray(int size)
{
    int *arr = new int[size];
    return arr;
}