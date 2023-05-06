#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../Jeu/jeu.h"


#define CELL_SIZE 80
#define PAWN_RADIUS 35
#define POTENTIAL_PAWN_RADIUS 10

#define FONT_PATH "../resources/font/ARIAL.TTF"
#define PATH_UNDO "../resources/img/undo.png"



void drawPAWN(SDL_Renderer *renderer, int x, int y, int radius, SDL_Color color);
/**
 * @brief La fonction drawPAWN sert a dessiner un cercle sur un render donné
 * @param x : centre du cercle en x
 * @param y : centre du cercle en y
 */
void drawCARE(SDL_Renderer *renderer, int x, int y, int LONG, SDL_Color color);
/**
 * @brief La fonction drawCARRE sert a dessiner un carré sur un render donné
 * @param x : position x du coin haut gauche du carré
 * @param y : position y du coin haut gauche du carré
 */

int gameStart(SDL_Window *window,SDL_Renderer *renderer,SDL_Event event ,TTF_Font* font);

void afficherTexte(SDL_Renderer* renderer, const char* texte, int x, int y, TTF_Font* font, SDL_Color color) ;
void chargerEtAfficherImage(SDL_Renderer* renderer, const char* imagePath, int x, int y) ;

#endif