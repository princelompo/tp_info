#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define INF 999999
#define taille 7

/**
 * Fonction pour trouver le sommet avec la distance minimale
 * parmi les sommets non encore visités.
 */
int trouverMinDistance(int dist[], bool visite[]) {
    int min = INF, min_index = -1;
    for (int v = 0; v < taille; v++) {
        if (!visite[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

/**
 * Implémentation de l'algorithme de Moore-Dijkstra
 */
void mooreDijkstra(int mat[taille][taille], int src) {
    int dist[taille];    // Vecteur des distances minimales
    bool visite[taille]; // Sommets dont le plus court chemin est trouvé

    // Initialisation
    for (int i = 0; i < taille; i++) {
        dist[i] = INF;
        visite[i] = false;
    }
    dist[src] = 0;

    for (int count = 0; count < taille - 1; count++) {
        int u = trouverMinDistance(dist, visite);
        if (u == -1) break; // Tous les sommets atteignables ont été visités

        visite[u] = true;

        // Mise à jour des distances des voisins du sommet u
        for (int v = 0; v < taille; v++) {
            if (!visite[v] && mat[u][v] != 0 && dist[u] + mat[u][v] < dist[v]) {
                dist[v] = dist[u] + mat[u][v]; 
            }
        }
    }

    // Affichage des résultats
    printf("\tDistances minimales depuis le sommet x%d :\n", src + 1);
    for (int i = 0; i < taille; i++) {
        if (dist[i] == INF)
            printf("\tx%d : Infini\n", i + 1);
        else
            printf("\tx%d : %d\n", i + 1, dist[i]);
    }
}

int main(){
    printf("\n");
    printf("\n\033[1;35m");
    printf("\t==================================\n");
    printf("\t====== ALGORITHME DIJKSTRA =======\n");
    printf("\t==================================\n");
    printf("\n");

    // Exemple de matrice d'adjacence pondérée
    int MAT[taille][taille] = {
        {0, 4, 0, 0, 0, 0, 0},
        {0, 0, 8, 0, 0, 0, 0},
        {0, 0, 0, 7, 0, 4, 0},
        {0, 0, 0, 0, 9, 14, 0},
        {0, 0, 0, 0, 0, 10, 0},
        {0, 0, 0, 0, 0, 0, 2},
        {0, 0, 0, 0, 0, 0, 0}
    };

    mooreDijkstra(MAT, 0); // Lancement depuis le premier sommet (index 0)

    printf("\n");
    system("pause");
    return 0;
}
