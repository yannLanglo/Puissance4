/*! \file puissance4.h
 *  \author Langlo Yann <langloyann@cy-tech.fr>
 *  \version 0.1
 *  \date Mon Nov 22 2021
 *  \brief Puissance 4
*/
#include "puissance4.h"

void init(int ttint_plateau[N][N])
{
    int i_i; /* Variable de boucle */
    int i_j; /* Variable de boucle */

    /* Parcours des lignes */
    for (i_i = 0; i_i < N; i_i++){
        /* Parcours des lignes */
        for (i_j = 0; i_j < N; i_j++){
            /* Initialisation du tableau */
            ttint_plateau[i_i][i_j] = -1;
        }
    }
}

void affichage(int ttint_plateau[N][N])
{
    int i_i; /* Variable de boucle */
    int i_j; /* Variable de boucle */

    /* Parcours des lignes */
    for (i_i = 0; i_i < N; i_i++){
        /* Parcours des colonnes */
        for (i_j = 0; i_j < N; i_j++){
            printf("|");
            /* Si la case parcourue est vide */
            if (ttint_plateau[i_i][i_j] == -1){
                /* On affiche un espace */
                printf("   ");
            /* Sinon si le premier joueur à rempli la case */
            }else if (ttint_plateau[i_i][i_j] == 1){
                /* On affiche une croix */
                printf(" X ");
            /* Sinon si le deuxième joueur à rempli la case */
            }else{
                /* On affiche un cercle */
                printf(" O ");
            }
        }
        printf("|");
        printf("\n");
    }  
    printf("  0   1   2   3   4   5  \n");
}

int saisieColonne(void)
{
    int i_colonne; /* Variable de retour */
    int scanretour; /* Valeur de vérification */

    /* Affichage de la requête */
    printf("Dans quelle colonne voulez-vous jouer ?\n");
    /* Initialisation de la valeur de vérification */
    scanretour = scanf("%d",&i_colonne);
    /* Vérification de la validité de la saisie */
    while(scanretour == 0 || i_colonne < 0 || i_colonne > N-1){
        /* Affichage d'un message d'erreur */
        printf("Colonne invalide. Veuillez choisir un chiffre entre 0,1 et 2.\n");
        /* Réinitialisation de la valeur de vérification */
        scanretour = scanf("%d",&i_colonne);
    }
    /* On retourne la colonne saisie par l'utilisateur */
    return(i_colonne);
}

int colonnePleine(int ttint_plateau[N][N], int i_colonne)
{
    int i_res; /* Valeur de retour */

    /* Initialisation de la valeur de retour à 0, la colonne n'est pas pleine */
    i_res = 0;
    /* Si la case la plus haute de la ligne est prise par un des deux joueurs*/
    if ((ttint_plateau[0][i_colonne] == 1) || (ttint_plateau[0][i_colonne] == 2)){
        /* La valeur de retour prend 1, la colonne est pleine */
        i_res = 1;
    }
    return(i_res);
}

int gagneLigne(int ttint_plateau[N][N])
{
    int i_res; /* Valeur de retour */
    int i_i; /* Valeur de boucle correspondant aux lignes */
    int i_j; /* Valeur de boucle correspondant aux colonnes */

    /* Initialisation de la valeur de retour */
    i_res = 0;
    /* Initialisation des colonnes à 0 */
    i_j = 0;

    /* Parcours des lignes */
    for (i_i = 0; i_i < N; i_i++){
        /* Initialisation du compteur à 1 */
        /* Tant que personne n'a gagné et que la colonne parcourue est dans le tableau */
        while((i_res == 0) && (i_j < N-3)){
            /* On vérifie la case parcourue est occupée par un joueur et et si les cases suivantes sont occupées par le même joueur */
            if ((ttint_plateau[i_i][i_j] != -1) && (ttint_plateau[i_i][i_j] == ttint_plateau[i_i][i_j+1]) && (ttint_plateau[i_i][i_j+1] == ttint_plateau[i_i][i_j+2]) && (ttint_plateau[i_i][i_j+2] == ttint_plateau[i_i][i_j+3])){
                /* Si oui, on met la valeur de retour à 1 */
                i_res = 1;
            }
            /* On passe à la colonne suivante */
            i_j++;
        }
        /* On remet la colonne à 0 après le parcours d'une ligne non concluant */
        i_j = 0;
    }
    /* On retourne 0 si personne n'a gagné en ligne, 1 sinon */
    return(i_res);
}

