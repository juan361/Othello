//gcc main.c $(sdl2-config --cflags --libs)

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])

{
    SDL_Window *window = NULL;              //Créer une variable pour la fenettre
    SDL_Renderer *renderer = NULL;          //Créer une variable pour le rendu -> permet de modifier l'intérieur de la fenettre

    int statut = EXIT_FAILURE;

    SDL_Color vert = {100, 255, 100, 255}; //{rouge, vert, bleu, transparance}

    SDL_Event event;
    SDL_bool quit = SDL_FALSE;
    
    if(0 != SDL_Init(SDL_INIT_VIDEO)) // Initialisation du SDL
    {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        goto Quit;
    }
    /*
    Creation de la fenettre :SDL_Window* SDL_CreateWindow(const char* title,
                             int         x,
                             int         y,
                             int         width,
                             int         height,
                             Uint32      flags)
    */
    window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              1000, 640, SDL_WINDOW_SHOWN);
    if(NULL == window)
    {
        fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
        goto Quit;
    }
    /*
    Creation du rendu: permet de modifier la fenettre:
    SDL_Renderer* SDL_CreateRenderer(SDL_Window* window,
                                 int         index,
                                 Uint32      flags)
    */
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(NULL == renderer)
    {
        fprintf(stderr, "Erreur SDL_CreateRenderer : %s", SDL_GetError());
        goto Quit;
    }



     if(0 != SDL_SetRenderDrawColor(renderer, vert.r, vert.g, vert.b, vert.a))
    {
        fprintf(stderr, "Erreur SDL_SetRenderDrawColor : %s", SDL_GetError());
        goto Quit;
    }
    
    if(0 != SDL_RenderClear(renderer))
    {
        fprintf(stderr, "Erreur SDL_SetRenderDrawColor : %s", SDL_GetError());
        goto Quit;
    }
    /*dessiner des lignes
    int j=1;
    while (j<8)
    {
    SDL_Point point[640];
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    size_t i = 0;
    for(i = 0; i < 640; i++)
    {
        point[i].x = i;
        point[i].y = j*80;
    }
    SDL_RenderDrawPoints(renderer, point, 640);
    j=j+1;
    }
    */

    /*dessiner une diagonale
    SDL_Point point[905];
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    size_t i = 0;
    for(i = 0; i < 905; i++)
    {
        point[i].x = i;
        point[i].y = i;
    }
    SDL_RenderDrawPoints(renderer, point, 640);
    */

    //dessiner un quadrillage
    int j=1;
    while (j<9)
    {
    SDL_Point point1[640];
    SDL_Point point2[640];
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    size_t i = 0;
    for(i = 0; i < 640; i++)
    {
        point1[i].x = i;
        point1[i].y = j*80;
        point2[i].x = j*80;
        point2[i].y = i;
    }
    SDL_RenderDrawPoints(renderer, point1, 640);
    SDL_RenderDrawPoints(renderer, point2, 640);
    j=j+1;
    }
    SDL_RenderPresent(renderer);
    SDL_Delay(3000);
    statut = EXIT_SUCCESS;

 
    while(!quit)
    {
        SDL_WaitEvent(&event);      //WaitEvent bloque le programme a ce niveau jusqua ce qu'on y rentre un event
        if(event.type == SDL_QUIT)
            goto Quit;
    } 

  
Quit:./
    if(NULL != renderer)
        SDL_DestroyRenderer(renderer);
    if(NULL != window)
        SDL_DestroyWindow(window);
    SDL_Quit();
    return statut;
}