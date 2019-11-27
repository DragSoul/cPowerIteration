#include "deflation.h"

//pt d'entrée
void deflate(double tab[], Vp vp, int N){
    double tmp[100];
    double div = 0, coeff;

    //calcul du denominateur de la deflation que je combine avec la valeur propre
    for (int i = 0; i < N; i++){
        div += vp.vectpL[i] * vp.vectpC[i];
    }
    coeff = vp.valp/div;

    //calcul de la matrice qu'on obtient au numérateur * coeff (pour aller plus vite)
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            tmp[i*N + j] = (vp.vectpC[i] * vp.vectpL[j]) * coeff;
        }
    }

    //calcul de A - (tout mon mélange)
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            tab[i*N + j] -= tmp[i*N +j];
        }
    }
}