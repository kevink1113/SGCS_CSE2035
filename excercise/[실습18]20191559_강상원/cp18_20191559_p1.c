#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union {
	char name [20];
	char subject[20];
	int score;
} Student; 

struct student{
	char name [20];
	char subject[20];
	int score;
};

int main() {
	struct student tmp;
	Student str1;
	Student str2;

	scanf("%s", tmp.name);
	scanf("%s", tmp.subject);
	scanf("%d", &tmp.score);

	strcpy (str1.name, tmp.name);
	strcpy(str1.subject, tmp.subject);
	str1.score=tmp.score;

	/*
		공용체 변수는 크기가 가장 큰 멤버에게만 메모리 공간을 할당하므로 
		모든 정보를 저장한 후 출력하도록 하면 str1.score에 해당하는 문자를 출력할 것이다.
	*/

	printf("Name		: %s\n", str1.name);
	printf("Subject		: %s\n", str1.subject);
	printf("Score		: %d\n", str1.score);

	strcpy(str2.name, tmp.name);
	printf("Name		: %s\n", str2.name);
	strcpy(str2.subject, tmp.subject);
	printf("Subject		: %s\n", str2.subject);
	str2.score=tmp.score;
	printf("Score		: %d\n", str2.score);

	//반면, 정보를 저장할 떄마다 출력하면 제대로 출력된다.
	   

	return 0;
}
