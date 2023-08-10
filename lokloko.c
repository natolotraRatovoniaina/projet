#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main (){
	for(int i=1;i<=109;i++){
	printf("%d=\033[%d;%dmalika\033[0m\n",i,(109-i),i);
	
	sleep(1);
	system("clear");
	//sleep(1);
	
	}
	
	
	
	
	
	
	
	return 0;
	}
