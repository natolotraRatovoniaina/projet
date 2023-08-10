#include <stdio.h>
#include <math.h>
void getData(float* a, float* b, float* c);
void displayResult(float a, float b, float c, float delta, float x1, float x2);
float resolve1(float a, float b, float c, float* x1, float* x2);
float calcDelta(float a, float b, float c);

int main(){

	printf("Resolution de ax²+bx+c=0\n");

///Données
	
	float a=1, b=1, c=-2;	//les coeff. de l'équation
	float x1=876, x2=987.6;	//les solutions éventuelles
	float delta=1;			//Le discriminant de l'équation
	
	getData(&a, &b, &c);
	
///Calcul
	
	delta = resolve1(a, b, c, &x1, &x2);
/*	
  delta = calcDelta(a,b,c);
	
	if(delta >= 0){
		x1 = (-b -sqrt(delta))/(2*a);
		x2 = (-b +sqrt(delta))/(2*a);
	}
*/ 
///Sortie
	
	displayResult(a, b, c, delta, x1, x2);

	return 0;
}

void getData(float* pa, float* pb, float* pc){
	
	printf("Entrez a:");
	scanf("%f", pa);
	
	printf("Entrez b:");
	scanf("%f", pb);
	
	printf("Entrez c:");
	scanf("%f", pc);		
}

float resolve1(float a, float b, float c, float* x1, float* x2){
	
	float delta1=9876.;			//Le discriminant de l'équation 
	
		delta1 = calcDelta(a,b,c);
	
	if(delta1 >= 0){
		*x1 = (-b-sqrt(delta1))/(2*a);
		*x2 = (-b+sqrt(delta1))/(2*a);
	}
	
	return delta1;
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
