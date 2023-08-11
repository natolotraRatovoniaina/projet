void display(int dim, float* u, float* v, float prod){
		
		printf("v= \n");
		
		for(int i=0; i<dim; i++){
		
			printf("v[%d] = %f\n", i, v[i]);
		
		}

		printf("u= \n");
		
		for(int i=0; i<dim; i++){
		
			printf("u[%d] = %f\n", i, *(u+i));
		
		}
}
