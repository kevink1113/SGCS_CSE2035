#include <stdio.h>
void swap(int*, int*);
void sort(int*, int);
void all_sort(int[][100], int, int);
int binary_search(int*, int*, int, int**);
int all_binary_search(int[][100], int, int, int, int**);

int main() {
	int i, j, n, m, k, result, *findPtr;
	int a[100][100];

	scanf("%d%d%d", &n, &m, &k);

	for (i = 0; i < n; i++) 
		for (j = 0; j < m; j++) 
			scanf("%d", (*(a + i) + j));
	all_sort(a, n, m);
	result = all_binary_search(a, n, m, k, &findPtr);
	printf("%d\n%p\n", result, findPtr);

	return 0;
}

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void sort(int* a, int m) {
	int i, j;
	for (i = m - 1; i >= 0; i--)
		for (j = 1; j <= i; j++) 
			if (*(a + j - 1) > *(a + j))
				swap((a + j - 1), (a + j));
}

void all_sort(int a[][100], int n, int m) {
	int i;
	for (i = 0; i < n; i++)
		sort(a[i], m);
}

int binary_search(int* a, int* endPtr, int key, int** findPtr) {
	int *left, *middle, *right;

	left = a;
	right = endPtr;

	while (left <= right) {
		middle = left + (right - left) / 2;

		if (key > *middle)
			left = middle + 1;
		else if (key < *middle)
			right = middle - 1;
		else 
			left = right + 1;
	}
	*findPtr = middle;
	return (key == *middle);
}

int all_binary_search(int a[][100], int n, int m, int key, int **findPtr) {
	int i;
	int f = 0;

	for (i = 0; i < n; i++) {
		if (binary_search(a[i], a[i] + m - 1, key, findPtr)) {
			f = 1;
			break;
		}
	}
	return f;
}
