/*
 * File: ProblemOne.cpp
 * --------------------------
 * This program finds the sum of all multiples of 3 or 5 below MAX.
 */

#include <iostream>
#include <string>
#include "console.h"
using namespace std;

const int define MAX = 1000;

int main() {
    int result = 0;
    
    for (int i = 0; i < MAX; i++) {
        if (i % 3 == 0 || i % 5 == 0) result += i;
    }
    cout << result << endl;
    
   return 0;
}
