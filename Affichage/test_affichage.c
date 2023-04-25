#include "affichage.h"

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

void initCell(CASE plate [8][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            plate[i][j].pion = VIDE;
            plate[i][j].posX= i;
            plate[i][j].posY= j;
        }
    }
    plate[3][3].pion = BLANC;        //On place les 4 pions de départ
    plate[4][4].pion = BLANC;
    plate[3][4].pion = NOIR;
    plate[4][3].pion = NOIR;
}


int playerColor (int round)
{
    int couleurJoueur;
    if (round%2 == 1)
        couleurJoueur = BLANC;
    if (round%2 == 0)
        couleurJoueur = NOIR;
    return(couleurJoueur);   
}

/*donne la couleur adverse*/
int advColor (int couleurJoueur)
{
    int advColor;
    if (couleurJoueur == NOIR)
        advColor = BLANC;
    if (couleurJoueur == BLANC)
        advColor = NOIR;
    return (advColor);
}


void possibility(CASE plateau[8][8], CELL couleurJoueur, CELL couleurAdv)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (plateau[j][i].pion == POTENTIEL)
            {
                plateau[j][i].pion = VIDE;
            }
            if (plateau[j][i].pion == VIDE)
            {
                if (j < 7 && plateau[j + 1][i].pion == couleurJoueur)
                {

                    int jj = j + 1;
                    while (jj < 8 && plateau[jj][i].pion == couleurJoueur)
                    {
                        jj++;
                    }
                    if (jj < 8 && plateau[jj][i].pion == couleurAdv)
                    {
                        plateau[j][i].pion = POTENTIEL;
                    }
                }
                if (i < 7 && plateau[j][i + 1].pion == couleurJoueur)
                {
                    int ii = i + 1;
                    while (ii < 8 && plateau[j][ii].pion == couleurJoueur)
                    {
                        ii++;
                    }
                    if (ii < 8 && plateau[j][ii].pion == couleurAdv)
                    {
                        plateau[j][i].pion = POTENTIEL;
                    }
                }
                if (j > 0 && plateau[j - 1][i].pion == couleurJoueur)
                {
                    int jj = j - 1;
                    while (jj >= 0 && plateau[jj][i].pion == couleurJoueur)
                    {
                        jj--;
                    }
                    if (jj >= 0 && plateau[jj][i].pion == couleurAdv)
                    {
                        plateau[j][i].pion = POTENTIEL;
                    }
                }
                if (i > 0 && plateau[j][i - 1].pion == couleurJoueur)
                {
                    int ii = i - 1;
                    while (ii >= 0 && plateau[j][ii].pion == couleurJoueur)
                    {
                        ii--;
                    }
                    if (ii >= 0 && plateau[j][ii].pion == couleurAdv)
                    {
                        plateau[j][i].pion = POTENTIEL;
                    }
                }
                // En haut à gauche :
                if (j > 0 && i > 0 && plateau[j - 1][i - 1].pion == couleurJoueur)
                {
                    int jj = j - 1;
                    int ii = i - 1;
                    while (jj >= 0 && ii >= 0 && plateau[jj][ii].pion == couleurJoueur)
                    {
                        jj--;
                        ii--;
                    }
                    if (jj >= 0 && ii >= 0 && plateau[jj][ii].pion == couleurAdv)
                    {
                        plateau[j][i].pion = POTENTIEL;
                    }
                }
                // En haut à droite :
                if (j < 7 && i > 0 && plateau[j + 1][i - 1].pion == couleurJoueur)
                {
                    int jj = j + 1;
                    int ii = i - 1;
                    while (jj < 8 && ii >= 0 && plateau[jj][ii].pion == couleurJoueur)
                    {
                        jj++;
                        ii--;
                    }
                    if (jj < 8 && ii >= 0 && plateau[jj][ii].pion == couleurAdv)
                    {
                        plateau[j][i].pion = POTENTIEL;
                    }
                }
                // En bas à gauche :
                if (j > 0 && i < 7 && plateau[j - 1][i + 1].pion == couleurJoueur)
                {
                    int jj = j - 1;
                    int ii = i + 1;
                    while (jj >= 0 && ii < 8 && plateau[jj][ii].pion == couleurJoueur)
                    {
                        jj--;
                        ii++;
                    }
                    if (jj >= 0 && ii < 8 && plateau[jj][ii].pion == couleurAdv)
                    {
                        plateau[j][i].pion = POTENTIEL;
                    }
                }
                // En bas à droite :
                if (j < 7 && i < 7 && plateau[j + 1][i + 1].pion == couleurJoueur)
                {
                    int jj = j + 1;
                    int ii = i + 1;
                    while (jj < 8 && ii < 8 && plateau[jj][ii].pion == couleurJoueur)
                    {
                        jj++;
                        ii++;
                    }
                    if (jj < 8 && ii < 8 && plateau[jj][ii].pion == couleurAdv)
                    {
                        plateau[j][i].pion = POTENTIEL;
                    }
                }
            }
        }
    }
}

