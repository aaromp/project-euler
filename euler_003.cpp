/*
 * File: ProblemThree.cpp
 * --------------------------
 * Finds the largest prime factor of input.
 */

#include <iostream>
#include <string>
#include "console.h"
using namespace std;

const unsigned long long INPUT = 600851475143ULL;

int findLargestPrimeFactor(unsigned long long input) {  
    // recursive case: the input has a factor prime factor
    for (unsigned long long i = 2; i < input; i++) {
        if (input % i == 0) {
            unsigned long long remainder = findLargestPrimeFactor(input / i);
            
            // take the max of i and remainder's largest prime factor
            return i > remainder ? i : remainder;
        }
    }
    
    // base case: the largest factor is the input itself
    return input;
}

int main() {
    
    cout << findLargestPrimeFactor(INPUT) << endl;
    
    return 0;
}