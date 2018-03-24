#include "analyseSyntaxique.h"

struct noeud * racine = NULL;

void constArbreAbsrait(FILE * fichier){


    result res;char ** regle;char * aux;int j,i=0;int blanc =0;char * type = NULL ;
    struct noeud * pereEnCours = NULL;
    struct noeud * pereSauv = NULL;
    empiler("P");
    arbreInit(&racine);
    pereEnCours = racine ;
    indice ind ;
    res=getNext(fichier);
        do{
            //printf("ul= %s \t code=%d \t sommet= %s   \n",res.uniteLex,res.code,sommetPile());
            //printf("%s = %s avec %s 1\n",pereEnCours->val,res.uniteLex,sommetPile());
            if(isupper(sommetPile()[0])==0){
                if(strcmp(sommetPile(),"epsilon")==0){
                    depiler();
                    continue;
                }
                if(strcmp(res.uniteLex,"blanc")==0){
                    while(strcmp(res.uniteLex,"blanc")==0){
                        res=getNext(fichier);
                    };
                    continue;
                }

                if(strcmp(sommetPile(),res.uniteLex)==0){
                    depiler();
                    if(!strcmp(pereEnCours->val,"id") || !strcmp(pereEnCours->val,"nb") ||
                        !strcmp(pereEnCours->val,"opadd") || !strcmp(pereEnCours->val,"oprel") ||
                        !strcmp(pereEnCours->val,"opmul") || !strcmp(pereEnCours->val,"opaff")){

                        if(!strcmp(res.uniteLex,"id") || !strcmp(res.uniteLex,"nb") ||
                           !strcmp(res.uniteLex,"opadd") || !strcmp(res.uniteLex,"oprel") ||
                           !strcmp(res.uniteLex,"opmul") || !strcmp(res.uniteLex,"opaff")){
                            //printf("%s = %s\n",pereEnCours->val,res.lexeme);
                            pereEnCours->donn = res;
                            pereEnCours = getFrere(pereEnCours)->contenuFils;
                        }
                            //ajouterFils(pereEnCours,regle[i],i);
                    }
                    // changer le pere
                    //pereEnCours = getFrere(pereEnCours)->contenuFils;
                    res=getNext(fichier);
                    continue;
                }
                else{
                    printf("Il manque %s",sommetPile());
                    exit(0);
                }
            }
            // traitement Non Terminal
            else if(isupper(sommetPile()[0])!=0){
                if(strcmp(sommetPile(),"BlancO")==0 && (strcmp(res.uniteLex,"blanc")==0)){
                    while(strcmp(res.uniteLex,"blanc")==0){
                        res=getNext(fichier);
                    };
                    depiler();
                    continue;
                }else if (strcmp(sommetPile(),"BlancO")==0 && (strcmp(res.uniteLex,"blanc")!=0)){
                    printf("Il manque un espace");
                    exit(0);
                }
                ind = rechercheIndice(res.uniteLex,sommetPile());
                regle = getRegle(ind);
                if (regle == NULL){
                    if(strcmp(res.uniteLex,"blanc")==0){
                        while(strcmp(res.uniteLex,"blanc")==0){
                        res=getNext(fichier);
                        };blanc=0;continue;
                    }else{
                        printf("i= %d \t j= %d avant erreur  \n",ind.i,ind.j);
                        printf("ul= %s \t sommet= %s avant erreur  \n",res.uniteLex,sommetPile());
                        printf("Programme non correcte 1\n");
                        exit(1);
                    }
                }else{
                    //calculer taille regle
                    while(regle[i] != NULL){
                        i++;
                    };
                    i--;j=i;
                    // depiler et empiler la nouvelle regle
                    depiler();
                    //printf("regle= ");
                    for (;i>=0;i--){
                        empiler(regle[i]);//printf("%s,",regle[i]);
                    }//printf("\n");
                    if(strcmp(regle[0],"epsilon")!=0){
                        for (i=0;i<=j;i++){
                            // ajout dans l'arbre
                            ajouterFils(pereEnCours,regle[i],i);
                            //printf("Ajout fils avec pere = %s \n",pereEnCours->val);
                        }
                        // changer le pere
                        pereEnCours = pereEnCours->listeFils->contenuFils ;

                        if( (!isupper(pereEnCours->val[0]) && strcmp(pereEnCours->val,"id") && strcmp(pereEnCours->val,"nb") &&
                             strcmp(pereEnCours->val,"opadd") && strcmp(pereEnCours->val,"oprel") &&
                             strcmp(pereEnCours->val,"opmul") && strcmp(pereEnCours->val,"opaff")) || !strcmp(pereEnCours->val,"BlancO")){
                            pereEnCours = getFrere(pereEnCours)->contenuFils;
                        }
                    }else{
                        pereEnCours = getFrere(pereEnCours)->contenuFils;
                    }
                    i=0;
                    blanc=0;
                }
            }
        }while(strcmp(sommetPile(),"$")!=0);
       //afficherArbre(racine);
}

struct noeud * getRacine(){
    return racine;
}