void check(CASE plateau[8][8], CASE maCase)
{
    // Check à GAUCHE du pion
    for (int i = (maCase.posX - 1); i >= 0; i--)
    {
        // Si t'a un trou
        if (plateau[i][maCase.posY].pion == VIDE || plateau[i][maCase.posY].pion == POTENTIEL)
            break;

        // Si il trouve un pion de la même couleur
        if (plateau[i][maCase.posY].pion == maCase.pion)
        {
            // Remplace tous les pions entre par la même couleur
            for (int j = i; j < maCase.posX; j++)
                plateau[j][maCase.posY].pion = maCase.pion;

            break;
        }
    }
    // Check à DROITE du pion
    for (int i = (maCase.posX + 1); i <= 7; i++)
    {                            
        // Si t'a un trou
        if (plateau[i][maCase.posY].pion == VIDE || plateau[i][maCase.posY].pion == POTENTIEL)
            break;

        // Si il trouve un pion de la même couleur
        if (plateau[i][maCase.posY].pion == maCase.pion)
        {
            // Remplace tous les pions entre par la même couleur
            for (int j = i; j > maCase.posX; j--)
                plateau[j][maCase.posY].pion = maCase.pion;
            break;
        }
    }

    // Check en BAS du pion
    for (int i = (maCase.posY + 1); i <= 7; i++)
    {
        // Si t'a un trou
        if (plateau[maCase.posX][i].pion == VIDE || plateau[maCase.posX][i].pion == POTENTIEL)
            break;

        // Si il trouve un pion de la même couleur
        if (plateau[maCase.posX][i].pion == maCase.pion)
        {
            // Remplace tous les pions entre par la même couleur
            for (int j = i; j > maCase.posY; j--)
                plateau[maCase.posX][j].pion = maCase.pion;
            break;
        }
    }
    // Check en HAUT du pion
    for (int i = (maCase.posY - 1); i >= 0; i--)
    {
        // Si t'a un trou
        if (plateau[maCase.posX][i].pion == VIDE || plateau[maCase.posX][i].pion == POTENTIEL)
            break;

        // Si il trouve un pion de la même couleur
        if (plateau[maCase.posX][i].pion == maCase.pion)
        {
            // Remplace tous les pions entre par la même couleur
            for (int j = i; j < maCase.posY; j++)
                plateau[maCase.posX][j].pion = maCase.pion;
            break;
        }
    }

    // Check en haut à gauche
    for (int i = maCase.posX - 1, j = maCase.posY - 1; i >= 0 && j >= 0; i--, j--)
    {
        // Si t'a un trou
        if (plateau[i][j].pion == VIDE || plateau[i][j].pion == POTENTIEL)
            break;

        // Si il trouve un pion de la même couleur
        if (plateau[i][j].pion == maCase.pion)
        {
            // Remplace tous les pions entre par la même couleur
            for (int k = i, l = j; k < maCase.posX && l < maCase.posY; k++, l++)
                plateau[k][l].pion = maCase.pion;
            break;
        }
    }

    // Check en haut à droite
    for (int i = maCase.posX - 1, j = maCase.posY + 1; i >= 0 && j <= 7; i--, j++)
    {
        // Si t'a un trou
        if (plateau[i][j].pion == VIDE || plateau[i][j].pion == POTENTIEL)
            break;

        // Si il trouve un pion de la même couleur
        if (plateau[i][j].pion == maCase.pion)
        {
            // Remplace tous les pions entre par la même couleur
            for (int k = i, l = j; k < maCase.posX && l > maCase.posY; k++, l--)
                plateau[k][l].pion = maCase.pion;
            break;
        }
    }

    // Check en bas à gauche
    for (int i = maCase.posX + 1, j = maCase.posY - 1; i <= 7 && j >= 0; i++, j--)
    {
        // Si t'a un trou
        if (plateau[i][j].pion == VIDE || plateau[i][j].pion == POTENTIEL)
            break;

        // Si il trouve un pion de la même couleur
        if (plateau[i][j].pion == maCase.pion)
        {
            // Remplace tous les pions entre par la même couleur
            for (int k = i, l = j; k > maCase.posX && l < maCase.posY; k--, l++)
                plateau[k][l].pion = maCase.pion;
            break;
        }
    }

    // Check en bas à droite
    for (int i = maCase.posX + 1, j = maCase.posY + 1; i <= 7 && j <= 7; i++, j++)
    {
        // Si t'a un trou
        if (plateau[i][j].pion == VIDE || plateau[i][j].pion == POTENTIEL)
            break;

        // Si il trouve un pion de la même couleur
        if (plateau[i][j].pion == maCase.pion)
        {
            // Remplace tous les pions entre par la même couleur
            for (int k = i, l = j; k > maCase.posX && l > maCase.posY; k--, l--)
                plateau[k][l].pion = maCase.pion;
            break;
        }
    }
}


