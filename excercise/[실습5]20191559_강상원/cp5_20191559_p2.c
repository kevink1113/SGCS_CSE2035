#include <stdio.h>
#include <stdlib.h>
int *calculate_next(int *pascal_tr, int current_level);
int main() {
	int n;
	printf("Input the level of Pascal's triangle : ");
	scanf("%d", &n);

	int *pascal_tr=(int *)malloc(1000*sizeof(int));
	(*pascal_tr)=1; *(pascal_tr+1)=1;
	
	if(n==1) printf("1\n");
	else printf("1\n1 1\n");
	
	for(int i=2; i<n; i++){
		calculate_next(pascal_tr, i);
		for (int j=0; j<i+1; j++)
			printf("%d ", *(pascal_tr+j));
		printf("\n");
	}

	free(pascal_tr);
	return 0;
}

int *calculate_next(int *pascal_tr, int current_level){
	int *tmp=(int *)malloc(1000*sizeof(int));
	
	for(int i=0; i<current_level; i++)
		*(tmp+i)=*(pascal_tr+i);

	for (int i=0; i<current_level-1; i++)
		*(pascal_tr+i+1)=*(tmp+i)+*(tmp+i+1);

	(*pascal_tr)=1; *(pascal_tr+current_level)=1;
	
	free(tmp);
	return pascal_tr;
}
