#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* getUnit(int nombre);
char* getDizaine(int nombre);
char* getCentaine(int nombre);
int charToInt(char* atransf);
double puiss(int nbr, int exp);
char* nbrTradMLG(long int atrad, int longAtrad);
int longeurNbr(long int trouverlong);

int main(){
	
	long int nbrAtrad = 111112111;
	char* nbrChar = NULL;
	int longNbr = 0;
	
	longNbr = longeurNbr(nbrAtrad);
	nbrChar = nbrTradMLG(nbrAtrad, longNbr);
	printf("%s", nbrChar);

	return 0;

}
double puiss(int nbr, int exp){
	
	double nbrReturn = 1.0;
	if(exp>0){
		for(int i=0; i<exp; i++){
		
			nbrReturn *= nbr;
			
		}
	}
	
	if(exp<0){
		for(int i=0; i>exp; i--){
		
			nbrReturn /= nbr;
			
		}
	}
	
	return nbrReturn;
}
char* getUnit(int unit){
	char ltskFolo[10][7]={"","iray","roa","telo","efatra","dimy","enina","fito","valo","sivy"};
	char* tradUnit=ltskFolo[unit];
	return tradUnit;
}

char* getDizaine(int diz){
	char tsiFolofolo[10][10]={"","folo","roapolo","telopolo","efatra","dimapolo","enimpolo","fitopolo","valopolo","sivifolo"};
	char* tradDiz=tsiFolofolo[diz];
	return tradDiz;
}

char* getCentaine(int cent){
	char tsiZatozato[10][15]={"","zato","roan-jato","telon-jato","efa-jato","diman-jato","enin-jato","fiton-jato","valon-jato","sivin-jato"};
	char* tradCent=tsiZatozato[cent];
	return tradCent;
}
int charToInt(char* atransf){
	
	int nbrReturn = 0;
	int taille = strlen(atransf)-1;
	
	for(int i=0; i<=taille; i++){
	
		nbrReturn += (atransf[i] -'0')*puiss(10,(taille-i));
		
	}
	
	return nbrReturn;
}
int longeurNbr(long int trouvLong){
	
	int longNbr = 0;
	
	while(trouvLong!=0){
	
		trouvLong /= 10;
		
		longNbr++;
	}
	
	return longNbr;
}

char* nbrTradMLG(long int atrad, int longAtrad){
	
	char* tradMlg = malloc(100);
	char alaOlana[10][7]={"","","roa ","telo ","efatra ","dimy ","enina ","fito ","valo ","sivy "};
	char marikisa[8][15]={"","","","arivo"," alina"," hetsy"," tapitrisa"," lavitrisa"};
	char mpampitohy[8][15]={" ambin'ny "," sy "," sy "," sy "," sy "," sy "," sy ",""};
	char mpampitohyZato[15] ={" amin'ny "};
	int conserv=0;
	int makatapitrisa=0;
	
	if(atrad == 0){
		
		tradMlg = "aotra";
		
	}
	
	else{
	
		for(int i=0;i<longAtrad;i++){
			
			conserv = atrad % 10;
			makatapitrisa = atrad % 1000;
			atrad /= 10;
			
			if((conserv!=0 && i<6) || (i>5 && makatapitrisa!=0)){
				
				if(i==0 || i==4 || i==5){
				
					strcat(tradMlg,getUnit(conserv));
				
				}
				
				else if(i==1){
				
					strcat(tradMlg,getDizaine(conserv));
				
				}
				
				else if(i==2){
				
					strcat(tradMlg,getCentaine(conserv));
				
				}
				
				else if(i==3){
				
					strcat(tradMlg,alaOlana[conserv]);
				
				}
				
				else if(i==6 || i==7){

					strcat(tradMlg, nbrTradMLG(makatapitrisa,longeurNbr(makatapitrisa)));
					
					atrad /= 100;

				}
			
				strcat(tradMlg,marikisa[i]);

				if(i==1){
					
					conserv = atrad%10;
				
					if(conserv == 1){
					
						strcat(tradMlg,mpampitohyZato);
					
					}
					
					else{
					
						if(atrad!=0){
			
							strcat(tradMlg,mpampitohy[i]);
				
						}

					}
				
				}
				else{
					
					if(atrad!=0){
			
						strcat(tradMlg,mpampitohy[i]);
				
					}

				}
							
			}
		
		}
	
	}
	
	return tradMlg;
	
}
