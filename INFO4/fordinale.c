#include<stdio.h>
#include<stdlib.h>

#define taille 7

void fonc_ordinale(int MAT[taille][taille],int m[taille], int niveau){
    int somme = 0;
    for(int i = 0; i < taille; i++){
        if(m[i] == -1){
            somme++;
        }
    }
    if(somme == taille){
        return;
    }

    for(int i = 0; i < taille; i++){
        if(m[i] != -1){
            m[i] = 0;
        }
    }
    for(int i = 0; i < taille; i++){
        for(int j = 0; j < taille; j++){
            if(m[i] != -1){
                m[i] = m[i] + MAT[j][i];
            }
        }
    }

    int trouve = 0;
    for(int i = 0; i < taille; i++){
        if(m[i] == 0){
            if(trouve == 0) printf("\tNIVEAU %d : ", niveau);
            printf("%d ",i);
            m[i] = -1;
            trouve = 1;
            for(int j = 0;j < taille; j++){
                MAT[i][j] = 0;
            }
        }
    }

    if(trouve == 0) {
        printf("\tErreur : Cycle detecte dans le graphe !\n");
        return;
    }
    
    printf("\n");
    fonc_ordinale(MAT, m, niveau+1);
}

int main(){

    int mat[taille][taille] = {
        {0 ,1, 1, 0, 0, 1, 0},
        {0 ,0, 1, 0, 1, 1, 0},
        {0 ,0, 0, 0, 1, 0, 0},
        {0 ,0, 0, 0, 0, 0, 1},
        {0 ,0, 0, 1, 0, 0, 0},
        {0 ,0, 0, 1, 0, 0, 0}, // 
        {0 ,0, 0, 0, 0, 0, 0}
    };

    printf("\n\033[1;35m");
    int niv = 1, m[taille] = {0, 0, 0, 0, 0, 0, 0};

    printf("\n\t===== CALCUL DE NIVEAUX, FONCTION ORDINALE ======\n\n");
    fonc_ordinale(mat, m, niv);

    system("pause");

    return 0;
}