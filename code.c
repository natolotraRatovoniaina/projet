#include <stdio.h>

int main(){

	printf("Pense à un nombre et je vais le deviner.\n");
	printf("Repond par 1 pour dire oui et 0 pour dire non et par 2 si le nombre est exact.\n");

	int a=100, b=0, i=0, j=1;
	
	while(i!=100 && a!=j){

		i=(j+a)/2;
	
		printf("Est-ce que le nombre est superieur ou egal a %d\n", i);
		scanf("%d", &b);
	
		if(b==1){
		
			j=i;
		
		}
		else if(b==0){
		
			a=i;
			
		}
		else if(b==2){
		
			printf("Le nombre est donc %d\n", i);
			
			break;
		
		}
		
		
		if(i==99 && b==1){
		
		printf("Le nombre est donc 100\n");
		
		break;
		
		}
		
		if(i==99 && b==0){
		
		printf("Vous mentez le nombre doit etre 99 ou 100 puisque j'ai deja fait le tour des nombres.\n");
		
		break;
		
		}
		
		if(i==1 && b==1){
			
			printf("Vous mentez, j'ai deja fait le tour des nombres donc le nombre doit etre 1.");
			
			break;
			
		}
		
	}
	
	/*if(i<=99 && b==2){
	
		printf("Le nombre est donc %d", i);
	
	}*/
	
	if(i==1 && b==0){
		
		printf("Vous mentez le nombre doit etre parmi ces nombres.");
		
	
	}
	
	return 0;

}

///trouve une solution pour faire en sorte que quand le chiffre est égale à 100 le programme n'affiche plus le nombre est 99
 
