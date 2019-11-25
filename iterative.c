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

#include "iterative.h"

//calcul du vecteur propre colonne (méthode dans l'énoncé du tp3)
Vp calculvectpC(double tab[], Vp vp, int N){
    double xinit[3] = {1,1,1}, xsuiv[3];
    int i, comp = 1;
    calcul_matriciel_C(tab, xinit, xsuiv, N);
    for (i = 0; i < N; i++){
            xsuiv[i] /= xsuiv[N-1];
    }
    comp = compare(xinit, xsuiv, N);
    while(comp){
        copy(xsuiv, xinit, 3, 1);
        calcul_matriciel_C(tab, xinit, xsuiv, N);
        for (i = 0; i < N; i++){
            xsuiv[i] /= xsuiv[N-1];
        }
        comp = compare(xinit, xsuiv, N);  
    }
    copy(xsuiv, vp.vectpC, N, 1);
    return vp;
}

//calcul le vecteur propre ligne de la même façon qu'on calcule le vecteur propre colonne.
Vp calculvectpL(double tab[], Vp vp, int N){
    double xinit[3] = {1,1,1}, xsuiv[3];
    int i, comp = 1;
    calcul_matriciel_L(tab, xinit, xsuiv, N);
    for (i = 0; i < N; i++){
            xsuiv[i] /= xsuiv[N-1];
    }
    comp = compare(xinit, xsuiv, N);
    while(comp){
        copy(xsuiv, xinit, 3, 1);
        calcul_matriciel_L(tab, xinit, xsuiv, N);
        for (i = 0; i < N; i++){
            xsuiv[i] /= xsuiv[N-1];
        }
        comp = compare(xinit, xsuiv, N);  
    }
    copy(xsuiv, vp.vectpL, N, 1);
    return vp;
}

//méthode de comparaison. Sert de test d'arrêt aux fonctions de calcul de vecteur propre
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

//quotient de Rayleigh
//valeur propre = (xt*tab*x)/(xt*x)
//en mémoire, il n'y a pas de différence entre un vecteur ligne et un vecteur colonne
//la différence est à gérer soi même
Vp valeur_propre(double tab[], Vp vp, int N){
    int a = 0, b = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            a = vp.vectpC[j] * tab[j*N + i];
        }
        b = b + a * vp.vectpC[i];
    }
    vp.valp = b;
    return vp;
}

//pt d'entrée
Vp iterative(double tab[], Vp vp, int N){
    
    vp = calculvectpC(tab, vp, N);
    vp = calculvectpL(tab, vp, N);
    vp = valeur_propre(tab, vp, N);
    return vp;
}

/*
*
* structures contenant vecteurs propres et valeurs propres associées
* besoin de garder une trace car la matrice va changer avec la déflation
* contenir ces structures dans tableau/liste ?
*
**/
