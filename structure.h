#include <stdbool.h>

typedef struct expression expression;
struct expression{
    int type;
    char nomVariable[50];
    bool isVariable;
    char valeurString[255];
    int valeurInteger;
    double valeurFloat;
    bool Valeurboolean;
};

typedef struct tableau tableau;
struct tableau{
    int type;
    int taille;
    char tabValeur[128][32];
};

typedef struct variable variable;
struct variable{
    struct nodeSymbole * nodeSymbole;
    int index;
    char indexString[20];
};


void valeurToString(expression expression, char * valeur);