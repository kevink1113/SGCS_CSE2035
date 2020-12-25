#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char* a = (char*)malloc(1000 * sizeof(char));
	char* b = (char*)malloc(1000 * sizeof(char));
	
	
	fgets(a, 1000, stdin);
	fgets(b, 1000, stdin);
	//scanf("%s", a); scanf("%s", b);
	int l1 = strlen(a);
	int l2 = strlen(b);
	//printf("%d %d\n", l1, l2);
	if (l1 != l2) {
		printf("Not equal\n");
		return 0;
	}
	int res = 1;

	for (int i = 0; i < l1; i++) {
		if (*(a + i) == *(b + i) || *(a + i) == *(b + i)-32 || *(a + i) == *(b + i)+32)
			res *= 1;
		else
			res *= 0;
		
	}

	if (res == 0) printf("Not equal\n");
	else printf("Equal\n");

	return 0;
	
}