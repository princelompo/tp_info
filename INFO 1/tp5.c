#include<stdio.h>
main()
{


    int taille,i,sup,tab[200];
    printf("\n");

    printf("  Entrer la taille que vous souhaitez manipuler : ");
    scanf("%d",&taille);
    printf("\n");

    for(i=0;i<taille;i++){
        printf("  Entrer la valeur numero %d : ",i+1);
        scanf("%d",&tab[i]);
    }
    printf("\n");

    printf("  Tableau = ");
    for(i=0;i<taille;i++){
        printf(" |%d|   ",tab[i]);
     }

    printf("\n");
    printf("\n");

    printf("  Quelle case voulez vous supprimer ? : ");
    scanf("%d",&sup);

    printf("\n");

    for(i=sup-1;i<taille-1;i++){
        tab[i]=tab[i+1];
    }

    taille = taille - 1;
    printf("  Nouveau tableau =  ");
    for(i=0;i<taille;i++){
        printf(" |%d|   ",tab[i]);
    }


    printf("\n");
    printf("\n");


    system("pause");




}
