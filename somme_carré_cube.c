#include <stdio.h>
void display(int n, int Scarres, int Scubes);
void sommes(int n, int* pscar, int* pscubes);

int main(){
	
	printf("Calcul de la somme des carrés et des cubes des n premiers entiers non nuls\n");
	
//Données:	
	
	int n=0, Scarres=0, Scubes=0;
	
	//printf("Entrez la valeur de n:");
	//scanf("%d", &n);
	
//Transformation:
	
	sommes(n, &Scarres, &Scubes);

//Résultat:	

	display(n, Scarres, Scubes);
	
	return 0;

}

void sommes(int n, int* pscar, int* pscubes){
	
	int k=0;
	*pscar=0;
	*pscubes=0;
	
	for(k=1; k<=n; k++){
		
		*pscar += (k*k);
		
		*pscubes += (k*k*k);
	}

}

void display(int n, int Scarres, int Scubes){
	
	printf("La sommes des carres des %d premiers non nuls est: %d\n", n, Scarres);
	printf("La sommes des cubes des %d premiers non nuls est: %d", n, Scubes);
	
}
