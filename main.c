#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include "file.h"
#include "view.h"
#include "game.h"

SDL_Window *window;
SDL_Renderer *renderer;

int main(){
    createWindow();
    Grid grid;
    twod_array_from_file(grid);
    drawGrid(grid);
    Grid newGrid;
    memcpy(newGrid, grid, sizeof(grid)); // works like strcpy

    Grid *tempGrid = &grid;
    Grid *tempNewGrid = &newGrid;
    SDL_bool quit = SDL_FALSE;
    int endState = 150;
    long runsTill = 0;
    while (!quit && runsTill < endState) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                quit = SDL_TRUE;
                break;
            }
        }
        drawGridBackground();
        anewgeneration(*tempGrid, *tempNewGrid);
        drawGrid(*tempNewGrid);
        Grid *temp = tempGrid;
        tempGrid = tempNewGrid;
        tempNewGrid = temp;
        SDL_RenderPresent(renderer);
        SDL_Delay(150);
        runsTill++;
    }
    SDL_Delay(1200);
    displayNextState(*tempGrid);
    closeWindow();
    return EXIT_SUCCESS;
}