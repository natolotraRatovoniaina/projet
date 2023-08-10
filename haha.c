#include <stdio.h>
#include <math.h>

int main(){
			int a=0,b=0;
			int x;
			
			printf( " resolution de ax + b = 0\n");
			
			printf("entrez a:");
			scanf("%d" , &a);
			
			printf("entrez b:");
			scanf("%d" , &b);
			
			x = -b/a;
			
			printf("x = %d\n" , x );
			
			return 0;
}
