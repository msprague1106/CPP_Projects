//Calculate BMI
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    double weight, height, bmi;

    while (true) 
    {
        cout << "Enter weight in pounds: ";
        cin >> weight;

        cout << "Enter height in inches: ";
        cin >> height;

        if (weight > 0 && height > 0)
            break;

        cout << "\nError: Both values must be positive. Try again.\n\n";
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