#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getLine();
int getNbrPage();
char* getName();
char* translatedate(char* month, char* day, int years);
void listDisplayNumberSend();
void pagingNumberSend();
void getStyles();
void disconnection();

int main()
{
	printf("Content-type:text/html\n\n");
	printf("<html lang=\"en\">");
	printf("<head><meta charset=\"UTF-8\">");
    printf("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">");
    printf("<style>");
    getStyles();
    printf("</style>");
	listDisplayNumberSend();
	printf("</body></html>");
	
	return 0;
}

void listDisplayNumberSend()
{
	FILE *file=fopen("./session.txt","r");
	char container[250];
	char date[250]; 
	char year[250];
	char month[20]; 
	char day[5];
	char time[20]; 
	char session[30]; 
	char user[30];
	char dayInt[30];
	int count=1;
	int line;
	int lineBegin;
	int lineCount=0;
	char useless[10];
	sscanf(getName(),"%[^=]=%d",useless,&line);
	lineBegin=line*10-10;
	printf("<div id=\"div0\">");
	printf("<div id=\"div1\">");
	pagingNumberSend();
	disconnection();
	printf("<center>");
	printf("<table id=\"tab\"border=\"2\">");
	printf("<tr>");
	printf("<td width=\"150px\"><font color=\"darkblue\"><center>Heure</center></font></td>");
	printf("<td width=\"150px\"><font color=\"darkblue\"><center>Jour</center></font></td>");
	printf("<td width=\"150px\"><font color=\"darkblue\"><center>Mois</center></font></td>");
	printf("<td width=\"150px\"><font color=\"darkblue\"><center>Annee</center></font></td>");
	printf("<td width=\"100px\"><center><font color=\"darkblue\">Session</font></center></td>");
	printf("<td width=\"70px\"><font color=\"darkblue\"><center>User</center></font></td>");
	printf("</tr>");
	
	while(fgets(container,250,file))
	{
		if(lineCount>=lineBegin&&count<=10)
		{
			sscanf(container,"%s %s %s %s %s",day,month,time,session,user);
			strcpy(date,translatedate(month,day,2023));
			sscanf(date,"%s %s %s %s",day,dayInt,month,year);
			if(strcmp(session,"opened")==0)
			{
				printf("<tr>");
				printf("<td><center><font color=\"yellow\">%s</font></center></td>" 
				"<td><center><font color=\"white\">%s, %s</font></center></td>" 
				"<td><center><font style=\"color:maroon;\">%s</font></center></td>"
				"<td><center><font style=\"color:maroon;\">%s</font></center></td>"
				"<td ><center><font color=\"green\">%s</font</center></td>" 
				"<td><center><font color=\"black\">%s</font></center></td></tr>",time,day,dayInt,month,year,session,user);
				count++;
			}
			else
			{
				printf("<td><center><font color=\"yellow\">%s</font></center></td>" 
				"<td><center><font color=\"white\">%s, %s</font></center></td>" 
				"<td><center><font style=\"color:maroon;\">%s</font></center></td>"
				"<td><center><font style=\"color:maroon;\">%s</font></center></td>"
				"<td ><center><font color=\"red\">%s</font</center></td>" 
				"<td><center><font color=\"black\">%s</font></center></td></tr>",time,day,dayInt,month,year,session,user);
				count++;
			}
		}
		lineCount++;
	}
	printf("</table></center>");
	printf("</div>");
	printf("</div>");
}

int getLine()
{
	FILE *file=popen("cat ./session.txt | wc -l", "r");
	char line[100];
	int lineReturn;
	fgets(line,100,file);
	sscanf(line,"%d",&lineReturn);
	return lineReturn;
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

void pagingNumberSend()
{
	int page;
	char useless[10];
	sscanf(getName(),"%[^=]=%d",useless,&page);
	int nbrPage=getNbrPage();
	int end=page+4;
	int begin=page-5;
	if(end>nbrPage)
		end=nbrPage;
	if(begin<0)
		begin=0;
	printf("<form action=\"http://localhost/cgi-bin/paging.cgi\" method=\"get\">");
	printf("<div id=\"div2\">");
	for(int i=begin;i<end;i++)
	{
	if(i+1==page)
		printf("<input style=\"height:30px;width:25px;\" name=\"nombre\" type=\"submit\" value=\"%d\"/>\n",i+1);
	else
		printf("<input style=\"height:30px;width:25px;\" name=\"nombre\" type=\"submit\" value=\"%d\"/>\n",i+1);
	}
	printf("</form>");
	printf("</div>");
	
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

char* getName()
{
	return getenv("QUERY_STRING");
}

void getStyles()
{
	char container[250];
	FILE* file=fopen("./stylesDisplay.css","r");
	while(fgets(container,250,file))
		printf("%s",container);
	fclose(file);
}
void disconnection()
{
	printf("<div style=\"position:absolute;right:10px;top:10px;\">");
	printf("<form action=\"http://localhost/cgi-bin/login.cgi\" method=\"get\">");
    printf("<button type=\"submit\" name=\"disconnection\" style=\"width:120px; height:40px;\">DÉCONNEXION</button>");
    printf("</form>");
    printf("</div>");
}
