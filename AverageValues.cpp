/*******************************************************************************
Average of Values:  
To get the average of a series of values, you add the values up then divide the 
sum by the number of values. Write a program that stores the following values 
in five different variables: 28, 32, 37, 24, and 33. The program should first 
calculate the sum of these five variables and store the result in a separate 
variable named . Then, the program should divide the  variable by 5 to get 
the average. Display the average on the screen.
********************************************************************************/

#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int v1 = 28;
    int v2 = 32;
    int v3 = 37;
    int v4 = 24;
    int v5 = 33;

    int sum = v1 + v2 + v3 + v4 + v5;

    double avg = sum  / 5.0;

    cout << fixed << setprecision(2);

    cout << left << setw(15) << "The sum of 5 variales is: " 
         << right << setw(10) << sum << endl;

    cout << "\nThe average of the the sum is: " << avg << endl;

    return 0;

}