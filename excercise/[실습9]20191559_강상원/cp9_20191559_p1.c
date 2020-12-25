#include<stdio.h>
#include<stdlib.h>
void IsPalindrome(char * str);
int StringLen(char * str);
int main(void){
	char *string=(char*)malloc(100*sizeof(char));

	scanf("%s", string);
	IsPalindrome(string);
	free(string);
	return 0;
}

void IsPalindrome(char * str){
	int len=StringLen(str);
	int i;
	for(i=0; i<len/2; i++){
		if(*(str+i) != *(str+len-i-1)){
			printf("Not palindrome. \n");
			return;
		}
	}
	printf("Palindrome. \n");
}

int StringLen(char * str){
	int len=0;	
	while(*(str+len) != 0)	
		len++;

	return len;
}

