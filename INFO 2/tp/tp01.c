#include<stdio.h>
#include<stdlib.h>

int main(){

    int a = 1, b = 2;
    int *p = &a;
    int *q = p;
    a = 3;
    b = *q +10 ;

    printf("Les valeurs sont : a = %d ; b = %d ",a,b);



    return 0;
}
