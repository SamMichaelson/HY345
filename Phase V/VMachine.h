
#include "avm.h"


#define AVM_STACHENV_SIZE 4

#define AVM_NUMACTUALS_OFFSET       +4
#define AVM_SAVEDPC_OFFSET          +3
#define AVM_SAVEDTOP_OFFSET         +2
#define AVM_SAVEDTOPSP_OFFSET       +1

unsigned totalActuals=0;

avm_memcell ax,bx,cx;
avm_memcell retval;
unsigned    top,topsp;

double             consts_getnumber(unsigned   index);
char*               consts_getstring(unsigned   index);
char*               libfuncs_getused(unsigned   index);
SymbolTableEntry*   userfuncs_getfunc(unsigned  index);

avm_memcell* avm_translate_operand(vmarg* arg,avm_memcell* reg){
    switch(arg->type){
        case global_a:  return &stack[AVM_STACKSIZE-1-arg->val];    
        case local_a:   return &stack[topsp-arg->val];
        case formal_a:  return &stack[topsp+AVM_STACHENV_SIZE+1+arg->val];
        case retval_a:  return &retval;
        case number_a:{
            reg->type = number_m;
            reg->data.numVal= consts_getnumber(arg->val);
            return reg;
        }
        case string_a:{
            reg->type = string_m;
            reg->data.strVal= strdup(consts_getstring(arg->val));
            return reg;
        }
        case bool_a:{
            reg->type = bool_m;
            reg->data.boolVal=arg->val;
            return reg;
        }
        case nil_a:  reg->type=nil_m; return reg;
        case userfunc_a:{
            reg->type=userfunc_m;
            reg->data.funcVal=arg->val;
            reg->data.funcVal=userfuncs_getfunc(arg->val)->value.funcVal->iaddress;
            return reg;      
        }
        case libfunc_a:{
            reg->type=userfunc_m;
            reg->data.libfuncVal=libfuncs_getused(arg->val);
            return reg;      
        }
        default: assert(0);
    }
}


typedef void (*execute_func_t)(instruction*);


#define AVM_MAX_INSTRUCTIONS (1024)

extern void execute_assign (instruction*);

extern void execute_add (instruction*);
extern void execute_sub (instruction*);
extern void execute_mul (instruction*);
extern void execute_div (instruction*);
extern void execute_mod (instruction*);
extern void execute_uminus (instruction*);

extern void execute_and (instruction*);
extern void execute_or (instruction*);
extern void execute_not (instruction*);

extern void execute_jeq (instruction*);
extern void execute_jne (instruction*);
extern void execute_jle (instruction*);
extern void execute_jge (instruction*);
extern void execute_jlt (instruction*);
extern void execute_jgt (instruction*);
extern void execute_param (instruction*);
extern void execute_return (instruction*);
extern void execute_getretval (instruction*);
extern void execute_jump (instruction*);
extern void execute_call (instruction*);
extern void execute_pusharg (instruction*);
extern void execute_funcenter (instruction*);
extern void execute_funcexit (instruction*);

extern void execute_newtable (instruction*);
extern void execute_tablegetelem (instruction*);
extern void execute_tablesetelem (instruction*);

extern void execute_nop (instruction*);


extern void avm_error(char* format,...); 
extern char* avm_tostring (avm_memcell*); /* Caller frees. */
extern void avm_calllibfunc (char* funcName); 
extern void avm_callsaveenvironment (void);
extern void avm_call_functor (avm_table* t); 

extern void avm_push_table_arg (avm_table* t); /* latter*/


extern Function* avm_getfuncinfo (unsigned address);


execute_func_t executeFuncs[]={
    execute_assign,
    execute_add,
    execute_sub,
    execute_mul,
    execute_div,
    execute_mod,
    execute_uminus,
    execute_and,
    execute_or,
    execute_not,
    execute_jeq,
    execute_jne,
    execute_jle,
    execute_jge,
    execute_jlt,
    execute_jgt,
    execute_call,
    execute_param,/**/
    execute_return,/**/
    execute_getretval,/**/
    execute_funcenter,
    execute_funcexit,
    execute_tablegetelem,
    execute_tablesetelem,
    execute_jump,/**/
    execute_pusharg,
    execute_nop
};

