#include <stdio.h>
#include <stdlib.h>
int main() {
	int n; char *charac = (char*)malloc(100 * sizeof(char));
	while (scanf("%[^0-9^\n]", charac)) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			printf("%s", charac);
	}
	printf("\n");
	free(charac);
}
