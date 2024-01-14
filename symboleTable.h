#ifndef SymboleTable_H
#define SymboleTable_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TYPE_BOOLEAN 0
#define TYPE_INTEGER 1
#define TYPE_FLOAT 2
#define TYPE_STRING 3

/*Structure*/
/*************************************************************************************/

typedef struct NodeSymbol
{
    int tokenType;   
    char symbolName[50];
    char tokenValue[50];
    bool isConstant;
    bool hasBeenInitialized;
    struct NodeSymbol *next; 
    struct NodeSymbol *previous;
} NodeSymbol;



typedef struct SymboleTable
{
    NodeSymbol *first;
    NodeSymbol *last;

} SymboleTable;



/*Entetes*/
/*****************************************************************************************/
SymboleTable *allocateSymboleTable();  
NodeSymbol *InsertEntry(SymboleTable *symboleTable, int tokenType ,char *symbolName,bool isConstant);
NodeSymbol *search(SymboleTable *symboleTable, char *symbolName);  
void displaySymbolTable(SymboleTable *symboleTable);
char *getName(NodeSymbol *nodeSymbole);
char *getValue(NodeSymbol *nodeSymbole);
int getType(NodeSymbol *nodeSymbole);
char *getRealType(int type);
void setValue(NodeSymbol *nodeSymbole, char *value);

/*****************************************************************************************/
#endif