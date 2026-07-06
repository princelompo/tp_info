#include<stdio.h>
#include<stdlib.h>
main()
{
    int nbr,i;
    int *arr;
    printf("Entrer le nombre d'elements : ");
    scanf("%d",&nbr);
    arr=malloc(nbr*sizeof(int));
    if(arr==NULL){
        printf("Erreur d'allocation de memoire");
        exit(1);
    }
    for(i=0;i<nbr;i++){
        printf("Entrer l'element num %d du tableau : ",i+1);
        scanf("%i",&*(arr+i));
    }
    printf("\n");
    printf("Tableau : \t");
    for(i=0;i<nbr;i++){
        printf("%d \t",*(arr+i));
    }
    free(arr);

    printf("\n");
    printf("\n");

    return 0;

    system("pause");



}
