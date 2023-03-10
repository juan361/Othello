#include <SDL2/SDL.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

enum State
{
    empty,
    black,
    white,
    playable
};

typedef struct cell
{
    int x;
    int y;
    enum State state;
}Cell;

Cell board [8][8];



int playableCell ()
{

}