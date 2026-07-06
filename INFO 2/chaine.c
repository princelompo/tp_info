#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int nb_mots(char *ptr){
    int count = 1;
    while(*ptr != '\0'){
        if(isspace(*ptr)){
            count++;
        }
        ptr++;
    }
    return count;
}

int main(){
    
    char phr[50] = {"Bonjour a tous comment allez vous"};

    printf("%d mots trouves \n",nb_mots(phr));




    return 0;
}