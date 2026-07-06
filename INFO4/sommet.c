#include<stdio.h>
#include<stdlib.h>

int main(){

    int A[4][4] = {{0,1,1,1},{1,0,0,1},{0,0,0,1},{0,0,0,0}};

    int s = 0, nbr = 0;

    for(int i = 0; i < 4; i++){
        printf("Les successeurs de x%d sont : ",i+1);
        for(int j = 1; j < 4; j++){
            if(A[i][j] == 1){
                s +=1;
                printf("x%d  ",j+1);
            }
        }
        printf("\n");
        printf("Le nombre de successeurs de x%d est : %d ",i+1,s);
        s = 0;
        printf("\n\n");
    }

    printf("\n\n");

    for(int i = 0; i < 4; i++){
        printf("les predeccesseurs de x%d sont : ",i+1);
        for(int j = 0; j < 4; j++){
            if(A[j][i] == 1){
                s +=1;
                printf("x%d  ",j+1);
            }
        }
        printf("\n");
        printf("Le nombre de predeccesseurs de x%d est : %d ",i+1,s);
        s = 0;
        printf("\n\n");
    }

    system("pause");

    return 0;
}