int gagneColonne(int ttint_plateau[N][N])
{
    int i_res; /* Valeur de retour */
    int i_i; /* Valeur de boucle correspondant aux lignes */
    int i_j; /* Valeur de boucle correspondant aux colonnes */

    /* Initialisation de la valeur de retour */
    i_res = 0;
    /* Initialisation des lignes à 0 */
    i_i = 0;
    
    /* Parcours des colonnes */
    for (i_j = 0; i_j < N; i_j++){
        /* Tant que personne n'a gagné et que la ligne parcourue est dans le tableau */
        while ((i_res == 0) && (i_i < N-3)){
            /* On vérifie la case parcourue est occupée par un joueur et si les cases suivantes sont occupées par le même joueur */
            if ((ttint_plateau[i_i][i_j] != -1) && (ttint_plateau[i_i][i_j] == ttint_plateau[i_i+1][i_j]) && (ttint_plateau[i_i+1][i_j] == ttint_plateau[i_i+2][i_j]) && (ttint_plateau[i_i+2][i_j] == ttint_plateau[i_i+3][i_j])){
                /* Si oui, on met la valeur de retour à 1 */
                i_res = 1;
            }
            /* On passe à la ligne suivante */
            i_i++;
        }
        /* On remet la ligne à 0 après le parcours d'une colonne non concluant */
        i_i = 0;
    }
    /* On retourne 0 si personne n'a gagné en colonne, 1 sinon */
    return(i_res);
}

int gagneDiago1(int ttint_plateau[N][N])
{
    int i_res; /* Valeur de retour */
    int i_i; /* Valeur de boucle correspondant aux lignes */
    int i_j; /* Valeur de boucle correspondant aux colonnes */

    /* Initialisation de la valeur de retour */
    i_res = 0;
    i_i = N-1;

    /* Parcours des colonnes */
    for (i_j = 0; i_j < N-3; i_j++){
        /* Tant que personne n'a gagné et que la ligne parcourue est dans le tableau */
        while ((i_res == 0) && (i_i > 1)){
            /* On vérifie la case parcourue est occupée par un joueur et si les cases suivantes sont occupées par le même joueur */
            if ((ttint_plateau[i_i][i_j] != -1) && (ttint_plateau[i_i][i_j] == ttint_plateau[i_i-1][i_j+1]) && (ttint_plateau[i_i-1][i_j+1] == ttint_plateau[i_i-2][i_j+2]) && (ttint_plateau[i_i-2][i_j+2] == ttint_plateau[i_i-3][i_j+3])){
                /* Si oui, on met la valeur de retour à 1 */
                i_res = 1;
            }
            /* On passe à la ligne du dessus */
            i_i--;
        }
        /* On repasse à la ligne du bas */
        i_i = N-1;
    }
    /* On retourne 0 si personne n'a gagné en colonne, 1 sinon */
    return(i_res);
}

int gagneDiago2(int ttint_plateau[N][N])
{
    int i_res; /* Valeur de retour */
    int i_i; /* Valeur de boucle correspondant aux lignes */
    int i_j; /* Valeur de boucle correspondant aux colonnes */

    /* Initialisation de la valeur de retour */
    i_res = 0;
    i_i = N-1;

    /* Parcours des colonnes */
    for (i_j = N-1; i_j > 2; i_j--){
        /* Tant que personne n'a gagné et que la ligne parcourue est dans le tableau */
        while ((i_res == 0) && (i_i > 1)){
            /* On vérifie la case parcourue est occupée par un joueur et si les cases suivantes sont occupées par le même joueur */
            if ((ttint_plateau[i_i][i_j] != -1) && (ttint_plateau[i_i][i_j] == ttint_plateau[i_i-1][i_j-1]) && (ttint_plateau[i_i-1][i_j-1] == ttint_plateau[i_i-2][i_j-2]) && (ttint_plateau[i_i-2][i_j-2] == ttint_plateau[i_i-3][i_j-3])){
                /* Si oui, on met la valeur de retour à 1 */
                i_res = 1;
            }
            /* On passe à la ligne du dessus */
            i_i--;
        }
        /* On repasse à la ligne du bas */
        i_i = N-1;
    }
    /* On retourne 0 si personne n'a gagné en colonne, 1 sinon */
    return(i_res);
}

