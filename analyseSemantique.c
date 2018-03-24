#include "analyseSemantique.h"



void remplirType(){

    int fin =0,var=0,begin=0,op = 0;
    char * type ;
    struct noeud * racine = getRacine();
    struct listeId * liste = NULL;
    struct listeId * listeAux = NULL;
    struct fils * aux = racine->listeFils;

    while(aux->contenuFils->listeFils != NULL){
        aux = aux->contenuFils->listeFils;
    };

    while(!fin){
        if(aux->contenuFils->listeFils != NULL){
            while(aux->contenuFils->listeFils != NULL){
                aux = aux->contenuFils->listeFils;
            };
            if(strcmp(aux->contenuFils->val,"var")==0){
                var=1;
            }
            if(strcmp(aux->contenuFils->val,"begin")==0){
                begin=1;
                liste = NULL;
            }//printf("ul = %s\n",aux->contenuFils->val);
            if(begin){
                // traitement variable non declare
                if((strcmp(aux->contenuFils->val,"id")==0)){
                    printf("ul =%s \n",aux->contenuFils->donn.lexeme);
                    op=1;
                    if((strcmp(getType(aux->contenuFils->donn.lexeme),"unknown")==0)){
                        printf("Erreur dans %s : Variable non declare \n",aux->contenuFils->donn.lexeme);
                        exit(0);
                    }
                }
                if(!isupper(aux->contenuFils->val[0]) && (strcmp(aux->contenuFils->val,"id") && strcmp(aux->contenuFils->val,"nb") &&
                   strcmp(aux->contenuFils->val,"opadd") && strcmp(aux->contenuFils->val,"oprel") &&
                   strcmp(aux->contenuFils->val,"opmul") && strcmp(aux->contenuFils->val,"opaff"))){
                    op = 0;
                    type=NULL;
                }
                if(!strcmp(aux->contenuFils->val,"id") || !strcmp(aux->contenuFils->val,"nb")){
                    if(liste == NULL){
                        liste = malloc(sizeof(struct listeId));
                        liste->noeud = aux->contenuFils;
                        liste->suiv = NULL;
                    }else{
                        listeAux = liste;
                        while(listeAux->suiv != NULL){
                            listeAux = listeAux->suiv;
                        }
                        listeAux->suiv = malloc(sizeof(struct listeId));
                        (listeAux->suiv)->noeud = aux->contenuFils;
                        (listeAux->suiv)->suiv = NULL;
                    }
                }
                // verfi de type dans une instruction
                if(!op){
                    if(liste!= NULL){
                        listeAux = liste;
                        copieChaine(&type,getType(liste->noeud->donn.lexeme));
                        //printf("%s \n",type);
                        while(listeAux != NULL){
                            //printf("%s\t",listeAux->noeud->donn.lexeme);
                            if(strcmp(getType(listeAux->noeud->donn.lexeme),type)){
                                printf("\nErreur type : %s n'est pas compatible avec %s \n",type,getType(listeAux->noeud->donn.lexeme));
                                exit(0);
                            }
                            listeAux = listeAux->suiv;
                        }
                        liste = NULL;
                    }
                }
            }
            if(var && liste == NULL && (strcmp(aux->contenuFils->val,"id")==0)){
                liste = malloc(sizeof(struct listeId));
                liste->noeud = aux->contenuFils;
                liste->suiv = NULL;
            }
            else if(var && liste != NULL && (strcmp(aux->contenuFils->val,"id")==0)){
                listeAux = liste;
                while(listeAux->suiv != NULL){
                    listeAux = listeAux->suiv;
                }
                listeAux->suiv = malloc(sizeof(struct listeId));
                (listeAux->suiv)->noeud = aux->contenuFils;
                (listeAux->suiv)->suiv = NULL;
            }
            if(strcmp(aux->contenuFils->val,"char")==0 || strcmp(aux->contenuFils->val,"integer")==0){
                var=0;
                do{
                    if(strcmp(getType(liste->noeud->donn.lexeme),"unknown")!=0){
                        printf("Erreur : La variable %s est declare 2 fois\n",liste->noeud->donn.lexeme);
                        exit(0);
                    }
                    ajouterType(liste->noeud->donn.lexeme,aux->contenuFils->val);
                    liste = liste->suiv;
                }while(liste != NULL);
            }
        }
        else{
           if(strcmp(aux->contenuFils->val,"var")==0){
                var=1;
           }
           if(strcmp(aux->contenuFils->val,"begin")==0){
                begin=1;
                liste = NULL;
            }
            if(begin){
                // traitement variable non declare
                if((strcmp(aux->contenuFils->val,"id")==0)){
                        printf("ul =%s \n",aux->contenuFils->donn.lexeme);
                    op=1;
                    if((strcmp(getType(aux->contenuFils->donn.lexeme),"unknown")==0)){
                        printf("Erreur dans %s : Variable non declare \n",aux->contenuFils->donn.lexeme);
                        exit(0);
                    }
                }
                if(!isupper(aux->contenuFils->val[0]) && (strcmp(aux->contenuFils->val,"id") && strcmp(aux->contenuFils->val,"nb") &&
                   strcmp(aux->contenuFils->val,"opadd") && strcmp(aux->contenuFils->val,"oprel") &&
                   strcmp(aux->contenuFils->val,"opmul") && strcmp(aux->contenuFils->val,"opaff"))){
                    op = 0;
                    type=NULL;
                }
                if(!strcmp(aux->contenuFils->val,"id") || !strcmp(aux->contenuFils->val,"nb")){
                    if(liste == NULL){
                        liste = malloc(sizeof(struct listeId));
                        liste->noeud = aux->contenuFils;
                        liste->suiv = NULL;
                    }else{
                        listeAux = liste;
                        while(listeAux->suiv != NULL){
                            listeAux = listeAux->suiv;
                        }
                        listeAux->suiv = malloc(sizeof(struct listeId));
                        (listeAux->suiv)->noeud = aux->contenuFils;
                        (listeAux->suiv)->suiv = NULL;
                    }
                }
                // verfi de type dans une instruction
                if(!op){
                    if(liste!= NULL){
                        listeAux = liste;
                        copieChaine(&type,getType(liste->noeud->donn.lexeme));
                        //printf("%s \n",type);
                        while(listeAux != NULL){
                            //printf("%s\t",listeAux->noeud->donn.lexeme);
                            if(strcmp(getType(listeAux->noeud->donn.lexeme),type)){
                                printf("\nErreur type : %s n'est pas compatible avec %s \n",type,getType(listeAux->noeud->donn.lexeme));
                                exit(0);
                            }
                            listeAux = listeAux->suiv;
                        }
                        liste = NULL;
                    }
                }
            }
            if(var && liste == NULL && (strcmp(aux->contenuFils->val,"id")==0)){
                liste = malloc(sizeof(struct listeId));
                liste->noeud = aux->contenuFils;
                liste->suiv = NULL;
            }
            else if(var && liste != NULL && (strcmp(aux->contenuFils->val,"id")==0)){
                listeAux = liste;
                while(listeAux->suiv != NULL){
                    listeAux = listeAux->suiv;
                }
                listeAux->suiv = malloc(sizeof(struct listeId));
                (listeAux->suiv)->noeud = aux->contenuFils;
                (listeAux->suiv)->suiv = NULL;
            }
            if(strcmp(aux->contenuFils->val,"char")==0 || strcmp(aux->contenuFils->val,"integer")==0){
                    var=0;
                    do{
                        if(strcmp(getType(liste->noeud->donn.lexeme),"unknown")!=0){
                            printf("Erreur : La variable %s est declare 2 fois\n",liste->noeud->donn.lexeme);
                            exit(0);
                        }
                        ajouterType(liste->noeud->donn.lexeme,aux->contenuFils->val);
                        liste = liste->suiv;
                    }while(liste != NULL);
                }
        }
        // condition arret et avancement
        if(strcmp(aux->contenuFils->val,"point")==0){
            fin =1 ;
        }else{
            while(aux->suiv == NULL){
                aux = getFilsContenant(aux->contenuFils->pere);
            }
            aux=aux->suiv;
        }

    };





/* parcours feuille arbre */


fin = 0;
aux = racine->listeFils;

    while(aux->contenuFils->listeFils != NULL){
        aux = aux->contenuFils->listeFils;
    };

    while(!fin){
        if(aux->contenuFils->listeFils != NULL){
            while(aux->contenuFils->listeFils != NULL){
                aux = aux->contenuFils->listeFils;
            };
            if(strcmp(aux->contenuFils->val,"id")==0){
                printf("%s = %s \n",aux->contenuFils->val,getType(aux->contenuFils->donn.lexeme));
            }
            else if(!strcmp(aux->contenuFils->val,"opadd") || !strcmp(aux->contenuFils->val,"oprel") ||
                   !strcmp(aux->contenuFils->val,"opmul") || !strcmp(aux->contenuFils->val,"opaff")){
                printf("%s = %s \n",aux->contenuFils->val,aux->contenuFils->donn.lexeme);
            }
            else if (!isupper(aux->contenuFils->val[0])){
                printf("%s  \n",aux->contenuFils->val);
            }
        }else{
            if(strcmp(aux->contenuFils->val,"id")==0){
                printf("%s = %s \n",aux->contenuFils->val,getType(aux->contenuFils->donn.lexeme));
            }
            else if(!strcmp(aux->contenuFils->val,"opadd") || !strcmp(aux->contenuFils->val,"oprel") ||
                   !strcmp(aux->contenuFils->val,"opmul") || !strcmp(aux->contenuFils->val,"opaff")){
                printf("%s = %s \n",aux->contenuFils->val,aux->contenuFils->donn.lexeme);
            }
            else if (!isupper(aux->contenuFils->val[0])){
                printf("%s  \n",aux->contenuFils->val);
            }
        }
        // condition arret et avancement
        if(strcmp(aux->contenuFils->val,"point")==0){
            fin =1 ;
        }else{
            while(aux->suiv == NULL){
                aux = getFilsContenant(aux->contenuFils->pere);
            }
            aux=aux->suiv;
        }

    };


}
