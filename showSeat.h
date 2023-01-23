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
    int r;
    int c;

    for(int r = 0; r < 7; r++) // prepares rows
    {

        for(int c = 0; c < 6; c++) // prepares columns
        {

            floorPlan[r][c] = 'A';// populates array with 'A' character (Available)

        }

    }
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Gets the user's no. of seats
int showSeat :: getNumSeats()
{

    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ SELECT SEATS INTERACTIVELY ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;

    cout << "\n How many tickets would you like to purchase (Max. 8)?:   " ; // prompts customer to enter no. of tickets
    cin >> numSeats;
    cout << "\n" << endl;
    displayFloorPlan();
    do {
        cin.clear();
        cin.ignore(100, '\n');

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
    cout<<"              ~~~  Key  ~~~";
    cout<<"\n           A - Available seats";
    cout<<"\n           H - Held  seats    "<<endl;
}

double showSeat::getSeatSelection(int numSeats) {
    int i;
    int a;
    char b;
    floorPlan[7][6];

    for (i = 0; i < numSeats; i++) {



        cin.clear();
        /* cin.ignore(100, '\n');*/
        cout << " \n Please Enter a column number (1-6) for seat  " << i + 1;
        cout << ":  ";
        cin >> a;
        cin.clear();
        cin.ignore(100, '\n');
        floorPlan[a-2][6]='H';

        cout << "\n Please Enter a  row  number  (A-G) for seat  " << i + 1;
        cout << ":  ";
        cin >> b;
        cout << "\n" << endl;
        cin.clear();
        cin.ignore(100, '\n');
        floorPlan[7][b-2]='H';






    }

   /* floorPlan[a][6]='H';
    floorPlan[7][b]='H';*/

    displayFloorPlan();

    // Here it should iterate numSeats times and ask what row letter and colum number DONE
    // of the seat user wants to hold. Display the floor map again with the hold seats.
    // Display an error if the seat is already taken or does not exist (e.g: seat A199)
    // Print a message with the seat sleected.

    //leave this here for now


/* void showSeat::update( int a, char b) {
    char floorPlan [a][b];
    initialiseFloorPlan();
    floorPlan[a][b] = 'H';*/





    }



#endif //OOSD_CO567_SHOWSEAT_H