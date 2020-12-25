#include <stdio.h>
#include <stdlib.h>
char* triple_concatenate(char *str1, char *str2, char *str3);
int main(){
	int l1, l2, l3, i;
	printf("Input size of str1 : ");
	scanf("%d", &l1);
	getchar();
	char *str1=(char *)malloc(l1*sizeof(char));
	printf("Input str1 : ");
	for (i=0; i<l1; i++)
		scanf("%c", str1+i);
	
	printf("Input size of str2 : ");
	scanf("%d", &l2);
	getchar();
	char *str2=(char *)malloc(l2*sizeof(char));
	printf("Input str2 : ");
	for (i=0; i<l2; i++)
		scanf("%c", str2+i);

	printf("Input size of str3 : "); 
	scanf("%d", &l3);
	getchar();
	char *str3=(char *)malloc(l3*sizeof(char));
	printf("Input str3 : ");
	for (i=0; i<l3; i++)
		scanf("%c", str3+i);

	printf("str1\t: ");
	for(i=0; i<l1; i++)
		printf("%c", *(str1+i));
	printf("\n");

	printf("str2\t: ");
	for(i=0; i<l2; i++)
		printf("%c", *(str2+i));
	printf("\n");

	printf("str3\t: ");
	for(i=0; i<l3; i++)
		printf("%c", *(str3+i));
	printf("\n");
	
	char* result=triple_concatenate(str1, str2, str3);
	
	printf("result\t: ");
	for(i=0; i<l1+l2+l3; i++)
		printf("%c", *(result+i));
	printf("\n");

	free(str1); free(str2); free(str3);
	return 0;
}

char* triple_concatenate(char *str1, char *str2, char *str3){
	int l1=0, l2=0, l3=0, i;
	for (i=0; i<100; i++){
		if (*(str1+i)=='\0')
			break;
	}
	l1=i;
	
	for (i=0; i<100; i++){
		if (*(str2+i)=='\0')
			break;
	}
	l2=i;

	for (i=0; i<100; i++){
		if (*(str3+i)=='\0')
			break;
	}
	l3=i;

	char *result;
	result=(char*)malloc((l1+l2+l3)*sizeof(char));
	for(i=0; i<l1; i++)
		*(result+i)=*(str1+i);
	for(i=0; i<l2; i++)
		*(result+l1+i)=*(str2+i);
	for(i=0; i<l3; i++)
		*(result+l1+l2+i)=*(str3+i);
	return result;
}
