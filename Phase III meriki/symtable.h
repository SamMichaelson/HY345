
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h> 
#include <fcntl.h>
#include <math.h>

#define HASHSIZE 1024



typedef enum scopespace_t{
    programvar,
    functionlocal,
    formalarg
}scopespace_t;

typedef struct Variable {
    const char *name;
    unsigned int scope;
    unsigned int line;
    enum scopespace_t    space;
    unsigned        offset;
    struct Variable *next;
} Variable;

typedef struct Function {
    const char *name;
    unsigned int scope;
    unsigned int line;
    unsigned int functionlocals;
    unsigned int iaddress;
    struct Function *next;
} Function;

enum SymbolType {
    GLOBAL, LOCALL, FORMAL,  USERFUNC, LIBFUNC
};

typedef struct SymbolTableEntry { 
    bool isActive;
    bool hashable;
    union {
        Variable *varVal;
        Function *funcVal;
    }value;
    enum SymbolType type;
    struct SymbolTableEntry *next;
} SymbolTableEntry;

SymbolTableEntry hashTable[HASHSIZE];

unsigned int  generateHashKey(const char *name, unsigned int scope) {
   unsigned int hash = 0;
    unsigned int len = strlen(name);

    for (int i = 0; i < len; i++) {
        hash = hash * 31 + name[i];
    }

    hash = (hash + scope) % HASHSIZE;

    return hash;
}

Variable* createVariable(const char *name, unsigned int scope, unsigned int line,enum scopespace_t space,unsigned offset) {
    Variable* var = malloc(sizeof(Variable));
    var->name = name;
    var->scope = scope;
    var->line = line;
    var->space = space;
    var->offset = offset;
    var->next = NULL;
    return var;
}

Function* createFunction(const char *name, unsigned int scope, unsigned int line , unsigned int functionlocals, unsigned int iaddress) {
    Function* func = malloc(sizeof(Function));
    func->name = name;
    func->scope = scope;
    func->line = line;
    func->functionlocals = functionlocals;
    func->iaddress = iaddress;
    func->next = NULL;
    return func;
}


void insertVariable(Variable *var, Function *func, enum SymbolType type, const char *name, unsigned int scope, unsigned int line,enum scopespace_t space,unsigned  offset) {
    unsigned int hashname = generateHashKey(name, scope);
    SymbolTableEntry *entry = &hashTable[hashname];
    if (!entry->hashable) {
 
        entry->isActive = true;
        entry->hashable = true;
        entry->type = type;
        entry->value.varVal = var;
   
        entry->next = NULL;
    } else {
        SymbolTableEntry *newEntry = malloc(sizeof(SymbolTableEntry));
        newEntry->isActive = true;
        newEntry->type = type;
        newEntry->value.varVal = var;
       
        newEntry->next = entry->next;
        entry->next = newEntry;
    }
}

void insertFunction(Variable *var, Function *func, enum SymbolType type, const char *name, unsigned int scope, unsigned int line, unsigned int functionlocals, unsigned int iaddress) {
    unsigned int hashname = generateHashKey(name, scope);
    SymbolTableEntry *entry = &hashTable[hashname];
    if (!entry->hashable) {
        entry->isActive = true;
        entry->hashable = true;
        entry->type = type;
        entry->value.funcVal = func;
        
        entry->next = NULL;
    } else {
        SymbolTableEntry *newEntry = malloc(sizeof(SymbolTableEntry));
        newEntry->isActive = true;
        newEntry->type = type;
        newEntry->value.funcVal = func;
        newEntry->next = entry->next;
        entry->next = newEntry;
    }
}



