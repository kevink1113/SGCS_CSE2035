#include <stdio.h>
#include <stdlib.h>
int main(){
	int n, i;
	printf("Input the level of Pascal's triangle : ");
	scanf("%d", &n);
	n++;
	int **pascal=(int**)malloc(sizeof(int*)*n);
	for(i=0; i<n; i++)
		pascal[i]=(int*)malloc(sizeof(int)*n);

	for(i=0; i<n; i++){
		pascal[i][0]=1;
		pascal[i][i-1]=1;
	}

	for(i=1; i<n; i++)
		for(int j=1; j<i-1; j++)
			pascal[i][j]=pascal[i-1][j-1]+pascal[i-1][j];
	
	for(i=0; i<n; i++){
		for(int j=0; j<i; j++){
			printf("%d ", pascal[i][j]);
		}
		printf("\n");
	}

	return 0;
}
