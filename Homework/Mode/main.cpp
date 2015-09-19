/* 
 * File:   main.cpp
 * Author: HaoHuynh
 *
 * Created on September 19, 2015, 2:52 PM
 */

#include <map>  // Map Library
#include <vector> // Vector Library
#include <algorithm> //Algorithm Library
#include <iostream> // Input/Output Stream Library

using namespace std;

/*The helper is used for comparing frequencies of a vector of pairs<value, frequency>
 *The frequencies are sorted in a decreasing order
 */
bool cmpValue(const pair<int, int> &v1, const pair<int, int> &v2) {
    return v1.second > v2.second;
}

/**
 * 
 * @param a : an array of integer values 
 * @param n : the size of a
 * @param m : the size of the return array
 * @return the array containing all the mode values of a
 */
int* findMode(int* a, int n, int& m) {

    // The input array a should have more than a element
    if (n <= 1) {
        return NULL;
    }

    /*This map containing pairs of values (in the array a) and their frequencies*/
    map<int, int> afreq;

    /*An iterator of the afreq map */
    map<int, int>::iterator afreqi;

    /*This vector of pairs is parallel to the map afreq*/
    vector< pair<int, int> > afreqv;

    /*An iterator of the afreqv vector */
    vector< pair<int, int> > ::iterator afreqvi;

    //Finding the frequency of each value in the array a
    for (int i = 0; i < n; i++) {

        afreqi = afreq.find(a[i]); // Check if a value has already existed in the map

        // Increasing the frequency of an existing value
        if (afreqi != afreq.end()) {
            afreqi->second++;

        } else {// Start the frequency of a new value with 1
            afreq.insert(pair<int, int> (a[i], 1));
        }

    }

    // Binding all map entries into a vector of pairs (values, frequencies))
    copy(afreq.begin(), afreq.end(), back_inserter(afreqv));

    /*
     * Take advantage of the build-in sort algorithm for vectors
     * Sort the vector of pairs<value, frequency> by a decreasing order of frequencies
     */
    sort(afreqv.begin(), afreqv.end(), cmpValue);

    // If the highest frequency of a value in the array a is equal to 1, then that array has no mode
    if (afreqv.begin()->second == 1) {
        return NULL;
    }

    //This vector contains all the values having the same highest frequency in the array a
    vector<int> result;

    //Finding values that have the same highest frequency
    for (afreqvi = afreqv.begin(); afreqvi != afreqv.end(); afreqvi++) {
        if (afreqvi->second == afreqv.begin()->second) {
            result.push_back(afreqvi->first);
        } else {
            break;
        }
    }

    m = result.size();

    //Returning the array in form of int*
    return &result[0];
}

/*
 * This program is used for finding the mode of a set of data
 */
int main(int argc, char** argv) {

    //Test data
    int a[] = {5, 6, 1, 2, 3, 1, 6, 2, 0, 6, 5, 5, 1, 2};

    // The mode array 
    int* result;

    // The size of a
    int n = 14;

    // The size of result
    int m;
    
    result = findMode(a, n, m);

    if (result == NULL) {
        cout << "There is no mode of the input array !";
    } else {
        cout << "The mode array: " << endl;

        for (int j = 0; j < m; j++) {
            cout << result[j] << " ";
        }
    }

    return 0;
}

