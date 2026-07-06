#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


// Déclaration du nœud
typedef struct Noeud {
    int donnee;
    struct Noeud *precedent;
    struct Noeud *suivant;
} Noeud;

// Déclaration de la liste (optionnel)
typedef struct ListeDouble {
    Noeud *tete;
    Noeud *queue;
    int taille;
} ListeDouble;

// Fonction pour créer un nouveau nœud
Noeud* creer_noeud(int donnee) {
    Noeud* nouveau_noeud = (Noeud*)malloc(sizeof(Noeud));
    if (nouveau_noeud == NULL) {
        printf("Erreur d'allocation de mémoire\n");
        return NULL;
    }
    nouveau_noeud->donnee = donnee;
    nouveau_noeud->precedent = NULL;
    nouveau_noeud->suivant = NULL;
    return nouveau_noeud;
}

ListeDouble* initialiserListe() {
    ListeDouble *liste = malloc(sizeof(ListeDouble));
    if (liste == NULL) return NULL;
    
    liste->tete = NULL;
    liste->queue = NULL;
    liste->taille = 0;
    
    return liste;
}

// verifier si la liste est vide
int est_vide(ListeDouble *liste) {
    return liste->taille == 0 || liste->tete == NULL ;
}

void insererDebut(ListeDouble *liste, int valeur) {
    Noeud *nouveau = creerNoeud(valeur);
    if (nouveau == NULL) return;
    
    if (estVide(liste)) {
        // Première insertion
        liste->tete = nouveau;
        liste->queue = nouveau;
    } else {
        // Insertion devant la tête actuelle
        nouveau->suivant = liste->tete;
        liste->tete->precedent = nouveau;
        liste->tete = nouveau;
    }
    
    liste->taille++;
}

void insererFin(ListeDouble *liste, int valeur) {
    Noeud *nouveau = creerNoeud(valeur);
    if (nouveau == NULL) return;
    
    if (estVide(liste)) {
        liste->tete = nouveau;
        liste->queue = nouveau;
    } else {
        // Insertion après la queue actuelle
        nouveau->precedent = liste->queue;
        liste->queue->suivant = nouveau;
        liste->queue = nouveau; 
    }
    
    liste->taille++;
}

// inserer apres un noeud quelconque
void insererApres(ListeDouble *liste, Noeud *cible, int valeur) {
    if (cible == NULL) return;
    
    Noeud *nouveau = creerNoeud(valeur);
    if (nouveau == NULL) return;
    
    // Mettre à jour les liens
    nouveau->precedent = cible;
    nouveau->suivant = cible->suivant;
    
    if (cible->suivant != NULL) {
        cible->suivant->precedent = nouveau;
    }
    
    cible->suivant = nouveau;
    
    // Si on insérait après le dernier élément
    if (cible == liste->queue) {
        liste->queue = nouveau;
    }
    
    liste->taille++;
}

void insererAvant(ListeDouble *liste, Noeud *cible, int valeur) {
    if (cible == NULL) return;
    
    Noeud *nouveau = creerNoeud(valeur);
    if (nouveau == NULL) return;
    
    // Mettre à jour les liens
    nouveau->suivant = cible;
    nouveau->precedent = cible->precedent;
    
    if (cible->precedent != NULL) {
        cible->precedent->suivant = nouveau;
    }
    
    cible->precedent = nouveau;
    
    // Si on insérait avant le premier élément
    if (cible == liste->tete) {
        liste->tete = nouveau;
    }
    
    liste->taille++;
}

int supprimerDebut(ListeDouble *liste) {
    if (estVide(liste)) {
        printf("Liste vide, impossible de supprimer!\n");
        return -1;
    }
    
    Noeud *aSupprimer = liste->tete;
    int valeur = aSupprimer->donnee;
    
    if (liste->tete == liste->queue) {
        // Un seul élément
        liste->tete = NULL;
        liste->queue = NULL;
    } else {
        // Plusieurs éléments
        liste->tete = liste->tete->suivant;
        liste->tete->precedent = NULL;
    }
    
    free(aSupprimer);
    liste->taille--;
    
    return valeur;
}

int supprimerFin(ListeDouble *liste) {
    if (estVide(liste)) {
        printf("Liste vide, impossible de supprimer!\n");
        return -1;
    }
    
    Noeud *aSupprimer = liste->queue;
    int valeur = aSupprimer->donnee;
    
    if (liste->tete == liste->queue) {
        // Un seul élément
        liste->tete = NULL;
        liste->queue = NULL;
    } else {
        // Plusieurs éléments
        liste->queue = liste->queue->precedent;
        liste->queue->suivant = NULL;
    }
    
    free(aSupprimer);
    liste->taille--;
    
    return valeur;
}

int supprimerNoeud(ListeDouble *liste, Noeud *cible) {
    if (cible == NULL || estVide(liste)) {
        return -1;
    }
    
    int valeur = cible->donnee;
    
    // Mise à jour des voisins
    if (cible->precedent != NULL) {
        cible->precedent->suivant = cible->suivant;
    }
    
    if (cible->suivant != NULL) {
        cible->suivant->precedent = cible->precedent;
    }
    
    // Mise à jour tête/queue si nécessaire
    if (cible == liste->tete) {
        liste->tete = cible->suivant;
    }
    
    if (cible == liste->queue) {
        liste->queue = cible->precedent;
    }
    
    free(cible);
    liste->taille--;
    
    return valeur;
}

int supprimerValeur(ListeDouble *liste, int valeur) {
    Noeud *courant = liste->tete;
    
    while (courant != NULL) {
        if (courant->donnee == valeur) {
            return supprimerNoeud(liste, courant);
        }
        courant = courant->suivant;
    }
    
    printf("Valeur %d non trouvée!\n", valeur);
    return -1;
}

