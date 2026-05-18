/********************************************************************************************************
Book Club Points  Serendipity Booksellers has a book club that awards points to its customers based on the number of books purchased each month. The points are awarded as follows:  
     If a customer purchases 0 books, he or she earns 0 points.
    • If a customer purchases 1 book, he or she earns 5 points.
    • If a customer purchases 2 books, he or she earns 15 points.
    • If a customer purchases 3 books, he or she earns 30 points.
    • If a customer purchases 4 or more books, he or she earns 60 points.  
Write a program that asks the user to enter the number of books he or she has purchased this month then displays the number of points awarded.
********************************************************************************************************/

#include<iostream>
using namespace std;

int main()
{
    int books;
    int points = 0;
    char again; 

    do
    {
        cout << "Enter the number of books you have purchased this month: ";
        cin >> books;

        while (cin.fail() || books < 0)
        {
            cin.clear();             // clear error flag
            cin.ignore(1000, '\n'); // discard bad input

            cout << "\nError: Please enter a valid non-negative number: \n";
            cin >> books;
        }
        switch (books)
        {
            case 0:
                points = 0;
                break;
            case 1:
                points = 5;
                break;
            case 2:
                points = 15;
                break;
            case 3:
                points = 30;
                break;
            default:
                points = 60;
        }

        cout << "\nYou earned " << points << " points total for the month. \n";

        cout << "\nWould you like to enter books again (Y/N): ";
        cin >> again;
        cout << endl;
        
    } while (again == 'Y' || again == 'y');
    
    return 0;
}