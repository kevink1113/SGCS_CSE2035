//
//  proj_20191559.c
//  C Programming Project
//
//  Created by 강상원 on 2019/12/09.
//  Copyright © 2019 강상원. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
	int lv_HP;  //현재 레벨에서의 체력
	int cur_HP; //현재 상태(배틀, 도망침, 포획 등)에서의 체력
	int HP;     //체력
	int Attack; //공격
	int Block;  //방어
	int Contact;//특수공격
	int Defense;//특수방어
	int Speed;  //스피드
	int iv;     //랜덤 값 (0~31)
} Stat;

typedef struct {
	int lv;         //레벨
	int dex_num;    //도감 번호
	char name[20];  //포켓몬 이름
	char type1[30]; //타입1
	char type2[30]; //타입2
	int dex_state;  //0 -> 도감에 등록되지 않음, 1 -> 발견함!, 2 -> 잡았다!
	int exp;        //경험치
	Stat stat;      //스텟
	struct POKE *link;
} POKE;

typedef struct {
	char user_name[10]; //사용자 이름
	POKE *poke;         //사용자가 지닌 포켓몬 (최대 6마리)
	int num_poke;       //사용자가 지닌 포켓몬의 수
} User;

POKE **head, **head2;        //모든 포켓몬의 진화 과정을 저장.
POKE *dic;
FILE* in2;
POKE *dic;
int pokenum = 0;
int boxnum = 0;
POKE *box;//포켓몬 박스.
User BOX;


void Battle(User *user);
void Pokedex();
void user_Pokemon(POKE *poke, User *user);//+++++++++++++
void Pokecen(User *user);
void Report(User *user);
int Fight(POKE* adversary, User *user, POKE *cur);
void Catch(POKE *adversary, User *user, POKE *cur);
int Run();
void Box(User *user);

void Insert(POKE** head);
int Find(POKE** head, int dex_num/*POKE* adversary*/);
void Evolution(POKE *cur, int n);

