#ifndef TABLEMOTCLE_H_INCLUDED
#define TABLEMOTCLE_H_INCLUDED

#include <string.h>
#include <stdlib.h>
#include"chaine.h"

#define PROGRAM	0
#define VAR	    1
#define INTEGER	2
#define CHAR    3
#define BEGIN	4
#define END	    5
#define IF	    6
#define THEN	7
#define ELSE	8
#define WHILE	9
#define DO	    10
#define READ	11
#define READLN	12
#define WRITE	13
#define WRITELN	14
#define INFEG	15
#define DIFF	16
#define INF	    17
#define EGAL 	18
#define SUPEG	19
#define SUP	    20
#define IDENTIF	21
#define PARGAUCHE 22
#define PARDROITE 23
#define OPAFF   24
#define ADD   25
#define SUB   26
#define OR    27
#define MULT  28
#define DIV   29
#define MOD   30
#define AND   31
#define POINT 32
#define POINTVR 33
#define NB      34
#define BLANC  35
#define PTPT  36
#define VR  36




typedef struct{
    char * lexeme;
    char * uniteLex ;
    int code;
} motCle;

typedef struct{
    char * uniteLex ;
    char * lexeme;
    int code;
} result;

result rechercheMotCle (char *);

#endif // TABLEMOTCLE_H_INCLUDED
