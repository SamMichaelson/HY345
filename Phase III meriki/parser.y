%{

    
/*
        csd4111
        csd4534

*/

#include "quad_list.h"


#define YY_DECL int alpha_yylex (void* ylval) 
#define MAX_LENGTH 20

int yyerror (char* yaccProvidedMessage);
int yylex(void);

extern int yylineno;

extern char* yytext ;
extern FILE* yyin;


int whiletop=0;

int arrayLocals[100];
int functionlocals=0;
int iaddress=0;
int tempCondition=0;
int c=0;
int top=-1;
int call_=0;
int inloop=0;
int isFunc=0;
int scope=0;
int returned=0;
int eq=0;
int is_func=0;
int annonymous=0;
int inIf=0;
int foonk=0;
int id_Func=0;
int inIff=0;
int tblcount=0;
int onlyBlock=0;
int loopcounter=0;
int whilestack[100]; 
int inelist=0;

SymbolTableEntry * varfunc;
SymbolTableEntry * func;
SymbolTableEntry * func3;
SymbolTableEntry * func1;
SymbolTableEntry * func33;




%}

%start program




/* Token Types Union */
%union{


    char*           stringValue;
    int             intValue;
    double          doubleValue;
    struct expr*    exprVal;
    unsigned uns;

    
    struct  {
            int test;
            int enter;
    }for_s;
    struct  {
            struct expr* elist;
            unsigned char method;
            char* name;
    }call_s;
    struct {
        int breakList;
        int contList;
    } stmt_t;

    }

%token IF
%token ELSE
%token WHILE
%token FOR
%token FUNCTION
%token RETURN
%token BREAK
%token CONTINUE
%token AND
%token NOT
%token OR
%token LOCAL
%token TRUE
%token FALSE
%token NIL

%token BRACEOPEN
%token BRACECLOSE
%token SQBRACKETOPEN
%token SQBRACKETCLOSE
%token L_PARENTHESIS
%token R_PARENTHESIS
%token SEMICOLON
%token COMMA
%token COLON
%token DOUBLECOLON
%token DOT
%token DOUBLEDOT

%token EQUAL
%token ADD
%token SUB
%token MULT
%token DIVA
%token MOD
%token EQUALITY
%token NOTEQUAL
%token ADDITY
%token MULTITY 
%token GREATER
%token LESS
%token GREATEREQUAL
%token LESSEQUAL

%token SIMPLECOMMENT

%token COMMENT



/*Rest of the tokens; */

%token <stringValue>    ID
%token <intValue>       INT
%token <doubleValue>    REAL
%token <stringValue>    STRING
/* %token ID INTEGER */

%right EQUAL
%left OR
%left AND 
%nonassoc EQUALITY NOTEQUAL
%nonassoc GREATER GREATEREQUAL LESS LESSEQUAL
%left ADD  
%left MULT DIVA MOD
%right NOT ADDITY MULTITY 
%left DOT DOUBLEDOT
%left SQBRACKETOPEN SQBRACKETCLOSE
%left L_PARENTHESIS R_PARENTHESIS

%nonassoc UMINUS SUB



%type <stmt_t> stmt
%type <exprVal> assiginexpr    
%type <exprVal> lvalue 
%type <exprVal> expr
%type <exprVal> term
%type <exprVal> idlist
%type <exprVal> const
%type <exprVal> funcdef
%type <exprVal> member
%type <exprVal> primary
%type <exprVal> call
%type <exprVal> elist
%type <exprVal> indexed
%type <exprVal> objectdef
%type <uns> ifprefix
%type <stmt_t> ifstmt

%type <uns> elseprefix
%type <stmt_t> while
%type <uns> whilestart
%type <uns> whilesecond
%type <uns> N
%type <uns> M
%type <for_s> forprefix

%type <stmt_t> for
%type <stmt_t> stmt_list
%type <stmt_t> loopstmt
%type <stmt_t> break
%type <stmt_t> continue
%type <stmt_t> returnstmt
%type <stmt_t> block



%%

program:        stmt_list  {  printf("Program Starts:\n");}
                ;

stmt:           expr SEMICOLON {resettemp(); $$.breakList=0; $$.contList=0; }
                | ifstmt {  }
                | while {  }
                | for  { }
                | returnstmt{ if(isFunc==0 )printf("Error:Use of 'return' while not in a function at line:%d\n",yylineno);  } 
                | break { }
                | continue{  }
                | block{ 
                       if(inloop==1||inIff==1){
                        onlyBlock=0;
                    }else{
                        onlyBlock=0;
                    }
                    
                  }
                | funcdef{
                       $$.breakList=0; 
                       $$.contList=0;
                        }
                | SEMICOLON{ 
                    $$.breakList=0; 
                    $$.contList=0;  
                }
                ;

break:          BREAK SEMICOLON{
              
                    printWhileStack(whilestack,whiletop);
                    $$.breakList=0;
                    $$.contList=0;

               
                 
                    $$.breakList = newlist(nextquadlabel());
                    emit(jump,NULL,NULL,0,nextquadlabel(),yylineno); 

                if(topWhileStack(whilestack,whiletop)>0)
                    printf("Error:Use of 'break' while not in a loop at line:%d\n",yylineno);
                else{
                }
                }
                ;                
continue:       CONTINUE{
                } SEMICOLON{
                $$.breakList=0;
                $$.contList=0;
                $$.contList = newlist(nextquadlabel());
                  
                
                emit(jump,NULL,NULL,0,nextquadlabel(),yylineno); 
                if(topWhileStack(whilestack,whiletop)>0)
                    printf("Error:Use of 'continue' while not in a loop at line:%d\n",yylineno);
                else{
                                     
                }
                }
                ;