int main(int argc, const char * argv[]) {

	int opt, len;
	int trash;
	dic = (POKE*)malloc(sizeof(POKE) * 151);
	FILE *in = fopen("sogang_poke.txt", "r");
	in2 = fopen("sogang_poke.txt", "r");



	POKE **head = (POKE**)malloc(sizeof(POKE*) * 100);
	for (int i = 0; i < 100; i++) {
		head[i] = NULL;
	}

	for (int i = 0; i<3; i++)
		Insert(&head[0]);
	for (int i = 0; i<3; i++)
		Insert(&head[1]);
	for (int i = 0; i<3; i++)
		Insert(&head[2]);
	for (int i = 0; i<3; i++)
		Insert(&head[3]);
	for (int i = 0; i<3; i++)
		Insert(&head[4]);
	for (int i = 0; i<3; i++)
		Insert(&head[5]);

	for (int i = 0; i<2; i++)
		Insert(&head[6]);
	for (int i = 0; i<2; i++)
		Insert(&head[7]);
	for (int i = 0; i<2; i++)
		Insert(&head[8]);
	for (int i = 0; i<2; i++)
		Insert(&head[9]);
	for (int i = 0; i<2; i++)
		Insert(&head[10]);

	for (int i = 0; i<3; i++)
		Insert(&head[11]);
	for (int i = 0; i<3; i++)
		Insert(&head[12]);

	for (int i = 0; i<2; i++)
		Insert(&head[13]);
	for (int i = 0; i<2; i++)
		Insert(&head[14]);
	for (int i = 0; i<2; i++)
		Insert(&head[15]);
	for (int i = 0; i<2; i++)
		Insert(&head[16]);

	for (int i = 0; i<3; i++)
		Insert(&head[17]);

	for (int i = 0; i<2; i++)
		Insert(&head[18]);
	for (int i = 0; i<2; i++)
		Insert(&head[19]);
	for (int i = 0; i<2; i++)
		Insert(&head[20]);
	for (int i = 0; i<2; i++)
		Insert(&head[21]);
	for (int i = 0; i<2; i++)
		Insert(&head[22]);
	for (int i = 0; i<2; i++)
		Insert(&head[23]);
	for (int i = 0; i<2; i++)
		Insert(&head[24]);

	for (int i = 0; i<3; i++)
		Insert(&head[25]);
	for (int i = 0; i<3; i++)
		Insert(&head[26]);
	for (int i = 0; i<3; i++)
		Insert(&head[27]);
	for (int i = 0; i<3; i++)
		Insert(&head[28]);

	for (int i = 0; i<2; i++)
		Insert(&head[29]);

	for (int i = 0; i<3; i++)
		Insert(&head[30]);

	for (int i = 0; i<2; i++)
		Insert(&head[31]);
	for (int i = 0; i<2; i++)
		Insert(&head[32]);
	for (int i = 0; i<2; i++)
		Insert(&head[33]);

	Insert(&head[34]);

	for (int i = 0; i<2; i++)
		Insert(&head[35]);
	for (int i = 0; i<2; i++)
		Insert(&head[36]);
	for (int i = 0; i<2; i++)
		Insert(&head[37]);
	for (int i = 0; i<2; i++)
		Insert(&head[38]);

	for (int i = 0; i<3; i++)
		Insert(&head[39]);

	Insert(&head[40]);

	for (int i = 0; i<2; i++)
		Insert(&head[41]);
	for (int i = 0; i<2; i++)
		Insert(&head[42]);
	for (int i = 0; i<2; i++)
		Insert(&head[43]);
	for (int i = 0; i<2; i++)
		Insert(&head[44]);
	for (int i = 0; i<2; i++)
		Insert(&head[45]);
	for (int i = 0; i<2; i++)
		Insert(&head[46]);

	Insert(&head[47]);//108

					  ////
	for (int i = 0; i<2; i++)
		Insert(&head[48]);
	for (int i = 0; i<2; i++)
		Insert(&head[49]);

	Insert(&head[50]);
	Insert(&head[51]);
	Insert(&head[52]);

	for (int i = 0; i<2; i++)
		Insert(&head[53]);
	for (int i = 0; i<2; i++)
		Insert(&head[54]);
	for (int i = 0; i<2; i++)
		Insert(&head[55]);

	Insert(&head[56]);
	Insert(&head[57]);
	Insert(&head[58]);
	Insert(&head[59]);
	Insert(&head[60]);
	Insert(&head[61]);
	Insert(&head[62]);

	for (int i = 0; i<2; i++)
		Insert(&head[63]);

	Insert(&head[64]);
	Insert(&head[65]);

	for (int i = 0; i<4; i++)
		Insert(&head[66]);

	Insert(&head[67]);

	for (int i = 0; i<2; i++)
		Insert(&head[68]);
	for (int i = 0; i<2; i++)
		Insert(&head[69]);

	Insert(&head[70]);
	Insert(&head[71]);
	Insert(&head[72]);
	Insert(&head[73]);
	Insert(&head[74]);

	for (int i = 0; i<3; i++)
		Insert(&head[75]);

	Insert(&head[76]);
	Insert(&head[77]);


	for (int i = 0; i<151; i++) {
		len = 0;
		fscanf(in, "%d%s%s%d%d%d%d%d%d\n", &dic[i].dex_num, &dic[i].name, &dic[i].type1, &dic[i].stat.HP, &dic[i].stat.Attack, &dic[i].stat.Block, &dic[i].stat.Contact, &dic[i].stat.Defense, &dic[i].stat.Speed);

		for (int j = 0; j<30; j++) {
			len++;
			if (dic[i].type1[j] == ',')
				break;
		}
		dic[i].type1[len - 1] = '\0';
		dic[i].type2[0] = '\0';
		if (len>0)
			strcpy(&dic[i].type2[0], &dic[i].type1[len]);
	}
	for (int i = 0; i<151; i++)
		dic[i].dex_state = 0;


	head2 = head;


	int startopt = 1;
	User user;
	//++++++++++++++++++++++++++++++++++++++++++++++
	BOX.poke = (POKE*)malloc(sizeof(POKE) * 1000);

	printf("+----------Pokemon R&AS----------+\n");
	printf("+  메뉴를 선택해주세요.          +\n");
	printf("+  1. 새로 시작한다.             +\n");
	printf("+  2. 종료.                      +\n\n");
	printf("+  >> ");
	scanf("%d", &startopt);

	if (startopt == 1)
	{
		printf("\n+---------------New Game---------------+\n");
		printf("+ 당신의 이름을 입력해주세요.          +\n");
		printf("+ >> ");
		scanf("%s", user.user_name);
		printf("\n");
		printf("+ 스타팅 포켓몬을 선택해주세요.       +\n");
		printf("+-------------------------------------+\n");
		printf("+ 1. Bulbasaur (Type1 : Grass, Type2 : Poison)\n");
		printf("+ 2. Charmander (Type : Fire)\n");
		printf("+ 3. Squirtle (Type : Water)\n");
		printf("+-------------------------------------+\n");
		printf("+ >> ");
		int startpoke = 1;
		scanf("%d", &startpoke);
		user.poke = (POKE*)malloc(sizeof(POKE) * 6);
		user.num_poke = 1;
		if (startpoke == 1) {
			user.poke[0] = *head[0];
			dic[0].dex_state = 2;

		}
		else if (startpoke == 2) {
			user.poke[0] = *head[1];
			dic[3].dex_state = 2;
		}
		else {
			user.poke[0] = *head[2];
			dic[6].dex_state = 2;
		}
		user.poke[0].lv = 5;
		user.poke[0].exp = 0;

		srand(time(NULL));
		user.poke[0].stat.iv = rand() % 32;

		user.poke[0].stat.lv_HP = ((user.poke[0].stat.HP) * 2 + user.poke[0].stat.iv)*(user.poke[0].lv) / 100 + 10 + user.poke[0].lv;
		user.poke[0].stat.cur_HP = user.poke[0].stat.lv_HP;

		Report(&user);

		while (1) {
			printf("\n");
			printf("+-----------Main Menu----------+\n");
			printf("+ 메뉴를 선택해주세요.         +\n");
			printf("+ 1. 배틀.                     +\n");
			printf("+ 2. 도감.                     +\n");
			printf("+ 3. 지닌 포켓몬.              +\n");
			printf("+ 4. 포켓몬 센터.              +\n");
			printf("+ 5. 리포트.                   +\n");
			printf("+ 6. 박스.                     +\n");
			printf("+ 7. 종료.                     +\n");
			printf("+ >> ");
			int menuopt = 1, totalhp = 0;
			scanf("%d", &menuopt);

			if (menuopt == 1) {
				for (int i = 0; i<user.num_poke; i++)
					totalhp += user.poke[i].stat.cur_HP;

				if (totalhp == 0) printf("+ 보유한 모든 포켓몬의 체력이 방전되어 있다...\n+ 포켓몬 센터에 가서 포켓몬의 체력을 회복하자!\n");
				else Battle(&user);
			}
			else if (menuopt == 2) {
				Pokedex();
			}
			else if (menuopt == 3) {
				user_Pokemon(NULL, &user);
			}
			else if (menuopt == 4) {
				Pokecen(&user);
			}
			else if (menuopt == 5) {
				Report(&user);
			}
			else if (menuopt == 6) {
				Box(&user);
			}
			else return 0;
		}
	}
	else return 0;

	return 0;
}

