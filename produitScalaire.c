#include <stdio.h>
#include "display.h"
#include "pscal.h"
//float pscal(int dim, float* u, float* v);
//void display(int dim, float* u, float* v, float prod);

int main(){
	
	printf("Calcul de produit scalaire de 2 vecteur\nn");

///Données:
	float 	u[3]={1. , 2. , 3. },		//déclaration de tableau de type float
			v[3]={1. , 4. , 5. };
	int dim=3;
	
	float prod=0.35;					//le produit scalaire
///Calcul:
	
	prod = pscal(dim, u, v);
	
	/*
	  for(int i=0; i<3; i++){
		prod += (u[i]*v[i]);
	}*/
	
///Sortie:
	display(dim, u, v, prod);
	printf("Le produit scalaire de u et v est= %f", prod);

	return 0;
	
}

