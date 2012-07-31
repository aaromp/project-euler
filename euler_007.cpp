/*
 * File: ProblemSeven.cpp
 * --------------------------
 * Finds the Nth prime number.
 */

#include <iostream>
#include <string>
#include "console.h"

using namespace std;

const int N = 10001;

int isPrime(int input) {  
    // if input has a divisor other than one and itself it's not prime
    for (int i = 2; i < input; i++) 
        if (input % i == 0) return false;
    
    // otherwise it's prime
    return true;
}

int main() {
    int count = 0;
   
    int current = 1;
    while (count < N) {
        current++;
        if (isPrime(current)) count++;
    }
    
    cout << current << endl;

    return 0;
}