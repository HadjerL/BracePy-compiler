%define parse.error verbose
%{

#include "global.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

%}




%token  TOK_INT  TOK_STR TOK_FLOAT TOK_BOOL TOK_ARRAY TOK_TYPE 
%token  TOK_CONST  TOK_IF  TOK_ELSE  TOK_ELIF TOK_RETURN TOK_SWITCH
%token  TOK_CASE  TOK_BREAK  TOK_DEFAULT TOK_FOR TOK_WHILE 
%token  TOK_FOREACH TOK_IN TOK_INPUT TOK_PRINT TOK_DEF  TOK_AS 
%token  TOK_FROM TOK_IMPORT
%token  TOK_INT_T TOK_FLOAT_T TOK_STR_T TOK_BOOl_T TOK_TRUE TOK_FALSE
%token  TOK_ADD TOK_SUB TOK_MUL TOK_DIV TOK_MOD TOK_INC TOK_DEC
%token  TOK_POW  TOK_FLOOR_DIV TOK_ADD_ASSIGN TOK_SUB_ASSIGN 
%token  TOK_MUL_ASSIGN TOK_DIV_ASSIGN TOK_MOD_ASSIGN
%token  TOK_NOT TOK_AND TOK_OR TOK_EQ TOK_GT TOK_LT TOK_GE TOK_LE 
%token  TOK_NE
%token  TOK_ID TOK_AFFECT TOK_PAR_OUV TOK_PAR_FER TOK_ACC_OUV 
%token  TOK_ACC_FER TOK_CRO_OUV TOK_CRO_FER TOK_POINT TOK_VIRGULE
%token  TOK_DEUX_POINTS TOK_POINT_VIRGULE
%left TOK_VIRGULE
%left TOK_OR
%left TOK_AND
%left TOK_NOT
%nonassoc TOK_AFFECT TOK_LT TOK_GT TOK_LE TOK_GE
%nonassoc TOK_NE TOK_ADD_ASSIGN TOK_SUB_ASSIGN TOK_MUL_ASSIGN 
%nonassoc TOK_DIV_ASSIGN  TOK_MOD_ASSIGN

%left TOK_ADD  TOK_SUB
%left TOK_MUL  TOK_DIV TOK_MOD TOK_FLOOR_DIV
%left TOK_POINT TOK_CRO_OUV TOK_CRO_FER
%left TOK_POW
%left TOK_PAR_OUV TOK_PAR_FER
%start ProgrammePrincipal

%{
    extern FILE *yyin;
    extern int yylineno;
    extern int yyleng;
    extern int yylex();
    char* file = "prg.txt";
    int currentColumn = 1;
    void yysuccess(char *s);
    void yyerror(const char *s);
    void showLexicalError();
%}

%%
//Les régles de productions
ProgrammePrincipal:
    /* %empty */
    |Importation;

Importation:
    /* %empty */
    |TOK_IMPORT TOK_STR_T TOK_POINT_VIRGULE Importation Fonction;

Fonction:
    /* %empty */
    |TOK_DEF TypeDeRetour TOK_ID TOK_PAR_OUV Parametres TOK_PAR_FER TOK_ACC_OUV Bloc TOK_ACC_FER Fonction;
TypeDeRetour:
    SimpleType
    | TOK_ARRAY SimpleType TOK_CRO_OUV TOK_CRO_FER BracketLoop
    | TOK_ARRAY TOK_ID TOK_CRO_OUV TOK_CRO_FER BracketLoop
    | TOK_ID;

/* Type:
    SimpleType
    | TypeCompose
    ; */

SimpleType:
TOK_INT|TOK_STR| TOK_FLOAT| TOK_BOOL;//ask about meriem

//ask serine

BracketLoop:
    /* %empty */
    | TOK_CRO_OUV TOK_ACC_OUV BracketLoop;

Parametres:
    /* %empty */
    | TypeDeRetour TOK_ID Parametre;

Parametre:
    /* %empty */
    | TOK_VIRGULE TypeDeRetour TOK_ID Parametre;
Bloc:
    /* %empty */
    | Statement Bloc;

Statement:
    DeclarationInitialisation TOK_POINT_VIRGULE
    | DeclarationStructure TOK_POINT_VIRGULE
    | AppelFontion TOK_POINT_VIRGULE
    | Affectation TOK_POINT_VIRGULE
    | Boucle TOK_POINT_VIRGULE
    | Condition TOK_POINT_VIRGULE
    | Switch TOK_POINT_VIRGULE
    | TOK_BREAK TOK_POINT_VIRGULE
    | TOK_RETURN Expression TOK_POINT_VIRGULE;

DeclarationInitialisation:
    DeclarationSimple PureAffectation
    | TOK_CONST DeclarationSimple PureAffectation
    ;

DeclarationSimple:
    SimpleType TOK_ID
    | Array TOK_ID;

/* TypeCompose:
    Array
    | TOK_ID; */

Array:
    TOK_ARRAY SimpleType TOK_CRO_OUV Expression TOK_CRO_FER BracketExpressionLoop
    | TOK_ARRAY TOK_ID TOK_CRO_OUV Expression TOK_CRO_FER BracketExpressionLoop;

Declaration:
    DeclarationSimple
    | DeclarationVariableStructure;

DeclarationStructure:
    TOK_TYPE TOK_ID TOK_ACC_OUV Declaration DeclarationStructureLoop TOK_ACC_FER;

DeclarationStructureLoop:
    /* %empty */
    | TOK_POINT_VIRGULE Declaration;

/* DeclarationVariableSimple:
    SimpleType TOK_ID
    | TOK_ARRAY TOK_ID; */

