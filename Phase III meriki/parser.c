/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"


    
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





#line 132 "parser.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_WHILE = 5,                      /* WHILE  */
  YYSYMBOL_FOR = 6,                        /* FOR  */
  YYSYMBOL_FUNCTION = 7,                   /* FUNCTION  */
  YYSYMBOL_RETURN = 8,                     /* RETURN  */
  YYSYMBOL_BREAK = 9,                      /* BREAK  */
  YYSYMBOL_CONTINUE = 10,                  /* CONTINUE  */
  YYSYMBOL_AND = 11,                       /* AND  */
  YYSYMBOL_NOT = 12,                       /* NOT  */
  YYSYMBOL_OR = 13,                        /* OR  */
  YYSYMBOL_LOCAL = 14,                     /* LOCAL  */
  YYSYMBOL_TRUE = 15,                      /* TRUE  */
  YYSYMBOL_FALSE = 16,                     /* FALSE  */
  YYSYMBOL_NIL = 17,                       /* NIL  */
  YYSYMBOL_BRACEOPEN = 18,                 /* BRACEOPEN  */
  YYSYMBOL_BRACECLOSE = 19,                /* BRACECLOSE  */
  YYSYMBOL_SQBRACKETOPEN = 20,             /* SQBRACKETOPEN  */
  YYSYMBOL_SQBRACKETCLOSE = 21,            /* SQBRACKETCLOSE  */
  YYSYMBOL_L_PARENTHESIS = 22,             /* L_PARENTHESIS  */
  YYSYMBOL_R_PARENTHESIS = 23,             /* R_PARENTHESIS  */
  YYSYMBOL_SEMICOLON = 24,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 25,                     /* COMMA  */
  YYSYMBOL_COLON = 26,                     /* COLON  */
  YYSYMBOL_DOUBLECOLON = 27,               /* DOUBLECOLON  */
  YYSYMBOL_DOT = 28,                       /* DOT  */
  YYSYMBOL_DOUBLEDOT = 29,                 /* DOUBLEDOT  */
  YYSYMBOL_EQUAL = 30,                     /* EQUAL  */
  YYSYMBOL_ADD = 31,                       /* ADD  */
  YYSYMBOL_SUB = 32,                       /* SUB  */
  YYSYMBOL_MULT = 33,                      /* MULT  */
  YYSYMBOL_DIVA = 34,                      /* DIVA  */
  YYSYMBOL_MOD = 35,                       /* MOD  */
  YYSYMBOL_EQUALITY = 36,                  /* EQUALITY  */
  YYSYMBOL_NOTEQUAL = 37,                  /* NOTEQUAL  */
  YYSYMBOL_ADDITY = 38,                    /* ADDITY  */
  YYSYMBOL_MULTITY = 39,                   /* MULTITY  */
  YYSYMBOL_GREATER = 40,                   /* GREATER  */
  YYSYMBOL_LESS = 41,                      /* LESS  */
  YYSYMBOL_GREATEREQUAL = 42,              /* GREATEREQUAL  */
  YYSYMBOL_LESSEQUAL = 43,                 /* LESSEQUAL  */
  YYSYMBOL_SIMPLECOMMENT = 44,             /* SIMPLECOMMENT  */
  YYSYMBOL_COMMENT = 45,                   /* COMMENT  */
  YYSYMBOL_ID = 46,                        /* ID  */
  YYSYMBOL_INT = 47,                       /* INT  */
  YYSYMBOL_REAL = 48,                      /* REAL  */
  YYSYMBOL_STRING = 49,                    /* STRING  */
  YYSYMBOL_UMINUS = 50,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 51,                  /* $accept  */
  YYSYMBOL_program = 52,                   /* program  */
  YYSYMBOL_stmt = 53,                      /* stmt  */
  YYSYMBOL_break = 54,                     /* break  */
  YYSYMBOL_continue = 55,                  /* continue  */
  YYSYMBOL_56_1 = 56,                      /* $@1  */
  YYSYMBOL_stmt_list = 57,                 /* stmt_list  */
  YYSYMBOL_expr = 58,                      /* expr  */
  YYSYMBOL_term = 59,                      /* term  */
  YYSYMBOL_assiginexpr = 60,               /* assiginexpr  */
  YYSYMBOL_61_2 = 61,                      /* $@2  */
  YYSYMBOL_62_3 = 62,                      /* $@3  */
  YYSYMBOL_primary = 63,                   /* primary  */
  YYSYMBOL_lvalue = 64,                    /* lvalue  */
  YYSYMBOL_member = 65,                    /* member  */
  YYSYMBOL_call = 66,                      /* call  */
  YYSYMBOL_67_4 = 67,                      /* $@4  */
  YYSYMBOL_68_5 = 68,                      /* $@5  */
  YYSYMBOL_callsuffix = 69,                /* callsuffix  */
  YYSYMBOL_normcall = 70,                  /* normcall  */
  YYSYMBOL_71_6 = 71,                      /* $@6  */
  YYSYMBOL_methodcall = 72,                /* methodcall  */
  YYSYMBOL_elist = 73,                     /* elist  */
  YYSYMBOL_objectdef = 74,                 /* objectdef  */
  YYSYMBOL_indexed = 75,                   /* indexed  */
  YYSYMBOL_block = 76,                     /* block  */
  YYSYMBOL_77_7 = 77,                      /* $@7  */
  YYSYMBOL_funcdef = 78,                   /* funcdef  */
  YYSYMBOL_79_8 = 79,                      /* @8  */
  YYSYMBOL_80_9 = 80,                      /* $@9  */
  YYSYMBOL_81_10 = 81,                     /* $@10  */
  YYSYMBOL_82_11 = 82,                     /* @11  */
  YYSYMBOL_83_12 = 83,                     /* $@12  */
  YYSYMBOL_84_13 = 84,                     /* $@13  */
  YYSYMBOL_const = 85,                     /* const  */
  YYSYMBOL_idlist = 86,                    /* idlist  */
  YYSYMBOL_ifprefix = 87,                  /* ifprefix  */
  YYSYMBOL_88_14 = 88,                     /* $@14  */
  YYSYMBOL_elseprefix = 89,                /* elseprefix  */
  YYSYMBOL_ifstmt = 90,                    /* ifstmt  */
  YYSYMBOL_whilestart = 91,                /* whilestart  */
  YYSYMBOL_whilesecond = 92,               /* whilesecond  */
  YYSYMBOL_while = 93,                     /* while  */
  YYSYMBOL_N = 94,                         /* N  */
  YYSYMBOL_M = 95,                         /* M  */
  YYSYMBOL_forprefix = 96,                 /* forprefix  */
  YYSYMBOL_97_15 = 97,                     /* $@15  */
  YYSYMBOL_for = 98,                       /* for  */
  YYSYMBOL_loopstart = 99,                 /* loopstart  */
  YYSYMBOL_loopend = 100,                  /* loopend  */
  YYSYMBOL_loopstmt = 101,                 /* loopstmt  */
  YYSYMBOL_funcblockstart = 102,           /* funcblockstart  */
  YYSYMBOL_funcblockend = 103,             /* funcblockend  */
  YYSYMBOL_returnstmt = 104,               /* returnstmt  */
  YYSYMBOL_105_16 = 105,                   /* $@16  */
  YYSYMBOL_106_17 = 106,                   /* $@17  */
  YYSYMBOL_107_18 = 107                    /* $@18  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  72
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   510

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  116
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  211

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   305


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   205,   205,   208,   209,   210,   211,   212,   213,   214,
     215,   223,   227,   233,   250,   250,   266,   272,   281,   282,
     289,   297,   304,   311,   319,   330,   341,   352,   363,   374,
     385,   391,   397,   401,   402,   411,   419,   443,   464,   489,
     509,   512,   518,   512,   534,   535,   536,   537,   541,   546,
     667,   698,   715,   718,   719,   725,   726,   729,   729,   735,
     764,   764,   773,   778,   783,   783,   795,   804,   805,   808,
     812,   824,   847,   848,   854,   854,   899,   941,   941,   899,
     957,   980,   980,   957,   998,  1001,  1005,  1009,  1015,  1019,
    1023,  1029,  1066,  1094,  1098,  1098,  1105,  1112,  1118,  1139,
    1146,  1153,  1165,  1167,  1169,  1169,  1181,  1200,  1203,  1206,
    1213,  1216,  1220,  1220,  1224,  1224,  1224
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IF", "ELSE", "WHILE",
  "FOR", "FUNCTION", "RETURN", "BREAK", "CONTINUE", "AND", "NOT", "OR",
  "LOCAL", "TRUE", "FALSE", "NIL", "BRACEOPEN", "BRACECLOSE",
  "SQBRACKETOPEN", "SQBRACKETCLOSE", "L_PARENTHESIS", "R_PARENTHESIS",
  "SEMICOLON", "COMMA", "COLON", "DOUBLECOLON", "DOT", "DOUBLEDOT",
  "EQUAL", "ADD", "SUB", "MULT", "DIVA", "MOD", "EQUALITY", "NOTEQUAL",
  "ADDITY", "MULTITY", "GREATER", "LESS", "GREATEREQUAL", "LESSEQUAL",
  "SIMPLECOMMENT", "COMMENT", "ID", "INT", "REAL", "STRING", "UMINUS",
  "$accept", "program", "stmt", "break", "continue", "$@1", "stmt_list",
  "expr", "term", "assiginexpr", "$@2", "$@3", "primary", "lvalue",
  "member", "call", "$@4", "$@5", "callsuffix", "normcall", "$@6",
  "methodcall", "elist", "objectdef", "indexed", "block", "$@7", "funcdef",
  "@8", "$@9", "$@10", "@11", "$@12", "$@13", "const", "idlist",
  "ifprefix", "$@14", "elseprefix", "ifstmt", "whilestart", "whilesecond",
  "while", "N", "M", "forprefix", "$@15", "for", "loopstart", "loopend",
  "loopstmt", "funcblockstart", "funcblockend", "returnstmt", "$@16",
  "$@17", "$@18", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-165)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-113)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     120,  -165,  -165,  -165,   -19,    -7,     4,  -165,   196,   -24,
    -165,  -165,  -165,  -165,   158,    17,  -165,   -10,   196,    21,
      21,  -165,  -165,  -165,  -165,    53,   120,  -165,  -165,  -165,
     216,  -165,  -165,  -165,    79,  -165,    48,  -165,  -165,  -165,
    -165,   120,  -165,    20,  -165,  -165,  -165,  -165,    36,    47,
      28,  -165,    72,    51,   196,  -165,    71,    64,  -165,   120,
     196,   249,    76,    82,   264,    87,  -165,    80,   104,    -9,
      48,    -9,  -165,  -165,  -165,  -165,  -165,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,  -165,
      67,    68,  -165,  -165,    85,  -165,  -165,  -165,   196,  -165,
      70,   115,   196,  -165,   196,   196,   196,    99,   102,  -165,
    -165,   364,  -165,   112,   297,   196,  -165,  -165,  -165,   111,
     116,   196,   196,    58,    80,    64,    64,    64,   454,   454,
     160,   160,   160,   160,   314,   196,  -165,   119,  -165,   331,
     196,  -165,  -165,   120,   347,   120,  -165,   123,   380,   124,
     127,  -165,   105,   126,  -165,   196,  -165,  -165,   111,   467,
     441,  -165,   130,   196,   196,  -165,   131,  -165,  -165,  -165,
    -165,  -165,  -165,   105,   105,  -165,   -16,  -165,   413,   196,
    -165,   133,   364,  -165,  -165,  -165,   196,   -13,    -2,  -165,
     114,   132,   138,  -165,  -165,   427,  -165,  -165,   144,  -165,
     145,  -165,  -165,  -165,   144,   144,  -165,  -165,  -165,  -165,
    -165
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      17,    94,    99,   104,    80,   114,     0,    14,     0,     0,
      89,    90,    88,    74,    69,     0,    12,     0,     0,     0,
       0,    49,    85,    86,    87,     0,    17,     8,     9,     2,
       0,    32,    18,    40,    44,    52,    45,    46,    10,    11,
      48,     0,     4,     0,     5,   102,     6,     7,     0,     0,
       0,    76,     0,     0,     0,    13,     0,    35,    50,    17,
       0,    67,     0,     0,     0,     0,    51,    34,     0,    36,
       0,    38,     1,    16,   103,   103,     3,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    64,
       0,     0,    37,    39,     0,    59,    62,    63,     0,    57,
       0,    97,     0,   107,    69,     0,    69,     0,     0,    81,
     113,   115,    15,     0,     0,    69,    70,    71,    33,    47,
       0,     0,     0,    19,    20,    21,    22,    23,    28,    29,
      24,    26,    25,    27,     0,    69,    53,     0,    42,     0,
      69,    55,    96,     0,     0,     0,   101,     0,     0,     0,
       0,    77,    93,     0,    75,     0,    68,    60,     0,    30,
      31,    54,     0,    69,     0,    56,     0,    98,   100,   108,
     102,    95,   103,    93,    93,    91,     0,   116,     0,    69,
      65,     0,    43,    58,   109,   107,     0,     0,     0,    82,
       0,    73,     0,    66,   102,     0,   110,    78,     0,    92,
       0,    61,   106,   105,     0,     0,    83,    72,   111,    79,
      84
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -165,  -165,   -39,  -165,  -165,  -165,   -21,     0,  -165,  -165,
    -165,  -165,  -165,    32,  -165,    42,  -165,  -165,  -165,  -165,
    -165,  -165,   -90,  -165,   -35,  -158,  -165,   -11,  -165,  -165,
    -165,  -165,  -165,  -165,  -165,  -102,  -165,  -165,  -165,  -165,
    -165,  -165,  -165,  -164,   -72,  -165,  -165,  -165,  -165,  -165,
     -14,  -165,  -165,  -165,  -165,  -165,  -165
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    25,    26,    27,    28,    56,    29,    61,    31,    32,
      94,   164,    33,    34,    35,    36,   140,   179,    95,    96,
     135,    97,    62,    37,    63,    38,    59,    39,   108,   174,
     205,    52,   152,   198,    40,   176,    41,    48,   143,    42,
      43,   103,    44,   104,   121,    45,    49,    46,   145,   184,
     146,   204,   210,    47,    53,    54,   153
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      30,    50,   101,   122,    65,    73,   185,   189,    57,   190,
     196,    88,   190,    89,   147,    64,   149,  -112,    67,    90,
      91,   197,    58,   190,     4,   156,    30,    51,    55,     8,
     202,     9,    10,    11,    12,     9,    66,    14,   113,    15,
     206,    30,   102,    68,    17,   162,   208,   209,    17,    18,
     166,    69,    71,    72,   111,    19,    20,   120,   105,    30,
     114,    70,    70,    21,    22,    23,    24,    21,    98,   106,
      99,   187,   188,   181,   107,   110,   100,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   192,
      78,    79,    80,    81,   109,   112,    78,   116,   139,    88,
     186,    89,   144,   117,   167,   148,   169,    90,    91,   -41,
     119,     4,  -113,   136,   137,   138,   141,    92,    93,   142,
     150,   159,   160,     1,   151,     2,     3,     4,     5,     6,
       7,   154,     8,   157,     9,    10,    11,    12,    13,   158,
      14,   163,    15,    30,    16,    30,   170,    17,   172,   173,
     177,   175,    18,   180,   183,   178,   193,   200,    19,    20,
     199,   201,    13,    60,   182,   207,    21,    22,    23,    24,
       8,   194,     9,    10,    11,    12,    60,     0,    14,     0,
      15,     0,     0,     0,     0,    17,   195,     0,     0,     0,
      18,    77,    78,    79,    80,    81,    19,    20,     0,     0,
    -113,  -113,  -113,  -113,    21,    22,    23,    24,     8,     0,
       9,    10,    11,    12,     0,     0,    14,     0,    15,     0,
       0,     0,     0,    17,     0,     0,     0,    74,    18,    75,
       0,     0,     0,     0,    19,    20,     0,     0,     0,     0,
      76,     0,    21,    22,    23,    24,     0,    77,    78,    79,
      80,    81,    82,    83,     0,     0,    84,    85,    86,    87,
      74,     0,    75,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   115,    74,     0,    75,     0,     0,
      77,    78,    79,    80,    81,    82,    83,   118,     0,    84,
      85,    86,    87,     0,     0,    77,    78,    79,    80,    81,
      82,    83,     0,     0,    84,    85,    86,    87,    74,     0,
      75,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   155,     0,    74,     0,    75,    77,    78,
      79,    80,    81,    82,    83,   161,     0,    84,    85,    86,
      87,     0,    74,     0,    75,    77,    78,    79,    80,    81,
      82,    83,   165,     0,    84,    85,    86,    87,    74,     0,
      75,     0,    77,    78,    79,    80,    81,    82,    83,     0,
     168,    84,    85,    86,    87,    74,     0,    75,    77,    78,
      79,    80,    81,    82,    83,     0,     0,    84,    85,    86,
      87,    74,     0,    75,     0,    77,    78,    79,    80,    81,
      82,    83,     0,   171,    84,    85,    86,    87,     0,     0,
       0,    77,    78,    79,    80,    81,    82,    83,     0,     0,
      84,    85,    86,    87,    74,     0,    75,     0,     0,     0,
       0,     0,   191,     0,     0,     0,     0,     0,    74,     0,
      75,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      83,   203,    74,    84,    85,    86,    87,     0,    77,    78,
      79,    80,    81,    82,    83,     0,     0,    84,    85,    86,
      87,     0,    77,    78,    79,    80,    81,    82,    83,     0,
       0,    84,    85,    86,    87,    77,    78,    79,    80,    81,
    -113,  -113,     0,     0,    84,    85,    86,    87,    77,    78,
      79,    80,    81,    82,    83,     0,     0,    84,    85,    86,
      87
};

static const yytype_int16 yycheck[] =
{
       0,    20,    41,    75,    15,    26,   170,    23,     8,    25,
      23,    20,    25,    22,   104,    15,   106,    24,    18,    28,
      29,    23,    46,    25,     7,   115,    26,    46,    24,    12,
     194,    14,    15,    16,    17,    14,    46,    20,    59,    22,
     198,    41,    22,    22,    27,   135,   204,   205,    27,    32,
     140,    19,    20,     0,    54,    38,    39,    68,    22,    59,
      60,    19,    20,    46,    47,    48,    49,    46,    20,    22,
      22,   173,   174,   163,    46,    24,    28,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,   179,
      32,    33,    34,    35,    22,    24,    32,    21,    98,    20,
     172,    22,   102,    21,   143,   105,   145,    28,    29,    30,
      23,     7,    32,    46,    46,    30,    46,    38,    39,     4,
      21,   121,   122,     3,    22,     5,     6,     7,     8,     9,
      10,    19,    12,    22,    14,    15,    16,    17,    18,    23,
      20,    22,    22,   143,    24,   145,    23,    27,    24,    22,
      24,    46,    32,    23,    23,   155,    23,    25,    38,    39,
      46,    23,    18,    18,   164,   200,    46,    47,    48,    49,
      12,   185,    14,    15,    16,    17,    18,    -1,    20,    -1,
      22,    -1,    -1,    -1,    -1,    27,   186,    -1,    -1,    -1,
      32,    31,    32,    33,    34,    35,    38,    39,    -1,    -1,
      40,    41,    42,    43,    46,    47,    48,    49,    12,    -1,
      14,    15,    16,    17,    -1,    -1,    20,    -1,    22,    -1,
      -1,    -1,    -1,    27,    -1,    -1,    -1,    11,    32,    13,
      -1,    -1,    -1,    -1,    38,    39,    -1,    -1,    -1,    -1,
      24,    -1,    46,    47,    48,    49,    -1,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    40,    41,    42,    43,
      11,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    11,    -1,    13,    -1,    -1,
      31,    32,    33,    34,    35,    36,    37,    23,    -1,    40,
      41,    42,    43,    -1,    -1,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    40,    41,    42,    43,    11,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    -1,    11,    -1,    13,    31,    32,
      33,    34,    35,    36,    37,    21,    -1,    40,    41,    42,
      43,    -1,    11,    -1,    13,    31,    32,    33,    34,    35,
      36,    37,    21,    -1,    40,    41,    42,    43,    11,    -1,
      13,    -1,    31,    32,    33,    34,    35,    36,    37,    -1,
      23,    40,    41,    42,    43,    11,    -1,    13,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    40,    41,    42,
      43,    11,    -1,    13,    -1,    31,    32,    33,    34,    35,
      36,    37,    -1,    23,    40,    41,    42,    43,    -1,    -1,
      -1,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      40,    41,    42,    43,    11,    -1,    13,    -1,    -1,    -1,
      -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,    11,    -1,
      13,    -1,    -1,    -1,    31,    32,    33,    34,    35,    36,
      37,    24,    11,    40,    41,    42,    43,    -1,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    40,    41,    42,
      43,    -1,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    40,    41,    42,    43,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    40,    41,    42,    43,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    40,    41,    42,
      43
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,     6,     7,     8,     9,    10,    12,    14,
      15,    16,    17,    18,    20,    22,    24,    27,    32,    38,
      39,    46,    47,    48,    49,    52,    53,    54,    55,    57,
      58,    59,    60,    63,    64,    65,    66,    74,    76,    78,
      85,    87,    90,    91,    93,    96,    98,   104,    88,    97,
      20,    46,    82,   105,   106,    24,    56,    58,    46,    77,
      18,    58,    73,    75,    58,    78,    46,    58,    22,    64,
      66,    64,     0,    57,    11,    13,    24,    31,    32,    33,
      34,    35,    36,    37,    40,    41,    42,    43,    20,    22,
      28,    29,    38,    39,    61,    69,    70,    72,    20,    22,
      28,    53,    22,    92,    94,    22,    22,    46,    79,    22,
      24,    58,    24,    57,    58,    25,    21,    21,    23,    23,
      78,    95,    95,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    71,    46,    46,    30,    58,
      67,    46,     4,    89,    58,    99,   101,    73,    58,    73,
      21,    22,    83,   107,    19,    26,    73,    22,    23,    58,
      58,    21,    73,    22,    62,    21,    73,    53,    23,    53,
      23,    23,    24,    22,    80,    46,    86,    24,    58,    68,
      23,    73,    58,    23,   100,    94,    95,    86,    86,    23,
      25,    19,    73,    23,   101,    58,    23,    23,    84,    46,
      25,    23,    94,    24,   102,    81,    76,    75,    76,    76,
     103
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    54,    56,    55,    57,    57,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    59,    59,    59,    59,    59,    59,    59,
      59,    61,    62,    60,    63,    63,    63,    63,    63,    64,
      64,    64,    64,    65,    65,    65,    65,    67,    66,    66,
      68,    66,    69,    69,    71,    70,    72,    73,    73,    73,
      74,    74,    75,    75,    77,    76,    79,    80,    81,    78,
      82,    83,    84,    78,    78,    85,    85,    85,    85,    85,
      85,    86,    86,    86,    88,    87,    89,    90,    90,    91,
      92,    93,    94,    95,    97,    96,    98,    99,   100,   101,
     102,   103,   105,   104,   106,   107,   104
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     0,     3,     2,     0,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       4,     4,     1,     3,     2,     2,     2,     2,     2,     2,
       1,     0,     0,     5,     1,     1,     1,     3,     1,     1,
       2,     2,     1,     3,     4,     3,     4,     0,     5,     2,
       0,     7,     1,     1,     0,     4,     5,     1,     3,     0,
       3,     3,     7,     5,     0,     4,     0,     0,     0,     9,
       0,     0,     0,     8,    10,     1,     1,     1,     1,     1,
       1,     1,     3,     0,     0,     5,     1,     2,     4,     1,
       3,     3,     0,     0,     0,     8,     7,     0,     0,     3,
       0,     0,     0,     3,     0,     0,     5
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: stmt_list  */
#line 205 "parser.y"
                           {  printf("Program Starts:\n");}
