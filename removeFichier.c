#include <stdio.h>
#include <stdlib.h>

int main(){

	char nomFichier[50];
	const char* pointeur;

	pointeur = nomFichier;

	printf("Entrez le nom du fichier a effacer:");
	scanf("%s", nomFichier);

	remove(pointeur);

	return 0;

}
