%{
    /*
        csd4111
        csd4534
        csd4249
    */
    

    /*
    #undef YY_DECL
    #define YY_DECL int alpha_yylex(void* yylval)

    */

  
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "parser.h"
   
    
    enum {KEYWORD, ITERATOR, INTCONST, IDENT} type_of_token;
    int number_of_tokens=0;
    typedef struct alpha_token_t
    {
        int lineNumber;
        int tokenNumber;
        char* type;
        char* types_var;
        char* alpha_yytext;
        char* name;
        int open_lineNumber;
        int close_lineNumber;
        struct alpha_token_t *next;
    }alpha_token_t;

    alpha_token_t *head = NULL;
    alpha_token_t *tail = NULL;

    void insert_token(int lineNumber, int tokenNumber, char* type,char* a_yytext, int token_length, char* types_var,char* name, int open_lineNumber, int close_lineNumber)
    {
        alpha_token_t *tmp;
        char* token_type;
        char* alpha_yytext;
        char* t_v;
        char* name_of_yytext;
        name_of_yytext = (char*)malloc((strlen(name))*sizeof(char));
        strcpy(name_of_yytext,name);
        t_v = (char*)malloc((strlen(types_var))*sizeof(char));
        strcpy(t_v,types_var);
        alpha_yytext = (char*)malloc((token_length+1)*sizeof(char));
        strcpy(alpha_yytext,a_yytext);
        token_type = (void *)malloc(sizeof(type_of_token));
        tmp = (alpha_token_t *)malloc(sizeof(alpha_token_t));
        tmp->name = name_of_yytext;
        tmp->types_var = t_v;
        tmp-> alpha_yytext = alpha_yytext;
        tmp->lineNumber=lineNumber;
        tmp->tokenNumber=tokenNumber;
        tmp->open_lineNumber = open_lineNumber;
        tmp->close_lineNumber = close_lineNumber;
        token_type=type;
        tmp->type = type;
        tmp->next=NULL;

        if(head==NULL)
        {
            head=tmp;
            tail=head;
            return;
        }
        tail->next=tmp;
        tail=tmp;
        return;
    }

    void print_tokens()
    {
        alpha_token_t *tmp;
        tmp=head;
        printf("\n");
        while(tmp!=NULL)
        {
            if(tmp->lineNumber == tmp->close_lineNumber)
            {
                printf("%d:\t#%d\t\"%s\"\t%s\t%s\t\t<--%s\n",tmp->lineNumber,tmp->tokenNumber,tmp->alpha_yytext,tmp->type,tmp->name,tmp->types_var);     

            }else{
                printf("%d:\t#%d\t\"%d-%d\"\t%s\t%s\t\t<--%s\n",tmp->lineNumber, tmp->tokenNumber,tmp->open_lineNumber, tmp->close_lineNumber,tmp->type,tmp->name,tmp->types_var);
            }
            tmp=tmp->next;
        }
        printf("\n");
    }
    
%}
%option yylineno
%option noyywrap


IF     if
ELSE   else
WHILE  while
FOR    for
FUNCTION function
RETURN return
BREAK  break
CONTINUE continue
AND    and
NOT    not
OR     or
LOCAL  local
TRUE   true
FALSE  false
NIL    nil

INT      [0-9]+ 
ID     [a-zA-Z][a-zA-Z_0-9]* 
REAL    [0-9]*\.[0-9](e|E)?[0-9]*

BRACEOPEN   "{"
BRACECLOSE  "}"
SQBRACKETOPEN  "["
SQBRACKETCLOSE "]"
L_PARENTHESIS "("
R_PARENTHESIS ")"
SEMICOLON ";"
COMMA ","
COLON ":"
DOUBLECOLON "::"
DOT "."
DOUBLEDOT ".."

EQUAL "=" 
ADD "+" 
SUB "-" 
UMINUS "-" 
MULT "*" 
DIVA "/" 
MOD "%" 
EQUALITY "==" 
NOTEQUAL "!="
ADDITY  "++"
MULTITY "--"
GREATER ">"
LESS "<"
GREATEREQUAL ">="
LESSEQUAL "<="

SIMPLECOMMENT "//"
STRING "\""
COMMENT "/*"




