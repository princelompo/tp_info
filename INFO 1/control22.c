#include<stdio.h>
main()

{



    int i,n;
    float s,m,p,nbr;

    printf("\n");
    printf(" Ce programme vous demande le nombre de nombre n que vous souhaitez manipuler, puis calcule leur somme, produit, et leur moyenne. \n ");
    printf("\n");

    while(n<=0){
        printf(" Entrer la valeur de n : ");
        scanf("%d",&n);
    }

    printf("\n");

    i=1;
    s=0;
    p=1;

    while(i<=n){
        printf(" Entrer la valeur du nombre numero %d : ",i);
        scanf("%f",&nbr);
        s=s+nbr;
        p=p*nbr;
        i++;
    }
    m=s/n;
    printf("\n");
    printf(" La somme est s = %f \n",s);
    printf(" Le produit est p = %f \n",p);
    printf(" La moyenne est m = %f \n",m);
    printf("\n");


    system("pause");


}
