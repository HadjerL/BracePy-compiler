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
#line 2 "syntaxic.y"

#define simpleTypeNb 4
#define YYDEBUG 1

#line 76 "syntaxic.tab.c"

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

#include "syntaxic.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TOK_INT = 3,                    /* TOK_INT  */
  YYSYMBOL_TOK_STR = 4,                    /* TOK_STR  */
  YYSYMBOL_TOK_FLOAT = 5,                  /* TOK_FLOAT  */
  YYSYMBOL_TOK_BOOL = 6,                   /* TOK_BOOL  */
  YYSYMBOL_TOK_ARRAY = 7,                  /* TOK_ARRAY  */
  YYSYMBOL_TOK_TYPE = 8,                   /* TOK_TYPE  */
  YYSYMBOL_TOK_CONST = 9,                  /* TOK_CONST  */
  YYSYMBOL_TOK_IF = 10,                    /* TOK_IF  */
  YYSYMBOL_TOK_ELSE = 11,                  /* TOK_ELSE  */
  YYSYMBOL_TOK_ELIF = 12,                  /* TOK_ELIF  */
  YYSYMBOL_TOK_RETURN = 13,                /* TOK_RETURN  */
  YYSYMBOL_TOK_SWITCH = 14,                /* TOK_SWITCH  */
  YYSYMBOL_TOK_CASE = 15,                  /* TOK_CASE  */
  YYSYMBOL_TOK_BREAK = 16,                 /* TOK_BREAK  */
  YYSYMBOL_TOK_DEFAULT = 17,               /* TOK_DEFAULT  */
  YYSYMBOL_TOK_FOR = 18,                   /* TOK_FOR  */
  YYSYMBOL_TOK_WHILE = 19,                 /* TOK_WHILE  */
  YYSYMBOL_TOK_FOREACH = 20,               /* TOK_FOREACH  */
  YYSYMBOL_TOK_IN = 21,                    /* TOK_IN  */
  YYSYMBOL_TOK_INPUT = 22,                 /* TOK_INPUT  */
  YYSYMBOL_TOK_PRINT = 23,                 /* TOK_PRINT  */
  YYSYMBOL_TOK_DEF = 24,                   /* TOK_DEF  */
  YYSYMBOL_TOK_AS = 25,                    /* TOK_AS  */
  YYSYMBOL_TOK_FROM = 26,                  /* TOK_FROM  */
  YYSYMBOL_TOK_IMPORT = 27,                /* TOK_IMPORT  */
  YYSYMBOL_TOK_INT_T = 28,                 /* TOK_INT_T  */
  YYSYMBOL_TOK_FLOAT_T = 29,               /* TOK_FLOAT_T  */
  YYSYMBOL_TOK_STR_T = 30,                 /* TOK_STR_T  */
  YYSYMBOL_TOK_BOOl_T = 31,                /* TOK_BOOl_T  */
  YYSYMBOL_TOK_TRUE = 32,                  /* TOK_TRUE  */
  YYSYMBOL_TOK_FALSE = 33,                 /* TOK_FALSE  */
  YYSYMBOL_TOK_ADD = 34,                   /* TOK_ADD  */
  YYSYMBOL_TOK_SUB = 35,                   /* TOK_SUB  */
  YYSYMBOL_TOK_MUL = 36,                   /* TOK_MUL  */
  YYSYMBOL_TOK_DIV = 37,                   /* TOK_DIV  */
  YYSYMBOL_TOK_MOD = 38,                   /* TOK_MOD  */
  YYSYMBOL_TOK_INC = 39,                   /* TOK_INC  */
  YYSYMBOL_TOK_DEC = 40,                   /* TOK_DEC  */
  YYSYMBOL_TOK_POW = 41,                   /* TOK_POW  */
  YYSYMBOL_TOK_FLOOR_DIV = 42,             /* TOK_FLOOR_DIV  */
  YYSYMBOL_TOK_ADD_ASSIGN = 43,            /* TOK_ADD_ASSIGN  */
  YYSYMBOL_TOK_SUB_ASSIGN = 44,            /* TOK_SUB_ASSIGN  */
  YYSYMBOL_TOK_MUL_ASSIGN = 45,            /* TOK_MUL_ASSIGN  */
  YYSYMBOL_TOK_DIV_ASSIGN = 46,            /* TOK_DIV_ASSIGN  */
  YYSYMBOL_TOK_MOD_ASSIGN = 47,            /* TOK_MOD_ASSIGN  */
  YYSYMBOL_TOK_NOT = 48,                   /* TOK_NOT  */
  YYSYMBOL_TOK_AND = 49,                   /* TOK_AND  */
  YYSYMBOL_TOK_OR = 50,                    /* TOK_OR  */
  YYSYMBOL_TOK_EQ = 51,                    /* TOK_EQ  */
  YYSYMBOL_TOK_GT = 52,                    /* TOK_GT  */
  YYSYMBOL_TOK_LT = 53,                    /* TOK_LT  */
  YYSYMBOL_TOK_GE = 54,                    /* TOK_GE  */
  YYSYMBOL_TOK_LE = 55,                    /* TOK_LE  */
  YYSYMBOL_TOK_NE = 56,                    /* TOK_NE  */
  YYSYMBOL_TOK_ID = 57,                    /* TOK_ID  */
  YYSYMBOL_TOK_AFFECT = 58,                /* TOK_AFFECT  */
  YYSYMBOL_TOK_PAR_OUV = 59,               /* TOK_PAR_OUV  */
  YYSYMBOL_TOK_PAR_FER = 60,               /* TOK_PAR_FER  */
  YYSYMBOL_TOK_ACC_OUV = 61,               /* TOK_ACC_OUV  */
  YYSYMBOL_TOK_ACC_FER = 62,               /* TOK_ACC_FER  */
  YYSYMBOL_TOK_CRO_OUV = 63,               /* TOK_CRO_OUV  */
  YYSYMBOL_TOK_CRO_FER = 64,               /* TOK_CRO_FER  */
  YYSYMBOL_TOK_POINT = 65,                 /* TOK_POINT  */
  YYSYMBOL_TOK_VIRGULE = 66,               /* TOK_VIRGULE  */
  YYSYMBOL_TOK_DEUX_POINTS = 67,           /* TOK_DEUX_POINTS  */
  YYSYMBOL_TOK_POINT_VIRGULE = 68,         /* TOK_POINT_VIRGULE  */
  YYSYMBOL_YYACCEPT = 69,                  /* $accept  */
  YYSYMBOL_SimpleType = 70,                /* SimpleType  */
  YYSYMBOL_Bloc = 71,                      /* Bloc  */
  YYSYMBOL_Statement = 72,                 /* Statement  */
  YYSYMBOL_DeclarationInitialisation = 73, /* DeclarationInitialisation  */
  YYSYMBOL_DeclarationSimple = 74,         /* DeclarationSimple  */
  YYSYMBOL_Array = 75,                     /* Array  */
  YYSYMBOL_Declaration = 76,               /* Declaration  */
  YYSYMBOL_DeclarationStructure = 77,      /* DeclarationStructure  */
  YYSYMBOL_DeclarationStructureLoop = 78,  /* DeclarationStructureLoop  */
  YYSYMBOL_DeclarationVariableStructure = 79, /* DeclarationVariableStructure  */
  YYSYMBOL_AppelFontion = 80,              /* AppelFontion  */
  YYSYMBOL_Arguments = 81,                 /* Arguments  */
  YYSYMBOL_Expression = 82,                /* Expression  */
  YYSYMBOL_Valeur = 83,                    /* Valeur  */
  YYSYMBOL_Variable = 84,                  /* Variable  */
  YYSYMBOL_BracketExpressionLoop = 85,     /* BracketExpressionLoop  */
  YYSYMBOL_Affectation = 86,               /* Affectation  */
  YYSYMBOL_PureAffectation = 87,           /* PureAffectation  */
  YYSYMBOL_RapidAffectation = 88,          /* RapidAffectation  */
  YYSYMBOL_OperateurUnaire = 89,           /* OperateurUnaire  */
  YYSYMBOL_Condition = 90,                 /* Condition  */
  YYSYMBOL_ConditionElIf = 91,             /* ConditionElIf  */
  YYSYMBOL_ConditionELSE = 92,             /* ConditionELSE  */
  YYSYMBOL_Switch = 93,                    /* Switch  */
  YYSYMBOL_CaseLoop = 94,                  /* CaseLoop  */
  YYSYMBOL_SwitchDefault = 95,             /* SwitchDefault  */
  YYSYMBOL_Boucle = 96,                    /* Boucle  */
  YYSYMBOL_While = 97,                     /* While  */
  YYSYMBOL_For = 98,                       /* For  */
  YYSYMBOL_Tableau = 99,                   /* Tableau  */
  YYSYMBOL_TableauLoop = 100,              /* TableauLoop  */
  YYSYMBOL_ExpressionLoop = 101            /* ExpressionLoop  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Second part of user prologue.  */
#line 83 "syntaxic.y"

    extern FILE *yyin;
    extern int yylineno;
    extern int yyleng;
    extern int yylex();
    char* file = "test.txt";
    int currentColumn = 1;
    void yysuccess(char *s);
    void yyerrorSemantic(char *s);
    void yyerror(const char *s);
    void showLexicalError();
    SymboleTable * symboleTable = NULL;
    stockSauv * StockSauv;
    quad Quadruplet=NULL;
    int qc = 1;
    

