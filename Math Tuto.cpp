/******************************************************************************
Program Name: Math Tutor 
 Author: Matthew Sprague
 Assignment: Chapter 3 - Math Tutorial
 Date: 3/13/2026
 Purpose: This program provides a tutorial on basic math operations.
 *****************************************************************************/

#include <iostream>
#include <iomanip>
#include <random>
using namespace std;

int main()
{
	int choice;
	int num1;
	int num2;
	int studentAnswer;
	int correctAnswer;
	random_device myEngine;
	uniform_int_distribution<int> twoDigit(0, 1000);
	uniform_int_distribution<int> smallFactor(2, 100);

	choice = 0;

	while (choice != 5)
	{
		cout << endl;
		cout << "Math Tutor Menu" << endl;
		cout << "1. Addition" << endl;
		cout << "2. Subtraction" << endl;
		cout << "3. Multiplication" << endl;
		cout << "4. Division" << endl;
		cout << "5. Quit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		if (choice == 1)
		{
			num1 = twoDigit(myEngine);
			num2 = twoDigit(myEngine);
			correctAnswer = num1 + num2;
			cout << endl;
			cout << setw(6) << num1 << endl;
			cout << "+" << setw(5) << num2 << endl;
			cout << "------" << endl;
			cout << "Your answer: ";
			cin >> studentAnswer;

			if (studentAnswer == correctAnswer)
			{
				cout << "Congratulations! That is correct." << endl;
			}
			else
			{
				cout << "Sorry, that is not correct." << endl;
				cout << "The correct answer is " << correctAnswer << "." << endl;
			}
		}
		else if (choice == 2)
		{
			num1 = twoDigit(myEngine);
			num2 = twoDigit(myEngine);
			if (num2 > num1)
			{
				int temp = num1;
				num1 = num2;
				num2 = temp;
			}
			correctAnswer = num1 - num2;
			cout << endl;
			cout << setw(6) << num1 << endl;
			cout << "-" << setw(5) << num2 << endl;
			cout << "------" << endl;
			cout << "Your answer: ";
			cin >> studentAnswer;

			if (studentAnswer == correctAnswer)
			{
				cout << "Congratulations! That is correct." << endl;
			}
			else
			{
				cout << "Sorry, that is not correct." << endl;
				cout << "The correct answer is " << correctAnswer << "." << endl;
			}
		}
		else if (choice == 3)
		{
			num1 = smallFactor(myEngine);
			num2 = smallFactor(myEngine);
			correctAnswer = num1 * num2;
			cout << endl;
			cout << setw(6) << num1 << endl;
			cout << "*" << setw(5) << num2 << endl;
			cout << "------" << endl;
			cout << "Your answer: ";
			cin >> studentAnswer;

			if (studentAnswer == correctAnswer)
			{
				cout << "Congratulations! That is correct." << endl;
			}
			else
			{
				cout << "Sorry, that is not correct." << endl;
				cout << "The correct answer is " << correctAnswer << "." << endl;
			}
		}
		else if (choice == 4)
		{
			num2 = smallFactor(myEngine);
			correctAnswer = smallFactor(myEngine);
			num1 = num2 * correctAnswer;
			cout << endl;
			cout << setw(6) << num1 << endl;
			cout << "/" << setw(5) << num2 << endl;
			cout << "------" << endl;
			cout << "Your answer: ";
			cin >> studentAnswer;

			if (studentAnswer == correctAnswer)
			{
				cout << "Congratulations! That is correct." << endl;
			}
			else
			{
				cout << "Sorry, that is not correct." << endl;
				cout << "The correct answer is " << correctAnswer << "." << endl;
			}
		}
		else if (choice == 5)
		{
			cout << "Goodbye!" << endl;
		}
		else
		{
			cout << "Error: Invalid menu selection. Try again." << endl;
		}
	}

	return 0;
}
