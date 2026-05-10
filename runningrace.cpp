/*************************************************************************************************
Running the Race  Write a program that asks for the names of three runners and the time it took each of them to finish a race. The program should display who came in first, second, and third place.  Input Validation: Only accept positive numbers for the times.
************************************************************************************************/

#include<iostream>
using namespace std;

int main()
{
    string runner1, runner2, runner3;
    double time1, time2, time3;

    cout << "Enter the name of runner1: ";
    getline(cin, runner1);

    cout << "Enter the name of runner2: ";
    getline(cin, runner2);

    cout << "Enter the name of runner3: ";
    getline(cin, runner3);

     // Validate time for runner 1
    do {
        cout << "Enter " << runner1 << "'s time (positive number): ";
        cin >> time1;

        if (time1 <= 0)
            cout << "Invalid time. Please enter a positive number.\n";

    } while (time1 <= 0);

     // Validate time for runner 2
    do {
        cout << "Enter " << runner2 << "'s time (positive number): ";
        cin >> time2;

        if (time2 <= 0)
            cout << "Invalid time. Please enter a positive number.\n";

    } while (time2 <= 0);

     // Validate time for runner 3
    do {
        cout << "Enter " << runner3 << "'s time (positive number): ";
        cin >> time3;

        if (time3 <= 0)
            cout << "Invalid time. Please enter a positive number.\n";

    } while (time3 <= 0);

     cout << "\n--- Race Results ---\n";

      // Determine order
    if (time1 < time2 && time1 < time3) {
        cout << "1st: " << runner1 << " (" << time1 << ")\n";
        if (time2 < time3) {
            cout << "2nd: " << runner2 << " (" << time2 << ")\n";
            cout << "3rd: " << runner3 << " (" << time3 << ")\n";
        } else {
            cout << "2nd: " << runner3 << " (" << time3 << ")\n";
            cout << "3rd: " << runner2 << " (" << time2 << ")\n";
        }
    }
    else if (time2 < time1 && time2 < time3) {
        cout << "1st: " << runner2 << " (" << time2 << ")\n";
        if (time1 < time3) {
            cout << "2nd: " << runner1 << " (" << time1 << ")\n";
            cout << "3rd: " << runner3 << " (" << time3 << ")\n";
        } else {
            cout << "2nd: " << runner3 << " (" << time3 << ")\n";
            cout << "3rd: " << runner1 << " (" << time1 << ")\n";
        }
    }
    else {
        cout << "1st: " << runner3 << " (" << time3 << ")\n";
        if (time1 < time2) {
            cout << "2nd: " << runner1 << " (" << time1 << ")\n";
            cout << "3rd: " << runner2 << " (" << time2 << ")\n";
        } else {
            cout << "2nd: " << runner2 << " (" << time2 << ")\n";
            cout << "3rd: " << runner1 << " (" << time1 << ")\n";
        }
    }


    return 0;
}