#include <stdlib.h>
#include <string.h>
#include "quad_list.h"




#define AVM_STACKSIZE 4096
#define AVM_WIPEOUT(m) memset(&(m), 0, sizeof(m))


#define EXPAND_SIZE_IN 1024
#define CURR_SIZE_IN   (totalinstr*sizeof(instruction))
#define NEW_SIZE_IN    (EXPAND_SIZE_IN*sizeof(instruction)+CURR_SIZE_IN)



typedef struct {
    quad* data;
    int top;
    int capacity;
    SymbolTableEntry** entry;
} QuadStack;

QuadStack createStack(int capacity) {
    QuadStack stack;
    stack.capacity = capacity;
    stack.top = -1;
    stack.data = (quad*)malloc(capacity * sizeof(quad));
    stack.entry = (SymbolTableEntry**)malloc(capacity * sizeof(SymbolTableEntry*));
    for (int i = 0; i < capacity; i++) {
        stack.entry[i] = (SymbolTableEntry*)malloc(sizeof(SymbolTableEntry));
    }
    return stack;
}

QuadStack funcstack; 
int isFull(QuadStack stack) {
    return stack.top == stack.capacity - 1;
}

int isEmpty(QuadStack stack) {
    return stack.top == -1;
}

SymbolTableEntry * topStack(QuadStack stack){
    if (isEmpty(stack)) {
    }else
        return stack.entry[stack.top];
}

void pushStack(QuadStack* stack, SymbolTableEntry* item) {
    if (isFull(*stack)) {
        return;
    }
         stack->entry[++stack->top] = item;
}


SymbolTableEntry* popStack(QuadStack* stack) {
    if (isEmpty(*stack)) {
        return NULL;
    }
    return stack->entry[stack->top--];
}




typedef enum vmopcode {
    assign_v, add_v, sub_v,
    mul_v, div_v, mod_v,
    uminus_v, and_v, or_v,
    not_v, jeq_v, jne_v,
    jle_v, jge_v, jlt_v,
    jgt_v, call_v, pusharg_v,
    funcenter_v, funcexit_v, newtable_v,
    tablegetelem_v, tablesetelem_v, nop_v ,jump_v
}vmopcode;

enum vmarg_t {
    label_a = 0,
    global_a = 1,
    formal_a = 2,
    local_a = 3,
    number_a = 4,
    string_a = 5,
    bool_a = 6,
    nil_a = 7,
    userfunc_a = 8,
    libfunc_a = 9,
    retval_a = 10
};

typedef struct vmarg {
    enum vmarg_t    type;
    unsigned        val;
    double          dval;
    unsigned        offset;
    const char*     name;
} vmarg;

typedef struct instruction {
    enum vmopcode opcode;
    vmarg result;
    vmarg arg1;
    vmarg arg2;
    unsigned label;
    unsigned srcLine;
}instruction;


unsigned numOffset=0;
unsigned strOffset=0;
unsigned libOffset=0;
unsigned funcOffset=0;

unsigned currInstr = 0;
unsigned instructionlabel = 0;
unsigned totalinstr = 0;

struct instruction* instructions=(instruction*)0;;


unsigned consts_newstring(char* s) {
    return strtoul(s,NULL,10);
}

unsigned consts_newnumber(double n) {
    return (unsigned int)n;
}

unsigned libfuncs_newused(const char* s) {
    return strtoul(s,NULL,10);
}

unsigned userfuncs_newfunc(struct SymbolTableEntry* sym) {
    return sym->value.funcVal->iaddress;
}




void make_operands(struct expr* e, struct vmarg* arg) {
    if(e->sym){
        if (e->sym->type==USERFUNC){
            arg->type=userfunc_a;
            arg->val = atoi(e->sym->value.funcVal->name);
            arg->name = e->sym->value.funcVal->name;
            arg->offset=funcOffset++;
        }else if (e->sym->type==LIBFUNC){
            arg->type=libfunc_a;
            arg->val = atoi(e->sym->value.funcVal->name);
            arg->name = e->sym->value.funcVal->name;
            arg->offset=libOffset++;
        }else if (e->sym->type==GLOBAL){
            arg->type=global_a;
            arg->val = atoi(e->sym->value.varVal->name);
            arg->name = e->sym->value.varVal->name;
            arg->offset= e->sym->value.varVal->offset;
        }else if (e->sym->type==LOCALL){
            arg->type=local_a;        
            arg->val = atoi(e->sym->value.varVal->name);
            arg->name = e->sym->value.varVal->name;
            arg->offset= e->sym->value.varVal->offset;
        }else if (e->sym->type==FORMAL){
            arg->type=formal_a;
            arg->val = atoi(e->sym->value.varVal->name);
            arg->name = e->sym->value.varVal->name;
            arg->offset= e->sym->value.varVal->offset;
        }else{
            assert(0);
        }
    }
}