void Battle(User *user) {
	int battleopt = 1;
	srand(time(NULL));
	int random = rand() % 151;
	srand(time(NULL));
	int lvrand = rand() % 7;
	POKE* adversary = (POKE*)malloc(sizeof(POKE));
	adversary = &dic[random];
	adversary->lv = user->poke[0].lv + lvrand - 3;
	srand(time(NULL));
	adversary->stat.iv = rand() % 32;
	//HP 공식
	adversary->stat.lv_HP = ((adversary->stat.HP) * 2 + adversary->stat.iv)*(adversary->lv) / 100 + 10 + adversary->lv;
	adversary->stat.cur_HP = adversary->stat.lv_HP;

	printf("\n+----------------Battle----------------+\n");
	printf("+ 앗! 야생의 %s(Lv.%d)가 나타났다!\n", adversary->name, adversary->lv);
	dic[adversary->dex_num - 1].dex_state = 1;

	while (1) {
		printf("+ 무엇을 할까? > 1. 싸운다.\n");
		printf("+              > 2. 포켓몬.\n");
		printf("+              > 3. 잡는다.\n");
		printf("+              > 4. 도망친다.\n");
		printf("+               >> ");
		scanf("%d", &battleopt);

		if (battleopt == 1) {
			//int pokenum=0;
			while (1) {
				int fightresult;
				fightresult = Fight(adversary, user, &user->poke[pokenum]);


				if (fightresult == 3)
					break;

				else if (fightresult == 0 && pokenum < user->num_poke - 1) {// 나중에 진위 여부 확인할 것!
					pokenum++;
					break;
				}
				else if (fightresult == 0 && pokenum >= user->num_poke - 1) {
					printf("+ 더 이상 사용할 수 있는 포켓몬이 없다...\n");
					printf("+ %s는 %s로부터 간신히 도망쳤다...\n", user->user_name, adversary->name);
					pokenum++;
					return;
					//break;
				}
				else if (fightresult == -1) {
					pokenum++;
					return;
				}
				else if (fightresult == 1)
					return;
			}


		}
		else if (battleopt == 2) {
			user_Pokemon(NULL, user);
		}
		else if (battleopt == 3) {
			srand(time(NULL));
			int catchopt = rand() % 2;
			if (catchopt == 1) {
				Catch(adversary, user, NULL);
				return;
			}
			else printf("+ 아쉽다! 조금만 더 하면 잡을 수 있었는데!\n");
		}
		else {
			int runres = Run();
			if (runres == 1) break;
		}

	}
}

