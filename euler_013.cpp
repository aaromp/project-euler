/*
 * File: euler_013.cpp
 * --------------------------
 * Work out the first ten digits of the sum of the numbers contained in FILE_NAME
 */

#include <iostream>
#include <string>
#include "console.h"
#include <fstream>
#include "MegaInt.hh"

using namespace std;

const char* FILE_NAME = "euler_013_data.txt";
const int NUM_DIGITS = 10;


int main() {
    MegaInt result;
    ifstream infile;
    infile.open(FILE_NAME);
    
    while (true) {
        string number;
        getline(infile, number);
        if (infile.fail()) break;
        result += number;
    }
    infile.close();
    
    cout << result.toString().substr(0, NUM_DIGITS) << endl;
    
    return 0;
}