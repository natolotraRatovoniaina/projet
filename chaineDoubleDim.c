#include <stdio.h>

int main(){

	char mois[12] [10]={"Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin", "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "Decembre"};
	
	int n;
	
	printf("Taper le nombre du mois:\n");
	scanf("%d", &n);

	printf("Le mois est %s", mois[n-1]);

	return 0;

}
