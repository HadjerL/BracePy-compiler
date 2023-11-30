#include "symboleTable.h"
/********************************************************************************/
/** Allocation de la table de symbole  **/
SymboleTable *allocateSymboleTable()
{
    SymboleTable *symboleTable = (SymboleTable *)malloc(sizeof(SymboleTable));
    symboleTable->first = NULL;
    symboleTable->last = NULL;
    symboleTable->size = 0;
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
NodeSymbol *InsertEntry(SymboleTable *symboleTable, int tokenId, int tokenType, char *symbolName, int scope)
{
    NodeSymbol *q= symboleTable->last;
    NodeSymbol *nodeSymbol = (NodeSymbol *)malloc(sizeof(NodeSymbol));
    nodeSymbol->tokenId = tokenId;
    nodeSymbol->tokenType = tokenType;
    strcpy(nodeSymbol->symbolName, "variable");
    nodeSymbol->scope = scope;
    nodeSymbol->next = NULL;
    nodeSymbol->previous = q;
    nodeSymbol->first = NULL;
    nodeSymbol->last = NULL;
    if (q==NULL){
        symboleTable->first = nodeSymbol;
    }
    else{
        q->next = nodeSymbol;
    }
    symboleTable->last = nodeSymbol;
    return nodeSymbol;
}
void displaySymbolTable(SymboleTable *symboleTable)
{
    NodeSymbol *q= symboleTable->first;
    NodeSymbol *p = q;
        printf("|Token Id|Token Type|Symbol Name|Scope|\n");
        printf("--------------------------------------\n");
    while (p != NULL)
    {
        printf("|%d|%d|%s|%d|\n",p->tokenId,p->tokenType,p->symbolName, p->scope);
        printf("--------------------------------------\n");
        p= p->next;
    }
}


int main(){
     SymboleTable *symbolTable = allocateSymboleTable();
     NodeSymbol *nodeSymbole1 = InsertEntry(symbolTable, 1, 1, "Variable",0);
    // NodeSymbol *nodeSymbole2 = InsertEntry(symbolTable, 2, 1, "Variable",0);
    // NodeSymbol *nodeSymbole3 = InsertEntry(symbolTable, 3, 1, "Variable",0);
    // NodeSymbol *p = search(symbolTable,1);
    // printf("|%d|%d|%s|%d|\n",p->tokenId,p->tokenType,p->symbolName, p->scope);
    displaySymbolTable(symbolTable);
    printf("Hello zorld");
    return 0;
}