/*
 * File: euler_018.cpp
 * --------------------------
 * Finds the maximum total from row 0 to row LIMIT of the triangle in FILE_NAME.
 */

#include <iostream>
#include <string>
#include "console.h"

using namespace std;

const char* FILE_NAME = "euler_018_data.txt";
const int LIMIT = 15;

// doesn't have any error checking...
void readTriangleFile(int triangle[LIMIT][LIMIT]) {
    FILE* file = fopen(FILE_NAME, "r");
    
    for (int row = 0; row < LIMIT; row++)
        for (int col = 0; col <= row; col++)
            fscanf(file, "%d", &triangle[row][col]);
    
    fclose(file);
}

int max(int i, int j) {
    return i > j ? i : j;
}

int recFindMaxTotal(int triangle[LIMIT][LIMIT], int row, int col) {
    
    // base case:  out of bounds so we're done
    if (row == LIMIT || col == LIMIT) return 0;
    
    // recursive case: take the larger or the two branches.
    return max(recFindMaxTotal(triangle, row + 1, col) + triangle[row][col],
               recFindMaxTotal(triangle, row + 1, col + 1) + triangle[row][col]);
}


int main() {
    int triangle[LIMIT][LIMIT];
    readTriangleFile(triangle);
    
    cout << recFindMaxTotal(triangle, 0, 0) << endl;
    
    return 0;
}