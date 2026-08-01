/*******************************************************************************
Test Scores #1  
Write a program that dynamically allocates an array large enough to hold a
 userdefined number of test scores. Once all the scores are entered, the 
 array should be passed to a function that sorts them in ascending order. 
 Another function should be called that calculates the average score. 
 The program should display the sorted list of scores and averages with 
 appropriate headings. Use pointer notation rather than array notation 
 whenever possible.  
 
 Input Validation: Do not accept negative numbers for test scores.
****************************************************************************/

#include<iostream>
using namespace std;

// Function prototypes
void sortScores(int* scores, int size);
double averageScore(int* scores, int size);

int main()
{
    int size;

    cout << "How many test scores? ";
    cin >> size;

    // Validates size
    while (cin.fail() || size <= 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\nInvaild. Please enter a postive number: ";
        cin >> size;  
    }
    
    // Dynamicall allocate array
    int* scores = new int[size];

    // Input scores with validation
    cout << "\nEnter " << size << " test scores:\n\n";
    for (int i = 0; i < size; i++)
    {
        cout << "Score " << i + 1 << ": ";
        cin >> *(scores + i);
        
        while (cin.fail() || *(scores + i) < 0)
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "\nInvalid. Enter a postive score: ";
            cin >> *(scores + i);
        }
    }

    // Sort the scores
    sortScores(scores, size);

    // Calculate average
    double avg = averageScore(scores, size);

    // Display the results
    cout << "\nSorted Scores:\n";
    for (int i = 0; i < size; i++)
    cout << *(scores + i) << " ";

    cout << "\n\nAverage Score: " << avg << endl;

    // Free memory
    delete[] scores;
    
    return 0;
}

//===========================================================
//                   Function Defintions                    =
//===========================================================

// Sort scores in accending order (pointer notation)
void sortScores(int* scores, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (*(scores + j) < *(scores + i))
            {
                int temp = *(scores + i);
                *(scores + i) = *(scores + j);
                *(scores + j) = temp;
            }
        }
    }
}

// Calculate average (pointer notation)
double averageScore(int* scores, int size)
{
    double total = 0;

    for (int i = 0; i < size; i++)
    total += *(scores + i);

    return total / size;
}