void make_operand(struct expr* e, struct vmarg* arg) {
    switch (e->type) {
         
        case var_e:{
            make_operands(e,arg);
            break;}
        case assignexpr_e:{
            make_operands(e,arg);
            break;}
        case tableitem_e:{
            make_operands(e,arg);
            break;}
        case arithexpr_e:{
            make_operands(e,arg);
            break;}
        case boolexpr_e:{
            make_operands(e,arg);
            break;}
        case newtable_e: {
            assert(e->sym->value.varVal);
            make_operands(e,arg);
            switch (e->sym->value.varVal->space) {
                case programvar:
                    arg->type = global_a;
                    break;
                case functionlocal:
                    arg->type = local_a;
                    break;
                case formalarg:
                    arg->type = formal_a;
                    break;
            }
            break;
        }
        case constbool_e: {
            if(e->boolConst)
                arg->name="TRUE";
            else
                arg->name="FALSE";
            arg->type = bool_a;
            break;
        }
        case conststring_e: {
            arg->val = consts_newstring(e->strConst);
            arg->type = string_a;
            arg->name = e->strConst;
            arg->offset=strOffset++;
            break;
        }
        case costnum_e: {
            arg->val = consts_newnumber(e->numConst);
            arg->dval = e->numConst;
            arg->type = number_a;
            arg->name="num";
            arg->offset= numOffset++;
            break;
        }
        case nil_e:{
            make_operands(e,arg);
            arg->type = nil_a;
            break;
        }
        case programfunc_e: {
            make_operands(e,arg);
            arg->type=userfunc_a;
            break;
        }
        case libraryfunc_e: {
            make_operands(e,arg);
            break;
        }
        default:
          assert(0);
    }
    
}
void make_retvaloperand(struct vmarg* arg) {
    arg->type = retval_a;
}

void make_numberoperand(struct vmarg* arg, double val) {
    arg->val = consts_newnumber(val);
    arg->type = number_a;
}

void make_booloperand(struct vmarg* arg, unsigned val) {
    arg->val = val;
    arg->type = bool_a;
}


struct incomplete_jump {
    unsigned insertNo;
    unsigned iaddress;
    struct incomplete_jump* next;
};

struct incomplete_jump* ij_head = NULL; /* (incomplete_jump*)0 */
unsigned ij_total = 0;

void add_incomplete_jump(unsigned insertNo, unsigned iaddress) {
    struct incomplete_jump* jump = (struct incomplete_jump*)malloc(sizeof(struct incomplete_jump));
    jump->insertNo = insertNo;
    jump->iaddress = iaddress;
    jump->next = ij_head;
    ij_head = jump;
    ij_total++;
}

void patch_incomplete_jumps() {
    unsigned intermediate_code_size = currQuad;
    unsigned target_code_size = currInstr;
    struct incomplete_jump* jump = ij_head;
    while (jump != NULL) {
        if (jump->iaddress == intermediate_code_size) {
            instructions[jump->insertNo].result.val = target_code_size;
        } else {
            instructions[jump->insertNo].result.val = quads[jump->iaddress].taddress;
        }
    }
}
 

unsigned nextinstructionlabel(){
    return instructionlabel++;
}

unsigned currprocessedquad(){
    return instructionlabel;
}

void expandInstr(void) {
    assert(totalinstr==currInstr);
    instruction* p = (instruction*) malloc(NEW_SIZE_IN);
    if(instructions) {
        memcpy(p, instructions ,CURR_SIZE_IN);
        free(instructions);
    }
    instructions = p;
    totalinstr +=EXPAND_SIZE_IN;

}

void emitIn (instruction* k)
{
    if (currInstr ==totalinstr)
        expandInstr();
    instruction* p     = instructions+currInstr++;
    p->opcode   =k->opcode;
    p->arg1     =k->arg1;
    p->arg2     =k->arg2;
    p->result   =k->result;
    p->label    =k->label; 
    p->srcLine  =k->srcLine;   

}

