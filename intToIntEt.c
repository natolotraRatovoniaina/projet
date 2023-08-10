#include <stdio.h>
#include <stdlib.h>
int longueurNbr(int trouvLong);
int* intToIntEt(int nbrAconv, int longNbr);

int main(){

	int nombre = 1453;
	int* nombreReturn;
	int longNombre = 0;
	
	longNombre = longueurNbr(nombre);
	nombreReturn = intToIntEt(nombre, longNombre);

	for(int i = 0; i<longNombre; i++)
	printf("%d", nombreReturn[i]);
	
	return 0;
	
}

int longueurNbr(int trouvLong){
	
	int longNbr = 0;
	
	while(trouvLong!=0){
	
		trouvLong /= 10;
		
		longNbr++;
	}
	
	return longNbr;
}
int* intToIntEt(int nbrAconv, int longNbr){
	
	int* tabNbr;
	
	tabNbr = malloc(longNbr);
	
	for(int i = longNbr-1; i>=0; i--){
		
		tabNbr[i] = nbrAconv % 10;
		
		nbrAconv /= 10;
	
	}
	
	return tabNbr;
	
}
