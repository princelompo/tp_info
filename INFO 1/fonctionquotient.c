#include<stdio.h>
int main()

 {

    float Quotient(int A, int B){
        if(B==0){
            printf(" Erreur !! \n");
            return 0 ;
        }
        return (float)A/B;
    }


    int n1,n2;

    printf(" entrer la valeur de n1 : ");
    scanf("%d",&n1);
    printf(" entrer la valeur de n2 : ");
    scanf("%d",&n2);

    float resultat = (Quotient(n1,n2)) ;
    if(n2 != 0){
        printf(" Le resutat est : %f", resultat);
        }
    return 0 ;


}