void Pokedex () {
	printf("+------------Sogang Dex-----------+\n");

	for (int i = 0; i<151; i++)
	{
		if (dic[i].dex_state == 0)
			printf("\t%d. ???\n", i + 1);

		else if (dic[i].dex_state == 1)
			printf("\t%d. %s (Type : ???)\n", i + 1, dic[i].name);

		else if (dic[i].dex_state == 2) {
			if (dic[i].type2[0] == '\0')
				printf("\t%d. %s (Type : %s)\n", i + 1, dic[i].name, dic[i].type1, dic[i].type2);
			else
				printf("\t%d. %s (Type1 : %s, Type2 : %s)\n", i + 1, dic[i].name, dic[i].type1, dic[i].type2);
		}

	}

	printf("+--------------------------------+\n");
}

void user_Pokemon(POKE *poke, User *user) {
	while (1)
	{
		printf("+---------[%s]의 포켓몬---------+\n", user->user_name);
		for (int i = 0; i<user->num_poke; i++)
			printf(" %d. %s\n", i + 1, user->poke[i].name);
		printf("\n");
		printf("+  1. 상태를 본다.             +\n");
		printf("+  2. 순서를 바꾼다.           +\n");
		printf("+  3. 종료.                    +\n");
		printf("+  >> ");
		int upo = 1;
		scanf("%d", &upo);
		if (upo == 1) {
			for (int i = 0; i<user->num_poke; i++) {
				printf("+  %d. %s\n", i + 1, user->poke[i].name);
				if (user->poke[i].type2[0] == '\0')
					printf("     Type = (%s)\n", user->poke[i].type1);
				else
					printf("     Type = (%s, %s)\n", user->poke[i].type1, user->poke[i].type2);
				printf("     HP = %d / %d\n", user->poke[i].stat.cur_HP, user->poke[i].stat.lv_HP);
				printf("     공격 = %d\n", user->poke[i].stat.Attack);
				printf("     방어 = %d\n", user->poke[i].stat.Block);
				printf("     특수공격 = %d\n", user->poke[i].stat.Contact);
				printf("     특수방어 = %d\n", user->poke[i].stat.Defense);
				printf("     스피드 = %d\n\n", user->poke[i].stat.Speed);
				//printf("     exp = %d\n", user->poke[i].exp);
			}
			printf("\n");
		}

		else if (upo == 2) {
			for (int i = 0; i<user->num_poke; i++) {
				if (user->poke[i].type2[0] == '\0')
					printf("+ %d. %s (Type : %s)\n", i + 1, user->poke[i].name, user->poke[i].type1);
				else
					printf("+ %d. %s (Type1 : %s, Type2 : %s)\n", i + 1, user->poke[i].name, user->poke[i].type1, user->poke[i].type2);
			}
			printf("+ 순서를 바꿀 포켓몬을 선택하세요.\n");
			printf("+ >> ");
			int pre, aft;
			scanf("%d %d", &pre, &aft);
			POKE tmp;
			tmp = user->poke[pre - 1];
			user->poke[pre - 1] = user->poke[aft - 1];
			user->poke[aft - 1] = tmp;
		}
		else break;
	}
}

