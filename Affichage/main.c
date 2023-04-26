#include "affichage.h"


int main(int argc, char *argv[])
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Event event;                                        //Variables pour les interractions

    

    if (SDL_Init(SDL_INIT_VIDEO) != 0)      //On initialise SDL, on quitte si erreur(s)
    {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow("Grille de 64 cases", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 8*CELL_SIZE+300, 8*CELL_SIZE, SDL_WINDOW_SHOWN);//On crée la fenêtre
    if(NULL == window)                      //Après avoir créé la fenêtre, on quitte si erreur(s)
    {
        fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
         SDL_Quit();
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);    //On crée le renderer
    if(NULL == renderer)                    //Après avoir crée le renderer, on quitte si erreur(s)
    {
        fprintf(stderr, "Erreur SDL_CreateRenderer : %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    if (TTF_Init() < 0) {
        printf("SDL_ttf could not initialize! SDL_Error: %s\n", TTF_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

     TTF_Font* font = TTF_OpenFont(FONT_PATH, 24);
    if (!font) {
        printf("Font could not be loaded! SDL_Error: %s\n", TTF_GetError());
        TTF_Quit();
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }


    gameStart(window,renderer,event,font);

//bug dans le systeme de victoire

Quit:
    // Libérer la police
    //TF_CloseFont(font);
    TTF_Quit();
    // Détruire le renderer et la fenêtre
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    // Quitter SDL
    SDL_Quit();
    return 0;
}