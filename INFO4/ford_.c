#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define taille 5
#define INF  999999

// Algorithme de Bellman-Ford avec detection de cycle negatif dans le graphe

typedef struct Edge {
    int src;
    int dest;
    int weight;
} Edge;

typedef struct Result {
    int dist[taille];
    bool has_negative_cycle;
    int negative_cycle_vertex;
} Result;

/**
 * Ford - Algorithme de Bellman-Ford
 * Calcule les distances minimales depuis une source
 * et detecte les cycles negatifs
 * 
 * @param edges - tableau des aretes du graphe
 * @param num_edges - nombre d'aretes
 * @param num_vertices - nombre de sommets
 * @param src - sommet source
 * @return Result - structure contenant les distances et info de cycle
 */
Result Ford(Edge *edges, int num_edges, int num_vertices, int src){
    Result result;
    result.has_negative_cycle = false;
    result.negative_cycle_vertex = -1;
    
    // Initialisation des distances
    for(int i = 0; i < num_vertices; i++){
        result.dist[i] = INF;
    }
    result.dist[src] = 0;

    // Phase 1: Relaxation des aretes (num_vertices - 1) fois
    for(int k = 0; k < num_vertices - 1; k++){
        for(int i = 0; i < num_edges; i++){
            int u = edges[i].src;
            int v = edges[i].dest;
            int w = edges[i].weight;
            
            // Relaxation: si on peut diminuer la distance, on le fait
            if(result.dist[u] != INF && result.dist[u] + w < result.dist[v]){
                result.dist[v] = result.dist[u] + w;
            }
        }
    }

    // Phase 2: Detection de cycles negatifs
    // Si on peut encore diminuer une distance, il existe un cycle negatif
    for(int i = 0; i < num_edges; i++){
        int u = edges[i].src;
        int v = edges[i].dest;
        int w = edges[i].weight;
        
        if(result.dist[u] != INF && result.dist[u] + w < result.dist[v]){
            result.has_negative_cycle = true;
            result.negative_cycle_vertex = v;
            break;
        }
    }

    return result;
}


int main(){
    printf("\n");
    printf("\t====================================\n");
    printf("\t=== ALGORITHME DE BELLMAN-FORD ===\n");
    printf("\t====================================\n");
    printf("\n");

    // Conversion de la matrice d'adjacence en tableau d'aretes
    Edge edges[8];

    // Matrice d'adjacence du graphe (0 = pas d'arete)
    int graph[taille][taille] = {
        {0, 6, 3, 0, 0},
        {0, 0, 0, 8, 1},
        {0, 2, 0, 3, 5},
        {0, 1, 0, 0, 0},
        {0, 0, 2, 0, 0}
    };

    // Construction du tableau d'aretes
    int edge_count = 0;
    for(int i = 0; i < taille; i++){
        for(int j = 0; j < taille; j++){
            if(graph[i][j] != 0){
                edges[edge_count].src = i;
                edges[edge_count].dest = j;
                edges[edge_count].weight = graph[i][j];
                edge_count++;
            }
        }
    }

    printf("\tGraphe: %d sommets, %d aretes\n", taille, edge_count);
    printf("\n");

    // Execution de l'algorithme depuis le sommet 0
    int source = 0;
    Result result = Ford(edges, edge_count, taille, source);

    // Affichage des resultats
    printf("\tDistances minimales depuis le sommet x%d :\n", source + 1);
    printf("\t----------------------------------------\n");
    for (int i = 0; i < taille; i++) {
        if (result.dist[i] == INF)
            printf("\tx%d : ISOLÉ (distance infinie)\n", i + 1);
        else
            printf("\tx%d : %d\n", i + 1, result.dist[i]);
    }

    printf("\t----------------------------------------\n");
    if (result.has_negative_cycle) {
        printf("\n\t⚠️  CYCLE NEGATIF DETECTÉ!\n");
        printf("\tCycle affectant le sommet x%d\n", result.negative_cycle_vertex + 1);
        printf("\tLes distances ne sont pas fiables!\n");
    } else {
        printf("\n\t✓ Aucun cycle negatif detecté\n");
        printf("\tLes distances sont fiables!\n");
    }

    printf("\n");
    system("pause");

    return 0;
}