#line 1440 "parser.c"
    break;

  case 3: /* stmt: expr SEMICOLON  */
#line 208 "parser.y"
                               {resettemp(); (yyval.stmt_t).breakList=0; (yyval.stmt_t).contList=0; }
#line 1446 "parser.c"
    break;

  case 4: /* stmt: ifstmt  */
#line 209 "parser.y"
                         {  }
#line 1452 "parser.c"
    break;

  case 5: /* stmt: while  */
#line 210 "parser.y"
                        {  }
#line 1458 "parser.c"
    break;

  case 6: /* stmt: for  */
#line 211 "parser.y"
                       { }
#line 1464 "parser.c"
    break;

  case 7: /* stmt: returnstmt  */
#line 212 "parser.y"
                            { if(isFunc==0 )printf("Error:Use of 'return' while not in a function at line:%d\n",yylineno);  }
#line 1470 "parser.c"
    break;

  case 8: /* stmt: break  */
#line 213 "parser.y"
                        { }
#line 1476 "parser.c"
    break;

  case 9: /* stmt: continue  */
#line 214 "parser.y"
                          {  }
#line 1482 "parser.c"
    break;

  case 10: /* stmt: block  */
#line 215 "parser.y"
                       { 
                       if(inloop==1||inIff==1){
                        onlyBlock=0;
                    }else{
                        onlyBlock=0;
                    }
                    
                  }
