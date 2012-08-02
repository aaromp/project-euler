/*
 * File: euler_019.cpp
 * --------------------------
 * Determines how many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)
 */

#include <iostream>
#include <string>
#include "console.h"

using namespace std;

const int START_YEAR = 1900;
const int END_YEAR = 2000;
const int NUM_MONTHS = 12;
const int NUM_DAYS_IN_A_WEEK = 7;

bool isLeapYear(int year) {
    // a leap year can't be a century unless it's divisible by 400
    if (year % 100 == 0 && year % 400 != 0) return false;
    
    // a leap year must not be divisble by a number other than 4
    if (year % 4 != 0) return false;
    
    // it the above don't apply, it's a leap year
    return true;
}


int getNumDays(int month, int year) {
    switch (month) {
        case 2: 
						return isLeapYear(year) ? 29 : 28;
            
        case 4: case 6: case 9: case 11:
            return 30;
            
        default:
            return 31;
    }
}


int main() {    
    int result = 0;
    
    int daysElapsed = 0;
    for (int year = START_YEAR; year <= END_YEAR; year++)
        for (int month = 1; month <= NUM_MONTHS; month++)
            for (int day = 1; day <= getNumDays(month, year); day++) {
                daysElapsed++;
                if (year > START_YEAR && day == 1 && daysElapsed % NUM_DAYS_IN_A_WEEK == 0) result++;
            }
    
    cout << result << endl;

    return 0;
}