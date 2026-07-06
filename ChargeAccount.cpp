/*****************************************************
Charge Account Validation:
Write a program that lets the user enter a charge account number. The program shoulddetermine if the number is valid by checking for it in the following list:
The list of numbers above should be initialized in a single-dimensional array. A simple linear search should be used to locate the number entered by the user. If the user enters a number that is in the array, the program should display a message saying the number is valid. If the user enters a number that is not in the array, the program should display a message indicating the number is invalid.
 *****************************************************/

 #include<iostream>
 using namespace std;

 //=================================================
 // Function Prototypes
 //=================================================
 void selectionSort(int arr[], int size);
 bool binarySearch(int arr[], int size, int target);

 int main()
 {
    const int SIZE = 18;

    int accounts[SIZE] = 
    {
        5658845, 4520125, 7895122, 8777541, 8451277, 1302850,8080152, 4562555, 5552012, 5050552, 7825877, 1250255,1005231, 6545231, 3852085, 7576651, 7881200, 4581002
    };

    // Sort the array befoe the binary search.
    selectionSort(accounts, SIZE);

    int userAccount;
    char again;

    do
    {

        cout << "Enter a charge account number: ";
        cin >> userAccount;
        cout << endl;

        if (binarySearch(accounts, SIZE, userAccount))
        {
            cout << "The number is valid.\n";
        }
        else
        {
            cout <<"The number is invalid.\n";
        }

        cout << "\nWould you like to try again (Y/N): ";
        cin >> again;
        cout << endl;

    }while (again == 'Y' || again == 'y');

    cout <<"Program ended. Good bye.\n";

    return 0;
 }

 // ============================================================
 //                     Function Definitions
 // ============================================================
 void selectionSort(int arr[], int size)
 {
    for (int i = 0; i <size - 1; i++)
    {
        int minIndex = i;

        for (int j = i +1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

 }

 // ===========================================================
 // bool binarySearch
 // ============================================================
 bool binarySearch(int arr[], int size, int target)
 {
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
        {
            return true;
        }
        else if (target < arr[mid])
        {
            high = mid -1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return false;
 }