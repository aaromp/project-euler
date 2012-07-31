/*
 * File: ProblemEight.cpp
 * --------------------------
 * Finds the greatest product of SIZE consecutive digits in FILENAME containing an integer.
 */

#include <iostream>
#include <string>
#include "console.h"

using namespace std;

const char* FILENAME = "projectFiveData.txt";
const int SIZE = 5;

int main() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) return 1;
    
    int ch;
    int result = 0;
    while (true) {
        int product = 1;
        for (int i = 0; i < SIZE; i++) {
            ch = getc(file);
            product *= ch - '0';
            if (product > result) result = product;
        }
        if (getc(file) == EOF) break;
        fseek(file, -SIZE, SEEK_CUR);
    }

    cout << result << endl;
    
    return 0;
}