#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define CELL_SIZE 80
#define PAWN_RADIUS 35
#define POTENTIAL_PAWN_RADIUS 10

#define FONT_PATH "/home/isen/Algo/Proj_2/Othello/resources/font/ARIAL.TTF"
#define PATH_UNDO "/home/isen/Algo/Proj_2/Othello/resources/img/undo.png"

typedef enum {
    NOIR = 0,
    BLANC = 1,
    POTENTIEL = 2,
    VIDE = 3
} CELL;

typedef struct plate
{
    CELL pion;
    int posX;
    int posY;
    int poids;
}CASE;

void drawPAWN(SDL_Renderer *renderer, int x, int y, int radius, SDL_Color color);
void drawCARE(SDL_Renderer *renderer, int x, int y, int LONG, SDL_Color color);

void initCell(CASE plate [8][8]);
int roundr(int r);
void possibility(CASE plateau[8][8], CELL couleurJoueur, CELL couleurAdv);
void check(CASE plateau[8][8], CASE maCase);

int playerColor (int round);
int advColor (int couleurJoueur);
void initRound(CASE plateau[8][8]);
int checkPlayable(CASE plateau[8][8], int round,int * cptSkipTurn);

int checkWinGame(CASE plateau[8][8], int cptSkipTurn);
int cptCase (CASE plateau[8][8]);

void afficherTexte(SDL_Renderer* renderer, const char* texte, int x, int y, TTF_Font* font, SDL_Color color);
void loadImg(SDL_Renderer* renderer, int x, int y, char* path);

int gameStart(SDL_Window *window,SDL_Renderer *renderer,SDL_Event event ,TTF_Font* font);
#endif