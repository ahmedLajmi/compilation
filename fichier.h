#ifndef FICHIER_H_INCLUDED
#define FICHIER_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

FILE * ouvrirFichier (char *);

char lireCar(FILE * f);

void delireCar(char c,FILE * f);

int estBlanc(char c);

int estLettre(char c);

int estChiffre(char c);



#endif // FICHIER_H_INCLUDED
