#include "structProt.h"

int main()
{
	int nbrPc;
	Machine* container;
	char nameFic[50];
	printf("Nombre de Pc a enregistre : ");
	scanf("%d", &nbrPc);
	printf("Entrer le nom du fichier  : ");
	scanf("%[^\n]", nameFic);
	
	container=inputData(nbrPc);
	sort(container, nbrPc);
	insertData(container, nbrPc, nameFic);
	
	return 0;
}
