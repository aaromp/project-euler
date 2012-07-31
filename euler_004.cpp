/*
 * File: ProblemFour.cpp
 * --------------------------
 * Finds the largest palindrome made from the product of two numbers.
 */

#include <iostream>
#include <string>
#include <sstream>
#include "console.h"
#include "math.h"

using namespace std;

const int NUM_DIGITS = 5;

bool isPalindrome(string str) {
    
    // base case: one or fewer digits
    if (str.length() <= 1) return true;
    
    // recursive case: if the ends match, check the middle:
    if (str[0] == str[str.length() - 1]) return isPalindrome(str.substr(1, str.length() - 2));
    
    return false;
}

string intToString(int number) {
    ostringstream out;
    out << number;
    return out.str();
}

int getMaxPalindrome(int max) {
    int result = 0;
    int current;
    for (int i = max; i > 0; i--) {
        for (int j = max; j > 0; j--) {
            current = i * j;
            if (current > result && isPalindrome(intToString(current))) result = current;
        }
    }

    return result;
}

int main() {
    
    cout << getMaxPalindrome(pow(10, NUM_DIGITS)) << endl;

    return 0;
}