#include <stdio.h>
#include "moyenneTableau.h"
//double moyenneTableau(float tableau[], int tailleTableau);

int main(){

	printf("Calcul de la moyenne des valeur du tableau\n");

	float moyenne=0;
	float tableau[10];
	
	moyenne=moyenneTableau(tableau, 10);

	printf("La moyenne de la valeur du tableau est %f", moyenne);

	return 0;
	
}


