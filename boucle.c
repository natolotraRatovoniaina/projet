#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]){
	
	double x=0,n;
	
	printf("Entrez x:");
	scanf("%lf", &x);
	
	n = fabs(x) ;
	
	printf("fabs(x) = %lf", n);
	
	return 0;
}
