#include <stdio.h>
#include <stdlib.h>

void GetN_max(int *tab,int *taille);
void getdata(int* tab,int *taille);
void displayresult(int* tab);

int main(){
	int *tab;
	int taille=0;
	printf("Entrer la taille:");scanf("%d",&taille);
	tab=(int*)malloc(sizeof(int)*taille);
	getdata(tab,&taille);
	GetN_max(tab,&taille);
	displayresult(tab);
	free(tab);
	return 0;
}

void getdata(int* pointeur,int *tailleTab){
	for(int i=0;i<*tailleTab;i++){
		printf("Entrer tab[%d]:",i);scanf("%d",pointeur+i);
	}
}

void displayresult(int* pointeur){
	
	int N_max = 0;
	
	printf("Entrez le nombre de chiffre maximum à afficher que vous voulez:");
	scanf("%d", &N_max);
	
	for(int i=0;i<N_max;i++){
		printf(" %d",*(pointeur+i));
	}
	printf("\n");
}

void GetN_max(int *pointeur,int *tailleTab){
	int index=0;
	for(int i=0;i<*tailleTab;i++){
		for(int j=i+i;j<*tailleTab;j++){
			if(pointeur[i]==pointeur[j]){
				index=j;
				for(int b=index;b<*tailleTab-1;b++){
				pointeur[b]=pointeur[b+1];
				}
				(*tailleTab)--;
			}
		}
	}
			
	
	for(int i=0;i<*tailleTab;i++){
		for(int j=i+1;j<*tailleTab;j++){
			if(pointeur[i]<pointeur[j]){
				int tmp;
				tmp=pointeur[i];
				pointeur[i]=pointeur[j];
				pointeur[j]=tmp;
			}
		}
	}
}


				
				
				
				
