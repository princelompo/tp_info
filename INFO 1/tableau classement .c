#include<stdio.h>

int main()
{
    int t[10],l,j,inter;

    printf("\n");

    for(l=0;l<=9;l++){
        printf("  Entrer element %d : ",l+1);
        scanf("%d",&t[l]);
    }
    printf ("\n");

    printf("  Tableau = ");
    for(l=0;l<=9;l++){
        printf("|%d|  ",t[l]);
     }
    printf ("\n");
    printf ("\n");

    printf("  Classement par ordre croissant \n");
    printf ("\n");

    for(l=0;l<=8;l++){
        for(j=l+1;j<=9;j++){
            if(t[l] > t[j]){
                inter=t[l];
                t[l]=t[j];
                t[j]=inter;
            }
        }
    }
    printf("  New tab = ");
    for(l=0;l<=9;l++){
        printf("|%d|  ",t[l]);

    }
    printf ("\n");
    printf ("\n");



     system("pause");


}
