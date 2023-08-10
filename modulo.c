#include <stdio.h>
int main(int argc, char *argv[]){

	printf("Calcul de modulo\n");
	
	long x=0, n=0;
	long resultat;
	
	printf("Entrez x:");
	scanf("%ld", &x);
	
	printf("Entrez n:");
	scanf("%ld", &n);
	
		resultat = x % n;

	printf("%ld congrue a %ld modulo %ld " , x,resultat, n);

	return 0;
}
