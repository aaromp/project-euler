/*
 * File: euler_002.cpp
 * --------------------------
 * Finds the sum of the even-valued Fibonacci numbers less than MAX.
 */

#include <iostream>
#include <string>
#include "console.h"
#include "FibonacciIterator.hh"

using namespace std;

const int LIMIT = 4000000;

int main() {
    int result = 0;
    
    for (FibonacciIterator<int> itr; itr.current() < LIMIT; itr++)
        if (itr.current() %2 == 0) result += itr.current();
    
    cout << result << endl;

    return 0;
}