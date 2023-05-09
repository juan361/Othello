//gcc menu2.c -o menu -lSDL2 -lSDL2_ttf -lSDL2_image


//#include <windows.h>
//#include <curl/curl.h>
#include "Affichage/affichage.h"

#define SCREEN_WIDTH 940
#define SCREEN_HEIGHT 640
#define CELL_SIZE 80

void clignMenu(SDL_Renderer* renderer, SDL_Event event)
{
    if  (event.motion.x >= 285 && event.motion.x <= 655 && event.motion.y >= 320 && event.motion.y <= 400)
        chargerEtAfficherImage(renderer,"../resources/img/menu_1.png",0,0);
    else if (event.motion.x >= 285 && event.motion.x <= 655 && event.motion.y >= 430 && event.motion.y <= 507)
        chargerEtAfficherImage(renderer,"../resources/img/menu_2.png",0,0);
    else if (event.motion.x >= 285 && event.motion.x <= 655 && event.motion.y >= 535 && event.motion.y <= 613)
        chargerEtAfficherImage(renderer,"../resources/img/menu_3.png",0,0);
    else
        chargerEtAfficherImage(renderer,"../resources/img/menu.png",0,0);
    SDL_RenderPresent(renderer); 
}




int main(int argc, char* args[]) 
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)      //On initialise SDL, on quitte si erreur(s)
    {
        fprintf(stderr, "Erreur SDL_Init : %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Othello", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 8*CELL_SIZE+300, 8*CELL_SIZE, SDL_WINDOW_SHOWN);//On crée la fenêtre
    if(NULL == window)                      //Après avoir créé la fenêtre, on quitte si erreur(s)
    {
        printf( "Erreur SDL_CreateWindow : %s\n", SDL_GetError());
         SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);    //On crée le renderer
    if(NULL == renderer)                    //Après avoir crée le renderer, on quitte si erreur(s)
    {
        printf( "Erreur SDL_CreateRenderer : %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    if (TTF_Init() < 0)          //On initialise TTF, on quitte si erreur(s)
    {
        printf("Erreur TTF_Init : %s\n", TTF_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    TTF_Font* font = TTF_OpenFont(FONT_PATH, 24);
    if (NULL == font) 
    {
        printf("Erreur TTF_OpenFont: %s\n", TTF_GetError());
        TTF_Quit();
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    //création menu
    Home:
    chargerEtAfficherImage(renderer,"../resources/img/menu.png",0,0);

    // Mise à jour de la fenêtre
    SDL_RenderPresent(renderer); 

    // Boucle principale
    SDL_Event event;
    int quit = 0;
    while (quit ==0)
    {
        // Gestion des événements
        while (SDL_PollEvent(&event) != 0) 
        {
            if (event.type == SDL_QUIT) 
            {
                quit = 1;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN) 
            {
                // Vérification si une option de menu a été cliquée
                int x = event.button.x;
                int y = event.button.y;
                //printf("DEBUB  : x:%d  y:%d\n",x,y);
                if (x >= 285 && x <= 655 && y >= 320 && y <= 400)
                {
                    printf("L'option Nouvelle partie a été sélectionnée !\n");
                    int game = gameStart(/*window,*/renderer,event,font);
                    if( game ==1)
                        goto Quit;
                    if(game==2)
                        goto Home;
                }
                else if (x >= 285 && x <= 655 && y >= 430 && y <= 507)
                {
                    printf("L'option charger partie a été sélectionnée !\n");
                }
                else if (x >= 285 && x <= 655 && y >= 535 && y <= 613)
                {
                    printf("L'option regles a été sélectionnée !\n");
                    system("firefox https://www.regledujeu.fr/othello/");
                    
                }
                


            }
            else if (event.type == SDL_MOUSEMOTION)
            {
                //printf("Mouvement de souris (%d %d) \n", event.motion.x, event.motion.y);
               clignMenu(renderer,event); 
            }
        }
    }
    
    Quit:
    // Libération de la mémoire et fermeture de SDL
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}