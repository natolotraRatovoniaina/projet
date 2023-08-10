#include <stdio.h>

int main(){
	
	printf("Comparer les chiffres des deux tableaux\n");
	
	int tab[10];
	int tab2[10];
	int i;
	
	printf("Entrez les nombres:\n");
	
	for(i=0;i<10;i++){	
		scanf("%d", &tab[i]);
	}
	
	printf("Entrez les nombres:\n");
	
	for(i=0;i<10;i++){	
		scanf("%d",&tab2[i]);
	}
	
	for(i=0;i<10;i++){
		if(tab[i] == tab2[i]){
			printf("%d et %d sont egaux\n", tab[i], tab2[i]);
		}
		else{
			printf("%d et %d ne sont pas egaux\n", tab[i], tab2[i]);
		}
	}
	return 0;
}
