/****************************************************************************************************
*Largest/Smallest Array Values
*Write a program that lets the user enter ten values into an array. The program should then display *the largest and smallest values stored in the array.
*****************************************************************************************************/
#include<iostream>
using namespace std;

int main()
{
    const int SIZE = 3;
    int nums[SIZE];

    cout << "Enter 10 values:\n";

    for (int i = 0; i < SIZE; i++)
        cin >> nums[i];

    int largest = nums[0];
    int smallest = nums[0];

    // scan the array
    for (int i = 1; i < SIZE; i++)
    {
        if (nums[i] > largest)
            largest = nums[i];

        if (nums[i] < smallest)
            smallest = nums[i];
    }

    cout << "\nLargest number: " << largest << endl;
    cout << "Smallest number: " << smallest << endl;
    cout << endl;

    return 0;
}