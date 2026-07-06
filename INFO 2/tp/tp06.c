#include<stdio.h>
#include<stdlib.h>


int main(){

    int l,c;
    printf("Entrer le nombre de lignes : ");
    scanf("%d",&l);
    printf("Entrer le nombre de colognes : ");
    scanf("%d",&c);

    int *matrice = (int*)malloc(l*c*sizeof(int));
    if(matrice == NULL){
        printf("Erreur d'allocation dynamique de memoire \n");
        exit(1);
    }
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            printf("Entrer la valeur : ");
            scanf("%d",(matrice++));
        }

    }
        










    return 0;
}