#include<stdio.h>
main()
{
    int i,a,b,p;

    printf("entrer la valeur da a : ");
    scanf("%d",&a);
    printf("entrer la valeur da b : ");
    scanf("%d",&b);

    p=0;
    for(i=1;i<=b;i++){
            p=p+a;
        }
    printf(" le produit est p = %d ",p);




}
