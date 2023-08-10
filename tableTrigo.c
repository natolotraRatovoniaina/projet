#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926535

int main(){
	
	FILE *fichier = fopen("trigo.csv", "w+");
	
	fputs("Angles,Cosinus,Sinus,Tangente, Cotangente\n", fichier);
	
	for(int i = 0.; i<=360; i++){
	
		fprintf(fichier, "%d,%f,%f,%f,%f\n", i, cos((i*PI/180)), sin((i*PI/180)), tan((i*PI/180)),(1/tan((i*PI/180))));
	
	}
	
	fclose(fichier);
	
	return 0;
	
}
