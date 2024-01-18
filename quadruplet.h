// Liste linéaire chainé de quad
typedef struct quadruplet quadruplet;
struct quadruplet
{
	char operateur[20];
	char operande1[20];
	char operande2[20];
	char resultat[20];
	int qc;						// cursor ,represente le num de quadruplet
	struct quadruplet *Suivant; // chainage
};

typedef quadruplet *quad;
quad teteQuad(char opra[], char opr1[], char opr2[], char res[], int i);
quad addQuad(quad tete, char opra[], char opr1[], char opr2[], char res[], int i);
quad updateQuad(quad tete, int qc, char *adr);
void displayQuad(quad L);