#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
int getLine();
int getNbrPage();
char* getName();
char* translateMonth(char* month);
void archiveName();
void listDisplayNameSend();
void listDisplayNumberSend();
void pagingNameSend();
void pagingNumberSend();
void welcome();
void afterSearch();
void disconnection();
void login();
void getStyles();

int main()
{	
	char container[250];
	char name[20];
	char nameTest[]="Natolotra";
	char passwd[20];
	char passwdTest[]="123456";
	printf("Content-type:text/html\n\n");
	printf("<html lang=\"en\">");
    printf("<head><meta charset=\"UTF-8\">");
    printf("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">");
    printf("<style>");
    getStyles();
    printf("</style>");
    printf("</head>");
	printf("<body style=\"background-color: beige;\">");
	if(strstr(getName(),"&"))
	{
		strcpy(container,getName());
		sscanf(container,"%*[^=]=%[^&]&%*[^=]=%[^\n]",name,passwd);
		if(strcmp(name,nameTest)==0&&strcmp(passwd,passwdTest)==0)
		{	
			welcome();
			disconnection();
		}
		else
			printf("Error");
	}
	else if(strstr(getName(),"nom="))
	{		
		archiveName();
		afterSearch();
		listDisplayNameSend();
		disconnection();
	}
	else if(strstr(getName(),"nombre="))
	{
		disconnection();
		afterSearch();
		listDisplayNumberSend();
		printf("</div>");
	}
	else
	{
		login();
	}
	
	printf("</body></html>");
	
	return 0;
	
}
int getLine()
{
	FILE *file=popen("cat /usr/lib/cgi-bin/session.txt | wc -l", "r");
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
char* getName()
{
	return getenv("QUERY_STRING");
}

void archiveName()
{
	FILE *file=NULL;
	file=fopen("/var/log/auth.log","r");
	FILE *receptacle=NULL;
	receptacle=fopen("/usr/lib/cgi-bin/session.txt","w");
	char container[250];
	char month[20];
	char day[5];
	char time[20]; 
	char useless1[100]; 
	char useless2[100];
	char session[30];
	char user[30];
	char name[50];
	strcpy(name,getName());
	sscanf(name,"%*[^=]=%s",name);
	while(fgets(container,200,file))
	{	
		if(strstr(container,"for user"))
		{
			sscanf(container,"%[^ ] %[^ ] %[^ ] %[^:]: %[^ ] session %[^ ] for user %[^ ] ",month,day,time,useless1,useless2,session,user);
			sscanf(user,"%[^\n]\n",user);
			if(strcmp(name,user)==0)
			{
				fprintf(receptacle,"%s %s %s %s %s\n",day,month,time,session,user);
			}
		}
	}

	fclose(file);
	fclose(receptacle);
}
void listDisplayNameSend()
{
	FILE *file=fopen("/usr/lib/cgi-bin/session.txt","r");
	char container[250]; 
	char month[20]; 
	char day[5];
	char time[20]; 
	char session[30]; 
	char user[30];
	int count=1;
	printf("<div style=\"display:flex;flex-direction:column\">");
	pagingNameSend();
	printf("<center><table border=\"1\">");
	printf("<tr><td width=\"150px\"><font color=\"darkblue\"><center>Heure</center></font></td><td width=\"150px\"><font color=\"darkblue\"><center>Jour</center></font></td><td width=\"150px\"><font color=\"darkblue\"><center>Mois</center></font></td>");
	printf("<td width=100px><center><font color=\"darkblue\">Session</font></center></td><td width=\"70px\"><font color=\"darkblue\"><center>User</center></font></td></tr>");
	while(fgets(container,250,file))
	{
		if(count<=10)
			{
				sscanf(container,"%s %s %s %s %s",day,month,time,session,user);
				strcpy(month,translateMonth(month));
				if(strcmp(session,"opened")==0)
				{
					printf("<tr><td><center>%s</center></td> <td><center>%s</center></td> <td><center>%s</center></td> <td style=\"color:green\"><center>%s</center></td> <td><center>%s</center></td> </tr>",time,day,month,session,user);
					count++;
				}
				else
				{
					printf("<tr><td><center>%s</center></td> <td><center>%s</center></td> <td><center>%s</center></td> <td style=\"color:red\"><center>%s</center></td> <td><center>%s</center></td> </tr>",time,day,month,session,user);
					count++;
				}
			}
		else
			break;
	}
	printf("</table></center>");
	printf("</div>");
}

void listDisplayNumberSend()
{
	FILE *file=fopen("/usr/lib/cgi-bin/session.txt","r");
	char container[250]; 
	char month[20]; 
	char day[5];
	char time[20]; 
	char session[30]; 
	char user[30];
	int count=1;
	int line;
	int lineBegin;
	int lineCount=0;
	char useless[10];
	sscanf(getName(),"%[^=]=%d",useless,&line);
	lineBegin=line*10-10;
	printf("<div style=\"display:flex;flex-direction:column\">");
	pagingNumberSend();
	printf("<center><table border=\"1\">");
	printf("<tr><td width=\"150px\"><font color=\"darkblue\"><center>Heure</center></font></td><td width=\"150px\"><font color=\"darkblue\"><center>Jour</center></font></td><td width=\"150px\"><font color=\"darkblue\"><center>Mois</center></font></td>");
	printf("<td width=100px><center><font color=\"darkblue\">Session</font></center></td><td width=\"70px\"><font color=\"darkblue\"><center>User</center></font></td></tr>");
	
	while(fgets(container,250,file))
	{
		if(lineCount>=lineBegin&&count<=10)
		{
			sscanf(container,"%s %s %s %s %s",day,month,time,session,user);
			strcpy(month,translateMonth(month));
			if(strcmp(session,"opened")==0)
			{
				printf("<tr><td><center>%s</center></td> <td><center>%s</center></td> <td><center>%s</center></td> <td style=\"color:green\"><center>%s</center></td> <td><center>%s</center></td> </tr>",time,day,month,session,user);
				count++;
			}
			else
			{
				printf("<tr><td><center>%s</center></td> <td><center>%s</center></td> <td><center>%s</center></td> <td style=\"color:red\"><center>%s</center></td> <td><center>%s</center></td> </tr>",time,day,month,session,user);
				count++;
			}
		}
		lineCount++;
	}
	printf("</table></center>");
	printf("</div>");
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
	printf("<form action=\"http://localhost/cgi-bin/logPagination.cgi\" method=\"get\">");
	printf("<div style=\"display:flex;flex-direction:row;padding-bottom:1%%;\">");
	for(int i=begin;i<end;i++)
	{
	if(i+1==page)
		printf("<input style=\"height:30px;width:25px;\" name=\"nombre\" type=\"submit\" value=\"%d\"/>",i+1);
	else
		printf("<input style=\"height:30px;width:25px;\" name=\"nombre\" type=\"submit\" value=\"%d\"/>",i+1);
	}
	printf("</div>");
	printf("</form>");
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
	printf("<form action=\"http://localhost/cgi-bin/logPagination.cgi\" method=\"get\">");
	printf("<div style=\"display:flex;flex-direction:row;padding-bottom:1%%;\">");
	for(int i=begin;i<end;i++)
	{
	if(i+1==page)
		printf("<input style=\"height:30px;width:25px;\" name=\"nombre\" type=\"submit\" value=\"%d\"/>\n",i+1);
	else
		printf("<input style=\"height:30px;width:25px;\" name=\"nombre\" type=\"submit\" value=\"%d\"/>\n",i+1);
	}
	printf("</div>");
	printf("</form>");
}

char* translateMonth(char* month)
{
	char acronymMonth[11][20]={"Janv","Fev","Mars","Avril","Mai","Juin","Juil","Août","Sept","Oct","Nov"};
	if(strcmp(month,acronymMonth[0])==0)
	{
		return "Janoary";
	}
	else if(strcmp(month,acronymMonth[1])==0)
	{
		return "Febroary";
	}
	else if(strcmp(month,acronymMonth[2])==0)
	{
		return "Marsa";
	}
	else if(strcmp(month,acronymMonth[3])==0)
	{
		return "Aprily";
	}
	else if(strcmp(month,acronymMonth[4])==0)
	{
		return "May";
	}
	else if(strcmp(month,acronymMonth[5])==0)
	{
		return "Jona";
	}
	else if(strcmp(month,acronymMonth[6])==0)
	{
		return "Jolay";
	}
	else if(strcmp(month,acronymMonth[7])==0)
	{
		return "Aogositra";
	}
	else if(strcmp(month,acronymMonth[8])==0)
	{
		return "Septambra";
	}
	else if(strcmp(month,acronymMonth[9])==0)
	{
		return "Oktobra";
	}
	else if(strcmp(month,acronymMonth[10])==0)
	{
		return "Novambra";
	}
	else
	{
		return "Desambra";
	}
}
void welcome() 
{
    printf("<form action=\"http://localhost/cgi-bin/logPagination.cgi\" method=\"get\">");
    printf("<div style=\"display: flex;flex-direction: column;align-items: center;justify-content: center;padding-top: 5%%;\">");
    printf("<div style=\"width: 400px;height: 400px;display: flex;flex-direction: column;align-items: center;justify-content: center;background-color: rgb(150, 96, 13);border-radius: 15px 15px;padding-bottom: 2%%;\"");
    printf("<h1><font style=\"color:darkblue;padding-bottom:3%%;\">Entrez l'utilisateur à rechercher:</font></h1>");
    printf("<input style=\"width:250px;height:30px;margin-top:3%%;border-radius: 5px 5px;\" type=\"text\" name=\"nom\">");
    printf("<div style=\"margin-top:3%%;padding-left:2%%;\"><button style=\"width:200px;height:35px;border-radius: 5px 5px;\" type=\"submit\"><font size=\"3\">RECHERCHER</font></button></div>");
    printf("</div>");
    printf("</form>");
}
void afterSearch() 
{
    printf("<form action=\"http://localhost/cgi-bin/logPagination.cgi\" method=\"get\">");
    printf("<div style=\"display:flex;flex-direction:row;\">");
    printf("<div style=\"width: 400px;height: 400px;display: flex;flex-direction: column;align-items: center;justify-content: center;background-color: rgb(150, 96, 13);border-radius: 15px 15px;padding-bottom: 2%%;\"");
    printf("<h1><font style=\"color:darkblue;\">Entrez l'utilisateur à rechercher:</font></h1>");
    printf("<input style=\"width:250px;height:30px;margin-top:3%%;border-radius: 5px 5px;\" type=\"text\" name=\"nom\">");
    printf("<div style=\"margin-top:3%%;padding-left:2%%;\"><button style=\"width:200px;height:35px;border-radius: 5px 5px;\" type=\"submit\"><font size=\"3\">RECHERCHER</font></button></div>");
    printf("</form>");
	printf("</div>");
}
void disconnection()
{
	printf("<div style=\"position:absolute;right:10px;top:10px;\">");
	printf("<form action=\"http://localhost/cgi-bin/logPagination.cgi\" method=\"post\">");
    printf("<button type=\"submit\" name=\"disconnection\" style=\"width:120px; height:40px;\">DÉCONNEXION</button>");
    printf("</form>");
    printf("</div>");
}
void login()
{
	printf("<div id=\"divP\">");
	printf("<div id=\"div0\">");
    printf("<form action=\"http://localhost/cgi-bin/logPagination.cgi\" method=\"get\">");
    printf("<p><font style=\"color: blue;\">Nom d'utilisateur :</font></p><input id=\"na\" type=\"text\" name=\"Nom\">");
    printf("<p><font style=\"color: blue;\">Mot de passe :</font></p><input id=\"pass\" type=\"password\" name=\"passwd\">");
    printf("<div id=\"div3\"><button id=\"butt\" type=\"submit\"><font style=\"color: rgb(11, 100, 142); font-size: 18px; text-align: center;\">Se connecter</font></button></div>");
    printf("</form>");
    printf("</div>");
    printf("</div>");
}
void getStyles()
{
	char container[250];
	FILE* file=fopen("./styles.css","r");
	while(fgets(container,250,file))
		printf("%s",container);
	fclose(file);
}
