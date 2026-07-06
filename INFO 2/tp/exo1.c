#include<stdio.h>
#include<stdlib.h>

int main(){

    int x, y;
    printf("Entrer la valeur de x : ");
    scanf("%d",&x);
    printf("Entrer la valeur de y : ");
    scanf("%d",&y);

    if(x == 0 && y == 0){
        printf("Origine du repere !\n");
    }
    if(x > 0){
        if(y > 0 ){
            printf("Partie A du repere \n");
        }else{
            printf("Partie D du repere \n");
        }
    }
    if(x < 0){
        if(y > 0 ){
            printf("Partie B du repere \n");
        }else{
            printf("Partie C du repere \n");
        }
    }

    return 0;
}