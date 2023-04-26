#include "/home/isen/Documents/algo/projet_othello/Othello/Affichage/affichage.h"


struct coup
{
    int tour;
    int plateau;
    struct noeud* suivant;
    struct noeud* prec;
};
int** retour_plateau(CASE plateau[8][8])
{
    int** tab[8][8];

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
          tab[i][j]= plateau.pion[i][j]; 
        }
        
    }
   return tab;
}
void save_coup(struct coup chaine)
{
    //variable joueur à faire
    struct coup c;
    c.prec   = *chaine;
    chaine.suivant = *c;
    c.plateau = retour_plateau(plateau[8][8]);

    
}
void sauvegarde_txt(struct coup c){
    int r = roundr();
    FILE *fichier = fopen("charger.txt", "w");

}