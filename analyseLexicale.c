#include"analyseLexicale.h"

result getNext (FILE * fichier){
    result res;
    char * chaine = malloc(10*sizeof(char));
    char c ;
    if (fichier != NULL ){
        c = lireCar(fichier);
        if (c == '('){
            c = lireCar(fichier);
            int stop =0;
            if(c== '*'){
                do{
                    c = lireCar(fichier);
                    if (c=='*'){
                        c= lireCar(fichier);
                        if (c==')'){
                            stop=1;
                        }else if(c==EOF)
                            stop=1;
                    }
                }while (!stop);
                c= lireCar(fichier);
            }else{
                delireCar(c,fichier);
                copieChaine(&res.uniteLex,"pargauche");
                res.code=PARGAUCHE;
                return res;
            }
        }
        if (c == '('){
            copieChaine(&res.uniteLex,"pargauche");
            res.code=PARGAUCHE;
            return res;
        }
        else if (c == ')'){
            copieChaine(&res.uniteLex,"pardroite");
            res.code=PARDROITE;
            return res;
        }
        else if (c == '<'){
            c = lireCar(fichier);
            if (c == '='){
                copieChaine(&res.uniteLex,"oprel");
                copieChaine(&res.lexeme,"<=");
                res.code=INFEG;
                return res;
            }
            else if (c == '>'){
                copieChaine(&res.uniteLex,"oprel");
                copieChaine(&res.lexeme,"<>");
                res.code=DIFF;
                return res;
            }
            else {
                delireCar(c,fichier);
                copieChaine(&res.uniteLex,"oprel");
                copieChaine(&res.lexeme,"<");
                res.code=INF;
                return res;
            }
        }
        else if (c == '>'){
            c = lireCar(fichier);
            if (c == '='){
                copieChaine(&res.uniteLex,"oprel");
                copieChaine(&res.lexeme,">=");
                res.code=SUPEG;
                return res;
            }
            else {
                delireCar(c,fichier);
                copieChaine(&res.uniteLex,"oprel");
                copieChaine(&res.lexeme,">");
                res.code=SUP;
                return res;
            }
        }
        else if (c == '='){
            c = lireCar(fichier);
            if(c== '='){
                copieChaine(&res.uniteLex,"oprel");
                copieChaine(&res.lexeme,"==");
                res.code=EGAL;
                return res;
            }
            else{
                printf("Il manque un autre signe d'egale\n");
                exit(0);
            }
        }
        else if (c == ':'){
            c = lireCar(fichier);
            if(c== '='){
                copieChaine(&res.uniteLex,"opaff");
                copieChaine(&res.lexeme,":=");
                res.code=OPAFF;
                return res;
            }
            else{
                delireCar(c,fichier);
                copieChaine(&res.uniteLex,"ptpt");
                res.code=PTPT;
                return res;
            }
        }
        else if (c == '+'){
            copieChaine(&res.uniteLex,"opadd");
            copieChaine(&res.lexeme,"+");
            res.code=ADD;
            return res;
        }
        else if (c == '-'){
            copieChaine(&res.uniteLex,"opadd");
            copieChaine(&res.lexeme,"-");
            res.code=SUB;
            return res;
        }
        else if (c == '|'){
            c = lireCar(fichier);
            if (c == '|'){
                copieChaine(&res.uniteLex,"opadd");
                copieChaine(&res.lexeme,"||");
                res.code=OR;
                return res;
            }
            else{
                printf("Il manque un autre barre \n");
                exit(0);
            }
        }
        else if (c == '&'){
           c = lireCar(fichier);
           if (c == '&'){
               copieChaine(&res.uniteLex,"opmul");
               copieChaine(&res.lexeme,"&");
               res.code=AND;
               return res;
           }
           else{
               printf("Il manque un autre et \n");
               exit(0);
           }
        }
        else if (c == '.'){
            copieChaine(&res.uniteLex,"point");
            res.code=POINT;
            return res;
        }
        else if (c == ';'){
            copieChaine(&res.uniteLex,"pointvr");
            res.code=POINTVR;
            return res;
        }
        else if (c == ','){
            copieChaine(&res.uniteLex,"vr");
            res.code=VR;
            return res;
        }
        else if (c == '*'){
            copieChaine(&res.uniteLex,"opmul");
            copieChaine(&res.lexeme,"*");
            res.code=MULT;
            return res;
        }
        else if (c == '/'){
            copieChaine(&res.uniteLex,"opmul");
            copieChaine(&res.lexeme,"/");
            res.code=DIV;
            return res;
        }
        else if (c == '%'){
            copieChaine(&res.uniteLex,"opmul");
            copieChaine(&res.lexeme,"%");
            res.code=MOD;
            return res;
        }
        else if (estChiffre(c)){
            int i=0;
            int stop = 0;
            do{
                chaine[i]=c;
                c=lireCar(fichier);
                if(estChiffre(c)){
                    i++;
                    if(i%10 ==0)
                        realloc(chaine,10);
                }else{
                    delireCar(c,fichier);
                    stop =1;
                }
            }while(!stop);
            chaine[i+1]='\0';
            return rechercheIdent(chaine,NB);
        }
        else if (estLettre(c)){
            int i=0;
            int stop = 0;
            do{
                chaine[i]=c;
                c=lireCar(fichier);
                if(estChiffre(c) || estLettre(c)){
                    i++;
                    if(i%10 ==0)
                        realloc(chaine,10);
                }else{
                    delireCar(c,fichier);
                    stop =1;
                }
            }while(!stop);
            chaine[i+1]='\0';
            result res1 = rechercheMotCle(chaine);
            if(res1.code<0){
                return rechercheIdent(chaine,IDENTIF);
            }else{
                return res1;
            }

        }
        else if (estBlanc(c)){
            res.code=BLANC;
            copieChaine(&res.uniteLex,"blanc");
            return res;
        }
        else if (c==EOF){
            res.code=EOF;
            copieChaine(&res.uniteLex,"fin");
            return res ;
        }
        else{
            printf("Carractere non reconnu \n");
            exit(0);
        }
    }
    else{
        printf("Erreur dans l'ouverture du fichier \n");
        exit(0);
    }
}



