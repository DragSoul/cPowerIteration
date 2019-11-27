/**
 * \file main.c
 * \author Aurelien DOUARD, Anthony Bertrand
 * \brief Programme permettant de trouver valeur propre et vecteur propre par la méthode des puissances itératives
 * \version 0.1
 * \date 11 novembre 2019
 *
 * Programme permettant de trouver valeur propre et vecteur propre par la méthode des puissances itératives
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "display.h"
#include "testMatrice.h"
#include "iterative.h"
#include "deflation.h"

#define N 3

int main(){
    int i = 0;
    double tab[100]={1,0,8,0,2,-1,1,0,3};
    Vp tabvp[10];

    printf("matrice A :\n");
    display_tab(tab, N);

    tabvp[i] = iterative(tab, tabvp[i], N);
    display_vp(tabvp[i], N);

    deflate(tab, tabvp[i], N);
    printf("\nmatrice B (déflation de A):\n");
    display_tab(tab, N);
    
    return 0;
}
