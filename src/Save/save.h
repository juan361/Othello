#ifndef SAVE_H
#define JEU_H
#include "../Jeu/jeu.h"
#include "../Affichage/affichage.h"


typedef struct coup
{
    int tour;
    int** plateau;
    struct noeud* suivant;
    struct noeud* prec;

};

int retour_plateau(CASE plateau[8][8]);

void save_coup(struct coup chaine, CASE plate[8][8]);

void sauvegarde_txt(struct coup c);

void retour_coup(struct coup c);

void charger_partie(int tab[8][8], CASE plate[8][8]);

#endif