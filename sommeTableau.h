int sommeTableau(int tableau[], int tailleTableau){
	
	int somme=0, i=0;
	for(i=0, somme=0; i<tailleTableau; i++){
			
		printf("Entrez les valeurs dans le tableau\n");
		scanf("%d", &tableau[i]);

		somme+=tableau[i];
	
	}
	
	return somme;

}
