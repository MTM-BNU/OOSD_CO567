//
// Created by Tomás Pinto on 04/01/2023.
//

#ifndef OOSD_CO567_SHOW_H
#define OOSD_CO567_SHOW_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class show
{
    public:
            show();
            ~show();
            void selectShow(string &showName, string &showDate);
            void selectTime(string &showTime);

    protected:
            string showName;
            string showDate;
            string showTime;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Constructor

show :: show()
{
    showName = "";
    showDate = "";
    showTime = "";
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Destructor

show :: ~show()
{
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Customer selects upcoming show

void show :: selectShow(string &showName, string &showDate)
{
    char ch;
    char terminator;

    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ SELECT AN UPCOMING SHOW ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
    cout << "1. Star Wars: The Musical (20/05/2013)" << endl;
    cout << "2. Les Miserables (21/05/2013)" << endl;
    cout << "3. The Phantom of the Opera (22/05/2013)\n" << endl;

    cin.clear();
    cin.ignore(100, '\n'); // Ensures buffer is completely clear (if, say, the user inputs a long string)
    cout << "Please select a show number: ";
    cin.get(ch);

    while(ch != '1' && ch != '2' && ch != '3')
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Please select a valid show number: ";
        cin.get(ch);
    }

    switch(ch)
    {
        case '1' : showName = "Star Wars: The Musical", showDate = "20/05/2023";
            break;
        case '2' : showName = "Les Miserables", showDate = "21/05/2023";
            break;
        case '3' : showName = "The Phantom of the Opera", showDate = "22/05/2023";
            break;
    }

    this -> showName = showName;
    this -> showDate = showDate; // enters reference variable into class variable

    cin.get(terminator); // clears buffer
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Customer selects 1pm/7pm showing

void show :: selectTime(string &showTime)
{
    char ch;

    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ SELECT PERFORMANCE TIME ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
    cout << "1. Matinee Performance (1pm)" << endl;
    cout << "2. Evening Performance (7pm)" << endl;
    cout << "\nPlease select a performance choice number: ";
    cin.get(ch);

    while(ch != '1' && ch != '2')
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Please select a valid performance choice number: ";
        cin.get(ch);
    }

    switch(ch)
    {
        case '1' : showTime = "1pm";
            break;
        case '2' : showTime = "7pm";
            break;
    }

    this -> showTime = showTime;

    cout << "\nYou have chosen " + showName + " at " + showTime + " (" + showDate + ")\n";
}

#endif //OOSD_CO567_SHOW_H