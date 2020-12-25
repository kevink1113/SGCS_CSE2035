#include <stdio.h>
#include <string.h>
void swap(char**, char**);
int main() {
	int n, i, j;
	scanf("%d", &n);
	char** input = (char**)malloc(sizeof(char*) * n);
	for (i = 0; i < n; i++)
		*(input + i) = (char*)malloc(sizeof(char) * 1000);

	for (i = 0; i < n; i++)
		scanf("%s", /* input[i] */*(input + i));

	for (i = 0; i < n; i++) {
		for (j = 0; j < n - 1; j++) {
			if (strcmp(*(input + j), *(input + j + 1)) > 0) {
				swap((input + j), (input + j + 1));
				//printf("a: %s, b: %s\n", *(input + j), *(input + j + 1));
			}
		}
	}
	printf("-Lexicographic Order-\n");
	for (i = 0; i < n; i++)
		printf("%s\n", /* input[i] */*(input + i));

	return 0;
}

void swap(char **a, char **b) {
	char* tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}


//ctrl+F10
