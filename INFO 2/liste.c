#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct listElement{
    int value;
    struct listElement *next;
}listElement;

listElement *create_node(int valeur){
    listElement *nouveau = malloc(sizeof(listElement));
    if(nouveau == NULL){
        printf("Erreur d'allocation dynamique de memoire\n");
        return NULL;
    }
    nouveau->value = valeur;
    nouveau->next = NULL;

    return nouveau;
}

listElement *push_to_head(listElement *list, int valeur){
    listElement *nouvelle_tete = create_node(valeur);
    nouvelle_tete->next = list;

    return nouvelle_tete;    
}

listElement *push_to_end(listElement *list, int valeur){
    listElement *noeud_fin = create_node(valeur);

    if(list == NULL){
        return noeud_fin;
    }

    listElement *temp = list;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = noeud_fin;

    return list;
}

listElement *push_to_position(listElement *list, int valeur, int position){
    listElement *nouveau = create_node(valeur);
    
    if(position < 0){
        printf("Erreur de position !!\n");
        free(nouveau);
        return list;
    }
    if(position == 0){
        nouveau->next = list;
        return nouveau;
    }

    int index = 0;
    listElement *temp = list;
    while(index < position - 1 && temp != NULL){
        temp = temp->next;
        index++;
    }
    if(temp == NULL){
        printf("Position trop grande !\n");
        free(nouveau);
        return list;
    }
    nouveau->next = temp->next;
    temp->next = nouveau;

    return list;
}

listElement *delete_to_head(listElement *head){
    if(head == NULL){
        printf("Liste vide \n");
        return NULL;
    }
    listElement *temp = head;
    head = head->next;
    free(temp);

    return head;
}

listElement *delete_to_end(listElement *final){
    if(final == NULL){
        printf("Liste vide !!\n");
        return NULL;
    }
    if(final->next == NULL){
        free(final);
        return NULL;
    }

    listElement *temp = final;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;

    return final;
}

int search_value(listElement *list, int valeur){
    int position = 0;
    listElement *temp = list;
    while(temp != NULL){
        if(temp->value == valeur){
            return position;
        }
        position ++;
        temp = temp->next;
    }
    return -1; // valeur non trouvée
}

void afficher_list(listElement *list){
    if(list == NULL){
        printf("Votre liste est vide.\n");
        return;
    }
    while(list != NULL){
        printf(" %d\t", list->value);
        list = list->next;
    }
    printf("\n");
}

int main(){

    listElement *ma_liste = create_node(66);
    afficher_list(ma_liste);
    ma_liste = push_to_head(ma_liste, 55);
    afficher_list(ma_liste);
    ma_liste = push_to_end(ma_liste, 77);
    afficher_list(ma_liste);
    ma_liste = push_to_position(ma_liste, 44, 2);
    afficher_list(ma_liste);


    return 0;
}







