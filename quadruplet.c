#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quadruplet.h"

// typedef quadruplet* quad;

// Fonctions pour la manipulation du quad

quad teteQuad(char opra[], char opr1[], char opr2[], char res[], int i)
{
    quad q;
    // Creation du tete de la liste
    q = malloc(sizeof(quadruplet));
    strcpy(q->operateur, opra);
    strcpy(q->operande1, opr1);
    strcpy(q->operande2, opr2);
    strcpy(q->resultat, res);
    q->qc = i;

    q->Suivant = NULL;
    return (q);
}
// ajouter un quad dans la liste
quad addQuad(quad tete, char opra[], char opr1[], char opr2[], char res[], int i)
{
    printf("JE SUIS DANS ADD QUAAAAAAAD \n");

    quad q;
    // Si la liste est vide donc ce quad va etre la téte de la liste
    if (tete == NULL)
    {
        tete = teteQuad(opra, opr1, opr2, res, i);
        printf("la liste des quad est vide \n");
        printf("\t Quad[%d]=[ %s , %s , %s , %s ] \n", tete->qc, tete->operateur, tete->operande1, tete->operande2, tete->resultat);

        return tete;
    }
    // Sinon insertion au debut
    else
    {
        q = malloc(sizeof(quadruplet));
        strcpy(q->operateur, opra);
        strcpy(q->operande1, opr1);
        strcpy(q->operande2, opr2);
        strcpy(q->resultat, res);
        q->qc = i;
        q->Suivant = tete;
        tete = q;
        printf("la liste des quad n'est pas vide \n");

        printf("\t Quad[%d]=[ %s , %s , %s , %s ] \n", tete->qc, tete->operateur, tete->operande1, tete->operande2, tete->resultat); // On affiche
        return tete;
    }
}

quad updateQuad(quad tete, int qc, char *adr)
{
    quad q = tete;

    // Si la liste est vide return tete
    if (q == NULL)
    {
        return tete;
    }

    while (q != NULL)
    {

        if (q->qc == qc)
        {
            strcpy(q->operande1, adr);
            return tete;
        }
        q = q->Suivant; // pour avancer
    }

    return tete;
}

// void displayQuad(quad L){
// printf("\n<<<<<<<<<<  Affichage des quads  >>>>>>>>>>\n");
//     if (L==NULL){
// 		printf("\n\n \t\t Quad Vide \n");
// 	 }
//     else{
//        printf("**********************************************\n");
//         while(L!=NULL){
//            printf("\t Quad[%d]=[ %s , %s , %s , %s ] \n",L->qc,L->operateur,L->operande1,L->operande2,L->resultat); // On affiche
//            L=L->Suivant;  // On avance d'une case
//         }
//     }
// printf("**********************************************\n");
// }

void displayQuad(quad L)
{
    printf("\n========================= Affichage des quads =========================\n");

    if (L == NULL)
    {
        printf("\nQuad Vide\n");
    }
    else
    {
        printf("------------------------------------------------------------------------\n");
        printf("| Quad No | Operateur | Operande1 | Operande2 | Resultat |\n");
        printf("------------------------------------------------------------------------\n");

        while (L != NULL)
        {
            printf("\t Quad[%d]=[ %s , %s , %s , %s ] \n", L->qc, L->operateur, L->operande1, L->operande2, L->resultat); // On affiche
            L = L->Suivant;
        }

        printf("------------------------------------------------------------------------\n");
    }

    printf("========================================================================\n");
}

void hola()
{
    printf("HOLLLA I AM INSIDE QUAD TEMCHI WLLA LA ");
}