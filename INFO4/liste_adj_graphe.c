#include<stdio.h>
#include<stdlib.h>


// tp 2 info 4 : creation d'un graphe avec 'val' sommets
// affiche la liste d'adjascence de chaque sommet 
// affiche la liste des successeurs et des predecesseurs de chaque sommet

typedef struct sommet{
    int label;
    struct sommet* next;
}sommet;


typedef struct Liste{
    sommet* head;
}Liste;

typedef struct Graphe{
    int V;
    Liste* array;
}Graphe;


sommet* newSommet(int label){
    sommet* new = (sommet*)malloc(sizeof(sommet));
    if(new == NULL){
        printf("Erreur allocation mémoire pour sommet\n");
        return 0;
    }
    new->label = label;
    new->next = NULL;
    return new;
}

// Création d'un graphe vide avec 'val' sommets.

Graphe* createGraphe(int val){
    Graphe* graphe = (Graphe*)malloc(sizeof(Graphe));
    if(graphe == NULL){
        printf("Erreur allocation mémoire pour graphe\n");
        return 0;
    }
    graphe->V = val;
    graphe->array = (Liste*)malloc(val * sizeof(Liste));
    if(graphe->array == NULL){
        printf("Erreur allocation mémoire pour tableau de listes\n");
        free(graphe);
        return 0;
    }
    for(int i = 0; i < val; i++){
        graphe->array[i].head = NULL; 
    }
    return graphe;
}

void addEdge(Graphe* graphe, int src, int dest){
    sommet* new = newSommet(dest);
    new->next = graphe->array[src].head;
    graphe->array[src].head = new;
}

void printGraphe(Graphe* graphe){
    for(int i = 0; i < graphe->V; i++){
        sommet* temp = graphe->array[i].head;
        printf(" sommet x%d \n: ",i+1);
        while(temp != NULL){
            printf("%d ->  x%d |",i+1,temp->label+1);
            temp = temp->next;
        }
        printf("\n");
    }
}

void printSuccesseurs(Graphe* graphe){
    for(int i = 0; i < graphe->V; i++){
        sommet* temp = graphe->array[i].head;
        printf("Les successeurs de x%d sont : ",i+1);
        while(temp != NULL){
            printf("x%d  ",temp->label+1);
            temp = temp->next;
        }
        printf("\n\n");
    }
}


void printPredecesseurs(Graphe* graphe){
    for(int i = 0; i < graphe->V; i++){
        printf("Les predecesseurs de x%d sont : ",i+1);
        for(int j = 0; j < graphe->V; j++){
            sommet* temp = graphe->array[j].head;
            while(temp != NULL){
                if(temp->label == i){
                    printf("x%d  ",j+1);
                }
                temp = temp->next;
            }
        }
        printf("\n\n");
    }
}


int main(){
    
    Graphe* graphe = createGraphe(4);
    addEdge(graphe,0,1); 
    addEdge(graphe,0,2); 
    addEdge(graphe,0,3); 
    addEdge(graphe,1,0); 
    addEdge(graphe,1,3); 
    addEdge(graphe,2,3);

    printGraphe(graphe);
    printSuccesseurs(graphe);
    printPredecesseurs(graphe);

    return 0;
 }


