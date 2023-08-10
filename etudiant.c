#include "identStruct.h"

int main()
{
	int nbrEt;
	Machine* container;
	char nameFic[50];
	printf("Entrer le nombre d'etudiant : ");
	scanf("%d", &nbrEt);
	printf("Entrer le nom du fichier  : ");
	scanf("%s", nameFic);
	
	container=inputData(nbrEt);
	sort(container, nbrEt);
	insertData(container, nbrEt, nameFic);
	
	return 0;
}

