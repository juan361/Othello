#include "affichage.h"

/*nt playableCELLS(CELL plate[8][8], int round)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (plate[i][j] == POTENTIEL)
                plate[i][j] = VIDE;
            if (plate[i][j] == VIDE)
                {
                    if (round%2 == 1)
                    {
                                        //noir
                    }
                    if (round%2 == 0)
                    {
                                        //blanc
                    }
                }
        }
    }
}
*/

void drawPAWN(SDL_Renderer *renderer, int x, int y, int radius, SDL_Color color)    //Fonction qui dessine un pion
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    for (int w = 0; w < radius * 2; w++)
        for (int h = 0; h < radius * 2; h++)
        {
            int dx = radius - w;
            int dy = radius - h;
            if ((dx*dx + dy*dy) <= (radius * radius))
                SDL_RenderDrawPoint(renderer, x + dx, y + dy);
        }
}
