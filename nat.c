#include <stdio.h>

int main (){
	printf("Calcul de 1+3...+n\n");
	
	int n,m, somme=0;
	int i=1;
	
	printf("Entrez n:");
	scanf("%d" , &n);

	m=2*(n)-1;
	
	printf("m donne alors %d\n ", m);

	for(i=1;i<=m;i+=2){
		somme+=i;
	}
		
	printf("La somme est donc %d\n" , somme);

	return 0;
}
