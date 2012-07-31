/*
 * File: ProblemTen.cpp
 * --------------------------
 * Finds the sum of all the primes below LIMIT.
 */

#include <iostream>
#include <string>
#include "console.h"
#include "vector.h"

using namespace std;

const int LIMIT = 2000000;

void sievePrimes(int number, Vector<bool> &soFar) {
    if (soFar[number] == false) return;
    
    for (int i = number + number; i < LIMIT; i += number) {
        soFar[i] = false;
    }
}

int main() {
    unsigned long long int result = 0;
		// would've liked to have use a plain array but LIMIT is too huge
    Vector<bool> primes;
    for (int i = 0; i < LIMIT; i++) primes += true;
    
    for (int j = 2; j < LIMIT; j++) {
        sievePrimes(j, primes);
    }
    
    for (int k = 2; k < LIMIT ; k++) {
        if (primes[k]) result += k;
    }

    cout << result << endl;
    
    return 0;
}