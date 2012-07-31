/*
 * File: ProblemFive.cpp
 * --------------------------
 * Finds the smallest positive number that is evenly divisible by all of the numbers 
 * from 1 to MAX.
 */

#include <iostream>
#include <string>
#include "console.h"


using namespace std;

const int MAX = 20;

bool isDivisible(unsigned long long int value) {
    for (int i = MAX; i > 0; i--) 
			if (value % i != 0) return false;
			
    return true;
}

int main() {
    unsigned long long int result = 1;
    
		// initialize the result as MAX!
    for (int i = MAX; i > 0; i--) result *= i;
    
		// divide MAX! by each factor until it is no longer divisible
    for (int i = MAX; i > 1; i--) 
			while (isDivisible(result / i)) result /= i;
    
    cout << result << endl;

    return 0;
}