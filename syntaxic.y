%define parse.error verbose
%{
#define simpleTypeNb 4
#define YYDEBUG 1
%}

%code requires{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "symboleTable.h"
#include "stockSauv.h"
#include "structure.h"
#include "quadruplet.h"
}


%union{
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
}





%token <type> TOK_INT  TOK_STR TOK_FLOAT TOK_BOOL 
%token TOK_ARRAY TOK_TYPE 
%token  TOK_CONST  TOK_IF  TOK_ELSE  TOK_ELIF TOK_RETURN TOK_SWITCH
%token  TOK_CASE  TOK_BREAK  TOK_DEFAULT TOK_FOR TOK_WHILE 
%token  TOK_FOREACH TOK_IN TOK_INPUT TOK_PRINT TOK_DEF  TOK_AS 
%token  TOK_FROM TOK_IMPORT
%token <valeurInteger> TOK_INT_T
%token <valeurFloat> TOK_FLOAT_T 
%token <valeurString> TOK_STR_T 
%token TOK_BOOl_T 
%token <Valeurboolean> TOK_TRUE 
%token <Valeurboolean> TOK_FALSE
%token  TOK_ADD TOK_SUB TOK_MUL TOK_DIV TOK_MOD TOK_INC TOK_DEC
%token  TOK_POW  TOK_FLOOR_DIV TOK_ADD_ASSIGN TOK_SUB_ASSIGN 
%token  TOK_MUL_ASSIGN TOK_DIV_ASSIGN TOK_MOD_ASSIGN
%token  TOK_NOT TOK_AND TOK_OR TOK_EQ TOK_GT TOK_LT TOK_GE TOK_LE 
%token  TOK_NE
%token <nomVariable> TOK_ID 
%token TOK_AFFECT TOK_PAR_OUV TOK_PAR_FER TOK_ACC_OUV 
%token  TOK_ACC_FER TOK_CRO_OUV TOK_CRO_FER TOK_POINT TOK_VIRGULE
%token  TOK_DEUX_POINTS TOK_POINT_VIRGULE
%left TOK_VIRGULE
%left TOK_OR
%left TOK_AND
%left TOK_NOT

%type <NodeSymbol> DeclarationSimple;
%type <expression> Expression;
%type <expression> Valeur;
%type <variable> Variable;
%type <type> SimpleType;
%type <tableau> Tableau;

%nonassoc TOK_AFFECT TOK_LT TOK_GT TOK_LE TOK_GE
%nonassoc TOK_NE TOK_ADD_ASSIGN TOK_SUB_ASSIGN TOK_MUL_ASSIGN 
%nonassoc TOK_DIV_ASSIGN  TOK_MOD_ASSIGN

%left TOK_ADD  TOK_SUB
%left TOK_MUL  TOK_DIV TOK_MOD TOK_FLOOR_DIV
%left TOK_POINT TOK_CRO_OUV TOK_CRO_FER
%left TOK_POW
%left TOK_PAR_OUV TOK_PAR_FER
%start Bloc

