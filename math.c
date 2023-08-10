#include <stdio.h>
#include <math.h>

int main(){

	printf("Resolution de ax^2 + bx + c = 0\n");
//Entrée des données
	float 	a, b, c;
	printf("Entrez a:");
	scanf("%f", &a);
	
	printf("Entrez b:");
	scanf("%f", &b);
	
	printf("Entrez c:");
	scanf("%f", &c);
	
	float 	x1, x2;
	float delta;
//Calcul de(s) solution(s)
	delta = b*b - 4*a*c;
	
	if (delta >= 0){
		x1 = (-b-sqrt(delta))/(2*a);
		x2 = (-b+sqrt(delta))/(2*a);
	}
	else{
		printf("Il n'y a pas de solution\n");
	}
//Sortie de resultat
	printf("les solutions sont:\n");
	printf("x1= %f\nx2= %f\n" , x1 , x2);
	
	return 0;
}
