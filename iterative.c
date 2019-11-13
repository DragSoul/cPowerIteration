/**
 * \file iterative.c
 * \author Aurelien DOUARD, Anthony Bertrand
 * \brief 
 * \version 0.1
 * \date 11 novembre 2019
 *
 * 
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "iterative.h"
#include "testMatrice.h"
#include "display.h"



void iterative(double tab[], int N){
    double xinit[3] = {1,1,1}, xsuiv[3];
    double err = 0;
    int i, comp = 1;
    calcul_matriciel(tab, xinit, xsuiv, N);
    for (i = 0; i < N; i++){
            xsuiv[i] /= xsuiv[N-1];
    }
    comp = compare(xinit, xsuiv, N);
    while(comp){
        copy(xsuiv, xinit, 3, 1);
        calcul_matriciel(tab, xinit, xsuiv, N);
        for (i = 0; i < N; i++){
            xsuiv[i] /= xsuiv[N-1];
        }
        comp = compare(xinit, xsuiv, N);  
    }

    display_tab_res(xsuiv, N);
}

int compare(double xinit[], double xsuiv[], int N){
    int i;
    double rapport;
    for(i = 0; i < N; i++){
        rapport = 1 - xsuiv[i] / xinit[i];
        if(sqrt(pow(rapport, 2)) > 0.00001){
            return 1;
        }
    }
    return 0;
}



//a = xsuiv * tab * xsuivt
//b = xsuiv * xsuivt
//valeur propre associée = a/b

/*
*
* structures contenant vecteurs propres et valeurs propres associées
* besoin de garder une trace car la matrice va changer avec la déflation
* contenir ces structures dans tableau/liste ?
*
**/
