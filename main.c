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

int main(){
    Vp vp;
    double tab[100]={1,0,8,0,2,-1,1,0,3};
    vp = iterative(tab, vp, 3);
    display_vp(vp, 3);
    return 0;
}