void generate (enum vmopcode op, quad quad) {
    instruction t;
    t.opcode = op;
    quad.taddress = nextinstructionlabel();
    if(quad.result){
        make_operand(quad.result, &t.result);
    }
    if(quad.arg1){
        make_operand(quad.arg1, &t.arg1);
    }
    if(quad.arg2){
        make_operand(quad.arg2, &t.arg2);
    }
    emitIn(&t);
} 

void generate_ADD (quad quad) { generate(add_v, quad);  }
void generate_SUB (quad quad) { generate(sub_v, quad); }
void generate_MUL (quad quad) { generate(mul_v, quad); }
void generate_DIV (quad quad) { generate(div_v, quad); }
void generate_MOD (quad quad) { generate(mod_v, quad); }
void generate_NEWTABLE (quad quad) { generate(newtable_v, quad); }
void generate_TABLEGETELM (quad quad) { generate(tablegetelem_v, quad); }
void generate_TABLESETELEM (quad quad) { generate(tablesetelem_v, quad); }
void generate_ASSIGN (quad quad) { generate(assign_v, quad);  }
void generate_NOP () {  instruction t; t.opcode=nop_v; emitIn(&t); } 
void generate_relational ( vmopcode op, quad quad) {
    instruction t;
    t.label=quad.label;
    t.opcode = op;
    if(quad.arg1)
        make_operand(quad.arg1, &t.arg1);
    if(quad.arg2)
        make_operand(quad.arg2, &t.arg2);
    t.result.type = label_a;
    if (quad.label < currprocessedquad())
        t.result.val = quads[quad.label].taddress;
    else
        add_incomplete_jump(nextinstructionlabel(), quad.label);
    quad.taddress = nextinstructionlabel();
    emitIn(&t);
} 
void generate_JUMP (quad quad) { 
    generate_relational(jump_v, quad); 
}
void generate_IF_EQ (quad quad) { generate_relational(jeq_v, quad); }
void generate_IF_NOTEQ(quad quad) { generate_relational(jne_v, quad); }
void generate_IF_GREATER (quad quad) { generate_relational(jgt_v, quad); }
void generate_IF_GREATEREQ(quad quad) { generate_relational(jge_v, quad); }
void generate_IF_LESS (quad quad) { generate_relational(jlt_v, quad); }
void generate_IF_LESSEQ (quad quad) { generate_relational(jle_v, quad); } 
void reset_operand( vmarg* arg) {
    arg=NULL;
}
void generate_NOT (quad quad) {
        quad.taddress = nextinstructionlabel();
        instruction t;
        t.opcode = jeq_v;
        make_operand(quad.arg1, &t.arg1);
        make_booloperand(&t.arg2, false);
        t.result.type = label_a;
        t.result.val = nextinstructionlabel()+3;
        emitIn(&t);
        t.opcode = assign_v;
        make_booloperand(&t.arg1, false);
        reset_operand(&t.arg2);
        make_operand(quad.result, &t.result);
        emitIn(&t);

        t.opcode = jump_v;
        reset_operand (&t.arg1);
        reset_operand(&t.arg2);
        t.result.type = label_a;
        t.result.val = nextinstructionlabel()+2;
        emitIn(&t);
        t.opcode = assign;
        make_booloperand(&t.arg1, true);
        reset_operand(&t.arg2);
        make_operand(quad.result, &t.result);
        emitIn(&t);
}


void generate_AND (quad quad) {
        quad.taddress = nextinstructionlabel();
        instruction t;
        t.opcode = jeq_v;
        make_operand(quad.arg1, &t.arg1);
        make_booloperand(&t.arg2, true);
        t.result.type = label_a;
        t.result.val = nextinstructionlabel()+4;
        emitIn(&t);
        make_operand(quad.arg2, &t.arg1);
        t.result.val = nextinstructionlabel()+3;
        emitIn(&t);

        t.opcode = assign_v;
        make_booloperand(&t.arg1, false);
        reset_operand(&t.arg2);
        make_operand(quad.result, &t.result);
        emitIn(&t);
        t.opcode = jump_v;
        reset_operand (&t.arg1);
        reset_operand(&t.arg2);
        t.result.type = label_a;
        t.result.val = nextinstructionlabel()+2;
        emitIn(&t);
        t.opcode = assign_v;
        make_booloperand(&t.arg1, true);
        reset_operand(&t.arg2);
        make_operand(quad.result, &t.result);
        emitIn(&t);
} 