stmt_list:       stmt stmt_list{ 
                    
                    $$.breakList = mergelist($2.breakList,$1.breakList);
                    $$.contList = mergelist( $2.contList, $1.contList); 
                    
                }
                |{  $$.breakList=0;
                    $$.contList=0;
                    }
                
            
                
                
                ;

expr:           assiginexpr                 {$$=$1; }
                | expr ADD expr             {if(check_arith_bool($1)||check_arith_bool($3)){
                                            if($1->type==costnum_e && $3->type==costnum_e)
                                                $$=newexpr(costnum_e);
                                            else
                                                $$=newexpr(arithexpr_e); 
                                            $$->sym=newtemp(scope,yylineno); 
                                            emit(add,$1,$3,$$,nextquadlabel() ,yylineno);}}
                | expr SUB expr             {if(check_arith_bool($1)||check_arith_bool($3)){   
                                            if($1->type==costnum_e && $3->type==costnum_e)    
                                                $$=newexpr(costnum_e);
                                            else
                                                $$=newexpr(arithexpr_e); 
                            
                                            $$->sym=newtemp(scope,yylineno); 
                                             emit(sub,$1,$3,$$,nextquadlabel(),yylineno);}}
                | expr MULT expr            {if(check_arith_bool($1)||check_arith_bool($3)){
                                            if($1->type==costnum_e && $3->type==costnum_e)
                                                $$=newexpr(costnum_e);
                                            else 
                                                $$=newexpr(arithexpr_e); 
                                            $$->sym=newtemp(scope,yylineno); 
                                             emit(mul,$1,$3,$$,nextquadlabel(),yylineno);}}
                | expr DIVA expr            {if(check_arith_bool($1)||check_arith_bool($3)){
                                            if($1->type==costnum_e && $3->type==costnum_e)
                                                $$=newexpr(costnum_e);
                                            else
                                                $$=newexpr(arithexpr_e); 
                                            $$->sym=newtemp(scope,yylineno); 
                                             emit(diva,$1,$3,$$,nextquadlabel(),yylineno);}}
                | expr MOD expr             {if(check_arith_bool($1)||check_arith_bool($3)){
                                            if($1->type==costnum_e && $3->type==costnum_e)
                                                $$=newexpr(costnum_e);
                                            else
                                                $$=newexpr(arithexpr_e); 
                                            $$->sym=newtemp(scope,yylineno); 
                                             emit(mod,$1,$3,$$,nextquadlabel(),yylineno);}}
  
                | expr GREATER expr         {$$=newexpr(boolexpr_e); $$->sym=newtemp(scope,yylineno); 
                                            
                                            $$->truelist=makelist(nextquadlabel());
                                            $$->falselist=makelist(nextquadlabel()+1);
                                            emit(if_greater ,$1,$3,0,currQuad+3,yylineno); 
                                            emit(jump       ,NULL,NULL,0,currQuad+3,yylineno);
                                            
                                            /*emit(assign     ,newexpr_constbool(0),NULL,$$,nextquadlabel(),yylineno);
                                            emit(jump       ,NULL,NULL,0,currQuad+2,yylineno);
                                            emit(assign     ,newexpr_constbool(1),NULL,$$,nextquadlabel(),yylineno);
                                            */}
                | expr GREATEREQUAL expr    {$$=newexpr(boolexpr_e); $$->sym=newtemp(scope,yylineno); 
                                            
                                            $$->truelist=makelist(nextquadlabel());
                                            $$->falselist=makelist(nextquadlabel()+1);
                                            emit(if_greatereq,$1,$3,0,currQuad+3,yylineno);
                                            emit(jump       ,NULL,NULL,0,currQuad,yylineno);
                                            
                                            /*emit(assign     ,newexpr_constbool(0),NULL,$$,nextquadlabel(),yylineno);
                                             emit(jump       ,NULL,NULL,0,currQuad+2,yylineno);
                                             emit(assign     ,newexpr_constbool(1),NULL,$$,nextquadlabel(),yylineno);
                                            */}
                | expr LESS expr            {$$=newexpr(boolexpr_e); $$->sym=newtemp(scope,yylineno); 
                                            
                                            $$->truelist=makelist(nextquadlabel());
                                            $$->falselist=makelist(nextquadlabel()+1);
                                            emit(if_less,$1,$3,0,currQuad+3,yylineno);
                                            emit(jump       ,NULL,NULL,0,currQuad+3,yylineno);
                                            
                                            /*emit(assign     ,newexpr_constbool(0),NULL,$$,nextquadlabel(),yylineno);
                                            emit(jump       ,NULL,NULL,0,currQuad+2,yylineno);
                                            emit(assign     ,newexpr_constbool(1),NULL,$$,nextquadlabel(),yylineno);
                                            */}
                | expr LESSEQUAL expr       {$$=newexpr(boolexpr_e); $$->sym=newtemp(scope,yylineno); 
                                            
                                            $$->truelist=makelist(nextquadlabel());
                                            $$->falselist=makelist(nextquadlabel()+1);
                                            emit(if_lesseq,$1,$3,0,currQuad+3,yylineno);
                                            emit(jump       ,NULL,NULL,0,currQuad+3,yylineno);
                                            
                                            /*emit(assign     ,newexpr_constbool(0),NULL,$$,nextquadlabel(),yylineno);
                                            emit(jump       ,NULL,NULL,0,currQuad+2,yylineno);
                                            emit(assign     ,newexpr_constbool(1),NULL,$$,nextquadlabel(),yylineno);
                                            */}
                | expr EQUALITY expr        {$$=newexpr(boolexpr_e); $$->sym=newtemp(scope,yylineno); 
                                            
                                            $$->truelist=makelist(nextquadlabel());
                                            $$->falselist=makelist(nextquadlabel()+1);
                                            emit(if_eq ,$1,$3,0,currQuad+3,yylineno); 
                                            emit(jump       ,NULL,NULL,0,currQuad+3,yylineno);
                                            
                                            /*emit(assign     ,newexpr_constbool(0),NULL,$$,nextquadlabel(),yylineno);
                                            emit(jump       ,NULL,NULL,0,currQuad+2,yylineno);
                                            emit(assign     ,newexpr_constbool(1),NULL,$$,nextquadlabel(),yylineno);
                                            */}
                | expr NOTEQUAL expr        {$$=newexpr(boolexpr_e); $$->sym=newtemp(scope,yylineno); 
                                            
                                            $$->truelist=makelist(nextquadlabel());
                                            $$->falselist=makelist(nextquadlabel()+1);
                                            emit(if_noteq,$1,$3,0,currQuad+3,yylineno);
                                            emit(jump       ,NULL,NULL,0,currQuad,yylineno);
                                            
                                            /*emit(assign     ,newexpr_constbool(0),NULL,$$,nextquadlabel(),yylineno);
                                            emit(jump       ,NULL,NULL,0,currQuad+2,yylineno);
                                            emit(assign     ,newexpr_constbool(1),NULL,$$,nextquadlabel(),yylineno);
                                            */}
                | expr AND M expr             {$$=newexpr(boolexpr_e); $$->sym=newtemp(scope,yylineno); 
                                             backpatch($1->falselist,$3);
                                            $$->truelist=$4->truelist;
                                            $$->falselist=merge($1->falselist,$4->falselist);
                                            emit(and,$1,$4,$$,nextquadlabel(),yylineno);
                                            }
                | expr OR M expr              {$$=newexpr(boolexpr_e); $$->sym=newtemp(scope,yylineno); 
                                            backpatch($1->falselist,$3);
                                            $$->truelist=merge($1->truelist,$4->truelist);
                                            $$->falselist=$4->truelist;
                                            emit(or,$1,$4,$$,nextquadlabel(),yylineno);
                                            }
                | term{$$=$1;  }
                ;


