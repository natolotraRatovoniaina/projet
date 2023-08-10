#include <stdio.h>
char itoascii(int i);
//char imtoascii(char *c);
//char iMtoascii(char *M)

int main(){

	int i;
	//char c[]="abcdefghijklmnopqrstuvwxyz"
	//char M="ABCDEFGHIJKLMOPQRSTUVWXYZ"
	
	printf("Les digits decimaux:\n");
	
	for(i=0; i<=9; i++){
	
	printf("%d=%d \t",i, itoascii(i));
	
	}
	/*for(i=0; i<strlen(c); i++){
	
	printf("%c=%d",c[], imtoascii(c));
	
	}*/
	//printf("%d", iMtoascii(&M));

	return 0;

}

char itoascii(int i){

	return '0'+ i;
	
}

/*char imtoascii(char *c){

	return 'a'+ *c;
	
}*/

//char iMtoascii(char *M){

	//return 'A'+ *M;
	
//}
