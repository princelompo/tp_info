#include<stdio.h>
main()


{
    float S;
    int i,n;

    printf("\n");
    printf("  Calcul de la somme des inverses de 1 allant a N. \n ");
    printf("\n");

    do{
        printf("  Entrer la valeur de N : ");
        scanf("%d",&n);
    }while(n<=0);

    S=0, i=1 ;
    while(i<=n){
        S=S+(1/(float)i);
        i++ ;
    }
    printf("\n");

    printf("  La somme est : %f \n",S);

    printf("\n");



    system("pause");

















}