term:           L_PARENTHESIS expr R_PARENTHESIS{ $$=$2;}
                | SUB expr/*  %prec UMINUS */
                         {
                                    check_arith($expr);
                                    $$=newexpr(arithexpr_e); 
                                    $term->sym = istempexpr($expr) ? $expr->sym : newtemp(scope,yylineno);
                                    
                                    emit(uminus,$expr, NULL, $term,nextquadlabel(),yylineno);
                                    }
                                    
                | NOT expr          {
                                    check_arith($expr);
                                    $$=newexpr(arithexpr_e); 
                                    $$->sym=newtemp(scope,yylineno);
                                    emit(not,$2,NULL,$$,nextquadlabel(),yylineno);
                                
                                    }

                | ADDITY lvalue     {
                                    if(id_Func)printf("Error using func as an lvalue |line:%d\n",yylineno);is_func=0;
                                    
                                    check_arith($lvalue);
                                    if ($lvalue->type == tableitem_e) {

                                    $term = emit_iftableitem($lvalue,scope,yylineno);
                                    emit(add, $term, newexpr_constnum(1), $term,nextquadlabel(),yylineno);
                                    emit(tablesetelem, $term, $lvalue->index, $lvalue,nextquadlabel(),yylineno);


                                    }
                                    else {

                                    emit(add, $lvalue, newexpr_constnum(1), $lvalue,nextquadlabel(),yylineno);
                                    $$=newexpr(arithexpr_e); 
                                    $$->sym=newtemp(scope,yylineno);
                                    
                                    emit(assign, $lvalue, NULL, $term,nextquadlabel(),yylineno);
                                     
                                    }
                                    

                                    }
                | lvalue ADDITY     {
                                    if(id_Func)printf("Error using func as an lvalue |line:%d\n",yylineno);is_func=0;
                                   
                                    check_arith($lvalue);
                                    $$=newexpr(var_e);  
                                    $$->sym=newtemp(scope,yylineno); 
                                    
                                    if ($lvalue->type == tableitem_e) {
                                    expr* val = emit_iftableitem($lvalue,scope,yylineno);
                                    emit(assign, val, NULL, $term,nextquadlabel(),yylineno);
                                    emit(add, val, newexpr_constnum(1), val,nextquadlabel(),yylineno);
                                    emit(tablesetelem, val, $lvalue->index, $lvalue,nextquadlabel(),yylineno);
                                    }
                                    else {
                                    emit(assign, $lvalue, NULL, $term,nextquadlabel(),yylineno);
                                    emit(add, $lvalue, newexpr_constnum(1), $lvalue,nextquadlabel(),yylineno);
                                    }
                                   
                                    
                                    }
                                    
                | MULTITY lvalue    {
                                    if(id_Func)printf("Error using func as an lvalue |line:%d\n",yylineno);is_func=0;
                                   
                                    check_arith($lvalue);
                                     if ($lvalue->type == tableitem_e) {

                                    $term = emit_iftableitem($lvalue,scope,yylineno);
                                    emit(sub, $term, newexpr_constnum(1), $term,nextquadlabel(),yylineno);
                                    emit(tablesetelem, $term, $lvalue->index, $lvalue,nextquadlabel(),yylineno);


                                    }
                                    else {

                                    emit(sub, $lvalue, newexpr_constnum(1), $lvalue,nextquadlabel(),yylineno);
                                    $$=newexpr(arithexpr_e); 
                                    $$->sym=newtemp(scope,yylineno);
                                    
                                    emit(assign, $lvalue, NULL, $term,nextquadlabel(),yylineno);
                                    
                                    }
                                    
                                   
                                    }
                                    
                | lvalue MULTITY    {
                                    if(id_Func)printf("Error using func as an lvalue |line:%d\n",yylineno);is_func=0;
                                    
                                    check_arith($lvalue);
                                    $$=newexpr(arithexpr_e); 
                                    $$->sym=newtemp(scope,yylineno); 

                                     if ($lvalue->type == tableitem_e) {
                                    expr* val = emit_iftableitem($lvalue,scope,yylineno);
                                    emit(assign, val, NULL, $term,nextquadlabel(),yylineno);
                                    emit(sub, val, newexpr_constnum(1), val,nextquadlabel(),yylineno);
                                      emit(tablesetelem, val, $lvalue->index, $lvalue,nextquadlabel(),yylineno);
                                    }
                                    else {
                                    emit(assign, $lvalue, NULL, $term,nextquadlabel(),yylineno);
                                    emit(sub, $lvalue, newexpr_constnum(1), $lvalue,nextquadlabel(),yylineno);
                                    }
                                   
                                    
                                    }
                | primary{ $$=$1; }
                ;

