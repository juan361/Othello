#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jeux2.c"


// Initialise le générateur pseudo-aléatoire
srand(time(NULL));
int min=1;
int max=8;
int a = min + rand() % (max + 1 - min);
int b = min + rand() % (max + 1 - min);

int niveauUn() {
	while (CELL bord [a][b] != playable){
		srand(time(NULL));
		int a = min + rand() % (max + 1 - min);
		int b = min + rand() % (max + 1 - min);
	}
	if a==1{  // char
		a==A;
		}
    return 
    //IA joue CELL bord [a][b]
}

int niveauDeux(){
	for (CELL bord	
}