int aGagne(int ttint_plateau[N][N])
{
    int i_res1; /* Valeur de retour de la fonction gagneLigne */
    int i_res2; /* Valeur de retour de la fonction gagneColonne */
    int i_res3; /* Valeur de retour de la fonction gagneLigne */
    int i_res4; /* Valeur de retour de la fonction gagneColonne */
    int i_resFinal; /* Valeur de retour de la fonction aGagne */

    /* i_res1 prend la valeur de retour de la fonction gagneLigne */
    i_res1 = gagneLigne(ttint_plateau);
    /* i_res1 prend la valeur de retour de la fonction gagneColonne */
    i_res2 = gagneColonne(ttint_plateau);
    /* i_res1 prend la valeur de retour de la fonction gagneLigne */
    i_res3 = gagneDiago1(ttint_plateau);
    /* i_res1 prend la valeur de retour de la fonction gagneColonne */
    i_res4 = gagneDiago2(ttint_plateau);
    /* Personne n'a gagné */
    i_resFinal = 0;
    /* Si une des fonctions de vérification de victoire renvoie une réponse positive */
    if ((i_res1 == 1) || (i_res2 == 1) || (i_res3 == 1) || (i_res4 == 1)){
        /* Alors quelqu'un a gagné */
        i_resFinal = 1;
    }
    /* Renvoie 0 si personne n'a gagné et 1 sinon */
    return(i_resFinal);
}

void placerCoup(int ttint_plateau[N][N], int i_joueur, int i_colonne)
{
    int i_i; /* Variable correspondant à la ligne */

    /* Initialisation de la ligne à celle du bas du plateau */
    i_i = N-1;
    /* Tant que la case parcourue n'est pas vide et qu'on est pas arrivé en haut du tableau */
    while ((ttint_plateau[i_i][i_colonne] != -1) && (i_i >= 0)){
        /* On passe à la ligne du dessus */
        i_i--;
    }
    /* On place le coup demandé par le joueur qui vient de jouer */
    ttint_plateau[i_i][i_colonne] = i_joueur;
}

void jouer(int ttint_plateau[N][N], int i_joueur, int i_colonne)
{
    int i_plein; /* Valeur de retour de la fonction occupee */

    /* Appel de la fonction colonnePleine */
    i_plein = colonnePleine(ttint_plateau,i_colonne);
    /* Tant que la colonne choisie par l'utilisateur est déjà pleine */
    while (i_plein == 1){
        /* On affiche un message d'erreur */
        printf("La colonne est pleine. Veuillez en choisir une autre.\n");
        /* L'utilisateur doit saisir une nouvelle valeur de colonne */
        i_colonne = saisieColonne();
        /* Appel de la fonction colonnePleine */
        i_plein = colonnePleine(ttint_plateau,i_colonne);
    }
    /* On place le coup */
    placerCoup(ttint_plateau,i_joueur,i_colonne);
}

void tourDeJeu(int ttint_plateau[N][N])
{
    int i_matchnul; /* Variable correspondant au nombre de coups joués et permettant de vérifier si un match est nul */
    int i_gagne; /* Variable permettant de vérifier si un joueur a gagné */
    int i_joueur; /* Variable correspondant au numéro du joueur */
    int i_colonne; /* Variable correspondant à la colonne choisie par l'utilisateur */

    /* C'est au premir joueur de commencer */
    i_joueur = 1;
    /* Personne n'a encore gagné */
    i_gagne = 0;
    /* Aucun coup n'est joué */
    i_matchnul = 0;
    /* Tant que personne n'a gagné et que le plateau n'est pas complet */
    while ((i_gagne != 1) && (i_matchnul != N*N)){
        /* On clear le systeme */
        system("clear");
        /* On affiche le plateau */
        affichage(ttint_plateau);
        /* On affiche qui doit jouer */
        printf("Joueur %d, à vous de jouer.\n",i_joueur);
        /* On lui demande dans quelle colonne jouer */
        i_colonne = saisieColonne();
        /* On place le coup du joueur après vérification */
        jouer(ttint_plateau,i_joueur,i_colonne);
        /* On affiche le plateau */
        affichage(ttint_plateau);
        /* On vérifie si le joueur a gagné */
        i_gagne = aGagne(ttint_plateau);
        /* On incrémente le nombre de coups joués */
        i_matchnul++;
        /* On passe au joueur suivant */
        i_joueur = (i_joueur % 2) + 1;
    }
    if (i_gagne == 1){
        /* On repasse au joueur précédent car c'est le dernier à avoir joué */
        i_joueur = (i_joueur % 2) + 1;
        /* On affiche un message de victoire */
        printf("Le joueur %d a gagné.\n",i_joueur);
    /* Sinon si le plateau est complet*/
    }else if (i_matchnul == N*N){
        /* On affiche un message de match nul */
        printf("MATCH NUL.\n");
    }

}






