#include <stdio.h>

int main(){

	printf("Entrer des valeurs dans un tableau à deux dimensions.\n");
	
	int tab [2] [3] [4];
	
	int i;
	
	int j;
	
	int k;
	
	for(i=0; i<2; i++){
		
		for(j=0; j<3; j++){
			
			for(k=0; k<4; k++){
				
				scanf("%d", &tab[i] [j] [k]);
			
			}
			
		}
	
		
	}
	
/*	
	for(i=0; i<2; i++){
		
		for(j=0; j<3; j++){
			
			for(k=0; k<4; k++){
				
				printf("%d", tab[i] [j] [k]);
			
			}
			
		}
	
		
	}
*/	

	return 0;

}
