#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <SDL2/SDL.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define CELL_SIZE 80
#define PAWN_RADIUS 35
#define POTENTIAL_PAWN_RADIUS 10


typedef enum {
    NOIR = 0,
    BLANC = 1,
    POTENTIEL = 2,
    VIDE = 3
} CELL;


void drawPAWN(SDL_Renderer *renderer, int x, int y, int radius, SDL_Color color);
#endif