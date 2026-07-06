

#include<stdlib.h>
#include<stdio.h>
int main()
{

    int  J,H;
    printf("Give the number of the day to ferify_______ : ");
    scanf("%d",&J);
    printf("Give the corresponding hours H______________: ");
    scanf("%d",&H);

      if((H>=7 && H<=13 && J!=2)||(H>=16 && H<=20 && J!=2 && J!=1)){
        printf("Bakery opened \n");
        while(J>6 || J<0 || H<0 || H>23){
        printf(" ERROR ");
        }
      }

        else{
        printf("Bakery closed \n");

      }




system("pause");


}
