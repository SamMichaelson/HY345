#include <assert.h>
#include "scope.h"



#define EXPAND_SIZE 1024
#define CURR_SIZE   (total*sizeof(quad))
#define NEW_SIZE    (EXPAND_SIZE*sizeof(quad)+CURR_SIZE)

unsigned programVarOffset    =0;
unsigned functionLocalOffset =0;
unsigned formalArgOffset     =0;
unsigned scopeSpaceCounter   =1;
unsigned   total = 0;
unsigned int currQuad = 0;

int tempcounter = 0;


enum iopcode {
    assign,
    add,
    sub,
    mul,
    diva,
    mod,
    uminus,
    and,
    or,
    not,
    if_eq,
    if_noteq,
    if_lesseq,
    if_greatereq,
    if_less,
    if_greater,
    call,
    param,
    ret,
    getretval,
    funcstart,
    funcend,
    tablecreate,
    tablegetelem,
    tablesetelem,
    jump,
    pusharg,
    nop
};

typedef enum expr_t{
    var_e,
    tableitem_e,

    programfunc_e,
    libraryfunc_e,

    arithexpr_e,
    boolexpr_e,
    assignexpr_e,
    newtable_e,

    costnum_e,
    constbool_e,
    conststring_e,

    nil_e
}expr_t;


typedef struct expr {
    enum expr_t         type;
    SymbolTableEntry*   sym;
    struct expr*        index;
    double              numConst;
    char*               strConst;
    unsigned char       boolConst;
    struct expr*        next;
    struct expr*        prev;
}expr;

typedef struct quad {
    enum iopcode    op;
    expr*           result;
    expr*           arg1;
    expr*           arg2;
    unsigned        label;
    unsigned        line;
    unsigned        taddress;
    int*            returnList;
    SymbolTableEntry* entry;
}quad;



 


 
quad*  quads = (quad*)  0;

void expand(void) {
    assert(total==currQuad);
    quad* p = (quad*) malloc(NEW_SIZE);
    if(quads) {
        memcpy(p, quads ,CURR_SIZE);
        free(quads);
    }
    quads = p;
    total +=EXPAND_SIZE;

}

void emit (
        enum iopcode     op,
        expr*           arg1,
        expr*           arg2,
        expr*           result,
        unsigned        label,
        unsigned        line
        )
       
         {
        
        if (currQuad ==total)
            expand();

        quad* p     = quads+currQuad++;
        p->op       =op;
        p->arg1     =arg1;
        p->arg2     =arg2;
        p->result   =result;
        p->label    =label;
        p->line     =line;
      
       
        
    } 





scopespace_t currscopespace(void){
    if(scopeSpaceCounter==1)
        return programvar;
    else
    if (scopeSpaceCounter%2==0)
        return formalarg;
    else    
        return functionlocal;
}


unsigned currscopeoffset (void) { 
    switch (currscopespace()){
        case programvar     : return programVarOffset;
        case functionlocal  : return functionLocalOffset;
        case formalarg      : return formalArgOffset;
        default: assert(0);
    }
}

void inccurrscopeoffset (void) {
    switch (currscopespace()){
        case programvar     : ++programVarOffset; break;
        case functionlocal  : ++functionLocalOffset; break;
        case formalarg      : ++formalArgOffset; break;
        default: assert(0);
    }
}

void restorecurrscopeoffset (unsigned n) {
     switch (currscopespace()){
        case programvar     : programVarOffset = n; break;
        case functionlocal  : functionLocalOffset = n; break;
        case formalarg      : formalArgOffset = n; break;
        default: assert(0);
    }
}

void enterscopespace(void){

    ++scopeSpaceCounter;
}

void exitscopespace (void){ 

    assert(scopeSpaceCounter>1); --scopeSpaceCounter;
}


void resetformalargsoffet (void){
   formalArgOffset      =0;
}

void resetfunctionlocalsoffset (void){
    functionLocalOffset =0;
}



