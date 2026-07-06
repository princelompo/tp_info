#include<stdio.h>
int main()
{

    int tab[200],i,nbr,compteur;
    printf("\n");
    printf(" Entrer le nombre correspondant : ");
    scanf("%d",&nbr);

    printf("\n");

    compteur = 0;
    printf(" Tableau = ");
    for(i=1;i<=nbr;i++){
        if(nbr%i==0){
            printf("|%d|\t",i);
            compteur++;
        }
    }
    printf("\n");



}
