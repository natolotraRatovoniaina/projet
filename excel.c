#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double f(double x);

int main(){

	double min = 0., max = 0., inc = 0.;
	
	int nbrP = 0;

	FILE* fichier = fopen("fonction.csv", "w");
	
	if(fichier == NULL)
		exit(1);
	
	printf("Entrez la valeur minimale de l'intervalle : ");	
	scanf("%lf", &min);
	
	printf("Entrez la valeur maximale de l'intervalle : ");	
	scanf("%lf", &max);
	
	printf("Entrez le nombre de point que vous voulez avoir : ");	
	scanf("%d", &nbrP);
	
	inc = max/nbrP;
	
	fputs("y,x", fichier);
	
	for(double i = min ;i<=max; i+=inc){
	
		fprintf(fichier,"\n%g,%g\n", f(i), i);
		
	}
	
	fclose(fichier);
	
	return 0;
	
}
double f(double x){
	
	double result = 0.;
	
	result = 5*x/3;
	
	return result;
}
