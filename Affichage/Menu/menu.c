//gcc menu.c -o menu `sdl2-config --cflags --libs` -lSDL2_ttf


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>


#define CELL_SIZE 80
#define PAWN_RADIUS 35
#define POTENTIAL_PAWN_RADIUS 10


typedef enum {
    NOIR = 0,
    BLANC = 1,
    POTENTIEL = 2,
    VIDE = 3
} CELL;


// Fonction qui dessine le texte sur le rendu
void drawText(SDL_Renderer *renderer, TTF_Font *font, const char *text, SDL_Rect *rect)
{
    SDL_Color color = {255, 255, 255, 255};
    SDL_Surface *surface = TTF_RenderText_Solid(font, text, color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    SDL_RenderCopy(renderer, texture, NULL, rect);

    SDL_DestroyTexture(texture);
}
CELL** back_game(SDL_Renderer *renderer)
{
    SDL_Color background_color = {83,147,120,255};          //Couleur de fond
    SDL_Color black_color = {0,0,0,255};                    //Couleur noir
    SDL_Color white_color = {255,255,255,255};              //Couleur blanc
    SDL_Color potential_color = {127,127,127,255};          //Couleur gris


    CELL plate[8][8];     //On crée le plateau de jeu

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            plate[i][j] = VIDE;
        }
    }
    plate[3][3] = BLANC;        //On place les 4 pions de départ
    plate[4][4] = BLANC;
    plate[3][4] = NOIR;
    plate[4][3] = NOIR;

    SDL_SetRenderDrawColor(renderer, background_color.r, background_color.g, background_color.b, background_color.a);
    SDL_RenderClear(renderer);      //On met le fond 

    SDL_SetRenderDrawColor(renderer, black_color.r, black_color.g, black_color.b, black_color.a);
    for (int i = 1; i <=8; i++)     //On fait la grille
    {
        SDL_RenderDrawLine(renderer, i*CELL_SIZE, 0, i*CELL_SIZE, 8*CELL_SIZE);
        SDL_RenderDrawLine(renderer, 0, i*CELL_SIZE, 8*CELL_SIZE, i*CELL_SIZE);
    }
    
    SDL_RenderPresent(renderer);
    return(plate);
}

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

int jeu(SDL_Window *window,SDL_Renderer *renderer, CELL**plate)
{
     int quit =0;
     int round = 1;

    SDL_Event event;                                        //Variables pour les interractions
    int clicX = 0;
    int clicY = 0;

    SDL_Color black_color = {0,0,0,255};                    //Couleur noir
    SDL_Color white_color = {255,255,255,255};              //Couleur blanc
    SDL_Color potential_color = {127,127,127,255};          //Couleur gris
    

    while (quit == 0)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:      //Si on clique sur la croix, on quitte
                    printf ("DEBUG : appui sur SDL_QUIT\n");
                    return(1);
                    break;
                case SDL_KEYDOWN:   //Si on appuie sur une touche, on teste laquelle
                    if (event.key.keysym.sym == SDLK_q)
                    {
                        quit = 1;
                    printf("DEBUG : appui sur touche %d détecté\n", event.key.keysym.sym);
                    }
                    break;
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                    {
                        printf("DEBUG : appui sur touche %d détecté\n", event.key.keysym.sym);
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT)
                    {
                        clicX = event.button.x;
                        clicY = event.button.y;
                        printf("DEBUG : clic gauche détecté à la position (%d, %d)\n", clicX, clicY);
                        if (round%2 == 1)
                            plate[clicX/CELL_SIZE][clicY/CELL_SIZE]=NOIR;
                        if (round%2 == 0)
                            plate[clicX/CELL_SIZE][clicY/CELL_SIZE]=BLANC;
                        round ++;
                    }
                    break;
                default:
                    break;
            }
            
        }

        for (int i = 0; i < 8; i++)             //On parcours le tableau plate pour afficher les pions
        {
            for (int j = 0; j < 8; j++)
            {
                if (plate[i][j] == BLANC)
                    drawPAWN(renderer, CELL_SIZE/2 + i*CELL_SIZE, CELL_SIZE/2 + j*CELL_SIZE, PAWN_RADIUS, white_color);
                if (plate[i][j] == NOIR)
                    drawPAWN(renderer, CELL_SIZE/2 + i*CELL_SIZE, CELL_SIZE/2 + j*CELL_SIZE, PAWN_RADIUS, black_color);
                if (plate[i][j] == POTENTIEL)
                    drawPAWN(renderer, CELL_SIZE/2 + i*CELL_SIZE, CELL_SIZE/2 + j*CELL_SIZE, POTENTIAL_PAWN_RADIUS, potential_color);
            }
        }

        SDL_RenderPresent(renderer);
    }
}

int main(int argc, char *argv[])
{
        int Affichage =0;
    // Initialisation de SDL2
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        fprintf(stderr, "Erreur lors de l'initialisation de SDL : %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    // Initialisation de SDL2_TTF
    if (TTF_Init() != 0)
    {
        fprintf(stderr, "Erreur lors de l'initialisation de SDL_TTF : %s\n", TTF_GetError());
        return EXIT_FAILURE;
    }

    // Création de la fenêtre et du rendu
    SDL_Window *window = SDL_CreateWindow("Menu de démarrage", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,8*CELL_SIZE+300,8*CELL_SIZE,SDL_WINDOW_SHOWN);;
    if (window == NULL)
    {
        fprintf(stderr, "Erreur lors de la création de la fenêtre : %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == NULL)
    {
        fprintf(stderr, "Erreur lors de la création du rendu : %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    // Chargement de la police de caractères
    TTF_Font *font = TTF_OpenFont("ARIAL.TTF", 24);
    if (font == NULL)
    {
        fprintf(stderr, "Erreur lors du chargement de la police de caractères : %s\n", TTF_GetError());
        return EXIT_FAILURE;
    }

     // Effacement du rendu
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Dessin des boutons
        SDL_Rect rect = {200, 100, 240, 40};
        drawText(renderer, font, "Nouvelle partie", &rect);
        rect.y += 80;
        drawText(renderer, font, "Charger une partie", &rect);
        rect.y += 80;
        drawText(renderer, font, "Regles", &rect);

        // Affichage du rendu
        SDL_RenderPresent(renderer);

    // Boucle principale
    bool done = false;
    while (!done)
    {
        // Gestion des événements
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    goto Quit;
                    break;
                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        goto Quit;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    // Vérification des clics sur les boutons
                    if (event.button.button == SDL_BUTTON_LEFT)
                    {
                        int x = event.button.x;
                        int y = event.button.y;
                        if (x >= 200 && x <= 440 && y >= 100 && y <= 140)
                        {
                            CELL** plate=NULL;
                            if (Affichage ==0)
                            {
                                plate=back_game(renderer);
                                Affichage=1;
                            }
                            done=jeu(window,renderer,plate);
                        }
                        else if (x >= 200 && x <= 440 && y >= 180 && y <= 220)
                            printf("Charger une partie\n");
                        else if (x >= 200 && x <= 440 && y >= 260)
                              printf("Regles\n");
                    }
                    break;
                default:
                    break;
            }
        }

       
    }
    Quit:
    // Libération des ressources
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();

    return EXIT_SUCCESS;
}