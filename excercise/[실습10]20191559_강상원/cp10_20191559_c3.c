#include <stdio.h>
#include <stdlib.h>
int main(){
	int len;
	char arr[1000];
	printf("Input  string : ");
	fgets(arr, sizeof(arr), stdin);
	for(int i=0; i<1000; i++){
		if (arr[i]=='\0'){
			len=i;
			break;
		}
	}
	printf("\n-Result-\n\t");
	for(int i=0; i<len; i++){
		printf("%c", arr[i]);
		if (arr[i]==' ')
			printf("\n\t");
	}
	
	return 0;
}