unsigned char   executionFinished=0;
unsigned        pc=0;
unsigned        currLine = 0;
unsigned        codeSize=0;
instruction*    code=(instruction*)0;

#define AVM_ENDING_PC codeSize

void execute_cycle(void){
    if(executionFinished)
        return;
    else if(pc==AVM_ENDING_PC){
        executionFinished=1;
        return;
    }
    else{
        assert(pc<AVM_ENDING_PC);
        instruction* instr= code+pc;
        assert(instr->opcode>=0 && instr->opcode<= AVM_MAX_INSTRUCTIONS );
        if(instr->srcLine)
            currLine=instr->srcLine;
        unsigned oldPc=pc;
        (*executeFuncs[instr->opcode])(instr);
        if(pc ==oldPc)
            ++pc;
    }
}


void avm_assign(avm_memcell* lv,avm_memcell* rv);



extern void avm_warning(char* format,...);
extern void avm_assign(avm_memcell* lv, avm_memcell* rv);

void execute_assign(instruction* instr){
    avm_memcell* lv=avm_translate_operand(&instr->result,(avm_memcell*)0);
    avm_memcell* rv=avm_translate_operand(&instr->arg1, &ax);

    assert(lv && (&stack[N-1]>=lv && lv>&stack[top] || lv==&retval));
    assert(rv);
    avm_assign(lv,rv);
}

void avm_assign(avm_memcell* lv,avm_memcell* rv){
    if(lv==rv)
        return;
    if (lv->type==table_m &&
        rv->type==table_m &&
        lv->data.tableVal==rv->data.tableVal )
    return;
    
    if(rv->type == undef_m)
        avm_warning("assigning from 'undef' content!" );

    avm_memcellclear(lv);

    memcpy(lv, rv, sizeof(avm_memcell));
    
    if(lv->type==string_m)
        lv->data.strVal=strdup(rv->data.strVal);
    else if (lv->type==table_m)
        avm_tableincrefcounnter(lv->data.tableVal);
}

avm_memcell*    avm_tablegetelem(
                    avm_table*      table,
                    avm_memcell*    index;
                    );

void avm_call_functor(avm_table *t) {
    cx.type=string_m; 
    cx.data.strVal = "()";
    avm_memcell* f=avm_tablegetelem(t,&cx);
    if (!f)
        avm_error("in calling table: no '()' element found!");
    else if (f->type == table_m) 
        avm_call_functor (f->data.tableVal);
    else if (f->type == userfunc_a) { 
        avm_push_table_arg(t);
        avm_callsaveenvironment(); 
        pc= f->data. funcVal;
        assert(pc < AVM_ENDING_PC && code[pc].opcode ==funcenter_v);
    } else
        avm_error("in calling table: illegal '()' element value!");
}



void avm_dec_top(void) {
    if(!top){
        avm_error("stack overflow");
        executionFinished=1;
    }else
        --top;
}

void avm_push_envvalue(unsigned val) {
    stack[top].type = number_m;
    stack[top].data.numVal = val;
    avm_dec_top();
}

void avm_callsaveenvironment(void){
    avm_push_envvalue(totalActuals);
    assert(code[pc].opcode==call_v);
    avm_push_envvalue(pc+1);
    avm_push_envvalue(top +totalActuals+2);
    avm_push_envvalue(topsp);
}


void execute_call (instruction* instr) {
    avm_memcell* func =avm_translate_operand (&instr->result, &ax);
    assert(func);
    switch (func->type) {
        case userfunc_m:{
            avm_callsaveenvironment();
            pc= func->data.funcVal;
            assert(pc < AVM_ENDING_PC); 
            assert(code[pc].opcode==funcenter_v); 
            break;
        }

        case string_m: avm_calllibfunc(func->data.strVal); break;
        case libfunc_m: avm_calllibfunc(func->data.libfuncVal); break;
        case table_m: avm_call_functor(func->data.tableVal); break;

        default: {
            char* s = avm_tostring(func);
            avm_error("call: cannot bind '%s' to function!", s);
            free(s); 
            executionFinished = 1;
        }
    }
}

