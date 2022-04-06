/*! \file puissance4.h
 *	\author Langlo Yann <langloyann@cy-tech.fr>
 *	\version 0.1
 *	\date Tue Nov 30 2021
*/

/* Vérification de la présence de la variable TP4 */
#ifndef __PUISSANCE4_H_
/* Si non présente on la définit et on l'inclut dans le fichier */
#define __PUISSANCE4_H_
/* Déclaration de la constante symbolique N à 20 */
#define N 6

/* Inclusion des bibliothèques */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

/*! \fn void init(int ttint_plateau[N][N])
 *  \author Yann Langlo <yann.langlo@cy-tech.fr>
 *  \version 0.1
 *  \date Sat Dec 04 2021
 *
 *  \brief Initialise les valeurs du plateau
 *
 *  \param ttint_plateau : Plateau de jeu 
 * 
 * \remarks 
 */
void init(int ttint_plateau[N][N]);

/*! \fn void affichage(int ttint_plateau[N][N])
 *  \author Yann Langlo <yann.langlo@cy-tech.fr>
 *  \version 0.1
 *  \date Sat Dec 04 2021
 *
 *  \brief Affiche le plateau
 *
 *  \param ttint_plateau : Plateau de jeu 
 * 
 * \remarks 
 */
void affichage(int ttint_plateau[N][N]);

/*! \fn int saisieEntier(void)
 *  \author Yann Langlo <yann.langlo@cy-tech.fr>
 *  \version 0.1
 *  \date Sat Dec 04 2021
 *
 *  \brief Permet à l'utilisateur de choisir la colonne dans laquelle il souhaite jouer
 *
 *  \return i_colonne : Valeur de la colonne saisie par l'utilisateur
 * 
 * \remarks 
 */
int saisieColonne(void);

/*! \fn int saisieEntier(void)
 *  \author Yann Langlo <yann.langlo@cy-tech.fr>
 *  \version 0.1
 *  \date Sat Dec 04 2021
 *
 *  \brief Permet de vérifier si la colonne choisie est pleine ou pas
 *
 *  \param ttint_plateau : Plateau de jeu 
 *         i_colonne : Colonne choisie par le joueur
 * 
 *  \return i_res : 0 si la colonne n'est pas pleine, 1 sinon
 * 
 * \remarks 
 */
int colonnePleine(int ttint_plateau[N][N], int i_colonne);

/*! \fn int gagneLigne(int ttint_plateau[N][N])
 *  \author Yann Langlo <yann.langlo@cy-tech.fr>
 *  \version 0.1
 *  \date Sat Dec 04 2021
 *
 *  \brief Permet de vérifier si un joueur a gagné en ligne
 * 
 *  \param ttint_plateau : Plateau de jeu 
 *
 *  \return i_res : 0 si personne n'a gagné en ligne, 1 sinon
 * 
 * \remarks 
 */
int gagneLigne(int ttint_plateau[N][N]);

/*! \fn int gagneColonne(int ttint_plateau[N][N])
 *  \author Yann Langlo <yann.langlo@cy-tech.fr>
 *  \version 0.1
 *  \date Mon Dec 06 2021
 *
 *  \brief Permet de vérifier si un joueur a gagné en colonne
 * 
 *  \param ttint_plateau : Plateau de jeu 
 * 
 *  \return i_res : 0 si personne n'a gagné en colonne, 1 sinon
 * 
 * \remarks 
 */
int gagneColonne(int ttint_plateau[N][N]);

/*! \fn int gagneDiago1(int ttint_plateau[N][N])
 *  \author Yann Langlo <yann.langlo@cy-tech.fr>
 *  \version 0.1
 *  \date Mon Dec 06 2021
 *
 *  \brief Permet de vérifier si un joueur a gagné en diagonale ascendante vers la droite
 * 
 *  \param ttint_plateau : Plateau de jeu 
 * 
 *  \return i_res : 0 si personne n'a gagné en diagonale ascendante vers la droite, 1 sinon
 * 
 * \remarks 
 */
int gagneDiago1(int ttint_plateau[N][N]);

/*! \fn int gagneDiago2(int ttint_plateau[N][N])
 *  \author Yann Langlo <yann.langlo@cy-tech.fr>
 *  \version 0.1
 *  \date Mon Dec 06 2021
 *
 *  \brief Permet de vérifier si un joueur a gagné en diagonale ascendante vers la gauche
 * 
 *  \param ttint_plateau : Plateau de jeu 
 * 
 *  \return i_res : 0 si personne n'a gagné en diagonale ascendante vers la gauche, 1 sinon
 * 
 * \remarks 
 */
int gagneDiago2(int ttint_plateau[N][N]);

/*! \fn int aGagne(int ttint_plateau[N][N])
 *  \author Yann Langlo <yann.langlo@cy-tech.fr>
 *  \version 0.1
 *  \date Mon Dec 06 2021
 *
 *  \brief Permet de vérifier si un joueur a gagné
 *
 *  \param ttint_plateau : Plateau de jeu 
 * 
 *  \return i_res : 0 si personne n'a gagné, 1 sinon
 *  
 * \remarks 
 */
int aGagne(int ttint_plateau[N][N]);

/*! \fn int aGagne(int ttint_plateau[N][N])
 *  \author Yann Langlo <yann.langlo@cy-tech.fr>
 *  \version 0.1
 *  \date Mon Dec 06 2021
 *
 *  \brief Permet au joueur de placer un coup
 * 
 *  \param ttint_plateau : Plateau de jeu 
 *         i_joueur : numéro du joueur qui joue
 *         i_colonne : colonne choisie par le joueur
 * 
 * \remarks 
 */
void placerCoup(int ttint_plateau[N][N], int i_joueur, int i_colonne);

/*! \fn void tourDeJeu(int ttint_plateau[N][N])
 *  \author Yann Langlo <yann.langlo@cy-tech.fr>
 *  \version 0.1
 *  \date Mon Dec 06 2021
 *
 *  \brief Procédure pour jouer
 *
 *  \param ttint_plateau : Plateau de jeu 
 *   
 *  \remarks 
 */
void tourDeJeu(int ttint_plateau[N][N]);



#endif