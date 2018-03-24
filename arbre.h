#ifndef ARBRE_H_INCLUDED
#define ARBRE_H_INCLUDED

#include "tableMotCle.h"
#include <ctype.h>

struct noeud;
struct fils ;

struct noeud{
    // result info;
    char * val;
    char * type ;
    char * valeur ;
    result donn;
    struct noeud * pere;
    struct fils * listeFils ;
    int rang;
};

struct fils{
        struct noeud * contenuFils ;
        struct fils * suiv ;
};

struct retour{
        struct noeud * pereEnCours ;
        struct noeud * pereSauv ;
};

void arbreInit(struct noeud ** racine);
void afficherArbre(struct noeud * racine);
void ajouterFils(struct noeud * pere,char * val,int rang);
struct fils * getFrere(struct noeud * noeud);
struct fils * getFilsPlusGauche(struct noeud * noeud);
struct fils * getFilsContenant(struct noeud * noeud);


#endif // ARBRE_H_INCLUDED
