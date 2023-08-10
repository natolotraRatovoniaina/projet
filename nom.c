#include <stdio.h>
#include <math.h>

int main(){
	
			float a, b, c, x, x1, x2, delta;
			
			printf("resolution de ax2 + bx + c = 0\n");
			
			printf("entrez a:");
			scanf("%f" , &a );
			
			printf("\nentrez b:");
			scanf("%f" , &b );
			
			printf("\nentrez c:");
			scanf ("%f" , &c );
			delta = (b*b) - 4*a*c;
			
			if (delta == 0){
				x = - b / (2*a);
				printf("x = %f" , x);
			}
			if (delta <0) {
				printf("\npas de solution dans R");
			}
			if (delta > 0){
				x1 = (- b - sqrt (delta)) / (2*a);
				x2 = ( - b + sqrt (delta)) / (2*a);
				}
				printf("\nsolution : x1 = %f ; x2 = %f \n" , x1 , x2);
				
			return 0;
}
