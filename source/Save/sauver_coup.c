#include "../Affichage/affichage.h"



struct coup
{
    int tour;
    int** plateau;
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
          tab[i][j] = plateau[i][j].pion; 
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
    FILE *fichier = fopen("../sauv/sauv.txt", "w");
    fprintf(fichier, "%d:", round);
    fprintf(fichier, "%d\n", entier);
        for(int i; i < 8; i++){
            for(int j; j < 8; j++){
                fprintf(fichier, "%d", plateau[i][j]);
            }
        }
}
void retour_coup(struct coup c){
    
    // on va rejouer le coup précédent
    struct coup a;
    a = c.prec;
    int tab[8][8];
    tab = a.plateau;

    
    //je vais supprimer la dernière ligne.
    FILE *fichier = fopen("../sauv/sauv.txt", "wr");
    long int pos = -1;
    int ch = 0;

    fseek(file, 0, SEEK_END);
    pos = ftell(file);

    while (pos) {
        fseek(file, --pos, SEEK_SET);
        ch = fgetc(file);
        if (ch == '\n') {
            break;
        }
    }

    fseek(file, pos, SEEK_SET);
    ftruncate(fileno(file), pos);

    fclose(file);
    }

void charger_partie(int tab[8][8], CASE plate[8][8])
{
    // nous allons imiter le initCell du jeu de base, sauf que au lieu de le mettre tout en vide nous allons suivre le tableau sauvegardé dans le tableau
    
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0;j < 8; j++)
        {
            plate[i][j].pion = tab[i][j];
            plate[i][j].posX = i;
            plate[i][j].posY = j; 
        }
    }
}
int main(struct coup c){}
{

}