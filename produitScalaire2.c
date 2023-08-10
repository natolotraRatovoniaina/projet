#include <stdio.h>
#include "produitScalaire.h"
//int produitScalaire(int* vect1, int* vect2);

int main(){

	int vect1[2] = {2,5};
	
	int vect2[2] = {2,5};

	int result = produitScalaire(vect1, vect2);

	printf("%d", result);

	return 0;

}
/*int produitScalaire(int* vect1, int* vect2){

	int resultReturn = 0;
	
	for(int i = 0;i<2 ; i++){

		resultReturn += vect1[i]*vect2[i];

	}

	return resultReturn; 

}*/
