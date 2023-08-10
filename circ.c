#include <stdio.h>
#define Pi 3.14
void getData(float* rayon);
void displayResult(float rayon, float circonference);
float calcul(float* rayon);

int main(){
	
	printf("Calcul de la circonference d'un cercle\n");
	
	float rayon=0, circonference=0;
	
	getData(&rayon);
	
	circonference = calcul(&rayon);
		
	displayResult(rayon, circonference);
	
		return 0;
}
void getData(float* rayon){
	
	printf("Entrez rayon:");
	scanf("%f", rayon);
}
float calcul(float* rayon){
	
	float circonference1=0.;
	
	circonference1 = 2*Pi*(*rayon);
	
	return circonference1;

}
void displayResult(float rayon, float circonference){
	
	printf("La circonference du cercle est %f", circonference);

}
