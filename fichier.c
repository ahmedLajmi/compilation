#include "fichier.h"

FILE * ouvrirFichier (char * f){
    FILE * fichier = fopen(f,"r");
    return fichier ;
}

char lireCar(FILE * f) {
    return getc(f);
}

void delireCar(char c,FILE * f) {
    ungetc(c, f);
}

int estBlanc(char c) {
    return (c == ' ' || c == '\t' || c == '\n');
}

int estLettre(char c) {
    return (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'));
}

int estChiffre(char c) {
    return ('0' <= c && c <= '9');
}
