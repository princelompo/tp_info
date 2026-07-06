#include<stdio.h>
main()

{
        int i,j;

        printf("\n");

        printf(" X*Y\t|\t");
        for(i=1;i<=10;i++){
            printf("%d\t",i);
        }
        printf("\n");

        for(i=1;i<=10;i++){
            printf("_ _ _ _ _");
        }
        printf("\n");

        for(i=1;i<=10;i++){
            printf(" %d\t|\t",i);
            for(j=1;j<=10;j++){
                printf("%d\t",i*j);
            }
            printf("\n");
        }







}
