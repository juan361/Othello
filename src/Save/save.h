#ifndef SAVE_H
#define JEU_H

#include "../Jeu/jeu.h"

#include <stdio.h>
//#include "../Affichage/affichage.h"

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

typedef struct noeud
{
    int tour;
    int** plateau;
    coup* suivant;
    coup* prec;
}coup;

int retour_plateau(CASE plateau[8][8]);

void save_coup(coup* chaine, CASE plate[8][8]);

void sauvegarde_txt(coup* c);

void retour_coup(coup c);

void charger_partie(int tab[8][8], CASE plate[8][8]);

#endif