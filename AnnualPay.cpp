/*
Name: Mathew Sprague
Date: 6/11/2024     
Description:Suppose an employee gets paid every two weeks and earns $2,200 each pay period. In a year, the employee gets paid 26 times. Write a program that defines the following variables:  This variable will hold the amount of pay the employee earns each pay period. Initialize the variable with 2200.0.This variable will hold the number of pay periods in a year. Initialize the variable with 26.This variable will hold the employee’s total annual pay, which will be calculated.  The program should calculate the employee’s total annual pay by multiplying the employee’s pay amount by the number of pay periods in a year and store the result in the  variable. Display the total annual pay on the screen.
*/
#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
    double payAmount=2200.00; //Amount of pay employee earns each pay period. 
    double payPeriods=26; //Number of pay periods in a year. 
    double annualPay; //Employee's total annual pay.
    
    annualPay=payAmount*payPeriods; //Calculating employee's total annual pay. 

    cout<<"The employee's total annual pay is: $"<<fixed<<setprecision(2)<<annualPay<<endl; //Outputting the result. 

    return 0;
}