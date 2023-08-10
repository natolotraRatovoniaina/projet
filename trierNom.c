#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	printf("Arranger les noms dans l'ordre de l'alphabet.\n");

	char tmp[30];
	int k=0;
	char **noms;
	
	noms=(char**)malloc(sizeof(char*)*5);
	
	for(int i=0; i<5; i++){
		
		noms[i]=(char*)malloc(sizeof(char)*30);
	
	}
	
	printf("Entrez les noms:\n");
	
	for(int i=0; i<5; i++){
		
		scanf("%s", noms[i]);
		
	}
	
	for(int i=0; i<5; i++){
		
		for(int j=i+1; j<5; j++){
			
			while(noms[i][k]==noms[j][k]){
				
				k++;
				
			}
			
			if(noms[i][k]>noms[j][k]){
				
				strcpy(tmp, noms[i]);
				
				strcpy(noms[i], noms[j]);
				
				strcpy(noms[j], tmp);
				
			}
			
		}
		
	}
	
	printf("Les noms triés sont:\n");
	
	for(int i=0; i<5; i++){
	
		printf("%s\n", noms[i]);
		
	}
		
	return 0;

}