void drawCARE(SDL_Renderer *renderer, int x, int y, int LONG, SDL_Color color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_Rect rect = {x, y, LONG, LONG};
    SDL_RenderFillRect(renderer, &rect); 

}

void initRound(CASE plateau[8][8])
{
    for (int i = 0; i < 8; i++)             //On parcours le tableau plate pour afficher les pions
        {
            for (int j = 0; j < 8; j++)
            {
                if (plateau[i][j].pion == POTENTIEL)
                    plateau[i][j].pion = VIDE;
            }
        }
}

int checkPlayable(CASE plateau[8][8], int round,int * cptSkipTurn)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (plateau[i][j].pion==POTENTIEL)
            {
                cptSkipTurn = 0;
                return(round);
            }
            else 
            {
                cptSkipTurn++;
                return(round++);
            }
        }
    }
}

int checkWinGame(CASE plateau[8][8], int cptSkipTurn)
{
    int cptVide = 0;
    int cptNoir= 0;
    int cptBlanc= 0;
    if (cptSkipTurn == 2)   //check si personne ne peux jouer (2 tours skip)
            return(cptCase (plateau));
    for (int i = 0; i < 8; i++)     
    {
        for (int j = 0; j < 8; j++)
        {
            if(plateau[i][j].pion == VIDE)  //check si le pleteau est plein
                cptVide++;
            if (plateau[i][j].pion == NOIR) 
                cptNoir++;
            if (plateau[i][j].pion == BLANC)
                cptBlanc++;
        }
    }
    if (cptVide == 0)
        return(cptCase (plateau));
    if (cptBlanc == 0)      //check si les blanc ont été éliminé
        return(2);      //return 2 -> victoire Noire
    if (cptNoir == 0)       //check si les noirs ont été éliminé
        return(1);      // return 1 -> victoire blanche
    else
        return(0);
}

int cptCase (CASE plateau[8][8])
{
    int caseNoir = 0;
    int caseBlanche = 0;
    for (int i = 0; i < 8; i++)     
    {
        for (int j = 0; j < 8; j++)
        {
            if (plateau[i][j].pion ==BLANC )
                caseBlanche++;
            else if (plateau[i][j].pion ==NOIR )
                caseNoir++;
        }
    }
    if (caseBlanche > caseNoir)
        return(1);
    else
        return(2);
}

int cptCaseColor (CASE plateau[8][8],int Color)
{
    int caseNoir = 0;
    int caseBlanche = 0;
    for (int i = 0; i < 8; i++)     
    {
        for (int j = 0; j < 8; j++)
        {
            if (plateau[i][j].pion ==BLANC )
                caseBlanche++;
            else if (plateau[i][j].pion ==NOIR )
                caseNoir++;
        }
    }
    if (Color == BLANC)
        return(caseBlanche);
    else if (Color == NOIR)
        return(caseNoir);
}

void gameStart(SDL_Window *window,SDL_Renderer *renderer,SDL_Event event ,TTF_Font* font)
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

    int cpt = 0;
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
                                printf("DEBUG : round (%d)\n", round);
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
       

        SDL_RenderPresent(renderer);    // On met a jours le render
        check(plate, plate[clicTabX/CELL_SIZE][clicTabY/CELL_SIZE]);
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