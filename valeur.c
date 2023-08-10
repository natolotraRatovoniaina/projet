#include <stdio.h>
void displayReturn(int x, int y);

int main(){
	
	int x=0, y=0;
	
	displayReturn(x,y);
	
	return 0;
}	

void displayReturn(int x, int y){		
	
	printf("Entrez x:");
	scanf("%d", &x);
	
	y=4*x*x+10*x+5;
	
	printf("y=%d", y);
}
