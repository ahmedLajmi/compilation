#include "arbre.h"
#include <ctype.h>

void arbreInit(struct noeud ** racine){
    struct noeud * aux ;
    if((*racine) == NULL){
        aux = malloc(sizeof(struct noeud));
        aux->val = "P" ;
        aux->pere = NULL;
        aux->listeFils = NULL ;
        aux->rang=0;
        *racine = aux;
    }
}

void ajouterFils(struct noeud * pere,char * val,int rang){
    struct fils * listeFils = pere->listeFils;
    struct fils * aux = listeFils; // variable pour le parcours de la liste
    struct fils * aux1 ; // variable pour le parcours de la liste
    struct noeud * contenu ;
    if (listeFils == NULL){
        listeFils = malloc(sizeof(struct fils));
        // remplir le contenu du fils avec une variable auxiliare appele contenu
        contenu = malloc(sizeof(struct noeud));
        contenu->val = val;
        contenu->type= "unknown";
        contenu->pere = pere;
        contenu->listeFils = NULL;
        contenu->rang=rang;
        listeFils->contenuFils = contenu;
        listeFils->suiv = NULL;
        pere->listeFils = listeFils;
    }
    else{
        while(aux->suiv != NULL){
            aux = aux->suiv;
        };
        contenu = malloc(sizeof(struct noeud));
        contenu->val = val;
        contenu->type= "unknown";
        contenu->pere = pere;
        contenu->listeFils = NULL;
        contenu->rang=rang;
        aux1 = malloc(sizeof(struct fils));
        aux1->contenuFils = contenu ;
        aux1->suiv = NULL;
        aux->suiv = aux1;

    }

}

struct fils * getFrere(struct noeud * noeud){
    struct fils * aux ;int i=0;
    aux = noeud->pere->listeFils;
    while(i<= noeud->rang){
        aux = aux->suiv;
        i++;
    };
    if(aux == NULL){
        aux = getFrere(noeud->pere);//printf("%s \n",aux->contenuFils->val);
    }
    if(!strcmp(aux->contenuFils->val,"point")){
        return aux ;
        //printf("%s 1\n",aux->contenuFils->val);
    }
    if(!isupper(aux->contenuFils->val[0])){
       // printf("%s 1\n",aux->contenuFils->val);
        if(strcmp(aux->contenuFils->val,"id")!=0 && strcmp(aux->contenuFils->val,"nb")!=0 &&
           strcmp(aux->contenuFils->val,"opadd")!=0 && strcmp(aux->contenuFils->val,"oprel")!=0 &&
           strcmp(aux->contenuFils->val,"opmul")!=0 && strcmp(aux->contenuFils->val,"opaff")!=0){
            aux = getFrere(aux->contenuFils);
        }else
            return aux;
    }
    if(!strcmp(aux->contenuFils->val,"BlancO")){
        aux = getFrere(aux->contenuFils);
        //printf("%s 1\n",aux->contenuFils->val);
    }


    return aux ;
}

struct fils * getFilsContenant(struct noeud * noeud){
    struct fils * aux ;int i=0;
    aux = noeud->pere->listeFils;
    while(i< noeud->rang){
        aux = aux->suiv;
        i++;
    };
    return aux;
}

struct fils * getFilsPlusGauche(struct noeud * noeud){
    struct fils * aux = noeud->listeFils ;
    if(aux != NULL){
        while(aux->contenuFils->listeFils != NULL){
            aux = aux->contenuFils->listeFils;
        };
    }else{
        aux = getFilsContenant(noeud);
    }
    return aux ;

}





void afficherArbre(struct noeud * racine){

    struct fils * listeFils;int i=0 ;
    printf("|- %s \n",racine->val);
    i++;
    listeFils = racine->listeFils;
    while(listeFils != NULL){
        afficherFils(listeFils->contenuFils,i);
        listeFils = listeFils->suiv;
    }
}

void afficherFils(struct noeud * fils,int niv){

    struct fils * listeFils;int i ;
    for(i=0;i<=niv;i++){
        printf("  ");
    }
    printf("|- %s \n",fils->val);
    listeFils = fils->listeFils;
    i=niv+1;
    while(listeFils != NULL){
        afficherFils(listeFils->contenuFils,i);
        listeFils = listeFils->suiv;
    }
}

