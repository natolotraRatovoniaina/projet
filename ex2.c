#include <stdio.h>

int main (){
	printf("Calcul de 1+3...+n\n");
	
	int n, somme=0;
	int i=1;
	
	printf("Entrez n non nul:");
	scanf("%d" , &n);
	
	while(n!=0){
		
		for(i=1;i<=2*n-1;i+=2){
			somme+=i;
		}
		printf("La somme est %d\n" , somme);
		
		printf("Entrez n non nul:");
		scanf("%d" , &n);
	}
		
	

	return 0;
}
