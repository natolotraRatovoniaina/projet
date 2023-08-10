#include <stdio.h>
#include <math.h>
void displayResult(float a, float b, float c, float delta, float x1, float x2);
void resolve(float a, float b, float c, float* delta, float* x1, float* x2);
float calcDelta(float a, float b, float c);

int main(){

	printf("Resolution de ax²+bx+c=0\n");

///Données
	
	float a=1, b=1, c=-2;	//les coeff. de l'équation
	float x1=876, x2=987.6;	//les solutions éventuelles
	float delta=1;			//Le discriminant de l'équation

///Calcul
	
	resolve(a, b, c, &delta, &x1, &x2);
/*	
 * delta = calcDelta(a,b,c);
	
	if(delta >= 0){
		x1 = (-b -sqrt(delta))/(2*a);
		x2 = (-b +sqrt(delta))/(2*a);
	}
*/ 
///Sortie
	
	displayResult(a, b, c, delta, x1, x2);

	return 0;
}

void resolve(float a, float b, float c, float* delta, float* x1, float* x2){
	
	*delta = calcDelta(a,b,c);
	
	if(*delta >= 0){
		*x1 = (-b -sqrt(*delta))/(2*a);
		*x2 = (-b +sqrt(*delta))/(2*a);
	}
}

float calcDelta(float a, float b, float c){
	float delta = 0;

		delta = b*b - 4*a*c;
		
	return delta;
}
  
void displayResult(float a, float b, float c, float delta, float x1, float x2){
	
	if(delta < 0){
		printf("il n'y a pas de solution reelle\n");
	}
	
	else{
		printf("Avec les coefficients:\na = %f\nb = %f\nc = %f\n", a, b, c);
		printf("Les solutions sont:\nx1 = %f\nx2 = %f\n", x1, x2);
	}
}
