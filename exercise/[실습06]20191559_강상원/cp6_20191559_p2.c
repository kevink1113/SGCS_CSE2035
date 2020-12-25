#include <stdio.h>
#include <stdlib.h>
int main() {
	int n, i, j;
	scanf("%d", &n);
	int *sec=(int *)malloc(1000*sizeof(int));
	
	for (i=0; n>0; i++){
		*(sec+i)=n%2;
		n /= 2;
	}

	for (j=i-1; j>=0; j--)
		printf("%d", *(sec+j));
	printf("\n");
	free(sec);

	return 0;
}