void generate_OR (quad quad) {
        quad.taddress = nextinstructionlabel();
        instruction t;
        t.opcode = jeq_v;
        make_operand(quad.arg1, &t.arg1);
        make_booloperand(&t.arg2, true);
        t.result.type = label_a;
        t.result.val = nextinstructionlabel()+4;
        emitIn(&t);
        make_operand(quad.arg2, &t.arg1);
        t.result.val = nextinstructionlabel()+3;
        emitIn(&t);

        t.opcode = assign_v;
        make_booloperand(&t.arg1, false);
        reset_operand(&t.arg2);
        make_operand(quad.result, &t.result);
        emitIn(&t);
        t.opcode = jump_v;
        reset_operand (&t.arg1);
        reset_operand(&t.arg2);
        t.result.type = label_a;
        t.result.val = nextinstructionlabel()+2;
        emitIn(&t);
        t.opcode = assign_v;
        make_booloperand(&t.arg1, true);
        reset_operand(&t.arg2);
        make_operand(quad.result, &t.result);
        emitIn(&t);
} 

void generate_PARAM(quad quad) {
    quad.taddress = nextinstructionlabel();
    instruction t;
    t.opcode = pusharg_v;
    make_operand(quad.arg1, &t.arg1);
    emitIn(&t);
}
void generate_CALL(quad quad) {
    quad.taddress = nextinstructionlabel();
    instruction t;
    t.opcode = call_v;
    make_operand(quad.arg1, &t.arg1);
    emitIn(&t);
}
void generate_GETRETVAL(quad quad) {
    quad.taddress = nextinstructionlabel();
    instruction t;
    t.opcode = assign_v;
    make_operand(quad.result, &t.result);
    make_retvaloperand(&t.arg1);
    emitIn(&t);
} 



void generate_FUNCSTART(quad quad) {

    SymbolTableEntry* f= quad.result->sym;
    f->value.funcVal->iaddress = nextinstructionlabel();
    quad.taddress = nextinstructionlabel();

    if (funcstack.capacity == 0) {
        funcstack = createStack(1000); 
    }
    pushStack(&funcstack,f);
    instruction t;
    t.opcode=funcenter_v;
    make_operand(quad.result,&t.result);
    emitIn(&t);
}

void append(int* list, int value) {
    int length = sizeof(list) / sizeof(list[0]);
    list[length] = value;
}

void generate_RETURN(quad quads) {
    quads.taddress = nextinstructionlabel();
    instruction t;
    t.opcode=assign_v;
    
    make_retvaloperand(&t.result);
    make_operand(quads.result,&t.arg1);
    emitIn(&t);
    SymbolTableEntry f;

    f=*topStack(funcstack);
    t.result.offset=f.value.funcVal->functionlocals;
    t.opcode=jump_v;
    
    reset_operand(&t.arg1);
    reset_operand(&t.arg2);
    t.result.type=label_a;
    
}

void backpatch(int* list, int label) {
    for (int i = 0;  i < *list; i++) {
        list[i] = label;
    }
}

void generate_FUNCEND(quad quads) {
    SymbolTableEntry* f = popStack(&funcstack);
    
    quads.taddress = nextinstructionlabel();
    instruction t;
    t.opcode = funcexit_v;
   
    t.result.offset= f->value.funcVal->functionlocals;
    make_operand(quads.result, &t.result);
    emitIn(&t);
}


typedef void (*generator_func_t)(quad);

generator_func_t generators[] = {
    generate_ASSIGN,
    generate_ADD,
    generate_SUB,
    generate_MUL,
    generate_DIV,
    generate_MOD,
    generate_NOT,
    generate_AND,
    generate_OR,
    generate_NOT,
    generate_IF_EQ,
    generate_IF_NOTEQ,
    generate_IF_LESS,
    generate_IF_GREATEREQ,
    generate_IF_LESS,
    generate_IF_GREATER,
    generate_JUMP,
    generate_CALL,
    generate_PARAM,
    generate_RETURN,
    generate_GETRETVAL,
    generate_FUNCSTART,
    generate_FUNCEND,
    generate_NEWTABLE,
    generate_TABLEGETELM,
    generate_TABLESETELEM
};


