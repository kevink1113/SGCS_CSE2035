#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	double x;
	double y;
	double z;
	double r;
} SPHERE;

double Distance (SPHERE, SPHERE);
double CrossSectionArea(SPHERE, SPHERE);
double SurfaceArea(SPHERE, SPHERE);
double Volume(SPHERE, SPHERE);

int main(){
	SPHERE sp1;
	SPHERE sp2;
	printf("Type First Sphere Coordinate : ");
	scanf("%lf%lf%lf", &sp1.x, &sp1.y, &sp1.z);
	printf("Type First Sphere Radius : ");
	scanf("%lf", &sp1.r);
	
	printf("Type Second Sphere Coordinate : ");
	scanf("%lf%lf%lf", &sp2.x, &sp2.y, &sp2.z);
	printf("Type Second Sphere Radius : ");
	scanf("%lf", &sp2.r);

	double dis=Distance (sp1, sp2);
	
	if (dis>sp1.r+sp2.r){
		double csa=CrossSectionArea(sp1, sp2);
		printf("Sum of Cross Section Area : %.2lf\n", csa);
	}
	else if (dis==sp1.r+sp2.r){
		double area=SurfaceArea(sp1, sp2);
		printf("Sum of Surface Area : %.2lf\n", area);
	}
	else{
		double vol=Volume(sp1, sp2);
		printf("Sum of Volume : %.2lf\n", vol);
	}

	return 0;
}
double Distance (SPHERE a, SPHERE b){
	double res2=pow(a.x-b.x, 2)+pow(a.y-b.y, 2)+pow(a.z-b.z, 2);
	double res=sqrt(res2);
	return res;
}
double CrossSectionArea(SPHERE a, SPHERE b){
	return 3.14*(pow(a.r, 2)+pow(b.r, 2));
}
double SurfaceArea(SPHERE a, SPHERE b){
	return 4*3.14*(pow(a.r, 2)+pow(b.r, 2));
}
double Volume(SPHERE a, SPHERE b){
	return 4*3.14*(pow(a.r, 3)+pow(b.r, 3))/3;
}

