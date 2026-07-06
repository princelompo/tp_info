#include<stdio.h>
main()
{

    int nbr, mod, inv;

    printf("\n");

    do{
        printf(" Entrer la valeur de N : ");
        scanf("%d",&nbr);
    }
    while(nbr<=0);

    printf("\n");

    inv=0;
    while(nbr>0){
        mod = nbr%10 ;
        inv= inv*10 + mod ;
        nbr=nbr/10;
    }
    printf(" Le nomre inverse est : %d \n",inv);

        printf("\n");

    system("pause");







}
