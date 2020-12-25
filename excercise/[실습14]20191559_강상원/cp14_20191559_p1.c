#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
	float comps;
	int vec_size;
} vector;

typedef float Distance;
typedef float Scalar;
typedef float Size;

Distance DistVector(vector *v1, vector *v2);
Scalar innerProduct(vector *v1, vector *v2);
Size vectorSize(vector *v);

int main(){
	int v1size, v2size;
	vector *v1, *v2;
	
	scanf("%d", &v1size);
	v1=(vector*)malloc(sizeof(vector)*v1size);
	for(int i=0; i<v1size; i++)
		scanf("%f", &v1[i].comps);
	v1[0].vec_size=v1size;
	
	scanf("%d", &v2size);
	v2=(vector*)malloc(sizeof(vector)*v2size);
	for(int i=0; i<v2size; i++)
		scanf("%f", &v2[i].comps);
	v2[0].vec_size=v2size;

	
	printf("%f\n", vectorSize(v1));
	printf("%f\n", vectorSize(v2));

	
	if (v1size==v2size){
		printf("%f\n", DistVector(v1, v2));
		printf("%f\n", innerProduct(v1, v2));
	}
	else return 0;
	
	free(v1); free(v2);

	return 0;
}

Distance DistVector(vector *v1, vector *v2){
	float res2=0;
	for(int i=0; i<v1[0].vec_size; i++)
		res2 += ((v1[i].comps-v2[i].comps)*(v1[i].comps-v2[i].comps));
	return sqrt(res2);
}

Scalar innerProduct(vector *v1, vector *v2){
	float res=0;
	for (int i=0; i<v1[0].vec_size; i++)
		res += v1[i].comps*v2[i].comps;
	return res;
}

Size vectorSize(vector *v){
	float res2=0;
	for(int i=0; i<v[0].vec_size; i++)
		res2 += ((v[i].comps)*(v[i].comps));
	return sqrt(res2);
}

