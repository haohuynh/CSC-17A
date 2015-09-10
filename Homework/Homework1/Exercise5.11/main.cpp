/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on September 10, 2015, 9:47 AM
 */

#include <cstdlib>
#include <iostream>
#include <limits.h>

using namespace std;

/*This function clears the console buffer in case of invalid input types */
void flushConsole() {
    cin.clear();
    cin.ignore(INT_MAX, '\n');
}

/**
 * Population
 * This program will predict the size of a population of organisms. The program
 * should ask the user for the starting number of organisms, their average daily population
 * increase (as a percentage), and the number of days they will multiply. A loop
 * should display the size of the population for each day.
 * Input Validation: Do not accept a number less than 2 for the starting size of the population.
 * Do not accept a negative number for average daily population increase. Do not
 * accept a number less than 1 for the number of days they will multiply.
 */
int main(int argc, char** argv) {

    /*The minimum of the starting size of the population.*/
    const double MIN_START_SIZE = 2.0;

    /*The minimum of the number of days organisms will multiply.*/
    const int MIN_MUL_DAY = 1;

    /*100% population increase*/
    const int HUNDRED_PERCENT = 100;

    /*The starting size of the population*/
    double popSize;

    /* The average daily population increase (as a percentage)*/
    double incPer;

    /*The number of days organisms will multiply*/
    int days;

    cout << "Please enter the starting number of organisms: ";
    if (!(cin >> popSize) || (popSize < MIN_START_SIZE)) {
        cout << "Invalid input !!! The population size is assigned to " << MIN_START_SIZE << endl;
        popSize = MIN_START_SIZE;
        flushConsole();
    }

    cout << "Please enter average daily population increase (as a percentage): ";
    if (!(cin >> incPer) || (incPer < 0)) {
        cout << "Invalid input !!! The organisms will not be multiplied" << endl;
        incPer = 0;
        flushConsole();
    }
    incPer /= HUNDRED_PERCENT;

    cout << "Please enter the whole number of days organisms will multiply: ";
    if (!(cin >> days) || (days < MIN_MUL_DAY)) {
        cout << "Invalid input !!! The number of days is considered as " << MIN_MUL_DAY << endl;
        days = MIN_MUL_DAY;
        flushConsole();
    }

    for (int i = 1; i <= days; i++) {
        popSize += (popSize * incPer);
        cout << "The size of the population of organisms after day " << i
                << " is " << popSize << endl;
    }

    return 0;
}

