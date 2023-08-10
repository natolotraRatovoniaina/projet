#include <stdio.h>
int Tableau(int t);

int main(){

	printf("Ranger dans l'ordre croissante les nombres\n");
	
	int* t=0;
	
	printf("Entrez les nombres:\n");
	
	Tableau(&t);
	
	for(int i=0;i<10;i++){	
		scanf("%d",&tab[i]);
	}
	
	for(int i=0;i<1+10;i++){
		for(int j=i+1;j<10;j++){
			if(tab[i]>tab[j]){
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
		}
	}
	
	for(int i=0;i<10;i++){
		printf("%d", tab[i]);
	}
	
	return 0;
}
int* Tableau(){

	int tab[10];
	int tmp;


	return 0;
}
