/*
 * File: euler_020.cpp
 * --------------------------
 * Finds the sum of the digits in LIMIT!
 */

#include <iostream>
#include <string>
#include "console.h"
#include "MegaInt.hh"

using namespace std;

const int LIMIT = 100;

MegaInt factorial(int n) {
    MegaInt result = 1;
    for (int i = n; i > 0; i--){
        result *= i;
    }
    
    return result;
}

int main() {
    MegaInt value = factorial(LIMIT);
    
    int result = 0;
    
    for (int i = 0; i < value.toString().length(); i++) {
        char digit = value.toString()[i];
        result += atoi(&digit);
    }
    
    cout << result << endl;

    return 0;
}