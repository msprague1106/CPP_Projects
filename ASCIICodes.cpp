/**************************************************************************************************************
Program Name: ASCIICodes.cpp
Author: Matthew Sprague 
Assignment: Chapter 5 - ASCII Codes
Date: 3/13/2026
Purpose: A program that uses a loop to display the characters for the ASCII codes 0 through 127.
 Display the ASCII code along with the character. Format the output so that it is displayed in two columns.

***************************************************************************************************************/

#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    const int CHARS_PER_LINE = 16;

    for (int code = 0; code <= 127; code++)
    {
        cout << setw(4) << (char)code;

        if ((code + 1) % CHARS_PER_LINE == 0)
        {
            cout << endl;
        }
    }

    return 0;
}