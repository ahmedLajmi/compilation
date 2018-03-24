#include <stdio.h>
#include <stdlib.h>
#include "analyseSemantique.h"



int main()
{
    char chemin []  = "./Code Test/code 1.txt" ;
    FILE * fichier = ouvrirFichier(chemin);
    constArbreAbsrait(fichier);
    remplirType();

    return 0;
}
