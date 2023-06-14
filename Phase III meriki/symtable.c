#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtable.h"
int main() {


    insertLibFuncts();
    // Create some variables and functions to insert
    Variable* var1 = createVariable("x", 0, 10);
    Variable* var2 = createVariable("y", 0, 20);
    Function* func1 = createFunction("f", 0, 30);
    Function* func2 = createFunction("g", 0, 40);

    /* Insert variables and functions into the hash table*/
    insert(var1, NULL, GLOBAL, "x", 0, 10);
    insert(var2, NULL, GLOBAL, "y", 0, 20);
    insert(NULL, func1, USERFUNC, "f", 0, 30);
    insert(NULL, func2, USERFUNC, "g", 0, 40);

    /* Create another variable with the same name as var1*/
    Variable* var3 = createVariable("x", 0, 50);
    Variable* var4 = createVariable("x", 0, 51);
    /* Insert it into the hash table*/
    insert(var3, NULL, GLOBAL, "x", 0, 50);
    insert(var4, NULL, GLOBAL, "x", 0, 51);

    /* Access entries in the hash table*/
    unsigned int hashval = hash("x");
    SymbolTableEntry* entry = &hashTable[hashval];
    while (entry != NULL) {
        if (entry->isActive && strcmp(entry->value.varVal->name, "x") == 0) {
            printf("Variable %s found in scope %d, line %d\n", entry->value.varVal->name, entry->value.varVal->scope, entry->value.varVal->line);
        }
        entry = entry->next;
    }
    printHashTable();


    return 0;
}
