#include <iostream>
#include <string>
#include "ticket.h"
#include "show.h"
#include "customer.h"
#include "showSeat.h"
#include "promotion.h"

using namespace std;

int main() {
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // Initial variable declarations

    string a,
            b,
            c,
            f,
            g,
            h;
    int d,
        ctype;
    map<int,string> e;
    char ch,
            terminator;

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // Objects

    showSeat SEAT;
    SEAT.initialiseFloorPlan();

    customer CUST;
    show SHOW;
    ticket TICK;
    promotion PROM;

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // Deal with customer's information

    CUST.getLogin();
    CUST.getProfileInfo(f,g,h, ctype);

    do
    {
        // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        // Displays Main Menu, and allows customer to choose option

        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MAIN MENU ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
        cout << " 1. Buy tickets for upcoming shows" << endl;
        cout << " 2. Log out\n" << endl;
        cout << "Please enter a menu choice number: ";
        cin.get(ch);
        while(ch != '1' && ch != '2')
        {
            cin.clear();
            cin.ignore(100, '\n'); // Ensures buffer is completely clear (if, say, the user inputs a long string)
            cout << "Please select a valid menu choice number: ";
            cin.get(ch);
        }
        if (ch== '2')
        {
            return EXIT_SUCCESS;
        }

        // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        // Deals with selecting a show

        do
        {
            SHOW.selectShow(a,b);
            SHOW.selectTime(c);

            do
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "\nAre you happy with your choice (Y = Yes, N = No)?: ";
                cin.get(ch);
                cin.clear();
                cin.ignore(100, '\n');
            }
            while (ch != 'Y' && ch != 'y' && ch != 'N' && ch != 'n');
        }
        while (ch == 'N' || ch == 'n' );

        // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        // Deals with selecting seat and calculating price of seats

        do
        {
            // release hold of seats
            if(!e.empty())
            {
                SEAT.reinitialiseFloorPlan();
                e.clear();
            }

            // initialises choice
            ch = 'N';

            d = SEAT.getNumSeats();
            e = SEAT.getSeatSelection(d);

            do
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "\n=================================================================================" << endl;
                cout << "Number of seats: " << e.size() << endl;
                for(int i = 0; i < e.size(); i++)
                {
                    cout << "Seat #" << i + 1 << ": "<< e[i]<< endl;
                }
                cout << "=================================================================================" << endl;
                cout << "\nAre you happy with your choice (Y = Yes, N = No)?: ";
                cin >> ch;
            }
            while (ch != 'Y' && ch != 'y' && ch != 'N' && ch != 'n');
        }
        while(ch == 'N' || ch == 'n');

        // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        // Deals with discounts, payment and ticket generation

        SEAT.reserveSeats(e);
        auto selectedSeats = PROM.getPriceMap(e, ctype);
        TICK.setPrice(selectedSeats);
        CUST.getPaymentInfo();
        TICK.printTicket(a,b,c,selectedSeats,f,g,h);


    }
    while(true);
}