#line 1495 "parser.c"
    break;

  case 11: /* stmt: funcdef  */
#line 223 "parser.y"
                         {
                       (yyval.stmt_t).breakList=0; 
                       (yyval.stmt_t).contList=0;
                        }
#line 1504 "parser.c"
    break;

  case 12: /* stmt: SEMICOLON  */
#line 227 "parser.y"
                           { 
                    (yyval.stmt_t).breakList=0; 
                    (yyval.stmt_t).contList=0;  
                }
#line 1513 "parser.c"
    break;

  case 13: /* break: BREAK SEMICOLON  */
#line 233 "parser.y"
                               {
              
                    printWhileStack(whilestack,whiletop);
                    (yyval.stmt_t).breakList=0;
                    (yyval.stmt_t).contList=0;

               
                 
                    (yyval.stmt_t).breakList = newlist(nextquadlabel());
                    emit(jump,NULL,NULL,0,nextquadlabel(),yylineno); 

                if(topWhileStack(whilestack,whiletop)>0)
                    printf("Error:Use of 'break' while not in a loop at line:%d\n",yylineno);
                else{
                }
                }
#line 1534 "parser.c"
    break;

  case 14: /* $@1: %empty  */
#line 250 "parser.y"
                        {
                }
#line 1541 "parser.c"
    break;

  case 15: /* continue: CONTINUE $@1 SEMICOLON  */
#line 251 "parser.y"
                           {
                (yyval.stmt_t).breakList=0;
                (yyval.stmt_t).contList=0;
                (yyval.stmt_t).contList = newlist(nextquadlabel());
                  
                
                emit(jump,NULL,NULL,0,nextquadlabel(),yylineno); 
                if(topWhileStack(whilestack,whiletop)>0)
                    printf("Error:Use of 'continue' while not in a loop at line:%d\n",yylineno);
                else{
                                     
                }
                }
#line 1559 "parser.c"
    break;

  case 16: /* stmt_list: stmt stmt_list  */
#line 266 "parser.y"
                               { 
                    
                    (yyval.stmt_t).breakList = mergelist((yyvsp[0].stmt_t).breakList,(yyvsp[-1].stmt_t).breakList);
                    (yyval.stmt_t).contList = mergelist( (yyvsp[0].stmt_t).contList, (yyvsp[-1].stmt_t).contList); 
                    
                }
#line 1570 "parser.c"
    break;

  case 17: /* stmt_list: %empty  */
#line 272 "parser.y"
                 {  (yyval.stmt_t).breakList=0;
                    (yyval.stmt_t).contList=0;
                    }
#line 1578 "parser.c"
    break;

  case 18: /* expr: assiginexpr  */
#line 281 "parser.y"
                                            {(yyval.exprVal)=(yyvsp[0].exprVal); }
#line 1584 "parser.c"
    break;

  case 19: /* expr: expr ADD expr  */
#line 282 "parser.y"
                                            {if(check_arith_bool((yyvsp[-2].exprVal))||check_arith_bool((yyvsp[0].exprVal))){
                                            if((yyvsp[-2].exprVal)->type==costnum_e && (yyvsp[0].exprVal)->type==costnum_e)
                                                (yyval.exprVal)=newexpr(costnum_e);
                                            else
                                                (yyval.exprVal)=newexpr(arithexpr_e); 
                                            (yyval.exprVal)->sym=newtemp(scope,yylineno); 
                                            emit(add,(yyvsp[-2].exprVal),(yyvsp[0].exprVal),(yyval.exprVal),nextquadlabel() ,yylineno);}}
#line 1596 "parser.c"
    break;

  case 20: /* expr: expr SUB expr  */
#line 289 "parser.y"
                                            {if(check_arith_bool((yyvsp[-2].exprVal))||check_arith_bool((yyvsp[0].exprVal))){   
                                            if((yyvsp[-2].exprVal)->type==costnum_e && (yyvsp[0].exprVal)->type==costnum_e)    
                                                (yyval.exprVal)=newexpr(costnum_e);
                                            else
                                                (yyval.exprVal)=newexpr(arithexpr_e); 
                            
                                            (yyval.exprVal)->sym=newtemp(scope,yylineno); 
                                             emit(sub,(yyvsp[-2].exprVal),(yyvsp[0].exprVal),(yyval.exprVal),nextquadlabel(),yylineno);}}
#line 1609 "parser.c"
    break;

  case 21: /* expr: expr MULT expr  */
#line 297 "parser.y"
                                            {if(check_arith_bool((yyvsp[-2].exprVal))||check_arith_bool((yyvsp[0].exprVal))){
                                            if((yyvsp[-2].exprVal)->type==costnum_e && (yyvsp[0].exprVal)->type==costnum_e)
                                                (yyval.exprVal)=newexpr(costnum_e);
                                            else 
                                                (yyval.exprVal)=newexpr(arithexpr_e); 
                                            (yyval.exprVal)->sym=newtemp(scope,yylineno); 
                                             emit(mul,(yyvsp[-2].exprVal),(yyvsp[0].exprVal),(yyval.exprVal),nextquadlabel(),yylineno);}}
#line 1621 "parser.c"
    break;

  case 22: /* expr: expr DIVA expr  */
#line 304 "parser.y"
                                            {if(check_arith_bool((yyvsp[-2].exprVal))||check_arith_bool((yyvsp[0].exprVal))){
                                            if((yyvsp[-2].exprVal)->type==costnum_e && (yyvsp[0].exprVal)->type==costnum_e)
                                                (yyval.exprVal)=newexpr(costnum_e);
                                            else
                                                (yyval.exprVal)=newexpr(arithexpr_e); 
                                            (yyval.exprVal)->sym=newtemp(scope,yylineno); 
                                             emit(diva,(yyvsp[-2].exprVal),(yyvsp[0].exprVal),(yyval.exprVal),nextquadlabel(),yylineno);}}
#line 1633 "parser.c"
    break;

  case 23: /* expr: expr MOD expr  */
#line 311 "parser.y"
                                            {if(check_arith_bool((yyvsp[-2].exprVal))||check_arith_bool((yyvsp[0].exprVal))){
                                            if((yyvsp[-2].exprVal)->type==costnum_e && (yyvsp[0].exprVal)->type==costnum_e)
                                                (yyval.exprVal)=newexpr(costnum_e);
                                            else
                                                (yyval.exprVal)=newexpr(arithexpr_e); 
                                            (yyval.exprVal)->sym=newtemp(scope,yylineno); 
                                             emit(mod,(yyvsp[-2].exprVal),(yyvsp[0].exprVal),(yyval.exprVal),nextquadlabel(),yylineno);}}
