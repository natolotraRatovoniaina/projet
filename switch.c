#include <stdio.h>

int main(){
	
	printf("===Menu===\n\n1. Royal Cheese\n2. Mc Deluxe\n3. Mc Bacon\n4. Big Mac\n\n");
	
	int choixMenu=0;
	
	printf("Votre choix ?\n");
	scanf("%d", &choixMenu);
	
	switch(choixMenu){
		case 1:
				printf("Tu as choisi le menu Royal Cheese");
				break;
		case 2:
				printf("Tu as choisi le menu MC Deluxe");
				break;
		case 3:
				printf("Tu as choisi le menu Mc Bacon");
				break;
		case 4:
				printf("Tu as choisi le menu Big Mac");
				break;
		default: 
				printf("Passez une bonne journee cher client");
	}
	
	return 0;
}
