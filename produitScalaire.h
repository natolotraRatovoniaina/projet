int produitScalaire(int*  vect1, int* vect2){

	int resultReturn = 0;

	for(int i = 0;i<2; i++){
	
		resultReturn += vect1[i]*vect2[i];
	
	}

	return resultReturn;

}
