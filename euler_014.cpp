/*
 * File: ProblemFourteen.cpp
 * --------------------------
 * Which starting number, under one LIMIT, produces the longest chain?
 */

#include <iostream>
#include <string>
#include "console.h"

using namespace std;

const int THRESHOLD = 1000000;

unsigned long long int hailChain(unsigned long long n) {
    int count = 1;
    while (n > 1) {
        n = n % 2 == 0 ? 
            n / 2 : 3 * n + 1;
        
        count++;
    }
    
    return count;
}

int main() {
    int result = 0;
    
    int longestChain = 0;
    for (int n = 1; n < THRESHOLD; n++) {
        int chain = hailChain(n);
        if (chain > longestChain) {
            longestChain = chain;
            result = n;
        }
    }
    
    cout << result << endl;
    
    return 0;
}