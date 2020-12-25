#include <stdio.h>
int main() {
	int n, m, x, y;
	scanf("%d%d", &n, &m);


	int** arr=(int**)calloc(n+2, sizeof(int*));
	for(int i=0; i<n+2; i++)
		*(arr+i)=(int*)calloc(n+2, sizeof(int));

	for(int i=0; i<m; i++) {
		scanf("%d %d", &x, &y);
		arr[x][y]=1;
	}

	int r, cnt=0;
	scanf("%d", &r);
	for(int i=0; i<r; i++) {
		cnt=0;
		scanf("%d %d", &x, &y);
		if(arr[x][y]==1) {
			printf("BOMB\n");
			return 0;
		}
		else {
			if(arr[x-1][y]==1) cnt++;
			if(arr[x+1][y]==1) cnt++;
			if(arr[x][y-1]==1) cnt++;
			if(arr[x][y+1]==1) cnt++;

			if(arr[x-1][y-1]==1) cnt++;
			if(arr[x-1][y+1]==1) cnt++;

			if(arr[x+1][y-1]==1) cnt++;			
			if(arr[x+1][y+1]==1) cnt++;
			printf("Number if mine = %d\n", cnt);
		}
	}
	
	return 0;
}