unsigned avm_get_envvalue(unsigned i) {
    return i;
}



void execute_funcenter (instruction* instr) {
    avm_memcell* func= avm_translate_operand (&instr->result,&ax);
    assert(func);
    assert(pc==func->data.funcVal);
    
    totalActuals = 0;
    Function* funcInfo= avm_getfuncinfo(pc);
    topsp=top;
    top= top - funcInfo->functionlocals;
}
unsigned ava_get_envvalue (unsigned i) {
    assert(stack[i].type=number_m);
    unsigned val=(unsigned)stack[i].data.numVal;
    assert (stack[i].data.numVal = ((double) val));
    return val;
}

void execute_funcexit (instruction* unused) {
    unsigned oldTop = top;
    top=avm_get_envvalue (topsp + AVM_SAVEDTOP_OFFSET);
    pc=avm_get_envvalue (topsp + AVM_SAVEDPC_OFFSET);
    topsp =avm_get_envvalue (topsp+ AVM_SAVEDTOPSP_OFFSET);
    while (++oldTop <= top)
        avm_memcellclear (&stack[oldTop]);
}



typedef void (*library_func_t)(void);

extern void print_Lfunc(void);
extern void input_Lfunc(void);
extern void objectmemberkeys_Lfunc(void);
extern void objecttotalmembers_Lfunc(void);
extern void objectcopy_Lfunc(void);
extern void totalarguments_Lfunc(void);
extern void argument_Lfunc(void);
extern void typeof_Lfunc(void);
extern void strtonum_Lfunc(void);
extern void sqrt_Lfunc(void);
extern void cos_Lfunc(void);
extern void sin_Lfunc(void);


library_func_t libFuncs[] = {
    print_Lfunc,
    input_Lfunc,
    objectmemberkeys_Lfunc,
    objecttotalmembers_Lfunc,
    objectcopy_Lfunc,
    totalarguments_Lfunc,
    argument_Lfunc,
    typeof_Lfunc,
    strtonum_Lfunc,
    sqrt_Lfunc,
    cos_Lfunc,
    sin_Lfunc
};

library_func_t avm_getlibraryfunc(char* id) {
    int index = atoi(id);
    
    if (index >= 0 && index < sizeof(libFuncs) / sizeof(libFuncs[0])) {
        return libFuncs[index];
    } else {
        return NULL;
    }
}

void avm_calllibfunc(char* id) {
    library_func_t f = avm_getlibraryfunc(id);
    
    if (!f) {
        avm_error("unsupported lib func '%s' called!", id);
        executionFinished = 1;
    } else {
        avm_callsaveenvironment();
        topsp = top; /* Enter function sequence. No stack locals. */
        totalActuals = 0;
        (*f)(); /* Call library function. if (lexecutionFinished) /* An error may naturally occur inside. */
        if (!executionFinished)
            execute_funcexit((instruction*)0); /* Return sequence. */
    }
}


unsigned avm_totalactuals (void) {
    return avm_get_envvalue (topsp + AVM_NUMACTUALS_OFFSET);
}

avm_memcell* avm_getactual (unsigned i) {
    assert (i < avm_totalactuals()); 
    return &stack[topsp + AVM_STACKENV_SIZE + 1 + i];
}
void libfunc_print (void){
    unsigned n=avm_totalactuals();
    for (unsigned i = 0; i < n; ++i) {
        char* s = avm_tostring (avm_getactual (i)); 
        puts (s); 
        free (s);
    }
}       



void avm_registerlibfunc (char* id, library_func_t addr);


extern void avm_push_table_arg (avm_table* t) { 
    stack[top].type =table_m;
    avm_tableincrefcounnter (stack[top].data.tableVal = t);
    ++totalActuals;
    avm_dec_top();
}

void execute_pusharg (instruction* instr) {
    avm_memcell* arg = avm_translate_operand (&instr->arg1, &ax); 
    assert(arg);
    avm_assign(&stack[top], arg); 
    ++totalActuals;
    avm_dec_top();
}

