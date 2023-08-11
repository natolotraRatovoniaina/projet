#ifndef DEC_STRUCT_H
#define DEC_STRUCT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define nb 50;

typedef struct
{	
	char label[30];
	char marque[40];	
	char mac[20];
}
Machine;

Machine* inputData(int nbrPc);
void sort(Machine* container, int nbr);
void insertData(Machine* container, int nbr, char* nameFic);

Machine* inputData(int nbrPc)
{
	Machine* Pc;
	Pc=(Machine*)malloc(sizeof(Machine)*nbrPc);
	
	for(int i=0; i<nbrPc; i++)
	{	
		printf("Entrer le nom du proprietaire : ");
		scanf("%[^\n]", (Pc+i)->label);
		printf("Entrer la marque du Pc : ");
		scanf("%[^\n]", (Pc+i)->marque);
		printf("Entrer l'adresse Mac du Pc : ");
		scanf("%[^\n]", (Pc+i)->mac);
	}
	
	return Pc;

}

void sort(Machine* container, int nbr)
{
	for(int i=0; i<nbr; i++)
	{
		for(int j=i+1; j<nbr; j++)
		{
			if(strcmp(((container+i)->label), ((container+j)->label))>0)
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
	fprintf(fic, "LABEL,MARQUE,MAC\n");
	
	for(int i=0; i<nbr; i++)
	{
		fprintf(fic, "%s,%s,%s\n",(container+i)->label, (container+i)->marque, (container+i)->mac);
	}
	
}

#endif
