#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int main(){

    int size;

    printf("Entrer la taille du tableau : ");
    scanf("%d",&size);

    int *arr = (int*)malloc(size*sizeof(int));
    if(arr == NULL){
        printf("Erreur d'allocation \n");
        return 0;
    }

    for(int i = 0; i < size; i++){
        printf("Entrer la valeur : ");
        scanf("%d",(arr++));
    }

    for(int *p = arr; p < size; p++){
        for(int *q = arr+1; q < size; q++){
            if( *q > *p){
                int temp = *p;
                *p = *q;
                *q = temp;
            }
        }
    }
    for(int i = 0; i < size; i++){
        printf("%d\t",*(arr++));
    }


    return 0;
}
