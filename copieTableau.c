#include <stdio.h>
#include "copieTableau.h"
//void copie(int tableauOriginal[], int tableauCopie[], int tailleTableau);

int main(){

	printf("Copie de la valeur d'un tableau vers un autre\n");

	int tableau1[10];
	int tableau2[10];
	
	copieTableau(tableau1, tableau2, 10);

	for(int i=0; i<10; i++){
		
		printf("Les valeur dans le tableau2 n°%d est %d\n", i, *(tableau2+i));
		
	}

	return 0;

}
/*void copie(int tableauOriginal[], int tableauCopie[], int tailleTableau){
	
	int i=0;
	
	for(i=0; i<tailleTableau; i++){
		
		printf("Entrez la valeur du tableauOriginal[%d]\n", i);
		scanf("%d", &tableauOriginal[i]);
		
	}
	
	for(i=0; i<tailleTableau; i++){
		
		tableauCopie[i]=tableauOriginal[i];
		
	}
	
	for(i=0; i<tailleTableau; i++){
		
		
		printf("Les valeurs dans tableauCopie[%d] est %d\n", i, tableauCopie[i]);
		
	}
	
}*/
