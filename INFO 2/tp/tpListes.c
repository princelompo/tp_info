#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct Employe{
    char nom[20];
    char prenom[20];
    int age;
    char adresse[20];
    float salaire;
    struct Employe *suivant;
}Employe;

Employe* initialiser(){

}

Employe* creerEmploye(char name[], char lastname[], int x, char adress[], float sal){
    Employe* NE = (Employe*)malloc(sizeof(Employe));
    if(NE == NULL){
        printf("erreur d'allocation dynamique de memoire");
        return 0;
    }
    NE->age = x;
    NE->salaire = sal;
    strcpy(NE->nom, name);
    strcpy(NE->prenom, lastname);
    strcpy(NE->adresse, adress);
    NE->suivant = NULL;

    return NE;
}

void afficher(Employe* tete){
    Employe* temp = tete;
    while(temp != NULL){
        printf("%s %s %s %d %f da \n",temp->nom,temp->prenom,temp->adresse,temp->age,temp->salaire);
        temp = temp->suivant;
    }
}

Employe* insereDebut(Employe* liste,Employe* àInserer){
    àInserer->suivant = liste;

    return àInserer;

}

Employe* insererMillieu(Employe* list, Employe* àInserer){
    Employe *temp = list->suivant->suivant;
    temp->suivant = àInserer;
    àInserer->suivant = temp->suivant->suivant;

    return list;

}









int main(){

    Employe* E1= creerEmploye("Ahmed1", "SORE", 20, "Oran", 15000);
    Employe* E2= creerEmploye("Ahmed2", "SORE", 21, "Oran", 15000);
    Employe* E3= creerEmploye("Ahmed3", "SORE", 22, "Oran", 15000);
    Employe* E4= creerEmploye("Ahmed4", "SORE", 23, "Oran", 15000);

    Employe* E5= creerEmploye("Ahmed5", "SOOPP", 24, "PARIS", 1555500);
    Employe* E6= creerEmploye("Ahmed6", "SORE", 26, "Oran", 15000);



    E1->suivant = E2;
    E2->suivant = E3;
    E3->suivant = E4;

    afficher(E1);
    printf("\n\n\n");
    insereDebut(E1,E5);

    afficher(E5);





    return 0;

}
