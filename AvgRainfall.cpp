//Average Rainfall
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

char again;

int main()
{
    char again;
    
    do
    {
        string month[3];
        double rain[3];
        double avg = 0;

        for (int i = 0; i < 3; i++)
        {
            cout << "Enter the name of the month " << i + 1 << ": ";
            cin >> month[i];

            cout << "Enter the rainfall for " << month[i] << " (in inches): ";
            cin >> rain[i];
            cout << endl;

            while (rain[1] < 0)
            {
                cout << "Error: rainfall cannot be negative. Enter again: ";
                cin >> rain[i];
            }

            avg += rain[i];
        }

       avg /= 3;
   

        cout << fixed << setprecision(2);
        cout << "\nThe average rainfall for " << month[0] << ", " << month[1] << ", " << month[2]
         << " is " << avg << " inches." << endl;

         cout << "\nWould you like to enter again(Y/N): ";
         cin >> again;
         cout << endl;

    } while (again == 'Y' || again == 'y');
    
    return 0;
}