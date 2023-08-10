#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int charToNb(char* atransf);
int puiss(int iva, int avo);

int main(){
	
	char* car = NULL;
	int nombre = 0;
	
	car = malloc(5);
	
	printf("Entrez la chaine à transformer en nombre:");
	scanf("%s", car);
	
	nombre = charToNb(car);
	
	printf("%d", nombre);
	
	return 0;
	
}

int charToNb(char* atransf){
	
	int nombre = 0;
	int taille = strlen(atransf)-1;
	
	
	for(int i=0; i<strlen(atransf); i++){
	
	nombre += (atransf[i]-48)*puiss(10,(taille-i));
	
	}
	
	return nombre;
}

int puiss(int iva, int avo){
	
	int nbr = 1;
	
	for(int i=0; i<avo; i++){
		
		nbr*=iva;
		
	}
	
	return nbr;
}
