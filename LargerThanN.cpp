/*******************************************************************************
Larger than n  
In a program, write a function that accepts three arguments: an array, the size of the array, and a number n. Assume the array contains integers. The function should display all of the numbers in the array that are greater than the number 
 n.
********************************************************************************/
#include<iostream>
using namespace std;

// Function prototype
void showLarger(int arr[], int size, int n);

int main()
{
    char again;

    do
    {
    
        const int SIZE = 10;
        int numbers[SIZE] = {3, 10, 5, 8, 2, 15, 7, 1, 20, 9};
        int n;

        cout << "Enter a number n: ";
        cin >> n;

        showLarger(numbers, SIZE, n);

        cout << "\nWould you like to enter again(Y/N): ";
        cin >> again;

    }while(again == 'Y' || again == 'y');

    return 0;
}

// Function
void showLarger(int arr[], int size, int n)
{
    int maxValue = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > maxValue)
            maxValue = arr[i];
    }

    if (n >= maxValue)
    {
        cout << "\nNo numbers are greater than " << n
             << " (maximum value is " << maxValue << ")." << endl;
        return;
    }

    cout << "\nNumbers greater than " << n << ": ";

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > n)
            cout << arr[i] << " ";
    }
    cout << endl;
}