DeclarationVariableStructure:
    TOK_ID TOK_ID;

AppelFontion:
    TOK_ID TOK_PAR_OUV Arguments TOK_PAR_FER;

Arguments:
    Expression
    | Expression TOK_VIRGULE Arguments

Expression:
    TOK_PAR_OUV Expression TOK_PAR_FER
    | TOK_NOT Expression
    | TOK_SUB Expression
    | TOK_ADD Expression
    | Expression OperateurBinaire Expression
    | Valeur
    | Variable;

Valeur:
    TOK_INT_T
    | TOK_FLOAT_T
    | TOK_STR_T
    | TOK_TRUE
    | TOK_FALSE
    ;

Variable:
    TOK_ID
    | TOK_ID TOK_POINT Variable
    | TOK_ID TOK_CRO_OUV Expression TOK_CRO_FER BracketExpressionLoop
    | AppelFontion;

BracketExpressionLoop:
    /* %empty */
    |   TOK_CRO_OUV Expression TOK_CRO_FER BracketExpressionLoop;

OperateurBinaire:
TOK_AFFECT
| TOK_LT
| TOK_LE
|  TOK_GT
| TOK_GE
| TOK_NE 
|TOK_EQ
|TOK_ADD_ASSIGN 
|TOK_SUB_ASSIGN
| TOK_MUL_ASSIGN 
| TOK_DIV_ASSIGN 
| TOK_MOD_ASSIGN
|TOK_OR
|TOK_AND
|TOK_ADD 
|TOK_SUB
|TOK_MUL 
|TOK_DIV 
|TOK_MOD 
|TOK_POW;



Affectation:
    Variable PureAffectation
    | Variable RapidAffectation
    ;

PureAffectation:
    TOK_AFFECT Expression
    | TOK_AFFECT Tableau
    | TOK_POINT Affectation
    ;

RapidAffectation:
    OperateurUnaire
    | TOK_ADD_ASSIGN Expression
    | TOK_SUB_ASSIGN Expression
    | TOK_MUL_ASSIGN Expression
    | TOK_DIV_ASSIGN Expression
    | TOK_MOD_ASSIGN Expression
    ;

OperateurUnaire:
    TOK_INC 
    |TOK_DEC
    ;

Condition:
    TOK_IF TOK_PAR_OUV Expression TOK_PAR_FER TOK_ACC_OUV Bloc TOK_ACC_FER ConditionElIf
    |TOK_IF TOK_PAR_OUV Expression TOK_PAR_FER TOK_ACC_OUV Bloc TOK_ACC_FER ConditionELSE;

ConditionElIf:
    /* %empty */
    |TOK_ELIF TOK_PAR_OUV Expression TOK_PAR_FER TOK_ACC_OUV Bloc TOK_ACC_FER ConditionElIf
    |TOK_ELIF TOK_PAR_OUV Expression TOK_PAR_FER TOK_ACC_OUV Bloc TOK_ACC_FER ConditionELSE;

//ask serine
ConditionELSE: 
    /* %empty */
    | TOK_ELSE TOK_ACC_OUV Bloc TOK_ACC_FER
    ;

Switch:
    TOK_SWITCH TOK_PAR_OUV Variable TOK_PAR_FER TOK_ACC_OUV TOK_CASE Valeur TOK_DEUX_POINTS Bloc CaseLoop SwitchDefault TOK_ACC_FER

CaseLoop:
    /* %empty */
    | TOK_CASE Valeur TOK_DEUX_POINTS Bloc CaseLoop

SwitchDefault:
    /* %empty */
    | TOK_DEFAULT TOK_DEUX_POINTS Bloc

Boucle:
    While
    | For
    ;

While:
    TOK_WHILE TOK_PAR_OUV Expression TOK_PAR_FER TOK_ACC_OUV Bloc TOK_ACC_FER
    ;


For: 
    TOK_FOR TOK_PAR_OUV DeclarationInitialisation TOK_POINT_VIRGULE Expression TOK_POINT_VIRGULE Affectation TOK_PAR_FER TOK_ACC_OUV Bloc TOK_ACC_FER
    | TOK_FOREACH TOK_PAR_OUV Declaration TOK_IN Tableau TOK_PAR_FER TOK_ACC_OUV Bloc TOK_ACC_FER
    //for each (looping through a varibale (an object))
    | TOK_FOREACH TOK_PAR_OUV Declaration TOK_IN Variable TOK_PAR_FER TOK_ACC_OUV Bloc TOK_ACC_FER
    ;

Tableau:
    TOK_CRO_OUV Tableau TableauLoop TOK_CRO_FER
    | TOK_CRO_OUV Expression ExpressionLoop TOK_CRO_FER;

TableauLoop:
    /* %empty */
    | TOK_VIRGULE Tableau TableauLoop;

ExpressionLoop:
    /* %empty */
    | TOK_VIRGULE Expression ExpressionLoop;

%%
void yysuccess(char *s){
    //fprintf(stdout, "%d: %s, col:%d\n", yylineno, s,currentColumn);
    currentColumn+=yyleng;
}

void yyerror(const char *s) {
    fprintf(stdout, "File '%s', line %d, character %d :  %s \n", file, yylineno, currentColumn, s);
}

int main (void){
    yyin = fopen(file,"r");
    if(yyin == NULL){
        printf("error while opening file\n");
        return 1;
    }
    else {
        printf("file successfully opened\n");
    }
    if (yyparse() == 0) {
        printf("Parsing successful\n");
    } else {
        fprintf(stderr, "Parsing failed\n");
        return 1;
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






