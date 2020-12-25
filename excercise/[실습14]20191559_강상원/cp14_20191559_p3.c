#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	int num;
	char name[20];
	char type1[30];
	char type2[30];
} dex;

int main(){
	int opt, len;
	dex *dic=(dex*)malloc(sizeof(dex)*151);
	
	FILE *in=fopen("pokedex.txt", "r");

	for (int i=0; i<151; i++){
		len=0;
		fscanf(in, "%d%s%s", &dic[i].num, &dic[i].name, &dic[i].type1);
		for(int j=0; j<30; j++){
			len++;
			if (dic[i].type1[j]==',')
				break;
		}
		dic[i].type1[len-1]='\0';
		if (len>0)
			strcpy(&dic[i].type2[0], &dic[i].type1[len]);

		//
	}
	while(1){
		printf("1. National Number\n");
		printf("2. Name\n");
		printf("3. Type\n");
		printf("Input = ");
		scanf("%d", &opt);
		
		if (opt==1){
			int num;
			printf("Search by National Number = ");
			scanf("%d", &num);
			printf("\nResult--------------------\n\n");	
			printf("National Number : %d\n", num);
			printf("Name : %s\n", dic[num-1].name);
			if (dic[num-1].type2[0]=='\0')
				printf("Type : %s\n", dic[num-1].type1);
			else{ 
				printf("Type1 : %s\n", dic[num-1].type1);
				printf("Type2 : %s\n", dic[num-1].type2);
			}
			printf("\n---------------------------\n\n");
		}
		else if (opt==2){
			char in[20];
			int res;
			printf("Search by Name : ");
			scanf("%s", in);
			printf("\nResult--------------------\n\n");
			for(int i=0; i<151; i++)
			{
				res=1;
				for(int j=0; in[j]!='\0'; j++){
					if (in[j] != dic[i].name[j])
						res*=0;
				}
				if (res!=0){
					printf("National Number : %d\n", i+1);
					printf("Name : %s\n", dic[i].name);
					if (dic[i].type2[0]=='\0')
						printf("Type : %s\n\n\n", dic[i].type1);
					else{
						printf("Type1 : %s\n", dic[i].type1);
						printf("Type2 : %s\n\n\n", dic[i].type2);
					}
				}
			}
			printf("--------------------------\n\n");
		}
		else if (opt==3){
			char in[30];
			printf("Search by Type : ");
			scanf("%s", in);
			printf("\nResult--------------------\n\n");
			//
			for(int i=0; i<151; i++)
			{
				int res1, res2;
				res1=1; res2=1;
				for(int j=0; in[j]!='\0'; j++){
					if (in[j] != dic[i].type1[j])
						res1*=0;
				}
				for(int j=0; in[j]!='\0'; j++){
					if (in[j] != dic[i].type2[j])
						res2*=0;
				}
				if (res1!=0 || res2!=0){
					printf("National Number : %d\n", i+1);
					printf("Name : %s\n", dic[i].name);
					if (dic[i].type2[0]=='\0')
						printf("Type : %s\n\n\n", dic[i].type1);
					else{
						printf("Type1 : %s\n", dic[i].type1);
						printf("Type2 : %s\n\n\n", dic[i].type2);
					}
				}
			}
			printf("--------------------------\n\n");
		}
		else if (opt==0) 
			return 0;
	}
	free(dic);
	fclose(in);

	return 0;
}
