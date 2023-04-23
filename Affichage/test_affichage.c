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

void updateCELLS(CASE plate[8][8], int x, int y, int round) // Fonction qui retourne les pions après un coup
{
    int player = 0;
    int opponent = 0;
    if (round % 2 == 1)
    {
        player = NOIR;
        opponent = BLANC;
    }
    if (round % 2 == 0)
    {
        player = BLANC;
        opponent = NOIR;
    }

    int tempx = 0;
    int tempy = 0;
    int foundPlayer = 0;

    // On teste sur l'axe X à gauche
    tempx = x - 1;
    foundPlayer = 0;
    while (tempx >= 0 && plate[tempx][y].pion == opponent)
    {
        tempx--;
        foundPlayer = 1;
    }
    if (tempx >= 0 && foundPlayer == 1 && plate[tempx][y].pion == player)
    {
        tempx = x - 1;
        while (tempx >= 0 && plate[tempx][y].pion  == opponent)
        {
            plate[tempx][y].pion  = player;
            tempx--;
        }
    }

    // On teste sur l'axe X à droite
    tempx = x + 1;
    foundPlayer = 0;
    while (tempx < 8 && plate[tempx][y].pion  == opponent)
    {
        tempx++;
        foundPlayer = 1;
    }
    if (tempx < 8 && foundPlayer == 1 && plate[tempx][y].pion  == player)
    {
        tempx = x + 1;
        while (tempx < 8 && plate[tempx][y].pion  == opponent)
        {
            plate[tempx][y].pion  = player;
            tempx++;
        }
    }

    // On teste sur l'axe Y en haut
    tempy = y - 1;
    foundPlayer = 0;
    while (tempy >= 0 && plate[x][tempy].pion  == opponent)
    {
        tempy--;
        foundPlayer = 1;
    }
    if (tempy >= 0 && foundPlayer == 1 && plate[x][tempy].pion  == player)
    {
        tempy = y - 1;
        while (tempy >= 0 && plate[x][tempy].pion  == opponent)
        {
            plate[x][tempy].pion  = player;
            tempy--;
        }
    }

    // On teste sur l'axe Y en bas
    tempy = y + 1;
    foundPlayer = 0;
    while (tempy < 8 && plate[x][tempy].pion  == opponent)
    {
        tempy++;
        foundPlayer = 1;
    }
    if (tempy < 8 && foundPlayer == 1 && plate[x][tempy].pion  == player)
    {
        tempy = y + 1;
        while (tempy < 8 && plate[x][tempy].pion  == opponent)
        {
            plate[x][tempy].pion  = player;
            tempy++;
        }
    }

    // On teste sur la diagonale haut-gauche
    tempx = x - 1;
    tempy = y - 1;
    foundPlayer = 0;
    while (tempx >= 0 && tempy >= 0 && plate[tempx][tempy].pion  == opponent)
    {
        tempx--;
        tempy--;
        foundPlayer = 1;
    }
    if (tempx >= 0 && tempy >= 0 && foundPlayer == 1 && plate[tempx][tempy].pion  == player)
    {
        tempx = x - 1;
        tempy = y - 1;
        while (tempx >= 0 && tempy >= 0 && plate[tempx][tempy].pion  == opponent)
        {
            plate[tempx][tempy].pion  = player;
            tempx--;
            tempy--;
        }
    }

    // On teste sur la diagonale haut-droite
    tempx = x - 1;
    tempy = y + 1;
    foundPlayer = 0;
    while (tempx >= 0 && tempy < 8 && plate[tempx][tempy].pion  == opponent)
    {
        tempx--;
        tempy++;
        foundPlayer = 1;
    }
    if (tempx >= 0 && tempy < 8 && foundPlayer == 1 && plate[tempx][tempy].pion  == player)
    {
        tempx = x - 1;
        tempy = y + 1;
        while (tempx >= 0 && tempy < 8 && plate[tempx][tempy].pion  == opponent)
        {
            plate[tempx][tempy].pion  = player;
            tempx--;
            tempy++;
        }
    }

    // On teste sur la diagonale bas-gauche
    tempx = x + 1;
    tempy = y - 1;
    foundPlayer = 0;
    while (tempx < 8 && tempy >= 0 && plate[tempx][tempy].pion  == opponent)
    {
        tempx++;
        tempy--;
        foundPlayer = 1;
    }
    if (tempx < 8 && tempy >= 0 && foundPlayer == 1 && plate[tempx][tempy].pion  == player)
    {
        tempx = x + 1;
        tempy = y - 1;
        while (tempx < 8 && tempy >= 0 && plate[tempx][tempy].pion  == opponent)
        {
            plate[tempx][tempy].pion  = player;
            tempx++;
            tempy--;
        }
    }

    // On teste sur la diagonale bas-droite
    tempx = x + 1;
    tempy = y + 1;
    foundPlayer = 0;
    while (tempx < 8 && tempy < 8 && plate[tempx][tempy].pion  == opponent)
    {
        tempx++;
        tempy++;
        foundPlayer = 1;
    }
    if (tempx < 8 && tempy < 8 && foundPlayer == 1 && plate[tempx][tempy].pion  == player)
    {
        tempx = x + 1;
        tempy = y + 1;
        while (tempx < 8 && tempy < 8 && plate[tempx][tempy].pion  == opponent)
        {
            plate[tempx][tempy].pion  = player;
            tempx++;
            tempy++;
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

