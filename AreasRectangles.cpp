/**********************************************************************
Areas of Rectangles  
The area of a rectangle is the rectangle’s length times its width. 
Write a program that asks for the length and width of two rectangles. 
The program should tell the user which rectangle has the greater area, 
or if the areas are the same.
************************************************************************/
#include<iostream>
using namespace std;

int main()
{
    double length1, width1, length2, width2;
    double area1, area2;

    // Rectangle 1
    cout <<"Enter the length of retangle 1: ";
    cin>> length1;
    cout << "Enter the width of rectangle 1: ";
    cin>> width1;

    cout << endl;

    // Rectangle 2
    cout <<"Enter the length of retangle 2: ";
    cin>> length2;
    cout << "Enter the width of rectangle 2: ";
    cin>> width2;

    cout << endl;


    // Calculate areas
    area1 = length1 * width1;
    area2 = length2 * width2;

    // Display areas once
    cout << "Area 1 = " << area1 << endl;
    cout << "Area 2 = " << area2 << endl;

    //Compare areas
    if (area1 > area2)
    {
        cout <<"\nRecatangle 1 has the greater area." << endl;
    }

    else if (area2 > area1)
    {
        cout << "\nRectangle 2 has the greater area." << endl;
    }
        
    else
    {
        cout <<"\nBoth areas are the same!\n" << endl;
    }
  
    return 0;
}