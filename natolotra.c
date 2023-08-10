#include <stdio.h>

int main(){
	
	printf("Je vais essayer de trouver le chiffre dans ta tete entre 1 et 100\n");
	printf("Repondez par 1 si oui et 2 si non");
	
	int reponse;
	
	printf("Est ce que le chiffre est entre 30 et 50\n");
	scanf("%d", &reponse);
	
	if(reponse!=2){
		for(int i=31; i<=49; i++){
	
		printf("Est ce que le nombre est superieur egal a %d\n", i);
		scanf("%d", &reponse);
	
		}
	}
	
	printf("Vous mentez le chiffre doit etre dans ce que j'ai dis");

	return 0;

}
