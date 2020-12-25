#include <stdio.h>
#include <stdlib.h>
int determinant(int **a);
int main() {
	double**matrix=(double**)malloc(sizeof(double)*2);
	for(int i=0; i<2; i++)
		matrix[i]=(double*)malloc(sizeof(double)*2);
	
	int**a=(int**)malloc(sizeof(int)*2);
	for(int i=0; i<2; i++)
		a[i]=(int*)malloc(sizeof(int)*2);

	for(int i=0; i<2; i++)
		for(int j=0; j<2; j++)
			scanf("%d", &a[i][j]);
	
	double rde;

	if(determinant(a)==0){
		printf("Singular Matrix\n");
		return 0;
	}
	else{
		printf("Invertible Matrix\n");
		rde=1/(double)determinant(a);
	}

	matrix[0][0]=rde*a[1][1];
	matrix[0][1]=rde*a[0][1]*(-1);
	matrix[1][0]=rde*a[1][0]*(-1);
	matrix[1][1]=rde*a[0][0];

	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++)
			printf("%.2lf ", matrix[i][j]);
		printf("\n");
	}

	return 0;
}

int determinant(int **a){
	int result=a[0][0]*a[1][1]-a[0][1]*a[1][0];
	return result;
}
