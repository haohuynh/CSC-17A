/* 
 * File:   main.cpp
 * Author: HaoHuynh
 *
 * Created on September 9, 2015, 8:55 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/**
 * Celsius to Fahrenheit
 * This program converts Celsius temperatures to Fahrenheit temperatures. The
 * formula is F = ((9*C)/5) + 32
 * F is the Fahrenheit temperature, and C is the Celsius temperature.
 **/
int main(int argc, char** argv) {

    //The Celsius temperature
    double celsius;
    
    //The Fahrenheit temperature
    double fahrenheit;
    
    cout << "Please input the Celsius temperature: ";
    cin >> celsius;
    
    fahrenheit = ( (celsius * 9) / 5) + 32;
    
    cout << "The equivalent Fahrenheit temperature is : " << fahrenheit;
    
    return 0;
}

