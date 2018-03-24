#ifndef ANALYSESEMANTIQUE_H_INCLUDED
#define ANALYSESEMANTIQUE_H_INCLUDED

#include<stdlib.h>
#include<ctype.h>
#include "analyseSyntaxique.h"

struct listeId{
    struct noeud * noeud ;
    struct listeId * suiv ;
};

void remplirType();

#endif // ANALYSESEMANTIQUE_H_INCLUDED