const char* getVmargTypeName(enum vmarg_t type) {
    static const char* vmargTypeNames[] = {
        "label",
        "global",
        "formal",
        "local",
        "number",
        "string",
        "bool",
        "nil",
        "userfunc",
        "libfunc",
        "retval"
    };

    if (type >= label_a && type <= retval_a) {
        return vmargTypeNames[type];
    } else {
        return "Unknown";
    }
}


void generates() {
   
    printf("\n\n");
    int i = 0;
    for ( i=0; i < nextquadlabel(); i++) {
            if( quads[i].line){
                generators[quads[i].op](quads[i]);
                
            }
    }
}

void printOperand(vmarg op) {
    if(op.type>=0 && op.type<=10){
        if(op.type<10)
            printf("\t| 0");
        else
            printf("\t| ");
    }
    switch (op.type) {
        case label_a:
            printf("%d(%s), %d:%s", op.type,getVmargTypeName(op.type),op.offset,  op.name);
            break;
        case global_a:
            printf("%d(%s), %d:%s", op.type,getVmargTypeName(op.type),op.offset,  op.name);
            break;
        case formal_a:
            printf("%d(%s), %d:%s", op.type,getVmargTypeName(op.type),op.offset,  op.name);
            break;
        case local_a:
            printf("%d(%s), %d:%s", op.type,getVmargTypeName(op.type),op.offset,  op.name);
            break;
        case number_a:
            printf("%d(%s), %d:%u", op.type,getVmargTypeName(op.type),op.offset,  op.val);
            break;
        case string_a:
            printf("%d(%s), %d:\"%s\"", op.type,getVmargTypeName(op.type), op.offset, op.name);
            break;
        case bool_a:
            printf("%d(%s), %d:%s", op.type,getVmargTypeName(op.type),op.offset,  op.name);
            break;
        case nil_a:
            printf("%d(%s), %d:%s", op.type,getVmargTypeName(op.type),op.offset,  op.name);
            break;
        case userfunc_a:
            printf("%d(%s), %d:\"%s\"", op.type,getVmargTypeName(op.type), op.offset, op.name);
            break;
        case libfunc_a:
            printf("%d(%s), %d:%s", op.type,getVmargTypeName(op.type),  op.offset,  op.name);
            break;
        case retval_a:
            printf("%d(%s)", op.type,getVmargTypeName(op.type));
            break;
        default:
            break;
    }
}

