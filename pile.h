#ifndef PILE_H_INCLUDED
#define PILE_H_INCLUDED
#include <stdlib.h>


typedef struct {
    char * val ;
    struct pile * suiv ;
} pile ;


void empiler (char * chaine);
void depiler ();
char * sommetPile ();

#endif // PILE_H_INCLUDED