#line 229 "syntaxic.tab.c"


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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  57
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   642

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  232

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   323


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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   103,   127,   128,   129,   130,   144,   146,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   160,   161,   165,
     175,   182,   183,   186,   187,   190,   192,   194,   201,   204,
     207,   208,   211,   215,   216,   337,   459,   581,   703,   823,
     943,   965,  1008,  1052,  1096,  1235,  1323,  1452,  1556,  1746,
    1747,  1748,  1751,  1752,  1753,  1754,  1755,  1759,  1760,  1761,
    1762,  1764,  1766,  1771,  1772,  1776,  1777,  1778,  1782,  1783,
    1784,  1785,  1786,  1787,  1791,  1792,  1796,  1797,  1799,  1801,
    1802,  1805,  1807,  1811,  1813,  1815,  1817,  1819,  1822,  1823,
    1827,  1832,  1833,  1835,  1839,  1840,  1842,  1844,  1846,  1848
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TOK_INT", "TOK_STR",
  "TOK_FLOAT", "TOK_BOOL", "TOK_ARRAY", "TOK_TYPE", "TOK_CONST", "TOK_IF",
  "TOK_ELSE", "TOK_ELIF", "TOK_RETURN", "TOK_SWITCH", "TOK_CASE",
  "TOK_BREAK", "TOK_DEFAULT", "TOK_FOR", "TOK_WHILE", "TOK_FOREACH",
  "TOK_IN", "TOK_INPUT", "TOK_PRINT", "TOK_DEF", "TOK_AS", "TOK_FROM",
  "TOK_IMPORT", "TOK_INT_T", "TOK_FLOAT_T", "TOK_STR_T", "TOK_BOOl_T",
  "TOK_TRUE", "TOK_FALSE", "TOK_ADD", "TOK_SUB", "TOK_MUL", "TOK_DIV",
  "TOK_MOD", "TOK_INC", "TOK_DEC", "TOK_POW", "TOK_FLOOR_DIV",
  "TOK_ADD_ASSIGN", "TOK_SUB_ASSIGN", "TOK_MUL_ASSIGN", "TOK_DIV_ASSIGN",
  "TOK_MOD_ASSIGN", "TOK_NOT", "TOK_AND", "TOK_OR", "TOK_EQ", "TOK_GT",
  "TOK_LT", "TOK_GE", "TOK_LE", "TOK_NE", "TOK_ID", "TOK_AFFECT",
  "TOK_PAR_OUV", "TOK_PAR_FER", "TOK_ACC_OUV", "TOK_ACC_FER",
  "TOK_CRO_OUV", "TOK_CRO_FER", "TOK_POINT", "TOK_VIRGULE",
  "TOK_DEUX_POINTS", "TOK_POINT_VIRGULE", "$accept", "SimpleType", "Bloc",
  "Statement", "DeclarationInitialisation", "DeclarationSimple", "Array",
  "Declaration", "DeclarationStructure", "DeclarationStructureLoop",
  "DeclarationVariableStructure", "AppelFontion", "Arguments",
  "Expression", "Valeur", "Variable", "BracketExpressionLoop",
  "Affectation", "PureAffectation", "RapidAffectation", "OperateurUnaire",
  "Condition", "ConditionElIf", "ConditionELSE", "Switch", "CaseLoop",
  "SwitchDefault", "Boucle", "While", "For", "Tableau", "TableauLoop",
  "ExpressionLoop", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-174)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     121,  -174,  -174,  -174,  -174,    25,   -36,   233,   -23,   302,
     -22,   -27,    -2,     5,     6,    -5,    15,    63,   121,    -1,
     -25,    16,     7,    17,   -20,    18,    19,    43,    51,  -174,
    -174,    30,    57,    60,   -25,   302,  -174,  -174,  -174,  -174,
    -174,   302,   302,   302,  -174,   194,  -174,  -174,    65,  -174,
     109,   302,     9,   302,   302,    65,  -174,  -174,  -174,  -174,
     139,    65,  -174,  -174,  -174,  -174,  -174,  -174,   302,   302,
     302,   302,   302,  -174,  -174,  -174,  -174,  -174,  -174,  -174,
     302,   302,     9,  -174,   417,    33,   559,   444,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   302,  -174,    72,    68,   471,    76,  -174,   117,
    -174,    87,   244,   317,  -174,   139,   525,  -174,  -174,   525,
     525,   525,   525,   525,   342,   367,    82,    91,  -174,    33,
      33,    -9,    -9,    -9,   104,   559,   550,   525,   584,   584,
     584,   584,   108,   584,    95,   302,    99,  -174,   -11,  -174,
     302,   100,   270,   110,   100,   100,     9,   118,   121,   151,
     219,   121,   119,   122,  -174,   302,  -174,   302,   106,   123,
     124,  -174,  -174,  -174,  -174,   127,    62,    65,   131,   120,
     140,   392,   270,  -174,   110,  -174,    -6,   138,   125,  -174,
     121,   121,   100,  -174,  -174,   145,   150,  -174,  -174,   121,
     149,   155,   156,  -174,   121,   302,   197,   121,  -174,  -174,
     157,   498,    62,   203,   162,  -174,   172,   167,   174,   180,
    -174,   121,   121,   121,  -174,   189,   197,  -174,    -6,  -174,
    -174,  -174
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       6,     2,     3,     4,     5,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    57,     0,     0,     6,     0,
       0,     0,     0,    60,     0,     0,     0,     0,     0,    88,
      89,     0,     0,     0,     0,     0,    52,    53,    54,    55,
      56,     0,     0,     0,    60,     0,    50,    51,     0,    15,
       0,     0,     0,     0,     0,     0,    19,     1,     7,     8,
       0,     0,    17,    20,     9,    10,    74,    75,     0,     0,
       0,     0,     0,    63,    64,    68,    11,    13,    14,    12,
       0,     0,     0,    18,     0,    41,    40,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    16,     0,     0,     0,     0,    23,     0,
      24,     0,    30,     0,    58,     0,    65,    66,    67,    69,
      70,    71,    72,    73,     0,     0,    26,     0,    32,    44,
      45,    46,    47,    48,    49,    42,    43,    38,    36,    34,
      37,    35,    39,    33,     0,     0,     0,    28,     0,    29,
       0,    61,    98,    96,    61,    61,     0,     0,     6,     0,
       0,     6,     0,     0,    31,     0,    59,     0,     0,     0,
       0,    22,    21,    27,    25,     0,     0,     0,     0,     0,
       0,     0,    98,    95,    96,    94,    78,     0,     0,    90,
       6,     6,    61,    99,    97,     0,     0,    76,    77,     6,
       0,     0,     0,    62,     6,     0,    84,     6,    93,    92,
       0,     0,     0,    86,     0,    82,     0,     0,     0,     0,
      91,     6,     6,     6,    83,     0,    84,    87,    78,    85,
      79,    80
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -174,   253,    -7,  -174,   209,     1,  -174,   -75,  -174,  -174,
    -174,     4,   111,     8,  -173,     0,  -145,   -60,    10,  -174,
    -174,  -174,    35,    36,  -174,    39,  -174,  -174,  -174,  -174,
    -113,    83,    84
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    16,    17,    18,    19,    20,    21,   109,    22,   157,
     110,    44,   111,   112,    46,    47,   166,    25,    62,    74,
      75,    26,   197,   198,    27,   213,   219,    28,    29,    30,
     117,   170,   168
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      24,   118,   153,   187,    23,   195,   196,   126,    34,   171,
     172,    58,     1,     2,     3,     4,     5,    45,    24,    66,
      67,    33,    23,    68,    69,    70,    71,    72,     1,     2,
       3,     4,    93,    60,    73,   163,    35,    48,    60,   217,
      61,    49,    96,    84,    83,    61,    15,   203,   104,    85,
      86,    87,   115,   108,    53,   114,   184,    50,    54,   106,
      55,    24,   113,    57,    51,    52,   107,    59,   116,    90,
      91,    92,    56,    63,    93,    64,   119,   120,   121,   122,
     123,   173,    31,   108,    96,    65,    76,    77,   124,   125,
      36,    37,    38,    80,    39,    40,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,    78,     1,     2,     3,     4,     5,   188,     7,    79,
      81,    82,    15,   152,     1,     2,     3,     4,     5,     6,
       7,     8,   144,   147,     9,    10,   145,    11,   148,    12,
      13,    14,    88,    89,    90,    91,    92,   149,   162,    93,
     156,   175,   158,   160,   178,    96,   159,   108,    24,    96,
     161,    24,    23,   165,    -1,    23,   176,    36,    37,    38,
     183,    39,    40,   181,    41,   182,   169,    24,    15,   179,
     174,   190,   180,   201,   202,   200,   115,    42,   185,   186,
      24,    24,   206,   189,    23,    23,    15,   210,    43,    24,
     214,   191,   115,    23,    24,   199,   204,    24,    23,   205,
     207,    23,   212,   211,   225,   226,   227,   208,   209,   215,
     218,    24,    24,    24,   220,    23,    23,    23,    88,    89,
      90,    91,    92,   221,   222,    93,     1,     2,     3,     4,
       5,   223,   224,    94,    95,    96,    97,    98,    99,   100,
     101,   228,   102,    88,    89,    90,    91,    92,    32,   105,
      93,   164,   103,   230,   231,   229,   193,   194,    94,    95,
      96,    97,    98,    99,   100,   101,     0,   102,    88,    89,
      90,    91,    92,     0,     0,    93,     0,   177,     0,     0,
       0,     0,     0,    94,    95,    96,    97,    98,    99,   100,
     101,     0,   102,     0,    88,    89,    90,    91,    92,     0,
     150,    93,     0,     0,     0,     0,     0,     0,     0,    94,
      95,    96,    97,    98,    99,   100,   101,     0,   102,     0,
      36,    37,    38,     0,    39,    40,   167,    41,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      42,    88,    89,    90,    91,    92,     0,     0,    93,    15,
       0,    43,     0,     0,     0,     0,    94,    95,    96,    97,
      98,    99,   100,   101,     0,   102,    88,    89,    90,    91,
      92,   151,     0,    93,     0,     0,     0,     0,     0,     0,
       0,    94,    95,    96,    97,    98,    99,   100,   101,     0,
     102,    88,    89,    90,    91,    92,   154,     0,    93,     0,
       0,     0,     0,     0,     0,     0,    94,    95,    96,    97,
      98,    99,   100,   101,     0,   102,    88,    89,    90,    91,
      92,   155,     0,    93,     0,     0,     0,     0,     0,     0,
       0,    94,    95,    96,    97,    98,    99,   100,   101,     0,
     102,    88,    89,    90,    91,    92,   192,     0,    93,     0,
       0,     0,     0,     0,     0,     0,    94,    95,    96,    97,
      98,    99,   100,   101,     0,   102,     0,   127,    88,    89,
      90,    91,    92,     0,     0,    93,     0,     0,     0,     0,
       0,     0,     0,    94,    95,    96,    97,    98,    99,   100,
     101,     0,   102,     0,   128,    88,    89,    90,    91,    92,
       0,     0,    93,     0,     0,     0,     0,     0,     0,     0,
      94,    95,    96,    97,    98,    99,   100,   101,     0,   102,
       0,   146,    88,    89,    90,    91,    92,     0,     0,    93,
       0,     0,     0,     0,     0,     0,     0,    94,    95,    96,
      97,    98,    99,   100,   101,     0,   102,     0,   216,    88,
      89,    90,    91,    92,     0,     0,    93,     0,     0,     0,
       0,     0,     0,     0,    94,    95,    96,    97,    98,    99,
     100,   101,     0,   102,    88,    89,    90,    91,    92,     0,
       0,    93,     0,    88,    89,    90,    91,    92,     0,    94,
      93,    96,    97,    98,    99,   100,   101,     0,   102,     0,
      96,    97,    98,    99,   100,   101,     0,   102,    88,    89,
      90,    91,    92,     0,     0,    93,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    96,    -1,    -1,    -1,    -1,
     101,     0,    -1
};

