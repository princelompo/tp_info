
#include<stdio.h>
#include<math.h>
int main()

{

    // calculons la moyenne de cette somme de notes
    float N[5];
    float S, M ;
    int i, taille=7 ;
    printf(" Calculons la moyenne correspondante aux notes de l'eleve \n");
    for(i=0;i<taille;i++){
        printf(" Entrer la note numéro %d : ", i+1);
        scanf("%f",&N[i]);

        }

    S=0;
    for(i=0;i<taille;i++){
            S=S+N[i] ;
    }

    M=S/taille ;
    printf(" La moyenne est : %f \n", M);




    system("pause");







}









