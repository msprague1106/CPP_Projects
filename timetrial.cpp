/*********************************************************************************************
 * 
 * 
 ***********************************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <sstream>
using namespace std;

// Convert seconds → mm:ss.xx format
string formatTime(double seconds) 
{
    int minutes = seconds / 60;
    double sec = seconds - (minutes * 60);

    ostringstream out;
    out << minutes << ":" << fixed << setprecision(2) << sec;
    return out.str();
}

// Runner struct
struct Runner 
{
    string name;
    double time;   // stored in seconds
};

// Get runner info with validation
void getRunner(Runner &r)
 {
    cout << "Enter runner name: ";
    getline(cin, r.name);

    do 
    {
        cout << "Enter " << r.name << "'s time in seconds (positive): ";
        cin >> r.time;

        if (r.time <= 0)
            cout << "Invalid time. Must be a positive number.\n";

    } while (r.time <= 0);

    cin.ignore(); // clear newline
}

int main() 
{
    char again;

    do 
    {
        Runner r[3];

        // Input all runners
        for (int i = 0; i < 3; i++)
        {
            getRunner(r[i]);
        }

        // Sort runners by time (ascending)
        sort(r, r + 3, [](Runner a, Runner b) 
        {
            return a.time < b.time;
        });

        // Display results
        cout << "\n--- Race Results ---\n";
        cout << "1st: " << r[0].name << " (" << formatTime(r[0].time) << ")\n";
        cout << "2nd: " << r[1].name << " (" << formatTime(r[1].time) << ")\n";
        cout << "3rd: " << r[2].name << " (" << formatTime(r[2].time) << ")\n";

        // Play again?
        cout << "\nRun another race? (Y/N): ";
        cin >> again;
        cin.ignore();

        cout << "--------------------------------------\n\n";

    } while (again == 'Y' || again == 'y');

    return 0;
}