%%
{IF}  {insert_token(yylineno,++number_of_tokens,"KEYWORD",yytext,strlen(yytext),"enumerated","IF",0,yylineno); return IF;}
{ELSE}  {insert_token(yylineno,++number_of_tokens,"KEYWORD",yytext,strlen(yytext),"enumerated","ELSE",0,yylineno); return ELSE;}
{WHILE}  {insert_token(yylineno,++number_of_tokens,"KEYWORD",yytext,strlen(yytext),"enumerated","WHILE",0,yylineno); return WHILE;}
{FOR}  {insert_token(yylineno,++number_of_tokens,"KEYWORD",yytext,strlen(yytext),"enumerated","FOR",0,yylineno); return FOR;}
{FUNCTION}  {insert_token(yylineno,++number_of_tokens,"KEYWORD",yytext,strlen(yytext),"enumerated","FUNCTION",0,yylineno); return FUNCTION;}
{RETURN}  {insert_token(yylineno,++number_of_tokens,"KEYWORD",yytext,strlen(yytext),"enumerated","RETURN",0,yylineno); return RETURN;}
{BREAK}  {insert_token(yylineno,++number_of_tokens,"KEYWORD",yytext,strlen(yytext),"enumerated","BREAK",0,yylineno); return BREAK;}
{CONTINUE}  {insert_token(yylineno,++number_of_tokens,"KEYWORD",yytext,strlen(yytext),"enumerated","CONTINUE",0,yylineno); return CONTINUE;}
{AND}  {insert_token(yylineno,++number_of_tokens,"KEYWORD",yytext,strlen(yytext),"enumerated","ADD",0,yylineno); return AND;}
{NOT}  {insert_token(yylineno,++number_of_tokens,"KEYWORD",yytext,strlen(yytext),"enumerated","NOT",0,yylineno); return NOT;}
{OR}  {insert_token(yylineno,++number_of_tokens,"KEYWORD",yytext,strlen(yytext),"enumerated","NOT",0,yylineno); return OR;}
{LOCAL}  {insert_token(yylineno,++number_of_tokens,"KEYWORD",yytext,strlen(yytext),"enumerated","LOCAL",0,yylineno); return LOCAL;}
{TRUE}  {insert_token(yylineno,++number_of_tokens,"KEYWORD",yytext,strlen(yytext),"enumerated","TRUE",0,yylineno); return TRUE;}
{FALSE}  {insert_token(yylineno,++number_of_tokens,"KEYWORD",yytext,strlen(yytext),"enumerated","FALSE",0,yylineno); return FALSE;}
{NIL}  {insert_token(yylineno,++number_of_tokens,"KEYWORD",yytext,strlen(yytext),"enumerated","NIL",0,yylineno); return NIL;}


{BRACEOPEN}      {insert_token(yylineno,++number_of_tokens,"PUNCTUATIONMARK",yytext,strlen(yytext),"enumerated","BRACEOPEN",0,yylineno); return BRACEOPEN; }
{BRACECLOSE}     {insert_token(yylineno,++number_of_tokens,"PUNCTUATIONMARK",yytext,strlen(yytext),"enumerated","BRACECLOSE",0,yylineno); return BRACECLOSE;}
{SQBRACKETOPEN}  {insert_token(yylineno,++number_of_tokens,"PUNCTUATIONMARK",yytext,strlen(yytext),"enumerated","SQBRACKETOPEN",0,yylineno); return SQBRACKETOPEN;}
{SQBRACKETCLOSE} {insert_token(yylineno,++number_of_tokens,"PUNCTUATIONMARK",yytext,strlen(yytext),"enumerated","SQBRACKETCLOSE",0,yylineno); return SQBRACKETCLOSE;}
{SEMICOLON}      {insert_token(yylineno,++number_of_tokens,"PUNCTUATIONMARK",yytext,strlen(yytext),"enumerated","SEMICOLON",0,yylineno); return SEMICOLON;}
{COMMA}          {insert_token(yylineno,++number_of_tokens,"PUNCTUATIONMARK",yytext,strlen(yytext),"enumerated","COMMA",0,yylineno); return COMMA;}
{COLON}          {insert_token(yylineno,++number_of_tokens,"PUNCTUATIONMARK",yytext,strlen(yytext),"enumerated","COLON",0,yylineno); return COLON;}
{DOUBLECOLON}    {insert_token(yylineno,++number_of_tokens,"PUNCTUATIONMARK",yytext,strlen(yytext),"enumerated","DOUBLECOLON",0,yylineno); return DOUBLECOLON;}
{DOT}            {insert_token(yylineno,++number_of_tokens,"PUNCTUATIONMARK",yytext,strlen(yytext),"enumerated","DOT",0,yylineno); return DOT;}
{DOUBLEDOT}      {insert_token(yylineno,++number_of_tokens,"PUNCTUATIONMARK",yytext,strlen(yytext),"enumerated","DOUBLEDOT",0,yylineno); return DOUBLEDOT;}
{L_PARENTHESIS}  {insert_token(yylineno,++number_of_tokens,"PUNCTUATIONMARK",yytext,strlen(yytext),"enumerated","L_PARENTHESIS",0,yylineno); return L_PARENTHESIS;}
{R_PARENTHESIS}   {insert_token(yylineno,++number_of_tokens,"PUNCTUATIONMARK",yytext,strlen(yytext),"enumerated","R_PARENTHESIS",0,yylineno); return R_PARENTHESIS;}