void Pokecen(User *user) {
	printf("\n+---------------Pokemon center----------------+\n");
	printf("+ 포켓몬센터에 오신 것을 환영합니다 %s님!\n", user->user_name);
	printf("+ 현재 지니고 계신 포켓몬의 체력을 회복해드리겠습니다!\n");

	printf("+ ...포켓몬의 체력이 모두 회복되었다!\n");
	for (int i = 0; i<user->num_poke; i++)
		user->poke[i].stat.cur_HP = user->poke[i].stat.lv_HP;
	pokenum = 0;
	printf("+---------------------------------------------+");
}

void Report(User *user) {
	FILE *out = fopen("log.txt", "w");
	fprintf(out, "+--------------Report------------+\n");
	printf("+--------------Report------------+\n");

	fprintf(out, "+ 현재까지의 정보를 기록합니다.  +\n");
	printf("+ 현재까지의 정보를 기록합니다.  +\n");

	fprintf(out, "+ 트레이너명 = [%s]\n", user->user_name);
	printf("+ 트레이너명 = [%s]\n", user->user_name);

	fprintf(out, "+ 지닌 포켓몬 =\n");
	printf("+ 지닌 포켓몬 =\n");

	for (int i = 0; i<user->num_poke; i++) {
		if (user->poke[i].type2[0] == '\0') {
			fprintf(out, "+ %d. %s (Type : %s)\n", i + 1, user->poke[i].name, user->poke[i].type1);
			printf("+ %d. %s (Type : %s)\n", i + 1, user->poke[i].name, user->poke[i].type1);
		}
		else {
			fprintf(out, "+ %d. %s (Type1 : %s, Type2 : %s)\n", i + 1, user->poke[i].name, user->poke[i].type1, user->poke[i].type2);
			printf("+ %d. %s (Type1 : %s, Type2 : %s)\n", i + 1, user->poke[i].name, user->poke[i].type1, user->poke[i].type2);
		}
	}
	fprintf(out, "\n+--------------------------------+\n");
	printf("\n+--------------------------------+\n");
}