SymbolTableEntry* searchScope(const char* name, unsigned int scope) {
  
    unsigned int hashname = generateHashKey(name, scope);
    SymbolTableEntry *entry = &hashTable[hashname];
    SymbolTableEntry *result = NULL; 
    
    while (entry != NULL) {
        if (entry->isActive) {
            if (entry->hashable && strcmp(entry->value.varVal->name, name) == 0 && entry->value.varVal->scope == scope ) {
                /* Found a match*/
                result = entry;
                break;
            } else if (entry->type == USERFUNC || entry->type == LIBFUNC) {
                Function *func = entry->value.funcVal;
                while (func != NULL) {
                    if (strcmp(func->name, name) == 0 && func->scope == scope) {
                        SymbolTableEntry *newEntry = malloc(sizeof(SymbolTableEntry));
                        newEntry->hashable = true;
                        newEntry->type = entry->type;
                        newEntry->value.funcVal = func;
                        newEntry->next = result;
                        result = newEntry;
                    }
                    func = func->next;
                }
            } else if (entry->type == GLOBAL || entry->type == LOCALL || entry->type == FORMAL) {
                Variable *var = entry->value.varVal;
                while (var != NULL) {
                    if (strcmp(var->name, name) == 0 && var->scope == scope) {
                        SymbolTableEntry *newEntry = malloc(sizeof(SymbolTableEntry));
                        newEntry->hashable = true;
                        newEntry->type = entry->type;
                        newEntry->value.varVal = var;
                        newEntry->next = result;
                        result = newEntry;
                    }
                    var = var->next;
                }
            }
        }
        entry = entry->next;
    }
    
    return result;
}



int k=0;


void hide(unsigned int scope) {
    for (int i = 0; i < HASHSIZE; i++) {
        SymbolTableEntry *entry = &hashTable[i];
        if (entry->isActive && entry->hashable) {
            if (entry->type == GLOBAL || entry->type == LOCALL || entry->type == FORMAL) {
                Variable *var = entry->value.varVal;
                while (var != NULL) {
                    if (var->scope == scope) {
                        entry->isActive = false;
                    }
                    var = var->next;
                }
            } else if (entry->type == USERFUNC || entry->type == LIBFUNC) {
                Function *func = entry->value.funcVal;
                while (func != NULL) {
                    if (func->scope == scope) {
                        entry->isActive = false;
                    }
                    func = func->next;
                }
            }
        }
    }
}



void printEntry(SymbolTableEntry *entry) {
    if (entry->type == GLOBAL || entry->type == LOCALL || entry->type == FORMAL) {
        Variable *var = entry->value.varVal;
        while (var != NULL) {
            if (var->name != NULL) {
                printf("Name: %s, Scope: %d, Line: %d, ScopeSpace: %d, offset: %d\n\n", var->name, var->scope, var->line ,var->space,var->offset);
            }
            var = var->next;
        }
    } else if (entry->type == USERFUNC || entry->type == LIBFUNC) {
        Function *func = entry->value.funcVal;
        while (func != NULL) {
            if (func->name != NULL) {
                printf("Name: %s, Scope: %d, Line: %d\n\n", func->name, func->scope, func->line);
            }
            func = func->next;
        }
    }
}
/**/
void print() {
    for (int i = 0; i < HASHSIZE; i++) {
        SymbolTableEntry *entry = &hashTable[i];
        if (entry->isActive) {
            printf("%d:", i);
            printEntry(entry);
        }
    }
}