assiginexpr:     lvalue{		if(id_Func==1){
                                   printf("Error using func as an lvalue |line:%d\n",yylineno);
                                    id_Func=0;
                                   }
						
                     
				} EQUAL{eq==1;} expr  {
                  
                    if ($lvalue->type == tableitem_e ) {
                     
                            emit(tablesetelem,$lvalue->index,$expr,$lvalue,nextquadlabel(),yylineno);
                            $$ = emit_iftableitem($lvalue,scope,yylineno);
                            $$->type = assignexpr_e;
                    }else {
                            emit(assign,NULL,$expr,$1,nextquadlabel(),yylineno);
                            $$ = newexpr(assignexpr_e);
                            $$->sym = newtemp(scope,yylineno);
                            emit(assign, NULL, $1, $$,nextquadlabel(),yylineno);
                    }
                }


primary:        lvalue { $primary = emit_iftableitem($lvalue,scope,yylineno); }
                | call { $$=$1;}
                | objectdef{$$=$1;  }
                | L_PARENTHESIS funcdef R_PARENTHESIS {
                    $primary = newexpr(programfunc_e);
                    $primary->sym = $funcdef->sym;
                }
                | const{$$=$1; }
    
                ;


lvalue:         ID{   
                          if(searchScope($1,scope)!=NULL){
                              $$=lvalue_expr(searchScope($1,scope));
                          }
                    
                              
                        if(searchScope($1,scope)!=NULL){/*exists in current scope*/
                            if(searchScope($1,scope)->type==LIBFUNC ||searchScope($1,scope)->type==USERFUNC){
                                id_Func=1;
                            }  
                        }
                        if(searchScope($1,0)!=NULL){
                            if(searchScope($1,0)->type==LIBFUNC ){
                                
                               $$ = newexpr(libraryfunc_e);
                               $$->strConst=$1;
                            }  
                        }
                         if(searchScope($1,0)!=NULL){
                            if(searchScope($1,0)->type==USERFUNC ){
                                
                               $$ = newexpr(programfunc_e);
                               $$->strConst=$1;
                            }  
                        }
                        if(searchScope($1,0)!=NULL){
                             
                             
                                $$ = newexpr(var_e);
                                $$->strConst=$1;
                              
                        }

                        func=searchScope($1,0);
                        if(scope==0 && searchScope($1,scope)==NULL){/*isglobal*/

                            insertElemVariable(GLOBAL,$1,scope,yylineno, currscopespace(),currscopeoffset()+arrayLocals[isFunc]);
                            $$=lvalue_expr(searchScope($1,scope));
                            
                            inccurrscopeoffset();
                        }else if(scope!=0  && searchScope($1,0)==NULL ){/*not global, doesnt exist in scope 0*/
                            int check=0;

                            for(int k=1; k<=scope; k++){
                              

                                if((searchScope($1,k)!=NULL && (isFunc && inloop==0))||(searchScope($1,k)!=NULL && (isFunc==0 && inloop==1))){/*if it finds it*/
                                    check=1;

                                    if(isFunc>1 && returned==0 && searchScope($1,k)->type!=LIBFUNC && searchScope($1,k)->type!=USERFUNC && searchScope($1,k)->type!=FORMAL)
                                        printf("1 Error Cannot access %s inside function |line %d\n",$1,yylineno);
                                    func=searchScope($1,k);
                                    
                                    if((func->type==GLOBAL|| func->type == LOCALL || func->type == FORMAL) ){
                                        if(returned==0 && inloop==0 && inIf==0 && foonk==0){
                                           

                                            if(searchScope($1,k)->type !=LOCALL && searchScope($1,k)->type !=FORMAL  ){
                                            
                                               printf("Error:already exist at scope: %d |line: %d\n",k,yylineno); }
                                                    
                                        } 
                                        
                                    }
                                        
                                }else if(searchScope($1,k)!=NULL ){/*not a func*/
                                    check=1;
                                    printf("Is refering at previus %s at line: %d\n",$1,yylineno);
                                   ;
                                }else if(searchScope($1,k)==NULL){
                                            for(int l=k; l>=1; l--){
                                                if(searchScope($1,l)!=NULL &&searchScope($1,l)->type==FORMAL){
                                                  
                                                     printf("Error:already exist at scope: %d |line: %d\n",l,yylineno); 
                                                }
                                            }   
                                        }
                            }
                            if(check==0 ){
                              
                                        if(searchScope($1,scope)!=NULL){

                                        } /*printf("token:%s at scope:%d at line:%d \n",$1,scope,yylineno);*/
                                        
                                        insertElemVariable(LOCALL,$1,scope,yylineno,currscopespace(),currscopeoffset()+arrayLocals[isFunc] );
                                        $$=lvalue_expr(searchScope($1,scope));
                                        inccurrscopeoffset();
                                    check=0;
                            }
                            
                        }else if(scope!=0  && searchScope($1,0)!=NULL ){/*not global ,exists scope 0*/
                            if(isFunc>1 && returned==0 && searchScope($1,0)->type!=LIBFUNC )
                              /*  printf("2 Error Cannot access %s inside function |line %d\n",$1,yylineno); */

                            for(int k=1; k<=scope; k++){
                              if(searchScope($1,k)!=NULL)  {
                                if(isFunc>1 && returned==1 && searchScope($1,k)->type!=LIBFUNC &&searchScope($1,k)->type!=USERFUNC)
                                    printf("3 Error Cannot access %s inside function |line %d\n",$1,yylineno); 
                                }
                            }
                            
                            if(func->type==GLOBAL|| func->type == LOCALL || func->type == FORMAL  ){
                               
                            }else if(returned == 0 && !func->type == LIBFUNC){
                                is_func=1;
                                
                                printf("Error: cannot access %s inside Function at scope:%d in line:%d\n",$1,scope,yylineno);
                            }/*else if(returned==1){
                                is_func=1;printf("2      \n");
                                }*/
                        }else  if((scope==0  && searchScope($1,0)!=NULL)&&(func->type==USERFUNC ||func->type==LIBFUNC) ){
                                $$=lvalue_expr(searchScope($1,scope));
                               is_func=1;
                              
                        }else{
                            $$=lvalue_expr(searchScope($1,scope));
                            
                          
                        }
                        
                }
                | LOCAL ID {
                   
                    if(searchScope($2,scope)==NULL ){
                        if( (varfunc=searchScope($2,0) )!=NULL){/*exists in scope 0*/
                            if(varfunc->type==LIBFUNC){
                                    printf("Error:Trying to shadow libfunc in line:%d\n",yylineno);
                                     $$=lvalue_expr(searchScope($2,scope));
                            }
                           else {
                            insertElemVariable(LOCALL,$2,scope,yylineno, currscopespace(),currscopeoffset()+arrayLocals[isFunc]);
                            $$=lvalue_expr(searchScope($2,scope));
                            inccurrscopeoffset();
                            }
                    
                    } else if(scope==0){
                                    
                            insertElemVariable(GLOBAL,$2,scope,yylineno, currscopespace(),currscopeoffset()+arrayLocals[isFunc]);
                            $$=lvalue_expr(searchScope($2,scope));
                            inccurrscopeoffset();
                        }else{
                            insertElemVariable(LOCALL,$2,scope,yylineno, currscopespace(),currscopeoffset()+arrayLocals[isFunc]);
                            $$=lvalue_expr(searchScope($2,scope));
                            inccurrscopeoffset();
                        }
                    }else { 
                            $$=lvalue_expr(searchScope($2,scope));
                            
                    }   
                }

                
                | DOUBLECOLON ID{
                if(searchScope($2,0)!=NULL){
                            if(searchScope($2,0)->type==LIBFUNC ){
                               
                               $$ = newexpr(libraryfunc_e);
                               $$->strConst=$2;
                            }  
                        }
                if(searchScope($2,scope)!=NULL){
                    $$=lvalue_expr(searchScope($2,scope));
                }
                    if(searchScope($2,0)!=NULL){
                        printf("Found Globaly at line:%d\n",yylineno);
                    }else{
                        printf("Error, undefined global variable %s in line:%d\n",$2,yylineno);
                    }
                }
                | member{$$=$1;}
                ;

