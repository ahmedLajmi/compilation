#ifndef TABLEM_H_INCLUDED
#define TABLEM_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int i,j;
} indice ;



indice rechercheIndice(char * term ,char * nTerm );
char ** getRegle(indice ind);

#endif // TABLEM_H_INCLUDED