#line 1645 "parser.c"
    break;

  case 24: /* expr: expr GREATER expr  */
#line 319 "parser.y"
                                            {(yyval.exprVal)=newexpr(boolexpr_e); (yyval.exprVal)->sym=newtemp(scope,yylineno); 
                                            
                                            (yyval.exprVal)->truelist=makelist(nextquadlabel());
                                            (yyval.exprVal)->falselist=makelist(nextquadlabel()+1);
                                            emit(if_greater ,(yyvsp[-2].exprVal),(yyvsp[0].exprVal),0,currQuad+3,yylineno); 
                                            emit(jump       ,NULL,NULL,0,currQuad+3,yylineno);
                                            
                                            /*emit(assign     ,newexpr_constbool(0),NULL,$$,nextquadlabel(),yylineno);
                                            emit(jump       ,NULL,NULL,0,currQuad+2,yylineno);
                                            emit(assign     ,newexpr_constbool(1),NULL,$$,nextquadlabel(),yylineno);
                                            */}
#line 1661 "parser.c"
    break;

  case 25: /* expr: expr GREATEREQUAL expr  */
#line 330 "parser.y"
                                            {(yyval.exprVal)=newexpr(boolexpr_e); (yyval.exprVal)->sym=newtemp(scope,yylineno); 
                                            
                                            (yyval.exprVal)->truelist=makelist(nextquadlabel());
                                            (yyval.exprVal)->falselist=makelist(nextquadlabel()+1);
                                            emit(if_greatereq,(yyvsp[-2].exprVal),(yyvsp[0].exprVal),0,currQuad+3,yylineno);
                                            emit(jump       ,NULL,NULL,0,currQuad,yylineno);
                                            
                                            /*emit(assign     ,newexpr_constbool(0),NULL,$$,nextquadlabel(),yylineno);
                                             emit(jump       ,NULL,NULL,0,currQuad+2,yylineno);
                                             emit(assign     ,newexpr_constbool(1),NULL,$$,nextquadlabel(),yylineno);
                                            */}
#line 1677 "parser.c"
    break;

  case 26: /* expr: expr LESS expr  */
#line 341 "parser.y"
                                            {(yyval.exprVal)=newexpr(boolexpr_e); (yyval.exprVal)->sym=newtemp(scope,yylineno); 
                                            
                                            (yyval.exprVal)->truelist=makelist(nextquadlabel());
                                            (yyval.exprVal)->falselist=makelist(nextquadlabel()+1);
                                            emit(if_less,(yyvsp[-2].exprVal),(yyvsp[0].exprVal),0,currQuad+3,yylineno);
                                            emit(jump       ,NULL,NULL,0,currQuad+3,yylineno);
                                            
                                            /*emit(assign     ,newexpr_constbool(0),NULL,$$,nextquadlabel(),yylineno);
                                            emit(jump       ,NULL,NULL,0,currQuad+2,yylineno);
                                            emit(assign     ,newexpr_constbool(1),NULL,$$,nextquadlabel(),yylineno);
                                            */}
#line 1693 "parser.c"
    break;

  case 27: /* expr: expr LESSEQUAL expr  */
#line 352 "parser.y"
                                            {(yyval.exprVal)=newexpr(boolexpr_e); (yyval.exprVal)->sym=newtemp(scope,yylineno); 
                                            
                                            (yyval.exprVal)->truelist=makelist(nextquadlabel());
                                            (yyval.exprVal)->falselist=makelist(nextquadlabel()+1);
                                            emit(if_lesseq,(yyvsp[-2].exprVal),(yyvsp[0].exprVal),0,currQuad+3,yylineno);
                                            emit(jump       ,NULL,NULL,0,currQuad+3,yylineno);
                                            
                                            /*emit(assign     ,newexpr_constbool(0),NULL,$$,nextquadlabel(),yylineno);
                                            emit(jump       ,NULL,NULL,0,currQuad+2,yylineno);
                                            emit(assign     ,newexpr_constbool(1),NULL,$$,nextquadlabel(),yylineno);
                                            */}
#line 1709 "parser.c"
    break;

  case 28: /* expr: expr EQUALITY expr  */
#line 363 "parser.y"
                                            {(yyval.exprVal)=newexpr(boolexpr_e); (yyval.exprVal)->sym=newtemp(scope,yylineno); 
                                            
                                            (yyval.exprVal)->truelist=makelist(nextquadlabel());
                                            (yyval.exprVal)->falselist=makelist(nextquadlabel()+1);
                                            emit(if_eq ,(yyvsp[-2].exprVal),(yyvsp[0].exprVal),0,currQuad+3,yylineno); 
                                            emit(jump       ,NULL,NULL,0,currQuad+3,yylineno);
                                            
                                            /*emit(assign     ,newexpr_constbool(0),NULL,$$,nextquadlabel(),yylineno);
                                            emit(jump       ,NULL,NULL,0,currQuad+2,yylineno);
                                            emit(assign     ,newexpr_constbool(1),NULL,$$,nextquadlabel(),yylineno);
                                            */}
#line 1725 "parser.c"
    break;

  case 29: /* expr: expr NOTEQUAL expr  */
#line 374 "parser.y"
                                            {(yyval.exprVal)=newexpr(boolexpr_e); (yyval.exprVal)->sym=newtemp(scope,yylineno); 
                                            
                                            (yyval.exprVal)->truelist=makelist(nextquadlabel());
                                            (yyval.exprVal)->falselist=makelist(nextquadlabel()+1);
                                            emit(if_noteq,(yyvsp[-2].exprVal),(yyvsp[0].exprVal),0,currQuad+3,yylineno);
                                            emit(jump       ,NULL,NULL,0,currQuad,yylineno);
                                            
                                            /*emit(assign     ,newexpr_constbool(0),NULL,$$,nextquadlabel(),yylineno);
                                            emit(jump       ,NULL,NULL,0,currQuad+2,yylineno);
                                            emit(assign     ,newexpr_constbool(1),NULL,$$,nextquadlabel(),yylineno);
                                            */}
#line 1741 "parser.c"
    break;

  case 30: /* expr: expr AND M expr  */
#line 385 "parser.y"
                                              {(yyval.exprVal)=newexpr(boolexpr_e); (yyval.exprVal)->sym=newtemp(scope,yylineno); 
                                             backpatch((yyvsp[-3].exprVal)->falselist,(yyvsp[-1].uns));
                                            (yyval.exprVal)->truelist=(yyvsp[0].exprVal)->truelist;
                                            (yyval.exprVal)->falselist=merge((yyvsp[-3].exprVal)->falselist,(yyvsp[0].exprVal)->falselist);
                                            emit(and,(yyvsp[-3].exprVal),(yyvsp[0].exprVal),(yyval.exprVal),nextquadlabel(),yylineno);
                                            }
#line 1752 "parser.c"
    break;

  case 31: /* expr: expr OR M expr  */
#line 391 "parser.y"
                                              {(yyval.exprVal)=newexpr(boolexpr_e); (yyval.exprVal)->sym=newtemp(scope,yylineno); 
                                            backpatch((yyvsp[-3].exprVal)->falselist,(yyvsp[-1].uns));
                                            (yyval.exprVal)->truelist=merge((yyvsp[-3].exprVal)->truelist,(yyvsp[0].exprVal)->truelist);
                                            (yyval.exprVal)->falselist=(yyvsp[0].exprVal)->truelist;
                                            emit(or,(yyvsp[-3].exprVal),(yyvsp[0].exprVal),(yyval.exprVal),nextquadlabel(),yylineno);
                                            }
#line 1763 "parser.c"
    break;

  case 32: /* expr: term  */
#line 397 "parser.y"
                      {(yyval.exprVal)=(yyvsp[0].exprVal);  }
#line 1769 "parser.c"
    break;

  case 33: /* term: L_PARENTHESIS expr R_PARENTHESIS  */
#line 401 "parser.y"
                                                { (yyval.exprVal)=(yyvsp[-1].exprVal);}
#line 1775 "parser.c"
    break;

  case 34: /* term: SUB expr  */
#line 403 "parser.y"
                         {
                                    check_arith((yyvsp[0].exprVal));
                                    (yyval.exprVal)=newexpr(arithexpr_e); 
                                    (yyval.exprVal)->sym = istempexpr((yyvsp[0].exprVal)) ? (yyvsp[0].exprVal)->sym : newtemp(scope,yylineno);
                                    
                                    emit(uminus,(yyvsp[0].exprVal), NULL, (yyval.exprVal),nextquadlabel(),yylineno);
                                    }
#line 1787 "parser.c"
    break;

  case 35: /* term: NOT expr  */
#line 411 "parser.y"
                                    {
                                    check_arith((yyvsp[0].exprVal));
                                    (yyval.exprVal)=newexpr(arithexpr_e); 
                                    (yyval.exprVal)->sym=newtemp(scope,yylineno);
                                    emit(not,(yyvsp[0].exprVal),NULL,(yyval.exprVal),nextquadlabel(),yylineno);
                                
                                    }
#line 1799 "parser.c"
    break;

  case 36: /* term: ADDITY lvalue  */
#line 419 "parser.y"
                                    {
                                    if(id_Func)printf("Error using func as an lvalue |line:%d\n",yylineno);is_func=0;
                                    
                                    check_arith((yyvsp[0].exprVal));
                                    if ((yyvsp[0].exprVal)->type == tableitem_e) {

                                    (yyval.exprVal) = emit_iftableitem((yyvsp[0].exprVal),scope,yylineno);
                                    emit(add, (yyval.exprVal), newexpr_constnum(1), (yyval.exprVal),nextquadlabel(),yylineno);
                                    emit(tablesetelem, (yyval.exprVal), (yyvsp[0].exprVal)->index, (yyvsp[0].exprVal),nextquadlabel(),yylineno);


                                    }
                                    else {

                                    emit(add, (yyvsp[0].exprVal), newexpr_constnum(1), (yyvsp[0].exprVal),nextquadlabel(),yylineno);
                                    (yyval.exprVal)=newexpr(arithexpr_e); 
                                    (yyval.exprVal)->sym=newtemp(scope,yylineno);
                                    
                                    emit(assign, (yyvsp[0].exprVal), NULL, (yyval.exprVal),nextquadlabel(),yylineno);
                                     
                                    }
                                    

                                    }
#line 1828 "parser.c"
    break;

  case 37: /* term: lvalue ADDITY  */
