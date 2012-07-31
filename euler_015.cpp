/*
 * File: euler_15.cpp
 * --------------------------
 * Finds the number of routes through a GRID_SIZE x GRID_SIZE grid.
 */

#include <iostream>
#include <string>
#include "console.h"
#include "vector.h"

using namespace std;

const int GRID_SIZE = 20;

struct coord {
    int x;  
    int y;
    unsigned long long int count;
};

unsigned long long int countRoutes(int x, int y, Vector<coord> &coords) {
    // base case: we've reached the origin
    if (x == 0 && y == 0) return 1;
    
    // base case: it's been memoized
    foreach (coord coord in coords) 
        if (coord.x == x && coord.y == y) return coord.count;
    
    // memoize
    coord curr;
    curr.x = x;
    curr.y = y;
    
    // recursive case: reached the x bound
    if (x == 0) curr.count = countRoutes(x, y - 1, coords);
    
    // recursive case: reached the y bound
    else if (y == 0) curr.count =  countRoutes(x - 1, y, coords);
    
    // recursive case: try all combinations
    else curr.count = countRoutes(x, y - 1, coords) + countRoutes(x - 1, y, coords);
    
    coords += curr;
    
    return curr.count;
}

int main() {  
    
    Vector<coord> coords;
    
    cout << countRoutes(GRID_SIZE, GRID_SIZE, coords) << endl;
    
    return 0;
}