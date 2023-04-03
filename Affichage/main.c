#include "affichage.h"


int main(int argc, char *argv[])
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    int quit = 0;
    int round = 1;

    SDL_Event event;                                        //Variables pour les interractions
    int clicX = 0;
    int clicY = 0;

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
    


    if (SDL_Init(SDL_INIT_VIDEO) != 0)      //On initialise SDL, on quitte si erreur(s)
    {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        quit = 1;
    }

    window = SDL_CreateWindow("Grille de 64 cases", //On crée la fenêtre
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        8*CELL_SIZE+300,
        8*CELL_SIZE,
        SDL_WINDOW_SHOWN);
    if(NULL == window)                      //Après avoir créé la fenêtre, on quitte si erreur(s)
    {
        fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
        quit = 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);    //On crée le renderer
    if(NULL == renderer)                    //Après avoir crée le renderer, on quitte si erreur(s)
    {
        fprintf(stderr, "Erreur SDL_CreateRenderer : %s", SDL_GetError());
        quit = 1;
    }


    SDL_SetRenderDrawColor(renderer, background_color.r, background_color.g, background_color.b, background_color.a);
    SDL_RenderClear(renderer);      //On met le fond 

    SDL_SetRenderDrawColor(renderer, black_color.r, black_color.g, black_color.b, black_color.a);
    for (int i = 1; i <=8; i++)     //On fait la grille
    {
        SDL_RenderDrawLine(renderer, i*CELL_SIZE, 0, i*CELL_SIZE, 8*CELL_SIZE);
        SDL_RenderDrawLine(renderer, 0, i*CELL_SIZE, 8*CELL_SIZE, i*CELL_SIZE);
    }
    SDL_Rect rect = {8*CELL_SIZE, 8*CELL_SIZE, 100, 100};
    SDL_SetRenderDrawColor(renderer, black_color.r,black_color.g,black_color.b,black_color.a);
    


    while (quit == 0)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:      //Si on clique sur la croix, on quitte
                    quit = 1;
                    printf ("DEBUG : appui sur SDL_QUIT\n");
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


    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    
}