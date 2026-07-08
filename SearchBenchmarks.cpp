/******************************************************************************
Search Benchmarks:   
Write a program that has an array of at least 20 integers. It should call a 
function that uses the linear search algorithm to locate one of the values. 
The function should keep a count of the number of comparisons it makes until 
it finds the value. 

The program then should call a function that uses the 
binary search algorithm to locate the same value. It should also keep count 
of the number of comparisons it makes. Display these values on the screen.
******************************************************************************/
#include <iostream>
#include <string>
using namespace std;

// Prototype
int linearSearch(int arr[], int size, int target);
int binarySearch(int arr[], int size, int target);

int main()
{
    int target;
    char again;
    const int SIZE = 20;

    int numbers[SIZE] =
    {
       3, 8, 12, 15, 22, 25, 31, 37, 42, 50,
        55, 60, 63, 70, 75, 80, 88, 90, 95, 100 
    };

    do
    {

        cout << "Ener a value to search for: ";
        cin >> target;
        cout << endl;

        // Linear search
        int linearComparisions = linearSearch(numbers, SIZE, target);

        // Binary search
        int binaryComparisons = binarySearch(numbers, SIZE, target);

        cout << "Linear search comparison: " << linearComparisions << endl;
        cout << "Binary search compariosn: " << binaryComparisons << endl;
        cout << endl;

        cout << "Search for another value? (Y/N): ";
        cin >> again;
        cout << endl;

    } while (again == 'Y' || again == 'y'); 

    cout << "Your program has ended." << endl;
    cout << "Good bye." << endl;

    return 0;
}

// Function definitions
int linearSearch(int arr[], int size, int target)
{
    int comparisons = 0;

    for (int i = 0; i < size; i++)
    {
        comparisons++;  // made a comparison

        if (arr[i] == target)
            return comparisons;  // return how many comparisons it took
    }

    return comparisons;  // if not found, return total comparison
}

// Binary Search
int binarySearch(int arr[], int size, int target)
{
    int low = 0;
    int high = size - 1;
    int comparison = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        comparison++;  // Compared arr[mid] to target

        if (arr[mid] == target)
            return comparison;

        else if (target < arr[mid])
            high = mid - 1;

        else
            low = mid +1;
    }

    return comparison; // if not found
}