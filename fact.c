#include <stdio.h>
#include <stdlib.h>
#include <string.h>
double charToDouble(char* atransf);
int estvirgule(char* trouvVirg);

int main(){
	
	char* car = NULL;
	double nbrTranfo = 0.00;
	
	car = malloc(5);
	
	printf("Entrez la chaine à transformer:");
	scanf("%s", car);
		
	nbrTransfo = charToDouble(car);
	
	return 0;
}

double chartoDouble(char* atransf){
	
	double doubleNbr = 0.00;
	
	
	
	return doubleNbr;

}


int estvirgule(const char* trouvVirg){
	
	int placeVirg = 0;
	const char* virg = NULL;
	
	virg = ",";
	
	for(int i=0; i < strlen(trouvVirg); i++){
	
		strcmp("virg", "trouvVirg");
		
		if(strcmp("virg","trouvVirg[i]")=0){
		
			placeVirg=i;
			
		}
	
	}
	
	return placeVirg;
	
}
