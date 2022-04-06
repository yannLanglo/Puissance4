/*! 
 *  \file main.c
 *  \author Yann Langlo <yann.langlo@cy-tech.fr>
 *  \version 0.1
 *  \date Mon Nov 22 2021
 *  \brief Fonction Principale
 */

#include "puissance4.h"

int main(int argc, char const *argv[])
{
    int ttint_plateau[N][N]; /* Plateau de jeu */

    /* Initialisation du plateau de jeu */
    init(ttint_plateau);
    /* On affiche le plateau de jeu */
    affichage(ttint_plateau);
    /* On lance le jeu */
    tourDeJeu(ttint_plateau);
    return 0;
}