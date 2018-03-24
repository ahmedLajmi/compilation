#include "tableM.h"
#include <string.h>

char * regleP [] = {"program","BlancO","id","pointvr","Dcl","Inst_compose","point",NULL};
char * regleDcl [] = {"Dcl1",NULL};
char * regleDcl1 [] = {"BlancO","Dcl2"};
char * regleDcl2 [] = {"var","BlancO","Liste_id","ptpt","Type","pointvr","Dcl1",NULL};
char * regleListe_id [] = {"id","Liste_id1",NULL};
char * regleListe_id1 [] = {"vr","id","Liste_id1",NULL};
char * regleType [] = {"BlancO","Type1",NULL};
char * regleType1 [] = {"integer","BlancO",NULL};
char * regleType11 [] = {"char","BlancO",NULL};
char * regleInst_compose [] = {"begin","BlancO","Inst","end","BlancO",NULL};
char * regleInst [] = {"Liste_inst","BlancO",NULL};
char * regleListe_inst [] = {"I","Liste_inst1",NULL};
char * regleListe_inst1 [] = {"pointvr","Liste_inst2",NULL};
char * regleListe_inst2 [] = {"I1","Liste_inst1",NULL};
char * regleListe_inst21 [] = {"BlancO","I2","Liste_inst1",NULL};
char * regleI1 [] = {"id","opaff","Exp_simple",NULL};
char * regleI2[] = {"if","BlancO","Exp","then","BlancO","I","BlancO","else","BlancO","I",NULL};
char * regleI21[] = {"while","BlancO","Exp","do","BlancO","I",NULL};
char * regleI22[] = {"read","pargauche","id","pardroite",NULL};
char * regleI23[] = {"readln","pargauche","id","pardroite",NULL};
char * regleI24[] = {"write","pargauche","id","pardroite",NULL};
char * regleI25[] = {"writeln","pargauche","id","pardroite",NULL};
char * regleI[] =  {"I1",NULL};
char * regleI11[] = {"I2",NULL};
char * regleExp[] = {"Exp_simple","Exp1",NULL};
char * regleExp1[] = {"oprel","Exp_simple","BlancO",NULL};
char * regleExp11[] = {"BlancO",NULL};
char * regleExp_simple[] = {"Terme","Exp_simple1",NULL};
char * regleExp_simple1[] = {"opadd","Terme","Exp_simple1",NULL};
char * regleTerme[] = {"Facteur","Terme1",NULL};
char * regleTerme1[] = {"opmul","Facteur","Terme1",NULL};
char * regleFacteur[] = {"id",NULL};
char * regleFacteur1[] = {"nb",NULL};
char * regleFacteur2[] = {"pargauche","Exp_simple","pardroite",NULL};
char * epsilon[] = {"epsilon",NULL};

char * indiceTable [][28] = {
    {"blanc","program","var","integer","char","begin","end","if","then","else","while","do","read","readln","write","writeln","oprel","opadd","opmul","nb","id","vr","pointvr","point","pargauche","pardroite","ptpt","$"},
    {"P"},
    {"Dcl"},
    {"Dcl1"},
    {"Dcl2"},
    {"Liste_id"},
    {"Liste_id1"},
    {"Type"},
    {"Type1"},
    {"Inst_compose"},
    {"Inst"},
    {"Liste_inst"},
    {"Liste_inst1"},
    {"Liste_inst2"},
    {"I"},
    {"I1"},
    {"I2"},
    {"Exp"},
    {"Exp1"},
    {"Exp_simple"},
    {"Exp_simple1"},
    {"Terme"},
    {"Terme1"},
    {"Facteur"},
    {"blancO"},
    {"blancO1"}
};

char ** tableM [][28]  = {
    //1	    2	   3    4	5	 6	  7	   8	9	 10	  11  12	13	 14	  15  16	17	18	  19   20	21	 22	  23  24	25	26	  27   28
    {
        NULL,regleP,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL
    },
    {
        regleDcl,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL
    },
    {
        regleDcl1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL
    },
    {
        NULL,NULL,regleDcl2,NULL,NULL,epsilon,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL
    },
    {
        NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,regleListe_id,NULL,NULL,NULL,NULL,NULL,NULL,NULL
    },
    {
        NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,regleListe_id1,NULL,NULL,NULL,NULL,epsilon,NULL
    },
    {
        regleType,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL
    },
    {
        NULL,NULL,NULL,regleType1,regleType11,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL
    },
    {
        NULL,NULL,NULL,NULL,NULL,regleInst_compose,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL
    },
    {
        NULL,NULL,NULL,NULL,NULL,NULL,epsilon,regleInst,NULL,NULL,regleInst,NULL,regleInst,regleInst,regleInst,regleInst,NULL,NULL,NULL,NULL,regleInst,NULL,NULL,NULL,NULL,NULL,NULL,NULL
    },
    {
        NULL,NULL,NULL,NULL,NULL,NULL,NULL,regleListe_inst,NULL,NULL,regleListe_inst,NULL,regleListe_inst,regleListe_inst,regleListe_inst,regleListe_inst,NULL,NULL,NULL,NULL,regleListe_inst,NULL,NULL,NULL,NULL,NULL,NULL,NULL
    },
    {
        epsilon,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,regleListe_inst1,NULL,NULL,NULL,NULL,NULL
    },
    {
        regleListe_inst21,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,regleListe_inst2,NULL,NULL,NULL,NULL,NULL,NULL,NULL
    },
    {
        NULL,NULL,NULL,NULL,NULL,NULL,NULL,regleI11,NULL,NULL,regleI11,NULL,regleI11,regleI11,regleI11,regleI11,NULL,NULL,NULL,NULL,regleI,NULL,NULL,NULL,NULL,NULL,NULL,NULL
    },
    {
        NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,regleI1,NULL,NULL,NULL,NULL,NULL,NULL,NULL
    },
    {
        NULL,NULL,NULL,NULL,NULL,NULL,NULL,regleI2,NULL,NULL,regleI21,NULL,regleI22,regleI23,regleI24,regleI25,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL
    },
    {
        NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,regleExp,regleExp,NULL,NULL,NULL,regleExp,NULL,NULL,NULL
    },
    {
        NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,epsilon,NULL,NULL,epsilon,NULL,NULL,NULL,NULL,regleExp1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL
    },
    {
        NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,regleExp_simple,regleExp_simple,NULL,NULL,NULL,regleExp_simple,NULL,NULL,NULL
    },
    {
        epsilon,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,epsilon,regleExp_simple1,NULL,NULL,NULL,NULL,epsilon,NULL,NULL,epsilon,NULL,NULL
    },
    {
        NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,regleTerme,regleTerme,NULL,NULL,NULL,regleTerme,NULL,NULL,NULL
    },
    {
        epsilon,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,epsilon,epsilon,regleTerme1,NULL,NULL,NULL,epsilon,NULL,NULL,epsilon,NULL,NULL
    },
    {
        NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,regleFacteur1,regleFacteur,NULL,NULL,NULL,regleFacteur2,NULL,NULL,NULL
    }
};



indice rechercheIndice(char * term ,char * nTerm ){
    int i=0,j=1,tr=0;
    indice res ;
    do{
        if(strcmp(term,indiceTable[0][i])==0){
            tr=1;
        }else i++;
    }while(!tr && i<28);
    tr=0;
    do{
        if(strcmp(nTerm,indiceTable[j][0])==0){
            tr=1;
        }else j++;
    }while(!tr && j<26);
    j--;
    res.i=i;res.j=j;
    return res;
}

char ** getRegle(indice ind){
    return tableM[ind.j][ind.i];
}
