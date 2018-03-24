#ifndef ANALYSESYNTAXIQUE_H_INCLUDED
#define ANALYSESYNTAXIQUE_H_INCLUDED

#include <ctype.h>
#include "analyseLexicale.h"
#include "pile.h"
#include "tableM.h"
#include "arbre.h"


void constArbreAbsrait(FILE * fichier) ;
struct noeud * getRacine();

#endif // ANALYSESYNTAXIQUE_H_INCLUDED
