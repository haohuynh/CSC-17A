/* 
 * File:   main.cpp
 * Author: HaoHuynh
 *
 * Created on September 9, 2015, 9:04 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

/**
 * Currency
 *  This program will convert U.S. dollar amounts to Japanese yen and to euros.
 *  The exchange rates is the following:
 *  1 Dollar = 98.93 Yen
 *  1 Dollar = 0.74 Euros
 **/
int main(int argc, char** argv) {
    
    /*Storing the conversion factor of yen per dollar*/
    const double YEN_PER_DOLLAR = 98.93;
    
    /*Storing the conversion factor of euros per dollar*/
    const double EUROS_PER_DOLLAR = 0.74;
    
    /*U.S. dollar amounts*/
    double dollar;
    
    cout << "Please input your U.S. dollar amounts: ";
    cin >> dollar;
    
    if (dollar <= 0){
        cout << "Invalid input !!! Your amounts should be a positive number" << endl;
        cout << "Example with 1 dollar" << endl;
        dollar = 1;
    }
        
    //The currency amounts are formated in fixed-point notation, with two decimal places of
    //precision, and be sure the decimal point is always displayed.
    cout << fixed << setprecision(2) << showpoint;
    cout << "The equivalent currency amounts in Yen and Euros are : ";
    
    //Output the conversions
    cout << (YEN_PER_DOLLAR * dollar) << "  and  " << (EUROS_PER_DOLLAR * dollar);
    
    return 0;
}

