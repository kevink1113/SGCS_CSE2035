#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int number;
	char id[50];
	char pw[50];
	char name[50];
	char address[200];
} customer;


int main(){
	char in[50];
	char in2[50];
	customer *cus=(customer*)malloc(sizeof(customer)*5);

	FILE *inp=fopen("customer.txt", "r");
	
	for(int i=0; i<5; i++)
		fscanf(inp, "%d%*c%[^,]%*c%[^,]%*c%[^,]%*c%[^\n]", &cus[i].number, &cus[i].id, &cus[i].pw, &cus[i].name, &cus[i].address);

	/*
	for(int i=0; i<5; i++)	
		printf("%d--%s--%s--%s--%s\n", cus[i].number, cus[i].id, cus[i].pw, cus[i].name, cus[i].address);
	*/
	int cnt=0;
	printf("로그인 프로그램\n");
	while (cnt<3){
	printf("아이디 : ");
	scanf("%s", in);
	printf("패스워드 : ");
	scanf("%s", in2);
	//printf("=====================\n");
	

	for(int i=0; i<5; i++)
	{
		int res=1, res2=1;
		for(int j=0; in[j]!='\0'; j++){
			if (in[j] != cus[i].id[j])
				res*=0;
		}
		for(int j=0; in2[j]!='\0'; j++){
			if (in2[j] != cus[i].pw[j])
				res2*=0;
		}

		if (res!=0 && res2!=0){
			printf("=====================\n");
			printf("회원번호 : %d\n아이디 : %s\n패스워드 : %s\n이름 : %s\n주소 : %s\n", cus[i].number, cus[i].id, cus[i].pw, cus[i].name, cus[i].address);
			return 0;				
		}
	}
	printf("일치하는 회원이 없습니다.\n");

	cnt++;
	}
	fclose(inp); free(cus);

	return 0;
}
