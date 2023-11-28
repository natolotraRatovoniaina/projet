#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display();
void displayStyle();
char* translatedate(char* month, char* day,int years);
void pagingNameSend();
void archiveName();
int getNbrPage();
int getLine();

int main()
{
	printf("Content-type:text/html\n\n");
	printf("<html lang=\"en\">");
	printf("<head><meta charset=\"UTF-8\">");
    printf("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">");
    printf("<style>\n");
    
	displayStyle();
	
	printf("</style>");
	printf("</head>");
	
	archiveName();
	display();
	
	printf("</html>");

	return 0;
}

void display()
{
	FILE *file = fopen("./archive.txt","r");
	char container[250];
	char date[250];
	char year[50];
	char month[40]; 
	char day[100];
	char dayInt[5];
	char time[200]; 
	char url[200];
	char ip[200];
	int count=1;
	
	pagingNameSend();
	
	printf("<table id=\"tab\"border=\"2\">");
	printf("<tr>");
	printf("<td width=\"150px\"><font color=\"darkblue\"><center>Heure</center></font></td>");
	printf("<td width=\"150px\"><font color=\"darkblue\"><center>Jour</center></font></td>");
	printf("<td width=\"150px\"><font color=\"darkblue\"><center>Mois</center></font></td>");
	printf("<td width=\"150px\"><font color=\"darkblue\"><center>Annee</center></font></td>");
	printf("<td width=\"100px\"><center><font color=\"darkblue\">URL</font></center></td>");
	printf("<td width=\"70px\"><font color=\"darkblue\"><center>Addresse IP</center></font></td>");
	printf("</tr>");
	
	while(fgets(container,250,file))
	{
		if(count<=10)
		{
			sscanf(container,"%s %s %[^\n]",ip,date,url);
			sscanf(date,"%[^/]/%[^/]/%[^:]:%s",day,month,year,time);
			strcpy(date,translatedate(month,day,atoi(year)));
			sscanf(date,"%s %s %s %s",day,dayInt,month,year);
			if(strstr(ip,"192.")||strstr(ip,"127."))
			{
				printf("<tr>");
				printf("<td><center><font color=\"yellow\">%s</font></center></td>" 
					"<td><center><font color=\"white\">%s, %s</font></center></td>" 
					"<td><center><font style=\"color:maroon;\">%s</font></center></td>"
					"<td><center><font style=\"color:maroon;\">%s</font></center></td>"
					"<td ><center><font color=\"green\">%s</font</center></td>" 
					"<td><center><font color=\"black\">%s</font></center></td></tr>"
					,time,day,dayInt,month,year,url,ip);
					count++;
			}
	
		}
		
	}
	
	printf("</table>");
	fclose(file);

}

void displayStyle()
{
	char container[250];
	FILE* file=fopen("./stylesDisplayAccess.css","r");
	while(fgets(container,250,file))
		printf("%s",container);
	fclose(file);
}

void pagingNameSend()
{
	int page=1;
	int nbrPage=getNbrPage();
	int end=page+4;
	int begin=page-5;
	if(end>nbrPage)
		end=nbrPage;
	if(begin<0)
		begin=0;
	printf("<form action=\"http://localhost/cgi-bin/accessPaging.cgi\" method=\"get\">");
	printf("<div id=\"div2\">");
	for(int i=begin;i<end;i++)
	{
	if(i+1==page)
		printf("<input style=\"height:30px;width:25px;\" name=\"nombre\" type=\"submit\" value=\"%d\"/>",i+1);
	else
		printf("<input style=\"height:30px;width:25px;\" name=\"nombre\" type=\"submit\" value=\"%d\"/>",i+1);
	}
	printf("</form>");
	printf("</div>");
}

int getNbrPage()
{
	int line=getLine();
	int nbrPageReturn=0;
	while(line>0)
	{
		line-=10;
		nbrPageReturn+=1;
	}
	return nbrPageReturn;
}

int getLine()
{
	FILE *file=popen("cat ./archive.txt | wc -l", "r");
	char line[100];
	int lineReturn;
	fgets(line,100,file);
	sscanf(line,"%d",&lineReturn);
	return lineReturn;
}

void archiveName()
{
	FILE *file=NULL;
	file=fopen("/var/log/apache2/access.log.1","r");
	FILE *receptacle=NULL;
	receptacle=fopen("./archive.txt","w");
	char container[250];
	char ip[200];
	char date[200];
	char url[200];
	while(fgets(container,200,file))
	{	
		sscanf(container,"%[^ ] - - [%[^ ] +0300] \"%*[^\"]\" %*[^ ] %*[^ ] \"%[^\"]\" ",ip,date,url);
		fprintf(receptacle,"%s %s %s\n",ip,date,url);
	}

	fclose(file);
	fclose(receptacle);
}

char* translatedate(char* month, char* day,int years)
{
	char* date=malloc(250);
	char *Day[] = {"Sabotsy","Alahady","Alatsinainy","Talata","Alarobia","Alakamisy","Zoma"};
	char *acronymMonth[]= {"Mar","Avr","Mai","Jun","Jui","Aug","Sep","Oct","Nov","Dec","Jan","Fev"};
	char *Month[] = {"Martsa","Aprily","May","Jona","Jolay","Aogostra","Septambra","Oktobra","Novambra","Desambra","Janoary","Febroary"};
	int dayIntReturn = atoi(day);
	int m = 0;
    char MonthReturn[100];
    int Years = years;
    char dayReturn[100];
    int n=0;
    for(int i = 0; i < 12; i++){
        if(!(strcmp(acronymMonth[i],month))){
            m = i+3;
            strcpy(MonthReturn,Month[i]);
        }
    }
    n = (dayIntReturn + (26*(m + 1))/10 + (Years%100) + ((Years%100)/4) + ((Years/100)/4) + ((Years/100)*5))%7;
    strcpy(dayReturn,Day[n]);
    sprintf(date,"%s %d %s %d",dayReturn,dayIntReturn,MonthReturn,Years);
    
    return date;
}
