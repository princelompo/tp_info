#include <stdio.h>

int main()
{
    int A, B;
    int quotient = 0 ;

    // Entrée des valeurs
    printf("Entrez l'entier A (positif ou nul) : ");
    scanf("%d", &A);
    printf("Entrez l'entier B (positif ou nul) : ");
    scanf("%d", &B);

    // Cas particulier : division par zéro
    if (B == 0) {
        printf("Erreur : division par zéro !\n");
        return 1;
    }

    // Division par soustraction répétée
    while (A >= B) {
        A = A-B;
        quotient++;
    }

    // Affichage du résultat
    printf("Quotient = %d\n", quotient);
    printf("Reste = %d\n", A);

    return 0;
}

