#include <stdio.h>
#include <stdlib.h>

int main(){

	FILE *f = fopen("Info.txt", "r");

	if(f == NULL)
	
		exit(1);
/*
	char c;

	char* cont = malloc(100);

	while(!feof(f)){
	
		c = fgetc(f);

		printf("%c", c);

	}
*/
	
	char* cont = malloc(100);
	
	while(fgets(cont, 100,f)!=NULL){

		printf("%s", cont);
	
	}

	fclose(f);

	return 0;

}
