#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define TAILLE 6

typedef struct Table{
    int src;
    int dest;
    int poid;
}Table;

void trie(Table *mat, int size){
    for(int i = 0; i < size-1; i++){
        for(int j = 0; j < size-i-1; j++){
            if(mat[j].poid > mat[j+1].poid){
                Table t = mat[j];
                mat[j] = mat[j+1];
                mat[j+1] = t;
            }
        }
    }
}

int main(){

    printf("\n");
    printf("\n\033[1;35m");

    printf("\t==================================\n");
    printf("\t===== ALGORITHME DE KRUSKAL ======\n");
    printf("\t==================================\n");

    printf("\n");


    int MAT[TAILLE][TAILLE];
    
    for(int i = 0; i < TAILLE; i++){
        for(int j = 0; j < TAILLE; j++){
            MAT[i][j] = 0;
        }
    }
    MAT[1][2] = 3;
    MAT[1][3] = 8;
    MAT[1][4] = 2;
    MAT[2][3] = 6;
    MAT[3][4] = 5;
    MAT[3][5] = 9;

    Table Tableau[TAILLE];

    int index = 0;
    for(int i = 0; i < TAILLE; i++){
        for(int j = i+1; j < TAILLE; j++){
            if(MAT[i][j] != 0){
                Tableau[index].src = i;
                Tableau[index].dest = j;
                Tableau[index].poid = MAT[i][j];    
                index++;
            }
        }
    }

    trie(Tableau,TAILLE);

    printf("\tTableau trie : \n");
    for(int i = 0; i < TAILLE; i++){
        printf("\tx%d -> x%d | poid : %d \n",Tableau[i].src,Tableau[i].dest,Tableau[i].poid);
    }
    printf("\n");

    int coutTotal = 0;
    int cycle[TAILLE] = {1, 2, 3, 4, 5, 6};
    
    printf("\tArcs selectionnes : \n");
    for(int i = 0; i < TAILLE; i++){
        if(cycle[Tableau[i].src] != cycle[Tableau[i].dest]){
            printf("\tx%d -> x%d | poid : %d \n",Tableau[i].src,Tableau[i].dest,Tableau[i].poid);
            coutTotal += Tableau[i].poid ;
            cycle[Tableau[i].src] = 1 ;
            cycle[Tableau[i].dest] = 1;
            
        }
    }
    printf("\n\tCout total : %d \n",coutTotal);
    

    system("pause");
    return 0;
}