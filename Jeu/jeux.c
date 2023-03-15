#include <SDL2/SDL.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8
enum State
{
    empty,
    black,
    white,
    playable
};

typedef struct cellule
{
    int x;
    int y;
    enum State state;
}Cell;

Cell bord [BOARD_SIZE][BOARD_SIZE];

/*
*brief:
    Cette fonction a pour but d'initialiser la plateau
*/
void initBoard (void)
{

}
/* Fonction pour verifier qu'une case existe */
int checkInBoard (int lig, int col) 
{
    return ((col >= 0) && (col < BOARD_SIZE) && (lig >= 0) && (lig < BOARD_SIZE));
}
/*
*brief:
    Cette fonction a pour but de checker toutes les cases du plateau et de dire si elles sont jouables ou non
*para:
    -cell
    -player
*return:
    -0 si 
*/
int playableCell (Cell bord[BOARD_SIZE][BOARD_SIZE],Cell cell, int player)
{
    int i,j,ok;
    if (!checkInBoard(cell.x, cell.y) && cell.state != empty)
    {
        /*********************Ligne Haut*****************/
        i=cell.y-1;
        //ok=0;
        while(checkInBoard(cell.x,i) && bord[cell.x][i].state==opponent(player))
        {
            i--;
           // ok=1;
        }
        if(checkInBoard(cell.x,i) && bord[cell.x][i].state==player/*&& ok==1*/)
        {
            cell.state = playable;
            return(1);
        }
        /***************Ligne Bas*************/
        i=cell.y+1;
        //ok=0;
        while(checkInBoard(cell.x,i) && bord[cell.x][i].state==opponent(player))
        {
            i++;
           // ok=1;
        }
        if(checkInBoard(cell.x,i) && bord[cell.x][i].state==player/*&& ok==1*/)
        {
            cell.state = playable;
            return(1);
        }
        /****************Ligne gauche*************/
        j=cell.x-1;
        //ok=0;
        while(checkInBoard(j,cell.y) && bord[j][cell.y].state==opponent(player))
        {
            j--;
           // ok=1;
        }
        if(checkInBoard(j,cell.y) && bord[j][cell.y].state==player/*&& ok==1*/)
        {
            cell.state = playable;
            return(1);
        }
        /**************************Ligne Droite***************************/
        j=cell.x+1;
        //ok=0;
        while(checkInBoard(j,cell.y) && bord[j][cell.y].state==opponent(player))
        {
            j++;
           // ok=1;
        }
        if(checkInBoard(j,cell.y) && bord[j][cell.y].state==player/*&& ok==1*/)
        {
            cell.state = playable;
            return(1);
        }
        /****************************Diag HG*******************************/
        j=cell.x-1;
        i=cell.y-1;
        while(checkInBoard(i,j) && bord[i][j].state==opponent(player))
        {
            j--;
            i--;
        }
        if(checkInBoard(i,j) && bord[i][j].state==player/*&& ok==1*/)
        {
            cell.state = playable;
            return(1);
        }
        /****************************Diag HD*******************************/
        j=cell.x+1;
        i=cell.y-1;
        while(checkInBoard(i,j) && bord[i][j].state==opponent(player))
        {
            j++;
            i--;
        }
        if(checkInBoard(i,j) && bord[i][j].state==player/*&& ok==1*/)
        {
            cell.state = playable;
            return(1);
        }
        /****************************Diag BG*******************************/
        j=cell.x-1;
        i=cell.y+1;
        while(checkInBoard(i,j) && bord[i][j].state==opponent(player))
        {
            j--;
            i++;
        }
        if(checkInBoard(i,j) && bord[i][j].state==player/*&& ok==1*/)
        {
            cell.state = playable;
            return(1);
        }
        /****************************Diag BD*******************************/
        j=cell.x+1;
        i=cell.y+1;
        while(checkInBoard(i,j) && bord[i][j].state==opponent(player))
        {
            j++;
            i++;
        }
        if(checkInBoard(i,j) && bord[i][j].state==player/*&& ok==1*/)
        {
            cell.state = playable;
            return(1);
        }
        return(0);
    }
}