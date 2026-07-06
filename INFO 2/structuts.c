#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
        char nom[30];
        int age;
        float taille;
    }Personne;


void modifier(Personne *p, char *nouveau_nom, int nouvel_age, float nouvelle_taille){
    strcpy(p->nom, nouveau_nom);
    p->age = nouvel_age;
    p->taille = nouvelle_taille;
}
void afficher(const Personne *p){
    printf("\t|-------Infos personne-------|\n");
    printf("\t| Nom: %s                  |\n", p->nom);
    printf("\t| Age: %d                    |\n", p->age);
    printf("\t| Taille: %.2f               |\n", p->taille);
    printf("\t|----------------------------|\n");      
}


int main(){

    // manipulations des structures 
    printf("\n\n");

    Personne p1;
    modifier(&p1, "Alice", 30, 1.65);
    afficher(&p1);

    printf("\n\n");

    Personne p2;
    modifier(&p2, "John", 25, 1.677);
    afficher(&p2);

    
    return 0;

}