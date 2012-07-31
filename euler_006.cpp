/*
 * File: ProblemSix.cpp
 * --------------------------
 * Finds the difference between the sum of the squares of LIMIT natural numbers and the 
 * square of the sum.
 */

#include <iostream>
#include <string>
#include "console.h"

using namespace std;

const int LIMIT = 100;

int main() {
    // calculate LIMIT!, then square it.
    int squareOfSum = 0;    
    for (int j = LIMIT; j > 0; j--) {
        squareOfSum += j;
    }
    squareOfSum *= squareOfSum;
    
    int sumOfSquares = 0;
    for (int i = 1; i <= LIMIT; i++) sumOfSquares += i * i;
    
    cout << squareOfSum - sumOfSquares << endl;

    return 0;
}