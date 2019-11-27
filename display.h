/**
 * \file display.h
 * \author Aurelien DOUARD, Anthony Bertrand
 * \brief fichier contenant le prototype des fonctions d'affichage de matrice
 * \version 0.1
 * \date 11 novembre 2019
 *
 * fichier contenant le prototype des fonctions d'affichage de matrice
 *
 */

#ifndef H_DISPLAY
#define H_DISPLAY

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    double vectpC[3];
    double vectpL[3];
	int valp;
}Vp;

void display_tab(double *tab, int N);
void display_tab_res(double *tab, int N);
void display_vp(Vp vp, int N);

#endif