member:         lvalue DOT ID{$$ = member_item($lvalue,$ID,scope,yylineno);}
                | lvalue SQBRACKETOPEN expr SQBRACKETCLOSE{ 
                    $lvalue = emit_iftableitem($lvalue,scope,yylineno);
                    $$ = newexpr(tableitem_e);
                    $$->sym = $lvalue->sym;
                    $$->index = $expr;
                }
                | call DOT ID{ $$->strConst=$ID;}
                | call SQBRACKETOPEN expr SQBRACKETCLOSE { $$=$3;}
                ;

call:           call L_PARENTHESIS{  id_Func=0;}   elist R_PARENTHESIS 
                    { 
                    if($elist)
                        rearrangeAndReverse(&$elist);
                    $$ = make_call($1, $elist,scope,yylineno); 
                   }                        
                | lvalue callsuffix{ 
                   
                    id_Func=0;
                    $lvalue = emit_iftableitem($lvalue,scope,yylineno); 
                    if ($<call_s>callsuffix.method ){ 
                        
                        expr* t = $lvalue; 
                      
                        $lvalue = emit_iftableitem(member_item(t, $<call_s>callsuffix.name,scope,yylineno),scope,yylineno);
                        if($<call_s>callsuffix.elist)
                            rearrangeAndReverse(&$<call_s>callsuffix.elist);
                        expr* oof=$<call_s>callsuffix.elist;
                        if(oof){ 
                            while( oof->next!=NULL){
                                oof=oof->next;
                            }
                            

                            oof->next= t;  
                        }
                       
                    }
                    if($<call_s>callsuffix.elist){
                        rearrangeAndReverse(&$<call_s>callsuffix.elist);
                    }
                    
                    $call = make_call($lvalue, $<call_s>callsuffix.elist,scope,yylineno);

                }     
                | L_PARENTHESIS  funcdef R_PARENTHESIS L_PARENTHESIS{  id_Func=0;}   elist R_PARENTHESIS 
                 {
                    expr* func = newexpr(programfunc_e);
                    func->sym = $funcdef->sym;
                     rearrangeAndReverse(&$elist);
                    $$ = make_call(func, $elist,scope,yylineno);
                }
                ;

