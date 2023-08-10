#include <stdio.h>
#define Pi 3.14
void getData(float* rayon);
void displayResult(float rayon, float circonference, float Aire);
float calcul(float* rayon);
float solution(float* rayon);

int main(){
	
	printf("Calcul de la circonference et l'aire d'un disque\n");
	
	float rayon=0, circonference=0, Aire=0;
	
	getData(&rayon);
	
	circonference = calcul(&rayon);
	
	Aire = solution(&rayon);
	
	displayResult(rayon, circonference, Aire);
	
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
float solution(float* rayon){
	
	float Aire1=0;
	
	Aire1=(*rayon)*(*rayon)*Pi;
	
	return Aire1;
}

void displayResult(float rayon, float circonference, float Aire){

	printf("La circonference du disque est %f\nL'aire du disque est %f", circonference, Aire);
}
