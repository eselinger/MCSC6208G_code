// Using uniform distribution from -0.5 to 0.5, mean=0, standard deviation=1

#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int main(){
	int i, j, N=10, N_iter=1E05;
	
	float r;
	float avg;
	
	FILE *out;
	out=fopen("a1_q2_clt-avg.dat","w");
	
	for(i=0;i<N_iter;i++){
		avg=0;
		for(j=0;j<N;j++){
			r=(((float)rand()/RAND_MAX)-0.5);
			avg+=r;
			
			//printf("%f %f\n", r, avg);
		}
		avg=avg*sqrt(12/(float)N);
		fprintf(out,"%f\n", avg);
	}
}
