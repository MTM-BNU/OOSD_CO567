//
// Created by Tomás Pinto on 04/01/2023.
//

#ifndef OOSD_CO567_TICKET_H
#define OOSD_CO567_TICKET_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class ticket
{
    public:
        ticket();
        ~ticket();
        void setPrice(double price);
        void printTicket(string showName, string showDate, string showTime, int numSeats, string fName,
                         string sName, string address);
        virtual double cost() = 0; // virtual function used by derived classes

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
// Calculates discount cost from total price

void ticket :: setPrice(double price)
{
    totalCost = price;
    cout << "\nThe total price of your tickets (including any applicable discount) is "
         << (char)156 << this -> cost() << ".\n" << endl;
    system("PAUSE");
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Prints Ticket using data from derived classes

void ticket :: printTicket(string showName, string showDate, string showTime, int numSeats,
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
    cout << "Number of seats: " << numSeats << endl;
    cout << "Total cost: " << (char)156 << this -> cost() << endl;
    cout << "Ticket Purchaser: " << fName << endl;
    cout << "Postal Address: " << address << endl;
    cout << "=================================================================================" << endl;
    cout << "=================================================================================" << endl;
}

#endif //OOSD_CO567_TICKET_H