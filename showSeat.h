//
// Created by Tomás Pinto on 04/01/2023.
//

#ifndef OOSD_CO567_SHOWSEAT_H
#define OOSD_CO567_SHOWSEAT_H

#include <iostream>
#include <iomanip>
#include <string>
#include <map>

//using namespace std;

class showSeat
{
    public:
        showSeat();
        ~showSeat();
        void initialiseFloorPlan();

        int getNumSeats();
        map<int,string> getSeatSelection(int numSeats);
        void reserveSeats(map<int,string> m);

    void reinitialiseFloorPlan();

private:
        void displayFloorPlan();

    protected:
    char floorPlan[7][6];
        int numSeats;

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

            numSeats = 0;// initialises remaining variables
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

    cout << " How many tickets would you like to purchase (Max. 8)?:   " ; // prompts customer to enter no. of tickets
    cin >> numSeats;

    while (!(numSeats >=1 && numSeats <=8))
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << " How many tickets would you like to purchase (Max. 8)?:   " ; // prompts customer to enter no. of tickets
        cin >> numSeats;
        cin.clear();
        cin.ignore(100, '\n');
    };

    cout << "\n" << endl;
    displayFloorPlan();

    return numSeats;
}

void showSeat::displayFloorPlan()
{
    cout << "\n~~~~~~~~~~~~ Venue Seating Chart ~~~~~~~~~~~~\n" << endl;
    cout << "   -----------------STAGE-----------------" <<endl;
    cout << endl;

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
        cout << endl;
    }
    cout<<"\n              ~~~  Key  ~~~"<<endl;
    cout<<"           A - Available seats"<<endl;
    cout<<"           x - Unavailable seats" <<endl;
    cout<<"           H - Held  seats    "<<endl;
}

map<int,string> showSeat::getSeatSelection(int numSeats)
{
    char ch;
    int chC;
    char chR;
    int c;
    int r;

    map<int,string> holdSeat;

    for (int i = 0; i < numSeats; i++)
    {
        cout << "\n\n~~~  Seat #" << i + 1 <<"  ~~~" << endl;
        cout << "~~~~~~~~~~~~~~~" << endl;
        cin.clear();
        cin.ignore(100, '\n');
        cout << "\n Please Enter a  row  number  (A-G) for seat #" << i + 1 << ": ";
        cin >> chR;

        chR = toupper(chR);

        while(!(chR >= 'A' && chR <= 'G'))
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "  Please select a valid letter: ";
            cin >> chR;
        }

        cin.clear();
        cin.ignore(100, '\n');
        cout << " Please Enter a column number (1-6) for seat #" << i + 1;
        cout << ":  ";
        cin >> chC;

        while(!(chC >= 1 && chC <= 6))
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "  Please select a valid number: ";
            cin >> chC;
        }

        // assign choice to integer r (row) by subtracting char value
        r = chR - 'A';
        // assign choice to integer c (column)
        c = (chC-1);

        if(floorPlan[r][c] == 'A')
        {
            floorPlan[r][c]='H';
            holdSeat[i] = chR + to_string(chC);

            cout << "\nYou have chosen seat #" << i + 1 << " to be " << holdSeat[i] << endl;
        }
        else
        {
            cout << "Seat " << holdSeat[i] << "is already taken!\n" << endl;
            // make user choose another seat instead
            ch = 'N';
        }
    }

    displayFloorPlan();

    return holdSeat;
}

void showSeat::reserveSeats(map<int, string> m)
{
    for(int i = 0; i < m.size(); i++)
    {
        string seat = m[i];

        // initialises row and column of seat to reserve
        int r = -1;
        int c = -1;

        // iterates the string array to get position in seating array
        for(char s : seat)
        {
            if(r == -1)
            {
                r = (s - 'A');
            }
            else
            {
                c = (s - '1');
            }
        }

        if((r < 7 && r >= 0) || (c < 6 && c >= 0))
        {
            floorPlan[r][c] = 'x';
        }
        else
        {
            cout << "There was an error reserving your seats. Please contact the administrator!" << endl;
        }
    }
}

void showSeat::reinitialiseFloorPlan()
{
    //TODO: reduce complexity time from log n^2 to O log n
    // by accessing array directly at position with 'H'
    for(int r = 0; r < 7; r++)
    {
        for(int c = 0; c < 6; c++)
        {
            if(floorPlan[r][c] == 'H')
            {
                floorPlan[r][c] = 'A';
            }
        }
    }
}


#endif //OOSD_CO567_SHOWSEAT_H