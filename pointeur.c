#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int *(tab);
	int a=10;
	int n=10;
	
	printf("Entrez la valeur de a:\n");
	scanf("%d", &a);
	
	tab= (int*)malloc(sizeof(int)*n);
	
	for(int i=0; i<n; i++){
		
		printf("N:%d\n", i);
		scanf("%d", &tab[i]);
		
	}
	
	for( int i=0; i<n; i++){
		
		printf("%d", tab[i]);
	
	}
	
	return 0;
}
