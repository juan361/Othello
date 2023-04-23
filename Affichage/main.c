#include "affichage.h"


int main(int argc, char *argv[])
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Event event;                                        //Variables pour les interractions

    int quit = 0;
    int round = 1;
    int clicX = NULL;
    int clicY = NULL;

    int clicTabX = NULL;
    int clicTabY = NULL;

    int cpt = 0;
    int win =0;
    
    // variable des différentes couleurs
    SDL_Color background_color = {83,147,120,255};          //Couleur de fond
    SDL_Color black_color = {0,0,0,255};                    //Couleur noir
    SDL_Color white_color = {255,255,255,255};              //Couleur blanc
    SDL_Color potential_color = {127,127,127,255};          //Couleur gris

    CASE plate[8][8];     //On crée le plateau de jeu
    
    initCell(plate);

    if (SDL_Init(SDL_INIT_VIDEO) != 0)      //On initialise SDL, on quitte si erreur(s)
    {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        quit = 1;
    }

    window = SDL_CreateWindow("Grille de 64 cases", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 8*CELL_SIZE+300, 8*CELL_SIZE, SDL_WINDOW_SHOWN);//On crée la fenêtre
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

                        //printf("DEBUG : clic gauche détecté à la position (%d, %d)\n", clicX, clicY);
                        //printf("DEBUG : clic gauche détecté à la position (%d, %d)\n", clicX/CELL_SIZE, clicY/CELL_SIZE);
                        if (clicX < 8*CELL_SIZE)
                        {
                            if (plate[clicX/CELL_SIZE][clicY/CELL_SIZE].pion==POTENTIEL)
                            {
                                if (round%2 == 1)
                                        plate[clicX/CELL_SIZE][clicY/CELL_SIZE].pion=NOIR;
                                if (round%2 == 0)
                                        plate[clicX/CELL_SIZE][clicY/CELL_SIZE].pion=BLANC;
                                clicTabX=clicX;
                                clicTabY=clicY;
                                round ++;
                            }
                        }
                    }
                    break;
                default:
                    break;
            }
        }
        initRound(plate);
        possibility(plate,playerColor(round),advColor(playerColor(round)));
        round=checkPlayable( plate, round, cpt);
        for (int i = 0; i < 8; i++)             //On parcours le tableau plate pour afficher les pions
        {
            for (int j = 0; j < 8; j++)
            {
                if (plate[i][j].pion == BLANC)
                    drawPAWN(renderer, CELL_SIZE/2 + i*CELL_SIZE, CELL_SIZE/2 + j*CELL_SIZE, PAWN_RADIUS, white_color);
                if (plate[i][j].pion == NOIR)
                    drawPAWN(renderer, CELL_SIZE/2 + i*CELL_SIZE, CELL_SIZE/2 + j*CELL_SIZE, PAWN_RADIUS, black_color);
                if (plate[i][j].pion == POTENTIEL)
                    drawPAWN(renderer, CELL_SIZE/2 + i*CELL_SIZE, CELL_SIZE/2 + j*CELL_SIZE, POTENTIAL_PAWN_RADIUS, potential_color);
                if (plate[i][j].pion == VIDE)
                    drawCARE(renderer, i*CELL_SIZE+1, j*CELL_SIZE+1, CELL_SIZE-1, background_color);
            }
        }
        SDL_RenderPresent(renderer);    // On met a jours le render
        check(plate, plate[clicTabX/CELL_SIZE][clicTabY/CELL_SIZE]);
        win = checkWinGame(plate, cpt);
        if (win == 1)
            printf("les blancs ont gagné\n");
        else if (win == 2)
            printf("les noirs ont gagné\n");
        SDL_RenderPresent(renderer);
    }


    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    
}