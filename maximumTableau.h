void maximumTableau(int tableau[], int tailleTableau, int valeurMax){
	
	int i=0;
		
	
	
	for(i=0; i<tailleTableau; i++){
			
		printf("Entrez la valeur du tableau[%d]\n", i);
		scanf("%d", &tableau[i]);
		
	}
		
	for(i=0; i<tailleTableau; i++){
	
		if(tableau[i]>valeurMax){
			
			tableau[i]=0;
		
		}
		
		printf("la valeur du tableau[%d] est %d\n", i, tableau[i]);	
		
	}
	
}
