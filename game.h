#define ROWS 12  //globally defined rows of the grid
#define COLS 12 //globally defined columns of the grid

typedef int Grid[ROWS][COLS]; //declaration for a 2d array to save grid values into

//this function counts the number of live neighbors around a specific cell and returns the count
//x and y are positions of the specific cell whose neighbors are supposed to be counted
int countneighbors (Grid grid, int x, int y);

//this function produces the next state of the grid based on the rules of the game
//it counts the number of live neighbors around a specific cell and makes the cell either
//dead(0) or alive(0) according to the rules
//the state of the cell is then saved to a new 2d array
//returns 0 if everything goes fine
int anewgeneration (Grid grid, Grid newGrid);