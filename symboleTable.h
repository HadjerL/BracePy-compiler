#ifndef SymboleTable_H
#define SymboleTable_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Structure*/
/*************************************************************************************/
typedef struct NodeAttribute
{   
    char name[50];
    char value[50];
    struct NodeAttribute *next;
    struct NodeAttribute *previous;

} NodeAttribute;

typedef struct NodeSymbol
{
    int tokenId; 
    int tokenType;   
    char symbolName[50];
    int scope;
    struct NodeSymbol *next; 
    struct NodeSymbol *previous; 
    NodeAttribute *first;      
    NodeAttribute *last;        

} NodeSymbol;



typedef struct SymboleTable
{
    NodeSymbol *first;
    NodeSymbol *last;
    int size;

} SymboleTable;



/*Entetes*/
/*****************************************************************************************/
SymboleTable *allocateSymboleTable();  
NodeSymbol *InsertEntry(SymboleTable *symboleTable, int tokenId, int tokenType, char symbolName[], int scope);
NodeAttribute *InsertAttribute(NodeSymbol *nodeSymbol, char *name, char *value);
NodeSymbol *search(SymboleTable *symboleTable, int tokenId);  
void deleteAllAttributes(NodeSymbol *nodesymbol);
void deletetoken(NodeSymbol *nodeSymbole);
void deletSymboleTable(SymboleTable  *symboleTable);
void addAttributByPointer(NodeSymbol *nodeSymbole, char *name, char *value);
void addAttributByIndex(SymboleTable *symboleTable, int tokenId ,char *name, char *value);
void displaySymbolAttributes(NodeSymbol *nodeSymbol);
void displaySymbolTable(SymboleTable *symboleTable);
/*****************************************************************************************/
#endif


