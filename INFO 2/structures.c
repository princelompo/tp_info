#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(){

    struct PLAYER {
        char nom_du_joueur[20];
        int points_de_vie;
        float score_de_jeu;
        char cri_de_coup[20]; 
        char arme_utilisé[20];
    };

    struct PLAYER player1;
    strcpy(player1.cri_de_coup,"BOUUMMM");
    player1.points_de_vie = 19;

    struct PLAYER player2 = {"Naruto",100,2455.669,"OAAAHHHHHH","mitrailleuse"};

    printf(" Nom : %s\n Points de vie : %d\n Score : %f\n Cri de coup : %s\n Arme preferee : %s\n ",player2.nom_du_joueur,player2.points_de_vie,player2.score_de_jeu,player2.cri_de_coup,player2.arme_utilisé);

    // printf("%d  %s \n",player1.points_de_vie,player1.cri_de_coup);




    return 0;

}
