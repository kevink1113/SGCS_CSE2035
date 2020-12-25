#include <stdio.h>
#include <stdlib.h>
void mergesort(int *a, int low, int high);
void merg(int *a, int low, int mid, int high);
int *merge(int *ary1, int size1, int *ary2, int size2, int *ary3, int size3){
	int i;
	int *a = (int*)calloc(12, sizeof(int));
	for (i = 0; i<size1; i++)
		a[i] = ary1[i];
	for (i = 3; i<3+size2; i++)
		a[i] = ary2[i-3];
	for (i = 7; i<7+size3; i++)
		a[i] = ary3[i-7];

	mergesort(a, 0, 11);
	printf("result Array	: ");
	for (i = 0; i < 12; i++)
		printf("%d ", a[i]);
	printf("\n");

	free(a);
}


int main() 
{
	int *arr1 = (int*)calloc(3, sizeof(int));
	int *arr2 = (int*)calloc(4, sizeof(int));
	int *arr3 = (int*)calloc(5, sizeof(int));
	printf("Input 12 integer : ");
	int i;
	for (i = 0; i<3; i++) 
		scanf("%d", &arr1[i]);
	for (i = 0; i<4; i++)
		scanf("%d", &arr2[i]);
	for (i = 0; i<5; i++)
		scanf("%d", &arr3[i]);

	printf("Array 1		: ");
	for (i = 0; i<3; i++)
		printf("%d ", arr1[i]);
	printf("\n");

	printf("Array 2		: ");
	for (i = 0; i<4; i++)
		printf("%d ", arr2[i]);
	printf("\n");

	printf("Array 3		: ");
	for (i = 0; i<5; i++) 
		printf("%d ", arr3[i]);
	printf("\n");

	merge(arr1, 3, arr2, 4, arr3, 5);
	free(arr1); free(arr2); free(arr3);

	return 0;
}

void mergesort(int *a, int low, int high)
{
	if (low<high)
	{
		int m = (low + high) / 2;
		mergesort(a, low, m);
		mergesort(a, m + 1, high);
		merg(a, low, m, high);
	}
	else
		return;
}

void merg(int *a, int low, int mid, int high)
{
	int *b = (int*)calloc(20, sizeof(int));
	int i = low, j = mid + 1, k = 0;
	while (i <= mid && j <= high)
	{
		if (a[i] <= a[j])
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
	}
	while (i <= mid)
		b[k++] = a[i++];
	while (j <= high)
		b[k++] = a[j++];
	k--;
	while (k >= 0)
	{
		a[low + k] = b[k];
		k--;
	}
	free(b);
}