%{
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
    quad * Quadruplet;
    int qc = 1;
    
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
    TOK_INT { $$ = TYPE_INTEGER; }
    |TOK_STR { $$ = TYPE_STRING; }
    |TOK_FLOAT { $$ = TYPE_FLOAT; }
    |TOK_BOOL { $$ = TYPE_BOOLEAN; };
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
    DeclarationSimple TOK_AFFECT Expression{
            if($1 != NULL){
            if($1->tokenType == $3.type){
                char valeurString[255];
                valeurToString($3, valeurString);
                setValue($1, valeurString);
                if($3.isVariable)
                {
                    Quadruplet = addQuad(Quadruplet, ":=", $3.nomVariable, "", $1->symbolName, qc);
                }
                else
                {
                                        Quadruplet = addQuad(Quadruplet, ":=", valeurString, "", $1->symbolName, qc);

                }
                qc++;
            }else{
                yyerrorSemantic( "Type mismatch");
            }
        }
    }
    ;

DeclarationSimple:
    SimpleType TOK_ID {
        if(search(symboleTable, $2) == NULL){
            // Si l'ID n'existe pas alors l'inserer
            NodeSymbol * newNodeSymbole = InsertEntry(symboleTable,$1,$2,false);
            $$ = newNodeSymbole;
        }else{
            printf("Identifiant deja declare : %s\n", $2);
            $$ = NULL;
        }
    }
    | TOK_CONST SimpleType TOK_ID
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
    | Expression TOK_AFFECT Expression
    | Expression TOK_LE Expression
    | Expression TOK_LT Expression
    | Expression TOK_GT Expression
    | Expression TOK_GE Expression
    | Expression TOK_NE Expression
    | Expression TOK_EQ Expression
    | Expression TOK_OR Expression
    | Expression TOK_AND Expression
    | Expression TOK_ADD Expression
    | Expression TOK_SUB Expression
    | Expression TOK_MUL Expression
    | Expression TOK_DIV Expression
    | Expression TOK_MOD Expression
    | Expression TOK_POW Expression
    | Valeur
    | Variable;

Valeur:
    TOK_INT_T { $$.type = TYPE_INTEGER; $$.valeurInteger = $1; }
    | TOK_FLOAT_T { $$.type = TYPE_FLOAT; $$.valeurFloat = $1; }
    | TOK_STR_T { $$.type = TYPE_STRING; strcpy($$.valeurString, $1); }
    | TOK_TRUE { $$.type = TYPE_BOOLEAN; $$.Valeurboolean = $1; }
    | TOK_FALSE { $$.type = TYPE_BOOLEAN; $$.Valeurboolean = $1; }
    ;

Variable:
    TOK_ID {
        NodeSymbol * node = search(symboleTable, $1);
        if(node==NULL){
            yyerrorSemantic( "Variable has not been declared!");
            $$.nodeSymbole = NULL;
        }else{
            $$.nodeSymbole = node;
        }
    }
    /* | TOK_ID TOK_POINT Variable
    | TOK_ID TOK_CRO_OUV Expression TOK_CRO_FER BracketExpressionLoop
    | AppelFontion; */

BracketExpressionLoop:
    /* %empty */
    |   TOK_CRO_OUV Expression TOK_CRO_FER BracketExpressionLoop;



Affectation:
    Variable TOK_AFFECT Expression
        {
            if($1.nodeSymbole != NULL){
            if($1.nodeSymbole->isConstant && $1.nodeSymbole->hasBeenInitialized){
                yyerrorSemantic("Cannot reassign a value to a constant");
            }else{
            if($1.nodeSymbole->tokenType != $3.type ){
                yyerrorSemantic( "Type mismatch");
            }else{
                char valeurString[255];
                if($1.nodeSymbole->tokenType < simpleTypeNb)
                    {
                        if($3.type  == TYPE_INTEGER){
                            sprintf(valeurString,"%d",$3.valeurInteger);
                        }else{
                            if($3.type == TYPE_FLOAT){
                            
                                sprintf(valeurString,"%d",$3.valeurFloat);
                            
                            }else{
                                if($3.type == TYPE_BOOLEAN){
                                    strcpy(valeurString, ($3.Valeurboolean == true) ? "true" : "false");
                                }else{
                                    if($3.type ==TYPE_STRING){
                                        strcpy(valeurString,$3.valeurString);
                                    }
                                }
                            }
                        }          
                        setValue($1.nodeSymbole, valeurString);
                        if($3.isVariable){
                            strcpy(valeurString , $3.nomVariable);
                        }else{
                            valeurToString($3,valeurString);
                        }
                        Quadruplet = addQuad(Quadruplet, ":=", valeurString, "", $1.nodeSymbole->symbolName, qc);
                        qc++;
                    }
            }
        }
        }
    } 
    | Variable TOK_INC {
        if($1.nodeSymbole != NULL){
            if(!$1.nodeSymbole->hasBeenInitialized){
                yyerrorSemantic( "Variable not initialized");
            }else{
                if($1.nodeSymbole->isConstant){
                    yyerrorSemantic("Cannot reassign a value to a constant");
                }else{
                if($1.nodeSymbole->tokenType != TYPE_FLOAT
                && $1.nodeSymbole->tokenType != TYPE_INTEGER){
                    yyerrorSemantic( "Non numeric variable found");
                }else{
                    char valeurString[255];
                    if($1.nodeSymbole->tokenType < simpleTypeNb)
                    {
                        Quadruplet = addQuad(Quadruplet, "ADD", $1.nodeSymbole->symbolName, "1", $1.nodeSymbole->symbolName, qc);
                        qc++;
                    }
                    if($1.nodeSymbole->tokenType  == TYPE_INTEGER){
                        strcpy(valeurString ,getValue($1.nodeSymbole));
                        int valeur = atoi(valeurString);
                        valeur++;
                        sprintf(valeurString, "%d", valeur);
                    }else{
                        double valeur = atof(valeurString);
                        valeur++;
                        sprintf(valeurString,"%.4f",valeur);
                    };

                    if($1.nodeSymbole->tokenType < simpleTypeNb)
                        {
                            setValue($1.nodeSymbole, valeurString);
                        }
                }
                }
            }
        }
        }
    | Variable TOK_DEC {
            if($1.nodeSymbole != NULL){
            if(!$1.nodeSymbole->hasBeenInitialized){
                yyerrorSemantic( "Variable not initialized");
            }else{
                if($1.nodeSymbole->isConstant){
                    yyerrorSemantic("Cannot reassign a value to a constant");
                }else{
                if($1.nodeSymbole->tokenType != TYPE_FLOAT
                && $1.nodeSymbole->tokenType != TYPE_INTEGER){
                    yyerrorSemantic( "Non numeric variable found");
                }else{
                    char valeurString[255];
                    if($1.nodeSymbole->tokenType < simpleTypeNb)
                    {
                        Quadruplet = addQuad(Quadruplet, "SUB", $1.nodeSymbole->symbolName, "1", $1.nodeSymbole->symbolName, qc);
                        qc++;
                    }
                    if($1.nodeSymbole->tokenType  == TYPE_INTEGER){
                        strcpy(valeurString ,getValue($1.nodeSymbole));
                        int valeur = atoi(valeurString);
                        valeur--;
                        sprintf(valeurString, "%d", valeur);
                        printf("valeur %d",valeur);
                    }else{
                        double valeur = atof(valeurString);
                        valeur--;
                        sprintf(valeurString,"%.4f",valeur);
                    };

                    if($1.nodeSymbole->tokenType < simpleTypeNb)
                        {
                            setValue($1.nodeSymbole, valeurString);
                        }
                }
                }
            }
        }
        };



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
    DebutWhile Bloc TOK_ACC_FER { 
	char adresse[10];
    char adresseCondWhile [10];
    int sauvAdrDebutWhile = supprimer(StockSauv);
    int sauvAdrCondWhile = supprimer(StockSauv);
    sprintf(adresseCondWhile,"%d",sauvAdrCondWhile);
    Quadruplet =  addQuad (Quadruplet,"BR",adresseCondWhile,"","",qc);
    hola();
    qc++;
    sprintf(adresse,"%d",qc);
    Quadruplet = updateQuad(Quadruplet ,qc, adresse);
};

DebutWhile : 
    ConditionWhile Expression TOK_PAR_FER  TOK_ACC_OUV {
    if($2.type == TYPE_BOOLEAN){
        char r[10];
        sprintf(r,"R%d",qc-1);
        Quadruplet =  addQuad (Quadruplet,"BZ","tmp","",r,qc);
		ajouter(StockSauv,qc); 
		qc++;
    }else{
        yyerrorSemantic( "Non boolean expression found");
    }
};


ConditionWhile:
    TOK_WHILE TOK_PAR_OUV { 
    ajouter(StockSauv,qc); 
}
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
    fprintf(stdout, "\033[1;31mFile '%s', line %d, character %d :  %s \033[0m\n", file, yylineno, currentColumn, s);
}
void yyerrorSemantic(char *s){
    fprintf(stdout, "\033[1;31mFile '%s', line %d, character %d, semantic error: %s\033[0m\n", file, yylineno, currentColumn, s);
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






