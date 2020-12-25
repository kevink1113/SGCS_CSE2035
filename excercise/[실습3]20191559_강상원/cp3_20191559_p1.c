#include <stdio.h>
void swap(int*, int*);
void sort(int*, int);
void print_array(int*, int);
int main() {
	int n, a[1000];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	sort(a, n);
	print_array(a, n);

	return 0;
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sort(int* a, int n) {
	for (int i = n - 1; i >= 0; i--) 
		for (int j = 0; j < i; j++) {
			if (*(a + j) > *(a + (j + 1)))
				swap(a + j, a + (j + 1));
		
		}
}

void print_array(int* a, int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", *(a + i));
	printf("\n");
}
