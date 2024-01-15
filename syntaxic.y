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
    quad Quadruplet=NULL;
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
    DeclarationSimple PureAffectation
    | TOK_CONST DeclarationSimple PureAffectation
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
    TOK_PAR_OUV Expression TOK_PAR_FER {
            $$=$2;
    }   
   
    | Expression TOK_AFFECT Expression
    | Expression TOK_LT Expression {
    // Check if the types of the two expressions are the same
    if ($1.type == $3.type) {
        $$.type = TYPE_BOOLEAN;

        // Check if the type is string
        if ($1.type == TYPE_STRING) {
            if (strcmp($1.valeurString, $3.valeurString) < 0) {
                $$.Valeurboolean = true;
            } else {
                $$.Valeurboolean = false;
            }

            // Create temporary buffers and result variable
            char buff[255];
            char buff2[255];
            char res[20];
            sprintf(res, "%s%d", "R", qc);
            strcpy($$.nomVariable, res);
            $$.isVariable = true;

            // Generate quadruplet based on variable types
            if ($1.isVariable == true && $3.isVariable == true) {
                Quadruplet = addQuad(Quadruplet, "<", $1.nomVariable, $3.nomVariable, res, qc);
            } else {
                if ($1.isVariable == true) {
                    strcpy(buff2, $3.valeurString);
                    Quadruplet = addQuad(Quadruplet, "<", $1.nomVariable, buff2, res, qc);
                } else {
                    if ($3.isVariable == true) {
                        strcpy(buff, $1.valeurString);
                        Quadruplet = addQuad(Quadruplet, "<", buff, $3.nomVariable, res, qc);
                    } else {
                        strcpy(buff, $1.valeurString);
                        strcpy(buff2, $3.valeurString);
                        Quadruplet = addQuad(Quadruplet, "<", buff, buff2, res, qc);
                    }
                }
            }
            qc++;
        } else {
            // Check if the type is integer
            if ($1.type == TYPE_INTEGER) {
                if ($1.valeurInteger < $3.valeurInteger) {
                    $$.Valeurboolean = true;
                } else {
                    $$.Valeurboolean = false;
                }

                // Create temporary buffers and result variable
                char buff[255];
                char buff2[255];
                char res[20];
                sprintf(res, "%s%d", "R", qc);
                strcpy($$.nomVariable, res);
                $$.isVariable = true;

                // Generate quadruplet based on variable types
                if ($1.isVariable == true && $3.isVariable == true) {
                    Quadruplet = addQuad(Quadruplet, "<", $1.nomVariable, $3.nomVariable, res, qc);
                } else {
                    if ($1.isVariable == true) {
                        sprintf(buff2, "%d", $3.valeurInteger);
                        Quadruplet = addQuad(Quadruplet, "<", $1.nomVariable, buff2, res, qc);
                    } else {
                        if ($3.isVariable == true) {
                            sprintf(buff, "%d", $1.valeurInteger);
                            Quadruplet = addQuad(Quadruplet, "<", buff, $3.nomVariable, res, qc);
                        } else {
                            sprintf(buff, "%d", $1.valeurInteger);
                            sprintf(buff2, "%d", $3.valeurInteger);
                            Quadruplet = addQuad(Quadruplet, "<", buff, buff2, res, qc);
                        }
                    }
                }
                qc++;
            } else {
                // Check if the type is float
                if ($1.type == TYPE_FLOAT) {
                    if ($1.valeurFloat < $3.valeurFloat) {
                        $$.Valeurboolean = true;
                    } else {
                        $$.Valeurboolean = false;
                    }

                    // Create temporary buffers and result variable
                    char buff[255];
                    char buff2[255];
                    char res[20];
                    sprintf(res, "%s%d", "R", qc);
                    strcpy($$.nomVariable, res);
                    $$.isVariable = true;

                    // Generate quadruplet based on variable types
                    if ($1.isVariable == true && $3.isVariable == true) {
                        Quadruplet = addQuad(Quadruplet, "<", $1.nomVariable, $3.nomVariable, res, qc);
                    } else {
                        if ($1.isVariable == true) {
                            sprintf(buff2, "%f", $3.valeurFloat);
                            Quadruplet = addQuad(Quadruplet, "<", $1.nomVariable, buff2, res, qc);
                        } else {
                            if ($3.isVariable == true) {
                                sprintf(buff, "%f", $1.valeurFloat);
                                Quadruplet = addQuad(Quadruplet, "<", buff, $3.nomVariable, res, qc);
                            } else {
                                sprintf(buff, "%f", $1.valeurFloat);
                                sprintf(buff2, "%f", $3.valeurFloat);
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
// Production rule for less than or equal (<=) comparison
    |Expression TOK_LE Expression {
    // Check if the types of the two expressions are the same
    if ($1.type == $3.type) {
        $$.type = TYPE_BOOLEAN;

        // Check if the type is string
        if ($1.type == TYPE_STRING) {
            if (strcmp($1.valeurString, $3.valeurString) <= 0) {
                $$.Valeurboolean = true;
            } else {
                $$.Valeurboolean = false;
            }

            // Create temporary buffers and result variable
            char buff[255];
            char buff2[255];
            char res[20];
            sprintf(res, "%s%d", "R", qc);
            strcpy($$.nomVariable, res);
            $$.isVariable = true;

            // Generate quadruplet based on variable types
            if ($1.isVariable == true && $3.isVariable == true) {
                Quadruplet = addQuad(Quadruplet, "<=",$1.nomVariable, $3.nomVariable, res, qc);
            } else {
                if ($1.isVariable == true) {
                    strcpy(buff2, $3.valeurString);
                    Quadruplet = addQuad(Quadruplet, "<=",$1.nomVariable, buff2, res, qc);
                } else {
                    if ($3.isVariable == true) {
                        strcpy(buff, $1.valeurString);
                        Quadruplet = addQuad(Quadruplet, "<=",buff,$3.nomVariable,res, qc);
                    } else {
                        strcpy(buff, $1.valeurString);
                        strcpy(buff2, $3.valeurString);
                        Quadruplet = addQuad(Quadruplet, "<=",buff,buff2,res, qc);
                    }
                }
            }
            qc++;
        } else {
            // Check if the type is integer
            if ($1.type == TYPE_INTEGER) {
                if ($1.valeurInteger <= $3.valeurInteger) {
                    $$.Valeurboolean = true;
                } else {
                    $$.Valeurboolean = false;
                }

                // Create temporary buffers and result variable
                char buff[255];
                char buff2[255];
                char res[20];
                sprintf(res, "%s%d", "R",qc);
                strcpy($$.nomVariable,res);
                $$.isVariable=true;

                // Generate quadruplet based on variable types
                if ($1.isVariable == true && $3.isVariable == true) {
                    Quadruplet=addQuad(Quadruplet, "<=",$1.nomVariable, $3.nomVariable, res, qc);
                } else {
                    if ($1.isVariable==true) {
                        sprintf(buff2, "%d", $3.valeurInteger);
                        Quadruplet=addQuad(Quadruplet, "<=",$1.nomVariable, buff2, res, qc);
                    } else {
                        if ($3.isVariable==true) {
                            sprintf(buff, "%d", $1.valeurInteger);
                            Quadruplet=addQuad(Quadruplet, "<=",buff,$3.nomVariable,res, qc);
                        } else {
                            sprintf(buff, "%d", $1.valeurInteger);
                            sprintf(buff2, "%d", $3.valeurInteger);
                            Quadruplet=addQuad(Quadruplet, "<=",buff,buff2,res, qc);
                        }
                    }
                }
                qc++;
            } else {
                // Check if the type is float
                if ($1.type == TYPE_FLOAT) {
                    if ($1.valeurFloat <= $3.valeurFloat) {
                        $$.Valeurboolean=true;
                    } else {
                        $$.Valeurboolean=false;
                    }

                    // Create temporary buffers and result variable
                    char buff[255];
                    char buff2[255];
                    char res[20];
                    sprintf(res, "%s%d", "R",qc);
                    strcpy($$.nomVariable,res);
                    $$.isVariable=true;

                    // Generate quadruplet based on variable types
                    if ($1.isVariable == true && $3.isVariable == true) {
                        Quadruplet=addQuad(Quadruplet, "<=",$1.nomVariable, $3.nomVariable, res, qc);
                    } else {
                        if ($1.isVariable==true) {
                            sprintf(buff2, "%f", $3.valeurFloat);
                            Quadruplet=addQuad(Quadruplet, "<=",$1.nomVariable, buff2, res, qc);
                        } else {
                            if ($3.isVariable==true) {
                                sprintf(buff, "%f", $1.valeurFloat);
                                Quadruplet=addQuad(Quadruplet, "<=",buff,$3.nomVariable,res, qc);
                            } else {
                                sprintf(buff, "%f", $1.valeurFloat);
                                sprintf(buff2, "%f", $3.valeurFloat);
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

 // Production rule for greater than (>) comparison
|Expression TOK_GT Expression {
    // Check if the types of the two expressions are the same
    if ($1.type == $3.type) {
        $$.type = TYPE_BOOLEAN;

        // Check if the type is string
        if ($1.type == TYPE_STRING) {
            if (strcmp($1.valeurString, $3.valeurString) > 0) {
                $$.Valeurboolean = true;
            } else {
                $$.Valeurboolean = false;
            }

            // Create temporary buffers and result variable
            char buff[255];
            char buff2[255];
            char res[20];
            sprintf(res, "%s%d", "R", qc);
            strcpy($$.nomVariable, res);
            $$.isVariable = true;

            // Generate quadruplet based on variable types
            if ($1.isVariable == true && $3.isVariable == true) {
                Quadruplet = addQuad(Quadruplet, ">", $1.nomVariable, $3.nomVariable, res, qc);
            } else {
                if ($1.isVariable == true) {
                    strcpy(buff2, $3.valeurString);
                    Quadruplet = addQuad(Quadruplet, ">", $1.nomVariable, buff2, res, qc);
                } else {
                    if ($3.isVariable == true) {
                        strcpy(buff, $1.valeurString);
                        Quadruplet = addQuad(Quadruplet, ">", buff, $3.nomVariable, res, qc);
                    } else {
                        strcpy(buff, $1.valeurString);
                        strcpy(buff2, $3.valeurString);
                        Quadruplet = addQuad(Quadruplet, ">", buff, buff2, res, qc);
                    }
                }
            }
            qc++;
        } else {
            // Check if the type is integer
            if ($1.type == TYPE_INTEGER) {
                if ($1.valeurInteger > $3.valeurInteger) {
                    $$.Valeurboolean = true;
                } else {
                    $$.Valeurboolean = false;
                }

                // Create temporary buffers and result variable
                char buff[255];
                char buff2[255];
                char res[20];
                sprintf(res, "%s%d", "R", qc);
                strcpy($$.nomVariable, res);
                $$.isVariable = true;

                // Generate quadruplet based on variable types
                if ($1.isVariable == true && $3.isVariable == true) {
                    Quadruplet = addQuad(Quadruplet, ">", $1.nomVariable, $3.nomVariable, res, qc);
                } else {
                    if ($1.isVariable == true) {
                        sprintf(buff2, "%d", $3.valeurInteger);
                        Quadruplet = addQuad(Quadruplet, ">", $1.nomVariable, buff2, res, qc);
                    } else {
                        if ($3.isVariable == true) {
                            sprintf(buff, "%d", $1.valeurInteger);
                            Quadruplet = addQuad(Quadruplet, ">", buff, $3.nomVariable, res, qc);
                        } else {
                            sprintf(buff, "%d", $1.valeurInteger);
                            sprintf(buff2, "%d", $3.valeurInteger);
                            Quadruplet = addQuad(Quadruplet, ">", buff, buff2, res, qc);
                        }
                    }
                }
                qc++;
            } else {
                // Check if the type is float
                if ($1.type == TYPE_FLOAT) {
                    if ($1.valeurFloat > $3.valeurFloat) {
                        $$.Valeurboolean = true;
                    } else {
                        $$.Valeurboolean = false;
                    }

                    // Create temporary buffers and result variable
                    char buff[255];
                    char buff2[255];
                    char res[20];
                    sprintf(res, "%s%d", "R", qc);
                    strcpy($$.nomVariable, res);
                    $$.isVariable = true;

                    // Generate quadruplet based on variable types
                    if ($1.isVariable == true && $3.isVariable == true) {
                        Quadruplet = addQuad(Quadruplet, ">", $1.nomVariable, $3.nomVariable, res, qc);
                    } else {
                        if ($1.isVariable == true) {
                            sprintf(buff2, "%f", $3.valeurFloat);
                            Quadruplet = addQuad(Quadruplet, ">", $1.nomVariable, buff2, res, qc);
                        } else {
                            if ($3.isVariable == true) {
                                sprintf(buff, "%f", $1.valeurFloat);
                                Quadruplet = addQuad(Quadruplet, ">", buff, $3.nomVariable, res, qc);
                            } else {
                                sprintf(buff, "%f", $1.valeurFloat);
                                sprintf(buff2, "%f", $3.valeurFloat);
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

  // Production rule for greater than or equal (>=) comparison
|Expression TOK_GE Expression {
    // Check if the types of the two expressions are the same
    if ($1.type == $3.type) {
        $$.type = TYPE_BOOLEAN;

        // Check if the type is string
        if ($1.type == TYPE_STRING) {
            if (strcmp($1.valeurString, $3.valeurString) >= 0) {
                $$.Valeurboolean = true;
            } else {
                $$.Valeurboolean = false;
            }

            // Create temporary buffers and result variable
            char buff[255];
            char buff2[255];
            char res[20];
            sprintf(res, "%s%d", "R", qc);
            strcpy($$.nomVariable, res);
            $$.isVariable = true;

            // Generate quadruplet based on variable types
            if ($1.isVariable == true && $3.isVariable == true) {
                Quadruplet = addQuad(Quadruplet, ">=",$1.nomVariable, $3.nomVariable, res, qc);
            } else {
                if ($1.isVariable == true) {
                    strcpy(buff2, $3.valeurString);
                    Quadruplet = addQuad(Quadruplet, ">=",$1.nomVariable, buff2, res, qc);
                } else {
                    if ($3.isVariable == true) {
                        strcpy(buff, $1.valeurString);
                        Quadruplet = addQuad(Quadruplet, ">=",buff,$3.nomVariable,res, qc);
                    } else {
                        strcpy(buff, $1.valeurString);
                        strcpy(buff2, $3.valeurString);
                        Quadruplet = addQuad(Quadruplet, ">=",buff,buff2,res, qc);
                    }
                }
            }
            qc++;
        } else {
            // Check if the type is integer
            if ($1.type == TYPE_INTEGER) {
                if ($1.valeurInteger >= $3.valeurInteger) {
                    $$.Valeurboolean = true;
                } else {
                    $$.Valeurboolean = false;
                }

                // Create temporary buffers and result variable
                char buff[255];
                char buff2[255];
                char res[20];
                sprintf(res, "%s%d", "R", qc);
                strcpy($$.nomVariable, res);
                $$.isVariable = true;

                // Generate quadruplet based on variable types
                if ($1.isVariable == true && $3.isVariable == true) {
                    Quadruplet = addQuad(Quadruplet, ">=",$1.nomVariable, $3.nomVariable, res, qc);
                } else {
                    if ($1.isVariable == true) {
                        sprintf(buff2, "%d", $3.valeurInteger);
                        Quadruplet = addQuad(Quadruplet, ">=",$1.nomVariable, buff2, res, qc);
                    } else {
                        if ($3.isVariable == true) {
                            sprintf(buff, "%d", $1.valeurInteger);
                            Quadruplet = addQuad(Quadruplet, ">=",buff,$3.nomVariable,res, qc);
                        } else {
                            sprintf(buff, "%d", $1.valeurInteger);
                            sprintf(buff2, "%d", $3.valeurInteger);
                            Quadruplet = addQuad(Quadruplet, ">=",buff,buff2,res, qc);
                        }
                    }
                }
                qc++;
            } else {
                // Check if the type is float
                if ($1.type == TYPE_FLOAT) {
                    if ($1.valeurFloat >= $3.valeurFloat) {
                        $$.Valeurboolean = true;
                    } else {
                        $$.Valeurboolean = false;
                    }

                    // Create temporary buffers and result variable
                    char buff[255];
                    char buff2[255];
                    char res[20];
                    sprintf(res, "%s%d", "R", qc);
                    strcpy($$.nomVariable, res);
                    $$.isVariable = true;

                    // Generate quadruplet based on variable types
                    if ($1.isVariable == true && $3.isVariable == true) {
                        Quadruplet = addQuad(Quadruplet, ">=",$1.nomVariable, $3.nomVariable, res, qc);
                    } else {
                        if ($1.isVariable == true) {
                            sprintf(buff2, "%f", $3.valeurFloat);
                            Quadruplet = addQuad(Quadruplet, ">=",$1.nomVariable, buff2, res, qc);
                        } else {
                            if ($3.isVariable == true) {
                                sprintf(buff, "%f", $1.valeurFloat);
                                Quadruplet = addQuad(Quadruplet, ">=",buff,$3.nomVariable,res, qc);
                            } else {
                                sprintf(buff, "%f", $1.valeurFloat);
                                sprintf(buff2, "%f", $3.valeurFloat);
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

    // Production rule for equal (==) comparison
| Expression TOK_EQ Expression {
    if ($1.type == $3.type) {
        $$.type = TYPE_BOOLEAN;

        // Check if the type is string
        if ($1.type == TYPE_STRING) {
            if (strcmp($1.valeurString, $3.valeurString) == 0) {
                $$.Valeurboolean = true;
            } else {
                $$.Valeurboolean = false;
            }

            // Create temporary buffers and result variable
            char buff[255];
            char buff2[255];
            char res[20];
            sprintf(res, "%s%d", "R", qc);
            strcpy($$.nomVariable, res);
            $$.isVariable = true;

            // Generate quadruplet based on variable types
            if ($1.isVariable == true && $3.isVariable == true) {
                Quadruplet = addQuad(Quadruplet, "==", $1.nomVariable, $3.nomVariable, res, qc);
            } else {
                if ($1.isVariable == true) {
                    strcpy(buff2, $3.valeurString);
                    Quadruplet = addQuad(Quadruplet, "==", $1.nomVariable, buff2, res, qc);
                } else {
                    if ($3.isVariable == true) {
                        strcpy(buff, $1.valeurString);
                        Quadruplet = addQuad(Quadruplet, "==", buff, $3.nomVariable, res, qc);
                    } else {
                        strcpy(buff, $1.valeurString);
                        strcpy(buff2, $3.valeurString);
                        Quadruplet = addQuad(Quadruplet, "==", buff, buff2, res, qc);
                    }
                }
            }
            qc++;
        } else {
            // Check if the type is integer
            if ($1.type == TYPE_INTEGER) {
                if ($1.valeurInteger == $3.valeurInteger) {
                    $$.Valeurboolean = true;
                } else {
                    $$.Valeurboolean = false;
                }

                // Create temporary buffers and result variable
                char buff[255];
                char buff2[255];
                char res[20];
                sprintf(res, "%s%d", "R", qc);
                strcpy($$.nomVariable, res);
                $$.isVariable = true;

                // Generate quadruplet based on variable types
                if ($1.isVariable == true && $3.isVariable == true) {
                    Quadruplet = addQuad(Quadruplet, "==", $1.nomVariable, $3.nomVariable, res, qc);
                } else {
                    if ($1.isVariable == true) {
                        sprintf(buff2, "%d", $3.valeurInteger);
                        Quadruplet = addQuad(Quadruplet, "==", $1.nomVariable, buff2, res, qc);
                    } else {
                        if ($3.isVariable == true) {
                            sprintf(buff, "%d", $1.valeurInteger);
                            Quadruplet = addQuad(Quadruplet, "==", buff, $3.nomVariable, res, qc);
                        } else {
                            sprintf(buff, "%d", $1.valeurInteger);
                            sprintf(buff2, "%d", $3.valeurInteger);
                            Quadruplet = addQuad(Quadruplet, "==", buff, buff2, res, qc);
                        }
                    }
                }
                qc++;
            } else {
                // Check if the type is float
                if ($1.type == TYPE_FLOAT) {
                    if ($1.valeurFloat == $3.valeurFloat) {
                        $$.Valeurboolean = true;
                    } else {
                        $$.Valeurboolean = false;
                    }

                    // Create temporary buffers and result variable
                    char buff[255];
                    char buff2[255];
                    char res[20];
                    sprintf(res, "%s%d", "R", qc);
                    strcpy($$.nomVariable, res);
                    $$.isVariable = true;

                    // Generate quadruplet based on variable types
                    if ($1.isVariable == true && $3.isVariable == true) {
                        Quadruplet = addQuad(Quadruplet, "==", $1.nomVariable, $3.nomVariable, res, qc);
                    } else {
                        if ($1.isVariable == true) {
                            sprintf(buff2, "%f", $3.valeurFloat);
                            Quadruplet = addQuad(Quadruplet, "==", $1.nomVariable, buff2, res, qc);
                        } else {
                            if ($3.isVariable == true) {
                                sprintf(buff, "%f", $1.valeurFloat);
                                Quadruplet = addQuad(Quadruplet, "==", buff, $3.nomVariable, res, qc);
                            } else {
                                sprintf(buff, "%f", $1.valeurFloat);
                                sprintf(buff2, "%f", $3.valeurFloat);
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

// Production rule for not equal (!=) comparison
| Expression TOK_NE Expression {
    if ($1.type == $3.type) {
        $$.type = TYPE_BOOLEAN;

        // Check if the type is string
        if ($1.type == TYPE_STRING) {
            if (strcmp($1.valeurString, $3.valeurString) != 0) {
                $$.Valeurboolean = true;
            } else {
                $$.Valeurboolean = false;
            }

            // Create temporary buffers and result variable
            char buff[255];
            char buff2[255];
            char res[20];
            sprintf(res, "%s%d", "R", qc);
            strcpy($$.nomVariable, res);
            $$.isVariable = true;

            // Generate quadruplet based on variable types
            if ($1.isVariable == true && $3.isVariable == true) {
                Quadruplet = addQuad(Quadruplet, "!=", $1.nomVariable, $3.nomVariable, res, qc);
            } else {
                if ($1.isVariable == true) {
                    strcpy(buff2, $3.valeurString);
                    Quadruplet = addQuad(Quadruplet, "!=", $1.nomVariable, buff2, res, qc);
                } else {
                    if ($3.isVariable == true) {
                        strcpy(buff, $1.valeurString);
                        Quadruplet = addQuad(Quadruplet, "!=", buff, $3.nomVariable, res, qc);
                    } else {
                        strcpy(buff, $1.valeurString);
                        strcpy(buff2, $3.valeurString);
                        Quadruplet = addQuad(Quadruplet, "!=", buff, buff2, res, qc);
                    }
                }
            }
            qc++;
        } else {
            // Check if the type is integer
            if ($1.type == TYPE_INTEGER) {
                if ($1.valeurInteger != $3.valeurInteger) {
                    $$.Valeurboolean = true;
                } else {
                    $$.Valeurboolean = false;
                }

                // Create temporary buffers and result variable
                char buff[255];
                char buff2[255];
                char res[20];
                sprintf(res, "%s%d", "R", qc);
                strcpy($$.nomVariable, res);
                $$.isVariable = true;

                // Generate quadruplet based on variable types
                if ($1.isVariable == true && $3.isVariable == true) {
                    Quadruplet = addQuad(Quadruplet, "!=", $1.nomVariable, $3.nomVariable, res, qc);
                } else {
                    if ($1.isVariable == true) {
                        sprintf(buff2, "%d", $3.valeurInteger);
                        Quadruplet = addQuad(Quadruplet, "!=", $1.nomVariable, buff2, res, qc);
                    } else {
                        if ($3.isVariable == true) {
                            sprintf(buff, "%d", $1.valeurInteger);
                            Quadruplet = addQuad(Quadruplet, "!=", buff, $3.nomVariable, res, qc);
                        } else {
                            sprintf(buff, "%d", $1.valeurInteger);
                            sprintf(buff2, "%d", $3.valeurInteger);
                            Quadruplet = addQuad(Quadruplet, "!=", buff, buff2, res, qc);
                        }
                    }
                }
                qc++;
            } else {
                // Check if the type is float
                if ($1.type == TYPE_FLOAT) {
                    if ($1.valeurFloat != $3.valeurFloat) {
                        $$.Valeurboolean = true;
                    } else {
                        $$.Valeurboolean = false;
                    }

                    // Create temporary buffers and result variable
                    char buff[255];
                    char buff2[255];
                    char res[20];
                    sprintf(res, "%s%d", "R", qc);
                    strcpy($$.nomVariable, res);
                    $$.isVariable = true;

                    // Generate quadruplet based on variable types
                    if ($1.isVariable == true && $3.isVariable == true) {
                        Quadruplet = addQuad(Quadruplet, "!=", $1.nomVariable, $3.nomVariable, res, qc);
                    } else {
                        if ($1.isVariable == true) {
                            sprintf(buff2, "%f", $3.valeurFloat);
                            Quadruplet = addQuad(Quadruplet, "!=", $1.nomVariable, buff2, res, qc);
                        } else {
                            if ($3.isVariable == true) {
                                sprintf(buff, "%f", $1.valeurFloat);
                                Quadruplet = addQuad(Quadruplet, "!=", buff, $3.nomVariable, res, qc);
                            } else {
                                sprintf(buff, "%f", $1.valeurFloat);
                                sprintf(buff2, "%f", $3.valeurFloat);
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

// Production rule for logical NOT (!) expression
| TOK_NOT Expression {
    if ($2.type == TYPE_BOOLEAN) {
        $$.type = TYPE_BOOLEAN;
        $$.Valeurboolean = !$2.Valeurboolean;

        // Create temporary buffers and result variable
        char buff[255];
        char res[20];
        strcpy(buff, ($2.Valeurboolean == true) ? "true" : "false");
        sprintf(res, "%s%d", "R", qc);
        strcpy($$.nomVariable, res);
        $$.isVariable = true;

        // Generate quadruplet for logical NOT operation
        Quadruplet = addQuad(Quadruplet, "NOT", buff, "", res, qc);
        qc++;
    } else {
        yyerrorSemantic("Can't do NOT of non-boolean type");
    }
}

   // Production rule for unary minus operation
| TOK_SUB Expression {
    // Check if the expression is not a string
    if ($2.type != TYPE_STRING) {
        // Check if the expression is an integer
        if ($2.type == TYPE_INTEGER) {
            $$.type = TYPE_INTEGER;
            $$.valeurInteger = 0 - $2.valeurInteger;

            // Create temporary buffers and result variable
            char buff[255];
            char res[20];
            sprintf(buff, "%d", $2.valeurInteger);
            sprintf(res, "%s%d", "R", qc);
            strcpy($$.nomVariable, res);
            $$.isVariable = true;

            // Generate quadruplet for the unary minus operation
            Quadruplet = addQuad(Quadruplet, "-", "0", buff, res, qc);
            qc++;
        } else {
            // Check if the expression is a float
            if ($2.type == TYPE_FLOAT) {
                $$.type = TYPE_FLOAT;
                $$.valeurFloat = 0.0 - $2.valeurFloat;

                // Create temporary buffers and result variable
                char buff[255];
                char res[20];
                sprintf(buff, "%f", $2.valeurFloat);
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
  
 // Production rule for logical AND operation
| Expression TOK_AND Expression {
    // Check if both operands are of type boolean
    if ($1.type == TYPE_BOOLEAN && $3.type == TYPE_BOOLEAN) {
        // Perform logical AND operation
        if ($1.Valeurboolean && $3.Valeurboolean) {
            $$.Valeurboolean = true;
        } else {
            $$.Valeurboolean = false;
        }

        // Create temporary buffers and result variable
        char buff[255];
        char buff2[255];
        char res[20];
        sprintf(res, "%s%d", "R", qc);
        strcpy($$.nomVariable, res);
        $$.isVariable = true;

        // Generate quadruplet for logical AND operation
        if ($1.isVariable == true && $3.isVariable == true) {
            Quadruplet = addQuad(Quadruplet, "AND", $1.nomVariable, $3.nomVariable, res, qc);
        } else {
            if ($1.isVariable == true) {
                strcpy(buff2, ($3.Valeurboolean == true) ? "true" : "false");
                Quadruplet = addQuad(Quadruplet, "AND", $1.nomVariable, buff2, res, qc);
            } else {
                if ($3.isVariable == true) {
                    strcpy(buff, ($1.Valeurboolean == true) ? "true" : "false");
                    Quadruplet = addQuad(Quadruplet, "AND", buff, $3.nomVariable, res, qc);
                } else {
                    strcpy(buff, ($1.Valeurboolean == true) ? "true" : "false");
                    strcpy(buff2, ($3.Valeurboolean == true) ? "true" : "false");
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

// Production rule for logical OR operation
| Expression TOK_OR Expression {
    // Check if both operands are of type boolean
    if ($1.type == TYPE_BOOLEAN && $3.type == TYPE_BOOLEAN) {
        // Perform logical OR operation
        if ($1.Valeurboolean || $3.Valeurboolean) {
            $$.Valeurboolean = true;
        } else {
            $$.Valeurboolean = false;
        }

        // Create temporary buffers and result variable
        char buff[255];
        char buff2[255];
        char res[20];
        sprintf(res, "%s%d", "R", qc);
        strcpy($$.nomVariable, res);
        $$.isVariable = true;

        // Generate quadruplet for logical OR operation
        if ($1.isVariable == true && $3.isVariable == true) {
            Quadruplet = addQuad(Quadruplet, "OR", $1.nomVariable, $3.nomVariable, res, qc);
        } else {
            if ($1.isVariable == true) {
                strcpy(buff2, ($3.Valeurboolean == true) ? "true" : "false");
                Quadruplet = addQuad(Quadruplet, "OR", $1.nomVariable, buff2, res, qc);
            } else {
                if ($3.isVariable == true) {
                    strcpy(buff, ($1.Valeurboolean == true) ? "true" : "false");
                    Quadruplet = addQuad(Quadruplet, "OR", buff, $3.nomVariable, res, qc);
                } else {
                    strcpy(buff, ($1.Valeurboolean == true) ? "true" : "false");
                    strcpy(buff2, ($3.Valeurboolean == true) ? "true" : "false");
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

// Production rule for addition operation
| Expression TOK_ADD Expression{
    // Check if both operands are of the same type
    if($1.type == $3.type){
        // If the type is string, concatenate the strings
        if($1.type == TYPE_STRING){
            strcpy($$.valeurString, $1.valeurString);
            strcat($$.valeurString, $3.valeurString);

            // Create temporary buffers and result variable
            char buff[255];
            char buff2[255];
            char res[20];
            sprintf(res, "%s%d", "R", qc);
            strcpy($$.nomVariable, res);
            $$.isVariable = true;

            // Generate quadruplet for string concatenation
            if($1.isVariable == true && $3.isVariable == true){
                Quadruplet = addQuad(Quadruplet, "+", $1.nomVariable, $3.nomVariable, res, qc);
            } else {
                if($1.isVariable == true){
                    Quadruplet = addQuad(Quadruplet, "+", $1.nomVariable, $3.valeurString, res, qc);
                } else {
                    if($3.isVariable == true){
                        Quadruplet = addQuad(Quadruplet, "+", $1.valeurString, $3.nomVariable, res, qc);
                    } else {
                        Quadruplet = addQuad(Quadruplet, "+", $1.valeurString, $3.valeurString, res, qc);
                    }
                }
            }
            qc++;
        } else {
            // For integer, float, and boolean types, perform arithmetic or boolean addition
            if($1.type == TYPE_INTEGER){
                $$.valeurInteger = $1.valeurInteger + $3.valeurInteger;

                // Create temporary buffers and result variable
                char buff[255];
                char buff2[255];
                char res[20];
                sprintf(res, "%s%d", "R", qc);
                strcpy($$.nomVariable, res);
                $$.isVariable = true;

                // Generate quadruplet for integer addition
                if($1.isVariable == true && $3.isVariable == true){
                    Quadruplet = addQuad(Quadruplet, "+", $1.nomVariable, $3.nomVariable, res, qc);
                } else {
                    if($1.isVariable == true){
                        sprintf(buff2, "%d", $3.valeurInteger);
                        Quadruplet = addQuad(Quadruplet, "+", $1.nomVariable, buff2, res, qc);
                    } else {
                        if($3.isVariable == true){
                            sprintf(buff, "%d", $1.valeurInteger);
                            Quadruplet = addQuad(Quadruplet, "+", buff, $3.nomVariable, res, qc);
                        } else {
                            sprintf(buff, "%d", $1.valeurInteger);
                            sprintf(buff2, "%d", $3.valeurInteger);
                            Quadruplet = addQuad(Quadruplet, "+", buff, buff2, res, qc);
                        }
                    }
                }
                qc++;
            } else if($1.type == TYPE_FLOAT){
                $$.valeurFloat = $1.valeurFloat + $3.valeurFloat;

                // Create temporary buffers and result variable
                char buff[255];
                char buff2[255];
                char res[20];
                sprintf(res, "%s%d", "R", qc);
                strcpy($$.nomVariable, res);
                $$.isVariable = true;

                // Generate quadruplet for float addition
                if($1.isVariable == true && $3.isVariable == true){
                    Quadruplet = addQuad(Quadruplet, "+", $1.nomVariable, $3.nomVariable, res, qc);
                } else {
                    if($1.isVariable == true){
                        sprintf(buff2, "%f", $3.valeurFloat);
                        Quadruplet = addQuad(Quadruplet, "+", $1.nomVariable, buff2, res, qc);
                    } else {
                        if($3.isVariable == true){
                            sprintf(buff, "%f", $1.valeurFloat);
                            Quadruplet = addQuad(Quadruplet, "+", buff, $3.nomVariable, res, qc);
                        } else {
                            sprintf(buff, "%f", $1.valeurFloat);
                            sprintf(buff2, "%f", $3.valeurFloat);
                            Quadruplet = addQuad(Quadruplet, "+", buff, buff2, res, qc);
                        }
                    }
                }
                qc++;
            } else if($1.type == TYPE_BOOLEAN){
                $$.type = TYPE_BOOLEAN;
                // Perform boolean OR operation
                if(($1.Valeurboolean) || ($3.Valeurboolean)){
                    $$.Valeurboolean = true;
                } else {
                    $$.Valeurboolean = false;
                }

                // Create temporary buffers and result variable
                char buff[255];
                char buff2[255];
                char res[20];
                sprintf(res, "%s%d", "R", qc);
                strcpy($$.nomVariable, res);
                $$.isVariable = true;

                // Generate quadruplet for boolean OR operation
                if($1.isVariable == true && $3.isVariable == true){
                    Quadruplet = addQuad(Quadruplet, "+", $1.nomVariable, $3.nomVariable, res, qc);
                } else {
                    if($1.isVariable == true){
                        strcpy(buff, ($3.Valeurboolean == true) ? "true" : "false");
                        Quadruplet = addQuad(Quadruplet, "+", $1.nomVariable, buff2, res, qc);
                    } else {
                        if($3.isVariable == true){
                            strcpy(buff, ($1.Valeurboolean == true) ? "true" : "false");
                            Quadruplet = addQuad(Quadruplet, "+", buff, $3.nomVariable, res, qc);
                        } else {
                            strcpy(buff, ($1.Valeurboolean == true) ? "true" : "false");
                            strcpy(buff2, ($3.Valeurboolean == true) ? "true" : "false");
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

   // Production rule for subtraction operation
| Expression TOK_SUB Expression{
    // Check if both operands are of the same type and not string
    if($1.type == $3.type && $3.type != TYPE_STRING){
        // Check if subtraction involves boolean type (not supported)
        if($1.type == TYPE_BOOLEAN ){
            yyerrorSemantic("Could not perform subtraction of boolean");
        }
        else{
            // Perform subtraction for integer and float types
            if($1.type == TYPE_INTEGER){
                $$.valeurInteger = $1.valeurInteger - $3.valeurInteger;

                // Create temporary buffers and result variable
                char buff[255];
                char buff2[255];
                char res[20];
                sprintf(res, "%s%d", "R", qc);
                strcpy($$.nomVariable, res);
                $$.isVariable = true;

                // Generate quadruplet for integer subtraction
                if($1.isVariable == true & $3.isVariable == true) {
                    Quadruplet = addQuad(Quadruplet, "-", $1.nomVariable, $3.nomVariable, res, qc);
                }
                else{
                    if($1.isVariable == true){
                        sprintf(buff2, "%d", $3.valeurInteger);
                        Quadruplet = addQuad(Quadruplet, "-", $1.nomVariable, buff2, res, qc);
                    }
                    else{
                        if($3.isVariable == true){
                            sprintf(buff, "%d", $1.valeurInteger);
                            Quadruplet = addQuad(Quadruplet, "-", buff, $3.nomVariable, res, qc);
                        }
                        else{
                            sprintf(buff, "%d", $1.valeurInteger);
                            sprintf(buff2, "%d", $3.valeurInteger);
                            Quadruplet = addQuad(Quadruplet, "-", buff, buff2, res, qc);
                        }
                    }
                }
                qc++;
            }
            else {
                if($1.type == TYPE_FLOAT){
                    $$.valeurFloat = $1.valeurFloat - $3.valeurFloat;

                    // Create temporary buffers and result variable
                    char buff[255];
                    char buff2[255];
                    char res[20];
                    sprintf(res, "%s%d", "R", qc);
                    strcpy($$.nomVariable, res);
                    $$.isVariable = true;

                    // Generate quadruplet for float subtraction
                    if($1.isVariable == true & $3.isVariable == true){
                        Quadruplet = addQuad(Quadruplet, "-", $1.nomVariable, $3.nomVariable, res, qc);
                    }
                    else{
                        if($1.isVariable == true){
                            sprintf(buff2, "%f", $3.valeurFloat);
                            Quadruplet = addQuad(Quadruplet, "-", $1.nomVariable, buff2, res, qc);
                        }
                        else{
                            if($3.isVariable == true){
                                sprintf(buff, "%f", $1.valeurFloat);
                                Quadruplet = addQuad(Quadruplet, "-", buff, $3.nomVariable, res, qc);
                            }
                            else{
                                sprintf(buff, "%f", $1.valeurFloat);
                                sprintf(buff2, "%f", $3.valeurFloat);
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

  // Production rule for multiplication operation
| Expression TOK_MUL Expression {
    // Check if both operands are of the same type
    if($1.type == $3.type){
        // Check if the common type is integer
        if($1.type == TYPE_INTEGER){
            // Perform multiplication for integer type
            $$.valeurInteger = $1.valeurInteger * $3.valeurInteger;

            // Create temporary buffers and result variable
            char buff[255];
            char buff2[255];
            char res[20];
            sprintf(res, "%s%d", "R", qc);
            strcpy($$.nomVariable, res);
            $$.isVariable = true;

            // Generate quadruplet for integer multiplication
            if($1.isVariable == true & $3.isVariable == true){
                Quadruplet = addQuad(Quadruplet, "*", $1.nomVariable, $3.nomVariable, res, qc);
            }
            else{
                if($1.isVariable == true){
                    sprintf(buff2, "%d", $3.valeurInteger);
                    Quadruplet = addQuad(Quadruplet, "*", $1.nomVariable, buff2, res, qc);
                }
                else{
                    if($3.isVariable == true){
                        sprintf(buff, "%d", $1.valeurInteger);
                        Quadruplet = addQuad(Quadruplet, "*", buff, $3.nomVariable, res, qc);
                    }
                    else{
                        sprintf(buff, "%d", $1.valeurInteger);
                        sprintf(buff2, "%d", $3.valeurInteger);
                        Quadruplet = addQuad(Quadruplet, "*", buff, buff2, res, qc);
                    }
                }
            }
            qc++;
        }
        else {
            // Check if the common type is float
            if($1.type == TYPE_FLOAT){
                // Perform multiplication for float type
                $$.valeurFloat = $1.valeurFloat * $3.valeurFloat;

                // Create temporary buffers and result variable
                char buff[255];
                char buff2[255];
                char res[20];
                sprintf(res, "%s%d", "R", qc);
                strcpy($$.nomVariable, res);
                $$.isVariable = true;

                // Generate quadruplet for float multiplication
                if($1.isVariable == true & $3.isVariable == true){
                    Quadruplet = addQuad(Quadruplet, "*", $1.nomVariable, $3.nomVariable, res, qc);
                }
                else{
                    if($1.isVariable == true){
                        sprintf(buff2, "%f", $3.valeurFloat);
                        Quadruplet = addQuad(Quadruplet, "*", $1.nomVariable, buff2, res, qc);
                    }
                    else{
                        if($3.isVariable == true){
                            sprintf(buff, "%f", $1.valeurFloat);
                            Quadruplet = addQuad(Quadruplet, "*", buff, $3.nomVariable, res, qc);
                        }
                        else{
                            sprintf(buff, "%f", $1.valeurFloat);
                            sprintf(buff2, "%f", $3.valeurFloat);
                            Quadruplet = addQuad(Quadruplet, "*", buff, buff2, res, qc);
                        }
                    }
                }
                qc++;
            }
            else {
                // Check if the common type is boolean
                if($1.type == TYPE_BOOLEAN){
                    $$.type = TYPE_BOOLEAN;

                    // Perform multiplication for boolean type
                    if(($1.Valeurboolean) && ($3.Valeurboolean)){
                        $$.Valeurboolean = true;
                    }
                    else{
                        $$.Valeurboolean = false;
                    };

                    // Create temporary buffers and result variable
                    char buff[255];
                    char buff2[255];
                    char res[20];
                    sprintf(res, "%s%d", "R", qc);
                    strcpy($$.nomVariable, res);
                    $$.isVariable = true;

                    // Generate quadruplet for boolean multiplication
                    if($1.isVariable == true & $3.isVariable == true){
                        Quadruplet = addQuad(Quadruplet, "*", $1.nomVariable, $3.nomVariable, res, qc);
                    }
                    else{
                        if($1.isVariable == true) {
                            strcpy(buff, ($3.Valeurboolean == true) ? "true" : "false");
                            Quadruplet = addQuad(Quadruplet, "*", $1.nomVariable, buff2, res, qc);
                        }
                        else{
                            if($3.isVariable == true){
                                strcpy(buff, ($1.Valeurboolean == true) ? "true" : "false");
                                Quadruplet = addQuad(Quadruplet, "*", buff, $3.nomVariable, res, qc);
                            }
                            else{
                                strcpy(buff, ($1.Valeurboolean == true) ? "true" : "false");
                                strcpy(buff2, ($3.Valeurboolean == true) ? "true" : "false");
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
// Production rule for division operation
| Expression TOK_DIV Expression {
    // Check if both operands are of the same type
    if($1.type == $3.type){
        // Check for division by zero
        if((($3.type == TYPE_INTEGER) && ($3.valeurInteger == 0)) || (($3.type == TYPE_FLOAT) && ($3.valeurFloat == 0.0))){
            yyerrorSemantic("Division by zero");
        }
        else {
            // Check if the common type is string
            if($1.type == TYPE_STRING){
                yyerrorSemantic("Type Incompatible");
            }
            else {
                // Check if the common type is integer
                if($1.type == TYPE_INTEGER){
                    // Perform division for integer type
                    $$.valeurInteger = $1.valeurInteger / $3.valeurInteger;

                    // Create temporary buffers and result variable
                    char buff[255];
                    char buff2[255];
                    char res[20];
                    sprintf(res, "%s%d", "R", qc);
                    strcpy($$.nomVariable, res);
                    $$.isVariable = true;

                    // Generate quadruplet for integer division
                    if($1.isVariable == true && $3.isVariable == true){
                        Quadruplet = addQuad(Quadruplet, "/", $1.nomVariable, $3.nomVariable, res, qc);
                        qc++;
                    }
                    else {
                        if($1.isVariable == true){
                            sprintf(buff2, "%d", $3.valeurInteger);
                            Quadruplet = addQuad(Quadruplet, "/", $1.nomVariable, buff2, res, qc);
                            qc++;
                        }
                        else {
                            if($3.isVariable == true){
                                sprintf(buff, "%d", $1.valeurInteger);
                                Quadruplet = addQuad(Quadruplet, "/", buff, $3.nomVariable, res, qc);
                                qc++;
                            }
                            else {
                                sprintf(buff, "%d", $1.valeurInteger);
                                sprintf(buff2, "%d", $3.valeurInteger);
                                sprintf(res, "%s%d", "R", qc);
                                Quadruplet = addQuad(Quadruplet, "/", buff, buff2, res, qc);
                                qc++;
                            }
                        }
                    }
                }
                else {
                    // Check if the common type is float
                    if($1.type == TYPE_FLOAT){
                        // Perform division for float type
                        $$.valeurFloat = $1.valeurFloat / $3.valeurFloat;

                        // Create temporary buffers and result variable
                        char buff2[255];
                        char buff[255];
                        char res[20];
                        sprintf(res, "%s%d", "R", qc);
                        strcpy($$.nomVariable, res);
                        $$.isVariable = true;

                        // Generate quadruplet for float division
                        if($1.isVariable == true && $3.isVariable == true){
                            Quadruplet = addQuad(Quadruplet, "/", $1.nomVariable, $3.nomVariable, res, qc);
                            qc++;
                        }
                        else {
                            if($1.isVariable == true){
                                sprintf(buff2, "%f", $3.valeurFloat);
                                Quadruplet = addQuad(Quadruplet, "/", $1.nomVariable, buff2, res, qc);
                                qc++;
                            }
                            else {
                                if($3.isVariable == true){
                                    sprintf(buff, "%f", $1.valeurFloat);
                                    Quadruplet = addQuad(Quadruplet, "/", buff, $3.nomVariable, res, qc);
                                    qc++;
                                }
                                else {
                                    sprintf(buff, "%f", $1.valeurFloat);
                                    sprintf(buff2, "%f", $3.valeurFloat);
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
// Production rule for modulo operation
| Expression TOK_MOD Expression {
    // Check if both operands are of the same type
    if($1.type == $3.type){
        // Check for division by zero
        if((($3.type == TYPE_INTEGER) && ($3.valeurInteger == 0)) || (($3.type == TYPE_FLOAT) && ($3.valeurFloat == 0.0))){
            yyerrorSemantic("Division by zero");
        }
        else {
            // Check if the common type is string
            if($$.type == TYPE_STRING){
                yyerrorSemantic("Type Incompatible");
            }
            else {
                // Check if the common type is integer
                if($$.type == TYPE_INTEGER){
                    // Perform modulo for integer type
                    $$.valeurInteger = $1.valeurInteger % $3.valeurInteger;

                    // Temporary buffers and result variable
                    char buff[255];
                    char buff2[255];
                    char res[20];
                    sprintf(res, "%s%d", "R", qc);
                    strcpy($$.nomVariable, res);
                    $$.isVariable = true;

                    // Generate quadruplets for integer modulo
                    if($1.isVariable == true && $3.isVariable == true){
                        Quadruplet = addQuad(Quadruplet, "/", $1.nomVariable, $3.nomVariable, res, qc);
                        qc++;
                        sprintf(res, "%s%d", "R", qc);
                        Quadruplet = addQuad(Quadruplet, "*", $1.nomVariable, $3.nomVariable, res, qc);
                        qc++;
                        sprintf(res, "%s%d", "R", qc);
                        Quadruplet = addQuad(Quadruplet, "-", $1.nomVariable, $3.nomVariable, res, qc);
                        sprintf(res, "%s%d", "R", qc);
                        strcpy($$.nomVariable, res);
                        $$.isVariable = true;
                        qc++;
                    }
                    else {
                        if($1.isVariable == true){
                            sprintf(buff2, "%d", $3.valeurInteger);
                            Quadruplet = addQuad(Quadruplet, "/", $1.nomVariable, buff2, res, qc);
                            qc++;
                            sprintf(buff2, "%d", $3.valeurInteger);
                            sprintf(res, "%s%d", "R", qc);
                            Quadruplet = addQuad(Quadruplet, "*", $1.nomVariable, buff2, res, qc);
                            qc++;
                            strcpy(buff2, res);
                            sprintf(res, "%s%d", "R", qc);
                            Quadruplet = addQuad(Quadruplet, "-", $1.nomVariable, buff2, res, qc);
                            sprintf(res, "%s%d", "R", qc);
                            strcpy($$.nomVariable, res);
                            $$.isVariable = true;
                            qc++;
                        }
                        else {
                            if($3.isVariable == true){
                                sprintf(buff, "%d", $1.valeurInteger);
                                Quadruplet = addQuad(Quadruplet, "/", buff, $3.nomVariable, res, qc);
                                qc++;
                                strcpy(buff, res);
                                sprintf(res, "%s%d", "R", qc);
                                Quadruplet = addQuad(Quadruplet, "*", buff, $3.nomVariable, res, qc);
                                qc++;
                                sprintf(buff, "%d", $1.valeurInteger);
                                sprintf(res, "%s%d", "R", qc);
                                Quadruplet = addQuad(Quadruplet, "-", buff, $3.nomVariable, res, qc);
                                sprintf(res, "%s%d", "R", qc);
                                strcpy($$.nomVariable, res);
                                $$.isVariable = true;
                                qc++;
                            }
                            else {
                                sprintf(buff, "%d", $1.valeurInteger);
                                sprintf(buff2, "%d", $3.valeurInteger);
                                Quadruplet = addQuad(Quadruplet, "/", buff, buff2, res, qc);
                                qc++;
                                strcpy(buff, res);
                                sprintf(buff2, "%d", $3.valeurInteger);
                                sprintf(res, "%s%d", "R", qc);
                                Quadruplet = addQuad(Quadruplet, "*", buff, buff2, res, qc);
                                qc++;
                                sprintf(buff, "%d", $1.valeurInteger);
                                strcpy(buff2, res);
                                sprintf(res, "%s%d", "R", qc);
                                Quadruplet = addQuad(Quadruplet, "-", buff, buff2, res, qc);
                                sprintf(res, "%s%d", "R", qc);
                                strcpy($$.nomVariable, res);
                                $$.isVariable = true;
                                qc++;
                            }
                        }
                    }
                }
                else {
                    // Check if the common type is float
                    if($$.type == TYPE_FLOAT){
                        // Perform modulo for float type
                        $$.valeurFloat = fmod($1.valeurFloat, $3.valeurFloat);

                        // Temporary buffers and result variable
                        char buff2[255];
                        char buff[255];
                        char res[20];
                        sprintf(res, "%s%d", "R", qc);
                        strcpy($$.nomVariable, res);
                        $$.isVariable = true;

                        // Generate quadruplets for float modulo
                        if($1.isVariable == true && $3.isVariable == true){
                            Quadruplet = addQuad(Quadruplet, "/", $1.nomVariable, $3.nomVariable, res, qc);
                            qc++;
                            sprintf(res, "%s%d", "R", qc);
                            Quadruplet = addQuad(Quadruplet, "*", $1.nomVariable, $3.nomVariable, res, qc);
                            qc++;
                            sprintf(res, "%s%d", "R", qc);
                            Quadruplet = addQuad(Quadruplet, "-", $1.nomVariable, $3.nomVariable, res, qc);
                            sprintf(res, "%s%d", "R", qc);
                            strcpy($$.nomVariable, res);
                            $$.isVariable = true;
                            qc++;
                        }
                        else {
                            if($1.isVariable == true){
                                sprintf(buff2, "%f", $3.valeurFloat);
                                Quadruplet = addQuad(Quadruplet, "/", $1.nomVariable, buff2, res, qc);
                                qc++;
                                sprintf(buff2, "%f", $3.valeurFloat);
                                sprintf(res, "%s%d", "R", qc);
                                Quadruplet = addQuad(Quadruplet, "*", $1.nomVariable, buff2, res, qc);
                                qc++;
                                strcpy(buff2, res);
                                sprintf(res, "%s%d", "R", qc);
                                Quadruplet = addQuad(Quadruplet, "-", $1.nomVariable, buff2, res, qc);
                                sprintf(res, "%s%d", "R", qc);
                                strcpy($$.nomVariable, res);
                                $$.isVariable = true;
                                qc++;
                            }
                            else {
                                if($3.isVariable == true){
                                    sprintf(buff, "%f", $1.valeurFloat);
                                    Quadruplet = addQuad(Quadruplet, "/", buff, $3.nomVariable, res, qc);
                                    qc++;
                                    strcpy(buff, res);
                                    sprintf(res, "%s%d", "R", qc);
                                    Quadruplet = addQuad(Quadruplet, "*", buff, $3.nomVariable, res, qc);
                                    qc++;
                                    sprintf(buff, "%f", $1.valeurFloat);
                                    sprintf(res, "%s%d", "R", qc);
                                    Quadruplet = addQuad(Quadruplet, "-", buff, $3.nomVariable, res, qc);
                                    sprintf(res, "%s%d", "R", qc);
                                    strcpy($$.nomVariable, res);
                                    $$.isVariable = true;
                                    qc++;
                                }
                                else {
                                    sprintf(buff, "%f", $1.valeurFloat);
                                    sprintf(buff2, "%f", $3.valeurFloat);
                                    Quadruplet = addQuad(Quadruplet, "/", buff, buff2, res, qc);
                                    qc++;
                                    strcpy(buff, res);
                                    sprintf(buff2, "%f", $3.valeurFloat);
                                    sprintf(res, "%s%d", "R", qc);
                                    Quadruplet = addQuad(Quadruplet, "*", buff, buff2, res, qc);
                                    qc++;
                                    sprintf(buff, "%f", $1.valeurFloat);
                                    strcpy(buff2, res);
                                    sprintf(res, "%s%d", "R", qc);
                                    Quadruplet = addQuad(Quadruplet, "-", buff, buff2, res, qc);
                                    sprintf(res, "%s%d", "R", qc);
                                    strcpy($$.nomVariable, res);
                                    $$.isVariable = true;
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

    | Expression TOK_POW Expression
    | Valeur
    | Variable;

Valeur:
    TOK_INT_T     { $$.type = TYPE_INTEGER; $$.valeurInteger = $1; }
    | TOK_FLOAT_T { $$.type = TYPE_FLOAT; $$.valeurFloat = $1; }
    | TOK_STR_T   { $$.type = TYPE_STRING; strcpy($$.valeurString, $1);printf("token %s\n",$1); }
    | TOK_TRUE    { $$.type = TYPE_BOOLEAN; $$.Valeurboolean = $1; }
    | TOK_FALSE   { $$.type = TYPE_BOOLEAN; $$.Valeurboolean = $1; }
    ;

Variable:
    TOK_ID
    | TOK_ID TOK_POINT Variable
    | TOK_ID TOK_CRO_OUV Expression TOK_CRO_FER BracketExpressionLoop
    | AppelFontion;

BracketExpressionLoop:
    /* %empty */
    |   TOK_CRO_OUV Expression TOK_CRO_FER BracketExpressionLoop;



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





