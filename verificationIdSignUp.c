#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verification(char *name,char *passwd1,char *passwd2);

int main(){
    FILE *file = fopen("./dataBase.txt","a");
    char data[1000]="";
    char name[255];
    char passwd1[255];
    char passwd2[255];
    int result=0;
    strcpy(data,getenv("QUERY_STRING"));
    sscanf(data,"Name=%[^&]&Passwd1=%[^&]&Passwd2=%[^\n]\n",name,passwd1,passwd2);
    result = verification(name,passwd1,passwd2);
    if(result!=0)
        printf("Location: http://localhost/cgi-bin/signUp.cgi?Correspondance incorrect\n\n");
    else{
        fprintf(file,"Username=%s&Password=%s\n",name,passwd1);
        printf("Location: http://localhost/cgi-bin/welcome.cgi\n\n");
    }
    fclose(file);
    return 0;
}

int verification(char *name,char *passwd1,char *passwd2){
    FILE *file = fopen("./dataBase.txt","r");
    char data[255];
    if(strlen(name)<3)
        return 1;
    if(strcmp(passwd1,passwd2)!=0)
        return 2;
    if(strlen(passwd1)<6)
        return 3;
    while(fgets(data,255,file) != NULL){
        char nameTmp[255];
        sscanf(data,"username=%[^&]",nameTmp);
        if(strcmp(name,nameTmp) == 0)
            return 4;
    }
    fclose(file);
    return 0;
}
