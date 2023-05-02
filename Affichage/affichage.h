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


void initCell(CASE plate [8][8]);
/**
 * @brief Initialise le plateau pour un début de partie
 */

int roundr(int r); // ?

void possibility(CASE plateau[8][8], CELL couleurJoueur, CELL couleurAdv);
/**
 * @brief Détermine les cases qui sont jouables
 */
void check(CASE plateau[8][8], CASE maCase);
/**
 * @brief Retourne les cases entre maCase et les piosn de la meme couleurs
 * @param maCase : case séléctioner
 */

int playerColor (int round);
int advColor (int couleurJoueur);

int checkPlayable(CASE plateau[8][8], int round,int * cptSkipTurn);
/**
 * @brief compte le nombre de case jouables et incrémente le round si il n'y en a pas
 * @param maCase : case séléctioner
 */

int cptCaseColor (CASE plateau[8][8],int Color);

int checkWinGame(CASE plateau[8][8], int cptSkipTurn);
int cptCase (CASE plateau[8][8]);

void afficherTexte(SDL_Renderer* renderer, const char* texte, int x, int y, TTF_Font* font, SDL_Color color);
void loadImg(SDL_Renderer* renderer, int x, int y, char* path);

int gameStart(SDL_Window *window,SDL_Renderer *renderer,SDL_Event event ,TTF_Font* font);

void afficherTexte(SDL_Renderer* renderer, const char* texte, int x, int y, TTF_Font* font, SDL_Color color) ;
void chargerEtAfficherImage(SDL_Renderer* renderer, const char* imagePath, int x, int y) ;


#endif