#include<stdio.h>
main()
{
    //prinf("  m et n sont amis si la somme des diviseurs de m est egal à n et vice versa");

    int n,m,i,d1,d2;

    printf("\n");
    printf("  m et n sont amis si la somme des diviseurs de m est egal a n et vice versa");
    printf("\n");
    printf("\n");

    printf("  Enntrer la valeur de m : ");
    scanf("%d",&m);
    printf("  Enntrer la valeur de n : ");
    scanf("%d",&n);

    printf("\n");

    d1 = 0 ;
    for(i=2;i<=n-1;i++){
        if(n%i==0){
            d1=d1+i;
        }
    }
    printf("  d1 = %d \n",d1);

    d2 = 0 ;
    for(i=2;i<=m-1;i++){
        if(m%i==0){
            d2=d2+i;
        }
    }
    printf("  d2 = %d \n",d2);

    printf("\n");


    if(d1==m && d2==n){
        printf(" m et n sont amis ");
    }
    else{
        printf(" m et n ne sont pas amis ");
    }

    system("pause");

















}
