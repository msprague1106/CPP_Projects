//Test pointers
#include<iostream>
using namespace std;

int main()
{

    // pointers = variables that stores a memory address 
    // of anther variable 
    // sometime it's easier to work with an address

    // & address of operator
    // * deference operator

    string name = "Matthew John Sprague";
    int age = 25;
    string freePizzas[5] = {"pizza", "cheese pizza", "noo pizza", "pepperoni pizza", "my pizza" };

    string *pName = &name;
    int *pAge = &age;
    string *pfreePizzas = freePizzas;

    cout << *pName;
    cout << " is " << *pAge << endl;
    cout << endl;
    cout << *freePizzas << endl; 
    cout << endl;
    cout << freePizzas[2] << '\n' << endl;


    return 0;
}