void printHashTable() {
    for (int i = 0; i < HASHSIZE; i++) {
        if (hashTable[i].isActive) {
            printf("[%d]", i);
            SymbolTableEntry *entry = &hashTable[i];
            while (entry != NULL) {
                if (entry->type == GLOBAL || entry->type == LOCALL || entry->type == FORMAL) {
                    printf("   (%s, %d, %d , %d , %d )", entry->value.varVal->name, entry->value.varVal->scope,entry->value.varVal->line,entry->value.varVal->space,entry->value.varVal->offset);
                } else {
                    printf("   (%s, %d, %d , %d , %d )", entry->value.funcVal->name,entry->value.funcVal->scope ,entry->value.funcVal->line,entry->value.funcVal->functionlocals,entry->value.funcVal->iaddress);
                }
                entry = entry->next;
                if (entry != NULL) {
                    printf("  ->  ");
                }
            }printf("\n");
        } else {
        }
    }
}


 void insertLibFuncts(){
    Function* lprint =createFunction("print",0,0,0,0);
    Function* linput =createFunction("input",0,0,0,0);
    Function* lobjectmemberkeys =createFunction("objectmemberkeys",0,0,0,0);
    Function* lobjecttotalmembers =createFunction("objecttotalmembers",0,0,0,0);
    Function* lobjectcopy =createFunction("objectcopy",0,0,0,0);
    Function* ltotalarguments =createFunction("totalarguments",0,0,0,0);
    Function* largument =createFunction("argument",0,0,0,0);
    Function* ltypeof =createFunction("typeof",0,0,0,0);
    Function* lstrtonum =createFunction("strtonum",0,0,0,0);
    Function* lsqrt =createFunction("sqrt",0,0,0,0);
    Function* lcos =createFunction("cos",0,0,0,0);
    Function* lsin =createFunction("sin",0,0,0,0);

    insertFunction(NULL,lprint,LIBFUNC,"print",0,0,0,0);
    insertFunction(NULL,linput,LIBFUNC,"input",0,0,0,0);
    insertFunction(NULL,lobjectmemberkeys,LIBFUNC,"objectmemberkeys",0,0,0,0);
    insertFunction(NULL,lobjecttotalmembers,LIBFUNC,"objecttotalmembers",0,0,0,0);
    insertFunction(NULL,lobjectcopy,LIBFUNC,"objectcopy",0,0,0,0);
    insertFunction(NULL,ltotalarguments,LIBFUNC,"totalarguments",0,0,0,0);
    insertFunction(NULL,largument,LIBFUNC,"argument",0,0,0,0);
    insertFunction(NULL,ltypeof,LIBFUNC,"typeof",0,0,0,0);
    insertFunction(NULL,lstrtonum,LIBFUNC,"strtonum",0,0,0,0);
    insertFunction(NULL,lsqrt,LIBFUNC,"sqrt",0,0,0,0);
    insertFunction(NULL,lcos,LIBFUNC,"cos",0,0,0,0);
    insertFunction(NULL,lsin,LIBFUNC,"sin",0,0,0,0);



}

char *names[100];
void push(char* name, int top) {
    top++;
    if (top >= 0) {
        names[top] = (char*) malloc(strlen(name) + 1);
        strcpy(names[top], name);
    } else {
    }
}

char* pop(int top) {
    if (top < 0) {
        return NULL;
    }
    char* name = names[top];
    top--;
    return name;
}

char* top_name(int top) {
    if (top < 0) {
        return NULL;
    }
    return names[top];
}

void print_stack(int top) {
    /*printf("top %d\n",top);*/
   /* printf("Stack contents:\n");*/
    if (top < 0) {
     /*   printf("Stack is empty\n");*/
        return;
    }
    for (int i = top; i >= 0; i--) {
        if(names[i]!=NULL)
           {}/* printf("%s\n", names[i]);*/
        else  {} 
    }
}




/*for break and continue*/

int pushWhileStack(int* whileStack, int top) {
    (top)++;
    if (top >= 0) {
        whileStack[top] = 0; 
    } else {
    }
    return top;
}

int popWhileStack(int* whileStack, int top) {
    if (top < 0) {
    }else{
    int value = whileStack[top];
    (top)--;}
    return top;
}

void topFunc(int* whileStack, int top) {
    if (top >= 0) {
        whileStack[top]++;
    } else {
    }
}

void topCloseFunc(int* whileStack, int top) {
    if (top >= 0) {
        whileStack[top]--;
    } else {
    }
}

int topWhileStack(int* whileStack, int top) {
    if (top < 0) {
        return top;
    }
    return whileStack[top];
}

void printWhileStack(int* whileStack, int top) {
    if (top < 0) {
        /*printf("Stack is empty\n");*/
        return;
    }
   /* printf("Stack contents:\n");
    */for (int i = top; i > 0; i--) {
      /*  printf("%d\t", whileStack[i]);*/
    }/*printf("\n");*/
}