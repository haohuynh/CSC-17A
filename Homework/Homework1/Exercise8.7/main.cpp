/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on September 10, 2015, 5:02 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * Binary String Search
 */
int main(int argc, char** argv) {

    //Test data
    const int NUM_NAMES = 20;
    string names[NUM_NAMES] = {"Allen, Jim","Allison, Jeff","Collins, Bill",
    "Griffin, Jim","Harrison, Rose","Holland, Beth","James, Jean","Javens, Renee",
    "Johnson, Jill","Looney, Joe","Pike, Gordon","Pore, Bob","Rose, Geri","Rutherford, Greg",
    "Setzer, Cathy","Smith, Bart","Stamey, Marty","Taylor, Terri","Weaver, Jim","Wolfe, Bill"};

    /*The name needs searching*/
    string keyName;

    /*Set first index to 0.*/
    int leftLimit = 0;

    /*Set last index to the last subscript in the array.*/
    int rightLimit = NUM_NAMES - 1;

    /*Position of the name needs to be compared*/
    int middleIndex;

    cout << "Please enter the name you want to find: ";
    getline(cin,keyName);

    do {
        //Set middle to the subscript halfway between names[first] and names[last].
        middleIndex = (leftLimit + rightLimit) / 2;

        if (keyName > names[middleIndex]) {
            //Set first to middle + 1.
            leftLimit = middleIndex + 1;
        } else {//If names[middle] is greater than or equal to the desired value Set last to middle − 1.
            rightLimit = middleIndex - 1;
        }

    } while ((keyName != names[middleIndex]) && (leftLimit <= rightLimit));

    //Check if the key name was found or not
    if (keyName == names[middleIndex]) {
        cout << "The name was found at: " << middleIndex;
    } else {
        cout << "The name was not found!";
    }

    return 0;
}