unsigned nextquadlabel (void){
    return currQuad;
}


void patchlist (int list, int label) {
       
        while (list) {
            int next = quads[list].label;
            quads[list].label = label;
            list = next;
            if(list==label)
                break;

        }
}
void patchlabel(unsigned quadNo, unsigned label){
    assert(quadNo < currQuad );
    quads[quadNo].label = label;
}


expr* lvalue_expr (SymbolTableEntry* sym){
 

  
    assert(sym);
    expr* e = (expr*) malloc(sizeof(expr));
    memset(e, 0, sizeof(expr));
    

    e->next = (expr*) 0;
    e->sym  = sym;

     
    switch (sym->type) {
         
        case USERFUNC  : e->type = programfunc_e; break;
        case LIBFUNC   : e->type = libraryfunc_e; break;
        case GLOBAL    : e->type = var_e; break;
        case LOCALL    : e->type = var_e; break;
        case FORMAL    : e->type = var_e; break;
        default: assert(0);

    } 
    
    
    return e;
}

expr* newexpr ( expr_t t) {
    expr* e = (expr*) malloc(sizeof(expr));
    memset(e, 0, sizeof(expr));
    e->type = t;
    return e;
}
expr* newexpr_conststring(char* s) {
    expr* e = newexpr(conststring_e);
    e->strConst = strdup(s);
    return e;
}

expr* newexpr_constnum(double s) {
    expr* e = newexpr(costnum_e);
    e->numConst = s;
    return e;
}
expr* newexpr_constbool(unsigned char s) {
    expr* e = newexpr(constbool_e );
    e->boolConst = s;
    return e;
}

char* newtempname(void) {
    char* tempname = malloc(10 * sizeof(char)); 
    sprintf(tempname, "_t%d", tempcounter++); 
    return tempname; 
}


unsigned resettemp(void){
     tempcounter = 0;
}





SymbolTableEntry* newtemp(unsigned int scope,int line){

        char* name = newtempname();
        SymbolTableEntry* sym = searchScope(name,scope);
        if (sym==NULL){

            if(scope==0)
                insertElemVariable(GLOBAL,name,scope,line,currscopespace(),currscopeoffset());
            else
                insertElemVariable(LOCALL,name,scope,line,currscopespace(),currscopeoffset());
            inccurrscopeoffset();    
            
            return searchScope(name,scope);
        }else{
            return sym;
        }
  }

expr* emit_iftableitem(expr* e,unsigned int scope,int line){
    
    if(e->type != tableitem_e)
        return e;
    else{
        expr* result = newexpr(var_e);
        result->sym = newtemp(scope,line);
      
       
       
        emit(
            tablegetelem,
            e,
            e->index,
            result,
            currQuad,
            line
        );
        return result;
    }
}

expr* make_call(expr* lv, expr* reversed_elist,unsigned int scope,int line) {
    expr* func = emit_iftableitem(lv,scope,line);
   
    while(reversed_elist) {
        emit(param, reversed_elist, NULL,NULL,currQuad,line);
        reversed_elist = reversed_elist->next;
    }
    emit(call, func,NULL,NULL,currQuad,line);
    expr* result = newexpr(var_e);
    result->sym = newtemp(scope,line);
  
    emit(getretval,NULL,NULL,result,currQuad,line);
    return result;
}
void rearrangeAndReverse(struct expr** head) {
    struct expr* current = *head;
    struct expr* array[1000];
    int count = 0;

    while (current) {
        if(current!=NULL){
            array[count] = current;
            current = current->next;
            count++;}
    }
    for (int i = 0, j = count- 1; i < j; i++, j--) {
        struct expr* temp = array[i];
        array[i] = array[j];
        array[j] = temp;}
    for (int i = 0; i < count - 1; i++) {
        array[i]->next = array[i + 1];
    }
    array[count - 1]->next = NULL;
    *head = array[0];
}

