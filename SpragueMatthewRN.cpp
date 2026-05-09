/****************************************************************************
Program: SpragueMatthewRN.cpp
Author: Matthew Sprague
Assignment: Chapter 6 - Arithmetic with Fractions
Due date: 3/27/2026
Purpose: This program performs arithmetic with fractions 
		 The user may load two fractions, add, subtract,
		 multiply, or divide them. All results are displayed in reduced form
		and as decimals. 
****************************************************************************/

#include<iostream>
using namespace std;

/**********Function prototypes**********************/

void loadFraction(int &numerator, int &denominator);    //get a fraction
void reduceFraction(int &numerator, int &denominator); //reduce to lowest terms 
void addFractions(int n1, int d1, int n2, int d2);      // add fractions
void subtractFractions(int n1, int d1, int n2, int d2); //subtract fractions
void multiplyFractions(int n1, int d1, int n2, int d2); //multiply fractoins	
void divideFractions(int n1, int d1, int n2, int d2);	  //divide fractions
int computeGCD(int a, int b);                        //greatest common divisor		   

int main()
{
	// Variables for the two fractions
	int n1=0, d1=1;
	int n2=0, d2=1;
		
	char menuChoice;  //stores the user's menu selection
	
	do
	{
		// Display menu
		cout<<"\n======= Fraction Menu ===========\n";
		cout<<"a) Load/Reload first fraction\n";
		cout<<"b) Load/Reload second fraction\n";
		cout<<"c) Add two fractions and display answer\n";
		cout<<"d) Subtract two fractions and display answers\n";
		cout<<"e) Multiply two fractions and display answers\n";
		cout<<"f) Divide two fractions and display answers\n";
		cout<<"g) Exit\n";
		cout<<"Enter choice: ";
		cin>>menuChoice;
		
	    switch (menuChoice)
		{
			case 'a':
			case 'A':
				loadFraction(n1, d1);
				break;
				
			case 'b':
			case 'B':	
				loadFraction(n2, d2);
				break;
				
			case 'c':
			case 'C':
				addFractions(n1, d1, n2, d2);
				break;
				
			case 'd':
			case 'D':
				subtractFractions(n1, d1, n2, d2);
				break;
				
			case 'e':
			case 'E':
				multiplyFractions(n1, d1, n2, d2);
			    break;
				
			case 'f':
			case 'F':
				divideFractions(n1, d1, n2, d2);
				break;
				
			case 'g':
			case 'G':
				cout<<"\nExiting program.\n";
				break;
				
			default:
				cout<<"\nInvalid choice. Please select a-g.\n";		
		}	
		
	}while(menuChoice !='g'&& menuChoice !='G');
	
	return 0;
	
}
// ================= Function Definitions ===========================

void loadFraction(int &numerator, int &denominator)
{
	cout<<"Enter numerator: ";
	cin>>numerator;
	
	do
	{
		cout<<"Enter denominator (not zero): ";
		cin>>denominator;
		
		if (denominator==0)
		{
			cout<<"Denominator cannot be zero. Try again.\n";
		}
	}while (denominator==0);
}

int computeGCD(int a, int b)
{
	//Make sure values are postive for GCD
	if (a<0) a=-a;
	if (b<0) b=-b;
		
	while (b!=0)
	{
		int remainder=a%b;
		a=b;
		b=remainder;
	}
	
	return a;
}

void reduceFraction(int &numerator, int &denominator)
{
	if(denominator<0)
	{
		numerator=-numerator;
		denominator=-denominator;
	}
	
	int gcd = computeGCD(numerator, denominator);
	
	if (gcd !=0)
	{
		numerator /=gcd;
	    denominator /=gcd;
	}
}

void addFractions(int n1, int d1, int n2, int d2)
{
	int resultNumerator=n1*d2+n2*d1;
	int resultDenominator=d1*d2;
	
	reduceFraction(resultNumerator, resultDenominator);
	
	cout<<"Result: "<<resultNumerator<<"/"
		<< resultDenominator
		<<" = "<<static_cast<double>(resultNumerator)/
				resultDenominator<<endl;
}

void subtractFractions(int n1, int d1, int n2, int d2)
{
	int resultNumerator=n1*d2-n2*d1;
	int resultDenominator=d1*d2;
	
	reduceFraction(resultNumerator, resultDenominator);
	
	cout<<"Result: "<<resultNumerator<<"/"
		<<resultDenominator
	    <<" = "<<static_cast<double>(resultNumerator)/
			   resultDenominator<<endl;
}

void multiplyFractions(int n1, int d1, int n2, int d2)
{
	int resultNumerator=n1*n2;
	int resultDenominator=d1*d2;
	
	reduceFraction(resultNumerator, resultDenominator);
			
	cout<<"Result: "<<resultNumerator<<"/"
		<<resultDenominator
	    <<" = "<<static_cast<double>(resultNumerator)/
			     resultDenominator<<endl;
}

void divideFractions(int n1, int d1, int n2, int d2)
{
	if (n2==0)
	{
		cout<<"Error: Cannot divide by a fraction with "
			<<"numerator of 0.\n"; 
		
		return;
	}
	
	int resultNumerator=n1*d2;
	int resultDenominator=d1*n2;
	
	reduceFraction(resultNumerator, resultDenominator);
	
	cout<<"Result: "<<resultNumerator<<"/"
		<<resultDenominator
	    <<" = "<<static_cast<double>(resultNumerator)/
			   resultDenominator<<endl;
}









