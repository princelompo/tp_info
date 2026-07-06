#include<stdio.h>
#include<stdlib.h>

int main(){

    float salaire;
    float njrt;
    float jnt = 22;
    float salaire_total;

    printf("\n");

    printf("Entret le salaire correspondant : ");
    scanf("%d",&salaire);
    printf("Entrer le nombre de jours de  repos travaille : ");
    scanf("%d",&njrt);

    if(salaire < 15000){
        float ppj = 0.02*salaire;
        float psj = 200;
        salaire_total = ppj*jnt + psj*njrt + salaire;
    }

    if(salaire < 30000 && salaire >= 15000){
        float ppj = 0.015*salaire;
        float psj = 500;
        salaire_total = ppj*jnt + psj*njrt + salaire;
    }

    if(salaire >= 30000){
        float ppj = 0.01*salaire;
        float psj = 2000;
        salaire_total = ppj*jnt + psj*njrt + salaire;
    }

    printf("Le salaire est : %f da",salaire_total);


    return 0;
}