#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
	char cmd[200];
	char nomFichier[150];
	char nomDossier[150];
	char* cmdPointeur;
	
	cmdPointeur = cmd;
	
	printf("Entrez le nom du fichier:");
	scanf("%s", nomFichier);
	
	sprintf(cmd,"cp -r %s", nomFichier);
	
	printf("Entrez le nom du repertoire ou mettre le fichier:");
	scanf("%s", nomDossier);
	
	sprintf(cmd, " /home/$(whoami)/%s", nomDossier);
	
	system(cmdPointeur);
	
	return 0;
	
}
