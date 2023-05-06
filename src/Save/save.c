#include "save.h"


#include "../Jeu/jeu.c"
#include "../Jeu/jeu.h"
//gcc -o save save.c ../Jeu/jeu.c


int retour_plateau(CASE plateau[8][8])
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
void save_coup( coup *chaine, CASE plate[8][8])
{
   
    //variable joueur à faire
    coup *c;
    c->tour = chaine->tour+1;
    
    c->plateau = retour_plateau(plate[8][8]);

    c->prec   = chaine;
    chaine->suivant = c;
    sauvegarde_txt(c);

    
}
void sauvegarde_txt(coup *c){
    
    FILE *fichier = fopen("../sauv/sauv.txt", "w");
    fprintf(fichier, "%d:", c->tour);
    fprintf(fichier, "%d;");
        for(int i; i < 8; i++){
            for(int j; j < 8; j++){
                fprintf(fichier, "%d", c->plateau[i][j]);
            }
        }
}
void retour_coup(coup c){
    
    // on va rejouer le coup précédent
     //coup a;
     coup *a;
    a = c.prec;
    int tab[8][8];
     for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            tab[i][j] = a->plateau[i][j];
        }
    }


    
    //je vais supprimer la dernière ligne.
    FILE *fichier = fopen("../sauv/sauv.txt", "wr");
    long int pos = -1;
    int ch = 0;

    fseek(fichier, 0, SEEK_END);
    pos = ftell(fichier);

    while (pos) {
        fseek(fichier, --pos, SEEK_SET);
        ch = fgetc(fichier);
        if (ch == '\n') {
            break;
        }
    }

    fseek(fichier, pos, SEEK_SET);
    ftruncate(fileno(fichier), pos);

    fclose(fichier);
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
int main(coup c)
{

}