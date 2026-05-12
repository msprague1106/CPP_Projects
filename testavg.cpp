//Test Avg
// Take the avg of 5 test scores. 

#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    char again;
    double s1, s2, s3, s4, s5;
    double average;

    do
    {
        
        cout << "Enter score 1: ";
        cin >> s1;

        cout << "Enter score 2: ";
        cin >> s2;

        cout << "Enter score 3: ";
        cin >> s3;

        cout << "Enter score 4: ";
        cin >> s4;

        cout << "Enter score 5: ";
        cin >> s5;
        cout << endl;

        average = (s1 + s2 + s3 + s4 + s5) / 5;

        cout << "The average of your 5 scores is: " << average << endl;

        cout << "\nWould you like to average more scores(Y/N): ";
        cin >> again;
        cout << endl;
        
    } while (again == 'Y' || again == 'y');
    
  
    return 0;
}
