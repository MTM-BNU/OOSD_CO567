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
            void getProfileInfo(string &fName, string &sName, string &address, int &ctype);
            void getPaymentInfo();

    protected:
            string fName;
            string sName;
            string address;
            int ctype;
            bool isDigits(string card);
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
void customer :: getProfileInfo(string &fName, string &sName, string &address, int &ctype)
{

    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ENTER PROFILE INFORMATION ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
    cout << " As you are a new customer, you must provide your profile information" << endl;



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

    //customer category: student, adult or concession
    cout << "\nTicket categories:" << endl;
    cout << "1. Adult" << endl;
    cout << "2. Student" << endl;
    cout << "3. Concession (Senior +65y, child up to 18y, armed forces)" << endl;
    cout << "\nSelect the category for which you want to buy tickets for: ";
    cin >> ctype;
    cin.clear();
    cin.ignore(100, '\n');

    while(ctype > 3 || ctype <= 0)
    {
        cout << "Please choose a valid option: ";
        cin >> ctype;
        cin.clear();
        cin.ignore(100, '\n');
    }

    this->fName = fName;
    this->sName = sName;
    this->address = address;
    this->ctype = ctype;
}

void customer::getPaymentInfo()
{
    string card;
    cout << "\n~~~~~ PAYMENT ~~~~\n" << endl;
    cout << " Please type credit card number: ";
    cin >> card;
    cin.clear();
    cin.ignore(100, '\n');

    while(card.size() != 16 || !isDigits(card))
    {
        cout << " Please input a valid credit card number with 16 digits: ";
        cin >> card;
        cin.clear();
        cin.ignore(100, '\n');
    }

    int month;
    cout << " Please type credit card expiry month (1-12): ";
    cin >> month;
    cin.clear();
    cin.ignore(100, '\n');

    while(!(month >= 1 && month <= 12))
    {
        cout << " Please input a valid month between 1 and 12: ";
        cin >> month;
        cin.clear();
        cin.ignore(100, '\n');
    }

    int year;
    cout << " Please type credit card expiry year greater than 2022: ";
    cin >> year;
    cin.clear();
    cin.ignore(100, '\n');

    while(year <= 2022)
    {
        cout << " Please input a valid year (2023-2999): ";
        cin >> year;
        cin.clear();
        cin.ignore(100, '\n');
    }

    string code;
    cout << " Please type credit card security code: ";
    cin >> code;
    cin.clear();
    cin.ignore(100, '\n');

    while(code.size() != 3 || !isDigits(code))
    {
        cout << " Please input a valid expiry date with 3 digits: ";
        cin >> code;
        cin.clear();
        cin.ignore(100, '\n');
    }

    cout << "Successful Payment!" << endl;
}

// Validate credit card number and security code
bool customer::isDigits(string card)
{
    for(char c : card)
    {
        if(!(c >= '0' && c <= '9'))
        {
            return false;
        }
    }
    return true;
}

#endif //OOSD_CO567_CUSTOMER_H