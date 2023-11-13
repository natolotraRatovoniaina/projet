#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *file = fopen("./dataBase.txt","r");
    char dataFic[255];
    char data[1000]="";
    char name[255];
    char passwd[255];
    int imp = 1;
    strcpy(data,getenv("QUERY_STRING"));
    if(strstr(data,"Inscription=Inscription"))
    {
		printf("Location: http://localhost/cgi-bin/signUp.cgi\n\n");
		return 0;
	}
	else{
		
		sscanf(data,"Name=%[^&]&Password=%[^\n]",name,passwd);

		while(fgets(dataFic,255,file)){
			char nameTmp[255],passwdTmp[255];
			sscanf(dataFic,"Username=%[^&]&Password=%[^\n]",nameTmp,passwdTmp);
			if(strcmp(name,nameTmp) == 0 && strcmp(passwd,passwdTmp) == 0){
				printf("Set-Cookie: %s; expires: 0; httpOnly\n",name);
				printf("Location: http://localhost/cgi-bin/welcome.cgi\n\n");
				imp=0;
				return 0;
			}
		}
		if(imp)
			printf("Location: http://localhost/cgi-bin/login.cgi?incorrect identification\n\n");
    }
    fclose(file);
    return 0;
}