typedef char* (*tostring_func_t) (avm_memcell*);

extern char* number_tostring    (avm_memcell*); 
extern char* string_tostring    (avm_memcell*);
extern char* bool_tostring      (avm_memcell*);
extern char* table_tostring     (avm_memcell*);
extern char* userfunc_tostring  (avm_memcell*);
extern char* libfunc_tostring   (avm_memcell*);
extern char* nil_tostring       (avm_memcell*); 
extern char* undef_tostring     (avm_memcell*);

tostring_func_t tostringFuncs[]={
    number_tostring,
    string_tostring, 
    bool_tostring,
    table_tostring, 
    userfunc_tostring,
    libfunc_tostring,
    nil_tostring,
    undef_tostring
}; 

char* avm_tostring (avm_memcell* m) {
    assert(m->type >= 0 && m->type <= undef_m); 
    return (*tostringFuncs [m->type]) (m);
}

#define execute_add execute_arithmetic
#define execute_sub execute_arithmetic
#define execute_mul execute_arithmetic
#define execute_div execute_arithmetic
#define execute_mod execute_arithmetic



typedef double (*arithmetic_func_t)(double x, double y);

double add_impl (double x, double y) { return x+y; }
double sub_impl (double x, double y) { return x-y; }
double mul_impl (double x, double y) { return x*y; }
double div_impl (double x, double y) { return x/y; }
double mod_impl (double x, double y) {
    return ((unsigned) x) % ((unsigned) y);
}


arithmetic_func_t arithmeticFuncs[] = {
    add_impl,
    sub_impl,
    mul_impl,
    div_impl,
    mod_impl
};

void execute_arithmetic (instruction* instr) {

    avm_memcell* lv = avm_translate_operand (&instr->result, (avm_memcell*) 0);
    avm_memcell* rv1 = avm_translate_operand (&instr->arg1, &ax) ;
    avm_memcell* rv2 = avm_translate_operand (&instr->arg2,&bx);
    assert (lv && ( &stack [N-1] >= lv && lv > &stack[top] || lv==&retval));
    assert (rv1 && rv2) ;
    
    if (rv1->type != number_m || rv2->type != number_m) {
        avm_error ("not a number in arithmetic!");
        executionFinished = 1;
    }
    else {
        arithmetic_func_t op = arithmeticFuncs [instr->opcode - add_v];
        avm_memcellclear (lv);
        lv->type = number_m;
        lv->data.numVal = (*op) (rv1->data.numVal, rv2->data.numVal);

    }
}


typedef unsigned char (*tobool_func_t) (avm_memcell*);


unsigned char number_tobool     (avm_memcell* m) { return m->data.numVal != 0; } 
unsigned char string_tobool     (avm_memcell* m) { return m->data.strVal[0] != 0;}
unsigned char bool_tobool       (avm_memcell* m) { return m->data.boolVal; }
unsigned char table_tobool      (avm_memcell* m) { return 1; }
unsigned char userfunc_tobool   (avm_memcell* m) { return 1; }
unsigned char libfunc_tobool    (avm_memcell* m) { return 1; }
unsigned char nil_tobool        (avm_memcell* m) { return 0; }
unsigned char undef_tobool      (avm_memcell* m) { return 0;}


tobool_func_t toboolFuncs []={
    number_tobool,
    string_tobool,
    bool_tobool,
    table_tobool,
    userfunc_tobool,
    libfunc_tobool,
    nil_tobool,
    undef_tobool
};


unsigned char avm_tobool (avm_memcell* m) {
    assert (m->type >= 0 && m->type < undef_m) ;
    return (*toboolFuncs [m->type] ) (m) ;
}


char* typeStrings[]={
    "number",
    "string",
    "bool",
    "table",
    "userfunc",
    "nil",
    "undef"
};


