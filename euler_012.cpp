/*
 * File: euler_012.cpp
 * --------------------------
 * Finds the value of the first triangle number to have over THRESHOLD divisors.
 */

#include <iostream>
#include <string>
#include "console.h"
#include "vector.h"

using namespace std;

const int LIMIT = 1000;
const int THRESHOLD = 500;

void sievePrimes(int number, Vector<bool> &soFar) {
    if (soFar[number] == false) return;
    
    for (int i = number + number; i < LIMIT; i += number) {
        soFar[i] = false;
    }
}

int main() {
    
    int n = 1;
    int maxFactors = 0;
    
    // would've liked to have use a plain array but LIMIT is too huge
    Vector<bool> primeSieve;
    for (int i = 0; i < LIMIT; i++) primeSieve += true;
    
    for (int j = 2; j < LIMIT; j++) sievePrimes(j, primeSieve);
    
    Vector<int> primes;
    for (int k = 2; k < LIMIT; k++) if (primeSieve[k]) primes += k;
    
    
    unsigned long int triangleNumber = 0;
    while (maxFactors <= THRESHOLD) {
        
        triangleNumber += n;
        
        int numFactors = 1;
        
        unsigned long long int curr = triangleNumber;
        for (int i = 0; i < primes.size(); i++) {
            
            if (curr == 1) break;
            
            else if (curr % primes[i] == 0) {
                int exponent = 0;
                
                while (curr % primes[i] == 0) {
                    curr /= primes[i];
                    exponent++;
                }
                
                exponent++;
                numFactors *= exponent;
            }
        }


        if (numFactors > maxFactors) maxFactors = numFactors;
            
        n++;
    }    
    
    cout << triangleNumber << endl;
    
    return 0;
}