{EQUAL} {insert_token(yylineno,++number_of_tokens,"OPERATOR",yytext,strlen(yytext),"enumerated","EQUAL",0,yylineno); return EQUAL;}
{ADD} {insert_token(yylineno,++number_of_tokens,"OPERATOR",yytext,strlen(yytext),"enumerated","ADD",0,yylineno); return ADD;}
{SUB} {insert_token(yylineno,++number_of_tokens,"OPERATOR",yytext,strlen(yytext),"enumerated","SUB",0,yylineno); return SUB;}
{UMINUS} {insert_token(yylineno,++number_of_tokens,"OPERATOR",yytext,strlen(yytext),"enumerated","UMINUS",0,yylineno); return UMINUS;}
{MULT} {insert_token(yylineno,++number_of_tokens,"OPERATOR",yytext,strlen(yytext),"enumerated","MULT",0,yylineno); return MULT;}
{DIVA} {insert_token(yylineno,++number_of_tokens,"OPERATOR",yytext,strlen(yytext),"enumerated","DIVA",0,yylineno); return DIVA;}
{MOD} {insert_token(yylineno,++number_of_tokens,"OPERATOR",yytext,strlen(yytext),"enumerated","MOD",0,yylineno); return MOD;}
{EQUALITY} {insert_token(yylineno,++number_of_tokens,"OPERATOR",yytext,strlen(yytext),"enumerated","EQUALITY",0,yylineno); return EQUALITY;}
{NOTEQUAL} {insert_token(yylineno,++number_of_tokens,"OPERATOR",yytext,strlen(yytext),"enumerated","NOTEQUAL",0,yylineno); return NOTEQUAL;}
{ADDITY} {insert_token(yylineno,++number_of_tokens,"OPERATOR",yytext,strlen(yytext),"enumerated","ADDITY",0,yylineno); return ADDITY;}
{MULTITY} {insert_token(yylineno,++number_of_tokens,"OPERATOR",yytext,strlen(yytext),"enumerated","MULTITY",0,yylineno); return MULTITY;}
{GREATER} {insert_token(yylineno,++number_of_tokens,"OPERATOR",yytext,strlen(yytext),"enumerated","GREATER",0,yylineno); return GREATER;}
{LESS} {insert_token(yylineno,++number_of_tokens,"OPERATOR",yytext,strlen(yytext),"enumerated","LESS",0,yylineno); return LESS;}
{GREATEREQUAL} {insert_token(yylineno,++number_of_tokens,"OPERATOR",yytext,strlen(yytext),"enumerated","GREATEREQUAL",0,yylineno); return GREATEREQUAL;}
{LESSEQUAL} {insert_token(yylineno,++number_of_tokens,"OPERATOR",yytext,strlen(yytext),"enumerated","LESSEQUAL",0,yylineno); return LESSEQUAL;}
{SIMPLECOMMENT}  { /*all this code is as a comment because we try to appear them*/
   int c;
    int i=0,j;
    char *s;
    int line_n=yylineno;
    
    /*struct Node{
        char data;
        struct Node* next;
    };
    struct Node* head=NULL;
    void insert( char new_data){
        struct Node* tmp=(struct Node *)malloc(sizeof(struct Node));
        tmp->data=new_data;
        if(head==NULL){
            head=tmp;
            tmp->next=NULL;
        }else{
            tmp->next=head;
            head=tmp;
        }

    }*/
    
    while((c=input())!=0 && c!='\n'){
        i++;
        //insert(c);
    }i--;
    //s=(char*)malloc((i+1)*sizeof(char));
    //struct Node* temp=head;

    //temp=head;
    /*j=i;
    while(temp!=NULL){
        s[j--]=temp->data;
        temp=temp->next;
    }
    s[i]='\0';*/
    insert_token(line_n,++number_of_tokens,"COMMENT","",i,"enumerated","LINE COMMENT",0,line_n);
    }


{ID} {insert_token(yylineno,++number_of_tokens,"IDENT",yytext,strlen(yytext),"char*",yytext,0,yylineno);  yylval.stringValue= strdup(yytext); return ID;}
{INT} {insert_token(yylineno,++number_of_tokens,"INTCONST",yytext,strlen(yytext),"integer",yytext,0,yylineno); yylval.intValue= atoi(yytext); return INT;}
{REAL} {insert_token(yylineno,++number_of_tokens,"REALCONST",yytext,strlen(yytext),"real",yytext,0,yylineno); yylval.doubleValue= atof(yytext); return REAL;}


