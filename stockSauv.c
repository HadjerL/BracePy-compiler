#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stockSauv.h"

// Initialise la structure stockSauv en mettant le pointeur de tête à -1.
void initStockSauv(stockSauv *S)
{

    S->head = -1;
}

// Vérifie si le stockSauv est vide. Renvoie 1 si vrai, sinon 0.
int stockSauvVide(stockSauv *S)
{

    return (S->head == -1);
}

// Vérifie si le stockSauv est plein. Renvoie 1 si vrai, sinon 0.
int stockSauvPleine(stockSauv *S)
{

    return (S->head == (MAX - 1));
}

// Ajoute un élément au stockSauv, à condition que le stock ne soit pas plein.
void ajouter(stockSauv *s, int x)
{

    if (!stockSauvPleine(s))
    {
        s->head++;
        s->table[s->head] = x;
    }
    else
    {
        printf("Erreur: Ne peut pas ajouter - Stock Pleine ...\n");
    }
}

// Supprime un élément du stockSauv et le renvoie. Affiche une erreur si le stock est vide.
int supprimer(stockSauv *s)
{

    int x;
    if (!stockSauvVide(s))
    {
        x = s->table[s->head];
        s->head--;
        return x;
    }
    else
    {
        printf("stock du Sauv Vide\n");
        return 1;
    }
}

// Récupère la valeur du tête du stockSauv . Affiche une erreur si le stock est vide.
void head(stockSauv *s, int *x)
{

    if (!stockSauvVide(s))
    {
        *x = s->table[s->head];
    }
    else
    {
        printf("stock du Sauv vide\n");
    }
}

// Affiche tous les éléments du stockSauv et vide le stock.
void afficherStockSauv(stockSauv *s)
{
    int x;
    while (!stockSauvVide(s))
    {
        x = supprimer(s);
        printf(" %d ", x);
    }
    printf(" \n fin ");
}