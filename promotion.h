//
// Created by Tomás Pinto on 23/01/2023.
//

#ifndef OOSD_CO567_PROMOTION_H
#define OOSD_CO567_PROMOTION_H

#include <iostream>
#include <iomanip>
#include <string>
#include <map>

using namespace std;

class promotion
{
    public:
        promotion();
        ~promotion();
        map<string,double> getPriceMap(map<int, string> &seats, int &ctype);

    protected:
        map<string, double> mPrice;

    private:
        double getCategory(int &ctype);
        // Get price according to seat
        double getPrice(string &seat);
};

promotion::promotion()
{

}

promotion::~promotion()
{

}

// Return a map with seat and price with discount according to category type
map<string,double> promotion::getPriceMap(map<int, string> &seats, int &ctype)
{
    map<string,double> mPrice;

    double ctg = getCategory(ctype);

    for(const auto &[key, value] : seats)
    {
        string seat = seats[key];
        mPrice[seat] = getPrice(seat) * ctg;
    }

    return mPrice;
}

// gets discount category percentage
 double promotion::getCategory(int &ctype)
 {
    double discount = 0.00;
     switch(ctype)
     {
         case 1 :
             // Full price for adult
             discount = 1.00;
             break;
         case 2 :
            // 10% discount for student
             discount = 0.90;
             break;
         case 3 :
             // 35% discount for student
             discount = 0.65;
             break;
     }
     return discount;
}

// Get the price per row. Default Promotion.
// TODO: Replace this for a reusable promotion as system requirement
double promotion::getPrice(string &seat)
{
    // Get row letter
    char r = seat[0];
    double price = 0.00;

    switch(r)
    {
        case 'A' : price = 70.00;
            break;
        case 'B' : price = 65.00;
            break;
        case 'C' : price = 60.00;
            break;
        case 'D' : price = 55.00;
            break;
        case 'E' : price = 50.00;
            break;
        case 'F' : price = 40.00;
            break;
        case 'G' : price = 25.00;
            break;
        default: price = -1;
    }

    return price;
}

#endif //OOSD_CO567_PROMOTION_H
