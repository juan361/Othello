//gcc menu.c -o menu `sdl2-config --cflags --libs` -lSDL2_ttf
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>

#define SCREEN_WIDTH 940
#define SCREEN_HEIGHT 640
#define CELL_SIZE 80

// Structure pour représenter une option de menu
typedef struct {
    SDL_Rect rect;  // Rectangle pour afficher l'option de menu
    const char* label;  // Texte de l'option de menu
} MenuOption;

int main(int argc, char* args[]) 
{
    int sel =0;

    // Initialisation de SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL n'a pas pu être initialisé ! Erreur SDL : %s\n", SDL_GetError());
        return 1;
    }

    // Création de la fenêtre
    SDL_Window* window = SDL_CreateWindow("Menu d'options", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("La fenêtre n'a pas pu être créée ! Erreur SDL : %s\n", SDL_GetError());
        return 1;
    }

    // Chargement de l'image de fond
    SDL_Surface* bgSurface = IMG_Load("fond3.png");
    if (bgSurface == NULL) {
        printf("L'image de fond n'a pas pu être chargée ! Erreur SDL_image : %s\n", IMG_GetError());
        return 1;
    }

    // Chargement de la police de caractères pour le texte du menu
    TTF_Init();
    TTF_Font* font = TTF_OpenFont("ARIAL.TTF", 24);
    if (font == NULL) {
        printf("La police de caractères n'a pas pu être chargée ! Erreur TTF : %s\n", TTF_GetError());
        return 1;
    }
    SDL_Color colorWhite = { 255, 255, 255 };
    SDL_Color colorBlack = { 0,0,0 };
    SDL_Color background_color = {83,147,120,255};

    if (sel == 0)
    {
    // Création de la surface de la fenêtre
    SDL_Surface* windowSurface = SDL_GetWindowSurface(window);

    // Création des options de menu
    MenuOption newGameOption = { { 370, 0, 200, 50 }, "Nouvelle partie" };
    MenuOption loadGameOption = { { 370, 60, 200, 50 }, "Charger partie" };
    MenuOption rulesOption = { { 370, 120, 200, 50 }, "Regles" };

    // Affichage du fond d'écran
    SDL_BlitSurface(bgSurface, NULL, windowSurface, NULL);

    // Affichage des options de menu
    
    SDL_Surface* textSurface;
    textSurface = TTF_RenderText_Solid(font, newGameOption.label, colorBlack);
    SDL_BlitSurface(textSurface, NULL, windowSurface, &newGameOption.rect);
    SDL_FreeSurface(textSurface);

    textSurface = TTF_RenderText_Solid(font, loadGameOption.label, colorBlack);
    SDL_BlitSurface(textSurface, NULL, windowSurface, &loadGameOption.rect);
    SDL_FreeSurface(textSurface);

    textSurface = TTF_RenderText_Solid(font, rulesOption.label, colorBlack);
    SDL_BlitSurface(textSurface, NULL, windowSurface, &rulesOption.rect);
    SDL_FreeSurface(textSurface);
    }
    else if (sel == 1)
    {
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    SDL_SetRenderDrawColor(renderer, background_color.r, background_color.g, background_color.b, background_color.a);
    SDL_RenderClear(renderer);      //On met le fond 

    SDL_SetRenderDrawColor(renderer, colorBlack.r, colorBlack.g, colorBlack.b, colorBlack.a);
    for (int i = 1; i <=8; i++)     //On fait la grille
    {
        SDL_RenderDrawLine(renderer, i*CELL_SIZE, 0, i*CELL_SIZE, 8*CELL_SIZE);
        SDL_RenderDrawLine(renderer, 0, i*CELL_SIZE, 8*CELL_SIZE, i*CELL_SIZE);
    }
    }
    // Mise à jour de la fenêtre
    SDL_UpdateWindowSurface(window);

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
                if (x >= 370 && x <= 570 && y >= 0 && y <= 50)
                {
                    printf("L'option Nouvelle partie a été sélectionnée !\n");
                    sel=1;
                }
                else if (x >= 370 && x <= 570 && y >= 60 && y <= 110)
                {
                    printf("L'option charger partie a été sélectionnée !\n");
                }
                else if (x >= 370 && x <= 570 && y >= 120 && y <= 170)
                {
                    printf("L'option regles a été sélectionnée !\n");
                }
                
            }
        }
    }
    

    // Libération de la mémoire et fermeture de SDL
    SDL_FreeSurface(bgSurface);
    TTF_CloseFont(font);
    SDL_DestroyWindow(window);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}