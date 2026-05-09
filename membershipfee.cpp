/*****************************************************************************
 Program:  Membership Fee
 Author:   Matthew Sprague
 Assignment: Chapter 5 - Membership Fee
 Date: 3/13/2026
 Purpose: A country club, which currently charges $2,500 per year for membership, has announced it will increase its membership fee by 4 percent each year for the next 6 years. Write a program that uses a loop to display the projected rates for the next 6 years.
 ****************************************************************************/

 #include<iostream>
 #include<iomanip>
 using namespace std;

 int main()
 {     
    const double INCREASE_RATE= 0.04; //4 percent increase.
    const int YEARS=20; //Number of years to calculate.

    double membershipFee=20500.0; //Initial membership fee.s

     cout<<fixed<<setprecision(2);

     cout<<"Year\tMembership Fee\n";
     cout<<"-------------------------\n";

     for(int year=1; year<=YEARS; ++year)
     {
         membershipFee+= membershipFee*INCREASE_RATE; //Increase the fee by 4 percent.
         cout<<year<<"\t$"<<setw(12)<<membershipFee<<endl;
     }

     return 0;
 }