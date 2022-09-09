#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"

int countneighbors (Grid grid, int x, int y){
    int count = 0;
    int a, b;
    for (a = -1; a < 2; a++) {
        for (b = -1; b < 2; b++) {
            int row = (x + a + ROWS) % ROWS; //considering position of edge cells
            int col = (y + b + COLS) % COLS; //considering position of edge cells
            count += grid[row][col]; //saves the count of live neighbors around a specific cell 
        }
    }
    count -= grid[x][y]; //excluding the cell on which the function is being performed
    return count; //returns the number of live neighbors
}

int anewgeneration (Grid grid, Grid newGrid){
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            int currentstate = grid[i][j]; //saves the current state of 2d array

            int neighbors = countneighbors(grid, i, j); //counts the number of live neighbors around a specified cell

            if (currentstate == 0 && neighbors == 3) {
                newGrid[i][j] = 1; //rule 1 and 4
            } else if (currentstate == 1 && (neighbors < 2 || neighbors > 3)) {
                newGrid[i][j] = 0; //rule 1 and 3
            } else {
                newGrid[i][j] = grid[i][j]; //rule 2
            }
        }
    }
    return 0;
}