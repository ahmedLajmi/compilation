#include "pile.h"
#include <stdio.h>

pile * tete = NULL ;
pile * dernier = NULL;

void initPile (){
    tete = malloc(sizeof(pile));
    dernier=tete;
    copieChaine(&tete->val, "$");
    tete->suiv = NULL;
    dernier = tete;
}

void empiler (char * chaine){
    pile * nouvel = malloc(sizeof(pile));
    if (tete == NULL){
        initPile();
    }
    copieChaine(&nouvel->val, chaine);
    nouvel->suiv = NULL;
    dernier->suiv = nouvel;
    dernier = nouvel;
}
void depiler(){
    pile * aux ;
    aux = tete;
    while(aux != NULL && aux->suiv != dernier){
        aux = aux->suiv;
    };
    free(dernier);
    dernier=aux;
    aux->suiv = NULL;
}
char * sommetPile (){
    return dernier->val;
}

