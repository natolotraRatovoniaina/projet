#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"

int main(){
	
	int nbrPc = 0;
	printf("Entrez le nombre de Titulaire : ");
	scanf("%d", &nbrPc);
	Machine *pc = malloc(nbrPc);
	
	FILE *fic = fopen("machine.csv", "w+");
	fprintf(fic,"Titulaire,Marque,Adresse MAC");
	for(int i=0; i<nbrPc; i++){
		
		scanf("%[^/]%[^/]%[^\n]", (pc+i)->label, (pc+i)->marque, (pc+i)->mac);
		fprintf(fic, "%s,%s,%s", (pc+i)->label, (pc+i)->marque, (pc+i)->mac);
		
	}
	
	return 0;
	
}
