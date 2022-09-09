#define ROWS 12 //globally defined rows of the grid
#define COLS 12 //globally defined columns of the grid

typedef int Grid[ROWS][COLS]; //declaration for a 2d array to save grid values into

//this function returns 0 if the window and renderer are initialized
//returns 1 and exits the function if SDL is not initialized
//returns 1 and exits the function if SDL window and renderer aren't created
int createWindow();

//this function draws the background color of SDL and grid lines color
void drawGridBackground();

//this function draws color to the cell that is alive(1)
//returns 0 if the grid is drawn to SDL successfully
int drawGrid(Grid grid);

//this function closes the SDL window
void closeWindow();