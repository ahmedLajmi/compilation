#include "chaine.h"



void copieChaine(char ** ch1, char * ch2){
    int i,taille = strlen(ch2)+1;
    char * ch;
    ch= malloc(taille*sizeof(char));
    for(i=0;i<taille;i++){
        ch[i] = ch2[i];
    }
    * ch1 = ch;
}