void comperror(char* format){
    printf("%s\n",format);
}

void check_arith(expr* e ) {
    if( e->type == constbool_e   ||
        e->type == conststring_e ||
        e->type == nil_e         ||
        e->type == newtable_e    ||
        e->type == programfunc_e ||
        e->type == libraryfunc_e ||
        e->type == boolexpr_e    )
        comperror("Illegal expr used in %s!");
}
bool check_arith_bool(expr* e ) {
    if( e->type == constbool_e   ||
        e->type == conststring_e ||
        e->type == nil_e         ||
        e->type == newtable_e    ||
        e->type == programfunc_e ||
        e->type == libraryfunc_e ||
        e->type == boolexpr_e    )
        return false;
    return true;
}
unsigned int istempname (const char* s) {
        return *s == '_';
}

unsigned int istempexpr (expr* e) {
        return e->sym && istempname(e->sym->value.varVal->name);
}


expr* member_item (expr* lv, char* name,unsigned int scope,unsigned int line) {
            lv = emit_iftableitem(lv,scope,line); 
            expr* ti = newexpr(tableitem_e); 
            ti->sym = lv->sym;
            ti->index = newexpr_conststring(name); 
            return ti;
}

expr*  nextquad(unsigned int x){
    expr* e = newexpr(costnum_e);
    e->numConst=(nextquadlabel())+x;
    return e;
}



int newlist (int i)
{ quads[i].label = 0; return i; }



int mergelist (int l1, int l2) {
    if (!l1){
        return l2;
    }else if (!l2){
        return l1;
        int i = l1;
       while ((quads[i].label))
           { i = quads[i].label;}
        quads[i].label = l2;
        return l1;
    }
}



/*

    enum iopcode    op;
    expr*           result;
    expr*           arg1;
    expr*           arg2;
    unsigned        label;
    unsigned        line;*/

const char* opcodeToStr(enum iopcode opcode) {
    switch (opcode) {
        case assign:
            return "assign";
        case add:
            return "add";
        case sub:
            return "sub";
        case mul:
            return "mul";
        case diva:
            return "div";
        case mod:
            return "mod";
        case uminus:
            return "uminus";
        case and:
            return "and";
        case or:
            return "or";
        case not:
            return "not";
        case if_eq:
            return "if_eq";
        case if_noteq:
            return "if_noteq";
        case if_lesseq:
            return "if_lesseq";
        case if_greatereq:
            return "if_greatereq";
        case if_less:
            return "if_less";
        case if_greater:
            return "if_greater";
        case call:
            return "call";
        case param:
            return "param";
        case ret:
            return "ret";
        case getretval:
            return "getretval";
        case funcstart:
            return "funcstart";
        case funcend:
            return "funcend";
        case tablecreate:
            return "tablecreate";
        case tablegetelem:
            return "tablegetelem";
        case tablesetelem:
            return "tablesetelem";
        case jump:
            return "jump";
        default:
            return "unknown";
    }
}



