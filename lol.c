#include <stdio.h>
#define PI 3.1416

int main(){
	printf("calcul de la circonference\n");
	float 	rayon=1,	///Rayon du cercle 
			circonf=0;	///Circonference du cercle
//Entrée de données
		printf("Entrez le rayon du cercle: ");
		scanf("%f" , &rayon);
	
//Traitement
	circonf = 2*PI*rayon;

//Sortie de résultat

	printf("rayon = %f\ncirconference = %f\n" , rayon , circonf);
	
	return 0;
}
