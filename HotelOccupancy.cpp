/******************************************************************************
Name: Matthw Sprague
Assignment: Chapter 5 - Hotel Occupancy 
Date: 3/13/2026
Purpose: Write a program that calculates the occupancy rate for a hotel. The program should start by asking the user how many floors the hotel has. A loop should then iterate once for each floor. In each iteration, the loop should ask the user for the number of rooms on the floor and how many of them are occupied. After all the iterations, the program should display how many rooms the hotel has, how many of them are occupied, how many are unoccupied, and the percentage of rooms that are occupied. The percentage may be calculated by dividing the number of rooms occupied by the number of rooms. NOTE: It is traditional that most hotels do not have a thirteenth floor. The loop in this program should skip the entire thirteenth iteration.
******************************************************************************/

#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int numFloors;
    int roomsPerFloor;
    int occupiedRooms;
    int totalRooms = 0;
    int totalOccupied = 0;
    double occupancyRate;

    cout << "Enter the number of floors in the hotel: ";
    cin >> numFloors;

    while (numFloors < 1)
    {
        cout << "The hotel must have at least 1 floor. Try again: ";
        cin >> numFloors;
    }

    for (int floor = 1; floor <= numFloors; floor++)
    {
        if (floor == 13)
        {
            cout << "Skipping the 13th floor." << endl;
            continue;
        }

        cout << "Enter the number of rooms on floor " << floor << ": ";
        cin >> roomsPerFloor;

        while (roomsPerFloor < 10)
        {
            cout << "Each floor must have at least 10 rooms. Try again: ";
            cin >> roomsPerFloor;
        }

        cout << "Enter the number of occupied rooms on floor " << floor << ": ";
        cin >> occupiedRooms;

        totalRooms += roomsPerFloor;
        totalOccupied += occupiedRooms;
    }

    int unoccupiedRooms = totalRooms - totalOccupied;
    occupancyRate = static_cast<double>(totalOccupied) / totalRooms * 100;

    cout << fixed << setprecision(2);
    cout << "\nTotal rooms: " << totalRooms << endl;
    cout << "Occupied rooms: " << totalOccupied << endl;
    cout << "Unoccupied rooms: " << unoccupiedRooms << endl;
    cout << "Occupancy rate: " << occupancyRate << "%" << endl;

    return 0;
}