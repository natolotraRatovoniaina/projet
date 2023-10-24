#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <string.h>
#define epsilone 1e-9
double fonction(double x);
double derive(double a);
void tangente(double a);
void secante(double a,double b);
void dichotomie(double a,double b);

int main(int argc, char **argv)
{

    double a=1.5,b=3;    
   
    printf("Dichotomie\n\n");
	dichotomie(a,b);  
	
	printf("\nSecante\n\n");
	secante(a,b);
    
    printf("\nTangente\n\n");
	tangente(a);
	
	return 0;
}

double fonction(double x)
{	
	return log(x) - 1;
}

double derive(double a)
{
	return (fonction(a+epsilone)-fonction(a))/epsilone;
}

void tangente(double a)
{ 
	while(fabs(fonction(a))>epsilone)
	{
		a=-fonction(a)/derive(a)+a;
		printf("%lf\n",a);
	}
	
}

void secante(double a,double b)
{
	while(fonction(b)>epsilone)
	{
		
		if(fonction(a)*fonction(b)>0)
		{
			printf("Indefini");
			break;
		}
		
		b=(fabs(fonction(a))*b+fonction(b)*a)/(fabs(fonction(a))+fonction(b));
		printf("%lf\n",b);	
	}
	
}

void dichotomie(double a,double b)
{
	
    double milieu=0;
	
	while(fabs(a-b)>epsilone)
	{
	    milieu=(a+b)/2;
		if(fonction(a)*fonction(milieu)<0)
		{
			b=milieu;
			printf("%lf\n",milieu);
		}
	   	else if(fonction(milieu)*fonction(b)<0)
	   	{
			a=milieu;
			printf("%lf\n",milieu);
		}
		else
		{
			printf("Indefini");
			break;
		} 
	}
}
