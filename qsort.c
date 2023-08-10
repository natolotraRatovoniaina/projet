#include <stdio.h>
#include <stdlib.h>

int cmp(const void* val1, const void* val2){

	return (*(char*)val2 <	 *(char*)val1) ? -1 : +1; // triez dans l'ordre decroissante
}

int main(){
	
	char tab[28]={"abcdefghijklmnopqrstuvwxyz"};
	
	qsort(tab, 28, sizeof(char), cmp);
	
	for(int i=0; i<28; i++){
	
		printf("%c", tab[i]);
		
	}
	printf("%d", 't');
	
	return 0;
	
}

