/*
 * File: ProblemEleven.cpp
 * --------------------------
 * Finds the greatest product of four adjacent numbers in any direction (up, down, left, right, or diagonally) 
 */

#include <iostream>
#include <string>
#include "console.h"

using namespace std;

const char* FILE_NAME = "grid.txt";
const int gridSize = 20;

int max(int i, int j) {
    return i > j ? i : j;
}

int getLocalMaxProduct(int grid[gridSize][gridSize], int row, int col) {

    int down = row <= 20 - 4 ? 
        grid[row][col] * grid[row + 1][col] * grid[row + 2][col] * grid[row + 3][col] :
        0;
    
    int across = col <= 20 - 4 ?
        grid[row][col] * grid[row][col + 1] * grid[row][col + 2] * grid[row][col + 3] :
        0;
    
    int back = (row <= 20 - 4) && (col <= 20 - 4) ?
        grid[row][col] * grid[row + 1][col + 1] * grid[row + 2][col + 2] * grid[row + 3][col + 3] :
        0;
    
    int forward = (row <= 20 - 4) && (col >= 3) ?
        grid[row][col] * grid[row + 1][col - 1] * grid[row + 2][col - 2] * grid[row + 3][col - 3] :
        0;
    
    return max(down, max(across, max(back, forward)));
}


int main() {

    int grid[gridSize][gridSize];
    
    FILE* infile;
    infile = fopen(FILE_NAME, "r");
    
    int curr;
    
    for (int row = 0; row < gridSize; row++) {
        for (int col = 0; col < gridSize; col++) {
            fscanf(infile, "%d", &curr);
            if (curr == EOF) cout << "this thing messed up" << endl;
            grid[row][col] = curr;
        }
    }
    
    int result = 0;
    for (int row = 0; row < gridSize; row++) {
        for (int col = 0; col < gridSize; col++) {
            int localMax = getLocalMaxProduct(grid, row, col);
            if (localMax > result) result = localMax;
        }
    }
    
    
    cout << "Greatest product of four adjacent numbers in any direction: " << result << endl;
    
    return 0;
}