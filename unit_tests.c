#include "unity.h"
#include "game.h"
#include "file.h"
#include "view.h"

FILE *fp; //initialized a file pointer
Grid grid; //initialized the originial grid
Grid newGrid; //initiaized a new grid

//this function tests if the new generation function works fine
//it will pass
//if the new generation function is commented, this test will fail and display the appropriate error message
void test_anewgeneration(){
    TEST_ASSERT_EQUAL_INT_MESSAGE(0, anewgeneration(grid, newGrid), "Unable to create a new generation of the gird!");
}

//this function tests if the twod array from file function works fine
//it will pass
//if the file pointer is NULL or if something goes wrong in reading from the file, it will fail with an appropriate error message
void test_twod_array_from_file(){
    if(twod_array_from_file(grid) == 1){
        TEST_ASSERT_NOT_NULL_MESSAGE(fp, "twod_array_from_file returned a null file pointer");
    }
    else{
        TEST_ASSERT_MESSAGE(twod_array_from_file(grid) == 0, "Initial state of the grid is not read from a file!");
    }
}

//this function tests if the count neighbors function works fine
//this function reads from the specified file and tests the function on the values in that file
//if any values are changed in the intial state file, this test will fail
//if nothing's changed, it will pass
void test_countneighbors(){
    fp = fopen("../initialStateFile.txt", "r");
    int i, j;
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLS; j++){
            fscanf(fp,"%d",&grid[i][j]);
        }
    }
    TEST_ASSERT_EQUAL_INT(0, countneighbors(grid, 4, 2));
    TEST_ASSERT_EQUAL_INT(1, countneighbors(grid, 10, 2));
    TEST_ASSERT_EQUAL_INT(3, countneighbors(grid, 5, 6));
    TEST_ASSERT_EQUAL_INT(7, countneighbors(grid, 2, 6));
    TEST_ASSERT_EQUAL_INT(5, countneighbors(grid, 8, 6));
}

//this function tests the drawGrid function
//this test will pass
//the tester will be able to visualize if the grid is not drawn to SDL anyway
void test_drawGrid(){
    TEST_ASSERT_EQUAL_INT_MESSAGE(0, drawGrid(grid), "Grid is not drawn to SDL!");
}

//this function tests the create window function
//this test will pass
//the tester can always visualize if the SDL window is not created anyway
void test_createWindow(){
    TEST_ASSERT_EQUAL_INT_MESSAGE(0, createWindow(), "SDL window is not initialized and renderer is not created!");
}

void setUp(){
    //empty
}

void tearDown(){
    //empty
}

//the main function runs all the tests
int main(){
    UNITY_BEGIN();
    RUN_TEST(test_anewgeneration);
    RUN_TEST(test_twod_array_from_file);
    RUN_TEST(test_countneighbors);
    RUN_TEST(test_drawGrid);
    RUN_TEST(test_createWindow);

    return UNITY_END();
}