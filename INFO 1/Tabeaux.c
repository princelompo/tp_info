#include <stdio.h>
#include <stdbool.h>
int main()

{
  printf("\n");
  printf(" Vous entrer la taille d'un tableau,le remplissez ensuite; et le programme met la premiere moitie dans la deuxieme et vice versa, supprime les elements nuls et affiche sa nouvelle taille; et enfin vous entrer un nombre aleatoire et une fonction renvoie si cette valeur est dans ledit tableau ..! ");
  printf("\n");

  bool fonction(int A[],int y,int taille){
    int i;
    for(i=0;i<taille;i++){
        if(A[i]==y){
            return true;
        }
    }
  }
  int size,i,x,moitie,temp,newsize;

  printf("\n");

  printf(" Entrer la taille correspondante : ");
  scanf("%d",&size);

  printf("\n");

  int tab[size];
  for(i=0;i<size;i++){
    printf(" Entrer le nombre numero %d : ",i+1);
    scanf("%d",&tab[i]);
  }
  printf("\n");

  printf(" Tableau = ");
  for(i=0;i<size;i++){
    printf(" |%d|  ",tab[i]);
  }
  printf("\n");
  printf("\n");

  if (size%2==0){
    moitie = size/2 ;
  }
  else{
    moitie = size/2+1;
  }

  for(i=0;i<size/2;i++){
    temp = tab[i];
    tab[i]=tab[moitie+i];
    tab[moitie+i]=temp;
  }
  printf(" Nouveau tab = ");
  for(i=0;i<size;i++){
    printf(" |%d|  ",tab[i]);
  }
  newsize = size;
  for(i=0;i<size;i++){
    if (tab[i]== 0){
        tab[i]=tab[i+1];
        newsize--;
    }
  }
  printf("\n");
  printf("\n");

  printf(" Tableau sans zero = ");
  for(i=0;i<newsize;i++){
    printf(" |%d|  ",tab[i]);
  }
  printf("\n");
  printf("\n");

  printf(" La nouvelle taille est %d",newsize);

  printf("\n");
  printf("\n");

  printf(" Entrer le nombre a verifier : ");
  scanf("%d",&x);

  if (fonction(tab,x,size)== true){
    printf(" Cette valeur est dans le tableau");
  }
  else{
    printf(" OUFF!! Cette valeur n'est pas dans le tableau");
  }

  printf("\n");
  printf("\n");

  system("pause");



}

