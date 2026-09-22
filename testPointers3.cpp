//Test pointers 3
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    int savings = 10000;
    int *pSavings = &savings;

    *pSavings += 5000;

    cout << "Savings 1: " << savings << endl;
    cout << "Savings 2: " << *pSavings << endl;
    cout << endl;

   
    return 0;
}