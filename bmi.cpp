//Calculate BMI
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    double weight, height, bmi;

    
    
        cout << "Enter weight in pounds: ";
        cin >> weight;

        cout << "Enter height in inches: ";
        cin >> height;

        while (weight <= 0 || height <= 0)
        {
            cout << "\nError: Both values must be positive. Try again.\n\n";

            cout << "Enter weight in pounds: ";
            cin >> weight;

            cout << "Enter height in inches: ";
            cin >> height;

        }
    
    bmi = weight * 703 / (height * height);

    cout << fixed << setprecision(2);
    cout << "\nBMI = " << bmi << endl;

    cout << endl;

    if (bmi < 18.5)
        cout << "Status: Under weight\n";

    else if (bmi <= 25)
        cout << "Status: Optimal weight\n";

    else
        cout << "Status: Over weight\n";

    return 0;
}