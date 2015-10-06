#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int main(){

	int i, imax=1000000;

	float x, y, z, vx, vy, vz, ax, ay, az, vh;
	float t;
	float dt=0.01;

	float zeta=1.0;
	float m=1.0;
	float kT=2.0;

	float rnd;

	FILE *out;
	out=fopen("ld_kT1.dat","w");

	x=0, y=0, z=0;
	vx=1.0, vy=1.0, vz=1.0;
	ax=1.0, ay=1.0, az=1.0;

	for(i=0;i<imax;i++){

		vh=vx+0.5*ax*dt;
		x=x+vh*dt;
		rnd=(float)rand()/RAND_MAX-0.5;
		ax=-zeta/m*vh+sqrt(24*kT*zeta/(m*m*dt))*rnd;
		vx=vh+0.5*ax*dt;

		vh=vy+0.5*ay*dt;
		y=y+vh*dt;
		rnd=(float)rand()/RAND_MAX-0.5;
		ay=-zeta/m*vh+sqrt(24*kT*zeta/(m*m*dt))*rnd;
		vy=vh+0.5*ay*dt;

		vh=vz+0.5*az*dt;
		z=z+vh*dt;
		rnd=(float)rand()/RAND_MAX-0.5;
		az=-zeta/m*vh+sqrt(24*kT*zeta/(m*m*dt))*rnd;
		vz=vh+0.5*az*dt;

		fprintf(out,"%f %f %f\n",x,y,z);

	}
}
