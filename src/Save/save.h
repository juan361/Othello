#ifndef SAVE_H
#define JEU_H

#include "../Jeu/jeu.h"

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
//#include "../Affichage/affichage.h"

typedef struct coup
{
    int tour;
    int** plateau;
    struct coup* prec;
}coup;

int** retour_plateau(CASE tab[8][8]);
/**
 * @brief il va retourner le  l'état de chaque case au plateau. supposé être un tableau de 64 chiffres
 * @param 
*/

int isFileEmpty(char* filename);
/**
 * @brief prg qui retour un entier pour savoir si le fichier est vide ou non
 * @return 1 : fichier vide
 * @return 0 : pas vide
 * @return -1 : erreur
*/

coup save_coup(coup* chaine, CASE plate[8][8]);
/**
 * @brief à la fin de chaque coup, nous allons donc ajouter le coup avec le round et le tableau avec l'état de chaque case.
*/

void sauvegarde_txt(coup* c);
/**
 * @brief nous allons sauvegarder tout les coups de la fin au début dans le fichier. 
*/

void retour_coup(coup c,CASE plateau[8][8]);
/**
 * @brief pour le coup en arrière, qui utilise charger partie
*/

void charger_partie(int tab[8][8], CASE plate[8][8]);
/**
 * @brief retourne un CASE avec tout les état du plate comme ça on a qu'à faire un init cell avec le CASE déjà prêt
*/
#endif