#ifndef DEC_STRUCT_H
#define DEC_STRUCT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define nb 50;

typedef struct
{	
	char nom[30];
	char prenom1[40];
	char prenom2[40];
	char date[20];
	int numero;
	char sexe[20];
	char git[50];
	char mail[50];
}	
Machine;

Machine* inputData(int nbrEt);
void sort(Machine* container, int nbr);
void insertData(Machine* container, int nbr, char* nameFic);

Machine* inputData(int nbrEt)
{
	Machine* Etudiant;
	Etudiant=(Machine*)malloc(sizeof(Machine)*nbrEt);
	
	for(int i=0; i<nbrEt; i++)
	{	
		printf("Entrer le nom : ");
		scanf("%s", (Etudiant+i)->nom);
		printf("Entrer le premier prenom : ");
		scanf("%s", (Etudiant+i)->prenom1);
		printf("Entrer le second prenom(facultatif) : ");
		scanf("%s", (Etudiant+i)->prenom2);
		printf("Entrer la date de naissance : ");
		scanf("%s", (Etudiant+i)->date);
		printf("Entrer le numero : ");
		scanf("%d", &(Etudiant+i)->numero);
		printf("Entrer le sexe : ");
		scanf("%s", (Etudiant+i)->sexe);
		printf("Entrer le nom sur git : ");
		scanf("%s", (Etudiant+i)->git);
		printf("Entrer l'adresse mail : ");
		scanf("%s", (Etudiant+i)->mail);
	}
	
	return Etudiant;

}

void sort(Machine* container, int nbr)
{
	for(int i=0; i<nbr; i++)
	{
		for(int j=i+1; j<nbr; j++)
		{
			if(strcmp(((container+i)->nom), ((container+j)->nom))>0)
			{	
				Machine tmp;
				tmp=container[i];
				container[i]=container[j];
				container[j]=tmp;				
			}
		}
	}
}
void insertData(Machine* container, int nbr, char* nameFic)
{
	FILE *fic =fopen(nameFic, "w+");
	fprintf(fic, "Nom,Prenom,Date de Naissance,Numero,Sexe,Nom sur git, Mail\n");
	
	for(int i=0; i<nbr; i++)
	{
		fprintf(fic,"%s,%s %s,%s,%d,%s,%s,%s\n",(container+i)->nom, (container+i)->prenom1,(container+i)->prenom2, (container+i)->date, (container+i)->numero, (container+i)->sexe, (container+i)->git,(container+i)->mail);
	}
	
}

#endif