#line 443 "parser.y"
                                    {
                                    if(id_Func)printf("Error using func as an lvalue |line:%d\n",yylineno);is_func=0;
                                   
                                    check_arith((yyvsp[-1].exprVal));
                                    (yyval.exprVal)=newexpr(var_e);  
                                    (yyval.exprVal)->sym=newtemp(scope,yylineno); 
                                    
                                    if ((yyvsp[-1].exprVal)->type == tableitem_e) {
                                    expr* val = emit_iftableitem((yyvsp[-1].exprVal),scope,yylineno);
                                    emit(assign, val, NULL, (yyval.exprVal),nextquadlabel(),yylineno);
                                    emit(add, val, newexpr_constnum(1), val,nextquadlabel(),yylineno);
                                    emit(tablesetelem, val, (yyvsp[-1].exprVal)->index, (yyvsp[-1].exprVal),nextquadlabel(),yylineno);
                                    }
                                    else {
                                    emit(assign, (yyvsp[-1].exprVal), NULL, (yyval.exprVal),nextquadlabel(),yylineno);
                                    emit(add, (yyvsp[-1].exprVal), newexpr_constnum(1), (yyvsp[-1].exprVal),nextquadlabel(),yylineno);
                                    }
                                   
                                    
                                    }
#line 1853 "parser.c"
    break;

  case 38: /* term: MULTITY lvalue  */
#line 464 "parser.y"
                                    {
                                    if(id_Func)printf("Error using func as an lvalue |line:%d\n",yylineno);is_func=0;
                                   
                                    check_arith((yyvsp[0].exprVal));
                                     if ((yyvsp[0].exprVal)->type == tableitem_e) {

                                    (yyval.exprVal) = emit_iftableitem((yyvsp[0].exprVal),scope,yylineno);
                                    emit(sub, (yyval.exprVal), newexpr_constnum(1), (yyval.exprVal),nextquadlabel(),yylineno);
                                    emit(tablesetelem, (yyval.exprVal), (yyvsp[0].exprVal)->index, (yyvsp[0].exprVal),nextquadlabel(),yylineno);


                                    }
                                    else {

                                    emit(sub, (yyvsp[0].exprVal), newexpr_constnum(1), (yyvsp[0].exprVal),nextquadlabel(),yylineno);
                                    (yyval.exprVal)=newexpr(arithexpr_e); 
                                    (yyval.exprVal)->sym=newtemp(scope,yylineno);
                                    
                                    emit(assign, (yyvsp[0].exprVal), NULL, (yyval.exprVal),nextquadlabel(),yylineno);
                                    
                                    }
                                    
                                   
                                    }
#line 1882 "parser.c"
    break;

  case 39: /* term: lvalue MULTITY  */
#line 489 "parser.y"
                                    {
                                    if(id_Func)printf("Error using func as an lvalue |line:%d\n",yylineno);is_func=0;
                                    
                                    check_arith((yyvsp[-1].exprVal));
                                    (yyval.exprVal)=newexpr(arithexpr_e); 
                                    (yyval.exprVal)->sym=newtemp(scope,yylineno); 

                                     if ((yyvsp[-1].exprVal)->type == tableitem_e) {
                                    expr* val = emit_iftableitem((yyvsp[-1].exprVal),scope,yylineno);
                                    emit(assign, val, NULL, (yyval.exprVal),nextquadlabel(),yylineno);
                                    emit(sub, val, newexpr_constnum(1), val,nextquadlabel(),yylineno);
                                      emit(tablesetelem, val, (yyvsp[-1].exprVal)->index, (yyvsp[-1].exprVal),nextquadlabel(),yylineno);
                                    }
                                    else {
                                    emit(assign, (yyvsp[-1].exprVal), NULL, (yyval.exprVal),nextquadlabel(),yylineno);
                                    emit(sub, (yyvsp[-1].exprVal), newexpr_constnum(1), (yyvsp[-1].exprVal),nextquadlabel(),yylineno);
                                    }
                                   
                                    
                                    }
#line 1907 "parser.c"
    break;

  case 40: /* term: primary  */
#line 509 "parser.y"
                         { (yyval.exprVal)=(yyvsp[0].exprVal); }
#line 1913 "parser.c"
    break;

  case 41: /* $@2: %empty  */
#line 512 "parser.y"
                       {		if(id_Func==1){
                                   printf("Error using func as an lvalue |line:%d\n",yylineno);
                                    id_Func=0;
                                   }
						
                     
				}
#line 1925 "parser.c"
    break;

  case 42: /* $@3: %empty  */
#line 518 "parser.y"
                                       {eq==1;}
#line 1931 "parser.c"
    break;

  case 43: /* assiginexpr: lvalue $@2 EQUAL $@3 expr  */
#line 518 "parser.y"
                                                      {
                  
                    if ((yyvsp[-4].exprVal)->type == tableitem_e ) {
                     
                            emit(tablesetelem,(yyvsp[-4].exprVal)->index,(yyvsp[0].exprVal),(yyvsp[-4].exprVal),nextquadlabel(),yylineno);
                            (yyval.exprVal) = emit_iftableitem((yyvsp[-4].exprVal),scope,yylineno);
                            (yyval.exprVal)->type = assignexpr_e;
                    }else {
                            emit(assign,NULL,(yyvsp[0].exprVal),(yyvsp[-4].exprVal),nextquadlabel(),yylineno);
                            (yyval.exprVal) = newexpr(assignexpr_e);
                            (yyval.exprVal)->sym = newtemp(scope,yylineno);
                            emit(assign, NULL, (yyvsp[-4].exprVal), (yyval.exprVal),nextquadlabel(),yylineno);
                    }
                }
#line 1950 "parser.c"
    break;

  case 44: /* primary: lvalue  */
#line 534 "parser.y"
                       { (yyval.exprVal) = emit_iftableitem((yyvsp[0].exprVal),scope,yylineno); }
#line 1956 "parser.c"
    break;

  case 45: /* primary: call  */
#line 535 "parser.y"
                       { (yyval.exprVal)=(yyvsp[0].exprVal);}
#line 1962 "parser.c"
    break;

  case 46: /* primary: objectdef  */
#line 536 "parser.y"
                           {(yyval.exprVal)=(yyvsp[0].exprVal);  }
#line 1968 "parser.c"
    break;

  case 47: /* primary: L_PARENTHESIS funcdef R_PARENTHESIS  */
#line 537 "parser.y"
                                                      {
                    (yyval.exprVal) = newexpr(programfunc_e);
                    (yyval.exprVal)->sym = (yyvsp[-1].exprVal)->sym;
                }
#line 1977 "parser.c"
    break;

  case 48: /* primary: const  */
#line 541 "parser.y"
                       {(yyval.exprVal)=(yyvsp[0].exprVal); }
#line 1983 "parser.c"
    break;

  case 49: /* lvalue: ID  */
#line 546 "parser.y"
                  {   
                          if(searchScope((yyvsp[0].stringValue),scope)!=NULL){
                              (yyval.exprVal)=lvalue_expr(searchScope((yyvsp[0].stringValue),scope));
                          }
                    
                              
                        if(searchScope((yyvsp[0].stringValue),scope)!=NULL){/*exists in current scope*/
                            if(searchScope((yyvsp[0].stringValue),scope)->type==LIBFUNC ||searchScope((yyvsp[0].stringValue),scope)->type==USERFUNC){
                                id_Func=1;
                            }  
                        }
                        if(searchScope((yyvsp[0].stringValue),0)!=NULL){
                            if(searchScope((yyvsp[0].stringValue),0)->type==LIBFUNC ){
                                
                               (yyval.exprVal) = newexpr(libraryfunc_e);
                               (yyval.exprVal)->strConst=(yyvsp[0].stringValue);
                            }  
                        }
                         if(searchScope((yyvsp[0].stringValue),0)!=NULL){
                            if(searchScope((yyvsp[0].stringValue),0)->type==USERFUNC ){
                                
                               (yyval.exprVal) = newexpr(programfunc_e);
                               (yyval.exprVal)->strConst=(yyvsp[0].stringValue);
                            }  
                        }
                        if(searchScope((yyvsp[0].stringValue),0)!=NULL){
                             
                             
                                (yyval.exprVal) = newexpr(var_e);
                                (yyval.exprVal)->strConst=(yyvsp[0].stringValue);
                              
                        }

                        func=searchScope((yyvsp[0].stringValue),0);
                        if(scope==0 && searchScope((yyvsp[0].stringValue),scope)==NULL){/*isglobal*/

                            insertElemVariable(GLOBAL,(yyvsp[0].stringValue),scope,yylineno, currscopespace(),currscopeoffset()+arrayLocals[isFunc]);
                            (yyval.exprVal)=lvalue_expr(searchScope((yyvsp[0].stringValue),scope));
                            
                            inccurrscopeoffset();
                        }else if(scope!=0  && searchScope((yyvsp[0].stringValue),0)==NULL ){/*not global, doesnt exist in scope 0*/
                            int check=0;

                            for(int k=1; k<=scope; k++){
                              

                                if((searchScope((yyvsp[0].stringValue),k)!=NULL && (isFunc && inloop==0))||(searchScope((yyvsp[0].stringValue),k)!=NULL && (isFunc==0 && inloop==1))){/*if it finds it*/
                                    check=1;

                                    if(isFunc>1 && returned==0 && searchScope((yyvsp[0].stringValue),k)->type!=LIBFUNC && searchScope((yyvsp[0].stringValue),k)->type!=USERFUNC && searchScope((yyvsp[0].stringValue),k)->type!=FORMAL)
                                        printf("1 Error Cannot access %s inside function |line %d\n",(yyvsp[0].stringValue),yylineno);
                                    func=searchScope((yyvsp[0].stringValue),k);
                                    
                                    if((func->type==GLOBAL|| func->type == LOCALL || func->type == FORMAL) ){
                                        if(returned==0 && inloop==0 && inIf==0 && foonk==0){
                                           

                                            if(searchScope((yyvsp[0].stringValue),k)->type !=LOCALL && searchScope((yyvsp[0].stringValue),k)->type !=FORMAL  ){
                                            
                                               printf("Error:already exist at scope: %d |line: %d\n",k,yylineno); }
                                                    
                                        } 
                                        
                                    }
                                        
                                }else if(searchScope((yyvsp[0].stringValue),k)!=NULL ){/*not a func*/
                                    check=1;
                                    printf("Is refering at previus %s at line: %d\n",(yyvsp[0].stringValue),yylineno);
                                   ;
                                }else if(searchScope((yyvsp[0].stringValue),k)==NULL){
                                            for(int l=k; l>=1; l--){
                                                if(searchScope((yyvsp[0].stringValue),l)!=NULL &&searchScope((yyvsp[0].stringValue),l)->type==FORMAL){
                                                  
                                                     printf("Error:already exist at scope: %d |line: %d\n",l,yylineno); 
                                                }
                                            }   
                                        }
                            }
                            if(check==0 ){
                              
                                        if(searchScope((yyvsp[0].stringValue),scope)!=NULL){

                                        } /*printf("token:%s at scope:%d at line:%d \n",$1,scope,yylineno);*/
                                        
                                        insertElemVariable(LOCALL,(yyvsp[0].stringValue),scope,yylineno,currscopespace(),currscopeoffset()+arrayLocals[isFunc] );
                                        (yyval.exprVal)=lvalue_expr(searchScope((yyvsp[0].stringValue),scope));
                                        inccurrscopeoffset();
                                    check=0;
                            }
                            
                        }else if(scope!=0  && searchScope((yyvsp[0].stringValue),0)!=NULL ){/*not global ,exists scope 0*/
                            if(isFunc>1 && returned==0 && searchScope((yyvsp[0].stringValue),0)->type!=LIBFUNC )
                              /*  printf("2 Error Cannot access %s inside function |line %d\n",$1,yylineno); */

                            for(int k=1; k<=scope; k++){
                              if(searchScope((yyvsp[0].stringValue),k)!=NULL)  {
                                if(isFunc>1 && returned==1 && searchScope((yyvsp[0].stringValue),k)->type!=LIBFUNC &&searchScope((yyvsp[0].stringValue),k)->type!=USERFUNC)
                                    printf("3 Error Cannot access %s inside function |line %d\n",(yyvsp[0].stringValue),yylineno); 
                                }
                            }
                            
                            if(func->type==GLOBAL|| func->type == LOCALL || func->type == FORMAL  ){
                               
                            }else if(returned == 0 && !func->type == LIBFUNC){
                                is_func=1;
                                
                                printf("Error: cannot access %s inside Function at scope:%d in line:%d\n",(yyvsp[0].stringValue),scope,yylineno);
                            }/*else if(returned==1){
                                is_func=1;printf("2      \n");
                                }*/
                        }else  if((scope==0  && searchScope((yyvsp[0].stringValue),0)!=NULL)&&(func->type==USERFUNC ||func->type==LIBFUNC) ){
                                (yyval.exprVal)=lvalue_expr(searchScope((yyvsp[0].stringValue),scope));
                               is_func=1;
                              
                        }else{
                            (yyval.exprVal)=lvalue_expr(searchScope((yyvsp[0].stringValue),scope));
                            
                          
                        }
                        
                }
