#include "../Affichage/affichage.h"


struct coup
{
    int tour;
    int plateau[8][8];
    struct coup* suivant;
    struct coup* prec;
};


int** retour_plateau(CASE plateau[8][8])
{
    int** tab[8][8];

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
          tab[i][j] = plateau[i][j].pion; 
        }
        
    }
   return tab;
}
void save_coup(struct coup chaine,CASE plateau[8][8])
{
    //variable joueur à faire
    struct coup c;
    c.prec   = *chaine;
    chaine.suivant = *c;
    c.plateau = retour_plateau(plateau);

    
}
void sauvegarde_txt(struct coup c){
    int r = roundr();
    FILE *fichier = fopen("charger.txt", "w");
    fprintf(fichier, "%d:", round);
        for(int i; i < 8; i++){
            for(int j; j < 8; j++){
                fprintf(fichier, "%d", c.plateau[i][j]);
            }
        }
    fprintf(fichier, "\n");
}