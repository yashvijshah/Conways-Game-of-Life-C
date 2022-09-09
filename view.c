#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include "view.h"

const int size = 20; //grid cell size
const int width = 29; //grid cell width
const int height = 29; //grid cell height
static int ALIVE = 1;
static int resolution = 20;
SDL_Window *window; //pointer to initalize the SDL window
SDL_Renderer *renderer; //pointer to initialize the SDL renderer

int createWindow(){
    // + 1 so that the last grid lines fit in the screen.
    //this code is taken from GitHub which is referenced in the reflection pdf
    int wwidth = (width * size) + 1; //SDL window width
    int wheight = (height * size) + 1; //SDL window height

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Initialize SDL: %s",
                      SDL_GetError());
        return EXIT_FAILURE;
        return 1;
    }
    if (SDL_CreateWindowAndRenderer(wwidth, wheight, 0, &window, &renderer) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                    "Create window and renderer: %s", SDL_GetError());
        return EXIT_FAILURE;
        return 1;
    }
    SDL_SetWindowTitle(window, "Conway's Game of Life");
    return 0;
}

void drawGridBackground(){
    // + 1 so that the last grid lines fit in the screen.
    //this code is taken from GitHub which is referenced in the reflection pdf
    int wwidth = (width * size) + 1; //SDL window width
    int wheight = (height * size) + 1; //SDL window height
    SDL_Color Gridbackground = {22, 22, 22, 255}; // Black
    SDL_Color Gridlines = {44, 44, 44, 255}; //Dark grey
    SDL_SetRenderDrawColor(renderer, Gridbackground.r, Gridbackground.g,
                            Gridbackground.b, Gridbackground.a);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, Gridlines.r, Gridlines.g,
                            Gridlines.b, Gridlines.a);
    int x, y;
    for (x = 0; x < wheight; x += size) {
        SDL_RenderDrawLine(renderer, x, 0, x, wheight);
    }

    for (y = 0; y < wwidth; y += size) {
        SDL_RenderDrawLine(renderer, 0, y, wwidth, y);
    }
}

int drawGrid(Grid grid){
    int i, j;
    SDL_Color Gridcell = {255, 255, 255, 0}; // White
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLS; j++){
            // draw color to the cells that are alive
            SDL_Rect gridCellFill = {
                .x = i * resolution,
                .y = j * resolution,
                .w = resolution - 1,
                .h = resolution - 1,
            };
            if(grid[i][j] == ALIVE){
                SDL_SetRenderDrawColor(renderer, Gridcell.r,
                                        Gridcell.g, Gridcell.b,
                                        Gridcell.a);
                SDL_RenderFillRect(renderer, &gridCellFill);
            }
        }
    }
    SDL_RenderPresent(renderer); //save the new changes to SDL renderer
    return 0;
}

void closeWindow(){
    SDL_DestroyRenderer(renderer); //destroys the SDL renderer
    SDL_DestroyWindow(window); //destroys the SDL window
    SDL_Quit();//closes the SDL window and quits the program
}