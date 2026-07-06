#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


#define taille 7

// void fonc_ordinale(int MAT[taille][taille],int m[taille],int niveau){
//     int somme = 0;
//     for(int i = 0; i < taille; i++){
//         if(m[i] == -1){
//             somme += 1;
//             printf("%d ",somme);
//         }
//     }
//     if(somme == taille){
//         return;
//     }
//     for(int i = 0; i < taille; i++){
//         if(m[i] != -1){
//             m[i] = 0;
//         }
//     }
//     for(int i = 0; i < taille; i++){
//         printf("%d ",m[i]);
//     }
//     for(int i = 0; i < taille; i++){
//         for(int j = 0; j < taille; j++){
//             if(m[i] != -1){
//                 m[i] = m[i] + MAT[j][i];
//             }
//         }
//     }


//     printf("\tNIVEAU %d : ", niveau);
//     for(int i = 0; i < taille; i++){
//         if(m[i] == 0){
//             printf("%d ",i);
//             m[i] = -1;
//             for(int j = 0;j < taille; j++){
//                 MAT[i][j] = 0;
//             }
//         }
//     }
//     printf("\n");
    
//     fonc_ordinale(MAT, m, niveau+1);

// }

int cycle(int *mat){
    for(int *i = mat; i < mat + taille; i++){
        if( *i == 0){
            return 0;
        }
    }
    return 1;  
}

int main(){

    int mat[taille][taille] = {
        {0 ,1, 1, 0, 0, 1, 0},
        {1 ,0, 1, 0, 1, 1, 0},
        {0 ,0, 0, 1, 1, 0, 0},
        {0 ,0, 1, 0, 0, 0, 1},
        {0 ,0, 0, 1, 0, 0, 0},
        {0 ,0, 0, 1, 0, 0, 0}, // 
        {0 ,0, 0, 0, 0, 0, 0}
    };

    int niv = 1, m[taille] = {0, 0, 0, 0, 0, 0};

    printf("\n\t===== CALCUL DE NIVEAUX, FONCTION ORDINALE ======\n");

    do{
        int sum = 0;
        for(int i = 0; i < taille; i++){
            if(m[i] != -1){
                m[i] = 0;
            }
        }
        for(int i = 0; i < taille; i++){
            for(int j = 0; j < taille; j++){
                if(m[i] != -1){
                    m[i] = m[i] + mat[j][i];
                }
            }
        }
        int k = cycle(m);
        if(k == 1){
            printf(" CYCLE DETECTE DANS LE GRAPHE ");
            break;  
        }
        printf("\tNIVEAU %d : ", niv);
        for(int i = 0; i < taille; i++){
            if(m[i] == 0){
                printf("%d ",i+1);
                m[i] = -1;
                for(int j = 0;j < taille; j++){
                    mat[i][j] = 0;
                }
            }
        }
        
        printf("\n");
        niv++;
        for(int i = 0; i < taille; i++){
            if(m[i] == -1){
                sum++;
            }
        }
        if(sum == taille){
            break;
        }
        
    }while(1);


    system("pause");

    return 0;
}