int Fight(POKE* adversary, User *user, POKE *cur) {
	int d1, d2, attackopt1, attackopt2, attacksize, blocksize;
	srand(time(NULL));
	attackopt1 = rand() % 2;
	if (attackopt1 == 0) {
		attacksize = adversary->stat.Attack;
		blocksize = cur->stat.Block;
	}
	else {
		attacksize = adversary->stat.Contact;
		blocksize = cur->stat.Defense;
	}
	srand(time(NULL));
	d1 = ((((adversary->lv) * 2) / 5 + 2)*attacksize) / blocksize / 50 + 2 + rand() % 5; //0~4 사이가 의미하는 것???//d의 첫번째 정의
																						 ////
	srand(time(NULL));
	attackopt2 = rand() % 2;
	if (attackopt2 == 0) {
		attacksize = cur->stat.Attack;
		blocksize = adversary->stat.Block;
	}
	else {
		attacksize = cur->stat.Contact;
		blocksize = adversary->stat.Defense;
	}
	d2 = ((((cur->lv) * 2) / 5 + 2)*attacksize) / blocksize / 50 + 2 + rand() % 5;//d의 두번째 정의

//++++++++++++++++++++++++++++++++++++++++++
//여기서부터
	if (adversary->stat.Speed > cur->stat.Speed) {
		//선공---------------------------------------------------
		printf("+%s는 %s에게 %d의 피해를 입혔다!\n", adversary->name, cur->name, d1);
		cur->stat.cur_HP -= d1;
		if (cur->stat.cur_HP <= 0) cur->stat.cur_HP = 0;
		printf("+ %s(lv.%d)              %s(lv.%d)\n", cur->name, cur->lv, adversary->name, adversary->lv);
		//if(cur->stat.HP <=0) cur->stat.HP=0;
		printf("+ HP = (%d/%d)           (%d/%d)\n\n", cur->stat.cur_HP, cur->stat.lv_HP, adversary->stat.cur_HP, adversary->stat.lv_HP);

		if (cur->stat.cur_HP == 0) {
			int faintopt;
			printf("+ %s는 쓰러졌다!\n", cur->name);
			while (1) {
				printf("  1. 다음 포켓몬을 사용한다.\n");
				printf("  2. 도망친다.\n");
				scanf("%d", &faintopt);
				if (faintopt == 1) return 0;

				else if (faintopt == 2) {
					int runres = Run();
					if (runres == 1) {
						//break;
						return -1;
					}
				}

			}
		}
		//후공--------------------------------------------------
		printf("+%s는 %s에게 %d의 피해를 입혔다!\n", cur->name, adversary->name, d2);
		adversary->stat.cur_HP -= d2;
		if (adversary->stat.cur_HP <= 0) adversary->stat.cur_HP = 0;
		printf("+ %s(lv.%d)              %s(lv.%d)\n", cur->name, cur->lv, adversary->name, adversary->lv);
		printf("+ HP = (%d/%d)           (%d/%d)\n\n", cur->stat.cur_HP, cur->stat.lv_HP, adversary->stat.cur_HP, adversary->stat.lv_HP);

		if (adversary->stat.cur_HP == 0) {
			printf("+ %s를 쓰러트렸다!\n", adversary->name);
			int upexp = ((adversary->lv) * (adversary->stat.HP)) / 5;

			printf("+ %s는 %d만큼의 경험치를 얻었다!\n", cur->name, upexp);
			cur->exp += upexp;
			if (cur->exp >= ((cur->lv)*(cur->lv)*(cur->lv))) {
				cur->lv++;
				printf("+ %s는 lv.%d에서 lv.%d로 레벨업했다!\n", cur->name, cur->lv - 1, cur->lv);
				cur->stat.lv_HP = ((cur->stat.HP) * 2 + cur->stat.iv)*(cur->lv) / 100 + 10 + cur->lv;
				cur->exp = 0;

				int f = Find(head2, cur->dex_num);
				if (f == 1) {
					Evolution(cur, cur->dex_num);
				}
			}
			return 1;
		}
		return 3;
	}
	//여기까지


	//사용자의 포켓몬이 먼저 공격하는 경우
	else {
		//선공--------------------------------------------------
		printf("+%s는 %s에게 %d의 피해를 입혔다!\n", cur->name, adversary->name, d2);
		adversary->stat.cur_HP -= d2;
		if (adversary->stat.cur_HP <= 0) adversary->stat.cur_HP = 0;
		printf("+ %s(lv.%d)              %s(lv.%d)\n", cur->name, cur->lv, adversary->name, adversary->lv);
		printf("+ HP = (%d/%d)           (%d/%d)\n\n", cur->stat.cur_HP, cur->stat.lv_HP, adversary->stat.cur_HP, adversary->stat.lv_HP);

		if (adversary->stat.cur_HP == 0) {
			printf("+ %s를 쓰러트렸다!\n", adversary->name);
			int upexp = ((adversary->lv) * (adversary->stat.HP)) / 5;

			printf("+ %s는 %d만큼의 경험치를 얻었다!\n", cur->name, upexp);
			cur->exp += upexp;
			if (cur->exp >= ((cur->lv)*(cur->lv)*(cur->lv))) {
				cur->lv++;
				printf("+ %s는 lv.%d에서 lv.%d로 레벨업했다!\n", cur->name, cur->lv - 1, cur->lv);
				cur->stat.lv_HP = ((cur->stat.HP) * 2 + cur->stat.iv)*(cur->lv) / 100 + 10 + cur->lv;
				cur->exp = 0;
				int f = Find(head2, cur->dex_num);
				if (f == 1) {
					Evolution(cur, cur->dex_num);
				}
			}
			return 1;
		}

		//후공---------------------------------------------------
		printf("+%s는 %s에게 %d의 피해를 입혔다!\n", adversary->name, cur->name, d1);
		cur->stat.cur_HP -= d1;
		if (cur->stat.cur_HP <= 0) cur->stat.cur_HP = 0;
		printf("+ %s(lv.%d)              %s(lv.%d)\n", cur->name, cur->lv, adversary->name, adversary->lv);
		printf("+ HP = (%d/%d)           (%d/%d)\n\n", cur->stat.cur_HP, cur->stat.lv_HP, adversary->stat.cur_HP, adversary->stat.lv_HP);

		if (cur->stat.cur_HP == 0) {
			int faintopt;
			printf("+ %s는 쓰러졌다!\n", cur->name);
			while (1) {
				printf("  1. 다음 포켓몬을 사용한다.\n");
				printf("  2. 도망친다.\n");
				scanf("%d", &faintopt);
				if (faintopt == 1) return 0;

				else if (faintopt == 2) {
					int runres = Run();
					if (runres == 1)
						return -1;
				}
			}
		}
		return 3;
	}
}

