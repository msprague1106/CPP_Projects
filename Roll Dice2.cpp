/********************************************************************
Program: SpragueMatthewRD.cpp
Author: Matthew Sprague
Assignment: Roll Dice
Due Date: 4/10/2026
Purpose: Roll two dice (red and blue) 1000 times each, track the 
        frequency of each face using arrays, and display the results 
       in a formatted table
***********************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

//Global constant as required by instrutor 
const int SIZE = 6;
const int ROLLS = 1000;

//Function Prototypes
void initialize (int die[SIZE]);
void rollDie(int die[SIZE]);
void display(const int red[SIZE], const int blue[SIZE]);

int main()
{
    // Seed the random number generator
srand(static_cast<unsigned int>(time(0)));
    
//Define the two 1D-arrays
int redDie[SIZE];
int blueDie[SIZE];

//Initialize the arrays
initialize(redDie);
initialize(blueDie);

// Roll dice 1000 times each
rollDie(redDie);
rollDie(blueDie);

// Display the results
display(redDie, blueDie);

return 0;
}
// Sets all elements in the array to zero
void initialize(int die[SIZE]) 
{
	for (int index = 0; index < SIZE; index++)
    {
		die[index] = 0;
	}
}

// Simulates rolling a die 1000 times and fills the array
void rollDie(int die[SIZE]) 
{
	for (int index = 0; index < ROLLS; index++)
	{
		// rand() % 6 produces 0-5.
		int roll =  rand() % SIZE;
		die[roll]++;
	}
}

//Displays the contents of the arrays in a formatted table.
void display(const int red[SIZE], const int blue[SIZE]) 
{
	cout << "The result of rolling 2 dice 1000 time each is:\n\n";
	cout << left << setw(20) << "Blue Dice" << "Red Dice" << endl;
	cout << setw(20) << "==================" << "==================" << endl;

	for (int index = 0; index < SIZE; index++) 
	{
		// Blue die output
		cout << (index +1) << " rolled " << setw(3) << blue[index] << " times";
		cout << "  "; //Spacer

		// Red die output
		cout << (index + 1) << " rolled " << setw(3) << red[index] << " times" 
			<<endl;
	}
}



