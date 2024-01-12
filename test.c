#include "symboleTable.h"
/********************************************************************************/
/** Allocation de la table de symbole  **/
SymboleTable *allocateSymboleTable()
{
    SymboleTable *symboleTable = (SymboleTable *)malloc(sizeof(SymboleTable));
    symboleTable->first = NULL;
    symboleTable->last = NULL;
    return symboleTable;
}
/*******************************************************************************/
/** Recherche naive **/

NodeSymbol *search(SymboleTable *symboleTable, int tokenId)
{
   NodeSymbol *q= symboleTable->first;
   NodeSymbol *p = q;
    while (p != NULL)
    {
        if (p->tokenId == tokenId)
        {
            return p;
        }
        p = p->next;
    }
    return p;
}
/*******************************************************************************/
/** Insertion d'une entree dans la table de symbol **/
NodeSymbol *InsertEntry(SymboleTable *symboleTable, int tokenId, int tokenType,char *tokenValue, char *symbolName,bool isConstant)
{
    NodeSymbol *q= symboleTable->last;
    NodeSymbol *nodeSymbol = (NodeSymbol *)malloc(sizeof(NodeSymbol));
    nodeSymbol->tokenId = tokenId;
    nodeSymbol->tokenType = tokenType;
    strcpy(nodeSymbol->tokenValue, tokenValue);
    nodeSymbol->isConstant = isConstant;
    nodeSymbol->hasBeenInitialized = false;
    strcpy(nodeSymbol->symbolName, symbolName);
    nodeSymbol->next = NULL;
    nodeSymbol->previous = q;
    if (q==NULL){
        symboleTable->first = nodeSymbol;
    }
    else{
        q->next = nodeSymbol;
    }
    symboleTable->last = nodeSymbol;
    return nodeSymbol;
}
/*******************************************************************************/


/*******************************************************************************/
/** L'affichage de la table des symbols**/
void displaySymbolTable(SymboleTable *symboleTable)
{
    NodeSymbol *q= symboleTable->first;
    NodeSymbol *p = q;
        printf("|Token Id|Token Type|Symbol Name|hasBeenInitialized|isConstant|\n");
        printf("--------------------------------------\n");
    while (p != NULL)
    {
        printf("|%d|%d|%s|%s|%s|%s|\n",p->tokenId,p->tokenType,p->tokenValue,p->symbolName, p->hasBeenInitialized? "true" : "false", p->isConstant? "true" : "false");
        printf("--------------------------------------\n");
        p= p->next;
    }
}

/*******************************************************************************/

/*******************************************************************************/
/** Recuperer le nom de de symbole **/
char *getName(NodeSymbol *nodeSymbole){
    if(nodeSymbole != NULL && nodeSymbole->symbolName!= NULL){
        return nodeSymbole->symbolName;
    }
}
/*******************************************************************************/

/*******************************************************************************/
/** Recuperer la valeur de de symbole **/
char *getValue(NodeSymbol *nodeSymbole){
    if(nodeSymbole != NULL &&  nodeSymbole->tokenValue != NULL){
        return  nodeSymbole->tokenValue;
    }
}
/*******************************************************************************/

/*******************************************************************************/
/** Recuperer la valeur de de symbole **/
int getType(NodeSymbol *nodeSymbole){
    if(nodeSymbole != NULL && nodeSymbole->tokenType != NULL){
        return nodeSymbole->tokenType;
    }
}
/*******************************************************************************/

/*******************************************************************************/
/** Recuperer le nom de type de de symbole **/
char *getRealType(int type){
    switch (type){
        case TYPE_INTEGER:
            return "integer";
            break;
        case TYPE_FLOAT:
            return"Float";
            break;
        case TYPE_STRING:
            return "String";
            break;
        case TYPE_BOOLEAN:
            return"Boolean";
            break;
        default:
            break;
    }
}
/*******************************************************************************/

/*******************************************************************************/
/** setting value to a symbol**/
void setValue(NodeSymbol *nodeSymbole, char *value){
    if(nodeSymbole == NULL){
        printf("Value not set because symbole is NULL");
        return;
    }

    if(nodeSymbole->hasBeenInitialized && nodeSymbole->isConstant){
        printf("Can't reassign a vlue to a constant");
        return;
    }
    nodeSymbole->hasBeenInitialized = true;

}
/*******************************************************************************/



// char *getValue(NodeSymbol *nodeSymbole);
// int getType(NodeSymbol *nodeSymbole);
// char *getRealType(NodeSymbol *nodeSymbole);
// void setValue(NodeSymbol *nodeSymbole, char *value);

int main(){
    SymboleTable *symbolTable = allocateSymboleTable();
    NodeSymbol *nodeSymbole1 = InsertEntry(symbolTable, 1, 1,"2", "Variable",true);
    NodeSymbol *nodeSymbole2 = InsertEntry(symbolTable, 2, 1,"r", "Variable",false);
    NodeSymbol *nodeSymbole3 = InsertEntry(symbolTable, 3, 1, "Serine","Variable",true);
    NodeSymbol *p = search(symbolTable,1);
    printf("|%d|%d|%s|%s|%s|%s|\n",p->tokenId,p->tokenType,p->tokenValue,p->symbolName, p->hasBeenInitialized? "true" : "false", p->isConstant? "true" : "false");
    displaySymbolTable(symbolTable);
    printf(getName(p));
    printf(getValue(p));
    printf("%s",getType(p));
    printf(getRealType(getType(p)));
    setValue(p,"lol");
    printf("|%d|%d|%s|%s|%s|%s|\n",p->tokenId,p->tokenType,p->tokenValue,p->symbolName, p->hasBeenInitialized? "true" : "false", p->isConstant? "true" : "false");
    printf("Hello world");
    return 0;
}