void printQuads() {
    printf("\n\n");
    if (quads == NULL) {
    printf("No quads to print.\n");
    return;
    }
    for (int i = 0; i < currQuad; i++) {
    colortxt("orange");
    printf("Quad %3d: ,   ", i);
    reset();
    colortxt("f");
    printf("op:%12s,   ", opcodeToStr(quads[i].op));
    reset();
    colortxt("v");
    if (quads[i].result != NULL && quads[i].result->sym != NULL && quads[i].result->sym->value.varVal != NULL) { 
        printf("res: %5s,   ", quads[i].result->sym->value.varVal->name);
    } else if(  quads[i].result!=NULL && quads[i].result->type==8) {
        printf("res: %5.2f,   ",quads[i].result->numConst);
    } else if(  quads[i].result!=NULL && quads[i].result->type==0) {/*var_e*/
        printf("res: %5s,   ",quads[i].result->strConst);
    } else if(  quads[i].result!=NULL && quads[i].result->type==11) { /*nill*/
        printf("res:   nil,   ");
    }  else {
        printf("res:      ,   ");
    }reset();
    colortxt("pink");
    if (quads[i].arg1 != NULL &&  quads[i].arg1->sym != NULL && quads[i].arg1->sym->value.varVal != NULL  ) {
            printf("arg1: %5s,  ", quads[i].arg1->sym->value.varVal->name);
    } else if( quads[i].arg1!=NULL && quads[i].arg1->type==8 ) {
        printf("arg1: %5.2f,  ",quads[i].arg1->numConst);
    } else if( quads[i].arg1!=NULL && quads[i].arg1->type==2 ) {/*programfunc*/
        printf("arg1: %5s,  ",quads[i].arg1->strConst);
    } else if( quads[i].arg1!=NULL && quads[i].arg1->type==3 ) {/*libfuncs*/
        printf("arg1: %5s,  ",quads[i].arg1->strConst);
    } else if( quads[i].arg1!=NULL && quads[i].arg1->type==0 ) {/*var_e*/
        printf("arg1: %5s,  ",quads[i].arg1->strConst);
    } else if( quads[i].arg1!=NULL && quads[i].arg1->type==4) {/*arithmetic*/
        printf("arg1: %5d,  ",quads[i].arg1->type);
    } else if( quads[i].arg1!=NULL && (quads[i].arg1->type==9 ||quads[i].arg1->type==5)) {/*BOOL*/
        if(quads[i].arg1->boolConst==1)
            printf("arg1:  TRUE,  ");
        else
            printf("arg1: FALSE,  ");
    } else if( quads[i].arg1!=NULL && quads[i].arg1->type==10 ) {/*string*/
        printf("arg1: \"%3s\",  ",quads[i].arg1->strConst);
    } else {
        printf("arg1:      ,  ");
    }reset();
    colortxt("yellow");
    if (quads[i].arg2 != NULL && quads[i].arg2->sym != NULL && quads[i].arg2->sym->value.varVal != NULL) {
        printf("arg2: %5s,  ", quads[i].arg2->sym->value.varVal->name);
    } else if( quads[i].arg2!=NULL && quads[i].arg2->type==8 ) {
        printf("arg2: %5.2f,  ",quads[i].arg2->numConst);
    } else if( quads[i].arg2!=NULL && quads[i].arg2->type==2 ) {/*programfunc*/
        printf("arg2: %5s,  ",quads[i].arg2->strConst);
    }  else if( quads[i].arg2!=NULL && quads[i].arg2->type==3 ) {/*libfuncs*/
        printf("arg2: %5s,  ",quads[i].arg2->strConst);
    } else if( quads[i].arg2!=NULL && quads[i].arg2->type==0 ) {/*var_e*/
        printf("arg2: %5s,  ",quads[i].arg2->strConst);
    } else if( quads[i].arg2!=NULL  && quads[i].arg2->type==4) {/*arithmetic*/
        printf("arg2: %5d,  ",quads[i].arg2->type);
    } else if( quads[i].arg2!=NULL && quads[i].arg2->type==9 ) {/*BOOL*/
        if(quads[i].arg2->boolConst==1)
            printf("arg2:  TRUE,  ");
        else
            printf("arg2: FALSE,  ");
    } else if( quads[i].arg2!=NULL && quads[i].arg2->type==10 ) {/*string*/
        printf("arg2: \"%3s\",  ",quads[i].arg2->strConst);
    } else {
        printf("arg2:      ,  ");
    }reset();
        colortxt("white");
    if(quads[i].op<9 || quads[i].op>16)
        printf("\t        line: %2d\n", quads[i].line);
    else{colortxt("purple");
        printf("label: %2d, ", quads[i].label);
        reset();
        colortxt("white");
        printf(" line: %2d\n", quads[i].line);
        }
    }reset();
}


