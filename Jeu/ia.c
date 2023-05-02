#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.c"



void niveauUn(t_matrice plate) {
	// Initialise le générateur pseudo-aléatoire
	int min=1;
	int max=8;
	char c;
	srand(time(NULL));
		int a = min + rand() % (max + 1 - min);
		int b = min + rand() % (max + 1 - min);
	//while (plate[a][b].pion =! POTENTIEL){
		srand(time(NULL));
		a = min + rand() % (max + 1 - min);
		b = min + rand() % (max + 1 - min);
	//}
    retern plate[a][b];
}

void niveauDeux(CASE plate [8][8]) {

    plate[0][0].pion = 20;
    plate[0][7].pion = 20;
    plate[7][0].pion = 20;
    plate[7][7].pion = 20;

    plate[3][1].pion = 2;
    plate[4][1].pion = 2;
    plate[3][2].pion = 2;
    plate[4][2].pion = 2;
    plate[1][3].pion = 2;
    plate[1][4].pion = 2;
    plate[2][3].pion = 2;
    plate[2][4].pion = 2;
    plate[3][5].pion = 2;
    plate[4][5].pion = 2;
    plate[3][6].pion = 2;
    plate[4][6].pion = 2;
    plate[5][3].pion = 2;
    plate[6][3].pion = 2;
    plate[5][4].pion = 2;
    plate[6][4].pion = 2;

    plate[2][0].pion = 10;
    plate[3][0].pion = 10;
    plate[4][0].pion = 10;
    plate[5][0].pion = 10;
    plate[5][1].pion = 10;
    plate[5][2].pion = 10;
    plate[6][2].pion = 10;
    plate[7][2].pion = 10;
    plate[7][3].pion = 10;
    plate[7][4].pion = 10;
    plate[7][5].pion = 10;
    plate[6][5].pion = 10;
    plate[5][5].pion = 10;
    plate[5][6].pion = 10;
    plate[5][7].pion = 10;
    plate[4][7].pion = 10;
    plate[3][7].pion = 10;
    plate[2][7].pion = 10;
    plate[2][6].pion = 10;
    plate[2][5].pion = 10;
    plate[1][5].pion = 10;
    plate[0][5].pion = 10;
    plate[0][4].pion = 10;
    plate[0][3].pion = 10;
    plate[0][2].pion = 10;
    plate[1][2].pion = 10;
    plate[2][2].pion = 10;
    plate[2][1].pion = 10;

    if (plate[0][0].pion == /*occuper*/){
         if (plate[0][0].pion == /*couleur de l'ia*/){
            plate[1][0].pion = 15;
            plate[1][1].pion = 15;
            plate[0][1].pion = 15;
         }
         else{
            plate[1][0].pion = 0;
            plate[1][1].pion = 0;
            plate[0][1].pion = 0;  
         }
    }
    if (plate[0][0].pion !== /*occuper*/){
        plate[1][0].pion = 1;
        plate[1][1].pion = 1;
        plate[0][1].pion = ;  
    }

    if (plate[7][0].pion == /*occuper*/){
         if (plate[7][0].pion == /*couleur de l'ia*/){
            plate[6][0].pion = 15;
            plate[6][1].pion = 15;
            plate[7][1].pion = 15;
         }
         else{
            plate[6][0].pion = 0;
            plate[6][1].pion = 0;
            plate[7][1].pion = 0;  
         }
    }
    if (plate[7][0].pion !== /*occuper*/){
        plate[6][0].pion = 1;
        plate[6][1].pion = 1;
        plate[7][1].pion = 1;
    }

    if (plate[7][7].pion == /*occuper*/){
         if (plate[7][7].pion == /*couleur de l'ia*/){
            plate[6][7].pion = 15;
            plate[6][6].pion = 15;
            plate[7][6].pion = 15;
         }
         else{
            plate[6][7].pion = 0;
            plate[6][6].pion = 0;
            plate[7][6].pion = 0;  
         }
    }
    if (plate[7][7].pion !== /*occuper*/){
        plate[6][7].pion = 1;
        plate[6][6].pion = 1;
        plate[7][6].pion = 1;
    }

    if (plate[0][7].pion == /*occuper*/){
         if (plate[0][7].pion == /*couleur de l'ia*/){
            plate[1][7].pion = 15;
            plate[1][6].pion = 15;
            plate[0][6].pion = 15;
         }
         else{
            plate[1][7].pion = 0;
            plate[1][6].pion = 0;
            plate[0][6].pion = 0;  
         }
    }
    if (plate[0][7].pion !== /*occuper*/){
        plate[1][7].pion = 1;
        plate[1][6].pion = 1;
        plate[0][6].pion = 1;
    }

// comparer les valeur et retourner la plus élever
    int coupJouer = -1;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++){
            if (plate[i][j] == POTENTIEL) && (plate[i][j]>coupJouer){
                coupJouer = plate[i][j];
            }
        }
    }
    retern coupJouer;
}



