#include <stdio.h>
#include <stdlib.h>
int main() {
	int len, cnt=1;
	char arr[1000];
	fgets(arr, sizeof(arr), stdin);
	for(int i=0; i<1000; i++){
		if (arr[i]=='\0'){
			len=i;
			break;
		}
	}
	for(int i=1; i<len-1; i++)
		if (arr[i]==' ' && arr[i-1]!=' ') cnt++;

	printf("%d\n", cnt);

	return 0;
}
