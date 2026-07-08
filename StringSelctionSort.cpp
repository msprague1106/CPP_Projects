// String Selection Sort
#include <iostream>
#include <string>
using namespace std;

//Prototype
void selectionSort(string arr[], int size);

int main()
{
    const int NUM_NAMES = 20;
    string names[NUM_NAMES] =
    {
        "Collins, Bill", "Smith, Bart", "Allen, Jim",
        "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
        "Taylor, Terri", "Johnson, Jill", "Allison, Jeff",
        "Looney, Joe", "Wolfe, Bill", "James, Jean",
        "Weaver, Jim", "Pore, Bob", "Rutherford, Greg",
        "Javens, Renee", "Harrison, Rose", "Setzer, Cathy",
        "Pike, Gordon", "Holland, Beth"
    };

    selectionSort(names, NUM_NAMES);

    for (int i = 0; i < NUM_NAMES; i++)
    {
        cout << names[i] << endl;
    }

    return 0;
}

// Function definition
void selectionSort(string arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j <size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        string temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}