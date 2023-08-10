#include <stdio.h>

int main(){
	
	char nom[20];
	char prenom[30];
	int age=0;
	
	scanf("%s", nom);
	
	scanf("%s", prenom);
	
	scanf("%d", &age);
	
	printf("Je m'apelle %s %s et j'ai %d ans", nom, prenom, age);


	return 0;
}
