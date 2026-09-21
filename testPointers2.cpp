//Test pointers 2
#include<iostream>
using namespace std;

int main()
{

    // integer named x is set to  value 4
    int x = 4;

    // integer pointer(*) named pX is set to the 
    // address(&) of x
    int *pX = &x;

    // integer named y is set to the thing pointed to
    // (*) by pX
    int y = *pX;
    
    cout << y << endl;

    return 0;
}