#line 2109 "parser.c"
    break;

  case 50: /* lvalue: LOCAL ID  */
#line 667 "parser.y"
                           {
                   
                    if(searchScope((yyvsp[0].stringValue),scope)==NULL ){
                        if( (varfunc=searchScope((yyvsp[0].stringValue),0) )!=NULL){/*exists in scope 0*/
                            if(varfunc->type==LIBFUNC){
                                    printf("Error:Trying to shadow libfunc in line:%d\n",yylineno);
                                     (yyval.exprVal)=lvalue_expr(searchScope((yyvsp[0].stringValue),scope));
                            }
                           else {
                            insertElemVariable(LOCALL,(yyvsp[0].stringValue),scope,yylineno, currscopespace(),currscopeoffset()+arrayLocals[isFunc]);
                            (yyval.exprVal)=lvalue_expr(searchScope((yyvsp[0].stringValue),scope));
                            inccurrscopeoffset();
                            }
                    
                    } else if(scope==0){
                                    
                            insertElemVariable(GLOBAL,(yyvsp[0].stringValue),scope,yylineno, currscopespace(),currscopeoffset()+arrayLocals[isFunc]);
                            (yyval.exprVal)=lvalue_expr(searchScope((yyvsp[0].stringValue),scope));
                            inccurrscopeoffset();
                        }else{
                            insertElemVariable(LOCALL,(yyvsp[0].stringValue),scope,yylineno, currscopespace(),currscopeoffset()+arrayLocals[isFunc]);
                            (yyval.exprVal)=lvalue_expr(searchScope((yyvsp[0].stringValue),scope));
                            inccurrscopeoffset();
                        }
                    }else { 
                            (yyval.exprVal)=lvalue_expr(searchScope((yyvsp[0].stringValue),scope));
                            
                    }   
                }
#line 2143 "parser.c"
    break;

  case 51: /* lvalue: DOUBLECOLON ID  */
#line 698 "parser.y"
                                {
                if(searchScope((yyvsp[0].stringValue),0)!=NULL){
                            if(searchScope((yyvsp[0].stringValue),0)->type==LIBFUNC ){
                               
                               (yyval.exprVal) = newexpr(libraryfunc_e);
                               (yyval.exprVal)->strConst=(yyvsp[0].stringValue);
                            }  
                        }
                if(searchScope((yyvsp[0].stringValue),scope)!=NULL){
                    (yyval.exprVal)=lvalue_expr(searchScope((yyvsp[0].stringValue),scope));
                }
                    if(searchScope((yyvsp[0].stringValue),0)!=NULL){
                        printf("Found Globaly at line:%d\n",yylineno);
                    }else{
                        printf("Error, undefined global variable %s in line:%d\n",(yyvsp[0].stringValue),yylineno);
                    }
                }
#line 2165 "parser.c"
    break;

  case 52: /* lvalue: member  */
#line 715 "parser.y"
                        {(yyval.exprVal)=(yyvsp[0].exprVal);}
#line 2171 "parser.c"
    break;

  case 53: /* member: lvalue DOT ID  */
#line 718 "parser.y"
                             {(yyval.exprVal) = member_item((yyvsp[-2].exprVal),(yyvsp[0].stringValue),scope,yylineno);}
#line 2177 "parser.c"
    break;

  case 54: /* member: lvalue SQBRACKETOPEN expr SQBRACKETCLOSE  */
#line 719 "parser.y"
                                                          { 
                    (yyvsp[-3].exprVal) = emit_iftableitem((yyvsp[-3].exprVal),scope,yylineno);
                    (yyval.exprVal) = newexpr(tableitem_e);
                    (yyval.exprVal)->sym = (yyvsp[-3].exprVal)->sym;
                    (yyval.exprVal)->index = (yyvsp[-1].exprVal);
                }
#line 2188 "parser.c"
    break;

  case 55: /* member: call DOT ID  */
#line 725 "parser.y"
                             { (yyval.exprVal)->strConst=(yyvsp[0].stringValue);}
#line 2194 "parser.c"
    break;

  case 56: /* member: call SQBRACKETOPEN expr SQBRACKETCLOSE  */
#line 726 "parser.y"
                                                         { (yyval.exprVal)=(yyvsp[-1].exprVal);}
#line 2200 "parser.c"
    break;

  case 57: /* $@4: %empty  */
#line 729 "parser.y"
                                  {  id_Func=0;}
#line 2206 "parser.c"
    break;

  case 58: /* call: call L_PARENTHESIS $@4 elist R_PARENTHESIS  */
#line 730 "parser.y"
                    { 
                    if((yyvsp[-1].exprVal))
                        rearrangeAndReverse(&(yyvsp[-1].exprVal));
                    (yyval.exprVal) = make_call((yyvsp[-4].exprVal), (yyvsp[-1].exprVal),scope,yylineno); 
                   }
#line 2216 "parser.c"
    break;

  case 59: /* call: lvalue callsuffix  */
#line 735 "parser.y"
                                   { 
                   
                    id_Func=0;
                    (yyvsp[-1].exprVal) = emit_iftableitem((yyvsp[-1].exprVal),scope,yylineno); 
                    if ((yyvsp[0].call_s).method ){ 
                        
                        expr* t = (yyvsp[-1].exprVal); 
                      
                        (yyvsp[-1].exprVal) = emit_iftableitem(member_item(t, (yyvsp[0].call_s).name,scope,yylineno),scope,yylineno);
                        if((yyvsp[0].call_s).elist)
                            rearrangeAndReverse(&(yyvsp[0].call_s).elist);
                        expr* oof=(yyvsp[0].call_s).elist;
                        if(oof){ 
                            while( oof->next!=NULL){
                                oof=oof->next;
                            }
                            

                            oof->next= t;  
                        }
                       
                    }
                    if((yyvsp[0].call_s).elist){
                        rearrangeAndReverse(&(yyvsp[0].call_s).elist);
                    }
                    
                    (yyval.exprVal) = make_call((yyvsp[-1].exprVal), (yyvsp[0].call_s).elist,scope,yylineno);

                }
#line 2250 "parser.c"
    break;

  case 60: /* $@5: %empty  */
#line 764 "parser.y"
                                                                    {  id_Func=0;}
#line 2256 "parser.c"
    break;

  case 61: /* call: L_PARENTHESIS funcdef R_PARENTHESIS L_PARENTHESIS $@5 elist R_PARENTHESIS  */
#line 765 "parser.y"
                 {
                    expr* func = newexpr(programfunc_e);
                    func->sym = (yyvsp[-5].exprVal)->sym;
                     rearrangeAndReverse(&(yyvsp[-1].exprVal));
                    (yyval.exprVal) = make_call(func, (yyvsp[-1].exprVal),scope,yylineno);
                }
#line 2267 "parser.c"
    break;

  case 62: /* callsuffix: normcall  */
#line 773 "parser.y"
                        {
                
                (yyval.call_s)=(yyvsp[0].call_s);
              
                }
#line 2277 "parser.c"
    break;

  case 63: /* callsuffix: methodcall  */
#line 778 "parser.y"
                            {
            
                (yyval.call_s)=(yyvsp[0].call_s);}
#line 2285 "parser.c"
    break;

  case 64: /* $@6: %empty  */
#line 783 "parser.y"
                             {foonk==1;}
#line 2291 "parser.c"
    break;

  case 65: /* normcall: L_PARENTHESIS $@6 elist R_PARENTHESIS  */
#line 783 "parser.y"
                                                            {foonk=0;

                
                (yyval.call_s).elist= (yyvsp[-1].exprVal);
                (yyval.call_s).method = 0;
                (yyval.call_s).name = NULL;

              
              
                }
#line 2306 "parser.c"
    break;

  case 66: /* methodcall: DOUBLEDOT ID L_PARENTHESIS elist R_PARENTHESIS  */
#line 796 "parser.y"
                {
                (yyval.call_s).elist= (yyvsp[-1].exprVal); 
                (yyval.call_s).method = 1;
                (yyval.call_s).name = (yyvsp[-3].stringValue);
                }
#line 2316 "parser.c"
    break;

  case 67: /* elist: expr  */
#line 804 "parser.y"
                     { (yyval.exprVal)=(yyvsp[0].exprVal);}
