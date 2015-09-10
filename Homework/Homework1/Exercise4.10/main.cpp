/* 
 * File:   main.cpp
 * Author: HaoHuynh
 *
 * Created on September 9, 2015, 9:40 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * Days in a Month
 * This program asks the user to enter the month (letting the user enter an integer
 * in the range of 1 through 12) and the year. The program should then display the
 * number of days in that month. The following criteria is used to identify leap years:
 * 1. Determine whether the year is divisible by 100. If it is, then it is a leap year if and
 *    only if it is divisible by 400.
 * 2. If the year is not divisible by 100, then it is a leap year if and if only it is divisible by
 *    4. 
 */
int main(int argc, char** argv) {

    /*The month in the range of 1 through 12*/
    int month;

    /*The leap or normal year */
    int year;


    cout << "Enter a month(1-12): ";
    cin >> month;

    if ((month < 1) || (month > 12)) {
        cout << "Invalid input !!! January will be used" << endl;
        month = 1;
    }

    cout << "Enter a year: ";
    cin >> year;

    if (year < 0) {
        cout << "Invalid input !!! Year 1900 will be used" << endl;
        year = 1900;
    }

    switch (month) {

        case 1:case 3:case 5:case 7:case 8:case 10:case 12:
        {
            cout << "31 ";
            break;
        }

        case 4:case 6:case 9:case 11:
        {
            cout << "30 ";
            break;
        }

        default:
        {
            if (((year % 400) == 0)
                    || (((year % 4) == 0) && ((year % 100) != 0))) { //Leap Year. 
                cout << "29 ";
            } else { // Regular Year.
                cout << "28 ";
            }
        }
    }

    cout << "days";

    return 0;
}

