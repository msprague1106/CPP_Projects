/*****************************************************************************
Student Line Up  
A teacher has asked all her students to line up according to their first name. 
For example, in one class Amy will be at the front of the line, and Yolanda 
will be at the end. Write a program that prompts the user to enter the 
number of students in the class, then loops to read that many names. 
Once all the names have been read, it reports which student would be at the 
front of the line and which one would be at the end of the line. You may assume 
that no two students have the same name.Input Validation: Do not accept a number 
less than 1 or greater than 25 for the number of students.
********************************************************************************/
#include<iostream>
#include<string>
using namespace std;

int main()
{
    char again;
    do
    {
        int numStudents;
        string name;
        string firstName;
        string lastName;

        cout << "Enter the number of students (1-25): ";
        cin >> numStudents;

        while (cin.fail() || numStudents < 1 || numStudents > 25)
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Error: You must enter between 1-25: ";
            cin >> numStudents;
        }
        
        cin.ignore(); // clear leftover newline before getline.

        // Read the first name to initialize comparisons
        cout << "Enter student name: ";
        getline(cin, name);

        firstName = name;
        lastName = name;

        //loop remaining students
        for (int i = 2; i <= numStudents; i++)
        {
            cout << "Enter student name: ";
            getline (cin, name);

            if (name < firstName)
                firstName = name;

            if (name > lastName)
                lastName = name;
        }
        cout << "\nStudent at the front of the line: " << firstName << endl;
        cout << "Student at the end of the line: " << lastName <<endl;


        cout << "\nWould you like to try again(Y/N): ";
        cin >> again;
        cout << endl;
        cin.ignore();
        
    } while (again == 'Y' || again == 'y');
    
    return 0;
}