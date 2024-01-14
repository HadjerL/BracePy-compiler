/*** Section de definition***/

%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "global.h"
#include "serine.tab.h" 

extern void yysuccess(char *s);
extern void yyerror(const char *s);
extern void showLexicalError();
extern int currentColumn;
%}

%option yylineno 
%option noyywrap 

DIGIT              [0-9]
LETTER            [a-zA-Z]
IDENTIFIER       {LETTER}({LETTER}|{DIGIT}|_)*

KEYWORD            ("int"|"str"|"float"|"bool"|"array"|"Type"|"const"|"if"|"else"|"elif"|"return"|"switch"|"case"|"break"|"default"|"for"|"while"|"foreach"|"in"|"input"|"def"|"as"|"from"|"import")
/*|"print")         */
LINEBREAK [\n\r]+

WHITESPACE         [[:space:]]+
INT                [+-]?[0-9]+
FLOAT              [+-]?[0-9]*[.][0-9]+
STRING             \".*\"
BOOL               (true|false)

ARITHMETIC       "+"|"-"|"*"|"/"|"%"|"++"|"--"|"**"|"//"|"+="|"-="|"*="|"/="|"%="

LOGIC             "not"|"and"|"or"|"=="|">"|"<"|">="|"<="|"!="

COMMENTL        \/\/.*$

COMMENTM       [/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]

%%
{KEYWORD} {
    if (!strcmp(yytext, "int")){
        yysuccess(yytext);
            yylval.type = TYPE_INTEGER;

        return TOK_INT;
    }
    else if (!strcmp(yytext, "str")){
    yysuccess(yytext);
    yylval.type = TYPE_STRING; 
    return TOK_STR;
}

    else if (!strcmp(yytext, "float")){
        yysuccess(yytext);
        yylval.type = TYPE_FLOAT;
        return TOK_FLOAT;
    }
    else if (!strcmp(yytext, "bool")){
        yysuccess(yytext);
        yylval.type = TYPE_BOOLEAN;
        return TOK_BOOL;
    }
    else if (!strcmp(yytext, "array")){
        yysuccess(yytext);
        return TOK_ARRAY;
    }
    else if (!strcmp(yytext, "Type")){
        yysuccess(yytext);
        return TOK_TYPE;
    }
    else if (!strcmp(yytext, "const")){
        yysuccess(yytext);
        return TOK_CONST;
    }
    else if (!strcmp(yytext, "if")){
        yysuccess(yytext);
        return TOK_IF;
    }
    else if (!strcmp(yytext, "else")){
        yysuccess(yytext);
        return TOK_ELSE;
    }
    else if (!strcmp(yytext, "elif")){
        yysuccess(yytext);
        return TOK_ELIF;
    }
    else if (!strcmp(yytext, "return")){
        yysuccess(yytext);
        return TOK_RETURN;
    }
    else if (!strcmp(yytext, "switch")){
        yysuccess(yytext);
        return TOK_SWITCH;
    }
    else if (!strcmp(yytext, "case")){
        yysuccess(yytext);
        return TOK_CASE;
    }
    else if (!strcmp(yytext, "break")){
        yysuccess(yytext);
        return TOK_BREAK;
    }
    else if (!strcmp(yytext, "default")){
        yysuccess(yytext);
        return TOK_DEFAULT;
    }
    else if (!strcmp(yytext, "for")){
        yysuccess(yytext);
        return TOK_FOR;
    }
    else if (!strcmp(yytext, "while")){
        yysuccess(yytext);
        return TOK_WHILE;
    }
    else if (!strcmp(yytext, "foreach")){
        yysuccess(yytext);
        return TOK_FOREACH;
    }
    else if (!strcmp(yytext, "in")){
        yysuccess(yytext);
        return TOK_IN;
    }
    else if (!strcmp(yytext, "input")){
        yysuccess(yytext);
        return TOK_INPUT;
    }
    // else if (!strcmp(yytext, "print"))
    //     return TOK_PRINT;
    else if (!strcmp(yytext, "def")){
        yysuccess(yytext);
        return TOK_DEF;
    }
    else if (!strcmp(yytext, "as")){
        yysuccess(yytext);
        return TOK_AS;
    }
    else if (!strcmp(yytext, "from")){
        yysuccess(yytext);
        return TOK_FROM;
    }
    else if (!strcmp(yytext, "import")){
        yysuccess(yytext);
        return TOK_IMPORT;
    }
}

{INT} {
    yysuccess("TOK_INT_T");
    yylval.integerValue = atoi(yytext);
    return TOK_INT_T;
}

