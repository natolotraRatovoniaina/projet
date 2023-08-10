#include <stdio.h>
#include "sommeTableau.h"
//int sommeTableau(int tableau[], int tailleTableau);

int main(){

	printf("Calcul de la somme des valeurs du tableau\n");

	int tableau[10];
	int somme=0;
/*	for(int i=0; i<10; i++){
	printf("Entrez les valeurs dans le tableau\n");
	scanf("%d", &tableau[i]);
	}
*/	
	somme=sommeTableau(tableau, 10);
	
	printf("La somme des valeur est %d", somme);

	return 0;
	
}
