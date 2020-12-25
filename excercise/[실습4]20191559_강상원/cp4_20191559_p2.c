#include <stdio.h>
void swap(int*, int*);
void sort(int*, int);
void prt_arr(int*, int);
void all_sort(int[][100], int, int);
void prt_all_arr(int[][100], int, int);

int main() {
	int i, j, n, m;
	int a[100][100];
	scanf("%d%d", &n, &m);

	for (i = 0; i < n; i++) 
		for (j = 0; j < m; j++)
			scanf("%d", (*(a + i) + j));
	all_sort(a, n, m);
	prt_all_arr(a, n, m);

	return 0;
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sort(int* a, int m) {
	int i, j;

	for (i = m - 1; i >= 0; i--)
		for (j = 1; j <= i; j++) 
			if (*(a + j - 1) > *(a + j))
				swap((a + j - 1), (a + j));
}

void prt_arr(int* a, int m) {
	int i;
	for (i = 0; i < m; i++)
		printf("%d ", *(a + i));
}

void all_sort(int a[][100], int n, int m) {
	int i;
	for (i = 0; i < n; i++)
		sort(a[i], m);
}

void prt_all_arr(int a[][100], int n, int m) {
	int i;
	for (i = 0; i < n; i++) {
		prt_arr(a[i], m);
		printf("\n");
	}
}
