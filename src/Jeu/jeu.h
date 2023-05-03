#ifndef JEU_H
#define JEU_H

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

void initCell(CASE plate [8][8]);
/**
 * @brief Initialise le plateau pour un début de partie
 */

int playerColor (int round);
int advColor (int couleurJoueur);

void possibility(CASE plateau[8][8], CELL couleurJoueur, CELL couleurAdv);
/**
 * @brief Détermine les cases qui sont jouables
 */

void check(CASE plateau[8][8], CASE maCase);
/**
 * @brief Retourne les cases entre maCase et les piosn de la meme couleurs
 * @param maCase : case séléctioner
 */

int checkPlayable(CASE plateau[8][8], int round,int * cptSkipTurn);
/**
 * @brief compte le nombre de case jouables et incrémente le round si il n'y en a pas
 * @param maCase : case séléctioner
 */

int checkWinGame(CASE plateau[8][8], int cptSkipTurn);
int cptCase (CASE plateau[8][8]);
int cptCaseColor (CASE plateau[8][8],int Color);

#endif
