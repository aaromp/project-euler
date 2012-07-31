/*
 * File: ProblemNine.cpp
 * --------------------------
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * ProblemNine.cpp finds the product abc.
 */

#include <iostream>
#include <string>
#include "console.h"
#include "math.h"

using namespace std;

const int VALUE = 1000;

bool isPythagorean(int a, int b, int c) {
    return (pow(a, 2) + pow(b, 2) == pow(c, 2));
}

int main() {
    int result = 0;
    
    for (int a = 2; a < VALUE; a++) {
        for (int b = a + 1; b < VALUE - a; b++) {
            int c = VALUE - a - b;
            if (isPythagorean(a, b, c)) {
                result = a * b * c;
                break;
            }
        }
    }

    cout << result << endl;
    
    return 0;
}