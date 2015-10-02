#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int main(){

	int N=1E5+1;

	int i=0;

	float readx;
	float *x;
	x=malloc(N*sizeof(float));

	float dt;

	float pos1,pos2;

	FILE *in,*out;
	in=fopen("ld1part_x.txt","r");
	out=fopen("msd.txt","w");

	while(!feof(in)){
		fscanf(in,"%f",readx);
		if(!feof(in)){
			x[i]=readx;
			i++;
		}
	}

	for(dt=0;dt< ;dt++){

	}
}
