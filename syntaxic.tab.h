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

#ifndef YY_YY_SYNTAXIC_TAB_H_INCLUDED
# define YY_YY_SYNTAXIC_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 7 "syntaxic.y"

#include "global.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "symboleTable.h"
#include "stockSauv.h"
#include "structure.h"
#include "quadruplet.h"

#line 61 "syntaxic.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TOK_INT = 258,                 /* TOK_INT  */
    TOK_STR = 259,                 /* TOK_STR  */
    TOK_FLOAT = 260,               /* TOK_FLOAT  */
    TOK_BOOL = 261,                /* TOK_BOOL  */
    TOK_ARRAY = 262,               /* TOK_ARRAY  */
    TOK_TYPE = 263,                /* TOK_TYPE  */
    TOK_CONST = 264,               /* TOK_CONST  */
    TOK_IF = 265,                  /* TOK_IF  */
    TOK_ELSE = 266,                /* TOK_ELSE  */
    TOK_ELIF = 267,                /* TOK_ELIF  */
    TOK_RETURN = 268,              /* TOK_RETURN  */
    TOK_SWITCH = 269,              /* TOK_SWITCH  */
    TOK_CASE = 270,                /* TOK_CASE  */
    TOK_BREAK = 271,               /* TOK_BREAK  */
    TOK_DEFAULT = 272,             /* TOK_DEFAULT  */
    TOK_FOR = 273,                 /* TOK_FOR  */
    TOK_WHILE = 274,               /* TOK_WHILE  */
    TOK_FOREACH = 275,             /* TOK_FOREACH  */
    TOK_IN = 276,                  /* TOK_IN  */
    TOK_INPUT = 277,               /* TOK_INPUT  */
    TOK_PRINT = 278,               /* TOK_PRINT  */
    TOK_DEF = 279,                 /* TOK_DEF  */
    TOK_AS = 280,                  /* TOK_AS  */
    TOK_FROM = 281,                /* TOK_FROM  */
    TOK_IMPORT = 282,              /* TOK_IMPORT  */
    TOK_INT_T = 283,               /* TOK_INT_T  */
    TOK_FLOAT_T = 284,             /* TOK_FLOAT_T  */
    TOK_STR_T = 285,               /* TOK_STR_T  */
    TOK_BOOl_T = 286,              /* TOK_BOOl_T  */
    TOK_TRUE = 287,                /* TOK_TRUE  */
    TOK_FALSE = 288,               /* TOK_FALSE  */
    TOK_ADD = 289,                 /* TOK_ADD  */
    TOK_SUB = 290,                 /* TOK_SUB  */
    TOK_MUL = 291,                 /* TOK_MUL  */
    TOK_DIV = 292,                 /* TOK_DIV  */
    TOK_MOD = 293,                 /* TOK_MOD  */
    TOK_INC = 294,                 /* TOK_INC  */
    TOK_DEC = 295,                 /* TOK_DEC  */
    TOK_POW = 296,                 /* TOK_POW  */
    TOK_FLOOR_DIV = 297,           /* TOK_FLOOR_DIV  */
    TOK_ADD_ASSIGN = 298,          /* TOK_ADD_ASSIGN  */
    TOK_SUB_ASSIGN = 299,          /* TOK_SUB_ASSIGN  */
    TOK_MUL_ASSIGN = 300,          /* TOK_MUL_ASSIGN  */
    TOK_DIV_ASSIGN = 301,          /* TOK_DIV_ASSIGN  */
    TOK_MOD_ASSIGN = 302,          /* TOK_MOD_ASSIGN  */
    TOK_NOT = 303,                 /* TOK_NOT  */
    TOK_AND = 304,                 /* TOK_AND  */
    TOK_OR = 305,                  /* TOK_OR  */
    TOK_EQ = 306,                  /* TOK_EQ  */
    TOK_GT = 307,                  /* TOK_GT  */
    TOK_LT = 308,                  /* TOK_LT  */
    TOK_GE = 309,                  /* TOK_GE  */
    TOK_LE = 310,                  /* TOK_LE  */
    TOK_NE = 311,                  /* TOK_NE  */
    TOK_ID = 312,                  /* TOK_ID  */
    TOK_AFFECT = 313,              /* TOK_AFFECT  */
    TOK_PAR_OUV = 314,             /* TOK_PAR_OUV  */
    TOK_PAR_FER = 315,             /* TOK_PAR_FER  */
    TOK_ACC_OUV = 316,             /* TOK_ACC_OUV  */
    TOK_ACC_FER = 317,             /* TOK_ACC_FER  */
    TOK_CRO_OUV = 318,             /* TOK_CRO_OUV  */
    TOK_CRO_FER = 319,             /* TOK_CRO_FER  */
    TOK_POINT = 320,               /* TOK_POINT  */
    TOK_VIRGULE = 321,             /* TOK_VIRGULE  */
    TOK_DEUX_POINTS = 322,         /* TOK_DEUX_POINTS  */
    TOK_POINT_VIRGULE = 323        /* TOK_POINT_VIRGULE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 20 "syntaxic.y"

    int type;
    char nomVariable[50];
    bool isVariable;
    char valeurString[255];
    int valeurInteger;
    double valeurFloat;
    bool Valeurboolean;
    bool isConstant;

    NodeSymbol * NodeSymbol;
    expression expression;
    tableau tableau;
    variable variable;

#line 162 "syntaxic.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SYNTAXIC_TAB_H_INCLUDED  */
