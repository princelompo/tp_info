#include<stdio.h>
#include<stdio.h>

#define taille 7
#define INF 999999



#include<stdio.h>
#include<stdlib.h>
#define taille 5
#define INF  999999

// algorithme de ford avec detection de cycle dans le graphe

typedef struct Table{
    int src;
    int dest;
    int poid;
}Table;

void Ford(Table *mat, int src){
    int dist[taille];
    for(int i = 0; i < taille; i++){
        dist[i] = INF;
    }
    dist[src] = 0;

    for(int k = 0; k < 7; k++){
        for(int i = 0; i < 8; i++){
            int u = mat[i].src;
            int v = mat[i].dest;
            int w = mat[i].poid;
            if(dist[u] != INF && dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }

    printf("\tDistances minimales depuis le sommet x%d :\n", src + 1);
    for (int i = 0; i < taille; i++) {
        if (dist[i] == INF)
            printf("\tx%d est un sommet isolé \n", i + 1);
        else
            printf("\tx%d : %d\n", i + 1, dist[i]);
    }
}


int  main(){

    printf("\n");
    printf("\t==================================\n");
    printf("\t=== ALGORITHME DE BELLMAN-FORD ===\n");
    printf("\t==================================\n");
    printf("\n");

    Table Tableau[8];

    int G[taille][taille] = {
        {0, 6, 3, 0, 0},
        {0, 0, 0, 8, 1},
        {0, 2, 0, 3, 5},
        {0, 1, 0, 0, 0},
        {0, 0, 2, 0, 0}
    };
    int index = 0;
    for(int i = 0; i < taille; i++){
        for(int j = 0; j < taille; j++){
            if(G[i][j] != 0){
                Tableau[index].src = i;
                Tableau[index].dest = j;
                Tableau[index].poid = G[i][j];
                index++;
            }
        }
    }

    Ford(Tableau, index, 0);

    printf("\n");
    system("pause");

    return 0;
}
    // Affichage des distances finales
    printf("\tDistances minimales depuis le sommet x%d :\n", src + 1);
    for (int i = 0; i < taille; i++) {
        if (dist[i] == INF)
            printf("\tx%d est un sommet isolé \n", i + 1);
        else
            printf("\tx%d : %d\n", i + 1, dist[i]);
    }
}

int main(){

    printf("\n\033[1;35m");
    printf("\t==================================\n");
    printf("\t=== ALGORITHME DE BELLMAN-FORD ===\n");
    printf("\t==================================\n");
    printf("\n");


    int mat[taille][taille] = {
        {0, 1, 4, 0, 0, 0, 0},
        {0, 0, 4, 2, -7, 0, 0},
        {0, 0, 0, 3, 5, 0, 0},
        {0, 0, 0, 0, 0, 11, 0},
        {0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, -8},
        {0, 0, 0, 6, 0, 0, 0}
    };

    bellmanFord(mat, 0);

    printf("");


    system("pause");
    return 0;
}
