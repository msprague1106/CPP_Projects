/**************************************************************************************************
Test Scores #1:
  Write a program that dynamically allocates an array large enough to hold a userdefined number of test scores. Once all the scores are entered, the array should be passed to a function that sorts them in ascending order. Another function should be called that calculates the average score. The program should display the sorted list of scores and averages with appropriate headings. Use pointer notation rather than array notation whenever possible.  
  Input Validation: Do not accept negative numbers for test scores.
**************************************************************************************************/
#include<iostream> // lets us use cout and cin for input/output

using namespace std; // This lets us write cout instead of std::cout.

//===============================================================================================
// Function prototypes
//===============================================================================================
void sortScores(double *scores, int size); // Functio that sorts the scores
double calcAverage(double *scores, int size); // Function that calculates the average

//===============================================================================================

int main()  //This main function - the program starts here
{
    int size; // This variable will store how many test scores the user wnats

    cout << "How many test scores? ";  // Ask the user how many scores they have.
    cin >> size;                       // Read the number the user types.

    while (size <= 0)                  // Input validation: must be postive
    {
        cout << "Invalid: You must enter postive number!: ";  
        cin >> size;
    }

    // =================Dynmaically allocate memory =================================
    // new double[size] creates 'size' number of boxes in memory to hold scores
    // scores is a POINTER that points to the first box. 
    double *scores = new double[size];

    // Get scores from user
    for (int i = 0; i < size; i++)  // loop through each score postion
    {
        double temp;  // Temporary variable to hold score.
        cout << "Enter score #" << i + 1 << ": ";
        cin >> temp;  // read the score
    

        while (temp < 0)  // Input validation: no negative scores
        { 
            cout << "No negative scores. Please try again: ";
            cin >> temp;
        }

        *(scores + i) = temp;  // Store the score using POINTER notation
        // socres = address of first score
        // scores + 1 = address of the i-th score
        // *(scores + 1) = the actucal score stored in that memeory box
    }

    // Sorts the scores
    sortScores(scores, size);  // Call the sorting function

    // Calculate the average
    double average = calcAverage(scores, size);  // Call the average function

    // Display the sorted scores
    cout << "\nSorted Scores:\n";  // Print a heading
    for (int i = 0; i < size; i++) // Loop through sorted scores
    {
        cout << *(scores + i) << endl; // Print each score using pointer notation
    }

    // Dispaly the average
    cout << "\nAverage Score: " << average << endl;

    // Free the memory
    delete []scores; // Delete the dynamic array to avoid memory leaks

    return 0; // End of program
}

//==============================================================================================
//sortScores
//================================================================================================
void sortScores(double *scores, int size) {   // Function receives a pointer and size.
    bool swapped;                             // This will track if we swapped anything.

    do {                                      // Repeat until no swaps happen.
        swapped = false;                      // Reset swapped to false each loop.

        for (int i = 0; i < size - 1; i++)   // Loop through each pair of neighbors.
        {  
            // Get the current score and the next score using pointer notation.
            double current = *(scores + i);
            double next = *(scores + i + 1);

            if (current > next) {             // If they are out of order...
                // Swap them.
                *(scores + i) = next;
                *(scores + i + 1) = current;
                swapped = true;               // Mark that a swap happened.
            }
        }

    } while (swapped);                        // Keep looping until no swaps occur.
}

//==============================================================================================
//double calcAverage
//=============================================================================================
double calcAverage(double *scores, int size) {  // Function receives pointer + size.
    double sum = 0;                             // Start sum at 0.

    for (int i = 0; i < size; i++)               // Loop through all scores.
    {           
        sum += *(scores + i);                   // Add each score using pointer notation.
    }

    return sum / size;                          // Divide by number of scores.
}
