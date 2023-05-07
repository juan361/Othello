#include "save.h"


//gcc -o save save.c ../Jeu/jeu.c


int retour_plateau(CASE plateau[8][8])
{
     CASE tab[8][8];

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
          tab[i][j].pion = plateau[i][j].pion;
        }
        
    }
   return tab[8][8].pion;
}

int isFileEmpty(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return -1; // Erreur d'ouverture du fichier
    }
    
    fseek(file, 0, SEEK_END); // Se positionner à la fin du fichier
    if (ftell(file) == 0) { // Vérifier la position courante
        fclose(file);
        return 1; // Le fichier est vide
    }
    
    fclose(file);
    return 0; // Le fichier n'est pas vide
}

void save_coup( coup *chaine, CASE plateau[8][8])
{
   
    //variable joueur à faire
    coup *c;
    c->tour = chaine->tour+1;
    
    c->plateau = retour_plateau(plateau);

    c->prec   = chaine;
    chaine->suivant = c;
    sauvegarde_txt(c);

    
}
void sauvegarde_txt(coup *c){
    
    FILE *fichier = fopen("../sauv/sauv.txt", "w");
    fprintf(fichier, "%d:", c->tour);
   // fprintf(fichier, "%d:", c->plateau);
        for(int i; i < 8; i++){
            for(int j; j < 8; j++){
                fprintf(fichier, "%d", c->plateau);
            }
        }
    fclose(fichier);
}
void retour_coup(coup c,CASE plateau[8][8]){
    
    // on va rejouer le coup précédent
     //coup a;
     coup *a;
    a = c.prec;
    int tab[8][8];
     for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            tab[i][j] = plateau[i][j].pion;
        }
    }


    
    //je vais supprimer la dernière ligne.
    FILE *fichier = fopen("../sauv/sauv.txt", "w");
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
int main()
{
    char*  cv = "../test/testv.txt";
    char*  c  = "../test/test.txt";

    if(isFileEmpty(cv)==1)
    {
        printf("teste vide juste");
    }
    else
    {
        printf("test vide faux");
    }
        if(isFileEmpty(c)==1)
    {
        printf("teste juste");
    }
    else
    {
        printf("test faux");
    }
}