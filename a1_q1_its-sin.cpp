#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int main(){
	int i, N=1000000;
	
	float r, expr;

	FILE *out;
	out=fopen("a1_q1_its-sin.dat","w");
	
	for(i=0;i<N;i++){
		r=(float)rand()/RAND_MAX;
		expr=2*asin(sqrt(r));
		fprintf(out,"%f %f\n", r, expr);
		//printf("%f %f\n", r, expr);
	}	

}