#line 2322 "parser.c"
    break;

  case 68: /* elist: expr COMMA elist  */
#line 805 "parser.y"
                                         { 
                    (yyval.exprVal)->next=(yyvsp[0].exprVal);
            }
#line 2330 "parser.c"
    break;

  case 69: /* elist: %empty  */
#line 808 "parser.y"
             { (yyval.exprVal)=NULL;}
#line 2336 "parser.c"
    break;

  case 70: /* objectdef: SQBRACKETOPEN elist SQBRACKETCLOSE  */
#line 813 "parser.y"
                {   
                        expr* t = newexpr(newtable_e);
                        t->sym = newtemp(scope,yylineno);
                        
                        emit(tablecreate, t, NULL, NULL,nextquadlabel(),yylineno);
                        if((yyvsp[-1].exprVal)!=NULL){
                                  for(int i = 0; (yyvsp[-1].exprVal); (yyvsp[-1].exprVal) = (yyvsp[-1].exprVal)->next)
                                      emit(tablesetelem, (yyvsp[-1].exprVal), newexpr_constnum(i++), t,nextquadlabel(),yylineno);
                        }                         
                         (yyval.exprVal)= t;
                }
#line 2352 "parser.c"
    break;

  case 71: /* objectdef: SQBRACKETOPEN indexed SQBRACKETCLOSE  */
#line 824 "parser.y"
                                                       {
                    expr* t = newexpr(newtable_e);
                    t->sym = newtemp(scope,yylineno);
                    
                    emit(tablecreate, t, NULL, NULL,nextquadlabel(),yylineno);

                    if((yyvsp[-1].exprVal)->next!=NULL){
                      
                    }
                  
             
                   while((yyvsp[-1].exprVal)){
                        emit(tablesetelem,(yyvsp[-1].exprVal), (yyvsp[-1].exprVal)->index,t,nextquadlabel(),yylineno);
                        
                        (yyvsp[-1].exprVal)= (yyvsp[-1].exprVal)->next;          
                    }
                    
                          
                    (yyval.exprVal) = t;
                }
#line 2377 "parser.c"
    break;

  case 72: /* indexed: BRACEOPEN expr COLON expr BRACECLOSE COMMA indexed  */
#line 847 "parser.y"
                                                                  {  (yyval.exprVal)=(yyvsp[-5].exprVal);  (yyval.exprVal)->index=(yyvsp[-3].exprVal);  (yyval.exprVal)->next=(yyvsp[0].exprVal); }
#line 2383 "parser.c"
    break;

  case 73: /* indexed: BRACEOPEN expr COLON expr BRACECLOSE  */
#line 848 "parser.y"
                                                      { (yyval.exprVal)=(yyvsp[-3].exprVal); (yyval.exprVal)->index=(yyvsp[-1].exprVal);  }
#line 2389 "parser.c"
    break;

  case 74: /* $@7: %empty  */
#line 854 "parser.y"
                         {scope++;
                    
                
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

                }
#line 2412 "parser.c"
    break;

  case 75: /* block: BRACEOPEN $@7 stmt_list BRACECLOSE  */
#line 871 "parser.y"
                                      {
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
                     
                    (yyval.stmt_t).contList=(yyvsp[-1].stmt_t).contList;
                    (yyval.stmt_t).breakList=(yyvsp[-1].stmt_t).breakList;
                    
                    }
#line 2443 "parser.c"
    break;

  case 76: /* @8: %empty  */
#line 899 "parser.y"
                            { 
                    topFunc(whilestack,whiletop);

                    iaddress= nextquadlabel(); 


                    if (searchScope((yyvsp[0].stringValue),scope)==NULL){
                            if( (varfunc=searchScope((yyvsp[0].stringValue),0) )!=NULL){/*exists in scope 0*/
                                if(varfunc->type==LIBFUNC){
                                        printf("Error:Trying to shadow libfunc in line:%d\n",yylineno);
                                }else if(varfunc!=NULL){
                                }else{
                                    printf("Error: %s exists in line:%d\n",(yyvsp[0].stringValue),yylineno);
                                }
                            }

                            
                            push((yyvsp[0].stringValue),top);
                            top++;

                            insertElemFunction(USERFUNC,top_name(top),scope,yylineno,functionlocals,iaddress); 

                            if(searchScope(top_name(top),scope)!=NULL){
                            (yyval.exprVal)=lvalue_expr(searchScope(top_name(top),scope));
                            (yyval.exprVal)->sym->value.funcVal->iaddress = nextquadlabel(); 
                            emit(funcstart, NULL, NULL, (yyval.exprVal),nextquadlabel(),yylineno);
                            }
                          
                            print_stack(top);

                           
                    }else{
                        func=searchScope((yyvsp[0].stringValue),scope);
                        if(func->type==GLOBAL|| func->type == LOCALL || func->type == FORMAL){
                            printf("Error: %s is a var in line:%d\n",(yyvsp[0].stringValue),yylineno);
                        }else if(func->type==LIBFUNC){
                                        printf("Error:Trying to shadow libfunc in line:%d\n",yylineno);
                        }else{
                            printf("Error:already exist in the function /%s/ in line%d\n",(yyvsp[0].stringValue),yylineno);
                        }
                    }
                           
                }
#line 2491 "parser.c"
    break;

  case 77: /* $@9: %empty  */
#line 941 "parser.y"
                               {isFunc++; enterscopespace();}
#line 2497 "parser.c"
    break;

  case 78: /* $@10: %empty  */
#line 941 "parser.y"
                                                                                  {restorecurrscopeoffset(currscopespace()); resetformalargsoffet();enterscopespace();
                 
                }
#line 2505 "parser.c"
    break;

  case 79: /* funcdef: FUNCTION ID @8 L_PARENTHESIS $@9 idlist R_PARENTHESIS $@10 block  */
#line 944 "parser.y"
                      {
                { 
                  
                    
                  }
                     (yyval.exprVal)=lvalue_expr(searchScope(top_name(top),scope));
                    emit(funcend, NULL, NULL, (yyval.exprVal),nextquadlabel(),yylineno);
                
                    pop(top);
                    top--;
                    topCloseFunc(whilestack,whiletop);

                }
#line 2523 "parser.c"
    break;

  case 80: /* @11: %empty  */
#line 957 "parser.y"
                         { 
                    topFunc(whilestack,whiletop);
                   
                    iaddress= nextquadlabel(); 
                    
                    annonymous++;
                    
                    char* countStr = (char*)malloc(sizeof(annonymous) * 2); 
                    sprintf(countStr, "$%d", annonymous);

                    
                    push(countStr,top);
                    top++;
                    
                    insertElemFunction(USERFUNC,top_name(top),scope,yylineno,functionlocals,iaddress);
                    if(searchScope(top_name(top),scope)!=NULL){    
                        (yyval.exprVal)=lvalue_expr(searchScope(top_name(top),scope));
                        (yyval.exprVal)->sym->value.funcVal->iaddress = nextquadlabel(); 
                        emit(funcstart, NULL, NULL, (yyval.exprVal),nextquadlabel(),yylineno);
                    }
                                 
                     print_stack(top);
                  
                }
#line 2552 "parser.c"
    break;

  case 81: /* $@12: %empty  */
#line 980 "parser.y"
                                {isFunc++; enterscopespace();}
#line 2558 "parser.c"
    break;

  case 82: /* $@13: %empty  */
#line 980 "parser.y"
                                                                                   {  
                    restorecurrscopeoffset(currscopespace());
                    resetformalargsoffet(); 
                    enterscopespace();
                 
                    }
#line 2569 "parser.c"
    break;

  case 83: /* funcdef: FUNCTION @11 L_PARENTHESIS $@12 idlist R_PARENTHESIS $@13 block  */
#line 986 "parser.y"
                     { 
                {
                  
                    
                  }
                     (yyval.exprVal)=lvalue_expr(searchScope(top_name(top),scope));
                    emit(funcend, NULL,NULL, (yyval.exprVal), nextquadlabel(), yylineno);
                    
                    pop(top);
                    top--;
                    topCloseFunc(whilestack,whiletop);
                }
#line 2586 "parser.c"
    break;

  case 85: /* const: INT  */
#line 1001 "parser.y"
                    {
                    (yyval.exprVal)=newexpr(costnum_e);
                    (yyval.exprVal)->numConst=(yyvsp[0].intValue);
                }
#line 2595 "parser.c"
    break;

  case 86: /* const: REAL  */
#line 1005 "parser.y"
                      {
                    (yyval.exprVal)=newexpr(costnum_e);
                    (yyval.exprVal)->numConst=(yyvsp[0].doubleValue);
                }
#line 2604 "parser.c"
    break;

  case 87: /* const: STRING  */
#line 1009 "parser.y"
                        {
                   
                    (yyval.exprVal)=newexpr(conststring_e);
                    (yyval.exprVal)->strConst=(yyvsp[0].stringValue);
               
                }
#line 2615 "parser.c"
    break;

  case 88: /* const: NIL  */
#line 1015 "parser.y"
                      {
                    (yyval.exprVal)=newexpr(nil_e);
                    (yyval.exprVal)->numConst=0;
                }
#line 2624 "parser.c"
    break;

  case 89: /* const: TRUE  */
#line 1019 "parser.y"
                       {
                    (yyval.exprVal)=newexpr(constbool_e);
                    (yyval.exprVal)->boolConst=1;
                }
#line 2633 "parser.c"
    break;

  case 90: /* const: FALSE  */
#line 1023 "parser.y"
                       {
                    (yyval.exprVal)=newexpr(constbool_e);
                    (yyval.exprVal)->boolConst=0;
                }
#line 2642 "parser.c"
    break;

  case 91: /* idlist: ID  */
#line 1029 "parser.y"
                  { scope++;  
                    func=searchScope((yyvsp[0].stringValue),scope);
                    
                    if(searchScope((yyvsp[0].stringValue),scope)!=NULL ){
                  
                        if(func->type==FORMAL){ 
                         
                          insertElemVariable(FORMAL,(yyvsp[0].stringValue),scope,yylineno,currscopespace(),currscopeoffset()+arrayLocals[isFunc]);
                          (yyval.exprVal)=lvalue_expr(searchScope((yyvsp[0].stringValue),scope));
                          inccurrscopeoffset();
                        }

                    }else{
                        if(searchScope((yyvsp[0].stringValue),0)){
                            if(searchScope((yyvsp[0].stringValue),0)->type==LIBFUNC){
                                    printf("Error: Collision with %s library function,at scope:%d at line: %d\n",(yyvsp[0].stringValue),scope,yylineno);
                            }else{
                                    insertElemVariable(FORMAL,(yyvsp[0].stringValue),scope,yylineno,currscopespace(),currscopeoffset()+arrayLocals[isFunc]);
                                    (yyval.exprVal)=lvalue_expr(searchScope((yyvsp[0].stringValue),scope));
                                    inccurrscopeoffset();
                            }
                        }else if(searchScope((yyvsp[0].stringValue),scope)!=NULL){
                            printf("Error: Variable %s already defined at scope:%d at line %d.\n",(yyvsp[0].stringValue),scope,yylineno);

                        }else{
                            insertElemVariable(FORMAL,(yyvsp[0].stringValue),scope,yylineno, currscopespace(),currscopeoffset()+arrayLocals[isFunc]);
                            (yyval.exprVal)=lvalue_expr(searchScope((yyvsp[0].stringValue),scope));
                            inccurrscopeoffset();
                        }

                        
                    }  
                            
                    
                    scope--;  
                }
