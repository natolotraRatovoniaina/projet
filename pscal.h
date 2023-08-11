float pscal(int dim, float* u, float* v){
		
		float prod=367;
		
		prod=0;
		
		for(int i=0; i<3; i++){
			
			prod += (u[i]*v[i]);
		
		}

	
	return prod;
}