void execute_jeq (instruction* instr){
    
    assert (instr->result.type == label_a);
    avm_memcell* rv1 = avm_translate_operand (&instr->arg1, &ax);
    avm_memcell* rv2 = avm_translate_operand (&instr->arg2,&bx);
    unsigned char result = 0;

    if (rv1->type == undef_m || rv2->type == undef_m)
        avm_error ("' undef' involved in equality!");
    else
    if (rv1->type== bool_m || rv2->type == bool_m)
        result = (avm_tobool (rv1) == avm_tobool (rv2));
    else
    if (rv1->type == nil_m || rv2->type == nil_m)
        result = rv1->type == nil_m && rv2->type == nil_m;
    else
    if (rv1->type != rv2->type)
        avm_error (
            "%s == is is illegal!",
            typeStrings [rv1->type],
            typeStrings [rv2->type]
        );
    else{
    /* Equality check with dispatching.*/
    }
    if (!executionFinished && result)
        pc = instr->result.val;
}




void libfunc_typeof (void)  {
    unsigned n= avm_totalactuals();
    if(n!=1)
        avm_error("one argument (not %d) expected in 'typeof'!",n);
    else{
        avm_memcellclear(&retval);
        retval.type = string_m;
        retval.data.strVal = strdup(typeStrings[avm_getactual(0)->type]);
    }
}

void execute_newtable(instruction * instr) {
    avm_memcell* lv = avm_translate_operand(&instr->result, (avm_memcell*)  0);    
    assert(lv && (&stack[N-1] >= lv && lv > &stack[top] || lv==&retval));
    avm_memcellclear(lv);
    lv->type             = table_m;
    lv->data.tableVal    = avm_tablenew();
    avm_tableincrefcounnter(lv->data.tableVal);
}





void            avm_tablesetelem (
                    avm_table*      table,
                    avm_memcell*    index,
                    avm_memcell*    content
                );




void execute_tablegetelem(instruction* instr){

    avm_memcell* lv = avm_translate_operand(&instr->result, (avm_memcell*)  0);
    avm_memcell* t = avm_translate_operand(&instr->arg1, (avm_memcell*)  0);
    avm_memcell* i = avm_translate_operand(&instr->arg2, &ax);
    
    
    assert(lv && (&stack[N-1] >= lv && lv > &stack[top] || lv==&retval));
    assert(t && &stack[N-1] >= t && t>&stack[top] );
    assert(i );

    if (t->type != table_m)
        avm_error("illegal use of type %s as table !",typeStrings[t->type]);
    else{
        avm_memcell* content = avm_tablegetelem(t->data.tableVal,i);
        if(content)
            avm_assign(lv, content);
        else{
            char* ts = avm_tostring(t);
            char* is = avm_tostring(i);
            avm_warning("%s[%s] not found!",ts , is);
            free(ts);
            free(is);
        }
    }
       
    
}

void execute_tablesetelem(instruction* instr){

    avm_memcell* t = avm_translate_operand(&instr->result, (avm_memcell*)  0);
    avm_memcell* i = avm_translate_operand(&instr->arg1, &ax);
    avm_memcell* c = avm_translate_operand(&instr->arg2, &bx);

    assert(t && &stack[N-1] >= t && t>&stack[top] );
    assert(i && c);

    if (t->type != table_m)
        avm_error("illegal use of type %s as table !",typeStrings[t->type]);
    else
        avm_tablesetelem(t->data.tableVal, i, c);

    
}

void avm_inialize(void){   
    avm_initstack();
    avm_registerlibfunc("print", libfunc_print);
    avm_registerlibfunc("typeof", libfunc_typeof);
    
    /*Same for all the rest library functions*/
}


void libfunc_totalarguments(void){
    /*Get tops of previous activation record.*/
    unsigned p_topsp = avm_get_envvalue(topsp+AVM_SAVEDTOPSP_OFFSET);
    avm_memcellclear(&retval);
    if(!p_topsp){/*if 0,no previus activation record. */
        avm_error("'totalarguments' called outside a function! ");
        retval.type=nil_m;
    }
    else{/*Extract the number of actual argument for the previous activation record*/
        retval.type=number_m;
        retval.data.numVal=avm_get_envvalue(p_topsp + AVM_NUMACTUALS_OFFSET);

    }    
}





