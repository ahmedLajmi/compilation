#include "tableId.h"


id * tableIdent = NULL;
int cpt =0;

void afficherTable(void ){
    while(tableIdent!=NULL){
        printf("%s \n",tableIdent->lexeme);
        tableIdent=tableIdent->next;
    }
}

void ajouterType(char * lexeme,char * type){
    int trouve = 0,stop=0;
    id * aux = tableIdent;

    do{
        if(strcmp(lexeme,aux->lexeme)==0){
            trouve=1;
        }else if(aux->next != NULL){
            aux=aux->next;
        }else{
            stop=1;
        }
    }while(!trouve && !stop);
    if(aux != NULL){
        copieChaine(&(aux->type),type);
    }

}

char * getType(char * lexeme){
    int trouve = 0,stop=0;
    id * aux = tableIdent;

    do{
        if(strcmp(lexeme,aux->lexeme)==0){
            trouve=1;
        }else if(aux->next != NULL){
            aux=aux->next;
        }else{
            stop=1;
        }
    }while(!trouve && !stop);
    if(aux != NULL){
        return aux->type ;
    }
}

result rechercheIdent(char * chaine,int type){

    result res ;
    if(tableIdent == NULL){
        tableIdent = malloc(sizeof(id));
        tableIdent->code=cpt;
        if(type == NB){
            copieChaine(&tableIdent->uniteLex,"nb");
        }else{
            copieChaine(&tableIdent->uniteLex,"id");
        }
        copieChaine(&tableIdent->lexeme,chaine);
        tableIdent->next=NULL;
        copieChaine(&res.uniteLex,tableIdent->uniteLex);
        copieChaine(&res.lexeme,chaine);
        res.code=cpt;
        cpt++;
    }else{
        int trouve = 0,stop=0;;
        id * aux = tableIdent;
        do{
            if(strcmp(chaine,aux->lexeme)==0){
                trouve=1;
            }else if(aux->next != NULL){
                aux=aux->next;
            }else{
                stop=1;
            }
        }while(!trouve && !stop);
        if(trouve){
            copieChaine(&res.uniteLex,aux->uniteLex);
            copieChaine(&res.lexeme,chaine);
            res.code=aux->code;
        }else{
            id * nouvel = malloc(sizeof(id));
            nouvel->code=cpt;
            if(type == NB){
                copieChaine(&nouvel->uniteLex,"nb");
                nouvel->type = "integer";
            }else{
                copieChaine(&nouvel->uniteLex,"id");
                nouvel->type = "unknown";
            }
            copieChaine(&nouvel->lexeme,chaine);
            copieChaine(&res.lexeme,chaine);
            nouvel->next=NULL;
            aux->next = nouvel;
            copieChaine(&res.uniteLex,nouvel->uniteLex);
            res.code=cpt;
            cpt++;
        }
    }
    return res ;
}
