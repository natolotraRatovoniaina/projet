#include <stdio.h>
#include <math.h>

float condition(float a, float b, float c, float delta,float x1,float x2){
	
	delta = b*b - 4*a*c;
	
	if (delta >= 0){
		x1 = (-b-sqrt(delta))/(2*a);
		x2 = (-b+sqrt(delta))/(2*a);
	}
	else{
		printf("Il n'y a pas de solution\n");
	}
	
	printf("les solutions sont:\n");
	printf("x1= %f\nx2= %f\n" , x1 , x2);
	
	return delta;
}
int main(){
	
	float a,b,c,delta,x1,x2;
	
	printf("Resolution de ax“+bx+c=0\n");
	
	printf("Entrez a:");
	scanf("%f", &a);

	printf("Entrez b:");
	scanf("%f", &b);
	
	printf("Entrez c:");
	scanf("%f", &c);
	
	delta=condition(a,b,c,delta,x1,x2);
/*	
	delta = b*b - 4*a*c;
	
	if (delta >= 0){
		x1 = (-b-sqrt(delta))/(2*a);
		x2 = (-b+sqrt(delta))/(2*a);
	}
	else{
		printf("Il n'y a pas de solution\n");
	}
*/			
		return 0;
}

