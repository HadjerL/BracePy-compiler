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

NodeSymbol *search(SymboleTable *symboleTable, char *symbolName)
{
   NodeSymbol *q= symboleTable->first;
   NodeSymbol *p = q;
    while (p != NULL)
    {
        if (strcmp(p->symbolName,symbolName)==0)
        {
            return p;
        }
        p = p->next;
    }
    return p;
}
/*******************************************************************************/
/** Insertion d'une entree dans la table de symbol **/
NodeSymbol *InsertEntry(SymboleTable *symboleTable, int tokenType, char *symbolName, bool isConstant)
{
    NodeSymbol *q= symboleTable->last;
    NodeSymbol *nodeSymbol = (NodeSymbol *)malloc(sizeof(NodeSymbol));
    nodeSymbol->tokenType = tokenType;
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
        printf("|%-20s|%-10s|%-20s|%-15s|%-10s|\n", "Symbol Name", "Token Type", "Token Value", "Initialized", "Constant");
    printf("---------------------------------------------------------------------------------\n");
    while (p != NULL)
    {
        printf("|%-20s|%-10s|%-20s|%-15s|%-10s|\n", 
                p->symbolName, 
                getRealType(p->tokenType), 
                p->tokenValue, 
                p->hasBeenInitialized ? "true" : "false", 
                p->isConstant ? "true" : "false");
        printf("---------------------------------------------------------------------------------\n");
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
    strcpy(nodeSymbole->tokenValue, value);
    nodeSymbole->hasBeenInitialized = true;


}
/*******************************************************************************/



// char *getValue(NodeSymbol *nodeSymbole);
// int getType(NodeSymbol *nodeSymbole);
// char *getRealType(NodeSymbol *nodeSymbole);
// void setValue(NodeSymbol *nodeSymbole, char *value);

// int main(){
//     SymboleTable *symbolTable = allocateSymboleTable();
//     NodeSymbol *nodeSymbole1 = InsertEntry(symbolTable, 1,"2", "Variable1",true);
//     NodeSymbol *nodeSymbole2 = InsertEntry(symbolTable, 1,"r", "Variable1",false);
//     NodeSymbol *nodeSymbole3 = InsertEntry(symbolTable, 1, "Serine","Variable1",true);
//     NodeSymbol *p = search(symbolTable,"Variable1");
//     printf("|%s|%d|%s|%s|%s|\n",p->symbolName,p->tokenType,p->tokenValue, p->hasBeenInitialized? "true" : "false", p->isConstant? "true" : "false");
//     displaySymbolTable(symbolTable);
//     printf(getName(p));
//     printf(getValue(p));
//     printf("%d\n", 5);
//     printf("%d\n ",getType(p));
//     printf("%s\n",getRealType(getType(p)));
//     setValue(p,"lol");
//     printf("|%s|%d|%s|%s|%s|\n",p->symbolName,p->tokenType,p->tokenValue, p->hasBeenInitialized? "true" : "false", p->isConstant? "true" : "false");
//     printf("Hello world");
//     return 0;
// }


