/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on September 10, 2015, 2:33 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

/**
 * Rain or Shine
 * The weather conditions during the past year’s three-month summer season, 
 * and each day has been designated as either rainy (‘R’), cloudy (‘C’), or sunny (‘S’). 
 * This program stores that information in a 3 × 30 array of characters, 
 * where the row indicates the month (0 = June, 1 = July, 2 = August) 
 * and the column indicates the day of the month. Note that data are not
 * being collected for the 31st of any month. The program begins by reading the
 * weather data in from a file. Then it creates a report that displays, for each
 * month and for the whole three-month period, how many days were rainy, how many
 * were cloudy, and how many were sunny. It should also report which of the three
 * months had the largest number of rainy days. Data for the program can be found in
 * the RainOrShine.txt file.
 */

/*The maximum number of months in the report*/
const int MAX_MONTH_REPORT = 3;

/*The maximum number of days of each month in the report*/
const int MAX_DAY_REPORT = 30;

/*Enumerates illustrate the month indexes*/
enum Month {
    JUNE, JULY, AUGUST
};

/*Enumerates illustrate the weather condition indexes*/
enum Condition {
    RAIN, CLOUD, SUN
};

/*This function displays the name of a month by its index*/
void printMonth(int month) {

    switch (month) {
        case JUNE:
        {
            cout << "**June**" << endl;
            break;
        }
        case JULY:
        {
            cout << "**July**" << endl;
            break;
        }
        case AUGUST:
        {
            cout << "**August**" << endl;
            break;
        }
        default:
        {
            cerr << "This part of the report is invalid!!!";
        }
    }
}

/* 
 * Processing reports by each month and by three months.
 * Finding the month that has the largest number of rainy days
 */
void processReports(char weaConds[][MAX_DAY_REPORT]) {

    /*The weather condition for a rainy day*/
    const char RAINY = 'R';

    /*The weather condition for a cloudy day*/
    const char CLOUDY = 'C';

    /*The weather condition for a sunny day*/
    const char SUNNY = 'S';

    /*Storing the number of rainy, cloudy, and sunny days for monthly report 
     Indexes 0: Rainy
     *       1: Cloudy
     *       2: Sunny  
     */
    int weaDays[] = {0, 0, 0};

    /*Storing the number of rainy,cloudy,and sunny days for three-month report */
    int weaMDays[] = {0, 0, 0};

    /*Storing the maximum number of rainy days in one of three summer month*/
    int maxRDays = 0;

    /*Storing the month that had the largest number of rainy days*/
    int maxRMon = 0;

    /*The month and day indexes*/
    int i, j;

    /*Process report by each month*/
    for (i = 0; i < MAX_MONTH_REPORT; i++) {

        //Reset data for the next month report
        memset(weaDays,0,sizeof(weaDays));

        printMonth(i);
        for (j = 0; j < MAX_DAY_REPORT; j++) {

            switch (weaConds[i][j]) {
                case RAINY:
                {
                    weaDays[RAIN]++;
                    break;
                }
                case CLOUDY:
                {
                    weaDays[CLOUD]++;
                    break;
                }
                case SUNNY:
                {
                    weaDays[SUN]++;
                    break;
                }
                default:
                {
                    cerr << "This part of report is invalid!!!";
                }
            }

        }

        //Finding the month that has the largest number of rainy days
        if (maxRDays < weaDays[RAIN]) {
            maxRDays = weaDays[RAIN];
            maxRMon = i;
        }

        //Updating weather conditions for three-month report
        weaMDays[RAIN] += weaDays[RAIN];
        weaMDays[CLOUD] += weaDays[CLOUD];
        weaMDays[SUN] += weaDays[SUN];

        //Report of a month
        cout << weaDays[RAIN] << " days were rainy" << endl;
        cout << weaDays[CLOUD] << " days were cloudy" << endl;
        cout << weaDays[SUN] << " days were sunny\n\n";
    }

    //Report of three-month
    cout << "\n*-*-*-*The whole three summer month report*-*-*-*\n";
    cout << weaMDays[RAIN] << " days were rainy" << endl;
    cout << weaMDays[CLOUD] << " days were cloudy" << endl;
    cout << weaMDays[SUN] << " days were sunny" << endl;

    cout << "\nThe month has the largest number of rainy days is ";
    printMonth(maxRMon);
}

int main(int argc, char** argv) {


    /*The weather condition data file*/
    const string WEATHER_FILE_NAME = "RainOrShine.txt";

    /* The weather conditions array*/
    char weaConds[MAX_MONTH_REPORT][MAX_DAY_REPORT];

    /*Try to access the weather condition data file*/
    ifstream weaFile;
    weaFile.exceptions(ifstream::eofbit | ifstream::failbit | ifstream::badbit);

    //Process file exceptions if possible
    try {

        weaFile.open(WEATHER_FILE_NAME.c_str());

        //Reading weather conditions of three summer months
        for (int i = 0; i < MAX_MONTH_REPORT; i++) {
            for (int j = 0; j < MAX_DAY_REPORT; j++) {
                weaFile >> weaConds[i][j];
            }
        }

    } catch (ifstream::failure e) {
        //The file was corrupted or contains invalid data
        cerr << "The weather condition data file was corrupted. Please check for that !\n";
    }

    //Close the file if it has no IO Exception 
    if (weaFile.is_open()) {
        weaFile.close();
    }

    //Display reports 
    cout << "*************Rain or Shine report************* \n\n";
    processReports(weaConds);

    return 0;
}

