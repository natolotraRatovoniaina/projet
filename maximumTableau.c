#include <stdio.h>
#include "maximumTableau.h"
//void maximumTableau(int tableau[], int tailleTableau, int valeurMax);

int main(){

	printf("Remettre a zero la valeur du tableau depassant la valeur max\n");

	int tableau[10];
	int max=10;

	maximumTableau(tableau, 10, max);

	return 0;

}
