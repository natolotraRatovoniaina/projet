#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <string.h>
#define epsilone 1e-9
double fonction(double x);
double derive(double a);
void tangente(double a);
void secante(double a,double b);
void dichotomie(double a,double b);
void integrale(double a, double b);
void button();

int main(int argc, char **argv)
{

    double a=1.5,b=3;    
    char container[250];
    printf("Content-type:text/html\n\n");
    printf("<html><body style=\"background-color:beige;display:flex;justify-content:center;flex-direction:colomn;\">");
    printf("<div style=\"width:50vw;display:flex;flex-direction:column;justify-content:center;align-items:center;\">");
    printf("<table border=\"1\" style=\"width:200px\">");
    button();
    if(strstr(getenv("QUERY_STRING"),"dichotomie=Dichotomie"))
    {
		strcpy(container,getenv("QUERY_STRING"));
		sscanf(container,"%*[^=]=%lf&%*[^=]=%lf&%*[^\n]",&a,&b);
		dichotomie(a,b);  
    }
	else if(strstr(getenv("QUERY_STRING"),"secante=Secante"))
	{
		strcpy(container,getenv("QUERY_STRING"));
		sscanf(container,"%*[^=]=%lf&%*[^=]=%lf&%*[^\n]",&a,&b);
		secante(a,b);
	}
    else if(strstr(getenv("QUERY_STRING"),"tangente=Tangente"))
    {
		strcpy(container,getenv("QUERY_STRING"));
		sscanf(container,"%*[^=]=%lf&%*[^=]=%lf&%*[^\n]",&a,&b);
		tangente(a);
	}
	else if(strstr(getenv("QUERY_STRING"),"integrale=Integrale"))
    {
		strcpy(container,getenv("QUERY_STRING"));
		sscanf(container,"%*[^=]=%lf&%*[^=]=%lf&%*[^\n]",&a,&b);
		integrale(a,b);
	}
	else
	{
		dichotomie(a,b);
	}
	printf("</table>");
	printf("</div>");
	printf("</body></html>");
	return 0;
}

void button()
{
	printf("<form action=\"http://localhost/cgi-bin/fonction.cgi\" method=\"get\">");
	printf("<div style=\"display:flex;width:360px;justify-content:center;\">");
	printf("<input style=\"height:30px;width:120px;margin-right:1%%;color:blue;border-radius:2px;\" name=\"a\" type=\"text\"/>\n");
	printf("<input style=\"height:30px;width:120px;margin-left:1%%;color:blue;border-radius:2px;\" name=\"b\" type=\"text\"/>\n");
	printf("</div>");
	printf("<div style=\"display:flex;width:360px; margin-top:2%%;margin-bottom:2%%;\">");
	printf("<input style=\"height:40px;width:120px;\" name=\"dichotomie\" type=\"submit\" value=\"Dichotomie\"/>\n");
	printf("<input style=\"height:40px;width:120px;margin-left:1%%;\" name=\"secante\" type=\"submit\" value=\"Secante\"/>\n");
	printf("<input style=\"height:40px;width:120px;margin-left:1%%;\" name=\"tangente\" type=\"submit\" value=\"Tangente\"/>\n");
	printf("<input style=\"height:40px;width:120px;margin-left:1%%;\" name=\"integrale\" type=\"submit\" value=\"Integrale\"/>\n");
	printf("</div>");
	printf("</form>");
}

double fonction(double x)
{	
	return log(x) - 1;
}

double derive(double a)
{
	return (fonction(a+epsilone)-fonction(a))/epsilone;
}

void tangente(double a)
{ 
	while(fabs(fonction(a))>epsilone)
	{
		a=-fonction(a)/derive(a)+a;
		printf("<tr><td>%lf</td></tr>",a);
	}
	
}

void secante(double a,double b)
{
	while(fonction(b)>epsilone)
	{
		
		if(fonction(a)*fonction(b)>0)
		{
			printf("<h1 style=\"color:red\"><center>Pas de Solution</center></h1>");
			break;
		}
		
		b=(fabs(fonction(a))*b+fonction(b)*a)/(fabs(fonction(a))+fonction(b));
		printf("<tr><td>%lf</td></tr>",b);	
	}
	
}

void dichotomie(double a,double b)
{
	
    double milieu=0;
	
	while(fabs(a-b)>epsilone)
	{
	    milieu=(a+b)/2;
		if(fonction(a)*fonction(milieu)<0)
		{
			b=milieu;
			printf("<tr><td>%lf</td><tr>",milieu);
		}
	   	else if(fonction(milieu)*fonction(b)<0)
	   	{
			a=milieu;
			printf("<tr><td>%lf</tr></td>",milieu);
		}
		else
		{
			printf("<h1 style=\"color:red\"><center>Pas de Solution</center></h1>");
			break;
		} 
	}
}
void integrale(double a, double b)
{
	double surfaceRectangle=0;
	double surfaceTrapeze=0;
	double surfaceSimpson=0;
	double dis=(b - a) / 100000;
	for(double i = a; i < b; i += dis)
	{
		surfaceRectangle += fonction(i) * dis;
	}
	
	for(double i = a; i < b; i += dis)
	{
		surfaceTrapeze += ((fonction(i) + (fonction(dis + i))) / 2) * (dis);
	}
	
	printf("<tr><td>Rectangle</td><td>Trapeze</td><td>Simpson</td></tr>");
	printf("<tr><td>%lf</td><td>%lf</td><td>%lf</td></tr>",surfaceRectangle,surfaceTrapeze,surfaceSimpson);
}
