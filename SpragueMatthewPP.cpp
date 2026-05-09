/***************************************************************************
Program:  SpragueMatthewPP
Author:   Matthew Sprague
Assignment: Chapter 5 - Population Prattsville
Date: 3/13/2026
Purpose: This programs reads population values for Prattsville from an input
		 file. Each value represents the population (rounded to the nearest
		 1000 people) at 20-year intervals beginning with the year 1800. The
		 program displays a bar chart on the screen and writes the same chart
		 to an output file. 
***************************************************************************/

#include<iostream>
#include<fstream>
#include<string>
#include<cmath>

using namespace std;

int main()
{
	//Variables
	string fileName;      //storing the name of the input file from the user. 
	ifstream inputFile;   //Read data from the chosen file.  
	ofstream outputFile;   //Write the chart to a text file.
	int currentPopulation;  //To store each population number read from file.
	int currentYear=1800;  //Tracking year for the chart. 
	int numberOfStars;     //Calculate how many asterisks to print. 
	int starCounter;      //Loop counter for printing asterisks. 
	
	//Prompt user for file name. 
	cout<<"Enter the input file name: ";
	cin>>fileName;
	inputFile.open(fileName);
	
	//Validation loop to verify the input file can open. 
	while(!inputFile)
	{
		cout<<"Error: Cannot open the file.\n";
		cout<<"Please enter a valid file name: ";
		cin>>fileName;
		inputFile.clear();
		inputFile.open(fileName);
	}
	
	//Open the output file. 
	outputFile.open("SpragueMatthew.txt");
	
	//Check if the output file was created. 
	if(!outputFile)
	{
		cout<<"Error: Cannot create the output file.\n";
		inputFile.close();
		return 1;
	}
	
	//Display and write chart header. 
	cout<<"\nPRATTSVILLE POPULATION GROWTH\n";
	cout<<"(each * represents 1000 people)\n";
	cout<<"________________________________\n\n";
	
	outputFile<<"PRATTSVILLE POPULATION GROWTH\n";
	outputFile<<"(each * represents 1000 people)\n";
	outputFile<<"________________________________\n\n";
	
	//Read population until end of file. 
	while(inputFile>>currentPopulation)
	{
	
		//Calculate the number of * needed. 
		numberOfStars=round(currentPopulation/1000.0);
	
		//Print the screen and file
		cout<<currentYear<<" ";
		outputFile<<currentYear<<" ";
	
		//Print * to file. 
		for(starCounter=0; starCounter<numberOfStars; starCounter++)
		{
			cout<<"*";
			outputFile<<"*";
		}
	
		//Move to the line for file
		cout<<"\n";
		outputFile<<"\n";
	
		//Increment year by 20
		currentYear+=20;
	}
	
	//Close files 
	inputFile.close();
	outputFile.close();
	
	cout<<"\n________________________________\n\n";
	cout<<"Process complete. Chart saved to text file.\n";
		
	return 0;
}