#include <stdio.h>
#include <stdlib.h>
int main() {
	int n;
	scanf("%d", &n);
	char *word=(char *)calloc(n, sizeof(char));
	scanf("%s", word);
	
	for (int i=0; i<n; i++)
		printf("%c", word[i]);
	int k=0;
	printf("\n");	
	for (k=0; ; k++){
		if (word[k]=='\0')
			break;
	}
	if (k>n)
		word=(char*)realloc(word, k*sizeof(char));

	for(int i=n; ;i++){
		if (word[i]=='\0') break;
		printf("%c", word[i]);
	}
	printf("\n");
	free(word);

	return 0;
}