#line 2683 "parser.c"
    break;

  case 92: /* idlist: idlist COMMA ID  */
#line 1066 "parser.y"
                                {scope++;   

                        if(searchScope((yyvsp[0].stringValue),0)!=NULL){
                            if(searchScope((yyvsp[0].stringValue),0)->type==LIBFUNC){
                                    printf("Error: Collision with %s library function,at scope:%d at line: %d\n",(yyvsp[0].stringValue),scope,yylineno);
                            }else if(searchScope((yyvsp[0].stringValue),scope)!=NULL){
                            printf("Error: Variable %s already defined at scope:%d at line %d.\n",(yyvsp[0].stringValue),scope,yylineno);

                           }  else{
                            
                                   insertElemVariable(FORMAL,(yyvsp[0].stringValue),scope,yylineno, currscopespace(),currscopeoffset()+arrayLocals[isFunc]);
                                   (yyval.exprVal)=lvalue_expr(searchScope((yyvsp[0].stringValue),scope));
                                   inccurrscopeoffset();
                            }

                        }else if(searchScope((yyvsp[0].stringValue),scope)!=NULL){
                            printf("Error: Variable %s already defined at scope:%d at line %d.\n",(yyvsp[0].stringValue),scope,yylineno);

                        }else{

                           insertElemVariable(FORMAL,(yyvsp[0].stringValue),scope,yylineno,currscopespace(),currscopeoffset()+arrayLocals[isFunc]);
                           (yyval.exprVal)=lvalue_expr(searchScope((yyvsp[0].stringValue),scope));
                           inccurrscopeoffset();
                        }
                        
                     scope--;
                }
#line 2715 "parser.c"
    break;

  case 93: /* idlist: %empty  */
#line 1094 "parser.y"
                 {  (yyval.exprVal)=NULL;}
#line 2721 "parser.c"
    break;

  case 94: /* $@14: %empty  */
#line 1098 "parser.y"
                   {inIff=1;}
#line 2727 "parser.c"
    break;

  case 95: /* ifprefix: IF $@14 L_PARENTHESIS expr R_PARENTHESIS  */
#line 1098 "parser.y"
                                                              {
                    emit(if_eq,(yyvsp[-1].exprVal),newexpr_constbool(1),0,nextquadlabel()+2,yylineno);
                    (yyval.uns)=nextquadlabel();
                    emit(jump,NULL,NULL,0,currQuad,yylineno);
                }
#line 2737 "parser.c"
    break;

  case 96: /* elseprefix: ELSE  */
#line 1105 "parser.y"
                        {
                (yyval.uns)=nextquadlabel();
                emit(jump,NULL,NULL,0,currQuad,yylineno);
                }
#line 2746 "parser.c"
    break;

  case 97: /* ifstmt: ifprefix stmt  */
#line 1112 "parser.y"
                             {
                    inIff=0;
                    patchlabel((yyvsp[-1].uns),nextquadlabel());
                    (yyval.stmt_t).breakList=(yyvsp[0].stmt_t).breakList;    
                    (yyval.stmt_t).contList=(yyvsp[0].stmt_t).contList;                  
                }
#line 2757 "parser.c"
    break;

  case 98: /* ifstmt: ifprefix stmt elseprefix stmt  */
#line 1118 "parser.y"
                                               {
                    inIff=0;
                    patchlabel((yyvsp[-3].uns),(yyvsp[-1].uns)+1);
                    patchlabel((yyvsp[-1].uns),nextquadlabel());
                  if((yyvsp[-2].stmt_t).breakList!=0   ){
                       (yyval.stmt_t).breakList=(yyvsp[-2].stmt_t).breakList; 
                  }else if((yyvsp[0].stmt_t).breakList!=0){
                      (yyval.stmt_t).breakList=(yyvsp[0].stmt_t).breakList; 
                  }else
                    (yyval.stmt_t).breakList=0;

                  if((yyvsp[-2].stmt_t).contList!=0 ){
                       (yyval.stmt_t).contList=(yyvsp[-2].stmt_t).contList; 
                  }else if((yyvsp[0].stmt_t).contList!=0){
                      (yyval.stmt_t).contList=(yyvsp[0].stmt_t).contList; 
                  }else
                    (yyval.stmt_t).contList=0;
                }
#line 2780 "parser.c"
    break;

  case 99: /* whilestart: WHILE  */
#line 1139 "parser.y"
                    {
                    whiletop=pushWhileStack(whilestack,whiletop); 
                    inloop=1;
                     (yyval.uns)=nextquadlabel();
                }
#line 2790 "parser.c"
    break;

  case 100: /* whilesecond: L_PARENTHESIS expr R_PARENTHESIS  */
#line 1146 "parser.y"
                                               {
                    emit(if_eq,(yyvsp[-1].exprVal),newexpr_constbool(1),0,currQuad+2,yylineno);
                    (yyval.uns)=nextquadlabel();
                    emit(jump,NULL,NULL,0,nextquadlabel(),yylineno);
                    
                }
#line 2801 "parser.c"
    break;

  case 101: /* while: whilestart whilesecond loopstmt  */
#line 1153 "parser.y"
                                          {
                    inloop=0;
                
                     emit(jump,NULL,NULL,0,(yyvsp[-2].uns),yylineno);

                    patchlabel((yyvsp[-1].uns), nextquadlabel());
                    patchlist((yyvsp[0].stmt_t).breakList, nextquadlabel());
                    patchlist((yyvsp[0].stmt_t).contList, (yyvsp[-2].uns));
                    whiletop=popWhileStack(whilestack,whiletop);
                    (yyval.stmt_t).breakList=0; (yyval.stmt_t).contList=0;
                }
#line 2817 "parser.c"
    break;

  case 102: /* N: %empty  */
#line 1165 "parser.y"
                {  (yyval.uns) = nextquadlabel(); emit(jump,NULL,NULL,0,nextquadlabel(),yylineno); }
#line 2823 "parser.c"
    break;

  case 103: /* M: %empty  */
#line 1167 "parser.y"
                { (yyval.uns) = nextquadlabel(); }
#line 2829 "parser.c"
    break;

  case 104: /* $@15: %empty  */
#line 1169 "parser.y"
                   {inloop=1;
                    whiletop=pushWhileStack(whilestack,whiletop); 
                    }
#line 2837 "parser.c"
    break;

  case 105: /* forprefix: FOR $@15 L_PARENTHESIS elist SEMICOLON M expr SEMICOLON  */
#line 1172 "parser.y"
                                                                   {
                    (yyval.for_s).test = (yyvsp[-2].uns);
                    (yyval.for_s).enter = nextquadlabel();
                    emit(if_eq, (yyvsp[-1].exprVal), newexpr_constbool(1), 0,nextquadlabel(),yylineno);
                    whiletop=popWhileStack(whilestack,whiletop); 
                    
                }
#line 2849 "parser.c"
    break;

  case 106: /* for: forprefix N elist R_PARENTHESIS N loopstmt N  */
#line 1181 "parser.y"
                                                         {
                    inloop=0;
                     
                    
                    
                    patchlabel((yyvsp[-6].for_s).enter, (yyvsp[-2].uns)+1); 
                    patchlabel((yyvsp[-5].uns), nextquadlabel()); 
                    patchlabel((yyvsp[-2].uns), (yyvsp[-6].for_s).test); 
                    patchlabel((yyvsp[0].uns), (yyvsp[-5].uns)+1); 
                 
                    
                    patchlist((yyvsp[-1].stmt_t).breakList, nextquadlabel());
                    patchlist((yyvsp[-1].stmt_t).contList, (yyvsp[-5].uns)+1);
                        
                    (yyval.stmt_t).breakList=0; (yyval.stmt_t).contList=0;
                       
            }
#line 2871 "parser.c"
    break;

  case 107: /* loopstart: %empty  */
#line 1200 "parser.y"
                {++loopcounter;}
#line 2877 "parser.c"
    break;

  case 108: /* loopend: %empty  */
#line 1203 "parser.y"
                {--loopcounter;}
#line 2883 "parser.c"
    break;

  case 109: /* loopstmt: loopstart stmt loopend  */
#line 1206 "parser.y"
                                        { (yyval.stmt_t)=(yyvsp[-1].stmt_t); }
#line 2889 "parser.c"
    break;

  case 110: /* funcblockstart: %empty  */
#line 1213 "parser.y"
                { topFunc(whilestack,whiletop);  loopcounter=0; }
#line 2895 "parser.c"
    break;

  case 111: /* funcblockend: %empty  */
#line 1216 "parser.y"
                { topFunc(whilestack,whiletop);   }
#line 2901 "parser.c"
    break;

  case 112: /* $@16: %empty  */
#line 1220 "parser.y"
                      {returned=1;}
#line 2907 "parser.c"
    break;

  case 113: /* returnstmt: RETURN $@16 SEMICOLON  */
#line 1220 "parser.y"
                                             {returned=0;                     
                    emit(ret,NULL,0,0,nextquadlabel(),yylineno);
                    (yyval.stmt_t).breakList=0; (yyval.stmt_t).contList=0; 
                }
#line 2916 "parser.c"
    break;

  case 114: /* $@17: %empty  */
#line 1224 "parser.y"
                       {returned=1; }
#line 2922 "parser.c"
    break;

  case 115: /* $@18: %empty  */
#line 1224 "parser.y"
                                           {returned=0;}
#line 2928 "parser.c"
    break;

  case 116: /* returnstmt: RETURN $@17 expr $@18 SEMICOLON  */
#line 1224 "parser.y"
                                                                    {
               
                    emit(ret,0,0,(yyvsp[-2].exprVal),nextquadlabel(),yylineno);
                    (yyval.stmt_t).breakList=0; (yyval.stmt_t).contList=0; 
                }
#line 2938 "parser.c"
    break;


#line 2942 "parser.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1233 "parser.y"



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
