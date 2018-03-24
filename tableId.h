#ifndef TABLEID_H_INCLUDED
#define TABLEID_H_INCLUDED

#include "tableMotCle.h"
#include <stdlib.h>


typedef struct{
    char * lexeme;
    char * uniteLex ;
    char * type ;
    int code;
    struct id * next;
} id ;

void afficherTable(void );
result rechercheIdent(char *,int);
void ajouterType(char * lexeme,char * type);
char * getType(char * lexeme);


#endif // TABLEID_H_INCLUDED
