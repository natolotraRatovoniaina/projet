#include <stdio.h>
#include <string.h>

int main(){

	char texte[70]="Hello World";

	for (int i=0; i <= (strlen(texte)); i++){
		printf("%c\t", texte[i]);
	}
	
	printf("\nCode ASCII\n");

	

	return 0;

}
