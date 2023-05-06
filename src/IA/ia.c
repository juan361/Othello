#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ia.h"
#include "../Jeu/jeu.h"

//gcc -o ia ia.c ../Jeu/jeu.c

CASE niveauUn(CASE plate [8][8]) {
	// Initialise le générateur pseudo-aléatoire
	int min=1;
	int max=8;
	srand(time(NULL));
		int a = min + rand() % (max + 1 - min);
		int b = min + rand() % (max + 1 - min);
	while (plate[a][b].pion =! POTENTIEL){
		srand(time(NULL));
		a = min + rand() % (max + 1 - min);
		b = min + rand() % (max + 1 - min);
	}
    return plate[a][b];
}

CASE niveauDeux(CASE plate [8][8]) {

    plate[0][0].poids = 20;
    plate[0][7].poids = 20;
    plate[7][0].poids = 20;
    plate[7][7].poids = 20;

    plate[3][1].poids = 2;
    plate[4][1].poids = 2;
    plate[3][2].poids = 2;
    plate[4][2].poids = 2;
    plate[1][3].poids = 2;
    plate[1][4].poids = 2;
    plate[2][3].poids = 2;
    plate[2][4].poids = 2;
    plate[3][5].poids = 2;
    plate[4][5].poids = 2;
    plate[3][6].poids = 2;
    plate[4][6].poids = 2;
    plate[5][3].poids = 2;
    plate[6][3].poids = 2;
    plate[5][4].poids = 2;
    plate[6][4].poids = 2;

    plate[2][0].poids = 10;
    plate[3][0].poids = 10;
    plate[4][0].poids = 10;
    plate[5][0].poids = 10;
    plate[5][1].poids = 10;
    plate[5][2].poids = 10;
    plate[6][2].poids = 10;
    plate[7][2].poids = 10;
    plate[7][3].poids = 10;
    plate[7][4].poids = 10;
    plate[7][5].poids = 10;
    plate[6][5].poids = 10;
    plate[5][5].poids = 10;
    plate[5][6].poids = 10;
    plate[5][7].poids = 10;
    plate[4][7].poids = 10;
    plate[3][7].poids = 10;
    plate[2][7].poids = 10;
    plate[2][6].poids = 10;
    plate[2][5].poids = 10;
    plate[1][5].poids = 10;
    plate[0][5].poids = 10;
    plate[0][4].poids = 10;
    plate[0][3].poids = 10;
    plate[0][2].poids = 10;
    plate[1][2].poids = 10;
    plate[2][2].poids = 10;
    plate[2][1].poids = 10;

    if (plate[0][0].pion == NOIR || plate[0][0].pion == BLANC){
         if (plate[0][0].pion == BLANC){
            plate[1][0].poids = 15;
            plate[1][1].poids = 15;
            plate[0][1].poids = 15;
         }
         else if(plate[0][0].pion == NOIR){
            plate[1][0].poids = 0;
            plate[1][1].poids = 0;
            plate[0][1].poids = 0;  
         }
    }
    else {
        plate[1][0].poids = 1;
        plate[1][1].poids = 1;
        plate[0][1].poids = 1;  
    }
    

    if (plate[7][0].pion ==  NOIR || plate[7][0].pion == BLANC){
         if (plate[7][0].pion == BLANC){
            plate[6][0].poids = 15;
            plate[6][1].poids = 15;
            plate[7][1].poids = 15;
         }
         else if (plate[7][0].pion == NOIR){
            plate[6][0].poids = 0;
            plate[6][1].poids = 0;
            plate[7][1].poids = 0;  
         }
    }
    else {
        plate[6][0].poids = 1;
        plate[6][1].poids = 1;
        plate[7][1].poids = 1;
    }
    

    if (plate[7][7].pion == NOIR || plate[7][7].pion == BLANC){
         if (plate[7][7].pion == BLANC){
            plate[6][7].poids = 15;
            plate[6][6].poids = 15;
            plate[7][6].poids = 15;
         }
         else if (plate[7][7].pion == NOIR){
            plate[6][7].poids = 0;
            plate[6][6].poids = 0;
            plate[7][6].poids = 0;  
         }
    }
    else {
        plate[6][7].poids = 1;
        plate[6][6].poids = 1;
        plate[7][6].poids = 1;
    }
    

    if (plate[0][7].pion == NOIR || plate[0][7].pion == BLANC){
         if (plate[0][7].pion == BLANC){
            plate[1][7].poids = 15;
            plate[1][6].poids = 15;
            plate[0][6].poids = 15;
         }
         else if (plate[0][7].pion == NOIR){
            plate[1][7].poids = 0;
            plate[1][6].poids = 0;
            plate[0][6].poids = 0;  
         }
    }
    else{
        plate[1][7].poids = 1;
        plate[1][6].poids = 1;
        plate[0][6].poids = 1;
    }
    

// comparer les valeur et retourner la plus élever
    CASE coupJouer;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++){
            if ((plate[i][j].pion == POTENTIEL) && (plate[i][j].poids > coupJouer.poids)){
                coupJouer = plate[i][j];
            }
        }
    }
    return coupJouer;
}

int main (){
	CASE Tab[8][8];
    initCell(Tab);
	CASE nv1 = niveauUn(Tab);
	CASE nv2 = niveauDeux(Tab);
	printf ("%d,%d\n", nv1.posX, nv1.posY);
    printf ("%d,%d\n", nv2.posX, nv2.posY);
	
}



