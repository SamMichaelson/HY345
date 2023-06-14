#include <stdbool.h>
#include "instructions.h"


#define AVM_STACKENV_SIZE 1024
typedef enum avm_memcell_t {
    number_m = 0,
    string_m = 1,
    bool_m = 2,
    table_m = 3,
    userfunc_m = 4,
    libfunc_m = 5,
    nil_m = 6,
    undef_m = 7
} avm_memcell_t;

typedef struct avm_memcell {
    avm_memcell_t type;
    union {
        double numVal;
        char* strVal;
        unsigned char boolVal;
        struct avm_table* tableVal;
        unsigned funcVal;
        char* libfuncVal;
    } data;
} avm_memcell;


#define AVM_STACKSIZE 4096
int N=AVM_STACKSIZE;
#define AVM_WIPEOUT(m) memset(&(m), 0, sizeof(m))


struct avm_memcell stack[AVM_STACKSIZE];

static void avm_initstack(void) {
    for (unsigned i = 0; i < AVM_STACKSIZE; i++) {
        AVM_WIPEOUT(stack[i]);
        stack[i].type = undef_m;
    }
}
#define AVM_TABLE_HASHSIZE 211

typedef struct avm_table_bucket{
    struct avm_memcell         key;
    struct avm_memcell         value;
    struct avm_table_bucket*   next;
}avm_table_bucket;
typedef struct avm_table{
    unsigned                    refCounter;
    struct avm_table_bucket*    strIndexed[AVM_TABLE_HASHSIZE];
    struct avm_table_bucket*    numIndexed[AVM_TABLE_HASHSIZE];
    unsigned                    total;
}avm_table;


avm_table*              avm_tablenew(void);
void                    avm_tabledestroy( avm_table* t);



/*BOUNUS IMPLEMENT USERFUNCS LIBFUNCS AND BOOL
here we are given nums and strings*/

typedef void (*memclear_func_t)(avm_memcell*);


extern void memclear_string(avm_memcell* m){
    assert(m->data.strVal);
    free(m->data.strVal);
}

void avm_tabledecrefcounter ( avm_table* t){
    assert(t->refCounter > 0);
    if(!--t->refCounter)
        avm_tabledestroy(t);
}

extern void memclear_table(avm_memcell* m){
    assert(m->data.tableVal);
    avm_tabledecrefcounter(m->data.tableVal);
}

memclear_func_t memclearFuncs[]={
    0,
    memclear_string,
    0,
    memclear_table,
    0,
    0,
    0,
    0
};

void avm_memcellclear(avm_memcell* m){
    if(m->type !=undef_m){
        memclear_func_t f=memclearFuncs[m->type];
        if(f)
            (*f)(m);
        m->type=undef_m;
    }
}

void avm_tableincrefcounnter( avm_table* t){
    ++t->refCounter;
}
/*
automatic garbage collection for tables when 
refence counter gets zero.
*/

void avm_tablebucketdestroy( avm_table_bucket** p){
    for(unsigned i=0; i<AVM_TABLE_HASHSIZE; ++i,++p){
        for( avm_table_bucket* b=*p; b;){
            avm_table_bucket* del=b;
            b=b->next;
            avm_memcellclear(&del->key);
            avm_memcellclear(&del->value);
            free(del);
        }
        p[i]=(avm_table_bucket*)0;
    } 
}


void avm_tabledestroy(avm_table* t){
    avm_tablebucketdestroy(t->strIndexed);
    avm_tablebucketdestroy(t->numIndexed);
    free(t);
}


void avm_tablebucketsinit ( avm_table_bucket** p) {
    for(unsigned i=0; i<AVM_TABLE_HASHSIZE; ++i)
        p[i] = NULL;
}

/*The refernce counter is initially zero.
*/

avm_table* avm_tablenew(void){
    avm_table* t=( avm_table*) malloc(sizeof( avm_table));
    AVM_WIPEOUT(*t);

    t->refCounter = t->total =0;
    avm_tablebucketsinit(t->numIndexed);
    avm_tablebucketsinit(t->strIndexed);

    return t;

}





