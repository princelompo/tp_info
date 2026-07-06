#include<stdio.h>
main()
{

  printf("\n");
  printf(" Ce programme vous demande un nombre de lignes pour y construi un triangle isocele \n");
  printf("\n");

  int i,j,n;

  printf(" Entrer le nombre de lignes correspondant : ");
  scanf("%d",&n);
  printf("\n");

  // boucle pour chaque ligne
  for(i=1;i<=n;i++){
    // boucle pour chaque colone
    for(j=i;j<n;j++){
        // affichage d'espace
        printf(" ");
    }
    // affichage des étoiles
    for(j=1;j<=(2*i-1);j++){
        printf("J");
    }
    // retourner à la ligne suivante
    printf("\n");

  }
  printf("\n");


      system("pause ");


  }
























