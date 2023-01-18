//
// Created by Tomás Pinto on 04/01/2023.
//

#ifndef OOSD_CO567_CUSTOMER_H
#define OOSD_CO567_CUSTOMER_H

#include <iostream>
#include <iomanip>
#include <string>
//#include <Windows.h>

//using namespace std;

class customer
{
    public:
            customer();
            ~customer();
            void getLogin();
            void getProfileInfo(string &fName, string &sName, string &address);
            void getPaymentInfo();

    protected:
            string fName;
            string sName;
            string address;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Constructor

customer :: customer ()
{
    fName = "";
    sName = "";
    address = ""; // Initialises variables
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Destructor

customer :: ~customer()
{
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Customer logs in

void customer :: getLogin()
{
    string username; // in the real system, a set of usernames/passwords would be saved in a database file
    string password; // in this prototype, any username/password will be accpeted

    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ LOG IN ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
    cout << "\n Welcome to the Bucks Centre for the Performing Arts ticket purchasing system!" << endl;
    cout << "                                 Please log in." << endl;

    cout << "Enter username: ";
    getline(cin, username);

    while(username.length() > 10)
    {
        cout << "Your username should be no more than 10 characters long." << endl;
        cout << "Please re-enter your username: ";
        getline(cin, username);
    }

    cout << "Enter password: ";
    getline(cin, password);

    while(password.length() > 10)
    {
        cout << "Your password should be no more than 10 characters long." << endl;
        cout << "Please re-enter your password: ";
        getline(cin, password);
    }
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Customer enters profile information

void customer :: getProfileInfo(string &fName, string &sName, string &address)
{

}

#endif //OOSD_CO567_CUSTOMER_H