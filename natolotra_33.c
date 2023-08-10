#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

	printf("Je vais choisir un nombre entre 1 et 100 et vous allez le deviner en 7 coups\n");
	
	int nombreAleatoire=0,nombreEcrit=0, coups=7;
	
	srand(time(NULL));
	
	nombreAleatoire=1+(int)(100.0*rand()/RAND_MAX+1.0);
	
	while(nombreEcrit != nombreAleatoire && coups!=0){
	
		
		
		if(coups!=0){
		
			printf("Quel est le nombre?\n");
			scanf("%d", &nombreEcrit);
		
		}
		
		coups--;
	
		if(nombreEcrit == nombreAleatoire){
		
			printf("Felicitation, vous gagnez!");
			
		}
	
		else if(nombreEcrit <= nombreAleatoire && coups != 0){
		
			printf("Le nombre est plus grand et vous n'avez plus que %d coups\n", coups);
			
		}
		
		else if(nombreEcrit >= nombreAleatoire && coups !=0){
		
			printf("Le nombre est plus petit et vous n'avez plus que %d coups\n", coups);
			
		}
		
		if(coups==0 && nombreEcrit!=nombreAleatoire){
			
			printf("Perdu! Vous ferez mieux la prochaine fois");
		
		}

	}
	
	return 0;

}
