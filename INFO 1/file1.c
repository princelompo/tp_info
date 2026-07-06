#include<stdio.h>
main()

{
    float S ;
    int i,N;

    printf("\n");
    printf("  Calcul des inverses de 1 allant a N.2 \n ");
    printf("\n");

    do{
        printf("  Entrer la valeur de N : ");
        scanf("%d",&N);

    }
    while(N<=0);

    S=0;

    for(i=1;i<=N;i++){
        S=S+(1/(float)i) ;
    }
    printf("\n");

    printf("  La somme est egale a : %.3f \n", S);

    printf("\n");




    system("pause");










}
