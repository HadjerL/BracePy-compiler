/*** Section de definition***/
%{

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
FILE *yyin;

%}


DIGIT              [0-9]

LETTER            [a-zA-Z]
IDENTIFIER       {LETTER}({LETTER}|{DIGIT}|_)*

KEYWORD            ("int"|"str"|"float"|"bool"|"array"|"Type"|"const"|"if"|"else"|"elif"|"return"|"switch"|"case"|"break"|"default"|"for"|"while"|"foreach"|"in"|"input"|"print"|"def"|"as"|"from"|"import")         


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

{KEYWORD}      {printf("mot clé : %s \n",yytext);}

{IDENTIFIER}   {printf("identifiant  : %s \n",yytext);}

{INT}       {printf("nombre entier  : %s \n",yytext);  }

{FLOAT}       {printf("float : %s \n",yytext);  }

{BOOL}       {printf("boolean : %s \n",yytext);  }

{STRING}       {printf("chaine de caractére  : %s \n",yytext);  }

{ARITHMETIC}   {printf("opérateur arithmétique  : %s \n",yytext);  }

{LOGIC}        {printf("opérateur logique  : %s \n",yytext); }

{COMMENTL}     {printf("Commentaire d’une ligne \n");  }

{COMMENTM}     {printf("Commentaire des lignes   \n");  }
 
"="                                     {printf("opérateur d'affectation %s \n",yytext);} 
"("                                     {printf("parenthèse ouvrante\n");} 
")"                                     {printf("parenthèse fermante\n");}
"{"                                     {printf("accolade ouvrante\n");}
"}"                                     {printf("accolade fermante\n");}
"["                                     {printf("crochet ouvrant\n");} 
"]"                                     {printf("crochet fermant\n");}
"."                                     {printf("point\n");}
","                                     {printf("virgule\n");}
":"                                     {printf("deux points\n");}
";"                                     {printf("point virgule\n");}
{WHITESPACE}                            {}
 .                     {printf ("Erreur lexicale: %s",yytext);}
%%


/*** section code***/

int yywrap(){  
}
int main (void)
{
    yyin=fopen("test.txt", "r");
    if(yyin==NULL){
        printf("erreur dans l'ouverture du fichier");
        return 1;
    }
    yylex(); 
    fclose(yyin);
}
