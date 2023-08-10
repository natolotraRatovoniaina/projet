#include <stdio.h>

int main(){
	
	int tab[4];
	int i;
	int somme=0;
	float moyenne;
	
	printf("Entrez les nombres\n");
	
	for(i=0;i<4;i++){
		scanf("%d", &tab[i]);
	}
	
	for(i=0, somme=0;i<4;i++){
		somme+=tab[i];
	}
	moyenne = somme/4;

	printf("La moyenne est de %f", moyenne);
	
	return 0;
}
