//
// Created by Tomás Pinto on 04/01/2023.
//

#ifndef OOSD_CO567_SHOWSEAT_H
#define OOSD_CO567_SHOWSEAT_H

#include <iostream>
#include <iomanip>
#include <string>

//using namespace std;

class showSeat
{
    public:
        showSeat();
        ~showSeat();
        void initialiseFloorPlan();
        int getNumSeats();
        double getSeatSelection();

    double getSeatSelection(int i);

private:
        void displayFloorPlan();
        void calculatePrice(double &price); //encapsulation - functions only accessed by this class, and no other part of the program

    protected:
        char floorPlan[7][6];
        int numSeats;
        int rNum; // used to calculate price
        double price;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Constructor

showSeat :: showSeat()
{
    for(int r = 0; r < 7; r++)
    {
        for(int c = 0; c < 6; c++)
        {
            floorPlan[r][c] = '0'; // allocates memory slots for floor plan array

            numSeats = 0;
            rNum = 0;
            price = 0; // initialises remaining variables
        }
    }
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Destructor

showSeat :: ~showSeat()
{
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Initialises theatre floor plan

void showSeat :: initialiseFloorPlan()
{
    for(int r = 0; r < 7; r++) // prepares rows
    {
        for(int c = 0; c < 6; c++) // prepares columns
        {
            floorPlan[r][c] = 'A'; // populates array with 'A' character (Available)
        }
    }
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Gets the user's no. of seats
int showSeat :: getNumSeats()
{

    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ SELECT SEATS INTERACTIVELY ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;

    displayFloorPlan();
    do {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "How many tickets would you like to purchase (Max. 8)?: "; // prompts customer to enter no. of tickets
        cin >> numSeats;
        cout << endl;
    } while (!(numSeats >=1 && numSeats <=8));

    return numSeats;
}

void showSeat::displayFloorPlan()
{
    // initialises row letters
    char a = 'A';

    // Prints the rows
    for(int i = 0; i < 7; i++)
    {
        // Prints the column numbers
        if(i == 0)
        {
            cout << "   ";
            for(int j = 1; j < 7; j++)
            {
                cout << " ~~" << j << "~~ ";
            }
            cout << endl;
        }

        // Prints the columns
        for(int j = 0; j < 6; j++)
        {
            // Prints the row letters
            if(j == 0)
            {
                cout << char(a) << "~~";
                // increases letter
                a++;
            }
            cout << "   " << floorPlan[i][j] << "   ";
        }
        cout << "\n" << endl;
    }
}

double showSeat::getSeatSelection(int numSeats) {

    // Here it should iterate numSeats times and ask what row letter and colum number
    // of the seat user wants to hold. Display the floor map again with the hold seats.
    // Display an error if the seat is already taken or does not exist (e.g: seat A199)
    // Print a message with the seat sleected.

    //leave this here for now
    return 0;
}

#endif //OOSD_CO567_SHOWSEAT_H