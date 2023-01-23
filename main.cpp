#include <iostream>
#include <string>
#include "ticket.h"
#include "show.h"
#include "customer.h"
#include "showSeat.h"

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
    int d;
    double e;
    char ch,
            terminator;

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // Objects

    showSeat SEAT;
    customer CUST;
    show SHOW;
    ticket * TICK;

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // Deal with customer's information

    CUST.getLogin();
    CUST.getProfileInfo(f,g,h);

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
        SHOW.selectTime();

        do
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "\nAre you happy with your choice (Y = Yes, N = No)?: ";
            cin.get(ch);
        }
        while (ch != 'Y' && ch != 'y' && ch != 'N' && ch != 'n');
    }
    while (ch == 'N' || ch == 'n' );

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // Deals with selecting seat and calculating price of seats

    SEAT.initialiseFloorPlan();
    d = SEAT.getNumSeats();
    e = SEAT.getSeatSelection(d);

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // Deals with discounts, payment and ticket generation
}