callsuffix:     normcall{
                
                $<call_s>$=$<call_s>1;
              
                }
                | methodcall{
            
                $<call_s>$=$<call_s>1;}
                ;

normcall:       L_PARENTHESIS{foonk==1;} elist R_PARENTHESIS{foonk=0;

                
                $<call_s>$.elist= $elist;
                $<call_s>$.method = 0;
                $<call_s>$.name = NULL;

              
              
                }
                ;

methodcall:     DOUBLEDOT ID L_PARENTHESIS elist R_PARENTHESIS
                {
                $<call_s>$.elist= $elist; 
                $<call_s>$.method = 1;
                $<call_s>$.name = $ID;
                }

                ;

elist:		expr { $$=$1;}
			|expr COMMA elist{ 
                    $$->next=$3;
            }
            |{ $$=NULL;}
			;


objectdef:      SQBRACKETOPEN elist  SQBRACKETCLOSE
                {   
                        expr* t = newexpr(newtable_e);
                        t->sym = newtemp(scope,yylineno);
                        
                        emit(tablecreate, t, NULL, NULL,nextquadlabel(),yylineno);
                        if($elist!=NULL){
                                  for(int i = 0; $elist; $elist = $elist->next)
                                      emit(tablesetelem, $elist, newexpr_constnum(i++), t,nextquadlabel(),yylineno);
                        }                         
                         $$= t;
                }
                | SQBRACKETOPEN indexed SQBRACKETCLOSE {
                    expr* t = newexpr(newtable_e);
                    t->sym = newtemp(scope,yylineno);
                    
                    emit(tablecreate, t, NULL, NULL,nextquadlabel(),yylineno);

                    if($2->next!=NULL){
                      
                    }
                  
             
                   while($2){
                        emit(tablesetelem,$2, $2->index,t,nextquadlabel(),yylineno);
                        
                        $2= $2->next;          
                    }
                    
                          
                    $$ = t;
                }
                
                ;

indexed:        BRACEOPEN expr COLON expr BRACECLOSE COMMA indexed{  $$=$2;  $$->index=$4;  $$->next=$7; }
                | BRACEOPEN expr COLON expr BRACECLOSE{ $$=$2; $$->index=$4;  }
                ;




block:          BRACEOPEN{scope++;
                    
                
                    if(inloop==0 && inIff==0 && onlyBlock==0){
                    
                        if(isFunc>=1){
                        if(arrayLocals[isFunc-1]){
                                arrayLocals[isFunc-1]+=currscopeoffset();
                        }
                            else{
                                arrayLocals[isFunc-1]=currscopeoffset();          
                            }
                            
                                resetfunctionlocalsoffset(); 
                        }
                    }

                } stmt_list BRACECLOSE{
                    if(isFunc>=1 && inloop==0 && inIff==0 && onlyBlock==0){
                        isFunc--;
                        int scopeFunc=scope-1;
                        if(top_name(top)!=NULL){
                            arrayLocals[isFunc+1]+=currscopeoffset();
                            restorecurrscopeoffset(arrayLocals[isFunc+1]); 
                            func=searchScope(top_name(top),scopeFunc);
                            if(func!=NULL &&inloop==0){
                               
                                functionlocals=currscopeoffset(); 
                                func->value.funcVal->functionlocals=currscopeoffset();                           
                                exitscopespace();exitscopespace();
                            }
                            arrayLocals[isFunc+1]=0;
                            resetfunctionlocalsoffset(); 
                        }
                    }
                    hide(scope);
                
                    scope--;
                     
                    $$.contList=$stmt_list.contList;
                    $$.breakList=$stmt_list.breakList;
                    
                    } 
                ;