static const yytype_int16 yycheck[] =
{
       0,    61,   115,   176,     0,    11,    12,    82,     7,   154,
     155,    18,     3,     4,     5,     6,     7,     9,    18,    39,
      40,    57,    18,    43,    44,    45,    46,    47,     3,     4,
       5,     6,    41,    58,    24,   148,    59,    59,    58,   212,
      65,    68,    51,    35,    34,    65,    57,   192,    48,    41,
      42,    43,    63,    52,    59,    55,   169,    59,    63,    51,
      65,    61,    54,     0,    59,    59,    57,    68,    60,    36,
      37,    38,    57,    57,    41,    68,    68,    69,    70,    71,
      72,   156,    57,    82,    51,    68,    68,    68,    80,    81,
      28,    29,    30,    63,    32,    33,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,    68,     3,     4,     5,     6,     7,   177,     9,    68,
      63,    61,    57,   115,     3,     4,     5,     6,     7,     8,
       9,    10,    60,    57,    13,    14,    68,    16,    21,    18,
      19,    20,    34,    35,    36,    37,    38,    60,   148,    41,
      68,   158,    61,   145,   161,    51,    61,   156,   158,    51,
      61,   161,   158,    63,    56,   161,    15,    28,    29,    30,
      64,    32,    33,   165,    35,   167,    66,   177,    57,    60,
      62,    61,    60,   190,   191,    60,    63,    48,    64,    62,
     190,   191,   199,    62,   190,   191,    57,   204,    59,   199,
     207,    61,    63,   199,   204,    67,    61,   207,   204,    59,
      61,   207,    15,   205,   221,   222,   223,    62,    62,    62,
      17,   221,   222,   223,    62,   221,   222,   223,    34,    35,
      36,    37,    38,    61,    67,    41,     3,     4,     5,     6,
       7,    67,    62,    49,    50,    51,    52,    53,    54,    55,
      56,    62,    58,    34,    35,    36,    37,    38,     5,    50,
      41,   150,    68,   228,   228,   226,   182,   184,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    58,    34,    35,
      36,    37,    38,    -1,    -1,    41,    -1,    68,    -1,    -1,
      -1,    -1,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    58,    -1,    34,    35,    36,    37,    38,    -1,
      66,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    -1,    58,    -1,
      28,    29,    30,    -1,    32,    33,    66,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    34,    35,    36,    37,    38,    -1,    -1,    41,    57,
      -1,    59,    -1,    -1,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    58,    34,    35,    36,    37,
      38,    64,    -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      58,    34,    35,    36,    37,    38,    64,    -1,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    58,    34,    35,    36,    37,
      38,    64,    -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      58,    34,    35,    36,    37,    38,    64,    -1,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    58,    -1,    60,    34,    35,
      36,    37,    38,    -1,    -1,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    58,    -1,    60,    34,    35,    36,    37,    38,
      -1,    -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    58,
      -1,    60,    34,    35,    36,    37,    38,    -1,    -1,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    -1,    58,    -1,    60,    34,
      35,    36,    37,    38,    -1,    -1,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    -1,    58,    34,    35,    36,    37,    38,    -1,
      -1,    41,    -1,    34,    35,    36,    37,    38,    -1,    49,
      41,    51,    52,    53,    54,    55,    56,    -1,    58,    -1,
      51,    52,    53,    54,    55,    56,    -1,    58,    34,    35,
      36,    37,    38,    -1,    -1,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,
      56,    -1,    58
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    13,
      14,    16,    18,    19,    20,    57,    70,    71,    72,    73,
      74,    75,    77,    80,    84,    86,    90,    93,    96,    97,
      98,    57,    70,    57,    74,    59,    28,    29,    30,    32,
      33,    35,    48,    59,    80,    82,    83,    84,    59,    68,
      59,    59,    59,    59,    63,    65,    57,     0,    71,    68,
      58,    65,    87,    57,    68,    68,    39,    40,    43,    44,
      45,    46,    47,    87,    88,    89,    68,    68,    68,    68,
      63,    63,    61,    87,    82,    82,    82,    82,    34,    35,
      36,    37,    38,    41,    49,    50,    51,    52,    53,    54,
      55,    56,    58,    68,    84,    73,    82,    57,    74,    76,
      79,    81,    82,    82,    84,    63,    82,    99,    86,    82,
      82,    82,    82,    82,    82,    82,    76,    60,    60,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    60,    68,    60,    57,    21,    60,
      66,    64,    82,    99,    64,    64,    68,    78,    61,    61,
      82,    61,    84,    99,    81,    63,    85,    66,   101,    66,
     100,    85,    85,    76,    62,    71,    15,    68,    71,    60,
      60,    82,    82,    64,    99,    64,    62,    83,    86,    62,
      61,    61,    64,   101,   100,    11,    12,    91,    92,    67,
      60,    71,    71,    85,    61,    59,    71,    61,    62,    62,
      71,    82,    15,    94,    71,    62,    60,    83,    17,    95,
      62,    61,    67,    67,    62,    71,    71,    71,    62,    94,
      91,    92
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    69,    70,    70,    70,    70,    71,    71,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    73,    73,    74,
      74,    75,    75,    76,    76,    77,    78,    78,    79,    80,
      81,    81,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    83,    83,    83,    83,    83,    84,    84,    84,
      84,    85,    85,    86,    86,    87,    87,    87,    88,    88,
      88,    88,    88,    88,    89,    89,    90,    90,    91,    91,
      91,    92,    92,    93,    94,    94,    95,    95,    96,    96,
      97,    98,    98,    98,    99,    99,   100,   100,   101,   101
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     0,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     3,     2,     3,     2,
       2,     6,     6,     1,     1,     6,     0,     2,     2,     4,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     5,
       1,     0,     4,     2,     2,     2,     2,     2,     1,     2,
       2,     2,     2,     2,     1,     1,     8,     8,     0,     8,
       8,     0,     4,    12,     0,     5,     0,     3,     1,     1,
       7,    11,     9,     9,     4,     4,     0,     3,     0,     3
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
  case 2: /* SimpleType: TOK_INT  */
#line 127 "syntaxic.y"
            { (yyval.type) = TYPE_INTEGER; }
#line 1697 "syntaxic.tab.c"
    break;

  case 3: /* SimpleType: TOK_STR  */
#line 128 "syntaxic.y"
             { (yyval.type) = TYPE_STRING; }
#line 1703 "syntaxic.tab.c"
    break;

  case 4: /* SimpleType: TOK_FLOAT  */
#line 129 "syntaxic.y"
               { (yyval.type) = TYPE_FLOAT; }
#line 1709 "syntaxic.tab.c"
    break;

  case 5: /* SimpleType: TOK_BOOL  */
#line 130 "syntaxic.y"
              { (yyval.type) = TYPE_BOOLEAN; }
#line 1715 "syntaxic.tab.c"
    break;

  case 19: /* DeclarationSimple: SimpleType TOK_ID  */
#line 165 "syntaxic.y"
                      {
        if(search(symboleTable, (yyvsp[0].nomVariable)) == NULL){
            // Si l'ID n'existe pas alors l'inserer
            NodeSymbol * newNodeSymbole = InsertEntry(symboleTable,(yyvsp[-1].type),(yyvsp[0].nomVariable),false);
            (yyval.NodeSymbol) = newNodeSymbole;
        }else{
            printf("Identifiant deja declare : %s\n", (yyvsp[0].nomVariable));
            (yyval.NodeSymbol) = NULL;
        }
    }
#line 1730 "syntaxic.tab.c"
    break;

  case 32: /* Expression: TOK_PAR_OUV Expression TOK_PAR_FER  */
#line 211 "syntaxic.y"
                                       {
            (yyval.expression)=(yyvsp[-1].expression);
    }
#line 1738 "syntaxic.tab.c"
    break;

  case 34: /* Expression: Expression TOK_LT Expression  */
#line 216 "syntaxic.y"
                                   {
    // Check if the types of the two expressions are the same
    if ((yyvsp[-2].expression).type == (yyvsp[0].expression).type) {
        (yyval.expression).type = TYPE_BOOLEAN;

        // Check if the type is string
        if ((yyvsp[-2].expression).type == TYPE_STRING) {
            if (strcmp((yyvsp[-2].expression).valeurString, (yyvsp[0].expression).valeurString) < 0) {
                (yyval.expression).Valeurboolean = true;
            } else {
                (yyval.expression).Valeurboolean = false;
            }

            // Create temporary buffers and result variable
            char buff[255];
            char buff2[255];
            char res[20];
            sprintf(res, "%s%d", "R", qc);
            strcpy((yyval.expression).nomVariable, res);
            (yyval.expression).isVariable = true;

            // Generate quadruplet based on variable types
            if ((yyvsp[-2].expression).isVariable == true && (yyvsp[0].expression).isVariable == true) {
                Quadruplet = addQuad(Quadruplet, "<", (yyvsp[-2].expression).nomVariable, (yyvsp[0].expression).nomVariable, res, qc);
            } else {
                if ((yyvsp[-2].expression).isVariable == true) {
                    strcpy(buff2, (yyvsp[0].expression).valeurString);
                    Quadruplet = addQuad(Quadruplet, "<", (yyvsp[-2].expression).nomVariable, buff2, res, qc);
                } else {
                    if ((yyvsp[0].expression).isVariable == true) {
                        strcpy(buff, (yyvsp[-2].expression).valeurString);
                        Quadruplet = addQuad(Quadruplet, "<", buff, (yyvsp[0].expression).nomVariable, res, qc);
                    } else {
                        strcpy(buff, (yyvsp[-2].expression).valeurString);
                        strcpy(buff2, (yyvsp[0].expression).valeurString);
                        Quadruplet = addQuad(Quadruplet, "<", buff, buff2, res, qc);
                    }
                }
            }
            qc++;
        } else {
            // Check if the type is integer
            if ((yyvsp[-2].expression).type == TYPE_INTEGER) {
                if ((yyvsp[-2].expression).valeurInteger < (yyvsp[0].expression).valeurInteger) {
                    (yyval.expression).Valeurboolean = true;
                } else {
                    (yyval.expression).Valeurboolean = false;
                }

                // Create temporary buffers and result variable
                char buff[255];
                char buff2[255];
                char res[20];
                sprintf(res, "%s%d", "R", qc);
                strcpy((yyval.expression).nomVariable, res);
                (yyval.expression).isVariable = true;

                // Generate quadruplet based on variable types
                if ((yyvsp[-2].expression).isVariable == true && (yyvsp[0].expression).isVariable == true) {
                    Quadruplet = addQuad(Quadruplet, "<", (yyvsp[-2].expression).nomVariable, (yyvsp[0].expression).nomVariable, res, qc);
                } else {
                    if ((yyvsp[-2].expression).isVariable == true) {
                        sprintf(buff2, "%d", (yyvsp[0].expression).valeurInteger);
                        Quadruplet = addQuad(Quadruplet, "<", (yyvsp[-2].expression).nomVariable, buff2, res, qc);
                    } else {
                        if ((yyvsp[0].expression).isVariable == true) {
                            sprintf(buff, "%d", (yyvsp[-2].expression).valeurInteger);
                            Quadruplet = addQuad(Quadruplet, "<", buff, (yyvsp[0].expression).nomVariable, res, qc);
                        } else {
                            sprintf(buff, "%d", (yyvsp[-2].expression).valeurInteger);
                            sprintf(buff2, "%d", (yyvsp[0].expression).valeurInteger);
                            Quadruplet = addQuad(Quadruplet, "<", buff, buff2, res, qc);
                        }
                    }
                }
                qc++;
            } else {
                // Check if the type is float
                if ((yyvsp[-2].expression).type == TYPE_FLOAT) {
                    if ((yyvsp[-2].expression).valeurFloat < (yyvsp[0].expression).valeurFloat) {
                        (yyval.expression).Valeurboolean = true;
                    } else {
                        (yyval.expression).Valeurboolean = false;
                    }

                    // Create temporary buffers and result variable
                    char buff[255];
                    char buff2[255];
                    char res[20];
                    sprintf(res, "%s%d", "R", qc);
                    strcpy((yyval.expression).nomVariable, res);
                    (yyval.expression).isVariable = true;

                    // Generate quadruplet based on variable types
                    if ((yyvsp[-2].expression).isVariable == true && (yyvsp[0].expression).isVariable == true) {
                        Quadruplet = addQuad(Quadruplet, "<", (yyvsp[-2].expression).nomVariable, (yyvsp[0].expression).nomVariable, res, qc);
                    } else {
                        if ((yyvsp[-2].expression).isVariable == true) {
                            sprintf(buff2, "%f", (yyvsp[0].expression).valeurFloat);
                            Quadruplet = addQuad(Quadruplet, "<", (yyvsp[-2].expression).nomVariable, buff2, res, qc);
                        } else {
                            if ((yyvsp[0].expression).isVariable == true) {
                                sprintf(buff, "%f", (yyvsp[-2].expression).valeurFloat);
                                Quadruplet = addQuad(Quadruplet, "<", buff, (yyvsp[0].expression).nomVariable, res, qc);
                            } else {
                                sprintf(buff, "%f", (yyvsp[-2].expression).valeurFloat);
                                sprintf(buff2, "%f", (yyvsp[0].expression).valeurFloat);
                                Quadruplet = addQuad(Quadruplet, "<", buff, buff2, res, qc);
                            }
                        }
                    }
                    qc++;
                }
            }
        }
    } else {
        // Types are incompatible, throw an error
        yyerrorSemantic("Type Incompatible");
    }
}
#line 1863 "syntaxic.tab.c"
    break;

  case 35: /* Expression: Expression TOK_LE Expression  */
#line 337 "syntaxic.y"
                                  {
    // Check if the types of the two expressions are the same
    if ((yyvsp[-2].expression).type == (yyvsp[0].expression).type) {
        (yyval.expression).type = TYPE_BOOLEAN;

        // Check if the type is string
        if ((yyvsp[-2].expression).type == TYPE_STRING) {
            if (strcmp((yyvsp[-2].expression).valeurString, (yyvsp[0].expression).valeurString) <= 0) {
                (yyval.expression).Valeurboolean = true;
            } else {
                (yyval.expression).Valeurboolean = false;
            }

            // Create temporary buffers and result variable
            char buff[255];
            char buff2[255];
            char res[20];
            sprintf(res, "%s%d", "R", qc);
            strcpy((yyval.expression).nomVariable, res);
            (yyval.expression).isVariable = true;

            // Generate quadruplet based on variable types
            if ((yyvsp[-2].expression).isVariable == true && (yyvsp[0].expression).isVariable == true) {
                Quadruplet = addQuad(Quadruplet, "<=",(yyvsp[-2].expression).nomVariable, (yyvsp[0].expression).nomVariable, res, qc);
            } else {
                if ((yyvsp[-2].expression).isVariable == true) {
                    strcpy(buff2, (yyvsp[0].expression).valeurString);
                    Quadruplet = addQuad(Quadruplet, "<=",(yyvsp[-2].expression).nomVariable, buff2, res, qc);
                } else {
                    if ((yyvsp[0].expression).isVariable == true) {
                        strcpy(buff, (yyvsp[-2].expression).valeurString);
                        Quadruplet = addQuad(Quadruplet, "<=",buff,(yyvsp[0].expression).nomVariable,res, qc);
                    } else {
                        strcpy(buff, (yyvsp[-2].expression).valeurString);
                        strcpy(buff2, (yyvsp[0].expression).valeurString);
                        Quadruplet = addQuad(Quadruplet, "<=",buff,buff2,res, qc);
                    }
                }
            }
            qc++;
        } else {
            // Check if the type is integer
            if ((yyvsp[-2].expression).type == TYPE_INTEGER) {
                if ((yyvsp[-2].expression).valeurInteger <= (yyvsp[0].expression).valeurInteger) {
                    (yyval.expression).Valeurboolean = true;
                } else {
                    (yyval.expression).Valeurboolean = false;
                }

                // Create temporary buffers and result variable
                char buff[255];
                char buff2[255];
                char res[20];
                sprintf(res, "%s%d", "R",qc);
                strcpy((yyval.expression).nomVariable,res);
                (yyval.expression).isVariable=true;

                // Generate quadruplet based on variable types
                if ((yyvsp[-2].expression).isVariable == true && (yyvsp[0].expression).isVariable == true) {
                    Quadruplet=addQuad(Quadruplet, "<=",(yyvsp[-2].expression).nomVariable, (yyvsp[0].expression).nomVariable, res, qc);
                } else {
                    if ((yyvsp[-2].expression).isVariable==true) {
                        sprintf(buff2, "%d", (yyvsp[0].expression).valeurInteger);
                        Quadruplet=addQuad(Quadruplet, "<=",(yyvsp[-2].expression).nomVariable, buff2, res, qc);
                    } else {
                        if ((yyvsp[0].expression).isVariable==true) {
                            sprintf(buff, "%d", (yyvsp[-2].expression).valeurInteger);
                            Quadruplet=addQuad(Quadruplet, "<=",buff,(yyvsp[0].expression).nomVariable,res, qc);
                        } else {
                            sprintf(buff, "%d", (yyvsp[-2].expression).valeurInteger);
                            sprintf(buff2, "%d", (yyvsp[0].expression).valeurInteger);
                            Quadruplet=addQuad(Quadruplet, "<=",buff,buff2,res, qc);
                        }
                    }
                }
                qc++;
            } else {
                // Check if the type is float
                if ((yyvsp[-2].expression).type == TYPE_FLOAT) {
                    if ((yyvsp[-2].expression).valeurFloat <= (yyvsp[0].expression).valeurFloat) {
                        (yyval.expression).Valeurboolean=true;
                    } else {
                        (yyval.expression).Valeurboolean=false;
                    }

                    // Create temporary buffers and result variable
                    char buff[255];
                    char buff2[255];
                    char res[20];
                    sprintf(res, "%s%d", "R",qc);
                    strcpy((yyval.expression).nomVariable,res);
                    (yyval.expression).isVariable=true;

                    // Generate quadruplet based on variable types
                    if ((yyvsp[-2].expression).isVariable == true && (yyvsp[0].expression).isVariable == true) {
                        Quadruplet=addQuad(Quadruplet, "<=",(yyvsp[-2].expression).nomVariable, (yyvsp[0].expression).nomVariable, res, qc);
                    } else {
                        if ((yyvsp[-2].expression).isVariable==true) {
                            sprintf(buff2, "%f", (yyvsp[0].expression).valeurFloat);
                            Quadruplet=addQuad(Quadruplet, "<=",(yyvsp[-2].expression).nomVariable, buff2, res, qc);
                        } else {
                            if ((yyvsp[0].expression).isVariable==true) {
                                sprintf(buff, "%f", (yyvsp[-2].expression).valeurFloat);
                                Quadruplet=addQuad(Quadruplet, "<=",buff,(yyvsp[0].expression).nomVariable,res, qc);
                            } else {
                                sprintf(buff, "%f", (yyvsp[-2].expression).valeurFloat);
                                sprintf(buff2, "%f", (yyvsp[0].expression).valeurFloat);
                                Quadruplet=addQuad(Quadruplet, "<=",buff,buff2,res, qc);
                            }
                        }
                    }
                    qc++;
                }
            }
        }
    } else {
        // Types are incompatible, throw an error
        yyerrorSemantic("Type Incompatible");
    }
}
#line 1988 "syntaxic.tab.c"
    break;

  case 36: /* Expression: Expression TOK_GT Expression  */
#line 459 "syntaxic.y"
                              {
    // Check if the types of the two expressions are the same
    if ((yyvsp[-2].expression).type == (yyvsp[0].expression).type) {
        (yyval.expression).type = TYPE_BOOLEAN;

        // Check if the type is string
        if ((yyvsp[-2].expression).type == TYPE_STRING) {
            if (strcmp((yyvsp[-2].expression).valeurString, (yyvsp[0].expression).valeurString) > 0) {
                (yyval.expression).Valeurboolean = true;
            } else {
                (yyval.expression).Valeurboolean = false;
            }

            // Create temporary buffers and result variable
            char buff[255];
            char buff2[255];
            char res[20];
            sprintf(res, "%s%d", "R", qc);
            strcpy((yyval.expression).nomVariable, res);
            (yyval.expression).isVariable = true;

            // Generate quadruplet based on variable types
            if ((yyvsp[-2].expression).isVariable == true && (yyvsp[0].expression).isVariable == true) {
                Quadruplet = addQuad(Quadruplet, ">", (yyvsp[-2].expression).nomVariable, (yyvsp[0].expression).nomVariable, res, qc);
            } else {
                if ((yyvsp[-2].expression).isVariable == true) {
                    strcpy(buff2, (yyvsp[0].expression).valeurString);
                    Quadruplet = addQuad(Quadruplet, ">", (yyvsp[-2].expression).nomVariable, buff2, res, qc);
                } else {
                    if ((yyvsp[0].expression).isVariable == true) {
                        strcpy(buff, (yyvsp[-2].expression).valeurString);
                        Quadruplet = addQuad(Quadruplet, ">", buff, (yyvsp[0].expression).nomVariable, res, qc);
                    } else {
                        strcpy(buff, (yyvsp[-2].expression).valeurString);
                        strcpy(buff2, (yyvsp[0].expression).valeurString);
                        Quadruplet = addQuad(Quadruplet, ">", buff, buff2, res, qc);
                    }
                }
            }
            qc++;
        } else {
            // Check if the type is integer
            if ((yyvsp[-2].expression).type == TYPE_INTEGER) {
                if ((yyvsp[-2].expression).valeurInteger > (yyvsp[0].expression).valeurInteger) {
                    (yyval.expression).Valeurboolean = true;
                } else {
                    (yyval.expression).Valeurboolean = false;
                }

                // Create temporary buffers and result variable
                char buff[255];
                char buff2[255];
                char res[20];
                sprintf(res, "%s%d", "R", qc);
                strcpy((yyval.expression).nomVariable, res);
                (yyval.expression).isVariable = true;

                // Generate quadruplet based on variable types
                if ((yyvsp[-2].expression).isVariable == true && (yyvsp[0].expression).isVariable == true) {
                    Quadruplet = addQuad(Quadruplet, ">", (yyvsp[-2].expression).nomVariable, (yyvsp[0].expression).nomVariable, res, qc);
                } else {
                    if ((yyvsp[-2].expression).isVariable == true) {
                        sprintf(buff2, "%d", (yyvsp[0].expression).valeurInteger);
                        Quadruplet = addQuad(Quadruplet, ">", (yyvsp[-2].expression).nomVariable, buff2, res, qc);
                    } else {
                        if ((yyvsp[0].expression).isVariable == true) {
                            sprintf(buff, "%d", (yyvsp[-2].expression).valeurInteger);
                            Quadruplet = addQuad(Quadruplet, ">", buff, (yyvsp[0].expression).nomVariable, res, qc);
                        } else {
                            sprintf(buff, "%d", (yyvsp[-2].expression).valeurInteger);
                            sprintf(buff2, "%d", (yyvsp[0].expression).valeurInteger);
                            Quadruplet = addQuad(Quadruplet, ">", buff, buff2, res, qc);
                        }
                    }
                }
                qc++;
            } else {
                // Check if the type is float
                if ((yyvsp[-2].expression).type == TYPE_FLOAT) {
                    if ((yyvsp[-2].expression).valeurFloat > (yyvsp[0].expression).valeurFloat) {
                        (yyval.expression).Valeurboolean = true;
                    } else {
                        (yyval.expression).Valeurboolean = false;
                    }

                    // Create temporary buffers and result variable
                    char buff[255];
                    char buff2[255];
                    char res[20];
                    sprintf(res, "%s%d", "R", qc);
                    strcpy((yyval.expression).nomVariable, res);
                    (yyval.expression).isVariable = true;

                    // Generate quadruplet based on variable types
                    if ((yyvsp[-2].expression).isVariable == true && (yyvsp[0].expression).isVariable == true) {
                        Quadruplet = addQuad(Quadruplet, ">", (yyvsp[-2].expression).nomVariable, (yyvsp[0].expression).nomVariable, res, qc);
                    } else {
                        if ((yyvsp[-2].expression).isVariable == true) {
                            sprintf(buff2, "%f", (yyvsp[0].expression).valeurFloat);
                            Quadruplet = addQuad(Quadruplet, ">", (yyvsp[-2].expression).nomVariable, buff2, res, qc);
                        } else {
                            if ((yyvsp[0].expression).isVariable == true) {
                                sprintf(buff, "%f", (yyvsp[-2].expression).valeurFloat);
                                Quadruplet = addQuad(Quadruplet, ">", buff, (yyvsp[0].expression).nomVariable, res, qc);
                            } else {
                                sprintf(buff, "%f", (yyvsp[-2].expression).valeurFloat);
                                sprintf(buff2, "%f", (yyvsp[0].expression).valeurFloat);
                                Quadruplet = addQuad(Quadruplet, ">", buff, buff2, res, qc);
                            }
                        }
                    }
                    qc++;
                }
            }
        }
    } else {
        // Types are incompatible, throw an error
        yyerrorSemantic("Type Incompatible");
    }
}
#line 2113 "syntaxic.tab.c"
    break;

  case 37: /* Expression: Expression TOK_GE Expression  */
#line 581 "syntaxic.y"
                              {
    // Check if the types of the two expressions are the same
    if ((yyvsp[-2].expression).type == (yyvsp[0].expression).type) {
        (yyval.expression).type = TYPE_BOOLEAN;

        // Check if the type is string
        if ((yyvsp[-2].expression).type == TYPE_STRING) {
            if (strcmp((yyvsp[-2].expression).valeurString, (yyvsp[0].expression).valeurString) >= 0) {
                (yyval.expression).Valeurboolean = true;
            } else {
                (yyval.expression).Valeurboolean = false;
            }

            // Create temporary buffers and result variable
            char buff[255];
            char buff2[255];
            char res[20];
            sprintf(res, "%s%d", "R", qc);
            strcpy((yyval.expression).nomVariable, res);
            (yyval.expression).isVariable = true;

            // Generate quadruplet based on variable types
            if ((yyvsp[-2].expression).isVariable == true && (yyvsp[0].expression).isVariable == true) {
                Quadruplet = addQuad(Quadruplet, ">=",(yyvsp[-2].expression).nomVariable, (yyvsp[0].expression).nomVariable, res, qc);
            } else {
                if ((yyvsp[-2].expression).isVariable == true) {
                    strcpy(buff2, (yyvsp[0].expression).valeurString);
                    Quadruplet = addQuad(Quadruplet, ">=",(yyvsp[-2].expression).nomVariable, buff2, res, qc);
                } else {
                    if ((yyvsp[0].expression).isVariable == true) {
                        strcpy(buff, (yyvsp[-2].expression).valeurString);
                        Quadruplet = addQuad(Quadruplet, ">=",buff,(yyvsp[0].expression).nomVariable,res, qc);
                    } else {
                        strcpy(buff, (yyvsp[-2].expression).valeurString);
                        strcpy(buff2, (yyvsp[0].expression).valeurString);
                        Quadruplet = addQuad(Quadruplet, ">=",buff,buff2,res, qc);
                    }
                }
            }
            qc++;
        } else {
            // Check if the type is integer
            if ((yyvsp[-2].expression).type == TYPE_INTEGER) {
                if ((yyvsp[-2].expression).valeurInteger >= (yyvsp[0].expression).valeurInteger) {
                    (yyval.expression).Valeurboolean = true;
                } else {
                    (yyval.expression).Valeurboolean = false;
                }

                // Create temporary buffers and result variable
                char buff[255];
                char buff2[255];
                char res[20];
                sprintf(res, "%s%d", "R", qc);
                strcpy((yyval.expression).nomVariable, res);
                (yyval.expression).isVariable = true;

                // Generate quadruplet based on variable types
                if ((yyvsp[-2].expression).isVariable == true && (yyvsp[0].expression).isVariable == true) {
                    Quadruplet = addQuad(Quadruplet, ">=",(yyvsp[-2].expression).nomVariable, (yyvsp[0].expression).nomVariable, res, qc);
                } else {
                    if ((yyvsp[-2].expression).isVariable == true) {
                        sprintf(buff2, "%d", (yyvsp[0].expression).valeurInteger);
                        Quadruplet = addQuad(Quadruplet, ">=",(yyvsp[-2].expression).nomVariable, buff2, res, qc);
                    } else {
                        if ((yyvsp[0].expression).isVariable == true) {
                            sprintf(buff, "%d", (yyvsp[-2].expression).valeurInteger);
                            Quadruplet = addQuad(Quadruplet, ">=",buff,(yyvsp[0].expression).nomVariable,res, qc);
                        } else {
                            sprintf(buff, "%d", (yyvsp[-2].expression).valeurInteger);
                            sprintf(buff2, "%d", (yyvsp[0].expression).valeurInteger);
                            Quadruplet = addQuad(Quadruplet, ">=",buff,buff2,res, qc);
                        }
                    }
                }
                qc++;
            } else {
                // Check if the type is float
                if ((yyvsp[-2].expression).type == TYPE_FLOAT) {
                    if ((yyvsp[-2].expression).valeurFloat >= (yyvsp[0].expression).valeurFloat) {
                        (yyval.expression).Valeurboolean = true;
                    } else {
                        (yyval.expression).Valeurboolean = false;
                    }

                    // Create temporary buffers and result variable
                    char buff[255];
                    char buff2[255];
                    char res[20];
                    sprintf(res, "%s%d", "R", qc);
                    strcpy((yyval.expression).nomVariable, res);
                    (yyval.expression).isVariable = true;

                    // Generate quadruplet based on variable types
                    if ((yyvsp[-2].expression).isVariable == true && (yyvsp[0].expression).isVariable == true) {
                        Quadruplet = addQuad(Quadruplet, ">=",(yyvsp[-2].expression).nomVariable, (yyvsp[0].expression).nomVariable, res, qc);
                    } else {
                        if ((yyvsp[-2].expression).isVariable == true) {
                            sprintf(buff2, "%f", (yyvsp[0].expression).valeurFloat);
                            Quadruplet = addQuad(Quadruplet, ">=",(yyvsp[-2].expression).nomVariable, buff2, res, qc);
                        } else {
                            if ((yyvsp[0].expression).isVariable == true) {
                                sprintf(buff, "%f", (yyvsp[-2].expression).valeurFloat);
                                Quadruplet = addQuad(Quadruplet, ">=",buff,(yyvsp[0].expression).nomVariable,res, qc);
                            } else {
                                sprintf(buff, "%f", (yyvsp[-2].expression).valeurFloat);
                                sprintf(buff2, "%f", (yyvsp[0].expression).valeurFloat);
                                Quadruplet = addQuad(Quadruplet, ">=",buff,buff2,res, qc);
                            }
                        }
                    }
                    qc++;
                }
            }
        }
    } else {
        // Types are incompatible, throw an error
        yyerrorSemantic("Type Incompatible");
    }
}
#line 2238 "syntaxic.tab.c"
    break;

  case 38: /* Expression: Expression TOK_EQ Expression  */
#line 703 "syntaxic.y"
                               {
    if ((yyvsp[-2].expression).type == (yyvsp[0].expression).type) {
        (yyval.expression).type = TYPE_BOOLEAN;

        // Check if the type is string
        if ((yyvsp[-2].expression).type == TYPE_STRING) {
            if (strcmp((yyvsp[-2].expression).valeurString, (yyvsp[0].expression).valeurString) == 0) {
                (yyval.expression).Valeurboolean = true;
            } else {
                (yyval.expression).Valeurboolean = false;
            }

            // Create temporary buffers and result variable
            char buff[255];
            char buff2[255];
            char res[20];
            sprintf(res, "%s%d", "R", qc);
            strcpy((yyval.expression).nomVariable, res);
            (yyval.expression).isVariable = true;

            // Generate quadruplet based on variable types
            if ((yyvsp[-2].expression).isVariable == true && (yyvsp[0].expression).isVariable == true) {
                Quadruplet = addQuad(Quadruplet, "==", (yyvsp[-2].expression).nomVariable, (yyvsp[0].expression).nomVariable, res, qc);
            } else {
                if ((yyvsp[-2].expression).isVariable == true) {
                    strcpy(buff2, (yyvsp[0].expression).valeurString);
                    Quadruplet = addQuad(Quadruplet, "==", (yyvsp[-2].expression).nomVariable, buff2, res, qc);
                } else {
                    if ((yyvsp[0].expression).isVariable == true) {
                        strcpy(buff, (yyvsp[-2].expression).valeurString);
                        Quadruplet = addQuad(Quadruplet, "==", buff, (yyvsp[0].expression).nomVariable, res, qc);
                    } else {
                        strcpy(buff, (yyvsp[-2].expression).valeurString);
                        strcpy(buff2, (yyvsp[0].expression).valeurString);
                        Quadruplet = addQuad(Quadruplet, "==", buff, buff2, res, qc);
                    }
                }
            }
            qc++;
        } else {
            // Check if the type is integer
            if ((yyvsp[-2].expression).type == TYPE_INTEGER) {
                if ((yyvsp[-2].expression).valeurInteger == (yyvsp[0].expression).valeurInteger) {
                    (yyval.expression).Valeurboolean = true;
                } else {
                    (yyval.expression).Valeurboolean = false;
                }

                // Create temporary buffers and result variable
                char buff[255];
                char buff2[255];
                char res[20];
                sprintf(res, "%s%d", "R", qc);
                strcpy((yyval.expression).nomVariable, res);
                (yyval.expression).isVariable = true;

                // Generate quadruplet based on variable types
                if ((yyvsp[-2].expression).isVariable == true && (yyvsp[0].expression).isVariable == true) {
                    Quadruplet = addQuad(Quadruplet, "==", (yyvsp[-2].expression).nomVariable, (yyvsp[0].expression).nomVariable, res, qc);
                } else {
                    if ((yyvsp[-2].expression).isVariable == true) {
                        sprintf(buff2, "%d", (yyvsp[0].expression).valeurInteger);
                        Quadruplet = addQuad(Quadruplet, "==", (yyvsp[-2].expression).nomVariable, buff2, res, qc);
                    } else {
                        if ((yyvsp[0].expression).isVariable == true) {
                            sprintf(buff, "%d", (yyvsp[-2].expression).valeurInteger);
                            Quadruplet = addQuad(Quadruplet, "==", buff, (yyvsp[0].expression).nomVariable, res, qc);
                        } else {
                            sprintf(buff, "%d", (yyvsp[-2].expression).valeurInteger);
                            sprintf(buff2, "%d", (yyvsp[0].expression).valeurInteger);
                            Quadruplet = addQuad(Quadruplet, "==", buff, buff2, res, qc);
                        }
                    }
                }
                qc++;
            } else {
                // Check if the type is float
                if ((yyvsp[-2].expression).type == TYPE_FLOAT) {
                    if ((yyvsp[-2].expression).valeurFloat == (yyvsp[0].expression).valeurFloat) {
                        (yyval.expression).Valeurboolean = true;
                    } else {
                        (yyval.expression).Valeurboolean = false;
                    }

                    // Create temporary buffers and result variable
                    char buff[255];
                    char buff2[255];
                    char res[20];
                    sprintf(res, "%s%d", "R", qc);
                    strcpy((yyval.expression).nomVariable, res);
                    (yyval.expression).isVariable = true;

                    // Generate quadruplet based on variable types
                    if ((yyvsp[-2].expression).isVariable == true && (yyvsp[0].expression).isVariable == true) {
                        Quadruplet = addQuad(Quadruplet, "==", (yyvsp[-2].expression).nomVariable, (yyvsp[0].expression).nomVariable, res, qc);
                    } else {
                        if ((yyvsp[-2].expression).isVariable == true) {
                            sprintf(buff2, "%f", (yyvsp[0].expression).valeurFloat);
                            Quadruplet = addQuad(Quadruplet, "==", (yyvsp[-2].expression).nomVariable, buff2, res, qc);
                        } else {
                            if ((yyvsp[0].expression).isVariable == true) {
                                sprintf(buff, "%f", (yyvsp[-2].expression).valeurFloat);
                                Quadruplet = addQuad(Quadruplet, "==", buff, (yyvsp[0].expression).nomVariable, res, qc);
                            } else {
                                sprintf(buff, "%f", (yyvsp[-2].expression).valeurFloat);
                                sprintf(buff2, "%f", (yyvsp[0].expression).valeurFloat);
                                Quadruplet = addQuad(Quadruplet, "==", buff, buff2, res, qc);
                            }
                        }
                    }
                    qc++;
                }
            }
        }
    } else {
        yyerrorSemantic("Type Incompatible");
    }
}
#line 2361 "syntaxic.tab.c"
    break;

  case 39: /* Expression: Expression TOK_NE Expression  */
#line 823 "syntaxic.y"
                               {
    if ((yyvsp[-2].expression).type == (yyvsp[0].expression).type) {
        (yyval.expression).type = TYPE_BOOLEAN;

        // Check if the type is string
        if ((yyvsp[-2].expression).type == TYPE_STRING) {
            if (strcmp((yyvsp[-2].expression).valeurString, (yyvsp[0].expression).valeurString) != 0) {
                (yyval.expression).Valeurboolean = true;
            } else {
                (yyval.expression).Valeurboolean = false;
            }

            // Create temporary buffers and result variable
            char buff[255];
            char buff2[255];
            char res[20];
            sprintf(res, "%s%d", "R", qc);
            strcpy((yyval.expression).nomVariable, res);
            (yyval.expression).isVariable = true;

            // Generate quadruplet based on variable types
            if ((yyvsp[-2].expression).isVariable == true && (yyvsp[0].expression).isVariable == true) {
                Quadruplet = addQuad(Quadruplet, "!=", (yyvsp[-2].expression).nomVariable, (yyvsp[0].expression).nomVariable, res, qc);
            } else {
                if ((yyvsp[-2].expression).isVariable == true) {
                    strcpy(buff2, (yyvsp[0].expression).valeurString);
                    Quadruplet = addQuad(Quadruplet, "!=", (yyvsp[-2].expression).nomVariable, buff2, res, qc);
                } else {
                    if ((yyvsp[0].expression).isVariable == true) {
                        strcpy(buff, (yyvsp[-2].expression).valeurString);
                        Quadruplet = addQuad(Quadruplet, "!=", buff, (yyvsp[0].expression).nomVariable, res, qc);
                    } else {
                        strcpy(buff, (yyvsp[-2].expression).valeurString);
                        strcpy(buff2, (yyvsp[0].expression).valeurString);
                        Quadruplet = addQuad(Quadruplet, "!=", buff, buff2, res, qc);
                    }
                }
            }
            qc++;
        } else {
            // Check if the type is integer
            if ((yyvsp[-2].expression).type == TYPE_INTEGER) {
                if ((yyvsp[-2].expression).valeurInteger != (yyvsp[0].expression).valeurInteger) {
                    (yyval.expression).Valeurboolean = true;
                } else {
                    (yyval.expression).Valeurboolean = false;
                }

                // Create temporary buffers and result variable
                char buff[255];
                char buff2[255];
                char res[20];
                sprintf(res, "%s%d", "R", qc);
                strcpy((yyval.expression).nomVariable, res);
                (yyval.expression).isVariable = true;

                // Generate quadruplet based on variable types
                if ((yyvsp[-2].expression).isVariable == true && (yyvsp[0].expression).isVariable == true) {
                    Quadruplet = addQuad(Quadruplet, "!=", (yyvsp[-2].expression).nomVariable, (yyvsp[0].expression).nomVariable, res, qc);
                } else {
                    if ((yyvsp[-2].expression).isVariable == true) {
                        sprintf(buff2, "%d", (yyvsp[0].expression).valeurInteger);
                        Quadruplet = addQuad(Quadruplet, "!=", (yyvsp[-2].expression).nomVariable, buff2, res, qc);
                    } else {
                        if ((yyvsp[0].expression).isVariable == true) {
                            sprintf(buff, "%d", (yyvsp[-2].expression).valeurInteger);
                            Quadruplet = addQuad(Quadruplet, "!=", buff, (yyvsp[0].expression).nomVariable, res, qc);
                        } else {
                            sprintf(buff, "%d", (yyvsp[-2].expression).valeurInteger);
                            sprintf(buff2, "%d", (yyvsp[0].expression).valeurInteger);
                            Quadruplet = addQuad(Quadruplet, "!=", buff, buff2, res, qc);
                        }
                    }
                }
                qc++;
            } else {
                // Check if the type is float
                if ((yyvsp[-2].expression).type == TYPE_FLOAT) {
                    if ((yyvsp[-2].expression).valeurFloat != (yyvsp[0].expression).valeurFloat) {
                        (yyval.expression).Valeurboolean = true;
                    } else {
                        (yyval.expression).Valeurboolean = false;
                    }

                    // Create temporary buffers and result variable
                    char buff[255];
                    char buff2[255];
                    char res[20];
                    sprintf(res, "%s%d", "R", qc);
                    strcpy((yyval.expression).nomVariable, res);
                    (yyval.expression).isVariable = true;

                    // Generate quadruplet based on variable types
                    if ((yyvsp[-2].expression).isVariable == true && (yyvsp[0].expression).isVariable == true) {
                        Quadruplet = addQuad(Quadruplet, "!=", (yyvsp[-2].expression).nomVariable, (yyvsp[0].expression).nomVariable, res, qc);
                    } else {
                        if ((yyvsp[-2].expression).isVariable == true) {
                            sprintf(buff2, "%f", (yyvsp[0].expression).valeurFloat);
                            Quadruplet = addQuad(Quadruplet, "!=", (yyvsp[-2].expression).nomVariable, buff2, res, qc);
                        } else {
                            if ((yyvsp[0].expression).isVariable == true) {
                                sprintf(buff, "%f", (yyvsp[-2].expression).valeurFloat);
                                Quadruplet = addQuad(Quadruplet, "!=", buff, (yyvsp[0].expression).nomVariable, res, qc);
                            } else {
                                sprintf(buff, "%f", (yyvsp[-2].expression).valeurFloat);
                                sprintf(buff2, "%f", (yyvsp[0].expression).valeurFloat);
                                Quadruplet = addQuad(Quadruplet, "!=", buff, buff2, res, qc);
                            }
                        }
                    }
                    qc++;
                }
            }
        }
    } else {
        yyerrorSemantic("Type Incompatible");
    }
}
#line 2484 "syntaxic.tab.c"
    break;

  case 40: /* Expression: TOK_NOT Expression  */
#line 943 "syntaxic.y"
                     {
    if ((yyvsp[0].expression).type == TYPE_BOOLEAN) {
        (yyval.expression).type = TYPE_BOOLEAN;
        (yyval.expression).Valeurboolean = !(yyvsp[0].expression).Valeurboolean;

        // Create temporary buffers and result variable
        char buff[255];
        char res[20];
        strcpy(buff, ((yyvsp[0].expression).Valeurboolean == true) ? "true" : "false");
        sprintf(res, "%s%d", "R", qc);
        strcpy((yyval.expression).nomVariable, res);
        (yyval.expression).isVariable = true;

        // Generate quadruplet for logical NOT operation
        Quadruplet = addQuad(Quadruplet, "NOT", buff, "", res, qc);
        qc++;
    } else {
        yyerrorSemantic("Can't do NOT of non-boolean type");
    }
}
#line 2509 "syntaxic.tab.c"
    break;

  case 41: /* Expression: TOK_SUB Expression  */
#line 965 "syntaxic.y"
                     {
    // Check if the expression is not a string
    if ((yyvsp[0].expression).type != TYPE_STRING) {
        // Check if the expression is an integer
        if ((yyvsp[0].expression).type == TYPE_INTEGER) {
            (yyval.expression).type = TYPE_INTEGER;
            (yyval.expression).valeurInteger = 0 - (yyvsp[0].expression).valeurInteger;

            // Create temporary buffers and result variable
            char buff[255];
            char res[20];
            sprintf(buff, "%d", (yyvsp[0].expression).valeurInteger);
            sprintf(res, "%s%d", "R", qc);
            strcpy((yyval.expression).nomVariable, res);
            (yyval.expression).isVariable = true;

            // Generate quadruplet for the unary minus operation
            Quadruplet = addQuad(Quadruplet, "-", "0", buff, res, qc);
            qc++;
        } else {
            // Check if the expression is a float
            if ((yyvsp[0].expression).type == TYPE_FLOAT) {
                (yyval.expression).type = TYPE_FLOAT;
                (yyval.expression).valeurFloat = 0.0 - (yyvsp[0].expression).valeurFloat;

                // Create temporary buffers and result variable
                char buff[255];
                char res[20];
                sprintf(buff, "%f", (yyvsp[0].expression).valeurFloat);
                sprintf(res, "%s%d", "R", qc);

                // Generate quadruplet for the unary minus operation
                Quadruplet = addQuad(Quadruplet, "-", "0", buff, res, qc);
                qc++;
            }
        }
    } else {
        // Error handling for unary minus applied to a string
        yyerrorSemantic("Y'a pas une expression arithmétique");
    }
}
#line 2555 "syntaxic.tab.c"
    break;

  case 42: /* Expression: Expression TOK_AND Expression  */
#line 1008 "syntaxic.y"
                                {
    // Check if both operands are of type boolean
    if ((yyvsp[-2].expression).type == TYPE_BOOLEAN && (yyvsp[0].expression).type == TYPE_BOOLEAN) {
        // Perform logical AND operation
        if ((yyvsp[-2].expression).Valeurboolean && (yyvsp[0].expression).Valeurboolean) {
            (yyval.expression).Valeurboolean = true;
        } else {
            (yyval.expression).Valeurboolean = false;
        }

        // Create temporary buffers and result variable
        char buff[255];
        char buff2[255];
        char res[20];
        sprintf(res, "%s%d", "R", qc);
        strcpy((yyval.expression).nomVariable, res);
        (yyval.expression).isVariable = true;

        // Generate quadruplet for logical AND operation
        if ((yyvsp[-2].expression).isVariable == true && (yyvsp[0].expression).isVariable == true) {
            Quadruplet = addQuad(Quadruplet, "AND", (yyvsp[-2].expression).nomVariable, (yyvsp[0].expression).nomVariable, res, qc);
        } else {
            if ((yyvsp[-2].expression).isVariable == true) {
                strcpy(buff2, ((yyvsp[0].expression).Valeurboolean == true) ? "true" : "false");
                Quadruplet = addQuad(Quadruplet, "AND", (yyvsp[-2].expression).nomVariable, buff2, res, qc);
            } else {
                if ((yyvsp[0].expression).isVariable == true) {
                    strcpy(buff, ((yyvsp[-2].expression).Valeurboolean == true) ? "true" : "false");
                    Quadruplet = addQuad(Quadruplet, "AND", buff, (yyvsp[0].expression).nomVariable, res, qc);
                } else {
                    strcpy(buff, ((yyvsp[-2].expression).Valeurboolean == true) ? "true" : "false");
                    strcpy(buff2, ((yyvsp[0].expression).Valeurboolean == true) ? "true" : "false");
                    Quadruplet = addQuad(Quadruplet, "AND", buff, buff2, res, qc);
                }
            }
        }
        qc++;
    } else {
        // Error handling for incompatible types
        yyerrorSemantic("Type Incompatible");
    }
}
#line 2602 "syntaxic.tab.c"
    break;

  case 43: /* Expression: Expression TOK_OR Expression  */
#line 1052 "syntaxic.y"
                               {
    // Check if both operands are of type boolean
    if ((yyvsp[-2].expression).type == TYPE_BOOLEAN && (yyvsp[0].expression).type == TYPE_BOOLEAN) {
        // Perform logical OR operation
        if ((yyvsp[-2].expression).Valeurboolean || (yyvsp[0].expression).Valeurboolean) {
            (yyval.expression).Valeurboolean = true;
        } else {
            (yyval.expression).Valeurboolean = false;
        }

        // Create temporary buffers and result variable
        char buff[255];
        char buff2[255];
        char res[20];
        sprintf(res, "%s%d", "R", qc);
        strcpy((yyval.expression).nomVariable, res);
        (yyval.expression).isVariable = true;

        // Generate quadruplet for logical OR operation
        if ((yyvsp[-2].expression).isVariable == true && (yyvsp[0].expression).isVariable == true) {
            Quadruplet = addQuad(Quadruplet, "OR", (yyvsp[-2].expression).nomVariable, (yyvsp[0].expression).nomVariable, res, qc);
        } else {
            if ((yyvsp[-2].expression).isVariable == true) {
                strcpy(buff2, ((yyvsp[0].expression).Valeurboolean == true) ? "true" : "false");
                Quadruplet = addQuad(Quadruplet, "OR", (yyvsp[-2].expression).nomVariable, buff2, res, qc);
            } else {
                if ((yyvsp[0].expression).isVariable == true) {
                    strcpy(buff, ((yyvsp[-2].expression).Valeurboolean == true) ? "true" : "false");
                    Quadruplet = addQuad(Quadruplet, "OR", buff, (yyvsp[0].expression).nomVariable, res, qc);
                } else {
                    strcpy(buff, ((yyvsp[-2].expression).Valeurboolean == true) ? "true" : "false");
                    strcpy(buff2, ((yyvsp[0].expression).Valeurboolean == true) ? "true" : "false");
                    Quadruplet = addQuad(Quadruplet, "OR", buff, buff2, res, qc);
                }
            }
        }
        qc++;
    } else {
        // Error handling for incompatible types
        yyerrorSemantic("Type Incompatible");
    }
}
#line 2649 "syntaxic.tab.c"
    break;

  case 44: /* Expression: Expression TOK_ADD Expression  */
#line 1096 "syntaxic.y"
                               {
    // Check if both operands are of the same type
    if((yyvsp[-2].expression).type == (yyvsp[0].expression).type){
        // If the type is string, concatenate the strings
        if((yyvsp[-2].expression).type == TYPE_STRING){
            strcpy((yyval.expression).valeurString, (yyvsp[-2].expression).valeurString);
            strcat((yyval.expression).valeurString, (yyvsp[0].expression).valeurString);

            // Create temporary buffers and result variable
            char buff[255];
            char buff2[255];
            char res[20];
            sprintf(res, "%s%d", "R", qc);
            strcpy((yyval.expression).nomVariable, res);
            (yyval.expression).isVariable = true;

            // Generate quadruplet for string concatenation
            if((yyvsp[-2].expression).isVariable == true && (yyvsp[0].expression).isVariable == true){
                Quadruplet = addQuad(Quadruplet, "+", (yyvsp[-2].expression).nomVariable, (yyvsp[0].expression).nomVariable, res, qc);
            } else {
                if((yyvsp[-2].expression).isVariable == true){
                    Quadruplet = addQuad(Quadruplet, "+", (yyvsp[-2].expression).nomVariable, (yyvsp[0].expression).valeurString, res, qc);
                } else {
                    if((yyvsp[0].expression).isVariable == true){
                        Quadruplet = addQuad(Quadruplet, "+", (yyvsp[-2].expression).valeurString, (yyvsp[0].expression).nomVariable, res, qc);
                    } else {
                        Quadruplet = addQuad(Quadruplet, "+", (yyvsp[-2].expression).valeurString, (yyvsp[0].expression).valeurString, res, qc);
                    }
                }
            }
            qc++;
        } else {
            // For integer, float, and boolean types, perform arithmetic or boolean addition
            if((yyvsp[-2].expression).type == TYPE_INTEGER){
                (yyval.expression).valeurInteger = (yyvsp[-2].expression).valeurInteger + (yyvsp[0].expression).valeurInteger;

                // Create temporary buffers and result variable
                char buff[255];
                char buff2[255];
                char res[20];
                sprintf(res, "%s%d", "R", qc);
                strcpy((yyval.expression).nomVariable, res);
                (yyval.expression).isVariable = true;

                // Generate quadruplet for integer addition
                if((yyvsp[-2].expression).isVariable == true && (yyvsp[0].expression).isVariable == true){
                    Quadruplet = addQuad(Quadruplet, "+", (yyvsp[-2].expression).nomVariable, (yyvsp[0].expression).nomVariable, res, qc);
                } else {
                    if((yyvsp[-2].expression).isVariable == true){
                        sprintf(buff2, "%d", (yyvsp[0].expression).valeurInteger);
                        Quadruplet = addQuad(Quadruplet, "+", (yyvsp[-2].expression).nomVariable, buff2, res, qc);
                    } else {
                        if((yyvsp[0].expression).isVariable == true){
                            sprintf(buff, "%d", (yyvsp[-2].expression).valeurInteger);
                            Quadruplet = addQuad(Quadruplet, "+", buff, (yyvsp[0].expression).nomVariable, res, qc);
                        } else {
                            sprintf(buff, "%d", (yyvsp[-2].expression).valeurInteger);
                            sprintf(buff2, "%d", (yyvsp[0].expression).valeurInteger);
                            Quadruplet = addQuad(Quadruplet, "+", buff, buff2, res, qc);
                        }
                    }
                }
                qc++;
            } else if((yyvsp[-2].expression).type == TYPE_FLOAT){
                (yyval.expression).valeurFloat = (yyvsp[-2].expression).valeurFloat + (yyvsp[0].expression).valeurFloat;

                // Create temporary buffers and result variable
                char buff[255];
                char buff2[255];
                char res[20];
                sprintf(res, "%s%d", "R", qc);
                strcpy((yyval.expression).nomVariable, res);
                (yyval.expression).isVariable = true;

                // Generate quadruplet for float addition
                if((yyvsp[-2].expression).isVariable == true && (yyvsp[0].expression).isVariable == true){
                    Quadruplet = addQuad(Quadruplet, "+", (yyvsp[-2].expression).nomVariable, (yyvsp[0].expression).nomVariable, res, qc);
                } else {
                    if((yyvsp[-2].expression).isVariable == true){
                        sprintf(buff2, "%f", (yyvsp[0].expression).valeurFloat);
                        Quadruplet = addQuad(Quadruplet, "+", (yyvsp[-2].expression).nomVariable, buff2, res, qc);
                    } else {
                        if((yyvsp[0].expression).isVariable == true){
                            sprintf(buff, "%f", (yyvsp[-2].expression).valeurFloat);
                            Quadruplet = addQuad(Quadruplet, "+", buff, (yyvsp[0].expression).nomVariable, res, qc);
                        } else {
                            sprintf(buff, "%f", (yyvsp[-2].expression).valeurFloat);
                            sprintf(buff2, "%f", (yyvsp[0].expression).valeurFloat);
                            Quadruplet = addQuad(Quadruplet, "+", buff, buff2, res, qc);
                        }
                    }
                }
                qc++;
            } else if((yyvsp[-2].expression).type == TYPE_BOOLEAN){
                (yyval.expression).type = TYPE_BOOLEAN;
                // Perform boolean OR operation
                if(((yyvsp[-2].expression).Valeurboolean) || ((yyvsp[0].expression).Valeurboolean)){
                    (yyval.expression).Valeurboolean = true;
                } else {
                    (yyval.expression).Valeurboolean = false;
                }

                // Create temporary buffers and result variable
                char buff[255];
                char buff2[255];
                char res[20];
                sprintf(res, "%s%d", "R", qc);
                strcpy((yyval.expression).nomVariable, res);
                (yyval.expression).isVariable = true;

                // Generate quadruplet for boolean OR operation
                if((yyvsp[-2].expression).isVariable == true && (yyvsp[0].expression).isVariable == true){
                    Quadruplet = addQuad(Quadruplet, "+", (yyvsp[-2].expression).nomVariable, (yyvsp[0].expression).nomVariable, res, qc);
                } else {
                    if((yyvsp[-2].expression).isVariable == true){
                        strcpy(buff, ((yyvsp[0].expression).Valeurboolean == true) ? "true" : "false");
                        Quadruplet = addQuad(Quadruplet, "+", (yyvsp[-2].expression).nomVariable, buff2, res, qc);
                    } else {
                        if((yyvsp[0].expression).isVariable == true){
                            strcpy(buff, ((yyvsp[-2].expression).Valeurboolean == true) ? "true" : "false");
                            Quadruplet = addQuad(Quadruplet, "+", buff, (yyvsp[0].expression).nomVariable, res, qc);
                        } else {
                            strcpy(buff, ((yyvsp[-2].expression).Valeurboolean == true) ? "true" : "false");
                            strcpy(buff2, ((yyvsp[0].expression).Valeurboolean == true) ? "true" : "false");
                            Quadruplet = addQuad(Quadruplet, "+", buff, buff2, res, qc);
                        }
                    }
                }
                qc++;
            }
        }
    }
    else {
        // Error handling for incompatible types
        yyerrorSemantic("Type Incompatible");
    }
}
#line 2791 "syntaxic.tab.c"
    break;

  case 45: /* Expression: Expression TOK_SUB Expression  */
#line 1235 "syntaxic.y"
                               {
    // Check if both operands are of the same type and not string
    if((yyvsp[-2].expression).type == (yyvsp[0].expression).type && (yyvsp[0].expression).type != TYPE_STRING){
        // Check if subtraction involves boolean type (not supported)
        if((yyvsp[-2].expression).type == TYPE_BOOLEAN ){
            yyerrorSemantic("Could not perform subtraction of boolean");
        }
        else{
            // Perform subtraction for integer and float types
            if((yyvsp[-2].expression).type == TYPE_INTEGER){
                (yyval.expression).valeurInteger = (yyvsp[-2].expression).valeurInteger - (yyvsp[0].expression).valeurInteger;

                // Create temporary buffers and result variable
                char buff[255];
                char buff2[255];
                char res[20];
                sprintf(res, "%s%d", "R", qc);
                strcpy((yyval.expression).nomVariable, res);
                (yyval.expression).isVariable = true;

                // Generate quadruplet for integer subtraction
                if((yyvsp[-2].expression).isVariable == true & (yyvsp[0].expression).isVariable == true) {
                    Quadruplet = addQuad(Quadruplet, "-", (yyvsp[-2].expression).nomVariable, (yyvsp[0].expression).nomVariable, res, qc);
                }
                else{
                    if((yyvsp[-2].expression).isVariable == true){
                        sprintf(buff2, "%d", (yyvsp[0].expression).valeurInteger);
                        Quadruplet = addQuad(Quadruplet, "-", (yyvsp[-2].expression).nomVariable, buff2, res, qc);
                    }
                    else{
                        if((yyvsp[0].expression).isVariable == true){
                            sprintf(buff, "%d", (yyvsp[-2].expression).valeurInteger);
                            Quadruplet = addQuad(Quadruplet, "-", buff, (yyvsp[0].expression).nomVariable, res, qc);
                        }
                        else{
                            sprintf(buff, "%d", (yyvsp[-2].expression).valeurInteger);
                            sprintf(buff2, "%d", (yyvsp[0].expression).valeurInteger);
                            Quadruplet = addQuad(Quadruplet, "-", buff, buff2, res, qc);
                        }
                    }
                }
                qc++;
            }
            else {
                if((yyvsp[-2].expression).type == TYPE_FLOAT){
                    (yyval.expression).valeurFloat = (yyvsp[-2].expression).valeurFloat - (yyvsp[0].expression).valeurFloat;

                    // Create temporary buffers and result variable
                    char buff[255];
                    char buff2[255];
                    char res[20];
                    sprintf(res, "%s%d", "R", qc);
                    strcpy((yyval.expression).nomVariable, res);
                    (yyval.expression).isVariable = true;

                    // Generate quadruplet for float subtraction
                    if((yyvsp[-2].expression).isVariable == true & (yyvsp[0].expression).isVariable == true){
                        Quadruplet = addQuad(Quadruplet, "-", (yyvsp[-2].expression).nomVariable, (yyvsp[0].expression).nomVariable, res, qc);
                    }
                    else{
                        if((yyvsp[-2].expression).isVariable == true){
                            sprintf(buff2, "%f", (yyvsp[0].expression).valeurFloat);
                            Quadruplet = addQuad(Quadruplet, "-", (yyvsp[-2].expression).nomVariable, buff2, res, qc);
                        }
                        else{
                            if((yyvsp[0].expression).isVariable == true){
                                sprintf(buff, "%f", (yyvsp[-2].expression).valeurFloat);
                                Quadruplet = addQuad(Quadruplet, "-", buff, (yyvsp[0].expression).nomVariable, res, qc);
                            }
                            else{
                                sprintf(buff, "%f", (yyvsp[-2].expression).valeurFloat);
                                sprintf(buff2, "%f", (yyvsp[0].expression).valeurFloat);
                                Quadruplet = addQuad(Quadruplet, "-", buff, buff2, res, qc);
                            }
                        }
                    }
                    qc++;
                }
            }
        }
    }
    else {
        // Error handling for incompatible types
        yyerrorSemantic("Type Incompatible");
    }
}
#line 2882 "syntaxic.tab.c"
    break;

  case 46: /* Expression: Expression TOK_MUL Expression  */
#line 1323 "syntaxic.y"
                                {
    // Check if both operands are of the same type
    if((yyvsp[-2].expression).type == (yyvsp[0].expression).type){
        // Check if the common type is integer
        if((yyvsp[-2].expression).type == TYPE_INTEGER){
            // Perform multiplication for integer type
            (yyval.expression).valeurInteger = (yyvsp[-2].expression).valeurInteger * (yyvsp[0].expression).valeurInteger;

            // Create temporary buffers and result variable
            char buff[255];
            char buff2[255];
            char res[20];
            sprintf(res, "%s%d", "R", qc);
            strcpy((yyval.expression).nomVariable, res);
            (yyval.expression).isVariable = true;

            // Generate quadruplet for integer multiplication
            if((yyvsp[-2].expression).isVariable == true & (yyvsp[0].expression).isVariable == true){
                Quadruplet = addQuad(Quadruplet, "*", (yyvsp[-2].expression).nomVariable, (yyvsp[0].expression).nomVariable, res, qc);
            }
            else{
                if((yyvsp[-2].expression).isVariable == true){
                    sprintf(buff2, "%d", (yyvsp[0].expression).valeurInteger);
                    Quadruplet = addQuad(Quadruplet, "*", (yyvsp[-2].expression).nomVariable, buff2, res, qc);
                }
                else{
                    if((yyvsp[0].expression).isVariable == true){
                        sprintf(buff, "%d", (yyvsp[-2].expression).valeurInteger);
                        Quadruplet = addQuad(Quadruplet, "*", buff, (yyvsp[0].expression).nomVariable, res, qc);
                    }
                    else{
                        sprintf(buff, "%d", (yyvsp[-2].expression).valeurInteger);
                        sprintf(buff2, "%d", (yyvsp[0].expression).valeurInteger);
                        Quadruplet = addQuad(Quadruplet, "*", buff, buff2, res, qc);
                    }
                }
            }
            qc++;
        }
        else {
            // Check if the common type is float
            if((yyvsp[-2].expression).type == TYPE_FLOAT){
                // Perform multiplication for float type
                (yyval.expression).valeurFloat = (yyvsp[-2].expression).valeurFloat * (yyvsp[0].expression).valeurFloat;

                // Create temporary buffers and result variable
                char buff[255];
                char buff2[255];
                char res[20];
                sprintf(res, "%s%d", "R", qc);
                strcpy((yyval.expression).nomVariable, res);
                (yyval.expression).isVariable = true;

                // Generate quadruplet for float multiplication
                if((yyvsp[-2].expression).isVariable == true & (yyvsp[0].expression).isVariable == true){
                    Quadruplet = addQuad(Quadruplet, "*", (yyvsp[-2].expression).nomVariable, (yyvsp[0].expression).nomVariable, res, qc);
                }
                else{
                    if((yyvsp[-2].expression).isVariable == true){
                        sprintf(buff2, "%f", (yyvsp[0].expression).valeurFloat);
                        Quadruplet = addQuad(Quadruplet, "*", (yyvsp[-2].expression).nomVariable, buff2, res, qc);
                    }
                    else{
                        if((yyvsp[0].expression).isVariable == true){
                            sprintf(buff, "%f", (yyvsp[-2].expression).valeurFloat);
                            Quadruplet = addQuad(Quadruplet, "*", buff, (yyvsp[0].expression).nomVariable, res, qc);
                        }
                        else{
                            sprintf(buff, "%f", (yyvsp[-2].expression).valeurFloat);
                            sprintf(buff2, "%f", (yyvsp[0].expression).valeurFloat);
                            Quadruplet = addQuad(Quadruplet, "*", buff, buff2, res, qc);
                        }
                    }
                }
                qc++;
            }
            else {
                // Check if the common type is boolean
                if((yyvsp[-2].expression).type == TYPE_BOOLEAN){
                    (yyval.expression).type = TYPE_BOOLEAN;

                    // Perform multiplication for boolean type
                    if(((yyvsp[-2].expression).Valeurboolean) && ((yyvsp[0].expression).Valeurboolean)){
                        (yyval.expression).Valeurboolean = true;
                    }
                    else{
                        (yyval.expression).Valeurboolean = false;
                    };

                    // Create temporary buffers and result variable
                    char buff[255];
                    char buff2[255];
                    char res[20];
                    sprintf(res, "%s%d", "R", qc);
                    strcpy((yyval.expression).nomVariable, res);
                    (yyval.expression).isVariable = true;

                    // Generate quadruplet for boolean multiplication
                    if((yyvsp[-2].expression).isVariable == true & (yyvsp[0].expression).isVariable == true){
                        Quadruplet = addQuad(Quadruplet, "*", (yyvsp[-2].expression).nomVariable, (yyvsp[0].expression).nomVariable, res, qc);
                    }
                    else{
                        if((yyvsp[-2].expression).isVariable == true) {
                            strcpy(buff, ((yyvsp[0].expression).Valeurboolean == true) ? "true" : "false");
                            Quadruplet = addQuad(Quadruplet, "*", (yyvsp[-2].expression).nomVariable, buff2, res, qc);
                        }
                        else{
                            if((yyvsp[0].expression).isVariable == true){
                                strcpy(buff, ((yyvsp[-2].expression).Valeurboolean == true) ? "true" : "false");
                                Quadruplet = addQuad(Quadruplet, "*", buff, (yyvsp[0].expression).nomVariable, res, qc);
                            }
                            else{
                                strcpy(buff, ((yyvsp[-2].expression).Valeurboolean == true) ? "true" : "false");
                                strcpy(buff2, ((yyvsp[0].expression).Valeurboolean == true) ? "true" : "false");
                                Quadruplet = addQuad(Quadruplet, "*", buff, buff2, res, qc);
                            }
                        }
                    }
                    qc++;
                }
            }
        }
    }
    else {
        // Error handling for incompatible types
        yyerrorSemantic("Type Incompatible");
    }
}
#line 3015 "syntaxic.tab.c"
    break;

  case 47: /* Expression: Expression TOK_DIV Expression  */
#line 1452 "syntaxic.y"
                                {
    // Check if both operands are of the same type
    if((yyvsp[-2].expression).type == (yyvsp[0].expression).type){
        // Check for division by zero
        if((((yyvsp[0].expression).type == TYPE_INTEGER) && ((yyvsp[0].expression).valeurInteger == 0)) || (((yyvsp[0].expression).type == TYPE_FLOAT) && ((yyvsp[0].expression).valeurFloat == 0.0))){
            yyerrorSemantic("Division by zero");
        }
        else {
            // Check if the common type is string
            if((yyvsp[-2].expression).type == TYPE_STRING){
                yyerrorSemantic("Type Incompatible");
            }
            else {
                // Check if the common type is integer
                if((yyvsp[-2].expression).type == TYPE_INTEGER){
                    // Perform division for integer type
                    (yyval.expression).valeurInteger = (yyvsp[-2].expression).valeurInteger / (yyvsp[0].expression).valeurInteger;

                    // Create temporary buffers and result variable
                    char buff[255];
                    char buff2[255];
                    char res[20];
                    sprintf(res, "%s%d", "R", qc);
                    strcpy((yyval.expression).nomVariable, res);
                    (yyval.expression).isVariable = true;

                    // Generate quadruplet for integer division
                    if((yyvsp[-2].expression).isVariable == true && (yyvsp[0].expression).isVariable == true){
                        Quadruplet = addQuad(Quadruplet, "/", (yyvsp[-2].expression).nomVariable, (yyvsp[0].expression).nomVariable, res, qc);
                        qc++;
                    }
                    else {
                        if((yyvsp[-2].expression).isVariable == true){
                            sprintf(buff2, "%d", (yyvsp[0].expression).valeurInteger);
                            Quadruplet = addQuad(Quadruplet, "/", (yyvsp[-2].expression).nomVariable, buff2, res, qc);
                            qc++;
                        }
                        else {
                            if((yyvsp[0].expression).isVariable == true){
                                sprintf(buff, "%d", (yyvsp[-2].expression).valeurInteger);
                                Quadruplet = addQuad(Quadruplet, "/", buff, (yyvsp[0].expression).nomVariable, res, qc);
                                qc++;
                            }
                            else {
                                sprintf(buff, "%d", (yyvsp[-2].expression).valeurInteger);
                                sprintf(buff2, "%d", (yyvsp[0].expression).valeurInteger);
                                sprintf(res, "%s%d", "R", qc);
                                Quadruplet = addQuad(Quadruplet, "/", buff, buff2, res, qc);
                                qc++;
                            }
                        }
                    }
                }
                else {
                    // Check if the common type is float
                    if((yyvsp[-2].expression).type == TYPE_FLOAT){
                        // Perform division for float type
                        (yyval.expression).valeurFloat = (yyvsp[-2].expression).valeurFloat / (yyvsp[0].expression).valeurFloat;

                        // Create temporary buffers and result variable
                        char buff2[255];
                        char buff[255];
                        char res[20];
                        sprintf(res, "%s%d", "R", qc);
                        strcpy((yyval.expression).nomVariable, res);
                        (yyval.expression).isVariable = true;

                        // Generate quadruplet for float division
                        if((yyvsp[-2].expression).isVariable == true && (yyvsp[0].expression).isVariable == true){
                            Quadruplet = addQuad(Quadruplet, "/", (yyvsp[-2].expression).nomVariable, (yyvsp[0].expression).nomVariable, res, qc);
                            qc++;
                        }
                        else {
                            if((yyvsp[-2].expression).isVariable == true){
                                sprintf(buff2, "%f", (yyvsp[0].expression).valeurFloat);
                                Quadruplet = addQuad(Quadruplet, "/", (yyvsp[-2].expression).nomVariable, buff2, res, qc);
                                qc++;
                            }
                            else {
                                if((yyvsp[0].expression).isVariable == true){
                                    sprintf(buff, "%f", (yyvsp[-2].expression).valeurFloat);
                                    Quadruplet = addQuad(Quadruplet, "/", buff, (yyvsp[0].expression).nomVariable, res, qc);
                                    qc++;
                                }
                                else {
                                    sprintf(buff, "%f", (yyvsp[-2].expression).valeurFloat);
                                    sprintf(buff2, "%f", (yyvsp[0].expression).valeurFloat);
                                    sprintf(res, "%s%d", "R", qc);
                                    Quadruplet = addQuad(Quadruplet, "/", buff, buff2, res, qc);
                                    qc++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else {
        // Error handling for incompatible types
        yyerrorSemantic("Type Incompatible");
    }
}
#line 3123 "syntaxic.tab.c"
    break;

  case 48: /* Expression: Expression TOK_MOD Expression  */
#line 1556 "syntaxic.y"
                                {
    // Check if both operands are of the same type
    if((yyvsp[-2].expression).type == (yyvsp[0].expression).type){
        // Check for division by zero
        if((((yyvsp[0].expression).type == TYPE_INTEGER) && ((yyvsp[0].expression).valeurInteger == 0)) || (((yyvsp[0].expression).type == TYPE_FLOAT) && ((yyvsp[0].expression).valeurFloat == 0.0))){
            yyerrorSemantic("Division by zero");
        }
        else {
            // Check if the common type is string
            if((yyval.expression).type == TYPE_STRING){
                yyerrorSemantic("Type Incompatible");
            }
            else {
                // Check if the common type is integer
                if((yyval.expression).type == TYPE_INTEGER){
                    // Perform modulo for integer type
                    (yyval.expression).valeurInteger = (yyvsp[-2].expression).valeurInteger % (yyvsp[0].expression).valeurInteger;

                    // Temporary buffers and result variable
                    char buff[255];
                    char buff2[255];
                    char res[20];
                    sprintf(res, "%s%d", "R", qc);
                    strcpy((yyval.expression).nomVariable, res);
                    (yyval.expression).isVariable = true;

                    // Generate quadruplets for integer modulo
                    if((yyvsp[-2].expression).isVariable == true && (yyvsp[0].expression).isVariable == true){
                        Quadruplet = addQuad(Quadruplet, "/", (yyvsp[-2].expression).nomVariable, (yyvsp[0].expression).nomVariable, res, qc);
                        qc++;
                        sprintf(res, "%s%d", "R", qc);
                        Quadruplet = addQuad(Quadruplet, "*", (yyvsp[-2].expression).nomVariable, (yyvsp[0].expression).nomVariable, res, qc);
                        qc++;
                        sprintf(res, "%s%d", "R", qc);
                        Quadruplet = addQuad(Quadruplet, "-", (yyvsp[-2].expression).nomVariable, (yyvsp[0].expression).nomVariable, res, qc);
                        sprintf(res, "%s%d", "R", qc);
                        strcpy((yyval.expression).nomVariable, res);
                        (yyval.expression).isVariable = true;
                        qc++;
                    }
                    else {
                        if((yyvsp[-2].expression).isVariable == true){
                            sprintf(buff2, "%d", (yyvsp[0].expression).valeurInteger);
                            Quadruplet = addQuad(Quadruplet, "/", (yyvsp[-2].expression).nomVariable, buff2, res, qc);
                            qc++;
                            sprintf(buff2, "%d", (yyvsp[0].expression).valeurInteger);
                            sprintf(res, "%s%d", "R", qc);
                            Quadruplet = addQuad(Quadruplet, "*", (yyvsp[-2].expression).nomVariable, buff2, res, qc);
                            qc++;
                            strcpy(buff2, res);
                            sprintf(res, "%s%d", "R", qc);
                            Quadruplet = addQuad(Quadruplet, "-", (yyvsp[-2].expression).nomVariable, buff2, res, qc);
                            sprintf(res, "%s%d", "R", qc);
                            strcpy((yyval.expression).nomVariable, res);
                            (yyval.expression).isVariable = true;
                            qc++;
                        }
                        else {
                            if((yyvsp[0].expression).isVariable == true){
                                sprintf(buff, "%d", (yyvsp[-2].expression).valeurInteger);
                                Quadruplet = addQuad(Quadruplet, "/", buff, (yyvsp[0].expression).nomVariable, res, qc);
                                qc++;
                                strcpy(buff, res);
                                sprintf(res, "%s%d", "R", qc);
                                Quadruplet = addQuad(Quadruplet, "*", buff, (yyvsp[0].expression).nomVariable, res, qc);
                                qc++;
                                sprintf(buff, "%d", (yyvsp[-2].expression).valeurInteger);
                                sprintf(res, "%s%d", "R", qc);
                                Quadruplet = addQuad(Quadruplet, "-", buff, (yyvsp[0].expression).nomVariable, res, qc);
                                sprintf(res, "%s%d", "R", qc);
                                strcpy((yyval.expression).nomVariable, res);
                                (yyval.expression).isVariable = true;
                                qc++;
                            }
                            else {
                                sprintf(buff, "%d", (yyvsp[-2].expression).valeurInteger);
                                sprintf(buff2, "%d", (yyvsp[0].expression).valeurInteger);
                                Quadruplet = addQuad(Quadruplet, "/", buff, buff2, res, qc);
                                qc++;
                                strcpy(buff, res);
                                sprintf(buff2, "%d", (yyvsp[0].expression).valeurInteger);
                                sprintf(res, "%s%d", "R", qc);
                                Quadruplet = addQuad(Quadruplet, "*", buff, buff2, res, qc);
                                qc++;
                                sprintf(buff, "%d", (yyvsp[-2].expression).valeurInteger);
                                strcpy(buff2, res);
                                sprintf(res, "%s%d", "R", qc);
                                Quadruplet = addQuad(Quadruplet, "-", buff, buff2, res, qc);
                                sprintf(res, "%s%d", "R", qc);
                                strcpy((yyval.expression).nomVariable, res);
                                (yyval.expression).isVariable = true;
                                qc++;
                            }
                        }
                    }
                }
                else {
                    // Check if the common type is float
                    if((yyval.expression).type == TYPE_FLOAT){
                        // Perform modulo for float type
                        (yyval.expression).valeurFloat = fmod((yyvsp[-2].expression).valeurFloat, (yyvsp[0].expression).valeurFloat);

                        // Temporary buffers and result variable
                        char buff2[255];
                        char buff[255];
                        char res[20];
                        sprintf(res, "%s%d", "R", qc);
                        strcpy((yyval.expression).nomVariable, res);
                        (yyval.expression).isVariable = true;

                        // Generate quadruplets for float modulo
                        if((yyvsp[-2].expression).isVariable == true && (yyvsp[0].expression).isVariable == true){
                            Quadruplet = addQuad(Quadruplet, "/", (yyvsp[-2].expression).nomVariable, (yyvsp[0].expression).nomVariable, res, qc);
                            qc++;
                            sprintf(res, "%s%d", "R", qc);
                            Quadruplet = addQuad(Quadruplet, "*", (yyvsp[-2].expression).nomVariable, (yyvsp[0].expression).nomVariable, res, qc);
                            qc++;
                            sprintf(res, "%s%d", "R", qc);
                            Quadruplet = addQuad(Quadruplet, "-", (yyvsp[-2].expression).nomVariable, (yyvsp[0].expression).nomVariable, res, qc);
                            sprintf(res, "%s%d", "R", qc);
                            strcpy((yyval.expression).nomVariable, res);
                            (yyval.expression).isVariable = true;
                            qc++;
                        }
                        else {
                            if((yyvsp[-2].expression).isVariable == true){
                                sprintf(buff2, "%f", (yyvsp[0].expression).valeurFloat);
                                Quadruplet = addQuad(Quadruplet, "/", (yyvsp[-2].expression).nomVariable, buff2, res, qc);
                                qc++;
                                sprintf(buff2, "%f", (yyvsp[0].expression).valeurFloat);
                                sprintf(res, "%s%d", "R", qc);
                                Quadruplet = addQuad(Quadruplet, "*", (yyvsp[-2].expression).nomVariable, buff2, res, qc);
                                qc++;
                                strcpy(buff2, res);
                                sprintf(res, "%s%d", "R", qc);
                                Quadruplet = addQuad(Quadruplet, "-", (yyvsp[-2].expression).nomVariable, buff2, res, qc);
                                sprintf(res, "%s%d", "R", qc);
                                strcpy((yyval.expression).nomVariable, res);
                                (yyval.expression).isVariable = true;
                                qc++;
                            }
                            else {
                                if((yyvsp[0].expression).isVariable == true){
                                    sprintf(buff, "%f", (yyvsp[-2].expression).valeurFloat);
                                    Quadruplet = addQuad(Quadruplet, "/", buff, (yyvsp[0].expression).nomVariable, res, qc);
                                    qc++;
                                    strcpy(buff, res);
                                    sprintf(res, "%s%d", "R", qc);
                                    Quadruplet = addQuad(Quadruplet, "*", buff, (yyvsp[0].expression).nomVariable, res, qc);
                                    qc++;
                                    sprintf(buff, "%f", (yyvsp[-2].expression).valeurFloat);
                                    sprintf(res, "%s%d", "R", qc);
                                    Quadruplet = addQuad(Quadruplet, "-", buff, (yyvsp[0].expression).nomVariable, res, qc);
                                    sprintf(res, "%s%d", "R", qc);
                                    strcpy((yyval.expression).nomVariable, res);
                                    (yyval.expression).isVariable = true;
                                    qc++;
                                }
                                else {
                                    sprintf(buff, "%f", (yyvsp[-2].expression).valeurFloat);
                                    sprintf(buff2, "%f", (yyvsp[0].expression).valeurFloat);
                                    Quadruplet = addQuad(Quadruplet, "/", buff, buff2, res, qc);
                                    qc++;
                                    strcpy(buff, res);
                                    sprintf(buff2, "%f", (yyvsp[0].expression).valeurFloat);
                                    sprintf(res, "%s%d", "R", qc);
                                    Quadruplet = addQuad(Quadruplet, "*", buff, buff2, res, qc);
                                    qc++;
                                    sprintf(buff, "%f", (yyvsp[-2].expression).valeurFloat);
                                    strcpy(buff2, res);
                                    sprintf(res, "%s%d", "R", qc);
                                    Quadruplet = addQuad(Quadruplet, "-", buff, buff2, res, qc);
                                    sprintf(res, "%s%d", "R", qc);
                                    strcpy((yyval.expression).nomVariable, res);
                                    (yyval.expression).isVariable = true;
                                    qc++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else {
        // Error handling for incompatible types
        yyerrorSemantic("Type Incompatible");
    }
}
#line 3317 "syntaxic.tab.c"
    break;

  case 52: /* Valeur: TOK_INT_T  */
#line 1751 "syntaxic.y"
                  { (yyval.expression).type = TYPE_INTEGER; (yyval.expression).valeurInteger = (yyvsp[0].valeurInteger); }
#line 3323 "syntaxic.tab.c"
    break;

  case 53: /* Valeur: TOK_FLOAT_T  */
#line 1752 "syntaxic.y"
                  { (yyval.expression).type = TYPE_FLOAT; (yyval.expression).valeurFloat = (yyvsp[0].valeurFloat); }
#line 3329 "syntaxic.tab.c"
    break;

  case 54: /* Valeur: TOK_STR_T  */
#line 1753 "syntaxic.y"
                  { (yyval.expression).type = TYPE_STRING; strcpy((yyval.expression).valeurString, (yyvsp[0].valeurString));printf("token %s\n",(yyvsp[0].valeurString)); }
#line 3335 "syntaxic.tab.c"
    break;

  case 55: /* Valeur: TOK_TRUE  */
#line 1754 "syntaxic.y"
                  { (yyval.expression).type = TYPE_BOOLEAN; (yyval.expression).Valeurboolean = (yyvsp[0].Valeurboolean); }
#line 3341 "syntaxic.tab.c"
    break;

  case 56: /* Valeur: TOK_FALSE  */
#line 1755 "syntaxic.y"
                  { (yyval.expression).type = TYPE_BOOLEAN; (yyval.expression).Valeurboolean = (yyvsp[0].Valeurboolean); }
#line 3347 "syntaxic.tab.c"
    break;


#line 3351 "syntaxic.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 1850 "syntaxic.y"

void yysuccess(char *s){
    //fprintf(stdout, "%d: %s, col:%d\n", yylineno, s,currentColumn);
    currentColumn+=yyleng;
}

void yyerror(const char *s) {
    fprintf(stdout, "File '%s', line %d, character %d :  %s \n", file, yylineno, currentColumn, s);
}
void yyerrorSemantic(char *s){
    fprintf(stdout, "File '%s', line %d, character %d, ssemantic error:%s\n", file, yylineno, currentColumn, s);
    return;
}

int main (void){
    yydebug = 1;
    yyin = fopen(file,"r");
    if(yyin == NULL){
        printf("error while opening file\n");
        return 1;
    }
    else {
        printf("file successfully opened\n");
    }
    StockSauv = (stockSauv *)malloc(sizeof(stockSauv));
    symboleTable = allocateSymboleTable();
    if (yyparse() == 0) {
        printf("Parsing successful\n");
    } else {
        fprintf(stderr, "Parsing failed\n");
        return 1;
    }
    displaySymbolTable(symboleTable);
    displayQuad(Quadruplet);
    if(symboleTable != NULL){
        free(symboleTable);
    }
    fclose(yyin);
    return 0;
}
void showLexicalError() {

    char line[256], introError[80]; 

    fseek(yyin, 0, SEEK_SET);
    
    int i = 0; 

    while (fgets(line, sizeof(line), yyin)) { 
        i++; 
        if(i == yylineno) break;  
    } 
        
    sprintf(introError, "Lexical error in Line %d : Unrecognized character : ", yylineno);
    printf("%s%s", introError, line);  
    int j=1;
    while(j<currentColumn+strlen(introError)) { printf(" "); j++; }
    printf("^\n");


}





