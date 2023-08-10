#include <stdio.h>

int main(){
	
	int age=0;
	int argent=0;
	
	printf("Quel age as-tu?\n");
	scanf("%d", &age);
	
	printf("Combien d'argent as-tu?\n");
	scanf("%d", &argent);
	
	if (age > 30 && argent > 100000){
	
		printf("Bienvenue chez PicsouBanque !");
	}
	
	else{
		
		printf("Hors de ma vue, miserable !");
	}
	
	return 0;
}