funcdef:        FUNCTION ID { 
                    topFunc(whilestack,whiletop);

                    iaddress= nextquadlabel(); 


                    if (searchScope($2,scope)==NULL){
                            if( (varfunc=searchScope($2,0) )!=NULL){/*exists in scope 0*/
                                if(varfunc->type==LIBFUNC){
                                        printf("Error:Trying to shadow libfunc in line:%d\n",yylineno);
                                }else if(varfunc!=NULL){
                                }else{
                                    printf("Error: %s exists in line:%d\n",$2,yylineno);
                                }
                            }

                            
                            push($2,top);
                            top++;

                            insertElemFunction(USERFUNC,top_name(top),scope,yylineno,functionlocals,iaddress); 

                            if(searchScope(top_name(top),scope)!=NULL){
                            $<exprVal>$=lvalue_expr(searchScope(top_name(top),scope));
                            $<exprVal>$->sym->value.funcVal->iaddress = nextquadlabel(); 
                            emit(funcstart, NULL, NULL, $<exprVal>$,nextquadlabel(),yylineno);
                            }
                          
                            print_stack(top);

                           
                    }else{
                        func=searchScope($2,scope);
                        if(func->type==GLOBAL|| func->type == LOCALL || func->type == FORMAL){
                            printf("Error: %s is a var in line:%d\n",$2,yylineno);
                        }else if(func->type==LIBFUNC){
                                        printf("Error:Trying to shadow libfunc in line:%d\n",yylineno);
                        }else{
                            printf("Error:already exist in the function /%s/ in line%d\n",$2,yylineno);
                        }
                    }
                           
                } L_PARENTHESIS{isFunc++; enterscopespace();} idlist R_PARENTHESIS{restorecurrscopeoffset(currscopespace()); resetformalargsoffet();enterscopespace();
                 
                } 
                block {
                { 
                  
                    
                  }
                     $<exprVal>$=lvalue_expr(searchScope(top_name(top),scope));
                    emit(funcend, NULL, NULL, $<exprVal>$,nextquadlabel(),yylineno);
                
                    pop(top);
                    top--;
                    topCloseFunc(whilestack,whiletop);

                }
                |FUNCTION{ 
                    topFunc(whilestack,whiletop);
                   
                    iaddress= nextquadlabel(); 
                    
                    annonymous++;
                    
                    char* countStr = (char*)malloc(sizeof(annonymous) * 2); 
                    sprintf(countStr, "$%d", annonymous);

                    
                    push(countStr,top);
                    top++;
                    
                    insertElemFunction(USERFUNC,top_name(top),scope,yylineno,functionlocals,iaddress);
                    if(searchScope(top_name(top),scope)!=NULL){    
                        $<exprVal>$=lvalue_expr(searchScope(top_name(top),scope));
                        $<exprVal>$->sym->value.funcVal->iaddress = nextquadlabel(); 
                        emit(funcstart, NULL, NULL, $<exprVal>$,nextquadlabel(),yylineno);
                    }
                                 
                     print_stack(top);
                  
                } L_PARENTHESIS {isFunc++; enterscopespace();} idlist R_PARENTHESIS{  
                    restorecurrscopeoffset(currscopespace());
                    resetformalargsoffet(); 
                    enterscopespace();
                 
                    } 
                block{ 
                {
                  
                    
                  }
                     $<exprVal>$=lvalue_expr(searchScope(top_name(top),scope));
                    emit(funcend, NULL,NULL, $<exprVal>$, nextquadlabel(), yylineno);
                    
                    pop(top);
                    top--;
                    topCloseFunc(whilestack,whiletop);
                }
                |FUNCTION SQBRACKETOPEN ID SQBRACKETCLOSE L_PARENTHESIS idlist R_PARENTHESIS funcblockstart block funcblockend
                ;

const:          INT {
                    $$=newexpr(costnum_e);
                    $$->numConst=$1;
                }
                | REAL{
                    $$=newexpr(costnum_e);
                    $$->numConst=$1;
                }
                | STRING{
                   
                    $$=newexpr(conststring_e);
                    $$->strConst=$1;
               
                } 
                | NIL {
                    $$=newexpr(nil_e);
                    $$->numConst=0;
                }
                | TRUE {
                    $$=newexpr(constbool_e);
                    $$->boolConst=1;
                }
                | FALSE{
                    $$=newexpr(constbool_e);
                    $$->boolConst=0;
                }
                ;

idlist:         ID{ scope++;  
                    func=searchScope($1,scope);
                    
                    if(searchScope($1,scope)!=NULL ){
                  
                        if(func->type==FORMAL){ 
                         
                          insertElemVariable(FORMAL,$1,scope,yylineno,currscopespace(),currscopeoffset()+arrayLocals[isFunc]);
                          $$=lvalue_expr(searchScope($1,scope));
                          inccurrscopeoffset();
                        }

                    }else{
                        if(searchScope($1,0)){
                            if(searchScope($1,0)->type==LIBFUNC){
                                    printf("Error: Collision with %s library function,at scope:%d at line: %d\n",$1,scope,yylineno);
                            }else{
                                    insertElemVariable(FORMAL,$1,scope,yylineno,currscopespace(),currscopeoffset()+arrayLocals[isFunc]);
                                    $$=lvalue_expr(searchScope($1,scope));
                                    inccurrscopeoffset();
                            }
                        }else if(searchScope($1,scope)!=NULL){
                            printf("Error: Variable %s already defined at scope:%d at line %d.\n",$1,scope,yylineno);

                        }else{
                            insertElemVariable(FORMAL,$1,scope,yylineno, currscopespace(),currscopeoffset()+arrayLocals[isFunc]);
                            $$=lvalue_expr(searchScope($1,scope));
                            inccurrscopeoffset();
                        }

                        
                    }  
                            
                    
                    scope--;  
                }
              
                |idlist COMMA ID{scope++;   

                        if(searchScope($3,0)!=NULL){
                            if(searchScope($3,0)->type==LIBFUNC){
                                    printf("Error: Collision with %s library function,at scope:%d at line: %d\n",$3,scope,yylineno);
                            }else if(searchScope($3,scope)!=NULL){
                            printf("Error: Variable %s already defined at scope:%d at line %d.\n",$3,scope,yylineno);

                           }  else{
                            
                                   insertElemVariable(FORMAL,$3,scope,yylineno, currscopespace(),currscopeoffset()+arrayLocals[isFunc]);
                                   $$=lvalue_expr(searchScope($3,scope));
                                   inccurrscopeoffset();
                            }

                        }else if(searchScope($3,scope)!=NULL){
                            printf("Error: Variable %s already defined at scope:%d at line %d.\n",$3,scope,yylineno);

                        }else{

                           insertElemVariable(FORMAL,$3,scope,yylineno,currscopespace(),currscopeoffset()+arrayLocals[isFunc]);
                           $$=lvalue_expr(searchScope($3,scope));
                           inccurrscopeoffset();
                        }
                        
                     scope--;
                }

                |{  $$=NULL;}
                ;


