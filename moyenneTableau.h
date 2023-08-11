double moyenneTableau(float tableau[], int tailleTableau){

	float moyenne=0;
	
	printf("Entrez les valeurs des tableaux\n");
	
	for(int i=0; i<10; i++){
		
		scanf("%f", &tableau[i]);
		
		moyenne+=tableau[i];
		
	}

	return moyenne/=10;
	
}