void printInstruction(const instruction instr, const int index) {
    if(index<10)printf("0");
    switch (instr.opcode) {
        case assign_v:
            if(instr.result.type ==10)
                printf( "%d | assign\t| %d(%s)\t\t", index, instr.result.type, getVmargTypeName(instr.result.type));
            else
                printf("%d | assign\t| 0%d(%s),\t%u:%s \t", index, instr.result.type, getVmargTypeName(instr.result.type), instr.result.offset, instr.result.name);
            printOperand(instr.arg1);
            printOperand(instr.arg2);
            printf("\n");
            break;
        case add_v:
            printf( "%d | add\t| 0%d(%s),\t%u:%s \t", index, instr.result.type, getVmargTypeName(instr.result.type), instr.result.offset, instr.result.name);
            printOperand(instr.arg1);
            printOperand(instr.arg2);
            printf("\n");
            break;
        case sub_v:
            printf( "%d | sub\t| 0%d(%s),\t%u:%s \t", index, instr.result.type, getVmargTypeName(instr.result.type), instr.result.offset, instr.result.name);
            printOperand(instr.arg1);
            printOperand(instr.arg2);
            printf("\n");
            break;
        case mul_v:
            printf( "%d | mul\t| 0%d(%s),\t%u:%s \t", index, instr.result.type, getVmargTypeName(instr.result.type), instr.result.offset, instr.result.name);
            printOperand(instr.arg1);
            printOperand(instr.arg2);
            printf("\n");
            break;
        case div_v:
            printf( "%d | div\t| 0%d(%s),\t%u:%s \t", index, instr.result.type, getVmargTypeName(instr.result.type), instr.result.offset, instr.result.name);
            printOperand(instr.arg1);
            printOperand(instr.arg2);
            printf("\n");
            break;
        case mod_v:
            printf( "%d | mod\t| 0%d(%s),\t%u:%s \t", index, instr.result.type, getVmargTypeName(instr.result.type), instr.result.offset, instr.result.name);
            printOperand(instr.arg1);
            printOperand(instr.arg2);
            printf("\n");
            break;
        case jeq_v:   
            printf( "%d | if_eq\t| 0%d(%s),\t%u:%s \t", index, instr.result.type, getVmargTypeName(instr.result.type), instr.result.offset, instr.result.name);
            printOperand(instr.arg1);
            printOperand(instr.arg2);
            break;
        case jne_v:
            printf("%d | if_noteq | %d %d | %d %d | %d %d\n", index, instr.result.type, instr.result.val, instr.arg1.type, instr.arg1.val, instr.arg2.type, instr.arg2.val);
            break;
        case jle_v:
            printf("%d | if_lesseq | %d %d | %d %d | %d %d\n", index, instr.result.type, instr.result.val, instr.arg1.type, instr.arg1.val, instr.arg2.type, instr.arg2.val);
            break;
        case jge_v:
            printf("%d | if_greatereq | %d %d | %d %d | %d %d\n", index, instr.result.type, instr.result.val, instr.arg1.type, instr.arg1.val, instr.arg2.type, instr.arg2.val);
            break;
        case jlt_v:
            printf("%d | if_less | %d %d | %d %d | %d %d\n", index, instr.result.type, instr.result.val, instr.arg1.type, instr.arg1.val, instr.arg2.type, instr.arg2.val);
            break;
        case jgt_v:
            printf( "%d | if_greater\t| 0%d(%s),\t%u:%s \t", index, instr.result.type, getVmargTypeName(instr.result.type), instr.result.offset, instr.result.name);
            printOperand(instr.arg1);
            printOperand(instr.arg2);
            break;
        case call_v:
            printf("%d | call\t| 0%d(%s),\t%u:%s ", index, instr.arg1.type, getVmargTypeName(instr.arg1.type), instr.arg1.offset, instr.arg1.name);
            printf("\n");
            break;
        case pusharg_v:
            if(instr.arg1.name=="num")
                printf("%d | pusharg\t| 0%d(%s),\t%u:%f ", index, instr.arg1.type, getVmargTypeName(instr.arg1.type), instr.arg1.offset, instr.arg1.dval);
            else if(instr.arg1.name)
                printf("%d | pusharg\t| 0%d(%s),\t%u:%s ", index, instr.arg1.type, getVmargTypeName(instr.arg1.type), instr.arg1.offset, instr.arg1.name);
            printf("\n");
            break;
        case funcenter_v:
            printf("%d | enterfunc\t| 0%d(%s),\t%u:%s ", index, instr.result.type, getVmargTypeName(instr.result.type), instr.result.offset, instr.result.name);
            printf("\n");
            break;
        case funcexit_v:
            printf("%d | exitfunc\t| 0%d(%s),\t%u:%s ", index, instr.result.type, getVmargTypeName(instr.result.type), instr.result.offset, instr.result.name);
            printf("\n");
            break;
        case newtable_v:
            printf("%d | tablecreate\t| 0%d(%s),\t%u:%s ", index, instr.arg1.type, getVmargTypeName(instr.arg1.type), instr.arg1.offset, instr.arg1.name);
            printf("\n");
            break;
        case tablegetelem_v:
            printf("%d | tablegetelement \t| 0%d(%s),\t%u:%s    ", index, instr.result.type, getVmargTypeName(instr.result.type), instr.result.offset, instr.result.name);
            printOperand(instr.arg1);
            printOperand(instr.arg2);
            printf("\n");
            break;
        case tablesetelem_v:
            printf("%d | tablesetelement\t| 0%d(%s),\t%u:%s    ", index, instr.result.type, getVmargTypeName(instr.result.type), instr.result.offset, instr.result.name);
            printOperand(instr.arg1);
            printOperand(instr.arg2);
            printf("\n");
            break;
        case nop_v:
            printf("%d | nop\n", index);
            break;
        case jump_v:
            printf("%d | jump\t| 0%d(%s),\t%u ", index, instr.result.type, getVmargTypeName(instr.result.type), instr.label);
            printf("\n");
            break;
        default:
            break;
    }
}

void printInstructions() {
    int i;
    for (i = 0; i < nextquadlabel(); i++) {
        printInstruction(instructions[i], i);
    }
}
