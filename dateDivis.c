#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char** getChaineJourMoisAn(char* datechaine);
char** didim(int pd, int dd);
int charToInt(char* atransf);
int puiss(int nbr, int exp);
double conversion(int* aconvert);
double dateDivision(char* dateAdiv, char* dateDivis);

int main(){

	char* dateAdiv = "11/11/2023" ;
	char* dateDivis = "11/11/1993";
	double quotient = 0.;
	
	quotient = dateDivision(dateAdiv, dateDivis);
	
	printf("%f", quotient);
	
	return 0;

}
double dateDivision(char* dateAdiv, char* dateDivis){
	
	char** dateAdivSep = NULL;
	char** dateDivisSep = NULL;
	int* jMAdiv = malloc(3);
	int* jMADivis = malloc(3);
	double jourAdiv = 0;
	double jourDivis = 0;
	double quotientReturn = 0.;
	
	dateAdivSep = getChaineJourMoisAn(dateAdiv);
	dateDivisSep = getChaineJourMoisAn(dateDivis);
	
	for(int i = 0; i<3; i++)
	jMAdiv[i] = charToInt(dateAdivSep[i]);
	
	for(int i = 0; i<3; i++)
	jMADivis[i] = charToInt(dateDivisSep[i]);
	
	jourAdiv = conversion(jMAdiv);
	
	jourDivis = conversion(jMADivis);
	
	quotientReturn = jourAdiv / jourDivis;
	
	return quotientReturn;
}
char** getChaineJourMoisAn(char* datechaine){
	
	char** jMA = NULL;
	int j=0;
	int plcSlash=0;
	
	jMA = didim(3,10);
	
	for(int i=0; i<=strlen(datechaine); i++){
		
		if((datechaine[i]=='/' || datechaine[i]=='\0')){
			
			jMA [j] [plcSlash] = '\0';
			plcSlash = 0;
			j++;
			continue;
		}
			
			jMA [j] [plcSlash] = datechaine [i];
			
			plcSlash++;
	
	}
	
		return jMA;

}
char** didim(int pd, int dd){
	
	char** tabReturn;
	
	tabReturn = (char**)malloc(sizeof(char*)*pd);
	
	for(int i=0; i<pd; i++){
		
		*(tabReturn+i)=(char*)malloc(sizeof(char)*dd);
		
	}
	
	return tabReturn;
	
}
int charToInt(char* atransf){
	
	int nbrReturn = 0;
	int taille = strlen(atransf)-1;
	
	for(int i=0; i<=taille; i++){
	
		nbrReturn += (atransf[i] -'0')*puiss(10,(taille-i));
		
	}
	
	return nbrReturn;
}
int puiss(int nbr, int exp){
	
	int nbrReturn = 1;
	if(exp>0){
		for(int i=0; i<exp; i++){
		
			nbrReturn *= nbr;
			
		}
	}
	return nbrReturn;
}
double conversion(int* aconvert){
	
	double jourReturn = 0.;
	
	jourReturn += aconvert[0];
	
	jourReturn += aconvert[1]*31;
	
	jourReturn += aconvert[2]*365;
	
	return jourReturn;

}
