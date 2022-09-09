#define ROWS 12 //globally defined rows of the grid
#define COLS 12 //globally defined columns of the grid

typedef int Grid[ROWS][COLS]; //declaration for a 2d array to save grid values into

//opens an initial text file where the user has entered values(0 and 1)
//reads those values from the file and loads them into the 2d grid
//returns 0 if the values are loaded successfully into the grid
//returns 1 and terminates the proragm if the file pointer to open the initial text file is NULL
int twod_array_from_file(Grid grid);


//opens a final text file to write the final values(0 and 1) stored in the grid to the file
//terminates the program if the file pointer to open the file in write mode is NULL
//the user would be able to see the final text file with a 2d grid, saved in the directory
void displayNextState(Grid grid);