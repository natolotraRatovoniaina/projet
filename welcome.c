#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    printf("<form action=\"http://localhost/cgi-bin/authSearch.cgi\" method=\"get\">");
    printf("<div id=\"div0\">");
    printf("<div id=\"div1\"");
    printf("<h1 class=\"h1\">Entrez l'utilisateur à rechercher:</h1>");
    printf("<input id=\"inp\" type=\"text\" name=\"nom\">");
    printf("<div id=\"div2\">");
    printf("<button id=\"but\" type=\"submit\">RECHERCHER</button>");
    printf("</div>");
    printf("</div>");
    printf("</div>");
    printf("</form>");
    disconnection();
    
    return 0;
}

void getStyles()
{
	char container[250];
	FILE* file=fopen("./stylesWelcome.css","r");
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
