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

void iterative(double tab[], int N);
int compare(double xinit[], double xsuiv[], int N);
void calcul_matriciel(double tab[], double xinit[], double xsuiv[], int N);

#endif