#include <stdio.h>
#include <math.h>

int main(){
	printf("Calcul des sinus\n");

	float x, y;
	
	printf("Entrez x: ");
	scanf("%f" , &x);
	
	y = sin(x);
	
	printf("y= %f\n" , sin(x));

	return 0;
}
