#include <stdio.h>
#include <stdlib.h>
int main() {
	int n;
	scanf("%d", &n);
	int** mb=(int**)malloc(sizeof(int*)*n);
	for(int i=0; i<n; i++)
		mb[i]=(int*)malloc(sizeof(int)*n);
	
	int y=0, x=n/2;

	int cnt=1;
	while(1){
		mb[y][x]=cnt;
		if (cnt%n==0) y++;
		else{
			if(y==0) y=n-1;
			else y--;

			if(x==n-1) x=0;
			else x++;
		}
		cnt++;
		if(cnt==n*n+1) break;		
	}

	for (int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("%2d ", mb[i][j]);
		}
		printf("\n");
	}
	return 0;
}