void Catch(POKE *adversary, User *user, POKE *cur) {
	if (user->num_poke >= 6) {
		printf("+ 지닐 수 있는 최대 포켓몬 수 (6마리)가 꽉 찼습니다.\n");
		printf("+ 빈 공간을 만드려면 박스 옵션을 이용하십시오.\n");
		return;
	}
	printf("+ 신난다~! %s를 잡았다!\n", adversary->name);
	dic[adversary->dex_num - 1].dex_state = 2;

	user->poke[user->num_poke].stat.lv_HP = adversary->stat.lv_HP;
	user->poke[user->num_poke].stat.cur_HP = adversary->stat.cur_HP;
	user->poke[user->num_poke].stat.HP = adversary->stat.HP;

	user->poke[user->num_poke].stat.Attack = adversary->stat.Attack;
	user->poke[user->num_poke].stat.Block = adversary->stat.Block;
	user->poke[user->num_poke].stat.Contact = adversary->stat.Contact;
	user->poke[user->num_poke].stat.Defense = adversary->stat.Defense;
	user->poke[user->num_poke].stat.Speed = adversary->stat.Speed;

	user->poke[user->num_poke].lv = adversary->lv;
	user->poke[user->num_poke].dex_num = adversary->dex_num;
	strcpy(user->poke[user->num_poke].name, adversary->name);
	strcpy(user->poke[user->num_poke].type1, adversary->type1);
	strcpy(user->poke[user->num_poke].type2, adversary->type2);
	user->poke[user->num_poke].exp = 0; //초기 exp 값은 0

	user->num_poke++;

}

int Run() {
	srand(time(NULL));
	int random = rand() % 10;
	if (random<2) {
		printf("+ 무사히 도망쳤다!\n");
		return 1;
	}
	else {
		printf("+ 도망칠 수 없었다!\n");
		return 0;
	}
	return 0;
}


void Insert(POKE** head) {
	int len = 0;
	POKE* tmp = (POKE*)malloc(sizeof(POKE));

	fscanf(in2, "%d%s%s%d%d%d%d%d%d\n", &tmp->dex_num, tmp->name, tmp->type1, &tmp->stat.HP, &tmp->stat.Attack, &tmp->stat.Block, &tmp->stat.Contact, &tmp->stat.Defense, &tmp->stat.Speed);
	tmp->link = NULL;
	if (*head == NULL) *head = tmp;
	else {
		POKE* idx = (POKE*)malloc(sizeof(POKE));
		idx = head[0];

		while (1) {
			if (idx->link == NULL) break;
			idx = idx->link;
		}

		idx->link = tmp;
	}




	for (int j = 0; j<30; j++) {
		len++;
		if (tmp->type1[j] == ',')
			break;
	}
	tmp->type1[len - 1] = '\0';
	tmp->type2[0] = '\0';
	if (len>0)
		strcpy(&tmp->type2[0], &tmp->type1[len]);
}

