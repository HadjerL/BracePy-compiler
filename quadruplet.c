#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quadruplet.h"

//typedef quadruplet* quad;


//Fonctions pour la manipulation du quad 


quad teteQuad(char opra[],char opr1[],char opr2[],char res[],int i){
     quad q;
// Creation du tete de la liste 
q = malloc(sizeof(quadruplet));
	strcpy(q->operateur,opra);
	strcpy(q->operande1,opr1);
	strcpy(q->operande2,opr2);
	strcpy(q->resultat,res);
	q->qc=i;

q->Suivant = NULL;
return (q);
}
//ajouter un quad dans la liste
quad addQuad (quad tete,char opra[],char opr1[],char opr2[],char res[],int i) 
{  
   quad q;
//Si la liste est vide donc ce quad va etre la téte de la liste
if(tete==NULL){
     tete=teteQuad(opra,opr1,opr2,res,i);
	  return tete;


}
//Sinon insertion au debut 
else{
q = malloc(sizeof(quadruplet));
    strcpy(q->operateur,opra);
    strcpy(q->operande1,opr1);
    strcpy(q->operande2,opr2);
    strcpy(q->resultat,res);
	q->qc=i;
q->Suivant = tete;
tete = q;
	return tete;
   }
}



quad updateQuad(quad tete,int qc,char *adr){
quad q=tete;

//Si la liste est vide return tete
if (q==NULL){
return tete;
}

while(q!=NULL){

    if(q->qc == qc){				
      strcpy(q->operande1,adr);
      return tete;
    }
q=q->Suivant;  // pour avancer
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

void displayQuad(quad L) {
    printf("\n========================= Affichage des quads =========================\n");

    if (L == NULL) {
        printf("\nQuad Vide\n");
    } else {
        printf("------------------------------------------------------------------------\n");
        printf("| Quad No | Operateur | Operande1 | Operande2 | Resultat |\n");
        printf("------------------------------------------------------------------------\n");

        while (L != NULL) {
            printf("\t Quad[%d]=[ %s , %s , %s , %s ] \n",L->qc,L->operateur,L->operande1,L->operande2,L->resultat); // On affiche 
            L = L->Suivant;
        }

        printf("------------------------------------------------------------------------\n");
    }

    printf("========================================================================\n");
}

int main() {
    // Create an empty quad list
    quad quadList = NULL;

    // Add some quads to the list
    quadList = addQuad(quadList, "+", "2", "3", "x", 1);
    quadList = addQuad(quadList, "*", "x", "5", "y", 2);
    quadList = addQuad(quadList, "-", "y", "1", "z", 3);

    // Display the quads
    displayQuad(quadList);

    // Update a quad
    quadList = updateQuad(quadList, 2, "10");

    // Display the updated quads
    displayQuad(quadList);

    // Free the memory (optional, depends on your use case)
    // ... (Add code to free the allocated memory)

    return 0;
}































/*typedef struct elt{
	  char * oper;   //opérateur
	  char * op1;   //opérande 1
	  char * op2;   //opérande 2
	  char * res;   //Resultat
	//
}elt;
int main(){
	int i;
	elt tab[1000];
	tab[0].oper="+";
	tab[0].op1="33";
	tab[0].op2="99";
	tab[0].res="x";
for(i=0;i<20;i++)
	printf(" tab[%d]---> oper :%s  \top1 : %s   \top2 : %s  \tres : %s  \n",i+1,tab[i].oper,tab[i].op1,tab[i].op2,tab[i].res);	
	return 0;
}*/
