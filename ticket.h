//
// Created by Tomás Pinto on 04/01/2023.
//

#ifndef OOSD_CO567_TICKET_H
#define OOSD_CO567_TICKET_H

#include <iostream>
#include <iomanip>
#include <string>
#include <map>

using namespace std;

class ticket
{
    public:
        ticket();
        ~ticket();
        void setPrice(map<string,double> mPrice);
        void printTicket(string showName, string showDate, string showTime, map<string,double> selectedSeats, string fName,
                         string sName, string address);

    protected:
        double totalCost;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Constructor

ticket :: ticket()
{
    totalCost = 0; // initialises total cost
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Destructor

ticket :: ~ticket()
{
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Set Price in ticket

void ticket :: setPrice(map<string,double> mPrice)
{
    double cost;

    for(const auto &[key, value] : mPrice)
    {
        cost += mPrice[key];
    }

    totalCost= cost;
    cout << "\nThe total price of your tickets (including any applicable discount) is £" << totalCost << ".\n" << endl;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Prints Ticket using data from derived classes

void ticket :: printTicket(string showName, string showDate, string showTime, map<string,double> selectedSeats,
                           string fName,string sName, string address)
{
    cout << "\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ YOUR TICKETS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
    cout << "=================================================================================" << endl;
    cout << "==================== The Bucks Centre for the Performing Arts ===================" << endl;
    cout << "================================ Enjoy the show! ================================" << endl;
    cout << "Show: " << showName << endl;
    cout << "Date: " << showDate << endl;
    cout << "Time: " << showTime << endl;
    cout << "=================================================================================" << endl;
    cout << "Number of seats: " << selectedSeats.size() << "\n" << endl;
    int i = 1;
    for(const auto &[key, value] : selectedSeats)
    {
        cout << "Seat #" << i << ": "<< key << endl;
        cout << "Price: £" << selectedSeats[key] << "\n" << endl;
        i++;
    }
    cout << "Total cost: £" << totalCost << endl;
    cout << "Ticket Purchaser: " << fName << " " << sName << endl;
    cout << "Email Address: " << address << endl;
    cout << "=================================================================================" << endl;
    cout << "=================================================================================" << endl;
}

#endif //OOSD_CO567_TICKET_H