/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on September 10, 2015, 2:03 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

/**
 * Celsius Temperature Table
 * The formula for converting a temperature from Fahrenheit to Celsius is
 * C = (5/9)*(F-32)
 * where F is the Fahrenheit temperature and C is the Celsius temperature. 
 * The table will display the Fahrenheit temperatures 0 through 20
 * and their Celsius equivalents.
 */

/* This function accepts a Fahrenheit temperature as an argument 
 * and returns the Celsius temperature 
 */
double toCelsius(double fahrenheit){
    return (5/9.0)*(fahrenheit - 32);
}


int main(int argc, char** argv) {
    
    /* The maximum value of the Fahrenheit temperature in the table */
    const int MAX_FAH_VAL = 20;
    
    /*Formating displayed table*/
    cout << "Fahrenheit temperatures | Celsius temperatures" << endl;
    cout << setfill('-') << setw(45) << "-" << setfill(' ') << endl;
    
    /*Aligning temperatures in the table*/
    for (double i = 0; i <= MAX_FAH_VAL; i++){
        cout << setw(10) << i << setw(15) << "|" << setw(15) << toCelsius(i) << endl;
    }   
    
    return 0;
}

