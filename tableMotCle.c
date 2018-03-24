#include "tableMotCle.h"

motCle tableMotCle []={
{"program","program",PROGRAM},
{"var","var",VAR},
{"integer","integer",PROGRAM},
{"char","char",CHAR},
{"begin","begin",BEGIN},
{"end","end",END},
{"if","if",IF},
{"then","then",THEN},
{"else","else",ELSE},
{"while","while",WHILE},
{"do","do",DO},
{"read","read",READ},
{"readln","readln",READLN},
{"write","write",WRITE},
{"writeln","writeln",WRITELN}
};

result rechercheMotCle (char * chaine){
    int trouve = 0;
    int i = 0;
    do{
        if(strcmp(chaine,tableMotCle[i].lexeme)==0){
            trouve=1;
        }else{
            i++;
        }
    }while (!trouve && i<15);
    if (trouve){
        result res;
        copieChaine(&res.uniteLex,tableMotCle[i].uniteLex);
        res.code=tableMotCle[i].code;
        return res;
    }else{
        result res;res.uniteLex=NULL;res.code=-1;
        return res;
    }

}
