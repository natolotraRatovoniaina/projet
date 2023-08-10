#include <stdio.h>

int main(){
		char nom[30];
	
		char prenom[20];
	
		int age=0;

		char pere[40];
		
		char mere[20];

		char adresse[30];

	printf("Quel est ton nom? ");
	scanf("%s" , nom );
	
	printf("Quel est ton prenom? ");
	scanf("%s" , prenom );
	
	printf("Quel age as-tu? ");
	scanf("%d" , &age );

	printf("bonjour %s %s qui a %d ans\n", nom , prenom , age );
	printf("Quel est le nom de ton pere? ");
	scanf("%s" , pere );

	printf("Quel est le nom de ta mere? ");
	scanf("%s" , mere );
	
	printf("Ou habites-tu? ");
	scanf("%s" , adresse );

	return 0;
}
