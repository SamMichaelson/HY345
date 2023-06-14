#include "scope.h"


int main() {
    
    insertElem( GLOBAL, "x", 0, 1);
    insertElem( GLOBAL, "x", 0, 1);
    insertElem( USERFUNC, "x", 0, 2);
    printHashTable1();
    return 0;
}

void printHashTable1() {
    for (int i = 0; i < HASHSIZE; i++) {
        printf("[%d]", i);
        if (hashTable[i].isActive) {
            SymbolTableEntry *entry = &hashTable[i];
            while (entry != NULL) {
                if (entry->type == GLOBAL || entry->type == LOCALL || entry->type == FORMAL) {
                    printf(" %s(line:%d)", entry->value.varVal->name, entry->value.varVal->line);
                } else {
                    printf(" %s(line:%d)", entry->value.funcVal->name, entry->value.funcVal->line);
                }
                entry = entry->next;
                if (entry != NULL) {
                    printf("->");
                }
            }
        }
        printf("\n");
    }
}
