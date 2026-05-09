/*
The following program skeleton determines whether a person qualifies for a credit card. To qualify, the person must have worked on his or her current job for at least 2 years, and make at least $17,000 per year. Finish the program by writing the definitions of the functions  and . The function should explain that the applicant qualifies for the card, and that theannual interest rate is 12 percent. The function should explain that the applicant does not qualify for the card and give a general explanation why.
*/

#include <iostream>
using namespace std;

//You must write definitions for the two funtion qualify and noQualify. 
void qualify()
 {
    cout << "Congratulations! You qualify for the credit card. The annual interest rate is 12 percent." << endl;
}
void noQualify()
{
    cout << "Sorry, you do not qualify for the credit card. To qualify, you must have worked on your current job for at least 2 years and make at least $17,000 per year." << endl;
}

int main()
{
    int years;
    double salary;

    cout<<"This program will determin if you qualify\n";
    cout<<"for our credit card.\n";
    cout<<"What is your annual salary? ";
    cin>>salary;
    cout<<"How many years have you worked at your ";
    cout<<"current job? ";
    cin>>years;
    if(salary>=17000.0&&years>=2)
        qualify();
    else
        noQualify();        


    return 0;
}
