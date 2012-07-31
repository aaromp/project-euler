/*
 * File: euler_017.cpp
 * --------------------------
 * Counts the number of letters used in the numbers from one to LIMIT.
 */

#include <iostream>
#include <string>
#include "console.h"
#include <cctype>

using namespace std;

const int LIMIT = 1000;


// should have used a string array instead of a switch..  it takes up way too much space..
string convertToWord(int number) {
    switch (number) {
        case 1:
            return "one";
            
        case 2:
            return "two";
            
        case 3:
            return "three";
            
        case 4:
            return "four";
            
        case 5:
            return "five";
        
        case 6:
            return "six";
            
        case 7:
            return "seven";
            
        case 8:
            return "eight";
            
        case 9:
            return "nine";
            
        case 10:
            return "ten";
            
        case 11:
            return "eleven";
            
        case 12:
            return "twelve";
            
        case 13:
            return "thirteen";
            
        case 14:
            return "fourteen";
            
        case 15:
            return "fifteen";
            
        case 16:
            return "sixteen";
            
        case 17:
            return "seventeen";
            
        case 18:
            return "eighteen";
            
        case 19:
            return "nineteen";
        
        case 20:
            return "twenty";
            
        case 30:
            return "thirty";
            
        case 40:
            return "fourty";
            
        case 50:
            return "fifty";
            
        case 60:
            return "sixty";
            
        case 70:
            return "seventy";
            
        case 80:
            return "eighty";
            
        case 90:
            return "ninty";
            
        case 100:
            return "hundred";
            
        case 1000:
            return "thousand";
            
        default:
            return "";
    }
        
    return "";
}


// this function is super hacky but I just wanted to get it done.
string intToWords(int number) {
    if (number > 0 && number < 20) return convertToWord(number);
    if (number < 100) {
        if (number % 10 == 0) return convertToWord(number);
        else {
            return convertToWord((number / 10) * 10) + "-" + convertToWord(number % 10);
        }
    } else if (number < 1000) {
        return number % 100 == 0 ?
            convertToWord(number / 100) + " " + convertToWord(100) :
            convertToWord(number / 100) + " " + convertToWord(100) + " and " + intToWords(number % 100);
    }
        
    return convertToWord(number / 1000) + " " + convertToWord(1000);
}


int countLetters(string str) {
    int result = 0;
    
    for (int i = 0; i < str.length(); i++) {
        if (isalpha(str[i])) result++;
    }
    
    return result;
}

int main() {
    int result = 0;
    
    for (int i = 1; i <= LIMIT; i++) {
        result += countLetters(intToWords(i));
    }
    
    cout << result << endl;
    return 0;
}