/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IF = 258,                      /* IF  */
    ELSE = 259,                    /* ELSE  */
    WHILE = 260,                   /* WHILE  */
    FOR = 261,                     /* FOR  */
    FUNCTION = 262,                /* FUNCTION  */
    RETURN = 263,                  /* RETURN  */
    BREAK = 264,                   /* BREAK  */
    CONTINUE = 265,                /* CONTINUE  */
    AND = 266,                     /* AND  */
    NOT = 267,                     /* NOT  */
    OR = 268,                      /* OR  */
    LOCAL = 269,                   /* LOCAL  */
    TRUE = 270,                    /* TRUE  */
    FALSE = 271,                   /* FALSE  */
    NIL = 272,                     /* NIL  */
    BRACEOPEN = 273,               /* BRACEOPEN  */
    BRACECLOSE = 274,              /* BRACECLOSE  */
    SQBRACKETOPEN = 275,           /* SQBRACKETOPEN  */
    SQBRACKETCLOSE = 276,          /* SQBRACKETCLOSE  */
    L_PARENTHESIS = 277,           /* L_PARENTHESIS  */
    R_PARENTHESIS = 278,           /* R_PARENTHESIS  */
    SEMICOLON = 279,               /* SEMICOLON  */
    COMMA = 280,                   /* COMMA  */
    COLON = 281,                   /* COLON  */
    DOUBLECOLON = 282,             /* DOUBLECOLON  */
    DOT = 283,                     /* DOT  */
    DOUBLEDOT = 284,               /* DOUBLEDOT  */
    EQUAL = 285,                   /* EQUAL  */
    ADD = 286,                     /* ADD  */
    SUB = 287,                     /* SUB  */
    MULT = 288,                    /* MULT  */
    DIVA = 289,                    /* DIVA  */
    MOD = 290,                     /* MOD  */
    EQUALITY = 291,                /* EQUALITY  */
    NOTEQUAL = 292,                /* NOTEQUAL  */
    ADDITY = 293,                  /* ADDITY  */
    MULTITY = 294,                 /* MULTITY  */
    GREATER = 295,                 /* GREATER  */
    LESS = 296,                    /* LESS  */
    GREATEREQUAL = 297,            /* GREATEREQUAL  */
    LESSEQUAL = 298,               /* LESSEQUAL  */
    SIMPLECOMMENT = 299,           /* SIMPLECOMMENT  */
    COMMENT = 300,                 /* COMMENT  */
    ID = 301,                      /* ID  */
    INT = 302,                     /* INT  */
    REAL = 303,                    /* REAL  */
    STRING = 304,                  /* STRING  */
    UMINUS = 305                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IF 258
#define ELSE 259
#define WHILE 260
#define FOR 261
#define FUNCTION 262
#define RETURN 263
#define BREAK 264
#define CONTINUE 265
#define AND 266
#define NOT 267
#define OR 268
#define LOCAL 269
#define TRUE 270
#define FALSE 271
#define NIL 272
#define BRACEOPEN 273
#define BRACECLOSE 274
#define SQBRACKETOPEN 275
#define SQBRACKETCLOSE 276
#define L_PARENTHESIS 277
#define R_PARENTHESIS 278
#define SEMICOLON 279
#define COMMA 280
#define COLON 281
#define DOUBLECOLON 282
#define DOT 283
#define DOUBLEDOT 284
#define EQUAL 285
#define ADD 286
#define SUB 287
#define MULT 288
#define DIVA 289
#define MOD 290
#define EQUALITY 291
#define NOTEQUAL 292
#define ADDITY 293
#define MULTITY 294
#define GREATER 295
#define LESS 296
#define GREATEREQUAL 297
#define LESSEQUAL 298
#define SIMPLECOMMENT 299
#define COMMENT 300
#define ID 301
#define INT 302
#define REAL 303
#define STRING 304
#define UMINUS 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 68 "parser.y"



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

    

#line 194 "parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_H_INCLUDED  */