{STRING}        {
                
    int c;
    int i=0,j;
    char *s;
    int lin_n=yylineno;
    struct Node{
        char data;
        struct Node* next;
    };
    struct Node* head=NULL;
    void insert( char new_data){
        struct Node* tmp=(struct Node *)malloc(sizeof(struct Node));
        tmp->data=new_data;
        if(head==NULL){
            head=tmp;
            tmp->next=NULL;
        }else{
            tmp->next=head;
            head=tmp;
        }

    }
    c=input();
    while(c!=0)
    {
        if(c=='\"')
        {
            break;
        }
                    
        if(c=='\\')
        {
            c=input();
            if(c=='n')
            {
                i++;
                insert(10);
                c=input();
                continue;
            }else if(c=='t')
            {
                i++;
                insert(9);
                c=input();
                continue;
            }else if(c=='\\')
            {
                i++;
                insert(92);
                c=input();
                continue;
            }else if(c=='a')
            {
                i++;
                insert(7);
                c=input();
                continue;
            }else if(c=='b')
            {
                i++;
                insert(8);
                c=input();
                continue;
            }else if(c=='e')
            {
                i++;
                insert(27);
                c=input();
                continue;
            }else if(c=='f')
            {
                i++;
                insert(12);
                c=input();
                continue;
            }else if(c=='n')
            {
                i++;
                insert(10);
                c=input();
                continue;
            }else if(c=='r')
            {
                i++;
                insert(13);
                c=input();
                continue;
            }else if(c=='v')
            {
                i++;
                insert(11);
                c=input();
                continue;
            }else if(c=='\?')
            {
                i++;
                insert(63);
                c=input();
                continue;
            }else
            {
                printf("Error unexpected series of characters: \\%c\n",c);
            }
                        
        }
        i++;
        insert(c);
        c=input();
    }
    if(c!='\"')
    {
        printf("Error: string expected \" in line %d\n",lin_n);
        exit(EXIT_FAILURE);
    }
    s=(char*)malloc((i+1)*sizeof(char));

    struct Node* temp=head;
  
    temp=head;
    j=i-1;
    while(temp!=NULL){
        s[j]=temp->data;
        temp=temp->next;
        j--;
    }
    s[i+1]='\0';
    insert_token(lin_n , ++number_of_tokens , "STRING" , s ,i,"char *",s,0,lin_n);
    yylval.stringValue=strdup(s);
    return STRING;
              
}


{COMMENT}  {
   int c;
   int open_com =1;
   int close_com=0;
   int nested=0;
   int number_of_nested=0;
   int line = yylineno;
   char *in = (char *)malloc(3*sizeof(char));
   char *s = (char *)malloc(3*sizeof(char));
   c=input();
   in[0]=yylineno;

   while(c!=0 && (open_com!=close_com))
   {    

        if(c=='/')
        {
            c=input();
            if(c=='*')
            {   
                in[open_com]=yylineno;
                number_of_nested++;
                open_com++;
            }else{
                unput(c);
            }
        }else if(c=='*')
        {
            c=input();
            if(c=='/')
            {
                close_com++;
                if(open_com>close_com)
                {
                   insert_token(line,++number_of_tokens,"COMMENT","",1,"enumerated","NESTED COMMENT ",in[open_com+1-close_com],yylineno);
                }else if(open_com==close_com){
                   insert_token(line,++number_of_tokens,"COMMENT","",1,"enumerated","MULTILINE COMMENT",in[open_com-close_com],yylineno);
                }
            }else{
                unput(c);
            }
        }
        if(open_com==close_com)
        {
            break;
        }else
        {
            c=input();
        }
   }
   if(c==0 && (open_com!=close_com))
   {
    printf("Error: comment doesn't close in line %d!\n",line);
    exit(EXIT_FAILURE);
   }else{/*
    if(nested==1)
    {
        insert_token(line,++number_of_tokens,"COMMENT","",1,"enumerated","MULTILINE COMMENT",yylineno);

    }else{
        insert_token(line,++number_of_tokens,"COMMENT","",1,"enumerated","NESTED COMMENT ",yylineno);
    }*/
   }


}
"\r\n" {/*windows new line*/} 
\n     {}
\t     {}
" "    {}

. {printf("Undefined input %s in line %d\n",yytext,yylineno);
    exit(EXIT_FAILURE);
    }

%%


