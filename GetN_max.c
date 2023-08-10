#include <stdio.h>
#include <stdlib.h>
int tailleAllouer(int taille);
int* tailleTab(int taille);

int main(){

	int* tableau;
	int taille=0;

	tableau = tailleTab(taille);
	
	for(int i=0; i<5; i++){
		
		printf("la valeur du tableau N°%d est %d", i, *(tableau+i));

	}
	
	return 0;

}
int* tailleTab(int alloc){

	printf("Entrez la taille du tableau:");
	scanf("%d", &alloc);
	
	int* pointeur=NULL; 
	
	pointeur = malloc(sizeof(int)*alloc);
	
	for(int i=0; i<alloc; i++){
			
		printf("Entrez la valeur du tableau N°%d:", i);
		scanf("%d", pointeur);
	
	}
	
	return pointeur;

}
