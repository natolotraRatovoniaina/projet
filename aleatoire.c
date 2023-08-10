#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	int difficulte=0;
	printf("Veuillez choisir la difficulté:\n1-Facile\n2-Normal\n3-Difficile\n");
	scanf("%d",&difficulte);
	int Max=0, Min=0;
	
	if(difficulte==1){
		printf("Mode facile : Je vais choisir un nombre entre 1 et 100 et tu vas essayer de le deviner.\n");
		Min=1;Max=100; 
    }
    if(difficulte==2){
        printf("Mode normal : Je vais choisir un nombre etre 1 et 300 et tu vas essayer de le deviner.\n");
        Min=1;Max=300;	
	}
	if(difficulte==3){
		printf("Mode difficile : Je vais choisir un nombre entre 1 et 600 et tu vas essayer de le deviner.\n");
		Min=1;Max=600;
	}
			
    
	srand(time(NULL));
	int nombre=0,
	      y=0,
	        coups=0;	
	y= rand()%(Max+1-Min)+Min;
	
	while(nombre!=y){

	printf("Quelle est le nombre?");
	scanf("%d",&nombre);
	coups++;
	

	if(nombre<y){
		printf("Le nombre est plus élevé!\n");
	}
	else if(nombre>y){
		printf("Le nombre est moins élevé!\n");
	}
	else if(nombre==y){
		printf("Felicitation vous avez trouver le nombre en %d coups.\n",coups);
	}
	else{
		printf("Veuillez respecter les instructions!\n");
	}
	

	}

		return 0;
}
	
