//
// Created by Tomás Pinto on 04/01/2023.
//Updated by Milena Michalska on 19/01/23
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
    char terminator;
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ENTER PROFILE INFORMATION ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
    cout << "\n As you are a new customer, you must provide your profile information" << endl;



    //first name
    cout << "Enter Your Name: ";
    getline(cin, fName);

    while(fName.length() > 15)
    {
        cout << "Your First name should be no more than 15 characters long." << endl;
        cout << "Please re-enter your First Name: ";
        getline(cin, fName);
    }
//surname
    cout << "Enter Your Surname: ";
    getline(cin, sName);

    while(sName.length() > 15)
    {
        cout << "Your  Surname should be no more than 15 characters long." << endl;
        cout << "Please re-enter your Last Name: ";
        getline(cin, sName);
    }

    //email address
    cout << "Enter Your Email Address: ";
    getline(cin, address);

    while(address.length() > 30)
    {
        cout << "Your Email Address should be no more than 30 characters long." << endl;
        cout << "Please re-enter your Email Address: ";
        getline(cin, address);
    }

    cin.get(terminator);
}

#endif //OOSD_CO567_CUSTOMER_H