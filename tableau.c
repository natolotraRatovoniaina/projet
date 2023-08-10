#include <stdio.h>

int main(){

	printf("Ranger dans l'ordre croissante les nombres\n");
	
	int tab[10];
	int tmp,i,j;
	
	printf("Entrez les nombres:\n");
	
	for(i=0;i<10;i++){	
		scanf("%d",&tab[i]);
	}
	
	for(i=0;i<1+10;i++){
		for(j=i+1;j<10;j++){
			if(tab[i]>tab[j]){
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
		}
	}
	
	for(i=0;i<10;i++){
		printf("%d ", tab[i]);
	}
	
	return 0;
}
