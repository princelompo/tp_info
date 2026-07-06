#include<stdio.h>
#include<stdlib.h>

#define TAILLE 6

void tableurV(int mat[TAILLE][TAILLE], int TV[TAILLE], int sommet, int e){
    for(int i = 0; i < TAILLE; i++){
        if ((mat[sommet][i] == 1) && (TV[i] == -1)){
            TV[i] = e;
            tableurV(mat,TV,i,e+1);
        }
        
    }  
}

void tableurH(int mat[TAILLE][TAILLE], int TH[TAILLE], int sommet, int e){
    for(int i = 0; i < TAILLE; i++){
        if ((mat[i][sommet] == 1) && (TH[i] == -1)){
            TH[i] = e;
            tableurH(mat,TH,i,e+1);
        }
        
    }
}

void malgrange(int mat[TAILLE][TAILLE], int TV[TAILLE], int TH[TAILLE], int sommet,int l, int visite[TAILLE]){

    if (sommet >= TAILLE){
        return ;
    }

    int debut = sommet;
    
    while(debut < TAILLE && visite[debut] == -9){
        debut++;
    }
    if(debut >= TAILLE){
        return;
    }

    for(int i = sommet; i < TAILLE; i++){
        TV[i] = -1;
        TH[i] = -1;
    }
    TV[debut] = 0; 
    TH[debut] = 0;

    tableurV(mat,TV,debut,1);
    tableurH(mat,TH,debut,1);

    
    for(int i = 0; i < TAILLE; i++){
        printf("%d ",TV[i]);
    }

    printf("\n");
    
    for(int i = 0; i < TAILLE; i++){
        printf(" %d ",TH[i]);
    }
    printf("\n");

    printf("Composante %d ==> {",l);
    for(int i = 0; i < TAILLE; i++){
        if((TV[i] != -1) && (TH[i] != -1)){
            printf(" %d ",i+1);
            sommet++;
            visite[i] = -9;
        }
    }
    printf(" }");
    printf("\n");

    malgrange(mat,TV,TH,debut,l+1,visite);

}

int main(){

    int mat[TAILLE][TAILLE] = {
        {0,1,0,0,0,0},
        {0,0,1,0,0,0},
        {0,0,0,1,1,0},
        {1,0,0,0,0,0},
        {0,0,0,0,0,1},
        {0,0,0,0,1,0}
    };

    int tv[TAILLE], th[TAILLE];

    int visite[TAILLE] = {9,9,9,9,9,9};

    printf("\n");
    printf("Les composantes connexes sont : \n");
    printf("\n");

    malgrange(mat,tv,th,0,1,visite);


    printf("\n");
    system("pause");


    return 0;

}