#include "structure.h"
#include "tableSymboles.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void valeurToString(expression expression, char * valeur){
    switch (expression.type){
        case TYPE_INTEGER:
            sprintf(valeur, "%d", expression.valeurInteger);
            break;
        case TYPE_FLOAT:
            sprintf(valeur, "%.4f", expression.valeurFloat);
            break;
        case TYPE_STRING:
            sprintf(valeur, "%s", expression.valeurString);
            break;
        case TYPE_BOOLEAN:
            sprintf(valeur, "%s", expression.Valeurboolean ? "true" : "false");
            break;
        default:
            break;
    }
}