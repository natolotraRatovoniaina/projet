void copieTableau(int tableauOriginal[], int tableauCopie[], int tailleTableau){
	
	int i=0;
	
	for(i=0; i<tailleTableau; i++){
		
		printf("Entrez la valeur du tableauOriginal[%d]\n", i);
		scanf("%d", &tableauOriginal[i]);
		
	}
	
	for(i=0; i<tailleTableau; i++){
		
		tableauCopie[i]=tableauOriginal[i];
		
	}
	
	for(i=0; i<tailleTableau; i++){
		
		
		printf("Les valeurs dans tableauCopie[%d] est %d\n", i, tableauCopie[i]);
		
	}
	
}