{FLOAT} {
    yysuccess("FLOAT");
    yylval.floatValue = strtod(yytext, NULL);
    return TOK_FLOAT_T;
}

{STRING} {
    yysuccess(yytext);
    yylval.stringValue = atoi(yytext);
    return TOK_STR_T;
}

{BOOL} {
    yysuccess(yytext);
    if (!strcmp(yytext, "true"))
        return TOK_TRUE;
    else
        return TOK_FALSE;
}

{ARITHMETIC} {
    if (!strcmp(yytext, "+")){
        yysuccess(yytext);
        return TOK_ADD;
    }
    else if (!strcmp(yytext, "-")){
        yysuccess(yytext);
        return TOK_SUB;
    }
    else if (!strcmp(yytext, "*")){
        yysuccess(yytext);
        return TOK_MUL;
    }
    else if (!strcmp(yytext, "/")){
        yysuccess(yytext);
        return TOK_DIV;
    }
    else if (!strcmp(yytext, "%")){
        yysuccess(yytext);
        return TOK_MOD;
    }
    else if (!strcmp(yytext, "++")){
        yysuccess(yytext);
        return TOK_INC;
    }
    else if (!strcmp(yytext, "--")){
        yysuccess(yytext);
        return TOK_DEC;
    }
    else if (!strcmp(yytext, "**")){
        yysuccess(yytext);
        return TOK_POW;
    }
    else if (!strcmp(yytext, "//")){
        yysuccess(yytext);
        return TOK_FLOOR_DIV;
    }
    else if (!strcmp(yytext, "+=")){
        yysuccess(yytext);
        return TOK_ADD_ASSIGN;
    }
    else if (!strcmp(yytext, "-=")){
        yysuccess(yytext);
        return TOK_SUB_ASSIGN;
    }
    else if (!strcmp(yytext, "*=")){
        yysuccess(yytext);
        return TOK_MUL_ASSIGN;
    }
    else if (!strcmp(yytext, "/=")){
        yysuccess(yytext);
        return TOK_DIV_ASSIGN;
    }
    else if (!strcmp(yytext, "%=")){
        yysuccess(yytext);
        return TOK_MOD_ASSIGN;
    }
}

{LOGIC} {
    if (!strcmp(yytext, "not")){
        yysuccess(yytext);
        return TOK_NOT;
    }
    else if (!strcmp(yytext, "and")){
        yysuccess(yytext);
        return TOK_AND;
    }
    else if (!strcmp(yytext, "or")){
        yysuccess(yytext);
        return TOK_OR;
    }
    else if (!strcmp(yytext, "==")){
        yysuccess(yytext);
        return TOK_EQ;
    }
    else if (!strcmp(yytext, ">")){
        yysuccess(yytext);
        return TOK_GT;
    }
    else if (!strcmp(yytext, "<")){
        yysuccess(yytext);
        return TOK_LT;
    }
    else if (!strcmp(yytext, ">=")){
        yysuccess(yytext);
        return TOK_GE;
    }
    else if (!strcmp(yytext, "<=")){
        yysuccess(yytext);
        return TOK_LE;
    }
    else if (!strcmp(yytext, "!=")){
        yysuccess(yytext);
        return TOK_NE;
    }
}

{IDENTIFIER} { return TOK_ID; yysuccess(yytext);}
"=" { return TOK_AFFECT; yysuccess(yytext); }
"(" { return TOK_PAR_OUV;yysuccess(yytext); }
")" { return TOK_PAR_FER;yysuccess(yytext); }
"{" { return TOK_ACC_OUV;yysuccess(yytext); }
"}" { return TOK_ACC_FER;yysuccess(yytext); }
"[" { return TOK_CRO_OUV ;yysuccess(yytext); }
"]" { return TOK_CRO_FER;yysuccess(yytext); }
"." { return TOK_POINT;yysuccess(yytext); }
"," { return TOK_VIRGULE;yysuccess(yytext); }
":" { return TOK_DEUX_POINTS;yysuccess(yytext); }
";" { return TOK_POINT_VIRGULE; yysuccess(yytext); }


{LINEBREAK} {
    currentColumn = 1;
}

[ \t]+ {
    currentColumn+=yyleng;
}
{COMMENTL} { /* Ignorer les commentaires sur une seule ligne */ }
{COMMENTM} { /* Ignorer les commentaires multi-lignes */ }
{WHITESPACE} { /* Ignorer les espaces blancs */ }

<<EOF>> yyterminate();

. {
    // fprintf(stderr, "Erreur : caractère non reconnu à la ligne %d\n", yylineno);
    // exit(1);
    yyerror("Unexpected token");
    showLexicalError();
    yyterminate();
}
%%


