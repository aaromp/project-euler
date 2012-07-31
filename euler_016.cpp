/*
 * File: euler_18.cpp
 * --------------------------
 * Finds the sum of the digits of the number 2^LIMIT
 */

#include <iostream>
#include <string>
#include "console.h"
#include "vector.h"

using namespace std;

const int LIMIT = 1000;

void recSquareVector(Vector<int> &number, int index, int remainder) {
    // recursive case: double at index and carry any remainder
    if (index < number.size()) {    
        
        int doubled = number[index] * 2 + remainder;    
        remainder = doubled < 10 ? 0 : doubled / 10;
        number[index] = doubled % 10;
        recSquareVector(number, index + 1, remainder);
    } 
    
    // base case: we're reached the end of the array append the remainder!
    else if (remainder > 0) {
        number += remainder;
    }
}

// note: the array will be backwards!  32 will be 23!
void square(Vector<int> &number) {
    recSquareVector(number, 0, 0);
}

int main() {    
    int result = 0;
    
    Vector<int> number;
    number += 1;
    
    // create a vector of 2^LIMIT with its digits reversed
    for (int i = 0; i < LIMIT; i++) {
        square(number);
    }

    // add up the digits
    for (int j = 0; j < number.size(); j++) {
        result += number[j];
    }
    
    cout << result << endl;
    
    return 0;
}