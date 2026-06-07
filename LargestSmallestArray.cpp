/******************************************************************************
Largest/Smallest Array Values 
Write a program that lets the user enter ten values into an array. The program 
should then display the largest and smallest values stored in the array.
******************************************************************************/
#include<iostream>
using namespace std;

int main()
{
    const int SIZE = 10;
    int numbers[SIZE];
    int largest, smallest;

    cout << "Enter " << SIZE << " integers\n";
    for (int index; index < SIZE; index++)
    {
        cout << "Value " << (index + 1) << ": ";
        cin >> numbers[index];
    }

    // Initialize largest and smallest with the first element
    largest = numbers[0];
    smallest = numbers[0];

    // Step through the array to find extremes
    for (int index = 0; index < SIZE; index++)
    {
        if (numbers[index] > largest)
            largest = numbers[index];
        if (numbers[index] < smallest)
            smallest = numbers[index];
    }

    cout << "The LARGEST number is: ";
    cout << "\nThe SMALLEST number is: ";

    return 0;
}