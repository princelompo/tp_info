#include<stdio.h>
int main()
{
    int pgcd(int a, int b){
        while(b!=0){
            int temp = b;
            b=a%b;
            a=temp;
        }
        return a;
    }

    int n,m;
    printf(" Entrer une valeur 1 : ");
    scanf("%d",&m);
    printf(" Entrer une valeur 2 : ");
    scanf("%d",&n);
    printf(" Leur pgcd est %d ",pgcd(n,m));






    printf("\n");
    system("pause");


}
