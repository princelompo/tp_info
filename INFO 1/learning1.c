#include<stdio.h>
int main()

{
    float T[4][4] , S, M ;
    unsigned int i,j;

    printf("\n");

    printf("  Calcul de la moyenne de 4 eleves dans 4 matieres differentes. \n");

    printf("\n");

    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("   Put the mark of the student number %d in the matter %d : ",i+1,j+1);
            scanf("%f",&T[i][j]);
        }
    }
    printf("\n");

    for(i=0;i<4;i++){
        S=0;
        for(j=0;j<4;j++){
                S=S+T[i][j];
    }
    printf("\n");

    M=S/4;
    printf("     The moyen of the student number %d is %f \n",i+1,M);


    }
    printf("\n");

    system("pause");
}
