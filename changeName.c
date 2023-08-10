#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	char nomFichier[150];
	char newName[150];
	const char* nomPointeur;
	const char* newNamePointeur;
	
	nomPointeur = nomFichier;
	newNamePointeur = newName;
	
	printf("Entrez le nom du fichier:");
	scanf("%s", nomFichier);
	
	printf("Entrez le nouveau nom:");
	scanf("%s", newName);
	
	rename(nomPointeur, newNamePointeur);

	return 0;

}
