#include <stdio.h>
void displayResult(int n, int somme);

int main(){

	printf("Somme des n premiers entiers non nuls\n");
	
	int n, somme=0;
	int i=1;
	
	while (n != 0){
		printf("Entrez n non nul: ");
		scanf("%d" , &n);
	
		for(i=1, somme=0; i<=n; i++){
			somme += i;
		}
		
		//printf("la somme des %d premiers entiers = %d\n", n, somme)void;
		displayResult(n, somme);
	}
	
	return 0;
}
	
void displayResult(int n, int somme){
	printf("la somme des %d premiers entiers = %d\n", n, somme);
}