int Find(POKE** head, int num) {
	int i = 0;
	POKE* idx = (POKE*)malloc(sizeof(POKE));
	idx = head[i];
	for (int k = 0; k<151; k++) {
		if (idx->dex_num == num) break;
		if (idx->link == NULL) idx = head[++i];

		else idx = idx->link;
	}
	printf("%d ", idx->dex_num);

	if (idx->link == NULL) return 0;
	else return 1;
}


void Evolution(POKE *cur, int n) {
	srand(time(NULL));
	int revolutionopt = rand() % 10;
	if (revolutionopt<4) {
		printf("\n\n+ .....\n+ ........오잉?\n");
		printf("+ %s의 상태가.....!\n\n", cur->name);

		printf("+ 축하합니다! %s는 %s으로 진화했습니다!\n\n", dic[n - 1].name, dic[n].name);
		dic[n].dex_state = 2;

		cur->stat.HP = dic[n].stat.HP;

		cur->stat.Attack = dic[n].stat.Attack;
		cur->stat.Block = dic[n].stat.Block;
		cur->stat.Contact = dic[n].stat.Contact;
		cur->stat.Defense = dic[n].stat.Defense;
		cur->stat.Speed = dic[n].stat.Speed;
		//iv

		//cur->lv=dic[n].lv;// 포켓몬이 진화하면 레벨 그대로 유지
		cur->dex_num = dic[n].dex_num;
		strcpy(cur->name, dic[n].name);
		strcpy(cur->type1, dic[n].type1);
		strcpy(cur->type2, dic[n].type2);
		cur->exp = 0;
	}
}


void Box(User *user) {
	int boxopt;
	printf("+--------------Box---------------+\n");
	printf("+ 무엇을 하시겠습니까?\n");
	printf("  1. 박스에 포켓몬 넣기\n  2. 박스에서 포켓몬 꺼내기\n");
	printf("+ >> ");
	scanf("%d", &boxopt);

	if (boxopt == 1) {
		for (int i = 0; i<user->num_poke; i++) {
			if (user->poke[i].type2[0] == '\0')
				printf("+ %d. %s (Type : %s)\n", i + 1, user->poke[i].name, user->poke[i].type1);
			else
				printf("+ %d. %s (Type1 : %s, Type2 : %s)\n", i + 1, user->poke[i].name, user->poke[i].type1, user->poke[i].type2);
		}
		int inopt;
		printf("+ 넣을 포켓몬 :\n");
		printf("+ >> ");
		scanf("%d", &inopt);

		BOX.poke[boxnum] = user->poke[inopt - 1];

		printf("inserted name : %s\n", BOX.poke[boxnum].name);

		boxnum++;
		for (int i = inopt - 1; i<user->num_poke - 1; i++)
			user->poke[i] = user->poke[i + 1];
		user->num_poke--;
	}

	if (boxopt == 2) {
		if (boxnum == 0) {
			printf("+ 상자가 비어있습니다.\n");
			return;
		}
		if (user->num_poke >= 6) {
			printf("+ 사용자의 포켓몬 보관함이 이미 꽉 찼습니다.\n");
			return;
		}
		for (int i = 0; i<boxnum; i++) {
			if (BOX.poke[i].type2[0] == '\0')
				printf("+ %d. %s (Type : %s)\n", i + 1, BOX.poke[i].name, BOX.poke[i].type1);
			else
				printf("+ %d. %s (Type1 : %s, Type2 : %s)\n", i + 1, BOX.poke[i].name, BOX.poke[i].type1, BOX.poke[i].type2);
		}
		int outopt;
		printf("+ 꺼낼 포켓몬 :\n");
		printf("+ >> ");
		scanf("%d", &outopt);
		user->poke[user->num_poke] = BOX.poke[outopt - 1];
		user->num_poke++;

		for (int i = outopt - 1; i<boxnum - 1; i++)
			BOX.poke[i] = BOX.poke[i + 1];
		boxnum--;

	}

}
