#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"

FILE *fp; //initialized a file pointer
static int ALIVE = 1; 

int twod_array_from_file(Grid grid){
    int i,j;
    fp = fopen("../initialStateFile.txt","rb");
    if(fp == NULL){
        return 1;
        exit(1); //terminates the program
    }
    else{
        for(i=0; i<ROWS; i++) {
            for(j=0; j<COLS; j++) {
                fscanf(fp,"%d",&grid[i][j]); //stores the input grid values from the file in the 2d array
            }
        }
        return 0;
    }
}

void displayNextState(Grid grid){
    int i,j;
    fp = fopen("../finalStateFile.txt","w");
    if(fp == NULL){
        exit(1); //terminates the program
    }
    else{
        for(i = 0; i < ROWS; i++){
            for(j = 0; j < COLS; j++){
                if (grid[i][j] == ALIVE) {
                    fprintf(fp, "1 ");
                } else {
                    fprintf(fp, "0 ");
                }
            }
            fprintf(fp, "\n");
        }
    }
}