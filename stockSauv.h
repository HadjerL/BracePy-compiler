#define MAX 256

// stockSauv sous forme d'une structure utilisée comme une pile pour gérer les éléments sauvegardés (sauv) en vue de mettre à jour les quads.
// Elle maintient un pointeur de tête et un tableau pour stocker les éléments sauvegardés (sauv).
// Les éléments sauvegardés (sauv) sont stockés et récupérés selon une logique Last In, First Out (LIFO). 
typedef struct stockSauv{
    int head;
    int table[MAX];
}stockSauv;

void initStockSauv(stockSauv *S);

int stockSauvVide(stockSauv *S); 

int stockSauvPleine(stockSauv *S);

void ajouter(stockSauv *s, int x);

int supprimer(stockSauv *s);

void head(stockSauv *s, int *x);

void afficherStockSauv(stockSauv *s);