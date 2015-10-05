#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include <vector>

int main(){

	int N=1E6+1;
	int i=0, imax;

	int nwindows;

	float avg_dx, avg_dy, avg_dz;
	float avg_dx2, avg_dy2, avg_dz2;
	float readx, ready, readz;

	std::vector<double> x;
	std::vector<double> y;
	std::vector<double> z;
//	x.resize(N);
//	y.resize(N);
//	z.resize(N);

//	float x[500001],y[500001],z[500001];

	int dt;

	int pos1,pos2;

	FILE *in,*out;
	in=fopen("ld_3d.dat","r");
	out=fopen("msd.dat","w");

	while(!feof(in)){
		fscanf(in,"%f %f %f",&readx,&ready,&readz);
		if(!feof(in)){
			x.push_back(readx);
			y.push_back(ready);
			z.push_back(readz);
			i++;
		}
	}

	imax=i;
	for(dt=0;dt<imax/100;dt++){
		pos1=0;
		pos2=pos1+dt;

		avg_dx=0, avg_dy=0, avg_dz=0;
		avg_dx2=0, avg_dy2=0, avg_dz2=0;
		nwindows=0;
		
		while(pos2<imax){
			avg_dx+=x[pos2]-x[pos1];
			avg_dx2+=pow(x[pos2]-x[pos1],2.0);

			avg_dy+=y[pos2]-y[pos1];
			avg_dy2+=pow(y[pos2]-y[pos1],2.0);

			avg_dz+=z[pos2]-z[pos1];
			avg_dz2+=pow(z[pos2]-z[pos1],2.0);

			nwindows++;
			pos1++;
			pos2=pos1+dt;
		}
	avg_dx=avg_dx/(float)nwindows;
	avg_dx2=avg_dx2/(float)nwindows;

	avg_dy=avg_dy/(float)nwindows;
	avg_dy2=avg_dy2/(float)nwindows;

	avg_dz=avg_dz/(float)nwindows;
	avg_dz2=avg_dz2/(float)nwindows;

	fprintf(out,"%f %f %f\n",avg_dx2,avg_dy2,avg_dz2);
	}
}
