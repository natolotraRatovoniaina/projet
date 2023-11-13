#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getStyles();

int main()
{
	printf("Content-type:text/html\n\n");
	printf("<html lang=\"en\">");
    printf("<head><meta charset=\"UTF-8\">");
    printf("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">");
    printf("<style>");
    getStyles();
    printf("</style>");
    printf("</head>");
	printf("<div id=\"divP\">");
	printf("<div id=\"div0\">");
    printf("<form action=\"http://localhost/cgi-bin/verificationId.cgi\" method=\"get\">");
    printf("<p><font style=\"color: blue;\">Nom d'utilisateur :</font></p><input id=\"na\" type=\"text\" name=\"Name\">");
    printf("<p><font style=\"color: blue;\">Mot de passe :</font></p><input id=\"pass\" type=\"password\" name=\"Password\">");
    printf("<div id=\"div3\"><div style=\"margin-right:1%%;\"><button id=\"butt1\" type=\"submit\"><font style=\"color: rgb(11, 100, 142); font-size: 18px; text-align: center;\">Se connecter</font></button></div><div style=\"margin-left:1%%;margin-right:25%%\"><button type=\"submit\" name=\"Inscription\" value=\"Inscription\" id=\"butt2\"><font style=\"color: rgb(11, 100, 142); font-size: 18px; text-align: center;\">S'inscrire</font></button></div></div>");
    printf("</form>");
    printf("</div>");
    printf("</div>");
    
    return 0;
}

void getStyles()
{
	char container[250];
	FILE* file=fopen("./styles.css","r");
	while(fgets(container,250,file))
		printf("%s",container);
	fclose(file);
}
