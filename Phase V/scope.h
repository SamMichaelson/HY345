


#include "symtable.h"

void colortxt(char* f){
    if(f=="v")  printf("\033[1;34m");/*RED*/
    else if(f=="f")  printf("\033[0;32m");/*BLUE*/
    else if(f=="pink") printf("\033[1;35m"); /*PINK*/
    else if(f=="green") printf("\033[1;32m"); /*BRIGHT GREEN*/
    else if(f=="yellow") printf("\033[1;33m"); /*yellow*/
    else if(f=="white") printf("\033[1;37m"); /*bold white*/
    else if(f=="orange") printf("\033[0;33m"); /*orange*/
    else if (f== "purple")printf("\033[1;91m");   /* PURPLE*/

}
void reset(){
    printf("\033[0m");
}

typedef struct ListNode {
    SymbolTableEntry* entry;
    struct ListNode* next;
} ListNode;

ListNode** scopeLists = NULL;

int numScopes = 0;

void insertIntoScopeList(SymbolTableEntry* entry) {
    int scope;
    if(entry->type==USERFUNC || entry->type==LIBFUNC){
        scope = entry->value.funcVal->scope;
    }else{
        scope = entry->value.varVal->scope;
    }
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->entry = entry;
    newNode->next = NULL;
    if (scope >= numScopes) {

        scopeLists = (ListNode**)realloc(scopeLists, sizeof(ListNode*) * (scope + 1));
        for (int i = numScopes; i <= scope; i++) {
            scopeLists[i] = NULL;
        }
        numScopes = scope + 1;
    }

    ListNode* currNode = scopeLists[scope];
    while (currNode != NULL) {
        if (currNode->entry == entry) {
            return;
        }
        currNode = currNode->next;
    }

    if (scopeLists[scope] == NULL) {
        scopeLists[scope] = newNode;
    } else {
        newNode->next = scopeLists[scope];
        scopeLists[scope] = newNode;
    }
}

void autoInsert() {
    for (int i = 0; i < HASHSIZE; i++) {
        SymbolTableEntry* entry = &hashTable[i];
        while (entry != NULL) {
            if (entry->isActive) {
                insertIntoScopeList(entry);
            }
            entry = entry->next;
        }
    }
}


SymbolTableEntry* searchScopeList(int scope) {
    char* spaceString;
    if (scope < numScopes && scopeLists[scope] != NULL) {

        printf("Scope %d:\n", scope);
        ListNode* curr = scopeLists[scope];
        while (curr != NULL) {
            SymbolTableEntry* entry = curr->entry;
            if (entry->value.funcVal != NULL && (entry->type==USERFUNC || entry->type==LIBFUNC)) {
               if(entry->type==USERFUNC){
                 colortxt("f");   
               }
               
                printf("Function %s found in scope %d, line %d , functionlocas  %d, iaddress %d \n", entry->value.funcVal->name, entry->value.funcVal->scope, entry->value.funcVal->line, entry->value.funcVal->functionlocals, entry->value.funcVal->iaddress);
                reset();
            }else if (entry->value.varVal != NULL) {
                colortxt("v");
                if( entry->value.varVal->space==0){
                    spaceString="programvar";
                }else if(entry->value.varVal->space==1){
                    spaceString="functionlocal";
                }else{
                     spaceString="formalarg";
                }
                printf("Variable %s found in scope %d, line %d, space %s , offset %d, type: %d\n", entry->value.varVal->name, entry->value.varVal->scope, entry->value.varVal->line, spaceString, entry->value.varVal->offset,entry->type);
                reset();
            } 
            curr = curr->next;
}        return scopeLists[scope]->entry;
    }
    return NULL;
}


void insertElemVariable(enum SymbolType type, const char *name, unsigned int scope, unsigned int line,enum scopespace_t space,unsigned  offset){
     
        Variable *var=createVariable(name, scope, line , space , offset);
        insertVariable(var,NULL,type,name,scope,line,space,offset);
        
    autoInsert();
   

}


void insertElemFunction(enum SymbolType type, const char *name, unsigned int scope, unsigned int line, unsigned int functionlocals, unsigned int iaddress){
     
        Function *func=createFunction(name, scope, line,functionlocals,iaddress);
        insertFunction(NULL,func,type,name,scope,line,functionlocals,iaddress);


    autoInsert();
   
      

}


   



