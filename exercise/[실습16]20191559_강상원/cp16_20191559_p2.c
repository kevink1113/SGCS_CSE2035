#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int num;
	char name[20];
	int level;
	char type1[30];
	char type2[30];

	char sk1[20];
	char sk2[20];
	char sk3[20];
	char sk4[20];
} dex;

typedef struct {
	int inx;
	char name[10];
	char region[10];
	dex poke[6];
} user;

int main() {
	int j, cnt = 0;
	user* usr = malloc(sizeof(user) * 1000);
	dex* dx = malloc(sizeof(dex) * 1000);
	char ss[10];
	char ss2[10];
	
	FILE *inp = fopen("user.txt", "r");
	
	//fscanf("%[^\t]%[^\t]%d%[^\t]/**/%[^\t]%*c%[^\t]%*c%[^\t]%*c%[^\n]", &usr[i].name, &usr[i].region, &usr[i].poke[j].num, &usr[i].poke[j].name, &usr[i].poke[j].level, &usr[i].poke[j].type1, &usr[i].poke[j].sk1, &usr[i].poke[j].sk2, &usr[i].poke[j].sk3, &usr[i].poke[j].sk4);
	//i++;
	int rem=0, len;
	
	for(int q=0; q<16; q++) {
		fscanf(inp, "%s\t%s\t", ss, ss2);
		
		int res = 1;
		//printf("NAME: %s  REG: %s\n", ss, ss2);
		
		for (int l = /**/0; l < cnt; l++) {
			if (!strcmp(usr[l].name, ss)) {//¿¿¿ 1
				res *= 0;//¿¿¿ ¿¿¿¿ 0¿¿ ¿¿.
				rem = l; //¿¿ ¿¿ ¿¿ ¿¿
			}
		}
		if (res == 1) {
			cnt++;//¿¿¿ ¿¿¿¿ ¿¿¿ ¿¿¿¿ ¿ 1 ¿¿.
			strcpy(usr[cnt].name, ss);
			strcpy(usr[cnt].region, ss2);
			j = 0;//¿ ¿¿¿¿ ¿¿¿ ¿¿¿
			usr[cnt].inx = 1;
			
			len=0;
			fscanf(inp, "%d\t%s%d\t%s\t%[^,]%*c%[^,]%*c%[^,]%*c%[^\n]", &usr[cnt].poke[j].num, &usr[cnt].poke[j].name, &usr[cnt].poke[j].level, &usr[cnt].poke[j].type1, &usr[cnt].poke[j].sk1, &usr[cnt].poke[j].sk2, &usr[cnt].poke[j].sk3, &usr[cnt].poke[j].sk4);
			for(int k=0; k<30; k++){
				len++;
				if (usr[cnt].poke[j].type1[k]==',')
					break;
			}

			usr[cnt].poke[j].type1[len-1]='\0';
			if (len>0)
				strcpy(&usr[cnt].poke[j].type2[0], &usr[cnt].poke[j].type1[len]);
			//

		}
		else if (res==0) {//¿¿¿ ¿¿:
			usr[rem].inx++;
			j=usr[rem].inx;
			//¿¿ ¿¿¿ inx¿¿ 1¿ ¿¿¿¿¿ ¿¿
			len=0;
			fscanf(inp, "%d\t%s%d\t%s\t%[^,]%*c%[^,]%*c%[^,]%*c%[^\n]", &usr[rem].poke[j].num, &usr[rem].poke[j].name, &usr[rem].poke[j].level, &usr[rem].poke[j].type1, &usr[rem].poke[j].sk1, &usr[rem].poke[j].sk2, &usr[rem].poke[j].sk3, &usr[rem].poke[j].sk4);

			for(int k=0; k<30; k++){
				len++;
				if (usr[rem].poke[j].type1[k]==',')
					break;
			}
			usr[rem].poke[j].type1[len-1]='\0';
			if (len>0)
				strcpy(&usr[rem].poke[j].type2[0], &usr[rem].poke[j].type1[len]);
			//


			//fscanf("%d...", &usr[rem].poke[j].num,
		}

	}

	printf("Number of Users = %d\n\n", cnt-1);

	for (int i = /**/1; i < cnt; i++) {
		printf("[Name]  %s(%s)\n", usr[i].name, usr[i].region);
		printf(" [Pokemon]\n");
		for (int j = 0; j < usr[i].inx; j++){
			if (usr[i].poke[j].level!=0)
			{
				printf("  [Name]%s(%d)\n", usr[i].poke[j].name, usr[i].poke[j].num);
				//printf("  %dTH POKEMON\n", j+1);
				printf("  [Level]%d\n", usr[i].poke[j].level);
				if (usr[i].poke[j].type2[0]=='\0')
					printf("  [Type]%s\n", usr[i].poke[j].type1);
				else{
					printf("  [Type1]%s\n", usr[i].poke[j].type1);
					printf("  [Type2]%s\n", usr[i].poke[j].type2);
				}
				printf("  [Skill1]%s\n", usr[i].poke[j].sk1);
				printf("  [Skill2]%s\n", usr[i].poke[j].sk2);
				printf("  [Skill3]%s\n", usr[i].poke[j].sk3);
				printf("  [Skill4]%s\n", usr[i].poke[j].sk4);
				printf("\n");
			}
		}
	}
	//cnt++;
	//if (res != 1)
		//i++;

	return 0;
}
