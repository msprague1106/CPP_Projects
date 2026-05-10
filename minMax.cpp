//Min max
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    double larger, smaller;
    double num1, num2;
    

    cout << "Enter a number: ";
    cin >> num1;

    cout << "Enter another number: ";
    cin >> num2;

    //Determin max and min
    smaller = (num1 < num2) ? num1 : num2;
    larger = (num1 > num2) ? num1 : num2;

    // Display output
    cout << fixed << setprecision(2);
    cout << "\nThe smaller number is $" << smaller << endl;
    cout << "\nThe larger number is $" << larger << endl;

    return 0;
}