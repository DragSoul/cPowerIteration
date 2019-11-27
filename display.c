/**
 * \file display.c
 * \author Aurelien DOUARD, Anthony Bertrand
 * \brief Programme pour l'affichage de matrice carré et vecteur de résultat
 * \version 0.1
 * \date 11 novembre 2019
 *
 * Programme pour l'affichage de matrice carré et vecteur de résultat
 *
 */

#include "display.h"

/**
 * \fn void display_tab(double *tab, int N)
 * \brief Fonction pour afficher une matrice carré sur l'entrée standard
 *
 * \param tab tableau contenant la matrice à afficher.
 * \param N dimention de la matrice.
 */
void display_tab(double *tab, int N){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%.2f ",tab[i*N+j]);
        }
        printf("\n");
    }
}

/**
 * \fn void display_tab_res(double *tab, int N){
 * \brief Fonction pour afficher le vecteur résultat sur l'entrée standard
 *
 * \param res tableau contenant le vecteur à afficher.
 * \param N dimention de la matrice.
 */
void display_tab_res(double *tab, int N){
    for(int i = 0; i < N; i++){
        printf("%.20f \n",tab[i]);
    }
}

void display_vp(Vp vp, int N){
    printf("Vecteur propre colonne :\n");
    for (int i = 0; i < N; i++){
        printf("%f\n", vp.vectpC[i]);
    }

    printf("Vecteur propre ligne : ");
    for (int i = 0; i < N; i++){
        printf("%f ", vp.vectpL[i]);
    }
    printf("\nValeur propre : %d\n", vp.valp);
}