#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int main(){

	int i, imax=100000;

	float x, v, a, vh;
	float t;
	float dt=0.01;

	float zeta=1.0;
	float m=1.0;
	float kT=1.0;

	float rnd;
	float grnd;

	FILE *out;
	out=fopen("ld1part_x.txt","w");

	x=0;
	v=1.0;
	a=1.0;

	for(i=0;i<imax;i++){

		vh=v+0.5*a*dt;
		
		x=x+vh*dt;

		rnd=(float)rand()/RAND_MAX-0.5;
		

		a=-zeta/m*vh+sqrt(24*kT*zeta/(m*m*dt))*rnd;

		v=vh+0.5*a*dt;

		fprintf(out,"%f\n",x);

	}
}