ifprefix:       IF {inIff=1;}L_PARENTHESIS expr R_PARENTHESIS {
                    emit(if_eq,$expr,newexpr_constbool(1),0,nextquadlabel()+2,yylineno);
                    $$=nextquadlabel();
                    emit(jump,NULL,NULL,0,currQuad,yylineno);
                }
                ;
                
elseprefix:        ELSE {
                $$=nextquadlabel();
                emit(jump,NULL,NULL,0,currQuad,yylineno);
                }
                ;
                

ifstmt:         ifprefix stmt{
                    inIff=0;
                    patchlabel($1,nextquadlabel());
                    $$.breakList=$2.breakList;    
                    $$.contList=$2.contList;                  
                }
                |ifprefix  stmt elseprefix stmt{
                    inIff=0;
                    patchlabel($1,$3+1);
                    patchlabel($3,nextquadlabel());
                  if($2.breakList!=0   ){
                       $$.breakList=$2.breakList; 
                  }else if($4.breakList!=0){
                      $$.breakList=$4.breakList; 
                  }else
                    $$.breakList=0;

                  if($2.contList!=0 ){
                       $$.contList=$2.contList; 
                  }else if($4.contList!=0){
                      $$.contList=$4.contList; 
                  }else
                    $$.contList=0;
                }
                ;


whilestart:    WHILE{
                    whiletop=pushWhileStack(whilestack,whiletop); 
                    inloop=1;
                     $$=nextquadlabel();
                }
                ;

whilesecond:   L_PARENTHESIS expr R_PARENTHESIS{
                    emit(if_eq,$2,newexpr_constbool(1),0,currQuad+2,yylineno);
                    $$=nextquadlabel();
                    emit(jump,NULL,NULL,0,nextquadlabel(),yylineno);
                    
                }
                ;
while:     whilestart whilesecond loopstmt{
                    inloop=0;
                
                     emit(jump,NULL,NULL,0,$1,yylineno);

                    patchlabel($2, nextquadlabel());
                    patchlist($loopstmt.breakList, nextquadlabel());
                    patchlist($loopstmt.contList, $1);
                    whiletop=popWhileStack(whilestack,whiletop);
                    $$.breakList=0; $$.contList=0;
                }
                ;
N:              {  $N = nextquadlabel(); emit(jump,NULL,NULL,0,nextquadlabel(),yylineno); }
                ;
M:              { $M = nextquadlabel(); }
                ;
forprefix:      FOR{inloop=1;
                    whiletop=pushWhileStack(whilestack,whiletop); 
                    }
                    L_PARENTHESIS elist SEMICOLON M expr SEMICOLON {
                    $forprefix.test = $M;
                    $forprefix.enter = nextquadlabel();
                    emit(if_eq, $expr, newexpr_constbool(1), 0,nextquadlabel(),yylineno);
                    whiletop=popWhileStack(whilestack,whiletop); 
                    
                }
                ;

for:        forprefix N elist R_PARENTHESIS N loopstmt N {
                    inloop=0;
                     
                    
                    
                    patchlabel($forprefix.enter, $5+1); 
                    patchlabel($2, nextquadlabel()); 
                    patchlabel($5, $forprefix.test); 
                    patchlabel($7, $2+1); 
                 
                    
                    patchlist($6.breakList, nextquadlabel());
                    patchlist($6.contList, $2+1);
                        
                    $$.breakList=0; $$.contList=0;
                       
            }
            ;

loopstart:      {++loopcounter;}
                ;

loopend:        {--loopcounter;}
                ;

loopstmt:       loopstart  stmt loopend { $$=$2; }
                ;

whilestmt:      while L_PARENTHESIS expr R_PARENTHESIS loopstmt
                ;


funcblockstart: { topFunc(whilestack,whiletop);  loopcounter=0; }
                ;

funcblockend:   { topFunc(whilestack,whiletop);   }
                ;


returnstmt:     RETURN{returned=1;} SEMICOLON{returned=0;                     
                    emit(ret,NULL,0,0,nextquadlabel(),yylineno);
                    $$.breakList=0; $$.contList=0; 
                }
                |RETURN{returned=1; } expr {returned=0;} SEMICOLON  {
               
                    emit(ret,0,0,$expr,nextquadlabel(),yylineno);
                    $$.breakList=0; $$.contList=0; 
                }
                ;
               


%%


int yyerror(char* yaccProvidedMessage)
{
    fprintf(stderr, "%s: at line %d, before token: %s \n",yaccProvidedMessage, yylineno, yytext);
    fprintf(stderr,"INPUT NOT VALID \n");
}


int main(int argc , char** argv)
{
     

    insertLibFuncts();
    if(argc > 1){
        if(!(yyin = fopen (argv[1],"r"))){
            fprintf(stderr, "Cannot read file: %s \n", argv[1]);
            return 1;
        }
    }
    else {
        yyin = stdin;
    }
    yyparse();
    printHashTable();
    for(int i=0; i<=10; i++){
        searchScopeList(i);
    }
    
    printQuads();

    return 0;
}