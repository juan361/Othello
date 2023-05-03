#include "affichage.h"
#include "../Jeu/jeu.h"



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

void drawCARE(SDL_Renderer *renderer, int x, int y, int LONG, SDL_Color color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_Rect rect = {x, y, LONG, LONG};
    SDL_RenderFillRect(renderer, &rect); 

}

int gameStart(SDL_Window *window,SDL_Renderer *renderer,SDL_Event event ,TTF_Font* font)
{
    int quit = 0;

    int round = 1;
    int clicX = NULL;
    int clicY = NULL;

    int clicTabX = NULL;
    int clicTabY = NULL;

    int* counterBlack=0 ;
    int* counterWhite =0;
    char counterTextW[10];
    char counterTextB[10];
    char roundText[10];

    int* cpt = 0;
    int win =0;

    // variable des différentes couleurs
    SDL_Color background_color = {83,147,120,255};          //Couleur de fond
    SDL_Color black_color = {0,0,0,255};                    //Couleur noir
    SDL_Color white_color = {255,255,255,255};              //Couleur blanc
    SDL_Color potential_color = {127,127,127,255};          //Couleur gris

    CASE plate[8][8];     //On crée le plateau de jeu
    
    initCell(plate);

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
                    return 1;
                    break;
                case SDL_KEYDOWN:   //Si on appuie sur une touche, on teste laquelle
                    if (event.key.keysym.sym == SDLK_q)
                    {
                        quit = 1;
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
                                printf("DEBUG : round (%d)\n", round);
                            }
                        }
                    }
                    break;
                default:
                    break;
            }
        }

        possibility(plate,playerColor(round),advColor(playerColor(round)));
        round=checkPlayable( plate, round, cpt);
        check(plate, plate[clicTabX/CELL_SIZE][clicTabY/CELL_SIZE]);

        //mettre la fonction de save

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
        counterBlack = cptCaseColor(plate,NOIR);
        counterWhite = cptCaseColor(plate,BLANC);
        //printf("%d\n",counterBlack);

        sprintf(counterTextB, "%d", counterBlack);
        sprintf(counterTextW, "%d", counterWhite);
        sprintf(roundText, "round :%d", round);
        drawCARE(renderer,700,40,200,background_color);
        afficherTexte(renderer,counterTextB,700,40,font,black_color);
        afficherTexte(renderer,counterTextW,800,40,font,white_color);
        afficherTexte(renderer,roundText,750,100,font,black_color);
       //loadImg(renderer, 800, 500);
        
        
        SDL_RenderPresent(renderer);    // On met a jours le render
        
        win = checkWinGame(plate, cpt);
        if (win == 1)
            printf("les blancs ont gagné\n");
        else if (win == 2)
            printf("les noirs ont gagné\n");
        SDL_RenderPresent(renderer);
    }
}

void afficherTexte(SDL_Renderer* renderer, const char* texte, int x, int y, TTF_Font* font, SDL_Color color) {
    // Rendre le texte en surface
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, texte, color);
    if (!textSurface) {
        printf("Erreur lors de la création de la surface du texte : %s\n", TTF_GetError());
        return;
    }

    // Créer une texture à partir de la surface
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if (!textTexture) {
        printf("Erreur lors de la création de la texture du texte : %s\n", SDL_GetError());
        SDL_FreeSurface(textSurface);
        return;
    }

    // Obtenir la taille du texte rendu
    int textWidth = textSurface->w;
    int textHeight = textSurface->h;

    // Libérer la surface du texte
    SDL_FreeSurface(textSurface);

    // Configurer la position et la taille du texte dans le rendu
    SDL_Rect textRect;
    textRect.x = x;
    textRect.y = y;
    textRect.w = textWidth;
    textRect.h = textHeight;

    // Afficher le texte dans le rendu
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);

    // Libérer la texture du texte
    SDL_DestroyTexture(textTexture);
}

void chargerEtAfficherImage(SDL_Renderer* renderer, const char* imagePath, int x, int y) {
    // Charger l'image à partir du fichier
    SDL_Surface* image = IMG_Load(imagePath);
    if (!image) {
        printf("Erreur de chargement de l'image : %s\n", IMG_GetError());
        return;
    }

    // Convertir l'image en texture
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
    if (!texture) {
        printf("Erreur de création de la texture : %s\n", SDL_GetError());
        SDL_FreeSurface(image);
        return;
    }

    // Obtenir les dimensions de l'image
    int largeurImage = image->w;
    int hauteurImage = image->h;

    // Dessiner la texture sur le renderer
    SDL_Rect destRect = { x, y, largeurImage, hauteurImage };
    SDL_RenderCopy(renderer, texture, NULL, &destRect);

    // Libérer la mémoire allouée
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(image);
}

