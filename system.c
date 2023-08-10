#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	printf("Choisissez un commande que vous voulez utiliser\n");

	printf("Ce sera entre ls, cd, pwd et ls -a\n");
	
	int choix=0;
	
	printf("Ecrit 1 pour ls, 2 pour cd, 3 pour pwd et 4 pour ls -a");
	scanf("%d", &choix);
	
	switch(choix){
		
		case 1:
				system("ls");
				break;
		case 2:
				system("cd Documents; ls");				
				break;
		case 3:
				system("pwd");
				break;
		case 4:
				system("ls -a");
				break;
		
	}

	return 0;

}
