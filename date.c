#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int* charToDate(char* aconvert);
int estVirg(char* virgTrouv);
double puiss(int nbr, int exp);
double combinerJour(char* nombre);
char** didim(int pd, int dd);
double** didimens(int pd, int dd);
char** getChaineJourMoisAn(char* datechaine);
char** getChaineHeureMinuteSeconde(char* chaineDateHMS);
char** separerVirg(char* nbrVirgEnlv, int placeVirg);
char** separerDpoint(char* hmsDpointEnl);
int charToInt(char* atransf);
double charToDouble(char* atransf);
int* conversionHMinSJMA(char** dateSep);
double hmsConversionJ(char** hmsconvert);



int main(){
	
	char* nombre = "10/05/2022 00:00:00";
	char* date = "10,50/10/2023";
	double jFloatant = 0.;
	int* dateConv;
	
	jFloatant = combinerJour(nombre);
	
	dateConv = charToDate(date);
	
	printf("%lf", jFloatant);
	
	for(int i = 0; i<6; i++)
	printf("%d\n", dateConv[i]);
	
	return 0;

}

int charToInt(char* atransf){
	
	int nbrReturn = 0;
	int taille = strlen(atransf)-1;
	
	for(int i=0; i<=taille; i++){
	
		nbrReturn += (atransf[i] -'0')*puiss(10,(taille-i));
		
	}
	
	return nbrReturn;
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

double charToDouble(char* atransf){
	
	double nbrReturn = 0.0;
	int placeVirg = 0;
	double devVirg = 0.00;
	double derVirg =0.00;
	
	placeVirg = estVirg(atransf);
	
	for(int i=0; i<strlen(atransf); i++){
		
		if(placeVirg > i){
		
			devVirg += ((atransf[i] - '0'))*(puiss(10, (placeVirg-i-1)));
		
		}
	
		else if(placeVirg < i){
		
			derVirg += ((atransf[i] - '0'))*(puiss(10, (-i+placeVirg)));
		
		}
		
		else if(placeVirg == 0){
		
			devVirg += ((atransf[i] - '0'))*(puiss(10, (placeVirg+i)));
		
		}
	
	}
	
	nbrReturn = devVirg + derVirg;
	
	return nbrReturn;
	
}

int estVirg(char* virgTrouv){
	
	int nbrReturn = 0;
	
	for(int i=0; i<strlen(virgTrouv); i++){
	
		if((virgTrouv[i] == ',')){
	
			nbrReturn = i;
			
			break;
		}
		
	}

	return nbrReturn;
	
}

char** separerVirg(char* nbrVirgEnlv, int placeVirg){
	
	char** jmaVirgEnlev = NULL;
	
	jmaVirgEnlev = didim(2,(strlen(nbrVirgEnlv)-placeVirg));
	
	for(int i=0; i<placeVirg; i++){
	
		jmaVirgEnlev [0] [i] = *(nbrVirgEnlv+i);
	
	}
	
	for(int i=placeVirg; i<strlen(nbrVirgEnlv); i++){
	
		jmaVirgEnlev [1] [i-(placeVirg)] = *(nbrVirgEnlv+i);
	
	}
	
	return jmaVirgEnlev;
	
}

char** didim(int pd, int dd){
	
	char** tabReturn;
	
	tabReturn = (char**)malloc(sizeof(char*)*pd);
	
	for(int i=0; i<pd; i++){
		
		*(tabReturn+i)=(char*)malloc(sizeof(char)*dd);
		
	}
	
	return tabReturn;
	
}

double** didimens(int pd, int dd){
	
	double** tabReturn;
	
	tabReturn = (double**)malloc(sizeof(double*)*pd);
	
	for(int i=0; i<pd; i++){
		
		*(tabReturn+i)=(double*)malloc(sizeof(double)*dd);
		
	}
	
	return tabReturn;
	
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

	if(strchr(*(jMA+0), ',')== NULL){
		
		strcat(*(jMA+0), ",0");
	
	}
	
	if(strchr(*(jMA+1), ',')== NULL){
		
		strcat(*(jMA+1), ",0");
	
	}
	if(strchr(*(jMA+2), ',')== NULL){
		
		strcat(*(jMA+2), ",0");
	
	}
	
	return jMA;

}

int* conversionHMinSJMA(char** dateSep){
	
	int* dateReturn = malloc(6); 
	for(int i=0; i<6; i++)
	*(dateReturn+i) = 0;
	int heure = 0;
	int min = 0;
	int* sec = malloc(3);
	for(int i=0; i<3; i++)
	*(sec+i) = 0; 
	int placeVirgJ =0;
	int placeVirgM = 0;
	int placeVirgA = 0;
	char** jVirg = NULL;
	char** mVirg = NULL;
	char** aVirg = NULL;
	char** detectM = NULL;
	int mois = 0;
	char** testBisext = NULL;
	int annee = 0;
	char** priseAfloat = NULL;
	double testAfloat =0.;
	double jfloat = 0.;
	double mfloat = 0.;
	double afloat = 0.;
	int* convention = malloc(5);
	
	placeVirgJ = estVirg(*(dateSep+0));
	
	placeVirgM = estVirg(*(dateSep+1));
	
	placeVirgA = estVirg(*(dateSep+2));
	
	detectM = separerVirg(*(dateSep+1), placeVirgM);
	mois = charToInt(*(detectM+0));
	
	testBisext = separerVirg(*(dateSep+2), placeVirgA);
	annee = charToInt(*(testBisext+0));
	
	priseAfloat = separerVirg(*(dateSep+2), placeVirgA);
	testAfloat = charToDouble(*(priseAfloat+1));
		
	*(convention+0) = 60;
	*(convention+1) = 60;
	*(convention+2) = 24;
	
	if(mois == 2){
	
		*(convention+3) = 28;
	
	}
	
	else if((mois == 2) && ((annee%4) == 0)){
	
		*(convention+3) = 29;
	
	}
	
	else if((mois==1)||(mois==3)||(mois==5)||(mois==7)||(mois==8)||(mois==10)||(mois==12)){
	
		*(convention+3) = 31; 
	
	}
	
	else if((mois==4)||(mois==6)||(mois==9)||(mois==11)){
	
		*(convention+3) = 30;
	
	}
	
	*(convention+4) = 12;
	
	if(placeVirgA != 0){
	
		aVirg = separerVirg(*(dateSep+2), placeVirgA);
	
		afloat = charToDouble(*(aVirg+1));
		
		if(afloat>0&&(annee%4)==0){
			
			sec[0] = 6*24*60*60;
			
		}
		else if(afloat>0&&(annee%4)!=0){
			
			sec[0] = 5*24*60*60;
			
		}
		else{
		
			sec[0] = 0;
			
		}
		
		sec[0] += afloat*12*30*24*60*60;
	
		dateReturn[5] = charToInt(*(aVirg+0));
	
	}
	else{
		
		dateReturn[5] = charToInt(dateSep[2]);
		
	}
	
	if(placeVirgM != 0){
		
		mVirg = separerVirg(*(dateSep+1), placeVirgM);
	
		mfloat = charToDouble(*(mVirg+1));
		
		for(int i=3; i>=0; i--){
			
			mfloat *= convention[i];
		
		}
	
		sec[1] += mfloat;
	
		dateReturn[4] = charToInt(*(mVirg+0));
	
	}
	else{
		
		dateReturn[4] = charToInt(dateSep[1]);
	
	}
	
	if(placeVirgJ != 0){
		
		jVirg = separerVirg(*(dateSep+0), placeVirgJ);
		
		jfloat = charToDouble(*(jVirg+1));
	
		for(int i=2; i>=0; i--){
			
			jfloat *= convention[i];
		
		}	
	
		sec[2] += jfloat;
		
		dateReturn[3] = charToInt(*(jVirg+0));
	}
	else{
		
		dateReturn[3] = charToInt(dateSep[0]);
		
	}
	
	for(int i=0; i<3; i++){
		
		dateReturn[0] += sec[i];
	
	}
	
	dateReturn[1] = min;
	dateReturn[2] = heure;
	
	if(testAfloat==0){
		
		dateReturn[1] = dateReturn[0] / convention[0];

		dateReturn[0] = dateReturn[0] % convention[0];

		dateReturn[2] = dateReturn[1] / convention[1];
	
		dateReturn[1] = dateReturn[1] % convention[1];
	
		dateReturn[3] += dateReturn[2] / convention[2];
	
		dateReturn[2] = dateReturn[2] % convention[2];
		
		dateReturn[4] += dateReturn[3] / convention[3];
	
		dateReturn[4] += dateReturn[3] / convention[3];
	
		dateReturn[5] += dateReturn[4] / convention[4];
	
		if((mois==2 && dateReturn[3]>28)){
		
			dateReturn[3] = (dateReturn[3] % 28) +1;
	
		}
	
		else if((mois==2 && (annee%4)==0 && dateReturn[3]>29)){
		
			dateReturn[3] = (dateReturn[3] % 29) +1;
	
		}
	
		else if(((mois==1)&&dateReturn[3]>31)||((mois==3)&&dateReturn[3]>31)||((mois==5)&&dateReturn[3]>31)||((mois==7)&&dateReturn[3]>31)||((mois==8)&&dateReturn[3]>31)||((mois==10)&&dateReturn[3]>31)||((mois==12)&&dateReturn[3]>31)){
		
			dateReturn[3] = (dateReturn[3] % 31) +1;
	
		}
	
		else if(((mois==4)&&dateReturn[3]>31)||((mois==6)&&dateReturn[3]>31)||((mois==9)&&dateReturn[3]>31)||((mois==11)&&dateReturn[3]>31)){
	
			dateReturn[3] = (dateReturn[3] % 30) +1;
	
		}
	
		if(dateReturn[4]>12){
	
			dateReturn[4] = (dateReturn[4] % 12) +1;
		
		}
	
	}
	
	else if(testAfloat>0&&placeVirgJ!=0){
		
		dateReturn[1] = dateReturn[0] / convention[0];

		dateReturn[0] = dateReturn[0] % convention[0];

		dateReturn[2] = dateReturn[1] / convention[1];
	
		dateReturn[1] = dateReturn[1] % convention[1];
	
		dateReturn[3] += dateReturn[2] / convention[2];
	
		dateReturn[2] = dateReturn[2] % convention[2];
		
		dateReturn[4] += dateReturn[3] / 30;
	
		dateReturn[3] += dateReturn[3] % 30;
	
		dateReturn[5] += dateReturn[4] / convention[4];
		
		if((dateReturn[3]>30)){
		
			dateReturn[3] = (dateReturn[3] % 30) +1;
	
		}
		
		if(dateReturn[4]>12){
	
			dateReturn[4] = (dateReturn[4] % 12) +1;
		
		}
	
	}
	
	return dateReturn;

}

int* charToDate(char* aconvert){
	
	char** dateSep = NULL;
	int* jmafloatConvert = NULL;

	dateSep = getChaineJourMoisAn(aconvert);
	
	jmafloatConvert = conversionHMinSJMA(dateSep);
	
	return jmafloatConvert;
}

char** getChaineHeureMinuteSeconde(char* chaineDateHMS){
	
	char** hmsSepdateReturn = NULL;
	int j=0;
	int plcEsp=0;
	
	hmsSepdateReturn = didim(2,15);
	
	for(int i=0; i<=strlen(chaineDateHMS); i++){
		
		if((chaineDateHMS[i]==' ' || chaineDateHMS[i]=='\0')){
			
			hmsSepdateReturn [j] [plcEsp] = '\0';
			plcEsp = 0;
			j++;
			continue;
		}
			
			hmsSepdateReturn [j] [plcEsp] = chaineDateHMS [i];
			
			plcEsp++;
	
	}
	
	return hmsSepdateReturn;

}

char** separerDpoint(char* hmsDpointEnl){
	
	char** hmsSepReturn = NULL;
	hmsSepReturn = didim(3,3); 
	int plcDp = 0;
	int j = 0;
	
		for(int i=0; i<=strlen(hmsDpointEnl); i++){
		
		if((hmsDpointEnl[i] == ':' || hmsDpointEnl[i]=='\0')){
			
			hmsSepReturn [j] [plcDp] = '\0';
			
			plcDp = 0;
			
			j++;
			
			continue;
		}
			
			hmsSepReturn [j] [plcDp] = hmsDpointEnl [i];
			
			plcDp++;
	
	}

	return hmsSepReturn;

}

double hmsConversionJ(char** hmsAconvert){
	
	double hmsConvJReturn = 0.;
	double** hmsAconv = NULL;
	
	hmsAconv = didimens(1,3);
	
	for(int i=0; i<3; i++){
	
		hmsAconv[0][i] = charToInt(*(hmsAconvert+i));
	
	}
	
	hmsConvJReturn = ((hmsAconv[0][2])+(hmsAconv[0][1]*60)+(hmsAconv[0][0]*60*60));
	
	hmsConvJReturn /= 86400;
	
	return hmsConvJReturn;

}

double combinerJour(char* nombre){
	
	double jFloatantReturn = 0.;
	char** hmsSepdate = NULL;
	char** hmsSep = NULL;
	double hmsConvJ = 0.;
	char** dateSep = NULL;
	
	hmsSepdate = getChaineHeureMinuteSeconde(nombre);
	
	hmsSep = separerDpoint(*(hmsSepdate+1));
	
	hmsConvJ = hmsConversionJ(hmsSep);
	
	dateSep = getChaineJourMoisAn(*(hmsSepdate+0));
	
	
	jFloatantReturn = charToDouble(*(dateSep+0));
	
	jFloatantReturn = jFloatantReturn + hmsConvJ;
	
	return jFloatantReturn;
	
}
