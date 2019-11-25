/**
 * \file iterative.h
 * \author Aurelien DOUARD, Anthony Bertrand
 * \brief fichier contenant le prototype des fonctions du fichier iterative.c.
 * \version 0.1
 * \date 11 novembre 2019
 *
 * fichier contenant le prototype des fonctions du fichier iterative.c.
 *
 */

#ifndef H_ITERATIVE
#define H_ITERATIVE

typedef struct
{
    double vectpC[3];
    double vectpL[3];
	int valp;
}Vp;

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "testMatrice.h"
#include "display.h"



Vp calculvectpC(double tab[], Vp vp, int N);
Vp calculvectpL(double tab[], Vp vp, int N);
int compare(double xinit[], double xsuiv[], int N);
Vp valeur_propre(double tab[], Vp vp, int N);
Vp iterative(double tab[], Vp vp, int N);

#endif